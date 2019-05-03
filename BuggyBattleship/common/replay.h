
// Replay is only for linux builds
#ifndef TARGET_LINUX

#define OPEN_LOG open
#define OPEN3_LOG open
#define CLOSE_LOG close
#define READ_LOG read
#define WRITE_LOG write
#define DPRINTF_LOG dprintf
#define FCNTL_LOG fcntl
#define UNLINK_LOG unlink
#define MKSTEMPS_LOG mkstemps
#define REMOVE_LOG remove
#define FGETXATTR_LOG fgetxattr
#define RENAME_LOG rename
#define FD_ZERO_LOG fd_zero
#define FD_SET_LOG fd_set
#define SELECT_LOG select
#define FD_ISSET_LOG fd_isset
#define POLL_LOG poll
#define ACCESS_LOG access
#define FOPEN_LOG fopen
#define FDOPEN_LOG fdopen
#define FSEEK_LOG fseek
#define REWIND_LOG rewind
#define FTELL_LOG ftell
#define FGETC_LOG fgetc
#define FGETS_LOG fgets
#define FREAD_LOG fread
#define FWRITE_LOG fwrite
#define FPUTC_LOG fputc
#define FPUTS_LOG fputs
#define FSCANF_LOG fscanf
#define FCLOSE_LOG fclose
#define FPRINTF_LOG fprintf
#define GETXATTR_LOG getxattr
#define SETXATTR_LOG setxattr
#define NFTW_LOG ntfw
#define SYMLINK_LOG symlink
#define OPENDIR_LOG opendir
#define SEEKDIR_LOG seekdir
#define TELLDIR_LOG telldir
#define REWINDDIR_LOG rewinddir
#define READDIR_LOG readdir
#define CLOSEDIR_LOG closedir
#define GETENV_LOG getenv
#define STAT_LOG stat
#define RMDIR_LOG rmdir
#define MKDIR_LOG mkdir
#define TIME_LOG time
#define GETTIMEOFDAY_LOG gettimeofday
#define CLOCK_GETTIME_LOG clock_gettime
#define SOCKET_LOG socket
#define SETSOCKOPT_LOG setsocketopt
#define BIND_LOG bind
#define LISTEN_LOG listen
#define ACCEPT_LOG accept
#define SENDTO_LOG sendto
#define SEND_LOG send
#define SENDMSG_LOG sendmsg
#define RECVFROM_LOG recvfrom
#define RECV_LOG recv
#define RECVMSG_LOG recvmsg
#define CONNECT_LOG connect
#define GETIFADDRS_LOG getifaddrs
#define FREEIFADDRS_LOG freeifaddrs
#define GETADDRINFO_LOG getaddrinfo
#define FREEADDRINFO_LOG freeaddrinfo
#define GETSOCKNAME_LOG getsockname
#define FORK_LOG fork
#define WAITPID_LOG waitpid
#define GCRY_RANDOMIZE_LOG gcry_randomize
#define GCRY_CREATE_NONCE_LOG gcry_create_nonce
#define READ_IMAGE_LOG read
#define FREAD_IMAGE_LOG fread
#define replay_checkpoint()
#define in_replay() (false)

#define __REPLAY_H__
#endif

#ifdef __USE_TREPLAY
#define REPLAY_DONT_REPLACE_SYMBOLS
#include "treplay.h"
// Include all the treplay headers since old programs only include replay.h.
#include "file_treplay.h"
#include "fd_treplay.h"
#include "select_treplay.h"
#include "time_treplay.h"
#include "dir_treplay.h"
#include "socket_treplay.h"
#include "socketinfo_treplay.h"
#include "fork_treplay.h"
#include "random_treplay.h"
// #include "screen_treplay.h"
// #include "curl_treplay.h"
// #include "font_treplay.h"
#define __REPLAY_H__
#endif

#ifndef __REPLAY_H__
#define __REPLAY_H__

// Define these for replay_undef
#define FD_REPLAY_H
#define SELECT_REPLAY_H
#define FILE_REPLAY_H
#define DIR_REPLAY_H
#define TIME_REPLAY_H
#define SOCKET_REPLAY_H
#define FORK_REPLAY_H
#define RANDOM_REPLAY_H
#define SOCKETINFO_REPLAY_H
#define CURL_REPLAY_H
#define FONT_REPLAY_H
#define SCREEN_REPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef REPLAY_DONT_INCLUDE_SDL
  //    #include <SDL2/SDL.h>
  //    #include <SDL2/SDL_ttf.h>
