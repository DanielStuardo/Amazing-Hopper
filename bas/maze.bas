
#include <hbasic.h>

Begin
 Option Ctrl+C
     Cls, Locate(1,1)
     fd=0
     Create(CREATE_NORMAL,"lab01.txt")(fd)
     
     Brick="219," //0, Let( Brick := Chr$(219) + (",") )
     Space=" "  //0, Let( Space := Chr$(32) )
     SpcNl="32\n"  //0, Let( SpcNl := var(Space) + (Newl) )
     ss=0, t=0, c=0, tope=0, l=0

     Let( ss := var(Brick) Reply by (125), + (SpcNl) )

     WriteLine$( ss )(fd)
     
     For Up( i := 1, 80, 1 )
        sw=1
        ss=Brick
        t=ss
        For Up( j := 1, 40, 1 )
           If ( sw )
              If ( Rand(1), Is Gt? (0.5) )
                 Let( ss := Cat$( ss, "32,32,32," ) )
                 Let( t := Cat$( t, "32,32,32," ) )
              Else
                 Let( ss := Cat$( ss, "219,219,219," ) )
                 Let( t := Cat$( t, "219,219,219," ) )
              End If
              Let( sw := Not(sw) )

           Else
              Let( ss := Cat$( ss, "219,219,219," ) )
              Let( t := Cat$( t, "219,219,219," ) )
              Let( sw := Not(sw) )
           End If
        Next
        Let( ss := Cat$( ss, "32,32,32,219,32\n" ) )
        Let( t := Cat$( t, "32,32,32,219,32\n" ) )
        
        WriteLine$( ss )(fd)

        Let( c := Ceil(Rand(5)) )
        Let( tope := Sub(80,c) )
        ++i
        While( var(i) Is Lt? ( Sub(tope,1) ) ) // (++i)<(tope-1)
            WriteStr$( t )(fd)
            --c
            Exit If (c) Is Zero  //brkz (--c)
            ++i
        Wend

        WriteLine$( ss )(fd)

        Let( l := Cat$("219,", cte("32,") Reply by(123)) + ("219,32\n") )
        WriteLine$( l )(fd)
        
     Next
     
     Let( ss := Cat$( var( Brick ) Reply by(125), SpcNl ) )
     
     WriteLine$( ss )(fd)
     
     Let( l := Cat$( cte("32,") Reply by(125), SpcNl ) )
     WriteLine$( l )(fd)
     
     Close(fd)
//     mat.load((flag ",") lab (PATH+"lab.txt")  )//"/home/xu/Proyectos/xuesp/LINUX-64bits/output/lab.txt")
//     .busca_intersecciones()
//     screen(1)
     m=0
     Let( m := Load Matrix("lab01.txt") )
     Token Sep("")
     Print( Chr$(m) )
End
