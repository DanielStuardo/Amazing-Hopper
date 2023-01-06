
#include <hbasic.h>

Begin
  s="home/src/man/archivo.txt"
  
  Print( Cut$("/",s), Newl)
  Print( RCut$("/",s), Newl)
  
  Print( BtwnCut$( s ,"/", "/"), Newl)
End
