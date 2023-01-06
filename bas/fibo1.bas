
#include <hbasic.h>


#define TERM1    1.61803398874989
#define TERM2    -0.61803398874989

#context get Fibonacci number with analitic mode
  GetArgs(n) 
  get Inv of (M_SQRT5), Mul by( Pow (TERM 1, n), Minus( Pow(TERM 2, n) )  );
  then Return\\

#proto fibonacci_recursive(__X__)
#synon _fibonacci_recursive    getFibonaccinumberwithrecursivemodeof

#proto fibonacci_iterative(__X__)
#synon _fibonacci_iterative    getFibonaccinumberwithiterativemodeof

Begin
  Option Stack 1024

  get Arg Number(2, n), and Take( n );
  then, get Fibonacci number with analitic mode, and Print It with a Newl.
  secondly, get Fibonacci number with recursive mode of(n), and Print It with a Newl.
  finally, get Fibonacci number with iterative mode of (n), and Print It with a Newl.
End

Subrutines

fibonacci_recursive(n)
   Take If ( var(n) Is Le? (2), 1 , \
             get Fibonacci number with recursive mode of( var(n) Minus (1));\
             get Fibonacci number with recursive mode of( var(n) Minus (2)); and Add It )
Return

fibonacci_iterative(n)
  A=0
  B=1
  For Up( I:=2, n, 1 )
    C=B
   // Take(A),Plus(B),Move(B)
    Let ( B := var(A) Plus (B) )
    A=C
  Next
Return(B)
