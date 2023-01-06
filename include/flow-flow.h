

// TIPO FLOW: LOGICAS
#define  REL-LESS-EQUAL?         ;le?
#define  REL-LESS?               ;lt?
#define  REL-GREAT-EQUAL?        ;ge?
#define  REL-GREAT?              ;gt?
#define  REL-NOT-EQUAL?          ;neq?
#define  REL-EQUAL?              ;eq?
#define  REL-NOT-EQUAL-ARR?      ;neqarr?
#define  REL-EQUAL-ARR?          ;eqarr?

// saltos dependiendo de un valor en la memoria, obtenido por REL-XX?:
#define  THEN-JUMP(_X_)       jt(_X_)
#synon   THEN-JUMP            THEN-GOTO
#define  THEN-GOSUB(_X_)      gosub(_X_)

// otros tipo FLOW
#define  IS-INF?              ;inf?;
#define  IS-NAN?              ;nan?;
#define  IS-ODD?              ;odd?;
#define  IS-NOT-ZERO?         ;zero?;not;
#define  IS-ZERO?             ;zero?;
#define  IS-NOT-NULL?         ;void?;not;
#define  IS-NULL?             ;void?;
#define  IS-POS?              ;pos?;
#define  IS-NEG?              ;neg?;
#define  IS-ARRAY?            ;array?;
#define  IS-NUMERIC?          ;numeric?;
#define  IS-STRING?           ;string?;
#define  IS-ENV-VAR?          ;env?;

// tipo FLOW: ARITMETICAS
#define  ADD-IT                ;add;
#define  SUB-IT                ;sub;
#define  MUL-IT                ;mul;
#define  INT-DIV-IT            ;idiv;
#define  DIV-IT                ;div;
#define  APPLY-MOD             ;mod;
#define  APPLY-POW             ;pow;
#define  APPLY-ROUND           ;round;
#define  COMP-GCD              ;gcd;
#define  COMP-LCM              ;lcm;

// tipo FLOW: MATEMATICAS
#define  GET-SQR-DIFF          ;sqrdiff;
#define  GET-SQR-ADD           ;sqradd;
#define  GET-EUCL-DIST         ;hypot;
#define  MULTIPLY-ALL          ;mulall;
#define  ADD-ALL               ;sumall;
#define  PUT-SRAND             ;seed;
#define  GET-SQRT              ;sqrt;
#define  GET-CBRT              ;cbrt;
#define  GET-CEIL              ;ceil;
#define  GET-FLOOR             ;floor;
#define  GET-TRUNC             ;trunc;
#define  GET-LEN-INT           ;lennum;
#define  GET-INT               ;int;
#define  GET-SGN               ;sign;
#define  GET-SCI-FORMAT        ;sci;
#define  COMP-FACT             ;fact;
#define  GET-ABS               ;abs;
#define  GET-EXP2              ;exp2;
#define  GET-EXP10             ;exp10;
#define  GET-EXP               ;exp;
#define  GET-LOG2              ;log2;
#define  GET-LOG10             ;log10;
#define  GET-LOG               ;log;
#define  GET-RAND              ;rand;

#define  GET-INV-SQR           ;powby(2);powby(-1)
#define  GET-INV-CUB           ;powby(3);powby(-1)
#define  GET-INV-QUA           ;powby(4);powby(-1)
#define  GET-INV               ;powby(-1)
#define  GET-SQR               ;powby(2)
#define  GET-CUB               ;powby(3)
#define  GET-QUA               ;powby(4)
#define  GET-A-HALF            ;divby(2)
#define  GET-A-THIRD           ;divby(3)
#define  GET-A-QUARTER         ;divby(4)

#define  GET-RADIAN            ;d2r;
#define  GET-DEGREE            ;r2d;
#define  GET-ACOSH             ;arccosh;
#define  GET-ASINH             ;arcsinh;
#define  GET-ATANH             ;arctanh;
#define  GET-ACOS              ;arccos;
#define  GET-ASIN              ;arcsin;
#define  GET-ATAN              ;arctan;
#define  GET-COSH              ;cosh;
#define  GET-SINH              ;sinh;
#define  GET-TANH              ;tanh;
#define  GET-COS               ;cos;
#define  GET-SIN               ;sin;
#define  GET-TAN               ;tan;

