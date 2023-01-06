
#include <hbasic.h>

Begin
   Option Ctrl+C
   c=0
   While (1)
      If Key Pressed?
         ScanCode(c)
         If ( var(c) Is Eq? (K_ENTER) )
            Break
         End If
      End If
      Print( "CODE = ", c, Newl )
   Wend
End
