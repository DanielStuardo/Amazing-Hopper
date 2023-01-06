
#include <hbasic.h>

Begin
  Option Ctrl+C
  
  Dec as Numeric (i,j,k,col,columnas,filas)
      as Alpha(c)

  Back Terminal, Ambar Pencil
  Bold,Cls
  Italic,Print("Colores RGB:",¶),Italic Off
  Let (c:=Str2Utf8$(Chr$(219)))
  GetSizeTerm(columnas,filas)

  For (i=0, Le(i,255), ++i)
     For(j=0, Le(j,255), ++j)
        col=1 
        For(k=0, Le(k,255), ++k)
           RGBF(i,j,k)
           Puts(c)
           ++col, 
           When( Gt(col, columnas) ){ col=1, PutNewl }
        Next
     Next
  Next
  Pause
  Bold Off

End