#endif

#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <dirent.h>
#include <poll.h>
#include <ifaddrs.h>
#include <fcntl.h>
#include <gcrypt.h> // gcry_randomize
#include <netdb.h>
#include <signal.h>
#include <sys/stat.h>
#include <ftw.h>

//enum replay_operations {
//	OPEN = 0,
//	OPEN3,
//	CLOSE,
//	READ,
//	WRITE,
//	SELECT,
//	FD_ISSET,
//	ACCESS,
//	FOPEN
//};

// replay.c
void init_replay(int *argc, const char ***argv);
int parse_replay_arguments(int argc, const char **argv);
void log_and_restore_arguments(int *argc, const char ***argv, int *first_user_arg);
bool in_replay(void);
void end_replay(void);

void OpenMappings(const char *replay_filepath);

void enter_replay_function(const char *operation);
void enter_replay_ipc_function(const char *operation, const char *target);
void exit_replay_function(void);

    bool CheckWritePermissions(const char *path);
    bool CheckReadPermissions(const char *path);

int replay_log_log(void);

void replay_machine_halt(void);

pid_t replay_get_pid(const char *progname);
bool replay_operation_allowed(const char *progname);

void replay_checkpoint(void);
int replay_init_pegmessage(void);

void print_hex_mem(char *mem, int nbyte);
void check_operation(const char *operation, const char *file, int line);

void check_operation_target(char       *expected_operation_target,
                            const char *operation_target,
                            const char *operation,
                            const char *file,
                            int         line);

void check_operation_size(int         expected_size,
                          int         size,
                          const char *operation,
                          const char *operation_target,
                          const char *file,
                          int         line);

void check_operation_contents(char       *expected_buf,
                              char       *buf,
                              const char *operation,
                              const char *operation_target,
                              int         size,
                              const char *file,
                              int         line);

void replay_save_buffer_log(void *buf, size_t len, const char *file, int line);

void start_replay_instance(void);

#define replay_save_buffer(buf, len) replay_save_buffer_log(buf, len, __FILE__, __LINE__)

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

#define OPEN_LOG(path, oflags) open_log(path, oflags, __FILE__, __LINE__)
#define OPEN3_LOG(path, oflags, mode) open3_log(path, oflags, mode, __FILE__, __LINE__)
#define CLOSE_LOG(fildes) close_log(fildes, __FILE__, __LINE__)
#define READ_LOG(filedes, buf, nbytes) read_log(filedes, buf, nbytes, __FILE__, __LINE__)
#define WRITE_LOG(filedex, buf, nbytes) write_log(filedex, buf, nbytes, __FILE__, __LINE__)
#define DPRINTF_LOG(fd, format, ...) dprintf_log(__FILE__, __LINE__, fd, format, ##__VA_ARGS__)
#define FCNTL_LOG(fd, cmd, ...) fcntl_log(__FILE__, __LINE__, fd, cmd, ##__VA_ARGS__)
#define UNLINK_LOG(pathname) unlink_log(pathname, __FILE__, __LINE__)
#define MKSTEMPS_LOG(template, suffixlen) mkstemps_log(template, suffixlen, __FILE__, __LINE__)
#define REMOVE_LOG(path) remove_log(path, __FILE__, __LINE__)
#define FGETXATTR_LOG(fd, name, value, size) fgetxattr_log(fd, name, value, size, __FILE__, __LINE__)
#define RENAME_LOG(oldpath, newpath) rename_log(oldpath, newpath, __FILE__, __LINE__)

// select_replay.c
void fd_zero_log(fd_set *fds);
void fd_set_log(int filedes, fd_set *fds);
int select_log(int nfds,  fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout, const char *file, int line);
int fd_isset_log(int filedes, fd_set *fds_ptr, const char *file, int line);
int poll_log(struct pollfd *fds, nfds_t nfds, int timeout, const char *file, int line);

#define FD_ZERO_LOG(fds) fd_zero_log(fds)
#define FD_SET_LOG(filedes, fds) fd_set_log(filedes, fds)
#define SELECT_LOG(nfds, readfds, writefds, exceptfds, timeout) select_log(nfds, readfds, writefds, exceptfds, timeout, __FILE__, __LINE__)
#define FD_ISSET_LOG(filedes, fds) fd_isset_log(filedes, fds, __FILE__, __LINE__)
#define POLL_LOG(fds, nfds, timeout) poll_log(fds, nfds, timeout, __FILE__, __LINE__)

