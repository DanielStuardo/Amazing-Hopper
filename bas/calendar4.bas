#include <hbasic.h>

#proto SelectDate(__F__)
#proto SelectItem(__X__,__R__,__C__,__I__,__M__)

Begin
   Option Ctrl+C
   
   Declare as Alpha (fecha)
   Cls
   Locate (5,5)
   Let( fecha:= _SelectDate(DateNow$) )
   Print ("Fecha seleccionada: ",fecha,Newl)
   If ( Is Date Valid?(fecha) )
      Print("Es una fecha valida",Newl)
   Else
      Print("No es una fecha valida",Newl)
   End If
   Put a Newl

End

Subrutines
SelectDate(fecha)
   Declare as Numeric(X,XT,c,Mes,Ano,x,y), as Alpha (Item)
   Let (X:=Calendar(Month(fecha),Year(fecha),1))
   Let( Mes := Month(fecha) )
   Let( Ano := Year(fecha) )
   XT = X
   // TODO: buscar el día, y marcarlo.
   x=1, y=1
   Token Sep(" ")
   Let (Item := _Select Item(X,x,y,Item,"") )
   
   While( 1 )

         Let( c := GetCh )
      Salto:
         If Key(c, K_TAB)
        // If Key Tab(c)
            X = XT
            If ( Eq(x,1) )
               x = 3,y = 1
               Let (Item := _Select Item(X,x,y,Item,"C+") )
               If ( Eq(Item,"   ") )
                  c = K_RIGHT
                  Goto(Salto)
               End If
            Else
               x = 1, y = 1
               Let (Item := _Select Item(X,x,y,Item,"") )
            End If
            Continue
         Else If Key Enter(c)
            If ( Eq(x,1) )
               If ( are Eq(y,1) )
                  d=0
                  While( 1 )
                     Let ( d := GetCh )
                     Exit If (d) Is Escape
                     Exit If (d) Is Enter
                     If ( Eq(d,43) )
                        ++Mes
                        If ( Eq( Mes,13) )
                           Mes = 1, ++Ano
                        End If
                     Else If ( Eq(d,45))
                        --Mes
                        If ( Eq( Mes,0) )
                           Mes = 12, --Ano
                        End If
                     End If
                     Clear(X), Clear(XT)
                     Let (X:=Calendar(Mes,Ano,1))
                     XT = X
                     x=1, y=1
                     Let (Item := _Select Item(X,x,y,Item,"") )
                  Wend
               Else If ( Eq(y,7) )
                  d=0
                  While( 1 )
                     Let ( d := GetCh )
                     Exit If (d) Is Escape
                     Exit If (d) Is Enter
                     If ( Eq(d,43) )
                        ++Ano
                     Else If ( Eq(d,45))
                        --Ano
                     End If
                     Clear(X), Clear(XT)
                     Let (X:=Calendar(Mes,Ano,1))
                     XT = X
                     x=1, y=7
                     Let (Item := _Select Item(X,x,y,Item,"") )
                  Wend                  
               End If
               Continue
            Else
               Break
            End If
         Else If Key Forward(c)
            X = XT
            If ( Eq(y,1) )
               If ( Eq(x,1) )
                  y = 6
               End If
            Else If ( Eq(y,7) )
               If ( Eq(x,1) )
                  y = 0
               Else
                  If ( Eq(x,8) )
                     x = 3,y = 0
                  Else
                     ++x, y = 0
                  End If
               End If
            End If
            ++y, Let (Item := _Select Item(X,x,y,Item,"C+") )
            If ( Eq(Item,"   ") )
               Goto(Salto)
            End If
         Else If Key Back(c)
            X = XT
            If ( Eq(y,1))
               If ( Eq(x,1) )
                  y = 8
               Else 
                  If ( Eq(x,3) )
                     x = 8,y = 8
                  Else
                     --x, y = 8
                  End If
               End If
            Else If ( Eq(y,7) )
               If ( Eq(x,1) )
                  y = 2
               End If
            End If
            --y, Let (Item := _Select Item(X,x,y,Item,"C-") )
            If ( Eq(Item,"   ") )
               Goto(Salto)
            End If
         Else If Key Down(c)
            X = XT
            If ( Eq(x,8) )
               x = 0
            Else If( Eq(x,1) )
               x = 2
            End If
            ++x, Let (Item := _Select Item(X,x,y,Item,"R+") )
            If ( Eq(Item,"   ") )
               Goto(Salto)
            End If
         Else If Key Up(c)
            X = XT
            If ( Eq(x,1) )
               x = 9
            Else If ( Eq(x,3) )
               x = 2
            End If
            --x, Let (Item := _Select Item(X,x,y,Item,"R-") )
            If ( Eq(Item,"   ") )
               Goto(Salto)
            End If
         End If
   Wend
   Take(Trim$(Item),"/",Mes,"/",Ano)
   Let( fecha := Token Sep(""),SJoin$ )
   Token Sep(",")
Return(fecha)

SelectItem(X,x,y,Item,Modo)
   //Print("**** [",Modo,"] **** x=",x,", y=",y,", Item=[",Item,"]",Newl)
   Let (Item:=[x,y]Get(X))
   If ( are Eq(Item,"   ") )
      /*Switch(Modo)
         Case("R+"){ PutKey(K_DOWN),Exit }
         Case("R-"){ PutKey(K_UP),Exit }
         Case("C+"){ PutKey(K_RIGHT),Exit }
         Case("C-"){ PutKey(K_LEFT),Exit }
      End Switch*/
      Clear All
   Else
      Token Sep(""),Take("\BGW\BK",Item,"\OFF"),SJoin$, SPut(X),Token Sep(" ")
      Print Table( X )
      
   End If
   Clear(X)
Return(Item)
