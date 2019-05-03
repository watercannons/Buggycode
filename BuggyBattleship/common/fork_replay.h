
// Replay is only for linux builds
#ifndef TARGET_LINUX
// TODO: Add defines so that <FUNCTION>_LOG functions still work
#define __FORK_REPLAY_H__
#endif

#ifdef __USE_TREPLAY
#include "fork_treplay.h"
#define __FORK_REPLAY_H__
#endif

#ifndef __FORK_REPLAY_H__
#define __FORK_REPLAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h>

pid_t fork_log(void);
pid_t waitpid_log(pid_t pid, int *status, int options, \
                  const char *name, const char *file, int line);
int execl_log(const char *path, const char *arg, ...  /* (char  *) NULL */);
int execlp_log(const char *file, const char *arg, ... /* (char  *) NULL */);
int execv_log(const char *path, char *const argv[]);
int execvp_log(const char *file, char *const argv[]);

#define fork() \
	fork_log()
#define waitpid(pid, status, options) \
	waitpid_log(pid, status, options, #pid, __FILE__, __LINE__)
#define execl(path, arg, ...) \
  execl_log(path, arg, __VA_ARGS__)
#define execlp(file, arg, ...) \
  execlp_log(file, arg, __VA_ARGS__)
#define execv(path, argv) \
  execv_log(path, argv)
#define execvp(file, argv) \
  execvp_log(file, argv)


#ifdef __cplusplus
}
#endif

#endif // __FORK_REPLAY_H__
