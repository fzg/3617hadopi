#include "auth.h"

static char check_pgm(const char *pn)
{
  return ((access(pn, R_OK | X_OK)) != -1);
}

char handle_arg(const char *ibuf)
{
  const char *path = "./";
  char *arg, *cooked_arg, *end;
  long int argnum;

  if ((arg = rindex(ibuf, (int)SEPARATOR) + 1))
    {
      argnum = strtoll(arg, &end, 10);
      if (errno != ERANGE && *end == '\n')
	return (char) argnum;
      else
	if ((cooked_arg = malloc (2 + strlen(arg))))
	  {
	    memset(cooked_arg, 0, strlen(arg) + 2);
	    strcpy(cooked_arg, path);
	    strcpy(cooked_arg + strlen(path), arg);
	    cooked_arg[strlen(path) + strlen(arg) - 1] = 0; // eat trailing \n
	    newtFinished();
	    if (check_pgm(cooked_arg))
	      execl(cooked_arg, cooked_arg, NULL);
	    fprintf(stderr, "%s: %s", cooked_arg, strerror(errno));
	  }
    }
  return AUTH_ERROR;
}

char auth_attempt(const char *l, const char *p)
{
  char ibuf[LINELEN], *ib = (&ibuf[0]);
  FILE *inf;

  if (!*l || !*p)
    return AUTH_FAIL;
  memset(&ibuf, 0, LINELEN);
  if ((inf = fopen(AUTH_FILE, "r"))) {
    while (fgets(ib, LINELEN - 1, inf))
      {
	if (!strncmp(l, ibuf, strlen(l)))
	  {// login match
	    fclose(inf);
	    if (!strncmp(p, ibuf + strlen(l) + 1, strlen(p)))
	      return handle_arg(ibuf); // pass match
	    else
	      return AUTH_FAIL; // pass fail
	  }
      }
  }
  return AUTH_ERROR;
}
