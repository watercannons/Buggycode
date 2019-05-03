
// Replay is only for linux builds
#ifndef TARGET_LINUX
// TODO: Add defines so that <FUNCTION>_LOG functions still work
#define __SELECT_REPLAY_H__
#endif

#ifdef __USE_TREPLAY
#include "select_treplay.h"
#define __SELECT_REPLAY_H__
#endif

#ifndef __SELECT_REPLAY_H__
#define __SELECT_REPLAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <poll.h>
#include <sys/select.h>

int select_log(int nfds,  fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout, const char *file, int line);
int fd_isset_log(int filedes, fd_set *fds_ptr, const char *file, int line);
int poll_log(struct pollfd *fds, nfds_t nfds, int timeout, const char *file, int line);

#define select(nfds, readfds, writefds, exceptfds, timeout) \
	select_log(nfds, readfds, writefds, exceptfds, timeout, __FILE__, __LINE__)
#undef FD_ISSET
#define FD_ISSET(filedes, fds) \
	fd_isset_log(filedes, fds, __FILE__, __LINE__)
#define poll(fds, nfds, timeout) \
	poll_log(fds, nfds, timeout, __FILE__, __LINE__)

#ifdef __cplusplus
}
#endif

#endif // __SELECT_REPLAY_H__
