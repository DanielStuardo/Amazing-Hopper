
/* NATURAL */

#define  Get(_X_)       ;gosub(_X_)
#synon   Get            *Get  
#define  Do(_X_)        ;jsub(_X_)
#synon   Do             *Do 

#define Ceiling          ceil;
#define getFloor         floor;
#define TruncateIt       trunc;
#define getLenInt        lennum;
#define getInt           int;
#define getSign          sign;
#define getCubicRoot          cbrt;
#define getSquareRoot          sqrt;
#define getSci           sci;
#define getFactorial          fact;
#define getAbsoluteValue           abs;
#define getExp2          exp2;
#define getExp10         exp10;
#define getExp           exp;
#define getLog2          log2;
#define getLog10         log10;
#define getLog           log;

#define Ceil          ceil;
#define Floor         floor;
#define Trunc         trunc;
#define LenInt        lennum;
#define Int           int;
#define Sign          sign;
#define Cbrt          cbrt;
#define Sqrt          sqrt;
#define Sci           sci;
#define Fact          fact;
#define Abs           abs;
#define Exp2          exp2;
#define Exp10         exp10;
#define Exp           exp;
#define Log2          log2;
#define Log10         log10;
#define Log           log;


#define  InitTime(_X_)           ;timecpu(_X_)    
#define  EndTime(_X_,_Y_)        ;timecpu(_Y_),{_Y_}minus(_X_),clockpersec,div,mov(_Y_),clear(_X_)
