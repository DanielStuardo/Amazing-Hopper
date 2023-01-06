

#include <hbasic.h>
#proto Add_(_X_,_Y_) 
#synon _Add_  GetSuma,Invert
#define GetInverse   Inv   // Inv es una definición; luego, funciona que declare esto, a un #synon

// carga librería de entrada de datos
#import lib/input.bas.lib
#include include/input.h

Begin
  Cls
  Locate (0,0)
  Print("Suma = ",_Add_(10,10),¶)
  Print("Suma = ",Get Suma(10,10),¶)
  Print("Suma = ",Invert(10,10),¶)
  Take("Inverso de 10 = ",10),GetInverse,Print It with a Newl
  Print("Inverso(10) = ",Inv(10),¶)
  Locate (7,5),Print("Ingrese algo: ")
  msg=""
  /*LocCol (19),*/Fw(14), Let( msg := Input String(msg) )
  Print( Utf8$("\nIngresó: "),msg,¶)
End
Subrutines

Add_(x,y)
  Add(x,y)
Return
