
#include <hbasic.h>
/////#include <token.h>

Begin
  m="Mundo"
  PrintF(Str2Utf8$("Hola $0!!, número: [$1]\n"),m,Sqrt(250))
  
  Print(BtwnCut$( "Hola--OvO--mundo!","a","m"), Newl)
  
  t="token1,token2,token3"
  Using(t)
     Tkn(2),
     
            Take("mercado libre"), 
            TknPut$,
     Tkn(2), TknDel$
            // TknRepl$("Merme") 
     Flush(t)
  Print( t, Newl)
Stop
