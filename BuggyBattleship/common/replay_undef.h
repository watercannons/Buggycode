
// Replay only exists on linux
#ifdef TARGET_LINUX

#ifndef __REPLAY_H__
#ifndef REPLAY_H
#define savebuf INCLUDE_REPLAY_H
#endif
#endif

#ifndef __SELECT_REPLAY_H__
#ifndef SELECT_REPLAY_H
#define select INCLUDE_SELECT_REPLAY_H
#undef FD_ISSET
#define FD_ISSET INCLUDE_SELECT_REPLAY_H
#define poll INCLUDE_SELECT_REPLAY_H
#endif
#endif

#ifndef __FILE_REPLAY_H__
#ifndef FILE_REPLAY_H
#define access INCLUDE_FILE_REPLAY_H
#define fopen INCLUDE_FILE_REPLAY_H
#define fdopen INCLUDE_FILE_REPLAY_H
#define fseek INCLUDE_FILE_REPLAY_H
#define ftell INCLUDE_FILE_REPLAY_H
#define fgetc INCLUDE_FILE_REPLAY_H
#define fgets INCLUDE_FILE_REPLAY_H
#define fread INCLUDE_FILE_REPLAY_H
#define fwrite INCLUDE_FILE_REPLAY_H
#define fclose INCLUDE_FILE_REPLAY_H
#define fprintf INCLUDE_FILE_REPLAY_H
#define getxattr INCLUDE_FILE_REPLAY_H
#define setxattr INCLUDE_FILE_REPLAY_H
#define nftw_func INCLUDE_FILE_REPLAY_H
#define nftw INCLUDE_FILE_REPLAY_H
#undef fscanf
#define fscanf INCLUDE_FILE_REPLAY_H
#define readlink INCLUDE_FILE_REPLAY_H
#define fread_image INCLUDE_FILE_REPLAY_H
#define symlink INCLUDE_FILE_REPLAY_H
#endif
#endif

#ifndef __SOCKETINFO_REPLAY_H__
#ifndef SOCKETINFO_REPLAY_H
#define getsockname INCLUDE_SOCKETINFO_REPLAY_H
#endif
#endif

#ifndef __SOCKET_REPLAY_H__
#ifndef SOCKET_REPLAY_H
#define socket INCLUDE_SOCKET_REPLAY_H
#define accept INCLUDE_SOCKET_REPLAY_H
#define sendto INCLUDE_SOCKET_REPLAY_H
#define recvfrom INCLUDE_SOCKET_REPLAY_H
#define recvmsg INCLUDE_SOCKET_REPLAY_H
#define sendmsg INCLUDE_SOCKET_REPLAY_H
#endif
#endif

#ifndef __FORK_REPLAY_H__
#ifndef FORK_REPLAY_H
#define waitpid INCLUDE_FORK_REPLAY_H
#define fork INCLUDE_FORK_REPLAY_H
#endif
#endif

#ifndef __RANDOM_REPLAY_H__
#ifndef RANDOM_REPLAY_H
#define gcry_randomize INCLUDE_RANDOM_REPLAY_H
#define gcry_create_nonce INCLUDE_RANDOM_REPLAY_H
#endif
#endif

#ifndef __CURL_REPLAY_H__
#ifndef CURL_REPLAY_H
#define curl_easy_perform INCLUDE_CURL_REPLAY_H
#define curl_easy_getinfo INCLUDE_CURL_REPLAY_H
#endif
#endif

#ifndef __TIME_REPLAY_H__
#ifndef TIME_REPLAY_H
#define time INCLUDE_TIME_REPLAY_H
#define gettimeofday INCLUDE_TIME_REPLAY_H
#define clock_gettime INCLUDE_TIME_REPLAY_H
#endif
#endif

#ifndef __SCREEN_REPLAY_H__
#ifndef SCREEN_REPLAY_H
#define SDL_PeepEvents INCLUDE_SCREEN_REPLAY_H
#define imagewrite INCLUDE_SCREEN_REPLAY_H
#define auto_trigger_rle_compress INCLUDE_SCREEN_REPLAY_H
#define auto_trigger_rle_decompress INCLUDE_SCREEN_REPLAY_H
#endif
#endif

#ifndef __DIR_REPLAY_H__
#ifndef DIR_REPLAY_H
#define opendir INCLUDE_DIR_REPLAY_H
#define telldir INCLUDE_DIR_REPLAY_H
#define readdir INCLUDE_DIR_REPLAY_H
#define stat INCLUDE_DIR_REPLAY_H
#define rmdir INCLUDE_DIR_REPLAY_H
#define mkdir INCLUDE_DIR_REPLAY_H
#define lstat INCLUDE_DIR_REPLAY_H
#endif
#endif

#ifndef __FD_REPLAY_H__
#ifndef FD_REPLAY_H
#define open INCLUDE_FD_REPLAY_H
#define close INCLUDE_FD_REPLAY_H
#define read INCLUDE_FD_REPLAY_H
#define write INCLUDE_FD_REPLAY_H
#define dprintf INCLUDE_FD_REPLAY_H
#define unlink INCLUDE_FD_REPLAY_H
#define mkstemps INCLUDE_FD_REPLAY_H
#define remove INCLUDE_FD_REPLAY_H
#define fgetxattr INCLUDE_FD_REPLAY_H
#define rename INCLUDE_FD_REPLAY_H
#define read_image INCLUDE_FD_REPLAY_H
#define fcntl INCLUDE_FD_REPLAY_H
#endif
#endif

#endif // TARGET_LINUX
