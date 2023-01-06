#include <hbasic.h>

#import lib/input.bas.lib
#include include/input.h

Begin
  Cls
  Print( Utf8$("Impresión de código ASCII:"), Newl )
  For Up ( i:=1, 255, 1 )
     Print (Utf8$(Chr$(i)),"-")
  Next
  msg=0, Locate(10,5)
  Let ( msg := ReadString(msg) )
  Print ( msg, Newl )
End
