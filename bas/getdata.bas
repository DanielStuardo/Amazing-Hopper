#!/usr/bin/hopper

// Archivo Hopper-Basic
#include <hbasic.h>

Begin

  Dec as Alpha (dir,ot,datos,nuevo archivo)
      as Numeric(total archivos,cnt,lsufijo,ltipo)
      as Alpha(sufijos,tipo de simulación)
      as Alpha(s,t,v)

  sufijo = "SAG,SASC,SC,SCO,ST"
  tipo de simulación = "ab,am,aa,cb,cm,ca"
  lsufijo=5 // 5 tokens
  ltipo=6  // 6 tokens
  Token Sep(",")
  For Each Tkn(s,sufijo,lsufijo)
     For Each Tkn(t,tipo de simulación,ltipo)
        Let( dir := Execute ( Cat$("ls ",Upper$(t) + ("/")+(s)+("_")+(t)+("*"))) )
        Token Sep(Newl)
        Let ( total archivos := TotalTokens(dir))
        cnt=0, datos=""
        For Each Tkn(v := dir,total archivos)
           Let( ot := Execute( Cat$("tail -n 1 ",v)) )
           Let ( datos := Cat$(datos, ot) )
           ++cnt
        Next
        Let ( nuevo archivo := Cat$( Cat$( Cat$(s,"_"),t),".csv"))
        Print(datos,Newl,"Total: ",cnt,Newl)
        Print(nuevo archivo,Newl)
        SaveStr$(nuevo archivo,datos)
        Token Sep(",")
     Next
  Next
End
