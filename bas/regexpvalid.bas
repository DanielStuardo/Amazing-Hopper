#include <hbasic.h>

Begin
   flag=REG_EXTENDED
   flag |=REG_NEWLINE
   flag |= REG_NOSUB
   T=0
   
   R="^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$"

      RECompile(flag,R,T)
      flag=0
      Print( "IP valida? ", Get If( REValid( flag,"255.255.0.0",T), "Si", "No" ), Newl )
      Print( "IP valida? ", Get If( REValid( flag,"256.255.0.0",T), "Si", "No" ), Newl )
      REFree(T)
End