// TIPO FLOW:  CADENAS
#define  GET-LEN             ;len;
#define  GET-CHR             ;chr;
#define  GET-ASCII           ;asc;
#define  CONV-TO-STR         ;xtostr;
#define  CONV-TO-NUM         ;xtonum;
#define  CONV-TO-BOOL        ;xtobool;
#define  APPLY-PAD-CENTER    ;padcenter;
#define  APPLY-PAD-LEFT      ;padleft;
#define  APPLY-PAD-RIGHT     ;padright;
#define  GET-TYPE            ;type;
#define  GET-UCAS            ;upper;
#define  GET-LCAS            ;lower;
#define  GET-HEX             ;hex;
#define  GET-BIN             ;bin;
#define  GET-OCT             ;oct;
#define  GET-STR             ;utf8tostr;
#define  GET-UTF8            ;strtoutf8;
#define  APPLY-TRM-RIGHT     ;trimright;
#define  APPLY-TRM-LEFT      ;trimleft;
#define  APPLY-TRM           ;trim;
#define  APPLY-CAT           ;cat;

// TIPO FLOW: ENVIRONMENT Y SISTEMA
#define  EXEC-IT            ;exec;
#define  CALL-SYS           ;execv;

// TIPO FLOW; LISTAS
#define  GET-LENGTH         ;length;
#define  GET-CARTESIAN      ;cartesian;

// TIPO FLOW: ARRAYS
#define  CONCAT-IT          ;array(6)
#define  SORT-IT            ;array(0)
#define  DISTR-IT           ;array(9)
#define  GET-MAX-VALUE      ;array(10)
#define  GET-MIN-VALUE      ;array(13)
#define  GET-MAX-POS        ;array(11)
#define  GET-MIN-POS        ;array(14)
#define  GET-MAX-ARR        ;array(12);  // devuelve valor,posicion
#define  GET-MIN-ARR        ;array(15);  // devuelve valor,posicion
#define  MIX-THIS-ARRS      ;array(16);
#define  ROT-LEFT           ;array(17); //left rotate
#define  ROT-RIGHT          ;array(18);
#define  SWAP-THIS-ELEMS    ;array(19);  // swap elementos



// TIPO FLOW: BITS
#define  APPLY-AND-BIT             ;bit(100)
#define  APPLY-XOR-BIT             ;bit(102)
#define  APPLY-OR-BIT              ;bit(101)
#define  APPLY-NOT-BIT             ;bit(103)
#define  CLR-BIT                   ;bit(104)
#define  SET-BIT                   ;bit(105)
#define  HEX-TO-DEC                ;bit(110)
#define  OCT-TO-DEC                ;bit(111)
#define  BIN-TO-DEC                ;bit(112)

// TIPO FLOW: CONJUNTOS
#define  GET-UNION                 ;sets(1)
#define  GET-INTERSECT             ;sets(2)
#define  GET-SIM-DIFF              ;sets(4)
#define  GET-DIFFERENCE            ;sets(3)
#define  DISJOINT?                 ;sets(5)
#define  SUBSET?                   ;sets(6)
#define  SUPERSET?                 ;sets(7)

// TIPO FLOW: ESTADISTICAS

#define  GET-SUMMATORY         ;stats(0)
#define  GET-MULTIPLICATORY    ;stats(8)
#define  GET-GEO-MEAN          ;stats(9)
#define  GET-HAR-MEAN          ;stats(10)
#define  GET-MEAN              ;stats(1)
#define  GET-STURG-CLASS       ;stats(3)
#define  GET-BIN-CLASS         ;stats(4)
#define  GET-CLASS             ;stats(5)
#define  GET-ADD-SUB-SUCC      ;stats(13)
#define  GET-SUB-ADD-SUCC      ;stats(14)
// estas macros actúan sobre matrices 2D:
#define  GET-SUM-COL           ;stats(6)
#define  GET-SUM-ROW           ;stats(7)
#define  GET-MUL-COL           ;stats(11)
#define  GET-MUL-ROW           ;stats(12)

// TIPO FLOW: IMPRESION
#define  PRNL-IT               {"\n"}print;
#define  PRN-IT                ;print;
#define  LOCATE                ;goxy;
#define  LOC-ROW               ;gox;
#define  LOC-COL               ;goy;

/* EOF */
