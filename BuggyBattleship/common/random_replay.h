
// Replay is only for linux builds
#ifndef TARGET_LINUX
// TODO: Add defines so that <FUNCTION>_LOG functions still work
#define __RANDOM_REPLAY_H__
#endif

#ifdef __USE_TREPLAY
#include "random_treplay.h"
#define __RANDOM_REPLAY_H__
#endif

#ifndef __RANDOM_REPLAY_H__
#define __RANDOM_REPLAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <gcrypt.h>

void gcry_randomize_log(void                   *buffer,
                        size_t                  length,
                        enum gcry_random_level  level,
                        const char             *file,
                        int                     line);

void gcry_create_nonce_log(void       *buffer,
                           size_t      length,
                           const char *file,
                           int         line);

#define gcry_randomize(buffer, length, level) \
	gcry_randomize_log(buffer, length, level, __FILE__, __LINE__)
#define gcry_create_nonce(buffer, length) \
	gcry_create_nonce_log(buffer, length, __FILE__, __LINE__)

#ifdef __cplusplus
}
#endif

#endif // __RANDOM_REPLAY_H__
