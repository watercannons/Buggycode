#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#ifdef REPLAY
   const char* thisProcessStringID = "ip-player";
#include <replay.h>
#include <fork_replay.h>
#include <replay_undef.h>
#endif /* REPLAY */


void printHelp()
{
   fprintf(stderr, "Usage: client ip port player\n");
   exit(EXIT_FAILURE);
}

int openConnection(char* ip, unsigned short port)
{
  int soc = socket(AF_INET6, SOCK_STREAM, 0);
  struct sockaddr_in6 addInfo;
  memset(&addInfo, 0, sizeof(struct sockaddr_in6));
  addInfo.sin6_family = AF_INET6;
  inet_pton(AF_INET6, ip, &addInfo.sin6_addr);
  addInfo.sin6_port = htons(port);
  connect(soc, (struct sockaddr*) &addInfo, sizeof(struct sockaddr_in6));
  return soc;
}

void execPlayer(char* player, int soc)
{
  char socStr[5];
  sprintf(socStr, "%d", soc);
  execl(player, player, socStr, socStr, NULL);
}

int main(int argn, char** args)
{
  int socket;
  unsigned short port;
#ifdef REPLAY
  init_replay(&argn, (const char ***) &args);
#endif /* REPLAY */
  if (argn != 4 || !sscanf(args[2], "%hu", &port))
    {
      printHelp();
    }
  socket = openConnection(args[1], port);
  execPlayer(args[3], socket);
  return 0;
}