// file_replay.c
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
int nftw_log(const char *path, int (*fn)(const char *, const struct stat *, int, struct FTW *), int fd_limit, int flags, const char *file, int line);
int symlink_log(const char *path1, const char *path2, const char *file, int line);

#define ACCESS_LOG(pathname, mode) access_log(pathname, mode, __FILE__, __LINE__)
#define FOPEN_LOG(filename, mode) fopen_log((char *) (filename), mode, __FILE__, __LINE__)
#define FDOPEN_LOG(filedes, mode) fdopen_log(filedes, mode, __FILE__, __LINE__);
#define FSEEK_LOG(stream, offset, whence) fseek_log(stream, offset, whence, __FILE__, __LINE__)
#define REWIND_LOG(stream) rewind_log(stream)
#define FTELL_LOG(stream) ftell_log(stream, __FILE__, __LINE__)
#define FGETC_LOG(stream) fgetc_log(stream, __FILE__, __LINE__)
#define FGETS_LOG(s, n, stream) fgets_log(s, n, stream, __FILE__, __LINE__)
#define FREAD_LOG(ptr, size, nitems, stream) fread_log(ptr, size, nitems, stream, __FILE__, __LINE__)
#define FWRITE_LOG(ptr, size, nitems, stream) fwrite_log(ptr, size, nitems, stream, __FILE__, __LINE__)
#define FPUTC_LOG(c, stream) fputc_log(c, stream, __FILE__, __LINE__)
#define FPUTS_LOG(str, stream) fwrite_log((void *) (str), sizeof(char), strlen(str), stream, __FILE__, __LINE__)
#define FSCANF_LOG(stream, format, ...) fscanf_log(__FILE__, __LINE__, stream, format, ##__VA_ARGS__)
#define FCLOSE_LOG(stream) fclose_log(stream, __FILE__, __LINE__)
#define FPRINTF_LOG(stream, format, ...) fprintf_log(__FILE__, __LINE__, stream, format, ##__VA_ARGS__)
#define GETXATTR_LOG(path, name, value, size) getxattr_log(path, name, value, size, __FILE__, __LINE__)
#define SETXATTR_LOG(path, name, value, size, flags) setxattr_log(path, name, value, size, flags, __FILE__, __LINE__)
#define NFTW_LOG(path, fn, fd_limit, flags) nftw_log(path, fn, fd_limit, flags, __FILE__, __LINE__)
#define SYMLINK_LOG(path1, path2) symlink_log(path1, path2, __FILE__, __LINE__)

// dir_replay.c
DIR *opendir_log(const char *dirname, const char *file, int line);
void seekdir_log(DIR *dirp, long loc);
long telldir_log(DIR *dirp, const char *name, const char *file, int line);
void rewinddir_log(DIR *dirp);
struct dirent *readdir_log(DIR *dirp, const char *name, const char *file, int line);
int closedir_log(DIR *dirp);
char *getenv_log(const char *name, const char *file, int line);
int stat_log(const char *path, struct stat *buf, const char *file, int line);
int rmdir_log(const char *path, const char *file, int line);
int mkdir_log(const char *path, mode_t mode, const char *file, int line);

#define OPENDIR_LOG(dirname) opendir_log(dirname, __FILE__, __LINE__)
#define SEEKDIR_LOG(dirp, loc) seekdir_log(dirp, loc)
#define TELLDIR_LOG(dirp) telldir_log(dirp, #dirp, __FILE__, __LINE__)
#define REWINDDIR_LOG(dirp) rewinddir_log(dirp)
#define READDIR_LOG(dirp) readdir_log(dirp, #dirp, __FILE__, __LINE__)
#define CLOSEDIR_LOG(dirp) closedir_log(dirp)
#define GETENV_LOG(name) getenv_log(name, __FILE__, __LINE__)
#define STAT_LOG(path, buf) stat_log(path, buf, __FILE__, __LINE__)
#define RMDIR_LOG(path) rmdir_log(path, __FILE__, __LINE__)
#define MKDIR_LOG(path, mode) mkdir_log(path, mode, __FILE__, __LINE__)

// time_replay.c
time_t time_log(time_t *t, const char *file, int line);
int gettimeofday_log(struct timeval *tv, struct timezone *tz, const char *file, int line);
int clock_gettime_log(clockid_t clk_id, struct timespec *tp, const char *file, int line);

