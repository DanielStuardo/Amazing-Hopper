
#include <hbasic.h>

Begin

Cls
form="", subform="", reg=""
Pivot (form)
   Pivot (subform)
      Pivot (reg)
         ParsNormal$("nombre-empleado","sueldo=100 code='101-B'","Juanito Perez")
         ParsNormal$("nombre-empleado","sueldo=140 code='101-A'","Augusto Lorca")
         ParsOnly$("seguro","code=01")
      Flush(reg)
      ParsNormal$("employes","agencia=01",reg)
   Flush(subform)
   ParsNormal$("formulario","CODE='100H'", subform)
Flush(form)

Let ( form := Tran$(">\n<","><", form) )
Print( form, Newl )
Pause

Pivot(form)
  //UnPars$("employes"), atr=0,msg="",mov(atr),mov(msg)
  atr=0,msg=""
  Store ( UnPars$("employes"), msg, atr )
  Pivot(msg)
     contenido="",atrib=0,siga=1
     While ( siga )  
        Try
            Store ( UnPars$ ("nombre-empleado"), contenido, atrib)
            Print("Nombre de empleado:",contenido, Newl)
            Print("Sueldo: ",[1]Get(atrib), Newl)
            Print("Codigo: ",[2]Get(atrib), Newl)
         Catch(e)
            siga=0   
            ///popcatch,break  // ...use: popcatch, break; si no usa popcatch, el programa no terminará
         Finish
      Wend
      Let ( atrib := UnPars$ ("seguro") )
      Print("Codigo seguro: ", [1]get(atrib), Newl)
  Flush(msg)
Flush(form)

End
