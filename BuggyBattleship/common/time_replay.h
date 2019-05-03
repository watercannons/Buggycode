
// Replay is only for linux builds
#ifndef TARGET_LINUX
// TODO: Add defines so that <FUNCTION>_LOG functions still work
#define __TIME_REPLAY_H__
#endif

#ifdef __USE_TREPLAY
#include "time_treplay.h"
#define __TIME_REPLAY_H__
#endif

#ifndef __TIME_REPLAY_H__
#define __TIME_REPLAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include <sys/time.h> // struct timezone
#include <assert.h>

time_t time_log(time_t *t, const char *file, int line);
int gettimeofday_log(struct timeval *tv, struct timezone *tz, const char *file, int line);
int clock_gettime_log(clockid_t clk_id, struct timespec *tp, const char *file, int line);

#define time(t) \
	time_log(t, __FILE__, __LINE__)
#define gettimeofday(tv, tz) \
	gettimeofday_log(tv, tz, __FILE__, __LINE__)
#define clock_gettime(clk_id, tp) \
	clock_gettime_log(clk_id, tp, __FILE__, __LINE__)

#ifdef __cplusplus
}
#endif

#endif // __TIME_REPLAY_H__
