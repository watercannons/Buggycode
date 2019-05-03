#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/select.h>

#ifdef REPLAY
const char* thisProcessStringID = "ip-player";
#include <replay.h>
#include <fd_replay.h>
#include <select_replay.h>
#include <replay_undef.h>
#endif /* REPLAY */


#define MAX_CONNECTIONS 1
#define BUFFER_SIZE 1024

void printHelp()
{
   fprintf(stderr, "Usage: server readFD writeFD\n");
   exit(EXIT_FAILURE);
}

int getFD(char* fd)
{
   int res;
   if (!sscanf(fd, "%d", &res))
      printHelp();
   return res;
}

void printSocketInfo(int soc)
{
  char addrStr[INET6_ADDRSTRLEN+1];
  struct sockaddr_in6 addInfo;
  socklen_t addrLen = sizeof(struct sockaddr_in6);
  memset(&addInfo, 0, sizeof(struct sockaddr_in6));
  getsockname(soc, (struct sockaddr*) &addInfo, &addrLen);
  inet_ntop(AF_INET6, &addInfo.sin6_addr, addrStr, INET6_ADDRSTRLEN);
  printf("Network player listening on %s:%hu.\n", addrStr, ntohs(addInfo.sin6_port));
}

int openConnection()
{
  int serverSoc = socket(AF_INET6, SOCK_STREAM, 0);
  struct sockaddr_in6 addInfo;
  int result;
  socklen_t addrLen = sizeof(struct sockaddr_in6);
  memset(&addInfo, 0, sizeof(struct sockaddr_in6));
  addInfo.sin6_family = AF_INET6;
  inet_pton(AF_INET6, "::", &addInfo.sin6_addr);
  bind(serverSoc, (struct sockaddr*) &addInfo, sizeof(struct sockaddr_in6));
  printSocketInfo(serverSoc);
  listen(serverSoc, MAX_CONNECTIONS);
  memset(&addInfo, 0, sizeof(struct sockaddr_in6));
  result = accept(serverSoc, (struct sockaddr*) &addInfo, &addrLen);
  close(serverSoc);
  return result;
}

int passBetween(int r, int w)
{
  char buffer[BUFFER_SIZE];
  int readSize = read(r, buffer, BUFFER_SIZE);
  write(w, buffer, readSize);
  return readSize;
}

void passCommunications(int socket, int rfd, int wfd)
{
  fd_set set, ref;
  int maxFD = (rfd > socket? rfd:socket) + 1;
  int cont;
  FD_ZERO(&ref);
  FD_SET(socket, &ref);
  FD_SET(rfd, &ref);
  do
    {
      set = ref;
      select(maxFD, &set, NULL, NULL, NULL);
      if (FD_ISSET(socket, &set))
        cont = passBetween(socket, wfd);
      if (FD_ISSET(rfd, &set))
        cont = passBetween(rfd, socket);
    } while (cont);
}

int main(int argn, char** args)
{
  int socket, wFd, rFd;
#ifdef REPLAY
  init_replay(&argn, (const char ***) &args);
#endif /* REPLAY */
  if (argn != 3)
      printHelp();
  rFd = getFD(args[1]);
  wFd = getFD(args[2]);
  socket = openConnection();
  passCommunications(socket, rFd, wFd);
  close(socket);
  close(wFd);
  close(rFd);
  return 0;
}
