
#include <hbasic.h>

Begin
   Dec as Numeric (T,flag,i, matches, Res,e)
       as Numeric (desde, hasta)
       as Alpha (r,nuevo Número)

//   r="\+56\s[0-9]\s[0-9]{4}\s[0-9]{4}"
//   r="\+(56|49)\s[0-9]\s[0-9]{4}\s[0-9]{4}"
//   r="\+(56|49)\s[0-9](\s[0-9]{4}){2}"
   r="\+[1-9]{2,3}\s[0-9](\s[0-9]{3,4}){2}"

   text="Carlos\n+56 2 3899 7269\nPedro\n+49 2 2908 7712\nLuisa\n+56 2 2997 5670\nMaria\n+47 3 288 908"
   Print(text,Newl,Newl)
   
   flag = REG_EXTENDED  //BASIC

   Pivot(T)
      RECompile(flag,r)
      Let( matches := REMatch(0,1,text) ) 
      REFree
   Try
      Let( Res := MyRows(matches) )
   Catch(e)
      Res=0
      Print("No matching!",Newl)
   Finish

   Print("Tipo matches=",Type$(matches),Newl)

  // limpiando espacios y caracter "+":
   For( i=Res, while var 'i' Is Gt( 0 ) and Array?(matches),  --i)
      Let (nuevo Número := DelChar$("+ ",[i,3]Get(matches) ))
      Let( desde:=[i,1]Get(matches) )
      and Let( hasta:=[i,2]Get(matches) )
      Take(Sub(hasta,desde) Plus(1), desde), then Let( text := Repl$(nuevo Número, text) )
   Next
   get CurX(x), and get CurY(y)
   Print(text,Newl,Newl)
   and Print("Ultima posicion registrada por LOCATE:",x,", ",y,Newl)
   Take(5), Power of (2), and Print It with a Newl
End

