#!/usr/bin/hopper

// Archivo Hopper-Basic
#include <hbasic.h>

Begin
  Declare as Variant (archivos,redes afectadas,rango válido)
          as Variant (nuevo,sys,t,nt,ot)
          as Alpha   (ruta)
          
  Token Init
  ruta = "Redes/"
  Token Sep(",")
  For Each Tkn( t, "AB/,AM/,AA/,CB/,CM/,CA/", 6 )
     // ejecuto "ls", y el resultado lo dejo en un array con split:
     Split( Execute ( Cat$("ls ",ruta) + (t) + ("*_???_1.csv")), archivos, Newl)
     If ( Length(archivos) )
        Token Sep("_") , Token(3)
        Let( redes afectadas := Val(get Token$(archivos); Copy(ot)) )
        Let( rango válido    := Cartesian(Not(Zero?( Sub(redes afectadas,100); Copy(nt) ))) )
        If ( Is Array?(rango válido) )
           set Range(rango válido)  // se establece rango con qué trabajar
           Let ( nuevo := TranFirst$(Str$(Get(nt)), Get(ot),Get(archivos)))
           Let ( sys:=Cat$("mv ",Get(archivos)) + (" ") + (nuevo) )
           Clear All
           System( sys ) // solo en esta instrucción se acepta ejecutar un array de strings
        End If
     End If
     Token Sep(",")
     // limpio variables que contienen arrays:
     Clear(archivos),Clear(redes afectadas),Clear(nt)
     Clear(rango válido),Clear(nt),Clear(nuevo),Clear(sys)
  Next
End
