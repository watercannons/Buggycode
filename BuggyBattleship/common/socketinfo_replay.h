
// Replay is only for linux builds
#ifndef TARGET_LINUX
// TODO: Add defines so that <FUNCTION>_LOG functions still work
#define __SOCKETINFO_REPLAY_H__
#endif

#ifdef __USE_TREPLAY
#include "socketinfo_treplay.h"
#define __SOCKETINFO_REPLAY_H__
#endif

#ifndef __SOCKETINFO_REPLAY_H__
#define __SOCKETINFO_REPLAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <ifaddrs.h>

int getifaddrs_log(struct ifaddrs **ifap, const char *file, int line);
void freeifaddrs_log(struct ifaddrs *ifa);
int getaddrinfo_log(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **ai, const char *file, int line);
void freeaddrinfo_log(struct addrinfo *res);
int getsockname_log(int sockfd, struct sockaddr *addr, socklen_t *addrlen, const char *name, const char *file, int line);

#define getifaddrs(ifap) \
	getifaddrs_log(ifap, __FILE__, __LINE__)
#define freeifaddrs(ifa) \
	freeifaddrs_log(ifa)
#define getaddrinfo(node, service, hints, res) \
	getaddrinfo_log(node, service, hints, res, __FILE__, __LINE__)
#define freeaddrinfo(res) \
	freeaddrinfo_log(res)
#define getsockname(sockfd, addr, addrlen) \
	getsockname_log(sockfd, addr, addrlen, #sockfd, __FILE__, __LINE__)

#ifdef __cplusplus
}
#endif

#endif // __SOCKETINFO_REPLAY_H__
