
#context-free  Set Color Fondo
                  Color(0,252)
                  Back\\
#synon SetColorFondo   ColorFondo

#proto printinversed(_X_)
#synon _printinversed   *PrintInversed
#proto printbold(_X_)
#synon _printbold       *PrintBold

#include <hbasic.h>

Begin
  s="home/src/man/archivo.txt"
  /*Background(21),Foreground(15),*/
  Color Fondo
  //set Canvas Paper, set Black Pencil
  Cls
  
  Print("Archivo: \BGR\W\ENF", Mid$( Len(s),FindLast("/",s) Plus(1),s), Newl)
  then Print("\OFF\CB21m\CF15m","\n\n\nHecho!\n",Newl)

  now Print Inversed ( Cat$ ("Signal: ",Str$(100)) + ("\n") ), and Set Color Fondo;
  then Print Bold ("Nothing\n")
End
Subrutines

printinversed(S)
  Inversed,Print(S),Inversed Off
Return
printbold(S)
  Bold,Print(S),Bold Off
Return
