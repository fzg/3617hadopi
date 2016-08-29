#include "commands.h"

const t_cmd gl_commands[] = {
  {"bye", &a_bye},
  {"pouet", &a_pouet},
  {"help", &a_help},
  {NULL, NULL}
};
