#ifndef _UTIL_H_
#define _UTIL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_WAIT 5

void randwait(void);

void trylogaccess(const char *, const char *);

#endif
