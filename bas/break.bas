
#include <hbasic.h>

Begin
   i=0
   While( var(i) Is Le '1000' )
      Print( "I=",i, Newl )
      If ( are Eq(i,500) )
         then Break
      End If
      ++i
   Wend
End
