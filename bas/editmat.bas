
#include <hbasic.h>

Begin
  Declare as Stack (lotus)
  
  New Row(lotus → "Juanito Perez Cotapos",250000,"A01")
  New Row(lotus → "Pedro Alvarez",750000,"A03")
  New Row(lotus → "Mauricio Lopez",1500000,"B04")
  
  //Let( lotus := Str$(lotus) )
  n=0, Let ( n := Len(lotus))
/*  nRows=0, Let(nRows:=MyRows(lotus))
  nCols=0, Let(nCols:=MyCols(lotus))
  MaxCol=0,i=0
  For Up( i:=1, nCols, 1 )
     For Up( i:=1, nRows, 1 ) 
     lotus[1,2]
     */
     
//  t=0, Let ( t := Val(lotus) )
  t=0, Let ( t := Find All( Numeric?(lotus) ) )
  
  If ( Is Numeric?([1,2]Get(lotus) ) )
     Take(" ",9), LPad$(Str$([1:end,2]Get(lotus))), and SPut(lotus)
  End If
  
  m=0, Set interval [1:end,1] and Let( m := MaxValue(Get(n)))
  then Take(" ",m), Get(lotus), RPad$, and SPut(lotus)
  
  Cls
  Set Token("|"),Locate(5,5)
  Print Table(lotus)
 
  Print("Numericos=\n",t,¶)

End
