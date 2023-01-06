
#include <hbasic.h>
#include <pivot.h>

Begin
   n=0
   Pivot(n)
      ParsNormal$("nombre","","Juanito Perez")
   Flush(n)
   
   s="Cogito Ergo Sum"
   Token Sep(" ")
   Pivot(Upper$(s))
      Tkn(2), TknRepl$("eRGO")
      Tkn(1), TknSwap$(3)
   Flush(s)
   Token Sep(",")
   
   d=0
   Pivot(DateNow$)
      If ( Not(~LeapYear? ))
         Print( Str2Utf8$("No es año bisiesto"),¶)
      Else
         Print("Es el mes de ",GetMonth$,¶)
      End If
      If ( Eq(~GetMonth,1) )
         Print("Sigue siendo enero!\nCambiaremos a Marzo...\n")
         Token Sep("/")
         Tkn(2),TknRepl$(Str$(Add(~GetMonth,2)))
         Token Sep(",")
      End If
   Flush(d)
   
   Print("\tN=",n,¶,"\tS=",s,"\n\tFecha=",d,¶)
End
