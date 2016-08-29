#ifndef _WELCOME_H_
#define _WELCOME_H_

#include <newt.h>
//#include <stdio.h>

#include "auth.h"
#include "ad.h"
#include "util.h"

void disp_login(void);

void good_login(int);
void fail_login(void);


char login_ok(int *, const char *, const char *);  


#endif
