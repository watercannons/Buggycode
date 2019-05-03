
// Replay is only for linux builds
#ifndef TARGET_LINUX
// TODO: Add defines so that <FUNCTION>_LOG functions still work
#define __FILE_REPLAY_H__
#endif

#ifdef __USE_TREPLAY
#include "file_treplay.h"
#define __FILE_REPLAY_H__
#endif

#ifndef __FILE_REPLAY_H__
#define __FILE_REPLAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <ftw.h>
#include <stdio.h>

int access_log(const char *pathname, int mode, const char *file, int line);
FILE *fopen_log(char *filename, const char *mode, const char *file, int line);
FILE *fdopen_log(int filedes, const char *mode, const char *file, int line);
int fseek_log(FILE *stream, long offset, int whence, const char *file, int line);
void rewind_log(FILE *stream);
long ftell_log(FILE *stream, const char *file, int line);
int fgetc_log(FILE *stream, const char *file, int line);
char *fgets_log(char *s, int n, FILE *stream, const char *file, int line);
size_t fread_log(void *ptr, size_t size, size_t nitems, FILE *stream, const char *file, int line);
size_t fwrite_log(const void *ptr, size_t size, size_t nitems, FILE *stream, const char *file, int line);
int fputc_log(int c, FILE *stream, const char *file, int line);
int fscanf_log(const char *file, int line, FILE *stream, const char *format, ... );
int fclose_log(FILE *stream, const char *file, int line);
int fprintf_log(const char *file, int line, FILE *stream, const char *format, ...);
ssize_t getxattr_log(const char *path, const char *name, void *value, size_t size, const char *file, int line);
int setxattr_log(const char *path, const char *name, const void *value, size_t size, int flags, const char *file, int line);
int nftw_log(const char *path,
             int (*fn)(const char *, const struct stat *, int, struct FTW *),
             int         fd_limit,
             int         flags,
             const char *file,
             int         line);
int symlink_log(const char *path1, const char *path2, const char *file, int line);
ssize_t readlink_log(const char *path, char *buf, size_t bufsize, const char *file, int line);

size_t fread_image_log(void *ptr, size_t size, size_t nitems, FILE *stream, const char *file, int line);

#define access(pathname, mode) \
	access_log(pathname, mode, __FILE__, __LINE__)
#define fopen(filename, mode) \
	fopen_log((char *) (filename), mode, __FILE__, __LINE__)
#define fdopen(filedes, mode) \
	fdopen_log(filedes, mode, __FILE__, __LINE__);
#define fseek(stream, offset, whence) \
	fseek_log(stream, offset, whence, __FILE__, __LINE__)
#define rewind(stream) \
	rewind_log(stream)
#define ftell(stream) \
	ftell_log(stream, __FILE__, __LINE__)
#define fgetc(stream) \
	fgetc_log(stream, __FILE__, __LINE__)
#define fgets(s, n, stream) \
	fgets_log(s, n, stream, __FILE__, __LINE__)
#define fread(ptr, size, nitems, stream) \
	fread_log(ptr, size, nitems, stream, __FILE__, __LINE__)
#define fwrite(ptr, size, nitems, stream) \
	fwrite_log(ptr, size, nitems, stream, __FILE__, __LINE__)
#define fputc(c, stream) \
	fputc_log(c, stream, __FILE__, __LINE__)
#define fputs(str, stream) \
	fwrite_log((void *) (str), sizeof(char), strlen(str), stream, __FILE__, __LINE__)
#undef fscanf
#define fscanf(stream, format, ...) \
	fscanf_log(__FILE__, __LINE__, stream, format, ##__VA_ARGS__)
#define fclose(stream) \
	fclose_log(stream, __FILE__, __LINE__)
#define fprintf(stream, format, ...) \
	fprintf_log(__FILE__, __LINE__, stream, format, ##__VA_ARGS__)
#define getxattr(path, name, value, size) \
	getxattr_log(path, name, value, size, __FILE__, __LINE__)
#define setxattr(path, name, value, size, flags) \
	setxattr_log(path, name, value, size, flags, __FILE__, __LINE__)
#define nftw(path, fn, fd_limit, flags) \
	nftw_log(path, fn, fd_limit, flags, __FILE__, __LINE__)
#define symlink(path1, path2) \
	symlink_log(path1, path2, __FILE__, __LINE__)
#define readlink(path, buf, bufsize) \
	readlink_log(path, buf, bufsize, __FILE__, __LINE__)
#define fread_image(ptr, size, nitems, stream) \
	fread_image_log(ptr, size, nitems, stream, __FILE__, __LINE__)

#ifdef __cplusplus
}
#endif

#endif // __FILE_REPLAY_H__
