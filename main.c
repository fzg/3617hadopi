#include <stdio.h>
#include <stdlib.h>

#include "main.h"


char swapHL()
{
  static char u = 0;
  struct timeval tv = {0, 500000};
  newtPopHelpLine();
  if (++u%2) newtPushHelpLine("Appuyez sur une touche pour continuer.");
  else     newtPushHelpLine(" ");
  newtBell();
  newtRefresh();
  return waitforkeywithtimeout(&tv);
}

int main(int c, char **v)
{
  (void)c, (void)v;

  newtInit();
  newtCls();
  newtPushHelpLine(NULL);

  newtDrawRootText(0, 0, "Service telematique H.A.D.O.P.I.");
  #include "logo.out.c"

  while (!swapHL());
//  newtWaitForKey();
  disp_login();

  newtFinished();
  return 0;
}

