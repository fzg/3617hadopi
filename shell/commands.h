#ifndef _CMD_H_
#define _CMD_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_cmd {
  const char	*name;
  void		(*func)(const char *);
}		t_cmd;

//t_cmd gl_commands[];

void a_pouet(const char *);
void a_bye(const char *);
void a_help(const char *);

#endif