#define TIME_LOG(t) time_log(t, __FILE__, __LINE__)
#define GETTIMEOFDAY_LOG(tv, tz) gettimeofday_log(tv, tz, __FILE__, __LINE__)
#define CLOCK_GETTIME_LOG(clk_id, tp) clock_gettime_log(clk_id, tp, __FILE__, __LINE__)

// socket_replay.c
int socket_log(int domain, int type, int protocol, const char *file, int line);
int setsockopt_log(int socket, int level, int option_name, void *option_value, socklen_t option_len);
int bind_log(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int listen_log(int sockfd, int backlog);
int accept_log(int sockfd, struct sockaddr *addr, socklen_t *addrlen, const char *file, int line);
ssize_t sendto_log(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen, const char *file, int line);
ssize_t sendmsg_log(int socket, const struct msghdr *message, int flags);
ssize_t recvfrom_log(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen, const char *file, int line);
ssize_t recvmsg_log(int sockfd, struct msghdr *msg, int flags, const char *file, int line);
int connect_log(int socket, const struct sockaddr *address, socklen_t address_len);

#define SOCKET_LOG(domain, type, protocol) socket_log(domain, type, protocol, __FILE__, __LINE__)
#define SETSOCKOPT_LOG(socket, level, option_name, option_value, option_len) setsockopt_log(socket, level, option_name, option_value, option_len)
#define BIND_LOG(sockfd, addr, addrlen) bind_log(sockfd, addr, addrlen)
#define LISTEN_LOG(sockfd, backlog) listen_log(sockfd, backlog)
#define ACCEPT_LOG(sockfd, addr, addrlen) accept_log(sockfd, addr, addrlen, __FILE__, __LINE__)
#define SENDTO_LOG(sockfd, buf, len, flags, dest_addr, addrlen) sendto_log(sockfd, buf, len, flags, dest_addr, addrlen, __FILE__, __LINE__)
#define SEND_LOG(sockfd, buf, len, flags) sendto_log(sockfd, buf, len, flags, NULL, 0, __FILE__, __LINE__)
#define SENDMSG_LOG(socket, message, flags) sendmsg_log(socket, message, flags)
#define RECVFROM_LOG(sockfd, buf, len, flags, src_addr, addrlen) recvfrom_log(sockfd, buf, len, flags, src_addr, addrlen, __FILE__, __LINE__)
#define RECV_LOG(sockfd, buf, len, flags) recvfrom_log(sockfd, buf, len, flags, NULL, NULL, __FILE__, __LINE__)
#define RECVMSG_LOG(sockfd, msg, flags) recvmsg_log(sockfd, msg, flags, __FILE__, __LINE__)
#define CONNECT_LOG(socket, address, address_len) connect_log(socket, address, address_len)

// socketinfo_replay.c
int getifaddrs_log(struct ifaddrs **ifap, const char *file, int line);
void freeifaddrs_log(struct ifaddrs *ifa);
int getaddrinfo_log(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **ai, const char *file, int line);
void freeaddrinfo_log(struct addrinfo *res);
int getsockname_log(int sockfd, struct sockaddr *addr, socklen_t *addrlen, const char *name, const char *file, int line);

#define GETIFADDRS_LOG(ifap) getifaddrs_log(ifap, __FILE__, __LINE__)
#define FREEIFADDRS_LOG(ifa) freeifaddrs_log(ifa)
#define GETADDRINFO_LOG(node, service, hints, res) getaddrinfo_log(node, service, hints, res, __FILE__, __LINE__)
#define FREEADDRINFO_LOG(res) freeaddrinfo_log(res)
#define GETSOCKNAME_LOG(sockfd, addr, addrlen) getsockname_log(sockfd, addr, addrlen, #sockfd, __FILE__, __LINE__)

// fork_replay.c
pid_t fork_log(void);
pid_t waitpid_log(pid_t pid, int *status, int options, const char *name, const char *file, int line);
int execl_log(const char *path, const char *arg, ...  /* (char  *) NULL */);
int execlp_log(const char *file, const char *arg, ... /* (char  *) NULL */);
int execv_log(const char *path, char *const argv[]);
int execvp_log(const char *file, char *const argv[]);

#define FORK_LOG() fork_log()
#define WAITPID_LOG(pid, status, options) waitpid_log(pid, status, options, #pid, __FILE__, __LINE__)
#define EXECL_LOG(path, arg, ...) execl_log(path, arg, __VA_ARGS__)
#define EXECLP_LOG(path, arg, ...) execlp_log(path, arg, __VA_ARGS__)
#define EXECV_LOG(path, argv) execv_log(path, argv)
#define EXECVP_LOG(path, argv) execvp_log(path, argv)

// random_replay.c
void gcry_randomize_log(void                   *buffer,
                        size_t                  length,
                        enum gcry_random_level  level,
                        const char             *file,
                        int                     line);

void gcry_create_nonce_log(void       *buffer,
                           size_t      length,
                           const char *file,
                           int         line);

#define GCRY_RANDOMIZE_LOG(buffer, length, level) gcry_randomize_log(buffer, length, level, __FILE__, __LINE__)
#define GCRY_CREATE_NONCE_LOG(buffer, length) gcry_create_nonce_log(buffer, length, __FILE__, __LINE__)

// screen_replay.c
#ifndef REPLAY_DONT_INCLUDE_SDL
  //    void SDL_PumpEvents_log(void);
  //    int SDL_PeepEvents_log(SDL_Event *events, int numevents, SDL_eventaction action, Uint32 minType, Uint32 maxType, const char *name, const char *file, int line);
#endif
ssize_t sendto_image_info_log(int sockfd, void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen, const char *file, int line);
ssize_t sendto_image_log(int sockfd, void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen, const char *file, int line);
int write_image_info_log(int fildex, const void *buf, size_t nbyte, const char *file, int line);
int write_image_log(int fildex, const void *buf, size_t nbyte, const char *file, int line);
int read_image_log(int filedes, void *buf, size_t nbyte, const char *file, int line);
size_t fread_image_log(void *ptr, size_t size, size_t nitems, FILE *stream, const char *file, int line);
uint32_t auto_trigger_rle_compress_log(uint32_t   *output,
                                       uint32_t    output_max_length,
                                       uint32_t   *input,
                                       uint32_t    input_length,
                                       uint32_t    trigger_level,
                                       uint32_t    flags,
                                       const char *file,
                                       int         line);

uint32_t auto_trigger_rle_decompress_log(uint32_t   *output,
                                         uint32_t    output_max_length,
                                         uint32_t   *input,
                                         uint32_t    input_length,
                                         uint32_t    trigger_level,
                                         uint32_t    flags,
                                         const char *file,
                                         int         line);

#ifndef REPLAY_DONT_INCLUDE_SDL
  //    #define SDL_PUMPEVENTS_LOG SDL_PumpEvents_log();
  //    #define SDL_PEEPEVENTS_LOG(events, numevents, action, minType, maxType) SDL_PeepEvents_log(events, numevents, action, minType, maxType, #events, __FILE__, __LINE__)
#endif
#define SENDTO_IMAGE_INFO_LOG(sockfd, buf, len, flags, dest_addr, addrlen) sendto_image_info_log(sockfd, buf, len, flags, dest_addr, addrlen, __FILE__, __LINE__)
#define SENDTO_IMAGE_LOG(sockfd, buf, len, flags, dest_addr, addrlen) sendto_image_log(sockfd, buf, len, flags, dest_addr, addrlen, __FILE__, __LINE__)
#define WRITE_IMAGE_INFO_LOG(fildex, buf, nbyte) write_image_info_log(fildex, buf, nbyte, __FILE__, __LINE__)
#define WRITE_IMAGE_LOG(fildex, buf, nbyte) write_image_log(fildex, buf, nbyte, __FILE__, __LINE__)
#define READ_IMAGE_LOG(filedes, buf, nbytes) read_image_log(filedes, buf, nbytes, __FILE__, __LINE__)
#define FREAD_IMAGE_LOG(ptr, size, nitems, stream) fread_image_log(ptr, size, nitems, stream, __FILE__, __LINE__)
#define AUTO_TRIGGER_RLE_COMPRESS_LOG(output, output_max_length, input, input_length, trigger_level, flags) auto_trigger_rle_compress_log(output, output_max_length, input, input_length, trigger_level, flags, __FILE__, __LINE__)
#define AUTO_TRIGGER_RLE_DECOMPRESS_LOG(output, output_max_length, input, input_length, trigger_level, flags) auto_trigger_rle_decompress_log(output, output_max_length, input, input_length, trigger_level, flags, __FILE__, __LINE__)

#ifdef __cplusplus
}
#endif

#endif // __REPLAY_H__
