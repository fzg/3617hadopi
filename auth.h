#ifndef _AUTH_H_
#define _AUTH_H_

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <newt.h>

#define LINELEN 4096
#define AUTH_FILE "/tmp/auth.list"
#define SEPARATOR ':'

#define AUTH_ERROR -1
#define AUTH_FAIL  -2

extern char **environ;

char handle_arg(const char *);
char auth_attempt(const char *, const char *);

#endif
