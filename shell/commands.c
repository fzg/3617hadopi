#include "commands.h"

void a_bye(const char *parm)
{
  (void)parm;
  puts("Bye");
  exit(0);
}

void a_pouet(const char *parm)
{
  (void)parm;
  puts("POUET");
}

void a_help(const char *p)
{
  (void)p;
  printf("Available commands:\n\tpouet bye help\n");
}
