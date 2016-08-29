#include "ad.h"



void display_text_ad(const char *ad)
{
  newtDrawRootText(AD_L, AD_C, ad);  
  newtRefresh();
}
