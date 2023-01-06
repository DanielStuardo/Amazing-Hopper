
#include <hbasic.h>

Begin
  s=0
//  formato="numeros $0, [$1], $2"
  Take(200,1000,"hola mundo!" ), Let(s:=Format$( "numeros $0, [$1], $2" )) //, Move(s)
  
  Print( s, Newl)
  now Mem ( 1000 ), Let (s:=Format$("<$0>")), and Print(s, Newl)
End
