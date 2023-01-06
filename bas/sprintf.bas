


#include <hbasic.h>


Begin

  Option Stack 20

  n=10
  s="Daniel!"
  v=0, i=0
  t1=0,t2=0
  t3=0,t4=0
  Tic(t1)
  For Up( i:=1, 900,1)
     sPrintF(v,"Hola $0, [$1], $2\n",s,var(n) Plus(i),cte(200)Mulby(i))
     Print(v)
  Next
  Toc(t1,t2)

  n=10
  Tic(t3)
  For Up( i:=1, 900,1)
     Print("Hola ",s,", [",var(n) Plus(i),"], ",cte(200)Mulby(i),"\n")
  Next
  Toc(t3,t4)
  
  //Let ( t2 := Cat$("\INV", Str$(t2)) + ("\OFF") )
  Let ( t4 := Cat$("\INV", Str$(t4)) + ("\OFF") )

  Print("Time 1 = ",Inversed(Str$(t2)),Newl)
  Print("Time 2 = ",t4,Newl)
  Print("Mensaje ",Inversed("inverso")," off\n")
  Print("Mensaje ",Underline("subrayado")," off\n")
  Print("Mensaje ",Italic("cursivo")," off\n")
  Print("Mensaje ",Bold("enfatizado")," off\n")
  
End
