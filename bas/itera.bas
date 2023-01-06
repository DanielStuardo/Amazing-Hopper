#!/usr/bin/hopper


// Archivo Hopper-Basic
#include <hbasic.h>

#define TranArrayUtf8$(__X__)   ___i___=0,___nLen___=0,\
                                Let ( ___nLen___ := Length(__X__) )\
                                Iterator( ___i___:=1, ++___i___, while Le(___i___, ___nLen___),\
                                          Utf8$( [___i___]Get(__X__) ), then SPut(__X__) )

//#define-a  »»(__X__) ;mov(__X__)
//#define-a  »(__X__)  ;cpy(__X__)

#define    IGet$(__N__,__X__)   [__N__,2]SGet(__X__) // [__N__]getenum(__X__)
#define    IPut$(__N__,__X__)   [__N__,2]SPut(__X__)

Begin
   Dim (10000) as Array(S)
   S="María tenía un corderito"
   Print(S, Newl)
   Tran Array Utf8$( S )
   Print(S,Newl,"Size = ",get Rows(S),Newl)

   t="#include <hbasic.h>\nBegin\n\n   x=10,y=5\n\n   Print( Add(x,y), Newl)\nEnd"
   Let( t:= Tran$("\n \n","\n\n",t))
   Print(t, Newl)
  // Token Sep( Newl )
   EnumString(t, 1, Newl) 
   Token Sep(",")
//   Tran$("",Newl,[1:end,2]Get(t)), SPut(t)
   Print(t, Newl,Duplicate It)
   dato=0
   Print( IGet$(1,t)»(dato)," Len=",Len(dato), Newl)
   UCase$(IGet$(1,t)), IPut$(1,t)
   Print(t,Newl)
   Take(" ",3); At Interval [1:end,1], Str$( Get(t) ), get LPad$ + (" "), and SPut(t)
   Set Interval [1:end,2]  Cat$(" ",Get(t)) and SPut(t)
   
   Token Sep(":");Save Matrix( t, "chico.bas")
   
   If ( Is Array?(t) )
      Print("Es un array\n")
   End If
   If ( var(t) Is Array? )
      Print("Es un array\n")
   End If
End
