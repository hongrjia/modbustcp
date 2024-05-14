//
// Created by Administrator on 2023/10/25.
//

#ifndef MOBBUS_SERVER_UTIL_H
#define MOBBUS_SERVER_UTIL_H

#include <time.h>
#include <stdio.h>
#include <sys/time.h>

#define NLOOP_FOR_ESTIMATION 1000000000UL
#define NSECS_PER_MSEC 1000000UL
#define NSECS_PER_SEC 1000000000UL

#define DiffNS(begin, end) ((end.tv_sec - begin.tv_sec) * NSECS_PER_SEC \
                            + (end.tv_nsec - begin.tv_nsec))

extern struct timespec g_tbegin;
extern struct timespec g_tend;

extern struct tm *pTempTmEnd;
extern struct tm *pTempTmStr;

void Rtrim(char *string);
void Ltrim(char *string);
#endif //MOBBUS_SERVER_UTIL_H
