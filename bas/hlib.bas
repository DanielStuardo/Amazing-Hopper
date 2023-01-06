#include <hbasic.h>

/*#proto ___Select___Date___(__F__)
#proto ___Select___Item___(__X__,__R__,__C__,__I__)
#proto ___Select___Day___(__X__,__D__)
#proto ___Select___Red___Item___(__X__,__F__,__C__,__F1__,__C1__)
#synon ____Select___Date___     SelectDate*/

#import lib/sldate.bas.lib
#include include/sldate.h

Begin
   Option Ctrl+C
   Option Stack 15
   
   Declare as Alpha (fecha)
   Cls
   Locate (5,5)
   Let( fecha := SelectDate(DateNow$) )
   Print ("Fecha seleccionada: ",fecha,Newl)
   If ( IsDateValid?(fecha) )
      Print("Es una fecha valida",Newl)
   Else
      Print("No es una fecha valida",Newl)
   End If
   PutNewl
End

Subrutines
/*___Select___Date___(fecha)
   Number as(X,XT,c,i,Dia,Mes,Ano,x,y), String as (Item)
   Let (X:=Calendar(Month(fecha),Year(fecha),1))
   Let( Mes := Month(fecha) )
   Let( Ano := Year(fecha) )
   XT = X
   Let ( Dia := Day(fecha) )
   Sto ( ____Select___Day___(X,Dia), x, y)
   Token Sep(" ")
   Let (Item := ____Select___Item___(X,x,y,Item,"") )
   
   While( 1 )

         Let( c := GetCh )
      Salto:
         If Key(c, K_TAB)
        // If Key Tab(c)
            X = XT
            If ( Eq(x,1) )
               x = 3,y = 1
               Let (Item := ____Select___Item___(X,x,y,Item) )
               If ( Eq(Item,"   ") )
                  c = K_RIGHT
                  Goto(Salto)
               End If
            Else
               x = 1, y = 1
               Let (Item := ____Select___Item___(X,x,y,Item) )
            End If
            Continue
         Else If Key Enter(c)
            If ( Eq(x,1) )
               If ( Eq(y,1) )
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
                     x=1, y=1, x1=0, y1=0
                     Sto ( ____Select___Day___(X,Dia), x1, y1)
                     ____Select___Red___Item___(X,x,y,x1,y1)
                  Wend
                  x=x1, y=y1
                  Let (Item := ____Select___Item___(X,x,y,Item) )
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
                     x=1, y=7, x1=0, y1=0
                     Sto ( ____Select___Day___(X,Dia), x1, y1)
                     ____Select___Red___Item___(X,x,y,x1,y1)
                     //Let (Item := _Select Item(X,x,y,Item) )
                  Wend
                  //Store ( _SelectDay(X,Dia), x, y)
                  x=x1, y=y1
                  Let (Item := ____Select___Item___(X,x,y,Item) )
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
            ++y, Let (Item := ____Select___Item___(X,x,y,Item) )
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
            --y, Let (Item := ____Select___Item___(X,x,y,Item) )
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
            ++x, Let (Item := ____Select___Item___(X,x,y,Item) )
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
            --x, Let (Item := ____Select___Item___(X,x,y,Item) )
            If ( Eq(Item,"   ") )
               Goto(Salto)
            End If
         End If
   Wend
   Take(Trim$(Item),"/",Mes,"/",Ano)
   Let( fecha := Token Sep(""),SJoin$ )
   Token Sep(",")
Return(fecha)

___Select___Item___(X,x,y,Item)
   Let (Item:=[x,y]Get(X))
   If ( Eq(Item,"   ") )
      Clear All
   Else
      Token Sep(""),Take("\BGW\BK",Item,"\OFF"),SJoin$, SPut(X),Token Sep(" ")
      Print Table( X )
   End If
   Clear(X)
Return(Item)

___Select___Red___Item___(X,x,y,x1,y1)
   Item=0
   Let (Item:=[x,y]Get(X))
   Token Sep(""),Take("\BGW\BK",Item,"\OFF"),SJoin$, SPut(X),Token Sep(" ")
   Let (Item:=[x1,y1]Get(X))
   Token Sep(""),Take("\LR",Item,"\OFF"),SJoin$, SPut(X),Token Sep(" ")
   Print Table( X )
   Clear(X)
Return

___Select___Day___(X,Dia)
   nPos=0,i=0
   For Up( i:= 1, 8,1 )
      Let ( nPos:=Scan(1, Dia, Val([i,1:end]SGet(X)) ) )
      If ( Neq(nPos,0) )
         Break
      End If
   Next
   clear(X)
   Take (i,nPos)
Return*/
