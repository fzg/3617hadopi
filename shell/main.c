#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "commands.h"

extern t_cmd gl_commands[];

void handle_input(const char *in)
{
  if (!in) return;
  t_cmd *cur = &gl_commands[0];
  while (cur && cur->name && strncmp(cur->name, in, strlen(cur->name)))
    ++cur;
  if (cur->name)
    cur->func(in + strlen(cur->name) + 1);
  else
    puts("BAD");
}


int main(int c, char **v)
{
  char *read;
  const char *prompt = "TGSh# ";

  if (c > 1)
    printf("Good day %s. Where do you want to go today?\n", v[1]);
  else
    printf("Access granted to Anonymous.\n");
  do {
    handle_input((read = readline(prompt)));
  } while (42);

  return (0);
}
