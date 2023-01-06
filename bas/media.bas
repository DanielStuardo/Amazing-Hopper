
#include <hbasic.h>

#proto __Varianza__(__X__)
#synon ___Varianza__   Variance
#proto __Standar__Desviation__(__X__)
#synon ___Standar__Desviation__  StandardDeviation
Begin
   //x={},
   Seed(1234)
   Declare as Numeric (v,M,x)
           as Stack (y)

   Dim (100000) as Int Rnd Array(x,10)
   
   Let( M := Mean(x) )
   Let( v := Summatory( Sub(x, M),Powby(2) ), Divby(Length(x)))
   Print("Promedio: ",M,¶,"Varianza: ",v,¶)
   
   Print("Promedio: ",M,¶,"Varianza: ",Variance(x),¶,"Desviación estandar: ", Standard Deviation(x), ¶)
   
   Take(7,4.5,4.0,6.7,6.7), Push All(y)
   Print("Media = ",Mean(y),¶ )
End
Subrutines

__Varianza__(X)
  Summatory( Sub(x, Mean(X)),Powby(2) ), Divby(Length(X))
  Clear(X)
Return
__Standar__Desviation__(X)
  Sqrt( Summatory( Sub(x, Mean(X)),Powby(2) ), Divby(Length(X)) )
  Clear(X)
Return
