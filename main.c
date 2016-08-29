#include <stdio.h>
#include <stdlib.h>

#include "main.h"

void swapHL()
{
  newtPushHelpLine("Appuyez sur une touche pour continuer.");
  newtRefresh();
  usleep(200);
}

int main(int c, char **v)
{
  (void)c;
  (void)v;
  srand(time(0));
  newtInit();
  newtCls();

  newtDrawRootText(0, 0, "Service telematique H.A.D.O.P.I.");
  #include "logo.out.c"
  int i = 3;
  while (--i)
    swapHL();

  newtWaitForKey();
  disp_login();

  newtFinished();
  return 0;
}

