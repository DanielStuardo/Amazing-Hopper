#include <hbasic.h>

Begin
   X=0,m1=0,m2=0
   Cls
   Token Sep(" ")
   Let (X:=Calendar( 1,2022,3) )
   Print(X,Newl)
   
//   Let( m1 := [1:8,1:end]Get(X) )
   Let( m2 := [9:16,1:end]SGet(X) )
   Print(m2,Newl)
   
   //
//   Locate(15,5), Print Table(m1)
//   Locate(5,50), Print Table(m2)
   //Bold,ForeGround(69),
/*   Print("Calendario Mes 1:",Newl)   //,Bold Off
   Down(1),Print Table(m1)
   //Locate(10,36)
   Down(4),Fw(31)
   //Bold,ForeGround(214),
   Print("Calendario Mes 2:",Newl)   //,Bold Off
   Down(1),Print Table(m2)
   Jump Lines(7) */
End
