#ifndef __SLEEP_H__
#define __SLEEP_H__

#ifdef _WIN32

#include <windows.h>
#define SLEEP(ms) Sleep(ms)

#else

#include <unistd.h>
#define SLEEP(ms) usleep(ms * 1000)

#endif 
#endif // __SLEEP_H__
