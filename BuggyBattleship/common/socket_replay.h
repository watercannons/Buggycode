
// Replay is only for linux builds
#ifndef TARGET_LINUX
// TODO: Add defines so that <FUNCTION>_LOG functions still work
#define __SOCKET_REPLAY_H__
#endif

#ifdef __USE_TREPLAY
#include "socket_treplay.h"
#define __SOCKET_REPLAY_H__
#endif

#ifndef __SOCKET_REPLAY_H__
#define __SOCKET_REPLAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/socket.h>

int socket_log(int domain, int type, int protocol, const char *file, int line);

int setsockopt_log(int        socket,
                   int        level,
                   int        option_name,
                   void      *option_value,
                   socklen_t  option_len);

int bind_log(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int listen_log(int sockfd, int backlog);

int accept_log(int              sockfd,
               struct sockaddr *addr,
               socklen_t       *addrlen,
               const char      *file,
               int              line);

ssize_t sendto_log(int                    sockfd,
                   const void            *buf,
                   size_t                 len,
                   int                    flags,
                   const struct sockaddr *dest_addr,
                   socklen_t              addrlen,
                   const char            *file,
                   int                    line);

ssize_t sendmsg_log(int socket, const struct msghdr *message, int flags);

ssize_t recvfrom_log(int              sockfd,
                     void            *buf,
                     size_t           len,
                     int              flags,
                     struct sockaddr *src_addr,
                     socklen_t       *addrlen,
                     const char      *file,
                     int              line);

ssize_t recvmsg_log(int            sockfd,
                    struct msghdr *msg,
                    int            flags,
                    const char    *file,
                    int            line);

int connect_log(int socket, const struct sockaddr *address, socklen_t address_len);

#define socket(domain, type, protocol) \
	socket_log(domain, type, protocol, __FILE__, __LINE__)
#define setsockopt(socket, level, option_name, option_value, option_len) \
	setsockopt_log(socket, level, option_name, option_value, option_len)
#define bind(sockfd, addr, addrlen) \
	bind_log(sockfd, addr, addrlen)
#define listen(sockfd, backlog) \
	listen_log(sockfd, backlog)
#define accept(sockfd, addr, addrlen) \
	accept_log(sockfd, addr, addrlen, __FILE__, __LINE__)
#define sendto(sockfd, buf, len, flags, dest_addr, addrlen) \
	sendto_log(sockfd, buf, len, flags, dest_addr, addrlen, __FILE__, __LINE__)
#define send(sockfd, buf, len, flags) \
	sendto_log(sockfd, buf, len, flags, NULL, 0, __FILE__, __LINE__)
#define sendmsg(socket, message, flags) \
    sendmsg_log(socket, message, flags)
#define recvfrom(sockfd, buf, len, flags, src_addr, addrlen) \
	recvfrom_log(sockfd, buf, len, flags, src_addr, addrlen, __FILE__, __LINE__)
#define recv(sockfd, buf, len, flags) \
	recvfrom_log(sockfd, buf, len, flags, NULL, NULL, __FILE__, __LINE__)
#define recvmsg(sockfd, msg, flags) \
	recvmsg_log(sockfd, msg, flags, __FILE__, __LINE__)
#define connect(socket, address, address_len) \
	connect_log(socket, address, address_len)

#ifdef __cplusplus
}
#endif

#endif // __SOCKET_REPLAY_H__
