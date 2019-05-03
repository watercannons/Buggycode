
// Replay is only for linux builds
#ifndef TARGET_LINUX
// TODO: Add defines so that <FUNCTION>_LOG functions still work
#define __DIR_REPLAY_H__
#endif

#ifdef __USE_TREPLAY
#include "dir_treplay.h"
#define __DIR_REPLAY_H__
#endif

#ifndef __DIR_REPLAY_H__
#define __DIR_REPLAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <dirent.h>
#include <sys/stat.h>

DIR *opendir_log(const char *dirname, const char *file, int line);
void seekdir_log(DIR *dirp, long loc);
long telldir_log(DIR *dirp, const char *name, const char *file, int line);
void rewinddir_log(DIR *dirp);
struct dirent *readdir_log(DIR *dirp, const char *name, const char *file, int line);
int closedir_log(DIR *dirp);
char *getenv_log(const char *name, const char *file, int line);
int stat_log(const char *path, struct stat *buf, const char *file, int line);
int lstat_log(const char *path, struct stat *buf, const char *file, int line);
int rmdir_log(const char *path, const char *file, int line);
int mkdir_log(const char *path, mode_t mode, const char *file, int line);

#define opendir(dirname) \
	opendir_log(dirname, __FILE__, __LINE__)
#define seekdir(dirp, loc) \
	seekdir_log(dirp, loc)
#define telldir(dirp) \
	telldir_log(dirp, #dirp, __FILE__, __LINE__)
#define readdir(dirp) \
	readdir_log(dirp, #dirp, __FILE__, __LINE__)
#define rewinddir(dirp) \
	rewinddir_log(dirp)
#define closedir(dirp) \
	closedir_log(dirp)
#define getenv(name) \
	getenv_log(name, __FILE__, __LINE__)
#define stat(path, buf) \
	stat_log(path, buf, __FILE__, __LINE__)
#define lstat(path, buf) \
	lstat_log(path, buf, __FILE__, __LINE__)
#define rmdir(path) \
	rmdir_log(path, __FILE__, __LINE__)
#define mkdir(path, mode) \
	mkdir_log(path, mode, __FILE__, __LINE__)

#ifdef __cplusplus
}
#endif

#endif // __DIR_REPLAY_H__
