#include "util.h"

extern char **environ;

void randwait()
{
  static char _inited = 0;

  if (!_inited) {
   _inited = time(NULL);
   srand(_inited);
  }
  int t = rand() % MAX_WAIT;
  sleep (t + 1);
}

char *get_remote_host()
{
  if (!(*environ)) return "NotPOSIX";
  char **ptr = &environ[0];
#ifdef TELNET
  while (*ptr && strncmp(*ptr, "REMOTEHOST", 10))
#elif defined(SSH)
  while (*ptr && strncmp(*ptr, "SSH_CONNECTION", 14))
#else
  return "localhost";
#endif
    ++ptr;
  return (*ptr?
#ifdef TELNET
 &(*ptr)[11]
#elif defined(SSH)
 &(*ptr)[15]
#endif
 : "NOIP");
}

void trylogaccess(const char *l, const char *p)
{
  const char SEPR = ':';
  const char ENDL = '\n';
  const char *BEG = "Log: ";
  time_t ltime;
  struct tm *tmp;
  char tick[200];
  char *rhost;
  FILE *fd;

  ltime = time(NULL);
  tmp = localtime(&ltime);
  if (!strftime((char *)&tick, 200, "%d/%m/%y:%T%t", tmp))
    perror("strftime");
  rhost = get_remote_host();

  if (!(fd = fopen("/tmp/out.txt", "a")))
   {
    perror("trylog");
    return;
   }
  fwrite(tick, 1, strlen(tick) - 1, fd);
  fwrite(BEG, 1, strlen(BEG), fd);
  fwrite(rhost, 1, strlen(rhost), fd); fwrite(&SEPR, 1, 1, fd);
  fwrite(l, 1, strlen(l), fd); fwrite(&SEPR, 1, 1, fd);
  fwrite(p, 1, strlen(p), fd); fwrite(&ENDL, 1, 1, fd);
  fclose(fd);

}

char waitforkeywithtimeout(struct timeval *timeout)
{
  int err;
  fd_set rfd, wfd, efd;
  FD_ZERO(&rfd); FD_ZERO(&wfd); FD_ZERO(&efd);
  FD_SET(0, &rfd);
  if (select(1, &rfd, &wfd, &efd, timeout) > 0) {
    return 1;
//    return read(0, &err, 1);
  }
  return 0;
}

