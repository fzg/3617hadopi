#include "welcome.h"

void disp_login()
{
  display_text_ad("Votre pub ici ;-)");

  newtOpenWindow(2, 12, 38, 5, "Identification");

  newtComponent loginForm = newtForm(0, 0, 0);
  char *_l, *_p;
  newtComponent b = newtButton(28, 1, "Envoi");
  newtComponent ll = newtLabel(2, 1, "Compte:");
  newtComponent pl = newtLabel(2, 3, "Mot de passe:");
  newtComponent l = newtEntry(10, 1, "", 16, (const char**)(&_l), NEWT_FLAG_SCROLL);
  newtComponent p = newtEntry(16, 3, "", 8, (const char**)(&_p), NEWT_FLAG_PASSWORD);

  newtFormAddComponents(loginForm, ll, l, pl, p, b, 0);
  newtPushHelpLine("Veuillez vous identifier.");
  newtRunForm(loginForm);
  
  int uid;
  char login_result;
  if (*_l && *_p) 
  trylogaccess(_l, _p);
  newtPopHelpLine();
  login_result = login_ok(&uid, _l, _p);
  newtFormDestroy(loginForm);
  newtPopWindow();
  newtPopHelpLine();
  if (!login_result)
    good_login(uid);
  else
    fail_login();
}

char login_ok(int *uid, const char *u, const char *p)
{
  char ret = auth_attempt(u, p);
  if (ret >= 0) 
    *uid = ret;
  return (ret >= 0)? 0 : ret;
}


void good_login(int uid)
{
  (void)uid;
  newtOpenWindow(6, 4, 12, 12, "Acces suspendu.");
  newtComponent f, l, b;
  l = newtLabel(1, 1, "Vous avez perdu vos droits d'acces.");
  b = newtButton(4, 4, "Anayfay");
  f = newtForm(NULL, NULL, 0);
  newtFormAddComponents(f, l, b, 0);
  newtRunForm(f);
  newtFormDestroy(f);
  newtPopWindow();
}

void fail_login()
{
  newtPushHelpLine("Verification des informations d'acces. Veuillez patienter");
  newtRefresh();
  randwait();
  newtPushHelpLine("Echec d'identification.");
  newtWaitForKey();
  newtFinished();
}
