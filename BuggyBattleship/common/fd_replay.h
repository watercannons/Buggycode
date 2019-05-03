
// Replay is only for linux builds
#ifndef TARGET_LINUX
// TODO: Add defines so that <FUNCTION>_LOG functions still work
#define __FD_REPLAY_H__
#endif

#ifdef __USE_TREPLAY
#include "fd_treplay.h"
#define __FD_REPLAY_H__
#endif

#ifndef __FD_REPLAY_H__
#define __FD_REPLAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

// fd_replay.c
int open_log(const char *path, int oflags, const char *file, int line);
int open3_log(const char *path, int oflags, mode_t mode, const char *file, int line);
int close_log(int fildes, const char *file, int line);
int read_log(int filedes, void *buf, size_t nbytes, const char *file, int line);
int write_log(int filedex, const void *buf, size_t nbytes, const char *file, int line);
int dprintf_log(const char *file, int line, int fd, const char *format, ...);
int fcntl_log(const char* file, int line, int fd, int cmd, ...);
int unlink_log(const char *pathname, const char *file, int line);
int mkstemps_log(char *template_name, int suffixlen, const char *file, int line);
int remove_log(const char *path, const char *file, int line);
ssize_t fgetxattr_log(int fd, const char *name, void *value, size_t size, const char *file, int line);
int rename_log(const char *oldpath, const char *newpath, const char *file, int line);
int read_image_log(int filedes, void *buf, size_t nbyte, const char *file, int line);

#define open(path, oflags) \
	open_log(path, oflags, __FILE__, __LINE__)
#define open3(path, oflags, mode) \
	open3_log(path, oflags, mode, __FILE__, __LINE__)
#define close(fildes) \
	close_log(fildes, __FILE__, __LINE__)
#define read(filedes, buf, nbytes) \
	read_log(filedes, buf, nbytes, __FILE__, __LINE__)
#define write(filedex, buf, nbytes) \
	write_log(filedex, buf, nbytes, __FILE__, __LINE__)
#define dprintf(fd, format, ...) \
	dprintf_log(__FILE__, __LINE__, fd, format, ##__VA_ARGS__)
#define fcntl(fd, cmd, ...) \
	fcntl_log(__FILE__, __LINE__, fd, cmd, ##__VA_ARGS__)
#define unlink(pathname) \
	unlink_log(pathname, __FILE__, __LINE__)
#define mkstemps(template, suffixlen) \
	mkstemps_log(template, suffixlen, __FILE__, __LINE__)
#define remove(path) \
	remove_log(path, __FILE__, __LINE__)
#define fgetxattr(fd, name, value, size) \
	fgetxattr_log(fd, name, value, size, __FILE__, __LINE__)
#define rename(oldpath, newpath) \
	rename_log(oldpath, newpath, __FILE__, __LINE__)
#define read_image(filedes, buf, nbytes) \
	read_image_log(filedes, buf, nbytes, __FILE__, __LINE__)

#ifdef __cplusplus
}
#endif

#endif // __FD_REPLAY_H__
