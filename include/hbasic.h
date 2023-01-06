/* Hopper-BASIC */

/* Importante!

   NO CAMBIE DE POSICION LAS DEFINICIONES
*/

/* Saltos */
#defn   OnGoto(*)            #GENCODE $$$*$$$ {#ITV}keep,eq? do{kill,jmp(#LIST)},#ENDGEN
#defn   OnGosub(*)           #GENCODE $$$*$$$ {#ITV}keep,eq? do{kill,jsub(#LIST),jmp(#HERE)},#ENDGEN
#defn   OnOption(*)          #GENCODE $$$*$$$ {#ITV}keep,eq? do{kill,#LIST,jmp(#HERE)},#ENDGEN

#define GotoIfNotZero(__X__)       jnz(__X__)
#synon  GotoIfNotZero              GotoIfNZ 
#define GotoIfZero(__X__)          jz(__X__)
#synon  GotoIfZero                 GotoIfZ 
#define GotoIfareNotEquals(__X__)  jneq(__X__)
#synon  GotoIfareNotEquals         GotoIfNEQ
#define GotoIfareEquals(__X__)     jeq(__X__)
#synon  GotoIfareEquals            GotoIfEQ
#define GotoIfNotTrue(__X__)       jnt(__X__)
#synon  GotoIfNotTrue              GotoIfNT
#define GotoIfTrue(__X__)          jt(__X__)
#synon  GotoIfTrue                 GotoIfT
#define GotoIfNotVoid(__X__)       jnv(__X__)
#synon  GotoIfNotVoid              GotoIfNV
#define GotoIfVoid(__X__)          jv(__X__)
#synon  GotoIfVoid                 GotoIfV
#define GotoIfPositive(__X__)      jpos(__X__)
#synon  GotoIfPositive             GotoIfPOS
#define GotoIfNegative(__X__)      jneg(__X__)
#synon  GotoIfNegative             GotoIfNEG

// take(A, B), Goto If LE(LABEL)  salta si B <= A, y así lo que sigue
#define GotoIfLessEqual(__X__)     jle(__X__)
#synon  GotoIfLessEqual            GotoIfLE
#define GotoIfLess(__X__)          jlt(__X__)
#synon  GotoIfLess                 GotoIfLT
#define GotoIfGreaterEqual(__X__)  jge(__X__)
#synon  GotoIfGreaterEqual         GotoIfGE
#define GotoIfGreater(__X__)       jgt(__X__)
#synon  GotoIfGreater              GotoIfGT
             
#define Gosub(__X__)         jsub(__X__)
#define Goto(__X__)          jmp(__X__)               
#define Subrutines           .locals

// #define-a cambia el símbolo donde lo encuentre.
//#define-a  :=(__X__)    ;cpy(__X__)
#define-a  :=           ,
#define-a  ::           ,
#define-a  ~=           ,
//#define-a  =(__X__)     ;mov(__X__)

// Las siguientes macros no deben usarse cuando se quiere editar con Laica, porque no los reconoce:
//#define-a  →                   ,  // altGr + i
//#define-a  ←                   =  // altGr + y
//#define-a  ½                   0.5 // altgr + 5
//#define-a  ¶                   "\n"  // altgr + r  termina un párrafo.
// --------
#define-a  AtInterval          ;
#synon     AtInterval          DefineInterval,DefInterval,SetInterval

/*#define  ↓  // altgr + u
#define  « ,   // altgr + z
#define  » ,   // altgr + x*/

#define  »»(__X__)     ;mov(__X__)
#define  »(__X__)      ;cpy(__X__)

/* BUCLES y estructuras */
#defn   Iterator(_V_,_I_,_INC_,_REL_,*)          #RAND, _V_=_I_,_LOOP_#RNDV:,*,kbesc?do{{"infinity loop breaked"},throw(1010)},\
                                                 _INC_,_REL_,jt(_LOOP_#RNDV),%RAND
#defn   ForUp(__V__,__FROM__,__TO__,__STEP__)    &(__V__+=__STEP__) __V__=__FROM__,#LOOP:,\
                                                 {__V__}lethan(__TO__), jnt(#ENDLOOP),
#defn   ForDown(__V__,__FROM__,__TO__,__STEP__)  &(__V__-=__STEP__) __V__=__FROM__,#LOOP:,\
                                                 {__V__}gethan(__TO__), jnt(#ENDLOOP),
// para cada token dentro del string. Debe definirse antes TOKSEP para indicar separador de token.
#defn   ForEachTkn(_Y_,_X_,_TT_)                 #RAND, ##ENDLOOP &(++_EXPR2_#RNDV;--_EXPR_#RNDV;{_EXPR_#RNDV};jz(%%ENDLOOP)) , \
                                                 _Y_="", _EXPR2_#RNDV=1, _EXPR_#RNDV=_TT_,{_TT_},jz(%%ENDLOOP),#LOOP: ,\
                                                 {_EXPR2_#RNDV},$(_X_),mov(_Y_),%RAND
#synon  ForEachTkn                               ForEachLine
// itera para cada caracter
#defn   ForEachChr(_Y_,_X_,_LEN_)                #RAND, ##ENDLOOP &(++_EXPRI_#RNDV;--_EXPRL_#RNDV;{_EXPRL_#RNDV};jz(%%ENDLOOP)),\
                                                 {_LEN_},jz(%%ENDLOOP),_Y_="", _EXPRI_#RNDV=1, _EXPRL_#RNDV=_LEN_,\
                                                 #LOOP:,[_EXPRI_#RNDV]get(_X_),mov(_Y_),%RAND
// para cada elemento del array. se debe hacer reshape antes de este FOR
#defn   ForEach(_V_,_ARR_,_LEN_)                 #RAND,##ENDLOOP &(--_IND_#RNDV, {_IND_#RNDV}jz(%%ENDLOOP)),\
                                                 _IND_#RNDV=_LEN_,_V_=0,#LOOP:,[_IND_#RNDV]ewget(_ARR_),mov(_V_),%RAND
#defn   For(_X_,_Y_,_Z_)                         &(_Z_) _X_,#LOOP:,_Y_,jnt(#ENDLOOP),
// ciclo while clásico
#defn   WhileFalse(_X_)           &( ) #LOOP:, #ATOM #CMPLX ,not,jnt(#ENDLOOP),
#defn   WhileNotZero(_X_)         &( ) #LOOP:, #ATOM #CMPLX ,jz(#ENDLOOP),
#defn   WhileZero(_X_)            &( ) #LOOP:, #ATOM #CMPLX ,jnz(#ENDLOOP),
#defn   WhilePositive(_X_)        &( ) #LOOP:, #ATOM #CMPLX ,jneg(#ENDLOOP),
#defn   WhileNegative(_X_)        &( ) #LOOP:, #ATOM #CMPLX ,jpos(#ENDLOOP),
#defn   WhileStringVoid(_X_)      &( ) #LOOP:, #ATOM #CMPLX ,jnv(#ENDLOOP),
#defn   WhileStringNotVoid(_X_)   &( ) #LOOP:, #ATOM #CMPLX ,jv(#ENDLOOP),
#defn   WhileInf(_X_)             &( ) #LOOP:, #ATOM #CMPLX ,inf?,jnt(#ENDLOOP),
#defn   WhileNotInf(_X_)          &( ) #LOOP:, #ATOM #CMPLX ,inf?,jt(#ENDLOOP),
#defn   WhileNaN(_X_)             &( ) #LOOP:, #ATOM #CMPLX ,nan?,jnt(#ENDLOOP),
#defn   WhileNotNaN(_X_)          &( ) #LOOP:, #ATOM #CMPLX ,nan?,not,jnt(#ENDLOOP),
#defn   WhileNotEscape            &( ) #LOOP:,kbesc?,not,jnt(#ENDLOOP),
#defn   WhileNotBreak             &( ) #LOOP:,kbctrlc?,not,jnt(#ENDLOOP),
#defn   WhileNotKeyPressed        &( ) #LOOP:,kbhit?,not,jnt(#ENDLOOP),
#defn   WhileNotEof(_X_)          &( ) #LOOP:,eof(_X_),jt(#ENDLOOP),
#defn   While(__X__)              &( ) #LOOP:,#ATOM#CMPLX,jnt(#ENDLOOP)

/* Booleanas especiales para usar en estructuras de control */
/* caso NOT ...*/
#defn   IsNotInf?(__X__)              #ATOM#CMPLX;inf?;not;
#synon  IsNotInf?                     NotInf?
#define IsNotInf?                     inf?;not;
#defn   IsNotNaN?(__X__)              #ATOM#CMPLX;nan?;not;
#synon  IsNotNaN?                     NotNaN?
#define IsNotNaN?                     nan?;not;
#defn   IsNotOdd?(__X__)              #ATOM#CMPLX;odd?;not;
#synon  IsNotOdd?                     NotOdd?
#define IsNotOdd?                     odd?;not;
#defn   IsNotZero?(__X__)             #ATOM#CMPLX;zero?;not;
#synon  IsNotZero?                    NotZero?
#define IsNotZero?                    zero?;not;
#defn   IsStringNotVoid?(__X__)       #ATOM#CMPLX;void?;not;
#synon  IsStringNotVoid?              StringNotVoid?
#define IsStringNotVoid?              void?;not;
#defn   IsNotPositive?(__X__)         #ATOM#CMPLX;pos?;not;
#synon  IsNotPositive?                NotPositive?
#define IsNotPositive?                pos?;not;
#defn   IsNotNegative?(__X__)         #ATOM#CMPLX;neg?;not;
#synon  IsNotNegative?                NotNegative?
#define IsNotNegative?                neg?;not;
#defn   IsNotArray?(__X__)            #ATOM#CMPLX;array?;not;
#synon  IsNotArray?                   NotArray?
#define IsNotArray?                   array?;not;
#defn   IsNotNumeric?(__X__)          #ATOM#CMPLX;numeric?;not;
#synon  IsNotNumeric?                 NotNumeric?
#define IsNotNumeric?                 numeric?;not; 
#defn   IsNotString?(__X__)           #ATOM#CMPLX;string?;not;
#synon  IsNotString?                  NotString?
#define IsNotString?                  string?;not;
#defn   IsNotEnvVar?(__X__)           #ATOM#CMPLX;env?;not;
#synon  IsNotEnvVar?                  NotEnvVar?
#define IsNotEnvVar?                  env?;not;
#defn   IsNotAny?(__X__,__Y__)        #ATOM#CMPLX;#ATOM#CMPLX;any?;not;
#synon  IsNotAny?                     NotAny?
#define IsNotAny?                     any?;not;
//   Take(num), Between?( 10::including, 100::excluding)
#define includ     1
#define exclud     0
#defn   IsNotBetween?(__I__,_X_,__F__,_Y_)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;between?;not;
#synon  IsNotBetween?                           NotBetween?
#defn   IsNotAll?(__X__,__Y__)       #ATOM#CMPLX;#ATOM#CMPLX;all?;not;
#synon  IsNotAll?                    NotAll?
#define IsNotAll?                    all?not;
#defn   IsNotEmpty?(__X__)           #ATOM#CMPLX;isempty;not;
#synon  IsNotEmpty?                  NotEmpty?
#define IsNotEmpty?                  isempty?;not;

/* caso POSITIVO */
#defn   IsInf?(__X__)              #ATOM#CMPLX;inf?;
#synon  IsInf?                     Inf?
#define IsInf?                     inf?
#defn   IsNaN?(__X__)              #ATOM#CMPLX;nan?;
#synon  IsNaN?                     NaN?
#define IsNaN?                     nan?
#defn   IsOdd?(__X__)              #ATOM#CMPLX;odd?;
#synon  IsOdd?                     Odd?
#define IsOdd?                     odd?
#defn   IsZero?(__X__)             #ATOM#CMPLX;zero?;
#synon  IsZero?                    Zero?
#define IsZero?                    zero?
#defn   IsStringVoid?(__X__)       #ATOM#CMPLX;void?;
#synon  IsStringVoid?              StringVoid?
#define IsStringVoid?              void?
#defn   IsPositive?(__X__)         #ATOM#CMPLX;pos?;
#synon  IsPositive?                Positive?
#define IsPositive?                pos?
#defn   IsNegative?(__X__)         #ATOM#CMPLX;neg?;
#synon  IsNegative?                Negative?
#define IsNegative?                neg?
#defn   IsArray?(__X__)            #ATOM#CMPLX;array?;
#synon  IsArray?                   Array?
#define IsArray?                   array?  // sirve para "var(X) Is Array?
#defn   IsNumeric?(__X__)          #ATOM#CMPLX;numeric?;
#synon  IsNumeric?                 Numeric?
#define IsNumeric?                 numeric?
#defn   IsString?(__X__)           #ATOM#CMPLX;string?;
#synon  IsString?                  String?
#define IsString?                  string?
#defn   IsEnvVar?(__X__)           #ATOM#CMPLX;env?;
#synon  IsEnvVar?                  EnvVar?
#define IsEnvVar?                  env?
#defn   IsAny?(__X__,__Y__)        #ATOM#CMPLX;#ATOM#CMPLX;any?;
#synon  IsAny?                     Any?
#define IsAny?                     any?
//   Take(num), Between?( 10::including, 100::excluding)
//  define includ, exclud ya está listo
#defn   IsBetween?(__I__,_X_,__F__,_Y_)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;between?;
#synon  IsBetween?                           Between?
#defn   IsAll?(__X__,__Y__)       #ATOM#CMPLX;#ATOM#CMPLX;all?;
#synon  IsAll?                    All?
#define IsAll?                    all?
#defn   IsEmpty?(__X__)           #ATOM#CMPLX;isempty;
#synon  IsEmpty?                  Empty?
#define IsEmpty?                  isempty;
#define FileError?                error?
#define FileError                 error?

/* Quiebre condicionado de bucles FOR, WHILE y REPEAT*/
#defn   ExitIf(__X__)        #ATOM#CMPLX,
// subgrupo instrucciones lógicas para "exit if...": exit if 'v' is zero
#defn   IsNotZero            jnz(%%ENDLOOP)
#defn   IsZero               jz(%%ENDLOOP)
#defn   IsFalse              jnt(%%ENDLOOP)
#synon  IsFalse              IsNotTrue
#defn   IsTrue               jt(%%ENDLOOP)
#synon  IsTrue               IsNotFalse
#defn   IsNotVoid            jnv(%%ENDLOOP)
#defn   IsVoid               jv(%%ENDLOOP)
#defn   IsNegative           jneg(%%ENDLOOP)
#defn   IsPositive           jpos(%%ENDLOOP)
#defn   IsInf                inf?,jt(%%ENDLOOP)
#defn   IsNaN                nan?,jt(%%ENDLOOP)
#defn   HaveNaN              stats(0),nan?,jt(%%ENDLOOP)
#defn   IsEnter              eqto(13),jt(%%ENDLOOP)
#defn   IsEscape             eqto(27),jt(%%ENDLOOP)
#defn   IsEmpty              isempty,jt(%%ENDLOOP)

/******* NO DOCUMENTADOS *******/

///#defn   DeviateIf(_X_,_LIMIT_)  #ATOM#CMPLX;timer(_LIMIT_);do
#defn   InTime(_X_,_LIMIT_,*)   #ATOM#CMPLX;timer(_LIMIT_);do{ * }
// hace algo si es el tiempo:
#defn    OnTime(_X_,_LIMIT_)          #ATOM#CMPLX;timer(_LIMIT_);do
// salta a un sub si es el tiempo:
#defn    JitGosub(_X_,_L_,_LBL_)       #ATOM#CMPLX;timer(_L_);gsub(_LBL_)
// 
#defn    IsTime(_X_,_L_)            ;#ATOM#CMPLX;timer(_LIMIT_); // devuelve TRUE o FALSE
/** hasta aqui **/

/* IF especiales */
// ESTOS NO PUEDEN IR sin que se les añada la variable, PORQUE NO PUEDEN RESCATAR UN DATO YA CONSUMIDO.
#defn   ElseIfNegative?(_X_)     jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, neg?, jnt(#ENDIF),
#defn   ElseIfPositive?(_X_)     jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, pos?, jnt(#ENDIF),
#defn   ElseIfFalse?(_X_)        jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, jt(#ENDIF),
#defn   ElseIfTrue?(_X_)         jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, jnt(#ENDIF),
#defn   ElseIfStringNotVoid?(_X_)  jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, void?,jt(#ENDIF),
#defn   ElseIfStringVoid?(_X_)   jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, void?,jnt(#ENDIF),

#defn   ElseIfNotFileError?      jmp(%%CODEIF), %ENDIF:, error?,jt(#ENDIF),
#defn   ElseIfFileError?         jmp(%%CODEIF), %ENDIF:, error?,jnt(#ENDIF),

#defn   ElseIfInf?(_X_)          jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, inf?,jnt(#ENDIF),
#defn   ElseIfNaN?(_X_)          jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, nan?,jnt(#ENDIF),
#defn   ElseIfNotInf?(_X_)       jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, inf?,jt(#ENDIF),
#defn   ElseIfNotNaN?(_X_)       jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, nan?,jt(#ENDIF),

#defn   ElseIfZero?(_X_)         jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, zero?,jnt(#ENDIF),
#defn   ElseIfNotZero?(_X_)      jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, zero?,jt(#ENDIF),
#defn   ElseIfArray?(_X_)        jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, array?,jnt(#ENDIF),
#defn   ElseIfNotArray?(_X_)     jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, array?,jt(#ENDIF),
#defn   ElseIfAnyNan?(_X_)       jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX, stats(0),nan?,jnt(#ENDIF)

#defn   ElseIfNotAnyNaN(_X_)     jmp(%%CODEIF), %ENDIF:, #ATOM #CMPLX,stats(0),nan?,jnt(#ENDIF)
#defn   ElseIfKeyPressed?        jmp(%%CODEIF), %ENDIF:, kbhit?,jnt(#ENDIF),
#defn   ElseIfKeyDown(_X_)       jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX,eqto(24),jnt(#ENDIF) 
#defn   ElseIfKeyUp(_X_)         jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX,eqto(5),jnt(#ENDIF)
#defn   ElseIfKeyBack(_X_)       jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX,eqto(19),jnt(#ENDIF)
#defn   ElseIfKeyForward(_X_)    jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX,eqto(4),jnt(#ENDIF)
#defn   ElseIfKeySupr(_X_)       jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX,eqto(7),jnt(#ENDIF)
#defn   ElseIfKeyBksp(_X_)       jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX,eqto(8),jnt(#ENDIF)
#defn   ElseIfKeyEscape(_X_)     jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX,eqto(27),jnt(#ENDIF)
#defn   ElseIfKeyEnter(_X_)      jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX,eqto(13),jnt(#ENDIF)
#defn   ElseIfKeyTab(_X_)        jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX,eqto(9),jnt(#ENDIF)
#defn   ElseIfKey(_X_,_K_)       jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX,eqto(_K_),jnt(#ENDIF)
#defn   ElseIfCtrlC(_X_)         jmp(%%CODEIF), %ENDIF:,#ATOM #CMPLX,eqto(3),jnt(#ENDIF)
#defn   ElseIfMemBusy?           jmp(%%CODEIF), %ENDIF:, emptystack?,not,jnt(#ENDIF),
#synon  ElseIfMemBusy?           ElseIfNotMemEmpty?
#defn   ElseIfMemEmpty?          jmp(%%CODEIF), %ENDIF:, emptystack?,jnt(#ENDIF),
#synon  ElseIfMemEmpty?          ElseIfNotMemBusy?
#defn   ElseIfEmpty?(_X_)        jmp(%%CODEIF), %ENDIF:, #ATOM #CMPLX,isempty,jnt(#ENDIF),


/* BIFURCACION */
#defn   Iif(_X_,_Y_,_Z_)            #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:
#synon  Iif                         *TakeIf,*MemIf,*WithIf
#defn   GetIf(_X_,_Y_,_Z_)          #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:
//#defn   MoveIf(_X_,_Y_,_Z_,__W__)   #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:;mov(__W__)

#defn   IfNegative?(_X_)          ##CODEIF,#ATOM #CMPLX, neg?, jnt(#ENDIF),
#defn   IfPositive?(_X_)          ##CODEIF,#ATOM #CMPLX, pos?, jnt(#ENDIF),
#defn   IfFalse?(_X_)             ##CODEIF,#ATOM #CMPLX, jt(#ENDIF),
#defn   IfTrue?(_X_)              ##CODEIF,#ATOM #CMPLX, jnt(#ENDIF),
#defn   IfStringNotVoid?(_X_)     ##CODEIF,#ATOM #CMPLX, void?,jt(#ENDIF),
#defn   IfStringVoid?(_X_)        ##CODEIF,#ATOM #CMPLX, void?,jnt(#ENDIF),

#defn   IfNotFileError?           ##CODEIF, error?,jt(#ENDIF),
#defn   IfFileError?              ##CODEIF, error?,jnt(#ENDIF),

#defn   IfInf?(_X_)               ##CODEIF,#ATOM #CMPLX, inf?,jnt(#ENDIF),
#defn   IfNaN?(_X_)               ##CODEIF,#ATOM #CMPLX, nan?,jnt(#ENDIF),
#defn   IfNotInf?(_X_)            ##CODEIF,#ATOM #CMPLX, inf?,jt(#ENDIF),
#defn   IfNotNaN?(_X_)            ##CODEIF,#ATOM #CMPLX, nan?,jt(#ENDIF),

#defn   IfZero?(_X_)              ##CODEIF,#ATOM #CMPLX, zero?,jnt(#ENDIF),
#defn   IfNotZero?(_X_)           ##CODEIF,#ATOM #CMPLX, zero?,jt(#ENDIF),
#defn   IfArray?(_X_)             ##CODEIF,#ATOM #CMPLX, array?,jnt(#ENDIF),
#defn   IfNotArray?(_X_)          ##CODEIF,#ATOM #CMPLX, array?,jt(#ENDIF),

#defn   IfAnyNan?(_X_)            ##CODEIF, stats(0),nan?,jnt(#ENDIF)
#defn   IfNotAnyNaN(_X_)     ##CODEIF, #ATOM #CMPLX,stats(0),nan?,jnt(#ENDIF)

#defn   IfKeyPressed?        ##CODEIF, kbhit?,jnt(#ENDIF),
#defn   IfKeyDown(_X_)       ##CODEIF,#ATOM #CMPLX,eqto(24),jnt(#ENDIF) 
#defn   IfKeyUp(_X_)         ##CODEIF,#ATOM #CMPLX,eqto(5),jnt(#ENDIF)
#defn   IfKeyBack(_X_)       ##CODEIF,#ATOM #CMPLX,eqto(19),jnt(#ENDIF)
#defn   IfKeyForward(_X_)    ##CODEIF,#ATOM #CMPLX,eqto(4),jnt(#ENDIF)
#defn   IfKeySupr(_X_)       ##CODEIF,#ATOM #CMPLX,eqto(7),jnt(#ENDIF)
#defn   IfKeyBksp(_X_)       ##CODEIF,#ATOM #CMPLX,eqto(8),jnt(#ENDIF)
#defn   IfKeyEscape(_X_)     ##CODEIF,#ATOM #CMPLX,eqto(27),jnt(#ENDIF)
#defn   IfKeyEnter(_X_)      ##CODEIF,#ATOM #CMPLX,eqto(13),jnt(#ENDIF)
#defn   IfKeyTab(_X_)        ##CODEIF,#ATOM #CMPLX,eqto(9),jnt(#ENDIF)
#defn   IfKey(_X_,_K_)       ##CODEIF,#ATOM #CMPLX,eqto(_K_),jnt(#ENDIF)
#defn   IfCtrlC(_X_)         ##CODEIF,#ATOM #CMPLX,eqto(3),jnt(#ENDIF)
#defn   IfMemBusy?           ##CODEIF, emptystack?,not,jnt(#ENDIF),
#synon  IfMemBusy?           IfNotMemEmpty?
#defn   IfMemEmpty?          ##CODEIF, emptystack?,jnt(#ENDIF),
#synon  IfMemEmpty?          IfNotMemBusy?
#defn   IfEmpty?(_X_)        ##CODEIF, #ATOM #CMPLX,isempty,jnt(#ENDIF),


/* IF-ELSEIF-ELSE-ENDIF */
#defn   ElseIf(__X__)        jmp(%%CODEIF), %ENDIF:,  #ATOM#CMPLX , jnt(#ENDIF),
#defn   If(__X__)            ##CODEIF,  #ATOM#CMPLX , jnt(#ENDIF),
#defn   Else                 jmp(%%CODEIF), %ENDIF:, true,jnt(#ENDIF),
#defn   EndIf                %CODEIF:, %ENDIF:,
#defn   Wend                 %&,  jmp(%LOOP), %ENDLOOP:,
#synon  Wend                 Next

// usar construccion "When( expr-L ), {   }" para hacer un pequeño desvio:
#defn   When(_X_)     #ATOM#CMPLX;do

// ciclo REPEAT/UNTIL clásico de PASCAL
#defn   Repeat               &( )  #LOOP: ##ENDLOOP
#defn   UntilFalse(__X__)    %& ,#ATOM#CMPLX, jt(%LOOP), %ENDLOOP:
#defn   UntilNotZero(__X__)  %& ,#ATOM#CMPLX, jz(%LOOP), %ENDLOOP:
#defn   UntilZero(__X__)     %& ,#ATOM#CMPLX, jnz(%LOOP), %ENDLOOP:
#defn   UntilPositive(__X__) %& ,#ATOM#CMPLX, jneg(%LOOP), %ENDLOOP:
#defn   UntilNegative(__X__) %& ,#ATOM#CMPLX, jpos(%LOOP), %ENDLOOP:
#defn   UntilStringVoid(__X__)     %& ,#ATOM#CMPLX, jnv(%LOOP), %ENDLOOP:
#defn   UntilStringNotVoid(__X__)  %& ,#ATOM#CMPLX, jv(%LOOP), %ENDLOOP:
#defn   UntilInf(__X__)      %& ,#ATOM#CMPLX, inf?,jnt(%LOOP), %ENDLOOP:
#defn   UntilNotInf(__X__)   %& ,#ATOM#CMPLX, inf?,jt(%LOOP), %ENDLOOP:
#defn   UntilNotNaN(__X__)   %& ,#ATOM#CMPLX, nan?,jt(%LOOP), %ENDLOOP:
#defn   UntilNaN(__X__)      %& ,#ATOM#CMPLX, nan?,jnt(%LOOP), %ENDLOOP:
#defn   UntilEscape          %& ,kbesc?,jnt(%LOOP), %ENDLOOP:
#defn   UntilBreak           %& ,kbctrlc?,jnt(%LOOP), %ENDLOOP:
#defn   UntilKeyPressed      %& ,kbhit?,jnt(%LOOP), %ENDLOOP:
#defn   UntilEof(__X__)      %& ,eof(__X__),jnt(%LOOP), %ENDLOOP:
#defn   Until(__X__)         %& ,#ATOM#CMPLX, jnt(%LOOP), %ENDLOOP:
/* TRY/CATCH */
#defn   Try                  swtrap( #CATCH ),
#defn   Raise(_ERR_,_M_)     {_M_}, throw(_ERR_),
#defn   Catch(_X_)           jmp(#ENDCATCH), %CATCH:, clearstack,_X_=0,gettry(_X_),  // gettry hace poptry internamente?
#defn   FreeTry              popcatch
#defn   Finish               %ENDCATCH:,popcatch
#define GetStrError$         getstrerror

/* Sswitch */
#defn    DoCase(_X_)         ##CODESW,##CODEMRK;%%MARK=0,#ATOM#CMPLX,mov(%%MARK)
#defn    Case(_X_)           #ATOM#CMPLX,{%%MARK}eq?,do
#defn    Btwn(_X_,_Y_)       #ATOM#CMPLX,{%%MARK}ge?,#ATOM#CMPLX,{%%MARK}le?,and,do
#defn    ExactOccurs(_X_)    {_X_}{%%MARK}ecin?,do
#defn    Occurs(_X_)         {_X_}{%%MARK}cin?,do
#defn    OnList(_X_)         {%%MARK}{_X_}array(1),do
#defn    Exit                jmp(%%CODESW),
///#defn    Freeswitch          ipop(_VTMP09828),clear(_VTMP09828),
#defn    EndDo               %CODESW:,%MARK:,

/* Quiebre de ciclos */
#defn   ___CONTINUE___       %%&, jmp(%%LOOP)
#synon  ___CONTINUE___       *Continue
#defn   ___BREAK___          jmp(%%ENDLOOP)
#synon  ___BREAK___          *Break



/* Asignaciones */
//#defn   andLet(__V__,*)      #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN,{__V__}array?,do{clear(__V__)},mov(__V__)
#defn   ___CLET___(__V__,*)  #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN,clear(__V__);mov(__V__)
#synon  ___CLET___           *CLet,*ClearLet

#defn   ___LET___(__V__,*)   #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN,mov(__V__)
#synon  ___LET___            *Let

#defn   MStore(__X__,*)      #ATOM#CMPLX,#GENCODE $$$*$$$ /*#REVLIST=0,*/cpy(#REVLIST);#ENDGEN,kill,
#synon  MStore               MSto,MCopy
#defn   Store(__X__,*)       #ATOM#CMPLX,#GENCODE $$$*$$$ /*#REVLIST=0,*/mov(#REVLIST);#ENDGEN,
#synon  Store                Sto
// si no se cumple la expresión, no mueve y deja el dato en el stack
#defn    MoveIf(_X_,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);mov(_Y_);jmp(#ENDIF);%ENDIIF:;mov(_Z_);%ENDIF:
#defn    CopyIf(_X_,_Y_,_Z_)     #ATOM#CMPLX;jnt(#ENDIIF);cpy(_Y_);jmp(#ENDIF);%ENDIIF:;cpy(_Z_);%ENDIF:
// mueve un valor a una variable, si se cumple una condicion; sino, la deja intacta, pero el valor se pierde de la memoria:
// Move on( Equals(i,1), w )
#defn    MoveOn(_X_,_V_)       #ATOM#CMPLX;jnt(#ENDIIF);mov(_V_);jmp(#ENDIF);%ENDIIF:;kill;%ENDIF:
// copia el valor si se cumple la condicion; sino, pasa, pero el valor queda en memoria.
// .... Copy on(Equals(i,1), w), ...
#defn    CopyOn(_X_,_V_)       #RAND;#ATOM#CMPLX;jnt(__CPY#RNDV__);cpy(_V_);__CPY#RNDV__:;%RAND
//
#define ___CPYTO___(__X__)   cpy(__X__)
#synon  ___CPYTO___          *Copyto,*Copy
#define ___MOVTO___(__X__)   mov(__X__)
#synon  ___MOVTO___          *Moveto,*Move
#defn   Duplicate(__X__)     #ATOM#CMPLX;dup;
#synon  Duplicate            Dup
#define DuplicateIt          dup;
#synon  DuplicateIt          DupIt


/* DATA a lo Basic */
#defn   PrepareData(__X__)   ____VDATA____={#VOID};jsub(__X__)
#define getLenData           {____VDATA____}length;
#synon  getLenData           LenData
#defn   Data(*)              #GENCODE $$$*$$$ #ATCMLIST;push(____VDATA____),#ENDGEN
#define Read(__V__)          qpop(____VDATA____);mov(__V__)

/* Sistema y stack (memoria del lenguaje)*/
#define ___FORGETALL___       clearstack;
#synon  ___FORGETALL___       *ForgetAll
#define ___FORGET___          kill;
#synon  ___FORGET___          *Forget
#define Retain(__X__)         keep(__X__)
#define Retain                keep;
#define getArgCount           totalarg;
#synon  getArgCount           ArgCount
/* environment */
#defn   SetEnv(_X_,_Y_)   #ATOM#CMPLX;{#APTFE_X_#APTFE};setenv;
#defn   NumEnv(_X_)       {#APTFE_X_#APTFE};getenvnum;
#defn   StrEnv(_X_)       {#APTFE_X_#APTFE};getenv;
#defn   UnsetEnv(_X_)     {#APTFE_X_#APTFE};unsetenv;
/*#defn   Execute(_X_)      #RAND __CTOKSEP010=0;gettoksep;mov(__CTOKSEP010);{""}toksep;#ATOM#CMPLX;sjoin;\
                          exec;{__CTOKSEP010}toksep;%RAND
#defn   System(_X_)       #RAND __CTOKSEP010=0;gettoksep;mov(__CTOKSEP010);{""}toksep;#ATOM#CMPLX;sjoin;\
                          execv;{__CTOKSEP010}toksep;%RAND
*/
#defn   Execute(_X_)      #ATOM#CMPLX;exec;
#defn   System(_X_)       #ATOM#CMPLX;execv;

// mete todo lo puesto en Take(x,y,...),Gosub(F) en un array:
#defn   VargIn(_X_)       _X_={#VOID};pushall(_X_)
/* Argumentos linea de comandos y MAIN */
#define getArgNumber(_N_,_V_)       {[_N_]},xtonum,_V_=0,mov(_V_)
#define getArgString(_N_,_V_)       {[_N_]},_V_="",mov(_V_)
#defn   Params(_V_,_N_)             #RAND, V#RNDV=1,_V_={#VOID}, \
                                    _N_=0,totalarg,mov(_N_), \
                                    LOOPGETARG_#RNDV:, {[ V#RNDV ]},push(_V_),++V#RNDV,\
                                    {V#RNDV,_N_},jle(LOOPGETARG_#RNDV),clear(V#RNDV),%RAND
#defn   GetParam(*)                 #GENCODE $$$*$$$ #LIST=0,{[#ITV]},mov(#LIST);#ENDGEN,
                                   // #GENCODE $$$*$$$ #LIST=[#ITV];#ENDGEN,
#defn   GetArgs(*)                  #GENCODE $$$*$$$ #REVLIST=0,mov(#REVLIST);#ENDGEN,

/* ARCHIVOS */
// se usan como instrucción(,,,)(FD)
/* NO DOCUMENTADOS */
// USAR con Using(MODO), Open File (...)(fd)
#defn   OpenFile(_F_)     #ATOM#CMPLX,open
#defn   CreateFile(_F_)   #ATOM#CMPLX,create
/****/
#defn   Open(_M_,_F_)     #ATOM#CMPLX,#ATOM#CMPLX,open
#defn   Create(_M_,_F_)   #ATOM#CMPLX,#ATOM#CMPLX,create

#defn   ReadLine$(_L_)    #ATOM#CMPLX,readline
#define ReadLinefrom      readline
#defn   ReadStr$(_N_)     #ATOM#CMPLX,readstring
#defn   WriteLine$(_S_)   #ATOM#CMPLX,writeline
#define WriteLineto       writeline
#defn   WriteStr$(_S_)    #ATOM#CMPLX,writestring
#define GetPos            {SEEK_CUR,0}seek
//  SetPos devuelve un dato al stack: debe ser asignado:
#defn   SetPos(_N_)       {SEEK_SET},#ATOM#CMPLX,seek
#defn   Seek(_M_,_P_)     #ATOM#CMPLX,#ATOM#CMPLX,seek

// posicionan puntero de lectura-escritura en archivo abierto: no deben ser asignados
#define SetInit(_FD_)     {SEEK_SET,0}seek(_FD_),kill
#define SetEnd(_FD_)      {SEEK_END,0}seek(_FD_),kill

#defn   ReadLinesFromPos$(_FD_,_N_,_SIZE_)  #RAND; _STR_87364="";_STMP_726345="";_I_#RNDV=_N_;_LOOP_#RNDV:;\
                                            {_SIZE_}readline(_FD_);mov(_STMP_726345);\
                                            {_STR_87364}{_STMP_726345}{"\n"}*cat;mov(_STR_87364);--_I_#RNDV;\
                                            {_I_#RNDV}jnz(_LOOP_#RNDV);{_STR_87364};%RAND

#define GetSLinePos(_V_,_N_)             __ROW_768345=0;{2}{_N_}{_V_}array(8);mov(__ROW_768345);\
                                         [__ROW_768345,1]get(_V_)
#define GetSPosLine(_V_,_N_)             __ROW_768345=0;{1}{_N_}{_V_}array(8);mov(__ROW_768345);\
                                         [__ROW_768345,2]get(_V_)
#defn   GetSLine$(_I_,_SIZE_,_V_,_FD_)   __POS_4345=0;{SEEK_SET}{2};#ATOM#CMPLX;mov(__POS_4345);\
                                         __ROW_768345=0;[__POS_4345,1]get(_V_);{_V_}array(8);\
                                         seek(_FD_);kill;{_SIZE_}readline(_FD_) 

#defn   SearchLines(_F_,_V_)             {"-r $'\n'"},#ATOM#CMPLX,search(_V_)
#defn   Search(_P_,_F_,_V_)              #ATOM#CMPLX,#ATOM#CMPLX,search(_V_)
#define SizeFile(_FD_)                   _TMP_09384234=0;{SEEK_CUR}{0};seek(_FD_);mov(_TMP_09384234);\
                                         {SEEK_END}{0}seek(_FD_);{SEEK_SET}{_TMP_09384234}seek(_FD_);kill;
#defn   Stat(_F_,_A_)                    _A_={#VOID},#ATOM#CMPLX,statsfile,pushall(_A_)

#define andEof(_FD_)                     eof(_FD_);and;
#define orEof(_FD_)                      eof(_FD_);or;
#define Eof(_FD_)                        eof(_FD_)

#define Close(_FD_)                      close(_FD_)
#define getStringFileError$              fileerror
#synon  getStringFileError$              StringFileError$
// Archivos cargado como string:
#defn   LoadString$(_F_,_D_)             #ATOM#CMPLX;loadstring(_D_)
#synon  LoadString$                      LoadStr$
#defn   SaveString$(_F_,_D_)             #ATOM#CMPLX;savestring(_D_)
#synon  SaveString$                      SaveStr$
#defn   GetLine$(__L__,__S__)            #ATOM#CMPLX;getline(__S__)     

/* SETS conjuntos */
// las macros son asignables:
#defn   Set(__X__)            {__X__};array(0);{__X__};sets(0)  // unique
#defn   Union(__X__,__Y__)    {__X__}{__Y__}sets(1)
#defn   Intersect(_X_,_Y_)    {__X__}{__Y__}sets(2)
#defn   SimDiff(_X_,_Y_)      {__X__}{__Y__}sets(4)
#defn   Diff(_X_,_Y_)         {__X__}{__Y__}sets(3)
#defn   Disjoint(_X_,_Y_)     {__X__}{__Y__}sets(5)
#defn   Subset(_X_,_Y_)       {__X__}{__Y__}sets(6)
#defn   Superset(_X_,_Y_)     {__X__}{__Y__}sets(7)

/* BITS */
#defn   getBit(__N__,__I__)   #ATOM#CMPLX;bit(__I__)
#synon  getBit                Bit
#defn   AndBit(__X__,__Y__)   #ATOM#CMPLX;#ATOM#CMPLX;bit(100)
#defn   XorBit(__X__,__Y__)   #ATOM#CMPLX;#ATOM#CMPLX;bit(102)
#defn   OrBit(__X__,__Y__)    #ATOM#CMPLX;#ATOM#CMPLX;bit(101)
#defn   NotBit(__X__)         #ATOM#CMPLX;bit(103)
// Take(1,2,3...),ClrBit(n)
#defn   ClrBit(__X__)         #ATOM#CMPLX;bit(104)
// Take(1,2,3...),SetBit(n)
#defn   setBit(__X__)         #ATOM#CMPLX;bit(105)
// MissByte(LOWBYTE|HIGHBYTE, n)
#defn   MirrByte(__X__,__Y__) #ATOM#CMPLX;#ATOM#CMPLX;bit(106)
// RotBit(LOWBYTE|HIGHBYTE, i, n)
#defn   RotBit(_X_,_P_,_Y_)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;bit(107)
// ShiftR(k,n), k numero de bits
#defn   RShift(_E_,_X_)       #ATOM#CMPLX;#ATOM#CMPLX;bit(108)
#defn   LShift(_E_,_X_)       #ATOM#CMPLX;#ATOM#CMPLX;bit(109)
#defn   Hex2Dec(__X__)        #ATOM#CMPLX;bit(110)
#defn   Oct2Dec(__X__)        #ATOM#CMPLX;bit(111)
#defn   Bin2Dec(__X__)        #ATOM#CMPLX;bit(112)

/* STATS */
#defn   Summatory(__X__)      #ATOM#CMPLX;stats(0)
#define Summatory             stats(10)

#defn   Multiplicatory(__X__) #ATOM#CMPLX;stats(8)
#define Multiplicatory        stats(8)

#defn   GeoMean(__X__)        #ATOM#CMPLX;stats(9)
#define GeoMean               stats(9)
#define getGeometricMean      stats(9)
#synon  getGeometricMean      getGeoMean
#defn   HarMean(__X__)        #ATOM#CMPLX;stats(10)
#define HarMean               stats(10)
#define getHarmonicMean       stats(10)
#synon  getHarmonicMean       getHarMean
#defn   Mean(__X__)           #ATOM#CMPLX;stats(1)
#define Mean                  stats(1)
#define getMean               stats(1)
#defn   SturgClass(_X_)       #ATOM#CMPLX;stats(3)
#define SturgClass            stats(3)
#define getSturgesClass       stats(3)
#synon  getSturgesClass       getSturgClass
#defn   BinClass(_B_,_X_)     #ATOM#CMPLX;#ATOM#CMPLX;stats(4)
#define BinClass              stats(4)
#define getBinClass           stats(4)
#defn   Class(__X__)          #ATOM#CMPLX;stats(5)
#define Class                 stats(5)
#define getClass              stats(5)
#defn   AddSubSucc(__X__)     #ATOM#CMPLX;stats(13)
#define AddSubSucc            stats(13)
#define getAddSubSucc         stats(13)
#defn   SubAddSucc(__X__)     #ATOM#CMPLX;stats(14)
#define SubAddSucc            stats(14)
#define getSubAddSucc         stats(14)
// estas macros actúan sobre matrices 2D:
#defn   SumCol(__X__)         #ATOM#CMPLX;stats(6)
#define SumCol                stats(6)
#define getSumColumns         stats(6)
#synon  getSumColumns         getSumCols
#defn   SumRow(__X__)         #ATOM#CMPLX;stats(7)
#define SumRow                stats(7)
#define getSumRows            stats(7)
#defn   MulCol(__X__)         #ATOM#CMPLX;stats(11)
#define MulCol                stats(11)
#define MultiplyColumns       stats(11)
#synon  MultiplyColumns       MultiplyCols
#defn   MulRow(__X__)         #ATOM#CMPLX;stats(12)
#define MulRow                stats(12)
#define MultiplyRows          stats(12)

/* DATETIME */
// suma o resta días a la fecha DD/MM/AAAA
#defn   DateAdd$(_F_,_N_)     #ATOM#CMPLX;#ATOM#CMPLX;dateadd;
// días transcurridos entre F1 y F2:
#defn   DateDiff(_F2_,_F1_)   #ATOM#CMPLX;#ATOM#CMPLX;datediff;
// horas transcurridas entre 2 horas --> HH:MM:SS
#defn   ElapTime$(_H2_,_H1_)  #ATOM#CMPLX;#ATOM#CMPLX;elaptime;

#defn   andIsLeapYear?(__X__)      #ATOM#CMPLX;date(14);and;
#synon  andIsLeapYear?             andIsLeapYear
#defn   orIsLeapYear?(__X__)       #ATOM#CMPLX;date(14);or;
#synon  orIsLeapYear?              orIsLeapYear
#defn   whileIsLeapYear?(__X__)    #ATOM#CMPLX;date(14)
#synon  whileIsLeapYear?           IsLeapYear?,IsLeapYear

#defn   andIsTimeValid?(__X__)     #ATOM#CMPLX;date(19);and;
#synon  andIsTimeValid?            andIsTimeValid
#defn   orIsTimeValid?(__X__)      #ATOM#CMPLX;date(19);or;
#synon  orIsTimeValid?             orIsTimeValid
#defn   whileIsTimeValid?(__X__)   #ATOM#CMPLX;date(19)
#synon  whileIsTimeValid?          IsTimeValid?,IsTimeValid

#defn   andIsDateValid?(__X__)     #ATOM#CMPLX;date(20);and;
#synon  andIsDateValid?            andIsDateValid
#defn   orIsDateValid?(__X__)      #ATOM#CMPLX;date(20);or;
#synon  orIsDateValid?             orIsDateValid
#defn   whileIsDateValid?(__X__)   #ATOM#CMPLX;date(20)
#synon  whileIsDateValid?          IsDateValid?,IsDateValid

#define DateTime$          datenow(0)
#define DateNow$           datenow(2)
#define TimeNow$           datenow(3)
#defn   getYearof(__X__)      #ATOM#CMPLX;date(6)
#synon  getYearof             Yearof,Year    
#define getYear               date(6)
#define Year                  date(6)
#defn   Month$(__X__)         #ATOM#CMPLX;date(13)  // get no aplica para funciones string $, porque se me canta el orto
#define getMonth$             date(13)
#define Month$                date(13)
#defn   getMonthof(__X__)     #ATOM#CMPLX;date(7)
#synon  getMonthof            Monthof,Month
#define getMonth              date(7)
#define Month                 date(7)
#defn   getDaysMonthof(__X__) #ATOM#CMPLX;date(15)
#synon  getDaysMonthof        DaysMonthof,DaysMonth
#define getDaysMonth          date(15)
#define DaysMonth             date(15)
#defn   getDayWeekof(__X__)   #ATOM#CMPLX;date(17)
#synon  getDayWeekof          DayWeekof,DayWeek
#define getDayWeek            date(17)
#define DayWeek               date(17)
#defn   getDayYearof(__X__)   #ATOM#CMPLX;date(18)
#synon  getDayYearof          DayYearof,DayYear
#define getDayYear            date(18)
#define DayYear               date(18)
#defn   Day$(__X__)           #ATOM#CMPLX;date(12)
#define getDay$               date(12)
#define Day$                  date(12)
#defn   getDayof(__X__)       #ATOM#CMPLX;date(8)
#synon  getDayof              Dayof,Day
#define getDay                date(8)
#define Day                   date(8)
#defn   getWeekof(__X__)      #ATOM#CMPLX;date(17)
#synon  getWeekof             Weekof,Week
#define getWeek               date(17)
#define Week                  date(17)
// sobre horas
#defn   getHourof(__X__)      #ATOM#CMPLX;date(9)
#synon  getHourof             Hourof,Hour
#define getHour               date(9)
#define Hour                  date(9)
#defn   getMinuteof(__X__)    #ATOM#CMPLX;date(10)
#synon  getMinuteof           Minuteof,Minute
#define getMinute             date(10)
#define Minute                date(10)
#defn   getSecondof(__X__)    #ATOM#CMPLX;date(11)
#synon  getSecondof           Secondof,Second

// se declara esto aquí, porque se solapa con "getSecond" de date:
#define getSecondsFromMidnight    seconds;
#synon  getSecondsFromMidnight    SecondsFromMidnight,getSecsFromMidnight

#define getSecond             date(11)
#define Second                date(11)

/* CALENDARIO - CALENDAR */
// genera calendario actual, y devuelve una tabla:
#define getActualCalendar            {1}cal(0)
#synon  getActualCalendar            ActualCalendar
// genera calendario, más/menos _N_ meses:
#defn   getRadialCalendar(_M_,_Y_,_N_)  {1}#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;__CAL_CNTE_29839__=0;\
                                        mov(__CAL_CNTE_29839__);cal(__CAL_CNTE_29839__)
#synon  getRadialCalendar               RadialCalendar
// genera calendario, más _N_ meses:
#defn   getCalendar(_M_,_Y_,_N_)        {1}#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;plus(100);__CAL_CNTE_29839__=0;\
                                        mov(__CAL_CNTE_29839__);cal(__CAL_CNTE_29839__)
#synon  getCalendar                     Calendar
             
// TODO: MACROS UTILES DE VENTANAS O BOX.

/* SOCKETS */
// TCP
// Let ( fd := OpenServerTCP(5,8080) ) 
#defn   OpenServerTCP(_N_,_P_)     #ATOM#CMPLX;#ATOM#CMPLX;socket(0);
// Let ( fdCli := OpenClientTCP("127.0.0.1", 8080) )
// acepta conexion entrante: Let ( fdCli := Accept(fd) )
#define Accept(_FD_)               accept(_FD_)
// ejemplo:  Send(mensajeStr, fdCli) 
#defn   Send(__C__,_FDC_)          #ATOM#CMPLX;send(_FDC_)
#defn   Recv(__SIZE__,_FDC_)       #ATOM#CMPLX;recv(_FDC_)
#defn   OpenClientTCP(_IP_,_P_)    #ATOM#CMPLX;#ATOM#CMPLX;socket(1);
#define Connect(_FD_)              connect(_FD_)
// UDP
// Let ( fd := OpenServerUDP(8080) )
#defn   OpenServerUDP(_P_)         #ATOM#CMPLX;socket(3);
// Let ( fdCli := OpenClientUDP("127.0.0.1", 8080) )
#defn   OpenClientUDP(_IP_,_P_)    #ATOM#CMPLX;#ATOM#CMPLX;socket(4);
#defn   Sendto(__C__,_FD_)         #ATOM#CMPLX;sendto(_FD_)
#defn   RecvFrom(__SIZE__,_FD_)    #ATOM#CMPLX;recvfrom(_FD_)
// cierre socket
#defn   CloseSocket(__FD__)        #ATOM#CMPLX;socket(2)

/* LIMPIEZA DE VARIABLES Y MARCAS */
#define ___CLRMARK___            ;clearmark;
#synon  ___CLRMARK___            *ClearMark
#define ___CLRRANGE___           ;clearrange;
#synon  ___CLRRANGE___           *ClearRange
#define ___CLRINTERVAL___        ;clearinterval;
#synon  ___CLRINTERVAL___        *ClearInterval
#define ___CLRALL___             ;clearall; 
///clearmark;clearinterval;clearrange; 
#synon  ___CLRALL___             *ClearAll
#define ___CLEAR___(__X__)       clear(__X__)
#synon  ___CLEAR___              *Clear

/* PILAS Y ARRAYS ESTANDAR */

/* NO DOCUMENTADOS */
#defn   MultiPush(__X__,*)       #GENCODE $$$*$$$ #ATCMLIST;push(__X__); #ENDGEN;
/***/


#defn   ___PUSHALL___(__X__,*)   #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;pushall(__X__)
#synon  ___PUSHALL___            *PushAll   
#define ___PUSH___(__X__)        push(__X__)
#synon  ___PUSH___               *Push
#define QPop(__X__)              qpop(__X__)
#define Pop(__X__)               pop(__X__)
#define Head(__X__)              head(__X__)
#define Tail(__X__)              tail(__X__)
#defn   Look(__N__,__X__)        #ATOM#CMPLX;look(__X__)

#define andNotEmpty(__X__)       empty(__X__);not;and;
#define orNotEmpty(__X__)        empty(__X__);not;or;
#define andEmpty(__X__)          empty(__X__);and;
#define orEmpty(__X__)           empty(__X__);or;
#define Empty(__X__)             empty(__X__)

#defn   setSeed(__X__)           #ATOM#CMPLX;seed;
#synon  setSeed                  Seed
#defn   getLength(__X__)         #ATOM#CMPLX;length;
#synon  getLength                Length
#define getLengthIt              length;
#define getLength                length;

// estas no devuelven datos:
#defn   LinSpaced(__X__,__Y__,__Z__,_V_)  #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;keep;lthan(1);do{{"LinSpaced: num elements < 1"}throw(2301)},\
                                          seqsp(_V_)
#defn   Sequence(__X__,__Y__,__Z__,_V_)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;keep;lthan(1);do{{"Sequence: num elements < 1"}throw(2301)},seq(_V_)
#defn   CLamp(__X__,__Y__,_V_)            #ATOM#CMPLX;#ATOM#CMPLX;clamp(_V_)

#defn   ___PRNTABLE___(__M__)   #ATOM#CMPLX;{___X___}{___Y___};print2d;
#synon  ___PRNTABLE___          *PrintTable
#defn   ReDim(_X_,*)            #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;reshape(_X_)
#defn   NewRow(_X_,*)           #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;addrow(_X_)
#defn   ___SAVEMATRIX___(_MAT_,_F_)   #ATOM#CMPLX;#ATOM#CMPLX;save;
#synon  ___SAVEMATRIX___              *SaveMatrix
#defn   ___LOADMATRIX___(_F_)         __FILE_TO_LOAD__=0;#ATOM#CMPLX;mov(__FILE_TO_LOAD__);\
                                      {__FILE_TO_LOAD__}statsfile;{__FILE_TO_LOAD__}load;
#synon  ___LOADMATRIX___              *LoadMatrix
// ReadRow(MAX_LINE)(fd). (FD) se coloca naturalmente

#defn   ReadasRow(__M__)        #ATOM#CMPLX;readrow
#synon  ReadasRow               ReadRow
#defn   WriteasRow(__A__)       #ATOM#CMPLX;writerow
#synon  WriteasRow              WriteRow
#defn   Using(__X__)            #ATOM#CMPLX;
#define ReadasRowfrom           readrow
#synon  ReadasRowfrom           ReadRowfrom

// verifica la aproximación de un array comparado con otro:
#defn   Aproach?(_X_)           #RAND; _VAPROACH_#RNDV=0;keep;length;mov(_VAPROACH_#RNDV);xtonum;stats(0);\
                                {_VAPROACH_#RNDV};div;#ATOM#CMPLX;lt?;%RAND

#defn   ForAll(_X_,_R_,*)       clearinterval;clearrange;_R_;get(_X_);#GENCODE $$$*$$$\
                                #ATCMLIST;#ENDGEN;put(_X_);\
                                clearinterval;clearrange;
// encuentra todo lo que no sea cero o nulo, o false. EJ: find all ( Ge(r, 0x101b), rango)
#defn   FindAll(_R_)         #ATOM#CMPLX;cartesian;
#define setRange(__X__)      range(__X__)
#synon  setRange             Range

#defn   UniformRand(_X_,_MU_,_FVAR_,*)    #RAND;_V_#RNDV=0;#GENCODE $$$*$$$ #ATCMLIST;#ENDGEN;randarray(_V_#RNDV);\
                                          {_V_#RNDV}mulby(2);minus(1);mulby(_FVAR_);plus(1);mulby(_MU_);mov(_X_);%RAND
///#synon  getUniformRand                       UniformRand
                                      
/* mapea una matriz, cambiando un valor por _X_. crea el array _Y_, con el array _V_ modificado */ 
#defn   LetMap(_EXPR_,_X_,_V_,_Y_)   #RAND,clear range,_Y_=_V_,#ATOM#CMPLX;cartesian,_RG_#RNDV=0,\
                                     mov(_RG_#RNDV),\
                                     range(_RG_#RNDV),_Y_=_X_,clear(_RG_#RNDV),clear range,%RAND
/* mapea una matriz, cambiando un valor por _X_. Altera el mismo array.
   Si desea mantener el array original, respaldelo, o use LETMAP */ 
#defn   Map(_EXPR_,_X_,_V_)   #RAND,clear range,#ATOM#CMPLX;cartesian,_RG_#RNDV=0,mov(_RG_#RNDV),\
                              range(_RG_#RNDV),_V_=_X_,clear(_RG_#RNDV),clear range,%RAND
// Take(1,2,3,4...),GetRows(v)
#define GetRowsFrom(__X__)    getrow(__X__)
#synon  GetRowsFrom           GetRows 
#define GetColsFrom(__X__)    getcol(__X__)
#synon  GetColsFrom           GetCols
// estas dos no pueden ir dentro de Let:
#defn   CatRows(__X__,*)      #GENCODE $$$*$$$ #REVATCMLIST;#ENDGEN;catrow(__X__)
#defn   CatCols(__X__,*)      #GENCODE $$$*$$$ #REVATCMLIST;#ENDGEN;catcol(__X__)

// Las siguientes macros necesitan declarar [] con anterioridad:
#define GetPageFrom(__X__)        getpage(__X__)
#define PutPage(__X__)        putpage(__X__)

// Static-Get y Static-Put limpian las marcas luego de ejecutarse

/* NO DOCUMENTADOS */
#define ___SINGLESGET___(__X__)      ewget(__X__);clearinterval;
#synon  ___SINGLESGET___             *SingleSGet
#define ___SINGLESPUT___(__X__)      ewput(__X__);clearinterval;
#synon  ___SINGLESPUT___             *SingleSPut

#define ___SINGLEGET___(__X__)       ewget(__X__)
#synon  ___SINGLEGET___              *SingleGet
#define ___SINGLEPUT___(__X__)       ewput(__X__)
#synon  ___SINGLEPUT___              *SinglePut

/****/

#define ___SGET___(__X__)     get(__X__);clearinterval;
#synon  ___SGET___            *SGet
#define ___SPUT___(__X__)     put(__X__);clearinterval;
#synon  ___SPUT___            *SPut
// Get y Put con rangos persistentes. De por sí, los rangos son persistentes.
#define ___GET___(__X__)      get(__X__)
#synon  ___GET___             *Get
#define ___PUT___(__X__)      put(__X__)
#synon  ___PUT___             *Put


// separa un string en un array:
//#defn   Split(__S__,__A__)    #ATOM#CMPLX;split(__A__)
#defn   Split(__S__,__A__,__T__)    __TKN_SPLIT__=0;gettoksep;mov(__TKN_SPLIT__);{__T__}toksep;#ATOM#CMPLX;split(__A__);\
                                    {__TKN_SPLIT__};toksep;
// compacta un array N-DIM en uno 1D, eliminando blancos, ceros y falsos:
#defn   Compact(__A__)        #ATOM#CMPLX;compact;
#defn   Cartesian(__X__)      #ATOM#CMPLX;cartesian;
#define getCartesian          cartesian;

// macros para devolver datos del array:
#define MyDims(__A__)         dims(__A__)
#synon  MyDims                getDimsof,Dimsof,Dims
#define MyRows(__A__)         rows(__A__)
#synon  MyRows                getRowsof,Rowsof,getRows,Rows
#define MyCols(__A__)         cols(__A__)
#synon  MyCols                getColsof,Colsof,getCols,Cols
#define MyPages(__A__)        pages(__A__)
#synon  MyPages               getPagesof,Pagesof,getPages,Pages

/* FUNCIONES ESPECIALES DE ARRAYS */
// Swap de filas, columnas, paginas y rangos de intervalo:
#defn   SwapRows(_X_,_R1_,_R2_)      #RAND,clearstack,_TMP#RNDV_=0,[_R1_,1:end]get(_X_),mov(_TMP#RNDV_),\
                                     [_R2_,1:end]get(_X_),[_R1_,1:end]put(_X_),\
                                     {_TMP#RNDV_}[_R2_,1:end]put(_X_),clear(_TMP#RNDV_),clearstack,clearinterval,%RAND

#defn   SwapCols(_X_,_C1_,_C2_)      #RAND, clearstack,_TMP#RNDV_=0,[1:end,_C1_]get(_X_),mov(_TMP#RNDV_),\
                                     [1:end,_C2_]get(_X_),[1:end,_C1_]put(_X_),\
                                     {_TMP#RNDV_}[1:end,_C2_]put(_X_),clear(_TMP#RNDV_),clearstack,clearinterval,%RAND

#defn   SwapPages(_X_,_P1_,_P2_)      #RAND, clearstack,_TMP#RNDV_=0,[_P1_]getpage(_X_),mov(_TMP#RNDV_),\
                                      [_P2_]getpage(_X_),[_P1_]putpage(_X_),\
                                      {_TMP#RNDV_}[_P2_]putpage(_X_),,clear(_TMP#RNDV_),clearstack,clearinterval,%RAND

#defn   SwapInterval(_X_,_R1_,_R2_)     #RAND,clearstack,_TMP#RNDV_=0,_R1_,get(_X_),mov(_TMP#RNDV_),\
                                        _R2_,get(_X_),_R1_,put(_X_),\
                                        {_TMP#RNDV_}_R2_,put(_X_),clear(_TMP#RNDV_),clearstack,clearinterval,%RAND
#defn   EnumArray(_LISTA_,__INIT__)    #RAND, ___ENUMERATE_=0, {_LISTA_}array? do{ dims(_LISTA_),gthan(1),do{{0}reshape(_LISTA_)},\
                                       rows(_LISTA_),jmp(___EXIT_ENUM_ARRAY__#RNDV)},\
                                       {"enumerate: type mismatch - I need an array"}throw(1999),\
                                       ___EXIT_ENUM_ARRAY__#RNDV:,{__INIT__}minus(1),add,mov(___ENUMERATE_),__ENUMLST_={#VOID},\
                                       {__INIT__,___ENUMERATE_,___ENUMERATE_},minus(__INIT__),plus(1),seqsp(__ENUMLST_){_LISTA_,__ENUMLST_}catcolumn(_LISTA_),%RAND

#defn   EnumString(_STRING_,__INIT__,__TKN__)  ___ENUMERATE_=0,{"string",_STRING_}type,neq?,do{ {"enumerate: type mismatch - I need a string"}throw(1999) },\
                                       ___OLDTKN___=0,gettoksep,mov(___OLDTKN___),{__TKN__}toksep,{_STRING_}split(_STRING_),rows(_STRING_),{__INIT__}minus(1),add,mov(___ENUMERATE_),\
                                       __ENUMLST_={#VOID},{__INIT__,___ENUMERATE_,___ENUMERATE_},minus(__INIT__),plus(1),seqsp(__ENUMLST_),\
                                       {_STRING_,__ENUMLST_}catcolumn(_STRING_),{___OLDTKN___}toksep,

/* Arrays por funcion ARRAY de 1 dimensión (y algunas de 2) sin DEVOLUCION */
#defn   Insert(__V__,__P__,__X__)  #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;array(3);
#defn   Delete(__P__,__X__)        #ATOM#CMPLX;#ATOM#CMPLX;array(4);
#defn   Resize(__S__,__X__)        #ATOM#CMPLX;#ATOM#CMPLX;array(5);
#defn   ZapRange(_RI_,_RF_,_X_)    #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;array(7);
#defn   Concat(__AS__,__AT__)      #ATOM#CMPLX;#ATOM#CMPLX;array(6);
#defn   Sort(__X__)                #ATOM#CMPLX;array(0);
// con devolucion
#defn   RevScan(__V__,__X__)       #ATOM#CMPLX;#ATOM#CMPLX;array(2);
#defn   Scan(__P__,__V__,__X__)    #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;array(1);
#defn   ScanTable(_C_,_V_,_X_)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;array(8);
#defn   Distrib(_A1_,_A2_)         #ATOM#CMPLX;#ATOM#CMPLX;array(9);
#defn   getMaxValueof(__X__)       #ATOM#CMPLX;array(10);
#synon  getMaxValueof              MaxValueof,MaxValue
#defn   getMinValueof(__X__)       #ATOM#CMPLX;array(13);
#synon  getMinValueof              MinValueof,MinValue
#defn   getMaxPosof(__X__)         #ATOM#CMPLX;array(11);
#synon  getMaxPosof                MaxPosof,MaxPos
#defn   getMinPosof(__X__)         #ATOM#CMPLX;array(14);
#synon  getMinPosof                MinPosof,MinPos
#defn   getMaxofArray(_X_)         #ATOM#CMPLX;array(12);  // devuelve valor,posicion
#defn   getMinofArray(_X_)         #ATOM#CMPLX;array(15);  // devuelve valor,posicion
#defn   SwapElements(_P1_,_P2_,_X_)      #ATOM#CMPLX;#ATOM#CMPLX;{_X_}array(19);  // swap elementos

#defn   MixArrays(_X_,_Y_)         #ATOM#CMPLX;#ATOM#CMPLX;array(16);
#define getMaxValue                array(10)
#define MaxValue                   array(10)
#define getMinValue                array(13)
#define MinValue                   array(13)
#define getMaxPos                  array(11)
#define MaxPos                     array(11)
#define getMinPos                  array(14)
#define MinPos                     array(14)
#define MixArrays                  array(16)

/* Posiciones Pares y Nones en arrays */
#define setOddRowsandOddCols    [2:end,2:end];{2}{2}interval2;
#synon  setOddRowsandOddCols    setOddColsandOddRows,setOddRowsandCols,setOddColsandRows
#define setOddRowsandEvenCols   [2:end,1:end];{2}{2}interval2;
#synon  setOddRowsandEvenCols   setEvenColsandOddRows
#define setEvenRowsandEvenCols  [1:end,1:end];{2}{2}interval2;
#synon  setEvenRowsandEvenCols  setEvenColsandEvenRows,setEvenRowsandCols,setEvenColsandRows
#define setEvenRowsandOddCols   [1:end,2:end];{2}{2}interval2;
#synon  setEvenRowsandOddCols   setOddColsandEvenRows
#define setOddRows              [2:end,1:end];{2}interval1;
#define setOddCols              [1:end,2:end];{0}{2}interval2;
#define setOddPos               [2:end];{2}interval1;
#define setOddPages             [2:end];{0}{0}{2}interval3;
#define setEvenRows             [1:end,1:end];{2}interval1;
#define setEvenCols             [1:end,1:end];{0}{2}interval2;
#define setEvenPos              [1:end];{2}interval1;
#define setEvenPages            [1:end];{0}{0}{2}interval3;


/* Declaraciones */
#defn   Dim(*)               #GENCODE $$$*$$$ #ATCMLIST;#ENDGEN,
#defn   DeclareasNumeric(*)  #GENCODE $$$*$$$ #LIST=0;#ENDGEN,
#synon  DeclareasNumeric     DecasNumeric,asNumeric
#defn   DeclareasAlpha(*)    #GENCODE $$$*$$$ #LIST="";#ENDGEN,
#synon  DeclareasAlpha       DecasAlpha,asAlpha
#defn   DeclareasTrue(*)     #GENCODE $$$*$$$ #LIST=0;true(#LIST)#ENDGEN,
#synon  DeclareasTrue        DecasTrue,asTrue
#defn   DeclareasFalse(*)    #GENCODE $$$*$$$ #LIST=0;false(#LIST)#ENDGEN,
#synon  DeclareasFalse       DecasFalse,asFalse
#defn   DeclareasVoidArray(*)    #GENCODE $$$*$$$ #LIST={#VOID} #ENDGEN,
#synon  DeclareasVoidArray       DecasVoidArray,asVoidArray,DeclareasStack,DecasStack,asStack
#defn   DeclareasVariant(*)      #GENCODE $$$*$$$ #LIST=0;#ENDGEN,
#synon  DeclareasVariant         DecasVariant,asVariant

#defn   asNaNArray(*)    __TMPARR__=-1,nanarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#synon  asNaNArray           asArray,foraNaNArray,forNaNArray,foranArray,forArray
#defn   asZerosArray(*)  __TMPARR__=-1,zerosarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#synon  asZerosArray         foraZerosArray,forZerosArray
#defn   asOnesArray(*)   __TMPARR__=-1,onesarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#synon  asOnesArray          foranOnesArray,forOnesArray
#defn   asEyesArray(*)   __TMPARR__=-1,eyesarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill; 
#synon  asEyesArray          foranEyesArray,forEyesArray
#defn   asRandArray(*)   __TMPARR__=-1,randarray(__TMPARR__),\
                                         #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#synon  asRandArray          foraRandArray,forRandArray
#defn   asFillArray(__F__,*)     #ATOM#CMPLX,__TMPARR__=-1,fillarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,\
                                        cpy(#LIST);#ENDGEN,kill;
#synon  asFillArray          foraFillArray,forFillArray
#defn   asIntRndArray(_M_,*)   __TMPARR__=-1,randarray(__TMPARR__),mulby(_M_),int,\
                                             #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#synon  asIntRndArray        foranIntRndArray,forIntRndArray
#defn   asCeilRndArray(_M_,*)   __TMPARR__=-1,randarray(__TMPARR__),mulby(_M_),ceil,\
                                             #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#synon  asCeilRndArray        foranCeilRndArray,forCeilRndArray
#defn   asFloorRndArray(_M_,*)   __TMPARR__=-1,randarray(__TMPARR__),mulby(_M_),floor,\
                                             #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#synon  asFloorRndArray        foranFloorRndArray,forFloorRndArray

/* NO DOCUMENTADO */
#defn   asIntLimitedRndArray(_I_,_F_,*)    __TMPARR__=-1,randarray(__TMPARR__),mulby(1000000),__RNDLOW___=0;#ATOM#CMPLX;\
                                        cpy(__RNDLOW___);#ATOM#CMPLX;sub,mod,plus( __RNDLOW___ ),int,\
                                        #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
//#defn   asVoidArray(*)     __TMPARR__=-1,newarray(__TMPARR__),\
//                                     #GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;
#defn   asAlphaArray(*)     {""},__TMPARR__=-1,fillarray(__TMPARR__);#GENCODE $$$*$$$ #LIST=0,cpy(#LIST);#ENDGEN,kill;

/* RECORD LARGO-POSICION */
// declaracion estandar:
#defn   Declare               ##CODEMRK,__FLD_REC_LP=0,%%MARK="",
#defn   andCommit$(_X_)       #RAND,__PF#RNDV=0,join(__PF#RNDV),{__PF#RNDV}gettoksep;format(_X___FMT_),mov(_X_),%RAND
#synon  andCommit$            Commit$

// RECORD LP
#defn   asRecordLP(_X_)       _X_="";_X___FMT_=%MARK;
#defn   FieldStr(_X_,_S_)     {%%MARK,"$"}{__FLD_REC_LP}xtostr;cat;{":"}cat;{_S_}xtostr;cat;{"L"}cat;cat;mov(%%MARK);_X___SIZE_=_S_;_X_="";++__FLD_REC_LP
#defn   FieldNum(_X_,_S_)     {%%MARK,"$"}{__FLD_REC_LP}xtostr;cat;{":"}cat;{_S_}xtostr;cat;{"R"}cat;cat;mov(%%MARK);_X___SIZE_=_S_;_X_=0;++__FLD_REC_LP
#define getStringLP$(_F_,_X_) [1:_F___SIZE_]get(_X_),trim,mov(_F_);{""}put(_X_);clearmark
#synon  getStringLP$          StringLP$
#define getNumberLP(_F_,_X_)  [1:_F___SIZE_]get(_X_),trim,xtonum,mov(_F_);{""}put(_X_);clearmark
#synon  getNumberLP           NumberLP

/* RECORD LARGO LIBRE */
#defn   asRecord(_X_)         _X_="";_X___FMT_=%MARK;--_X___FMT_
#defn   Fields(*)             __SEP__FLD__=0;{36}chr;mov(__SEP__FLD__);#GENCODE $$$*$$$ {%%MARK}{__SEP__FLD__}{__FLD_REC_LP}xtostr;\
                               cat;cat;gettoksep;cat;mov(%%MARK);++__FLD_REC_LP;#LIST__TOKEN_=__FLD_REC_LP;#LIST=0;#ENDGEN;
#defn   Field(_X_)            {%%MARK,"$"}{__FLD_REC_LP}xtostr;cat;cat;gettoksep;cat;mov(%%MARK);++__FLD_REC_LP;_X___TOKEN_=__FLD_REC_LP;_X_=0;
#defn   Modify$(_D_,_F_,_X_)  #ATOM#CMPLX;{_F___TOKEN_}$$(_X_);mov(_X_)
#define getString$(_X_,_Y_)   {_X___TOKEN_}$(_Y_);trim;mov(_X_)
#synon  getString$            String$ 
#define getNumber(_X_,_Y_)    {_X___TOKEN_}$(_Y_);xtonum;mov(_X_)
#synon  getNumber             Number

/* instrucciones secundarias */
/* CADENAS HBASIC ESTANDAR */
#defn   Upper$(__X__)             #ATOM#CMPLX;upper;
#defn   Lower$(__X__)             #ATOM#CMPLX;lower;
#defn   Hex$(__X__)               #ATOM#CMPLX;hex;
#defn   Bin$(__X__)               #ATOM#CMPLX;bin;
#defn   Octal$(__X__)             #ATOM#CMPLX;oct;
#define SizeBin(__X__)           sizebin(__X__)
#defn   Utf82Str$(__X__)          #ATOM#CMPLX;utf8tostr;
#defn   Str2Utf8$(__X__)          #ATOM#CMPLX;strtoutf8;
#synon  Str2Utf8$                 Utf8$
#defn   RTrim$(__X__)             #ATOM#CMPLX;trimright;
#defn   LTrim$(__X__)             #ATOM#CMPLX;trimleft;
#defn   Trim$(__X__)              #ATOM#CMPLX;trim;
// Take(" ",20),PadC(var) para PadX
#defn   CPad$(__FILL__,__SIZ__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;padcenter;  // requiere algo en el stack
#defn   LPad$(__FILL__,__SIZ__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;padleft;  // requiere algo en el stack
#defn   RPad$(__FILL__,__SIZ__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;padright;  // requiere algo en el stack
//#defn   TypeStr()
//#defn   TypeChr()
#defn   Type$(__X__)              #ATOM#CMPLX;type;

/* NO DOCUMENTADOS */
#defn   Right$(_X_,_V_)           {999999999};#ATOM#CMPLX;#ATOM#CMPLX;copy;
#defn   Left$(_X_,_V_)            #ATOM#CMPLX;{1};#ATOM#CMPLX;copy;
#synon  Upper$                    UCase$
#synon  Lower$                    LCase$
#defn   Segment$(_X_,_I_,_F_)     ___VSEG___=0;#ATOM#CMPLX;mov(___VSEG___);clearinterval;#ATOM#CMPLX;loc1;\
                                  #ATOM#CMPLX;offset1;get(___VSEG___);clearinterval;
#define Segm$(_X_,_I_,_F_)        [_I_:_F_]get(_X_)


/* */

#define getUpper$             upper;
#synon  getUpper$             *getUpperCase,*UpperCase
#define getLower$             lower;
#synon  getLower$             *getLowerCase,*LowerCase
#define getHex$               hex;
#synon  getHex$               *getHexadecimal
#define getBin$               bin;
#synon  getBin$               *getBinary
#define getOctal$             oct;
#synon  getOctal$             *getOctal
#define getUtf82Str$          utf8tostr;
#define getUtf8$              strtoutf8;
#synon  getUtf8$              Utf8$
#define getStr2Utf8$          strtoutf8;

// son ordenes: recortar a la izquierda. No se lee bien obtener recorte a la izquerda
#define RTrim$                trimright;
#synon  RTrim$                *TrimRight
#define LTrim$                trimleft;
#synon  LTrim$                *TrimLeft
#define Trim$                 trim;
#synon  Trim$                 *TrimAll,*AllTrim
// Take(" ",20),PadC(var) para PadX
#define getCPad$              padcenter;  // requiere algo en el stack
#synon  getCPad$              *getPaddingCenter,*PaddingCenter,*getPadCenter,*PadCenter
#define getLPad$              padleft;  // requiere algo en el stack
#synon  getLPad$              *getPaddingLeft,*PaddingLeft,*getPadLeft,*PadLeft
#define getRPad$              padright;  // requiere algo en el stack
#synon  getRPad$              *getPaddingRight,*PaddingRight,*getPadRight,*PadRight

#define Upper$             upper;
#define Lower$             lower;
#define Hex$               hex;
#define Bin$               bin;
#define Octal$             oct;
#define Utf82Str$          utf8tostr;
#define Str2Utf8$          strtoutf8;
#define RTrim$             trimright;
#define LTrim$             trimleft;
#define Trim$              trim;
// Take(" ",20),PadC(var) para PadX
#define CPad$              padcenter;  // requiere algo en el stack
#define LPad$              padleft;  // requiere algo en el stack
#define RPad$              padright;  // requiere algo en el stack


#defn   Replicate$(__X__,__N__)   #ATOM#CMPLX;#ATOM#CMPLX;replicate;
// Take(cadena), ReplyBy(N)
#defn   Replyby(__N__)            #IF replyby(#FATOM) #ELSE #CMPLX;replicate; #EIF

// Concatenación multiple
#defn   MultiCat$(__X__,*)        {""};#GENCODE $$$*$$$ #ATCMLIST;cat; #ENDGEN;mov(__X__)
// concatenación
#defn   Cat$(__X__,__Y__)         #ATOM#CMPLX;#ATOM#CMPLX;cat;
// corta cadenas
#defn   RCut$(__X__,__Y__)        #ATOM#CMPLX;#ATOM#CMPLX;rcut;
#defn   Cut$(__X__,__Y__)         #ATOM#CMPLX;#ATOM#CMPLX;cut;
#defn   BtwnCut$(__X__,__A__,__B__)    #RAND;__V_#RNDV=0;#ATOM#CMPLX;mov(__V_#RNDV);#ATOM#CMPLX;{__V_#RNDV}cut;mov(__V_#RNDV);\
                                       #ATOM#CMPLX;{__V_#RNDV}findat;minus(1);{1}{__V_#RNDV};copy;%RAND
#define ___CAT___                 cat;
#synon  ___CAT___                 *ConcatenateIt,*ConcatIt
//#define RCut$                     rcut;
#defn   +(__X__)                  #ATOM#CMPLX;cat;

#defn   DelFront$(_N_,__X__)      ___SIZE_DEL__=0;#ATOM#CMPLX;mov(___SIZE_DEL__);__X__+=___SIZE_DEL__
#defn   DelBack$(_N_,__X__)       ___SIZE_DEL__=0;#ATOM#CMPLX;mov(___SIZE_DEL__);__X__-=___SIZE_DEL__

#define BaseName$(_X_)            {"/"}{_X_};rcut;
#define FullPath$(_X_)            {""};BaseName(_X_);{_X_}transform

#defn   Mid$(__P__,__F__,__X__)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;copy;

#defn   TranFirst$(_S_,_R_,_X_)   {1}{1};#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;
#defn   TranLast$(_S_,_R_,_X_)    #RAND;___VTRNL___#RNDV=0;___REPL_TXT_=0;#ATOM#CMPLX;mov(___REPL_TXT_);\
                                  ___FIND_LAST_=0;#ATOM#CMPLX;mov(___FIND_LAST_);___AT_LAST_=0;\
                                  {___FIND_LAST_};#ATOM#CMPLX;cpy(___VTRNL___#RNDV);countat;mov(___AT_LAST_);\
                                  {___AT_LAST_}{___REPL_TXT_}{___FIND_LAST_}{___VTRNL___#RNDV}transform;%RAND
#defn   TranTo$(_N_,_S_,_R_,_X_)          {1};#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;
#defn   TranToAll$(_N_,_S_,_R_,_X_)       #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;
#defn   TranFromTo$(_M_,_N_,_S_,_R_,_X_)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;
// Take(desde-la-ocurrencia), Tran$(...)
// Take(hasta-la-ocurrencia,desde-la-ocurrencia), Tran$(...)
// Ejemplo: reemplaza la primera ocurrencia: Take(1,1),Trans$("X","x",v)
#defn   Tran$(__R__,__S__,__X__)  {0}{0}#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;transform;

#defn   LReplChar$(__C__,__R__,__X__)  #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;rleft;
#defn   RReplChar$(__C__,__R__,__X__)  #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;rright;
#defn   ReplChar$(__C__,__R__,__X__)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;rall;

#defn   Repl$(_N_,_P_,__S__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;replace;
#defn   Ins$(__P__,__C__,__X__)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;insert;
#defn   DelChar$(__C__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;deletechar;
#defn   Del$(__P__,__C__,__X__)   #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;delete;
#defn   UniqueChar$(__C__,__X__)  #ATOM#CMPLX;#ATOM#CMPLX;onechar;
#defn   OnlyChar$(__C__,__X__)    #ATOM#CMPLX;#ATOM#CMPLX;onlychar;
#define LRot$(_X_)                [1]get(_X_):++_X_;{_X_}cat;
#define RRot$(_X_,_Y_)            {_X_};[_Y_]get(_X_);cat;mov(_X_);--_X_;{_X_}
#defn   LPosChar$(__C__,__X__)    {1};#ATOM#CMPLX;#ATOM#CMPLX;poschar;
#defn   RPosChar$(__C__,__X__)    {0};#ATOM#CMPLX;#ATOM#CMPLX;poschar;
#defn   Rever$(__X__)             reverse(__X__);   // requiete una constante string
// Take(x,y,z,...), Join(v)
#defn   Join$(__X__)              join(__X__);
/////#defn   SJoin$(__X__)             #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;sjoin
#define getSJoin$                 sjoin;
#define SJoin$                    sjoin;
#defn   Mask$(__F__,__M__,__X__)  #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;mask; 
#defn   Money$(__DEC__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;money;
// Take(a,b,c,...) Format$(v)
#defn   Format$(__X__)            #RAND;__C__#RNDV=__X__;sjoin;gettoksep;format(__C__#RNDV);%RAND
#defn   ChrUtf8$(__X__)           #ATOM#CMPLX;chrutf8;
#defn   Chr$(__X__)               #ATOM#CMPLX;chr;
#defn   Str$(__X__)               #ATOM#CMPLX;xtostr;

#define getChrUtf8$           chrutf8;
#define getChr$               chr;
#define getStr$               xtostr;

/* NUMERICAS */
//#defn   Left$(__P__,__X__)   #ATOM#CMPLX;#ATOM#CMPLX;copy;  //[__F__:end]get(__X__);
// busqueda de posiciones
#defn   FindFirst(__C__,__X__)             {1};#ATOM#CMPLX;#ATOM#CMPLX;findat;
#defn   FindLast(__C__,__X__)              {0};#ATOM#CMPLX;#ATOM#CMPLX;findat;
#defn   FindAt(__AT__,__C__,__X__)         #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;findat;
#defn   Find(__S__,__X__)                  #ATOM#CMPLX;#ATOM#CMPLX;find;
#defn   CountAt(__SALTA__,__S__,__X__)     #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;countat;

#defn   Len(__X__)                #ATOM#CMPLX;len;
#defn   Asc(__X__)                #ATOM#CMPLX;asc;
#defn   CountLin(__X__)           countlines(__X__);   // requiere una constante string

#define getLen                    len;
#define getAsc                    asc;
#define getASCII                  asc;

#define Len                       len;
#define Asc                       asc;


#define setMultiPassOn            multipasson;
#define setMultiPassOff           multipassoff;
#define MultiPassOn               multipasson;
#define MultiPassOff              multipassoff;

#define TokenInit                 ___TOKEN___=0;
#defn   TokenSep(__X__)           #ATOM#CMPLX;toksep;
#defn   getTokenTotal(__X__)      ___V_827662___=0;#ATOM#CMPLX;mov(___V_827662___);totaltoken(___V_827662___);___TOKEN___=0;
#synon  getTokenTotal             TokenTotal
#defn   getToken$(__V__)          {___TOKEN___};$(__V__);
#synon  getToken$                 Token$
#defn   TokenRepl(__X__,__V__)    #ATOM#CMPLX;{___TOKEN___}$$(__V__);mov(__V__);gettoksep;{__V__};onechar;mov(__V__);
#defn   TokenDel(__V__)           {""}{___TOKEN___}$$(__V__);mov(__V__);gettoksep;{__V__};onechar;mov(__V__);
/*#defn   TokenSwap(_N_,__V__)      #RAND  #ATOM#CMPLX;_T1#RNDV=0;cpy(_T1#RNDV);$(__V__);_V1#RNDV=0;mov(_V1#RNDV);\
                                  {___TOKEN___};$(__V__);_V2#RNDV=0;mov(_V2#RNDV);\
                                  {_V1#RNDV}{___TOKEN___}$$(__V__);mov(__V__);\
                                  {_V2#RNDV}{_T1#RNDV}$$(__V__);mov(__V__);%RAND */
#defn   TokenSwap(_N_,__V__)      #ATOM#CMPLX;__T_SWP__=0;cpy(__T_SWP__);$(__V__);\
                                  {___TOKEN___};$(__V__);\
                                  {__T_SWP__}$$(__V__);mov(__V__);\
                                  {___TOKEN___}$$(__V__);mov(__V__);
#define TokenSeparator$           gettoksep;
#synon  TokenSeparator$           Separator$
#defn   Token(__X__)              #ATOM#CMPLX;mov(___TOKEN___)

/* PIVOT usar una cadena de eje en torno a la cual se ejecutan funciones */
#defn   Pivot(__X__)          ##CODEMRK;clearinterval;clearrange;__V_109000160__=0;\
                              #ATOM#CMPLX;mov(__V_109000160__);%%MARK=__V_109000160__;
#defn   Flush(__X__)          clearinterval;clearrange;__X__=%MARK;
#defn   FreePivot             clear(%MARK)
#synon  FreePivot             FreePiv
#defn   Update                mov(%%MARK);
#defn   Backup(__X__)         clearinterval;clearrange;__X__=%%MARK;

/* PIVOT: EXPRESIONES REGULARES */
// para más informacion, ver POSIX y ejemplos:
#defn   RECompile(_F_,_E_,_T_)      #ATOM#CMPLX;#ATOM#CMPLX;regcompile(_T_)    
#defn   REValid(_F_,_S_,_T_)        #ATOM#CMPLX;{_T_};#ATOM#CMPLX;regvalid;
#defn   REMatch(_F_,_N_,_S_,_T_)    #ATOM#CMPLX;#ATOM#CMPLX;{_T_};#ATOM#CMPLX;regmatch;
#defn   REFree(_T_)                 regfree(_T_)

/* PIVOT: PARSER HTML */
#defn   ParsNormal$(_F_,_ATR_,_CON_)    #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;{0}parser   //(%%MARK)
#defn   ParsOnly$(_F_,_ATR_)            #ATOM#CMPLX;#ATOM#CMPLX;{"",1}parser   //(%%MARK)
#defn   UnPars$(_F_)                    #ATOM#CMPLX;unparser  //(%%MARK)

/* BOOLEANAS */
#defn   andIsNotInf?(__X__)      #ATOM#CMPLX;inf?;not;and;
#synon  andIsNotInf?             andNotInf? 
#defn   orIsNotInf?(__X__)       #ATOM#CMPLX;inf?;not;or;
#synon  orIsNotInf?              orNotInf?
#defn   andIsInf?(__X__)         #ATOM#CMPLX;inf?;and;
#synon  andIsInf?                andInf?
#defn   orIsInf?(__X__)          #ATOM#CMPLX;inf?;or;
#synon  orIsInf?                 orInf?
//#defn   Inf?(__X__)              #ATOM#CMPLX;inf?;

#defn   andIsNotNaN?(__X__)      #ATOM#CMPLX;nan?;not;and;
#synon  andIsNotNaN?             andNotNaN? 
#defn   orIsNotNaN?(__X__)       #ATOM#CMPLX;nan?;not;or;
#synon  orIsNotNaN?              orNotNaN?
#defn   andIsNaN?(__X__)         #ATOM#CMPLX;nan?;and;
#synon  andIsNaN?                andNaN?
#defn   orIsNaN?(__X__)          #ATOM#CMPLX;nan?;or;
#synon  orIsNaN?                 orNaN?
//#defn   NaN?(__X__)              #ATOM#CMPLX;nan?;

#defn   andIsNotOdd?(__X__)      #ATOM#CMPLX;odd?;not;and;
#synon  andIsNotOdd?             andNotOdd?
#defn   orIsNotOdd?(__X__)       #ATOM#CMPLX;odd?;not;or;
#synon  orIsNotOdd?              orNotOdd?
#defn   andIsOdd?(__X__)         #ATOM#CMPLX;odd?;and;
#synon  andIsOdd?                andOdd?
#defn   orIsOdd?(__X__)          #ATOM#CMPLX;odd?;or;
#synon  orIsOdd?                 orOdd?
//#defn   Odd?(__X__)              #ATOM#CMPLX;odd?;

#defn   andIsNotZero?(__X__)     #ATOM#CMPLX;zero?;not;and;
#synon  andIsNotZero?            andNotZero?
#defn   orIsNotZero?(__X__)      #ATOM#CMPLX;zero?;not;or;
#synon  orIsNotZero?             orNotZero?
#defn   andIsZero?(__X__)        #ATOM#CMPLX;zero?;and;
#synon  andIsZero?               andZero?
#defn   orIsZero?(__X__)         #ATOM#CMPLX;zero?;or;
#synon  orIsZero?                orZero?
//#defn   Zero?(__X__)             #ATOM#CMPLX;zero?;

#defn   andIsStringNotVoid?(__X__)    #ATOM#CMPLX;void?;not;and;
#synon  andIsStringNotVoid?           andStringNotVoid?
#defn   orIsStringNotVoid?(__X__)     #ATOM#CMPLX;void?;not;or;
#synon  orIsStringNotVoid?            orStringNotVoid?
#defn   andIsStringVoid?(__X__)       #ATOM#CMPLX;void?;and;
#synon  andIsStringVoid?              andStringVoid?
#defn   orIsStringVoid?(__X__)        #ATOM#CMPLX;void?;or;
//#defn   StringVoid?(__X__)       #ATOM#CMPLX;void?;

#defn   andIsNotPositive?(__X__)      #ATOM#CMPLX;pos?;not;and;
#synon  andIsNotPositive?             andNotPositive?
#defn   orIsNotPositive?(__X__)       #ATOM#CMPLX;pos?;not;or;
#synon  orIsNotPositive?              orNotPositive?
#defn   andIsPositive?(__X__)         #ATOM#CMPLX;pos?;and;
#synon  andIsPositive?                andPositive?
#defn   orIsPositive?(__X__)          #ATOM#CMPLX;pos?;or;
#synon  orIsPositive?                 orPositive?
//#defn   Positive?(__X__)         #ATOM#CMPLX;pos?;

#defn   andIsNotNegative?(__X__)      #ATOM#CMPLX;neg?;not;and;
#synon  andIsNotNegative?             andNotNegative?
#defn   orIsNotNegative?(__X__)       #ATOM#CMPLX;neg?;not;or;
#synon  orIsNotNegative?              orNotNegative?
#defn   andIsNegative?(__X__)         #ATOM#CMPLX;neg?;and;
#synon  andIsNegative?                andNegative?
#defn   orIsNegative?(__X__)          #ATOM#CMPLX;neg?;or;
#synon  orIsNegative?                 orNegative?
//#defn   Negative?(__X__)         #ATOM#CMPLX;neg?;

#defn   andIsNotArray?(__X__)         #ATOM#CMPLX;array?;not;and;
#synon  andIsNotArray?                andNotArray?
#defn   orIsNotArray?(__X__)          #ATOM#CMPLX;array?;not;or;
#synon  orIsNotArray?                 orNotArray?
#defn   andIsArray?(__X__)            #ATOM#CMPLX;array?;and;
#synon  andIsArray?                   andArray?
#defn   orIsArray?(__X__)             #ATOM#CMPLX;array?;or;
#synon  orIsArray?                    orArray?
//#defn   Array?(__X__)            #ATOM#CMPLX;array?;

#defn   andIsNotNumeric?(__X__)       #ATOM#CMPLX;numeric?;not;and;
#synon  andIsNotNumeric?              andNotNumeric?
#defn   orIsNotNumeric?(__X__)        #ATOM#CMPLX;numeric?;not;or;
#synon  orIsNotNumeric?               orNotNumeric?
#defn   andIsNumeric?(__X__)          #ATOM#CMPLX;numeric?;and;
#synon  andIsNumeric?                 andNumeric?
#defn   orIsNumeric?(__X__)           #ATOM#CMPLX;numeric?;or;
#synon  orIsNumeric?                  orNumeric?
//#defn   IsNumeric?(__X__)        #ATOM#CMPLX;numeric?;
//#synon  IsNumeric?               Numeric? 

#defn   andIsNotString?(__X__)        #ATOM#CMPLX;string?;not;and;
#synon  andIsNotString?               andNotString?
#defn   orIsNotString?(__X__)         #ATOM#CMPLX;string?;not;or;
#synon  orIsNotString?                orNotString?
#defn   andIsString?(__X__)           #ATOM#CMPLX;string?;and;
#synon  andIsString?                  andString?
#defn   orIsString?(__X__)            #ATOM#CMPLX;string?;or;
#synon  orIsString?                   orString?
//#defn   String?(__X__)           #ATOM#CMPLX;string?;

#defn   andNotExistFile?(__X__)       #ATOM#CMPLX;exist?;not;and;
#defn   orNotExistFile?(__X__)        #ATOM#CMPLX;exist?;not;or;
#defn   andExistFile?(__X__)          #ATOM#CMPLX;exist?;and;
#defn   orExistFile?(__X__)           #ATOM#CMPLX;exist?;or;
#defn   ExistFile?(__X__)             #ATOM#CMPLX;exist?;

#defn   andIsNotEnvVar?(__X__)        #ATOM#CMPLX;env?;not;and;
#synon  andIsNotEnvVar?               andNotEnvVar?
#defn   orIsNotEnvVar?(__X__)         #ATOM#CMPLX;env?;not;or;
#synon  orIsNotEnvVar?                orNotEnvVar?
#defn   andIsEnvVar?(__X__)           #ATOM#CMPLX;env?;and;
#synon  andIsEnvVar?                  andEnvVar?
#defn   orIsEnvVar?(__X__)            #ATOM#CMPLX;env?;or;
#synon  orIsEnvVar?                   orEnvVar?
//#defn   EnvVar?(__X__)           #ATOM#CMPLX;env?;

/*#define andTrue(__X__)           true(__X__);and;
#define orTrue(__X__)            true(__X__);or;*/
#define True(__X__)           true(__X__);
#define True                  true

/*#define andFalse(__X__)          false(__X__);and;
#define orFalse(__X__)           false(__X__);or;*/
#define False(__X__)          false(__X__);
#define False                 false

/* Take(x), Occurs In?("hola mundo!") */
#defn   ExactOccursIt?(__X__)    #ATOM#CMPLX;ecin?;  // requiere algo del stack
#defn   OccursIt?(__X__)         #ATOM#CMPLX;cin?;  // requiere algo del stack

//   Take(num), Between?( 10::including, 100::excluding)
//#define includ     1
//#define exclud     0
//#defn   Between?(__I__,_X_,__F__,_Y_)      #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;between?;

#defn   andIsNotAny?(__X__,__Y__)    #ATOM#CMPLX;#ATOM#CMPLX;any?;not;and;
#synon  andIsNotAny?                 andNotAny?
#defn   orIsNotAny?(__X__,__Y__)     #ATOM#CMPLX;#ATOM#CMPLX;any?;not;or;
#synon  orIsNotAny?                  orNotAny?
#defn   andIsAny?(__X__,__Y__)       #ATOM#CMPLX;#ATOM#CMPLX;any?;and;
#synon  andIsAny?                    andAny?
#defn   orIsAny?(__X__,__Y__)        #ATOM#CMPLX;#ATOM#CMPLX;any?;or;
#synon  orIsAny?                     orAny?
//#defn   Any?(__X__,__Y__)       #ATOM#CMPLX;#ATOM#CMPLX;any?;

#defn   andIsNotAll?(__X__,__Y__)    #ATOM#CMPLX;#ATOM#CMPLX;all?;not;and;
#synon  andIsNotAll?                 andNotAll?
#defn   orIsNotAll?(__X__,__Y__)     #ATOM#CMPLX;#ATOM#CMPLX;all?;not;or;
#synon  orIsNotAll?                  orNotAll?
#defn   andIsAll?(__X__,__Y__)       #ATOM#CMPLX;#ATOM#CMPLX;all?;and;
#synon  andIsAll?                    andAll?
#defn   orIsAll?(__X__,__Y__)        #ATOM#CMPLX;#ATOM#CMPLX;all?;or;
#synon  orIsAll?                     orAll?
//#defn   All?(__X__,__Y__)       #ATOM#CMPLX;#ATOM#CMPLX;all?;

#defn   andIsNotEmpty?(__X__)        #ATOM#CMPLX;isempty;not;and;
#synon  andIsNotEmpty?               andNotEmpty?
#defn   orIsNotEmpty?(__X__)         #ATOM#CMPLX;isempty;not;or;
#synon  orIsNotEmpty?                orNotEmpty?
#defn   andIsEmpty?(__X__)           #ATOM#CMPLX;isempty;and;
#synon  andIsEmpty?                  andEmpty?
#defn   orIsEmpty?(__X__)            #ATOM#CMPLX;isempty;or;
#synon  orIsEmpty?                   orEmpty?
//#defn   Empty?(__X__)           #ATOM#CMPLX;isempty;

// no aplica and u or, porque usa Take.
#define Empty?                  isempty;

// sobre tipos char:
#defn   andIsNotChar?(__X__,__Y__)   #ATOM#CMPLX;{__Y__}typechar?;not;and;
#synon  andIsNotChar?                andNotChar?
#defn   orIsNotChar?(__X__,__Y__)    #ATOM#CMPLX;{__Y__}typechar?;not;or;
#synon  orIsNotChar?                 orNotChar?
#defn   andIsChar?(__X__,__Y__)      #ATOM#CMPLX;{__Y__}typechar?;and;
#defn   orIsChar?(__X__,__Y__)       #ATOM#CMPLX;{__Y__}typechar?;or;
#defn   IsNotChar?(__X__,__Y__)      #ATOM#CMPLX;{__Y__}typechar?;not;
#defn   IsChar?(__X__,__Y__)         #ATOM#CMPLX;{__Y__}typechar?;

/*#defn   IsCAlnum?(__X__)      #ATOM#CMPLX;{"alnum"}typechar?;
#defn   IsCAlpha?(__X__)      #ATOM#CMPLX;{"alpha"}typechar?;
#defn   IsCAscii?(__X__)      #ATOM#CMPLX;{"ascii"}typechar?;
#defn   IsCCntrl?(__X__)      #ATOM#CMPLX;{"cntrl"}typechar?; 
#defn   IsCDigit?(__X__)      #ATOM#CMPLX;{"digit"}typechar?;
#defn   IsCGraph?(__X__)      #ATOM#CMPLX;{"graph"}typechar?;
#defn   IsCLower?(__X__)      #ATOM#CMPLX;{"lower"}typechar?;
#defn   IsCPrint?(__X__)      #ATOM#CMPLX;{"print"}typechar?;
#defn   IsCPunct?(__X__)      #ATOM#CMPLX;{"punct"}typechar?;
#defn   IsCSpace?(__X__)      #ATOM#CMPLX;{"space"}typechar?;
#defn   IsCUpper?(__X__)      #ATOM#CMPLX;{"upper"}typechar?;
#defn   IsCBlank?(__X__)      #ATOM#CMPLX;{"blank"}typechar?;
#defn   IsCXDigit?(__X__)     #ATOM#CMPLX;{"xdigit"}typechar?;*/
// sobre subtupos en cadenas: no sirve AND ni OR, porque deveulve dos valores.
//#defn   andIsNotAllType?(__X__,__Y__)  #ATOM#CMPLX;{__Y__}typestring?;not;and;
//#synon  andIsNotAllType?               andNotAllType?
//#defn   orIsNotAllType?(__X__,__Y__)   #ATOM#CMPLX;{__Y__}typestring?;not;or;
//#synon  orIsNotAllType?                orNotAllType?
#defn   IsNotAllType?(__X__,__Y__)     #ATOM#CMPLX;{__Y__}typestring?;not;
#synon  IsNotAllType?                  NotAllType?
//#defn   andIsAllType?(__X__,__Y__)     #ATOM#CMPLX;{__Y__}typestring?;and;
//#defn   orIsAllType?(__X__,__Y__)      #ATOM#CMPLX;{__Y__}typestring?;or;
#defn   IsAllType?(__X__,__Y__)        #ATOM#CMPLX;{__Y__}typestring?;
#synon  IsAllType?                     AllType?

/*#defn   IsSAlnum?(__X__)      #ATOM#CMPLX;{"alnum"}typestring?;
#defn   IsSAlpha?(__X__)      #ATOM#CMPLX;{"alpha"}typestring?;
#defn   IsSAscii?(__X__)      #ATOM#CMPLX;{"ascii"}typestring?;
#defn   IsSCntrl?(__X__)      #ATOM#CMPLX;{"cntrl"}typestring?; 
#defn   IsSDigit?(__X__)      #ATOM#CMPLX;{"digit"}typestring?;
#defn   IsSGraph?(__X__)      #ATOM#CMPLX;{"graph"}typestring?;
#defn   IsSLower?(__X__)      #ATOM#CMPLX;{"lower"}typestring?;
#defn   IsSPrint?(__X__)      #ATOM#CMPLX;{"print"}typestring?;
#defn   IsSPunct?(__X__)      #ATOM#CMPLX;{"punct"}typestring?;
#defn   IsSSpace?(__X__)      #ATOM#CMPLX;{"space"}typestring?;
#defn   IsSUpper?(__X__)      #ATOM#CMPLX;{"upper"}typestring?;
#defn   IsSBlank?(__X__)      #ATOM#CMPLX;{"blank"}typestring?;
#defn   IsSXDigit?(__X__)     #ATOM#CMPLX;{"xdigit"}typestring?;
*/
// devuelve más que un valor de verda: no aplica and u or
#defn   WhereNot?(__X__,__Y__)     #ATOM#CMPLX;{__Y__}disttypestring?;
/*#defn   WhereNotAlnum?(__X__)      #ATOM#CMPLX;{"alnum"}disttypestring?;
#defn   WhereNotAlpha?(__X__)      #ATOM#CMPLX;{"alpha"}disttypestring?;
#defn   WhereNotAscii?(__X__)      #ATOM#CMPLX;{"ascii"}disttypestring?;
#defn   WhereNotCntrl?(__X__)      #ATOM#CMPLX;{"cntrl"}disttypestring?; 
#defn   WhereNotDigit?(__X__)      #ATOM#CMPLX;{"digit"}disttypestring?;
#defn   WhereNotGraph?(__X__)      #ATOM#CMPLX;{"graph"}disttypestring?;
#defn   WhereNotLower?(__X__)      #ATOM#CMPLX;{"lower"}disttypestring?;
#defn   WhereNotPrint?(__X__)      #ATOM#CMPLX;{"print"}disttypestring?;
#defn   WhereNotPunct?(__X__)      #ATOM#CMPLX;{"punct"}disttypestring?;
#defn   WhereNotSpace?(__X__)      #ATOM#CMPLX;{"space"}disttypestring?;
#defn   WhereNotUpper?(__X__)      #ATOM#CMPLX;{"upper"}disttypestring?;
#defn   WhereNotBlank?(__X__)      #ATOM#CMPLX;{"blank"}disttypestring?;
#defn   WhereNotXDigit?(__X__)     #ATOM#CMPLX;{"xdigit"}disttypestring?; */
/* CONVERSION */
#defn   Bool(__X__)          #ATOM#CMPLX;xtobool;
#defn   Val(__X__)           #ATOM#CMPLX;xtonum;
#define getBool              xtobool;
#define getVal               xtonum;

#define Bool                 xtobool;
#define Val                  xtonum;

/* instrucciones matemáticas */
#defn   getCeilof(_X_)     #ATOM #CMPLX;ceil;
#synon  getCeilof          Ceilof,Ceil
#defn   getFloorof(_X_)    #ATOM #CMPLX;floor;
#synon  getFloorof         Floorof,Floor
#defn   getTruncof(_X_)    #ATOM #CMPLX;trunc;
#synon  getTruncof         Truncof,Trunc
#defn   getLenIntof(_X_)   #ATOM #CMPLX;lennum;
#synon  getLenIntof        LenIntof,LenInt
#defn   getIntof(_X_)      #ATOM #CMPLX;int;
#synon  getIntof           Intof,Int
#defn   getSignof(_X_)     #ATOM #CMPLX;sign;
#synon  getSignof          Signof,Sign
#defn   getCbrtof(_X_)     #ATOM #CMPLX;cbrt;
#synon  getCbrtof          Cbrtof,Cbrt
#defn   getSqrtof(_X_)     #ATOM #CMPLX;sqrt;
#synon  getSqrtof          Sqrtof,Sqrt
#defn   getSciof(_X_)      #ATOM #CMPLX;sci;
#synon  getSciof           Sciof,Sci
#defn   getFactof(_X_)     #ATOM #CMPLX;fact;
#synon  getFactof          Factof,Fact
#defn   getAbsof(_X_)      #ATOM #CMPLX;abs;
#synon  getAbsof           Absof,Abs
#defn   getExp2of(_X_)     #ATOM #CMPLX;exp2;
#synon  getExp2of          Exp2of,Exp2
#defn   getExp10of(_X_)    #ATOM #CMPLX;exp10;
#synon  getExp10of         Exp10of,Exp10
#defn   getExpof(_X_)      #ATOM #CMPLX;exp;
#synon  getExpof           Expof,Exp  
#defn   getLog2of(_X_)     #ATOM #CMPLX;log2;
#synon  getLog2of          Log2of,Log2
#defn   getLog10of(_X_)    #ATOM #CMPLX;log10;
#synon  getLog10of         Log10of,Log10
#defn   getLogof(_X_)      #ATOM #CMPLX;log;
#synon  getLogof           Logof,Log
#defn   getRandto(_X_)     #ATOM #CMPLX;rand;
#synon  getRandto          Randto,Rand
#defn   ++(__X__)     #ATOM #CMPLX;plus(1)
#defn   --(__X__)     #ATOM #CMPLX;minus(1)

#define getCeil          ceil;
#define getFloor         floor;
#define getTrunc         trunc;
#define getLenInt        lennum;
#define getInt           int;
#define getSign          sign;
#define getCbrt          cbrt;
#define getSqrt          sqrt;
#define getSci           sci;
#define getFact          fact;
#define getAbs           abs;
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

#defn   getInvSqrof(_X_)   #ATOM #CMPLX;powby(2);powby(-1)
#synon  getInvSqrof        InvSqrof,InvSqr
#defn   getInvCubof(_X_)   #ATOM #CMPLX;powby(3);powby(-1)
#synon  getInvCubof        InvCubof,InvCub
#defn   getInvQuaof(_X_)   #ATOM #CMPLX;powby(4);powby(-1)
#synon  getInvQuaof        InvQuaof,InvQua
#defn   getInvof(_X_)      #ATOM #CMPLX;powby(-1)
#synon  getInvof           Invof,Inv
#defn   getSqrof(_X_)      #ATOM #CMPLX;powby(2)
#synon  getSqrof           Sqrof,Sqr
#defn   getCubof(_X_)      #ATOM #CMPLX;powby(3)
#synon  getCubof           Cubof,Cub
#defn   getQuaof(_X_)      #ATOM #CMPLX;powby(4)
#synon  getQuaof           Quaof,Qua
#defn   getaHalfof(_X_)    #ATOM #CMPLX;divby(2)
#synon  getaHalfof         aHalfof,aHalf
#defn   getaThirdof(_X_)   #ATOM #CMPLX;divby(3)
#synon  getaThirdof        aThirdof,aThird
#defn   getaQuarterof(_X_) #ATOM #CMPLX;divby(4)
#synon  getaQuarterof      aQuarterof,aQuarter

#define getInvSqr        powby(2);powby(-1)
#define getInvCub        powby(3);powby(-1)
#define getInvQua        powby(4);powby(-1)
#define getInv           powby(-1)
#define getSqr           powby(2)
#define getCub           powby(3)
#define getQua           powby(4)
#define getaHalf         divby(2)
#define getaThird        divby(3)
#define getaQuarter      divby(4)

/* Terminal Inverso, y otros atributos en linea 
   Choca con Inv = 1/x */

/* NO DOCUMENTADO */
#defn   Inversed(__X__)       {"\INV"};#ATOM#CMPLX;cat;{"\033[27m"}cat;
#defn   Underline(__X__)      {"\UL"};#ATOM#CMPLX;cat;{"\033[24m"}cat;
#defn   Italic(__X__)         {"\CUR"};#ATOM#CMPLX;cat;{"\033[23m"}cat;
#defn   Bold(__X__)           {"\ENF"};#ATOM#CMPLX;cat;{"\033[22m"}cat;

/****/

#define InversedOff           {"\033[27m"}print;
#define Inversed              {"\INV"}print;

/* */

#define InvSqr           powby(2);powby(-1)
#define InvCub           powby(3);powby(-1)
#define InvQua           powby(4);powby(-1)
#define Inv              powby(-1)
#define Sqr              powby(2)
#define Cub              powby(3)
#define Qua              powby(4)
#define aHalf            divby(2)
#define aThird           divby(3)
#define aQuarter         divby(4)
#defn   SqrDiff(_X_,_Y_) #ATOM #CMPLX;#ATOM #CMPLX;sqrdiff;
#defn   SqrAdd(_X_,_Y_)  #ATOM #CMPLX;#ATOM #CMPLX;sqradd;
#defn   Hypot(_X_,_Y_)   #ATOM #CMPLX;#ATOM #CMPLX;hypot;
#define ___MULALL___     ;mulall;
#synon  ___MULALL___     *MultiplyAll 
#define ___ADDALL___     ;sumall;
#synon  ___ADDALL___     *AddAll

/* instrucciones aritmeticas */
#define ___ADDIT___        ;add;
#synon  ___ADDIT___        *AddIt
#define ___SUBIT___        ;sub;
#synon  ___SUBIT___        *SubIt,*SubtractIt
#define ___MULIT___        mul;
#synon  ___MULIT___        *MulIt,*MultiplyIt
#define ___DIVIT___        ;div;
#synon  ___DIVIT___        *DivIt,*DivideIt
#define ___IDIVIT___       ;idiv;
#synon  ___IDIVIT___       *iDivIt,*iDivideIt
#define ___INTDIVIT___     ;idiv;
#synon  ___INTDIVIT___     *IntDivIt,*IntDivideIt
#define ___POWIT___        ;pow;
#synon  ___POWIT___        *PowIt,*PowerIt
#define ___ROUNDIT___      ;round;
#synon  ___ROUNDIT___      *RoundIt


#define Minus1(__X__)      minusone(__X__);
#define Minus2(__X__)      minustwo(__X__);
#define Plus1(__X__)       plusone(__X__);
#define Plus2(__X__)       plustwo(__X__);

#defn   Plus(__X__)        ;#IF plus(#FATOM) #ELSE #CMPLX;add; #EIF
#defn   Minus(_X_)         ;#IF minus(#FATOM) #ELSE #CMPLX;sub; #EIF
#defn   Mulby(_X_)         ;#IF mulby(#FATOM) #ELSE #CMPLX;mul; #EIF
#defn   Divby(_X_)         ;#IF divby(#FATOM) #ELSE #CMPLX;div; #EIF
#defn   IntDivby(_X_)      ;#IF idivby(#FATOM) #ELSE #CMPLX;idiv; #EIF
#synon  IntDivby           iDivby
#defn   Module(_X_)        ;#IF module(#FATOM) #ELSE #CMPLX;mod; #EIF
#defn   Powby(_X_)         ;#IF powby(#FATOM) #ELSE #CMPLX;pow; #EIF
#synon  Powby              Poweredby
#defn   Roundby(_X_)       ;#IF roundby(#FATOM) #ELSE #CMPLX;round; #EIF
#defn   Times(_X_)         ;#IF mulby(#FATOM) #ELSE #CMPLX;mul; #EIF
#defn   setPrecision(_X_)  ;#IF prec(#FATOM) #ELSE ___SET_PREC___=0;#CMPLX;mov(___SET_PREC___);prec(___SET_PREC___); #EIF
#synon  setPrecision       Precision,setDecimal,Decimal

#defn   Add(__X__,__Y__)     #IF #ATOM #ELSE #CMPLX;#EIF #IF plus(#FATOM) #ELSE #CMPLX; add; #EIF
#define ___ADD___            add
#synon  ___ADD___            *Add
#defn   Mul(__X__,__Y__)     #IF #ATOM #ELSE #CMPLX;#EIF #IF mulby(#FATOM) #ELSE #CMPLX; mul; #EIF
#define ___MUL___            mul
#synon  ___MUL___            *Mul
#defn   Sub(__X__,__Y__)     #IF #ATOM #ELSE #CMPLX;#EIF #IF minus(#FATOM) #ELSE #CMPLX; sub; #EIF
#define ___SUB___            ;sub;
#synon  ___SUB___            *Sub
#defn   IntDiv(__X__,__Y__)  #IF #ATOM #ELSE #CMPLX;#EIF #IF idivby(#FATOM) #ELSE #CMPLX; idiv; #EIF
#define ___INTDIV___         ;idiv;
#synon  ___INTDIV___         *IntDiv,*iDiv
#defn   Div(__X__,__Y__)     #IF #ATOM #ELSE #CMPLX;#EIF #IF divby(#FATOM) #ELSE #CMPLX; div; #EIF
#define ___DIV___            ;div;
#synon  ___DIV___            *Div

#defn   Mod(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF module(#FATOM) #ELSE #CMPLX; mod; #EIF

#defn   Pow(_X_,_Y_)         #IF #ATOM #ELSE #CMPLX;#EIF #IF powby(#FATOM) #ELSE #CMPLX;pow; #EIF
#define ___POW___            ;pow;
#synon  ___POW___            *Pow

#defn   Round(_X_,_Y_)       #IF #ATOM #ELSE #CMPLX;#EIF #IF roundby(#FATOM) #ELSE #CMPLX; round; #EIF
#define ___ROUND___          ;round;
#synon  ___ROUND___          *Round

#defn   Max(_X_,_Y_)         #ATOM #CMPLX;#ATOM #CMPLX;max;
#defn   Min(_X_,_Y_)         #ATOM #CMPLX;#ATOM #CMPLX;min;

#defn   GCD(_X_,_Y_)         #ATOM #CMPLX;#ATOM #CMPLX;gcd;
#defn   LCM(_X_,_Y_)         #ATOM #CMPLX;#ATOM #CMPLX;lcm;

/* macros trigonométricas */
#defn   getRadianof(_X_)        #ATOM #CMPLX;d2r;
#synon  getRadianof             Radianof,Radian
#defn   getDegreeof(_X_)        #ATOM #CMPLX;r2d;
#synon  getDegreeof             Degreeof,Degree
#defn   getArcCoshof(_X_)       #ATOM #CMPLX;arccosh;
#synon  getArcCoshof            ArcCoshof,ArcCosh,ACosh
#defn   getArcSinhof(_X_)       #ATOM #CMPLX;arcsinh;
#synon  getArcSinhof            ArcSinhof,ArcSinh,Asinh
#defn   getArcTanhof(_X_)       #ATOM #CMPLX;arctanh;
#synon  getArcTanhof            ArcTanhof,ArcTanh,Atanh
#defn   getArcCosof(_X_)        #ATOM #CMPLX;arccos;
#synon  getArcCosof             ArcCosof,ArcCos,Acos
#defn   getArcSinof(_X_)        #ATOM #CMPLX;arcsin;
#synon  getArcSinof             ArcSinof,ArcSin,Asin
#defn   getArcTanof(_X_)        #ATOM #CMPLX;arctan;
#synon  getArcTanof             ArcTanof,ArcTan,Atan
#defn   getCoshof(_X_)          #ATOM #CMPLX;cosh;
#synon  getCoshof               Coshof,Cosh
#defn   getSinhof(_X_)          #ATOM #CMPLX;sinh;
#synon  getSinhof               Sinhof,Sinh
#defn   getTanhof(_X_)          #ATOM #CMPLX;tanh;
#synon  getTanhof               Tanhof,Tanh
#defn   getCosof(_X_)           #ATOM #CMPLX;cos;
#synon  getCosof                Cosof,Cos
#defn   getSinof(_X_)           #ATOM #CMPLX;sin;
#synon  getSinof                Sinof,Sin
#defn   getTanof(_X_)           #ATOM #CMPLX;tan;
#synon  getTanof                Tanof,Tan

#define getRadian        d2r;
#define getDegree        r2d;
#define getArcCosh       arccosh;
#define getArcSinh       arcsinh;
#define getArcTanh       arctanh;
#define getArcCos        arccos;
#define getArcSin        arcsin;
#define getArcTan        arctan;
#define getCosh          cosh;
#define getSinh          sinh;
#define getTanh          tanh;
#define getCos           cos;
#define getSin           sin;
#define getTan           tan;

#define Radian        d2r;
#define Degree        r2d;
#define ArcCosh       arccosh;
#define ArcSinh       arcsinh;
#define ArcTanh       arctanh;
#define ArcCos        arccos;
#define ArcSin        arcsin;
#define ArcTan        arctan;
#define Cosh          cosh;
#define Sinh          sinh;
#define Tanh          tanh;
#define Cos           cos;
#define Sin           sin;
#define Tan           tan;

/* instrucciones logicas */
#defn   IsGt?(__E__)     #IF gthan(#FATOM) #ELSE #CMPLX;gt?; #EIF
#synon  IsGt?            IsGt,IsGthan?,IsGthan

#defn   IsGe?(__E__)     #IF gethan(#FATOM) #ELSE #CMPLX;ge?; #EIF
#synon  IsGe?            IsGe,IsGE?,IsGE,IsGEthan?,IsGEthan

#defn   IsLt?(__E__)     #IF lthan(#FATOM) #ELSE #CMPLX;lt?; #EIF
#synon  IsLt?            IsLt,IsLthan?,IsLthan

#defn   IsLe?(__E__)     #IF lethan(#FATOM) #ELSE #CMPLX;le?; #EIF
#synon  IsLe?            IsLe,IsLE?,IsLE,IsLEto?,IsLEto

#defn   IsEq?(__E__)     #IF eqto(#FATOM) #ELSE #CMPLX; eq?; #EIF
#synon  IsEq?            IsEq,IsEQ?,IsEQ,IsEQto?,IsEQto

#defn   IsNotEq?(__E__)    #IF neqto(#FATOM) #ELSE #CMPLX; neq?; #EIF
#synon  IsNotEq?           IsNotEq,IsNotEQ?,IsNotEQ,IsNotEQto?,IsNotEQto

#defn   andareNotEqArray?(_X_,_Y_)    #IF #ATOM #ELSE #CMPLX;#EIF #IF neqarrto(#FATOM) #ELSE #CMPLX; neqarr?; #EIF;and;
#synon  andareNotEqArray?             andareNotEqArray,andNotEqArray?,andNotEqArray
#defn   orareNotEqArray?(_X_,_Y_)     #IF #ATOM #ELSE #CMPLX;#EIF #IF neqarrto(#FATOM) #ELSE #CMPLX; neqarr?; #EIF;or;
#synon  orareNotEqArray?              orareNotEqArray,orNotEqArray?,orNotEqArray
#defn   whileareNotEqArray?(_X_,_Y_)  #IF #ATOM #ELSE #CMPLX;#EIF #IF neqarrto(#FATOM) #ELSE #CMPLX; neqarr?; #EIF
#synon  whileareNotEqArray?           whileareNotEqArray,whileNotEqArray?,whileNotEqArray,areNotEqArray?,areNotEqArray,NotEqArray?,NotEqArray

#defn   andareEqArray?(_X_,_Y_)     #IF #ATOM #ELSE #CMPLX;#EIF #IF eqarrto(#FATOM) #ELSE #CMPLX; eqarr?; #EIF;and;
#synon  andareEqArray?              andareEqArray,andEqArray?,andEqArray
#defn   orareEqArray?(_X_,_Y_)      #IF #ATOM #ELSE #CMPLX;#EIF #IF eqarrto(#FATOM) #ELSE #CMPLX; eqarr?; #EIF;or;
#synon  orareEqArray?               orareEqArray,orEqArray?,orEqArray
#defn   whileareEqArray?(_X_,_Y_)   #IF #ATOM #ELSE #CMPLX;#EIF #IF eqarrto(#FATOM) #ELSE #CMPLX; eqarr?; #EIF
#synon  whileareEqArray?            whileareEqArray,whileEqArray?,whileEqArray,areEqArray?,areEqArray,EqArray?,EqArray

#defn   andareNotEq?(_X_,_Y_)      #IF #ATOM #ELSE #CMPLX;#EIF #IF neqto(#FATOM) #ELSE #CMPLX; neq?; #EIF;and;
#synon  andareNotEq?               andareNotEq,andNotEq?,andNotEq
#defn   orareNotEq?(_X_,_Y_)       #IF #ATOM #ELSE #CMPLX;#EIF #IF neqto(#FATOM) #ELSE #CMPLX; neq?; #EIF;or;
#synon  orareNotEq?                orareNotEq,orNotEq?,orNotEq
#defn   whileareNotEq?(_X_,_Y_)    #IF #ATOM #ELSE #CMPLX;#EIF #IF neqto(#FATOM) #ELSE #CMPLX; neq?; #EIF
#synon  whileareNotEq?             whileareNotEq,whileNotEq?,whileNotEq,areNotEq?,areNotEq,NotEq?,NotEq

#defn   andareEq?(_X_,_Y_)       #IF #ATOM #ELSE #CMPLX;#EIF #IF eqto(#FATOM) #ELSE #CMPLX; eq?; #EIF;and;
#synon  andareEq?                andareEq,andEq?,andEq
#defn   orareEq?(_X_,_Y_)        #IF #ATOM #ELSE #CMPLX;#EIF #IF eqto(#FATOM) #ELSE #CMPLX; eq?; #EIF;or;
#synon  orareEq?                 orareEq,orEq?,orEq
#defn   whileareEq?(_X_,_Y_)     #IF #ATOM #ELSE #CMPLX;#EIF #IF eqto(#FATOM) #ELSE #CMPLX; eq?; #EIF
#synon  whileareEq?              whileareEq,whileEq?,whileEq,areEq?,Eq?,areEq,Eq

#defn   andLe?(_X_,_Y_)       #IF #ATOM #ELSE #CMPLX;#EIF #IF lethan(#FATOM) #ELSE #CMPLX; le?; #EIF;and;
#synon  andLe?                andLe
#defn   orLe?(_X_,_Y_)        #IF #ATOM #ELSE #CMPLX;#EIF #IF lethan(#FATOM) #ELSE #CMPLX; le?; #EIF;or;
#synon  orLe?                 orLe
#defn   whileLe?(_X_,_Y_)     #IF #ATOM #ELSE #CMPLX;#EIF #IF lethan(#FATOM) #ELSE #CMPLX; le?; #EIF
#synon  whileLe?              whileLe,Le?,Le

#defn   andLt?(_X_,_Y_)       #IF #ATOM #ELSE #CMPLX;#EIF #IF lthan(#FATOM) #ELSE #CMPLX; lt?; #EIF;and;
#synon  andLt?                andLt
#defn   orLt?(_X_,_Y_)        #IF #ATOM #ELSE #CMPLX;#EIF #IF lthan(#FATOM) #ELSE #CMPLX; lt?; #EIF;or;
#synon  orLt?                 orLt
#defn   whileLt?(_X_,_Y_)     #IF #ATOM #ELSE #CMPLX;#EIF #IF lthan(#FATOM) #ELSE #CMPLX; lt?; #EIF
#synon  whileLt?              whileLt,Lt?,Lt

#defn   andGt?(_X_,_Y_)       #IF #ATOM #ELSE #CMPLX;#EIF #IF gthan(#FATOM) #ELSE #CMPLX;gt?; #EIF;and;
#synon  andGt?                andGt
#defn   orGt?(_X_,_Y_)        #IF #ATOM #ELSE #CMPLX;#EIF #IF gthan(#FATOM) #ELSE #CMPLX;gt?; #EIF;or;
#synon  orGt?                 orGt
#defn   whileGt?(_X_,_Y_)     #IF #ATOM #ELSE #CMPLX;#EIF #IF gthan(#FATOM) #ELSE #CMPLX; gt?; #EIF
#synon  whileGt?              whileGt,Gt?,Gt

#defn   andGe?(_X_,_Y_)       #IF #ATOM #ELSE #CMPLX;#EIF #IF gethan(#FATOM) #ELSE #CMPLX; ge?; #EIF;and;
#synon  andGe?                andGe
#defn   orGe?(_X_,_Y_)        #IF #ATOM #ELSE #CMPLX;#EIF #IF gethan(#FATOM) #ELSE #CMPLX; ge?; #EIF;or;
#synon  orGe?                 orGe
#defn   whileGe?(_X_,_Y_)     #IF #ATOM #ELSE #CMPLX;#EIF #IF gethan(#FATOM) #ELSE #CMPLX; ge?; #EIF
#synon  whileGe?              whileGe,Ge?,Ge

/* operadores logicos */
#defn   lAnd(__X__,__Y__)     #ATOM#CMPLX;.apl.;#ATOM#CMPLX;and;
#defn   lOr(__X__,__Y__)      #ATOM#CMPLX;.opl.;#ATOM#CMPLX;or;
#defn   iAnd(__X__,__Y__)     #ATOM#CMPLX;.api.;#ATOM#CMPLX;and;
#defn   iOr(__X__,__Y__)      #ATOM#CMPLX;.opi.;#ATOM#CMPLX;or;
#defn   And(__X__,__Y__)      #ATOM#CMPLX;#ATOM#CMPLX;and;
#defn   Or(__X__,__Y__)       #ATOM#CMPLX;#ATOM#CMPLX;or;
#defn   Nand(__X__,__Y__)     #ATOM#CMPLX;#ATOM#CMPLX;nand;
#defn   Nor(__X__,__Y__)      #ATOM#CMPLX;#ATOM#CMPLX;nor;
#defn   Xor(__X__,__Y__)      #ATOM#CMPLX;#ATOM#CMPLX;xor;

#defn   and(__X__)                #ATOM#CMPLX;and;
#defn   or(__X__)                 #ATOM#CMPLX;or;
#defn   nand(__X__)               #ATOM#CMPLX;nand;
#defn   nor(__X__)                #ATOM#CMPLX;nor;
#defn   xor(__X__)                #ATOM#CMPLX;xor;

#defn   andNot(__X__)             #ATOM#CMPLX;not;and;
#defn   orNot(__X__)              #ATOM#CMPLX;not;or;
#defn   Not(__X__)                #ATOM#CMPLX;not;

/* instrucciones primarias */
#defn   Locatecursorin(*)         #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;goxy;
#synon  Locatecursorin            Locatecursor,Locate
#defn   LocateinRow(__X__)        #ATOM#CMPLX;gox;
#synon  LocateinRow               LocateRow,LocRow
#defn   LocateinColumn(__X__)     #ATOM#CMPLX;goy;
#synon  LocateinColumn            LocateColumn,LocateCol,LocCol

#define ___GETCURX___(__X__)      __X__=0,cposx(__X__)
#synon  ___GETCURX___             *getCurX,*CurX 
#define ___GETCURY___(__X__)         __X__=0,cposy(__X__)
#synon  ___GETCURY___             *getCurY,*CurY
#define ___PRNITWANL___           {"\n"}print
#synon  ___PRNITWANL___           *PrintItwithaNewline,*PrintItwithaNewl

#define ___PUTANL___              puts("\n")
#synon  ___PUTANL___              *PutaNewl,*PutNewl

#defn    Printtop(_X_)           #ATOM#CMPLX;puts;
#define  Printtop               ;puts;
#define  Puts(_X_)              ;puts(_X_)


#defn   Newline                   "\n"
#synon  Newline                   Newl

//#defn   andPrintText:(__X__) {#APTFE__X__#APTFE}print
//#synon  andPrintText:        thenPrintText:,PrintText:,thenPrintText,PrintText
#defn   ___PRNUSINGTOK___(*)      #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;printusingtoken;
#synon  ___PRNUSINGTOK___         *PrintUsingToken,*PrintUsingTkn

#define ___PRNITUSINGTOK___       printusingtoken;
#synon  ___PRNITUSINGTOK___       *PrintItUsingToken,*PrintItUsingTkn


/** NO DOCUMENTADO **/
#define sPrintF(__V__,__S__,*)   Take(*),Format$(__S__),Move(__V__)

/******* ASTA AQUI *******/

#defn   ___PRNF___(__X__,*)       #RAND;__C__#RNDV=0;#ATOM#CMPLX;mov(__C__#RNDV);#GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;sjoin;{","}format(__C__#RNDV);print;%RAND
#synon  ___PRNF___                *PrintF

#defn   ___PRN___(*)              #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;print;
#synon  ___PRN___                 *Print  

#defn   ___PRNIF___(_X_,_Y_,_Z_)  #ATOM#CMPLX;jnt(#ENDIIF);#ATOM#CMPLX;jmp(#ENDIF);%ENDIIF:;#ATOM#CMPLX;%ENDIF:,print
#synon  ___PRNIF___               *PrintIf

#define ___PRNIT___               print
#synon  ___PRNIT___               *PrintIt

#defn   ___TAKE___(*)             #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;
#synon  ___TAKE___                *Take, *With, *Memorize, *Mem    

#defn   GetChar$(_X_)        #RAND,pause,lastkey(_X_),{_X_}{194}{1}{207}{1}between?,do{{_X_}chr,pause,\
                             lastkey(_X_),{_X_}chr,cat,utf8tostr,jmp(__GETCHAR__#RNDV)},\
                             {_X_}chr,utf8tostr,__GETCHAR__#RNDV:,mov(_X_),kbfree,%RAND
#defn   GetCh                #RAND;_VCH#RNDV_=0;__GETCHAR__#RNDV:;pause;lastkey(_VCH#RNDV_);{_VCH#RNDV_}\
                             dup;{194}{1}{207}{1}between?;do{jmp(__GETCHAR__#RNDV)};kbfree;%RAND
#defn   PutKey(__X__)        #ATOM#CMPLX;keyput;
//#defn   KeyPressed(__X__)    kbhit?;do{lastkey(__X__)}

/* NO DOCUMENTADO */
#defn   getScanCode(_X_)     #RAND,lastkey(_X_),{_X_}{194}{1}{207}{1}between?,do{{_X_}chr,pause,\
                             lastkey(_X_),{_X_}chr,cat,utf8tostr,jmp(__GETCHAR__#RNDV)},\
                             {_X_}chr,utf8tostr,__GETCHAR__#RNDV:,asc,mov(_X_),kbfree,%RAND
#synon  getScanCode          ScanCode
/****/

/* algunas macros semánticas */
#define  whilevar(__X__)                  {__X__};
#synon   whilevar                         ifvar,invar,var,whilecte,ifcte,incte,cte
#defn    whileexpression(__X__)           #ATOM#CMPLX;
#synon   whileexpression                  ifexpression,inexpression,expression
 
/* macros de control de terminal 
   Solo puede usar argumentos atómicos, no expresiones, y en el caso de los colores,
   dependerá del tipo de terminal. En el mío funciona. */
#define HideCursor            {"\033[?25l"}, print;
#synon  HideCursor            setCursorOff,CursorOff
#define ShowCursor            {"\033[?25h"}, print;
#synon  ShowCursor            setCursorOn,CursorOn
///#defn   GotoXY(_X_,_Y_)       {"\033["},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{"H"},print
///#define Home                  {"\033[2J\033[1;1H"},print

// necesita Locate para localizar el cursor.
#defn   FillBox(_C_,_H_,_W_)  #ATOM#CMPLX;#ATOM#CMPLX;#ATOM#CMPLX;fillbox;
// borra hacia abajo (0), hacia arriba(1), todo(2)
#defn   ClrScr(_X_)           {"\033["},#ATOM#CMPLX,{"J"}, print;
// borra hacia derecha (0), hacia izquierda(1), toda la linea(2)
#defn   ClrLine(_X_)         {"\033["},#ATOM#CMPLX,{"K"}, print;
#define Cls                   {"\033[2J\033[1;1H\n"},print;
//#defn   Fw(_X_)               {"\033["},#ATOM#CMPLX,{"C"},print; 
#defn   Fw(_X_)               #ATOM#CMPLX,updcol;
//#defn   Bw(_X_)               {"\033["},#ATOM#CMPLX,{"D"},print;
#defn   Bw(_X_)               #ATOM#CMPLX,mulby(-1),updcol;
#define ScrollDown            {"\033D"},print;
#define ScrollUp              {"\033M"},print;
#defn   ScrollScr(_X_,_Y_)    {"\033["},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{"r"},print;
#define ResetScroll           {"\033[r"},print;
#defn   JumpLines(_X_)        {"\033["},#ATOM#CMPLX,{"E"},print;
#defn   PrevLines(_X_)        {"\033["},#ATOM#CMPLX,{"F"},print;
//#defn   Up(_X_)               {"\033["},#ATOM#CMPLX,{"A"},print;
#defn   Up(_X_)               #ATOM#CMPLX,mulby(-1),updrow;
//#defn   Down(_X_)             {"\033["},#ATOM#CMPLX,{"B"},print;
#defn   Down(_X_)             #ATOM#CMPLX,updrow;
#defn   ResizTerm(_X_,_Y_)    {"\033[8;"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{"t"},print,sleep(0.5)  // cambia dimensiones del terminal
#define getSizeTerm(_X_,_Y_)  getsizscr,mov(_X_),mov(_Y_)  // devuelve: (col, row)
#synon  getSizeTerm           SizeTerm
#define CursorSave            {"\0337"},print;
#define CursorRest            {"\0338"},print;
#define SaveScreen            {"\033[?1049h\033[H"},print;
#define RestScreen            {"\033[?1049l"},print;

#define SetVideoGraph(_X_)    System(Cat$(Cat$("gsettings set org.gnome.Terminal.Legacy.Profile:/org/gnome/terminal/legacy/profiles:/:b1dcc9dd-5262-4d8d-a863-c897e6d979b9/ font 'Ubuntu Mono ",Str$(_X_)),"'"))
#define SetVideoText          System("gsettings set org.gnome.Terminal.Legacy.Profile:/org/gnome/terminal/legacy/profiles:/:b1dcc9dd-5262-4d8d-a863-c897e6d979b9/ font 'Ubuntu Mono 12'")

#defn   setForeground(_X_)       {"\033[38;5;"},#ATOM#CMPLX,{"m"}print;
#synon  setForeground            Foreground
#defn   setBackground(_X_)       {"\033[48;5;"},#ATOM#CMPLX,{"m"}print;
#synon  setBackground            Background
#defn   setColor(_X_,_Y_)        {"\033[38;5;"},#ATOM#CMPLX,{"m"},{"\033[48;5;"},#ATOM#CMPLX,{"m"}print;
#synon  setColor                 Color
#defn   setRGBF(_X_,_Y_,_Z_)     {"\033[38;2;"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{"m"}print;
#synon  setRGBF                  RGBF
#defn   setRGBB(_X_,_Y_,_Z_)     {"\033[48;2;"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{";"},#ATOM#CMPLX,{"m"}print;
#synon  setRGBB                  RGBB
#define setCanvasPaper             RGBB(227,216,181)
#synon  setCanvasPaper             CanvasPaper
#define setCanvasTerminal          RGBB(7,27,4)
#synon  setCanvasTerminal          CanvasTerminal
#define setCanvasOld               RGBB(60,6,19)
#synon  setCanvasOld               CanvasOld
#define setCanvasOcean             RGBB(72,136,216)
#synon  setCanvasOcean             CanvasOcean
#define setWhitePencil           RGBF(255,255,255)
#synon  setWhitePencil           WhitePencil
#define setBlackPencil           RGBF(30,27,10)
#synon  setBlackPencil           BlackPencil
#define setAmberPencil           RGBF(243,135,13)
#synon  setAmberPencil           AmberPencil
#define setGreenPencil           RGBF(121,192,35)
#synon  setGreenPencil           GreenPencil
#define BoldOff               {"\033[22m"}print;
#define Bold                  {"\ENF"}print;

#define ItalicOff             {"\033[23m"}print;
#define Italic                {"\CUR"}print;
#define UnderlineOff          {"\033[24m"}print;
#define Underline             {"\UL"}print;

/* TIME MEASURE */
#define Tic(_X_)             _X_=0,timecpu(_X_)    
#define Toc(_X_,_Y_)         _Y_=0,timecpu(_Y_),{_Y_}minus(_X_),clockpersec,div,mov(_Y_),clear(_X_)

// convierte a segundos una hora "hh:mm:ss:mm". _X_ se mete en stack.
// "seconds", sin stack, entrega los segundos desde la medianoche

#defn   getSecondsof(_X_)    #ATOM#CMPLX;seconds;
#synon  getSecondsof         Secondsof,Seconds

// obtiene el tiempo transcurrido en milisegundos, entre _X_ e _Y_:
#defn   LookTime(_X_,_Y_)    #ATOM#CMPLX;timer(_Y_)
#defn   MicroSec(_X_)        #ATOM#CMPLX;microsecs;
#defn   Sec2Time(_X_)        #ATOM#CMPLX;sectotime;
#defn   Sleep(_X_)           #ATOM#CMPLX;sleep;
// obtiene el tiempo transcurrido de ejecución:
#define TimeCpu(__X__)       timecpu(__X__)
#define ClocksPerSec         clockpersec;

/* DEFINICIONES DE CUERPO */
#define Stop                 {0}return
#define End                  {0}return
#define Begin                main:
///#defn   Return(_X_)          #GENCODE $$$*$$$ #ATCMLIST; #ENDGEN;back;
#defn   Return(_X_)          #ATOM#CMPLX;back;
#define ___RETURN___         back
#synon  ___RETURN___         *Return
#define ___BACK___           back
#synon  ___BACK___           *Back
#define Keep                 keep;
#define OptionCtrl+C         .ctrlc
#define OptionStack          .stack
#defn   Function(_F_,*)      _F_:,#GENCODE $$$*$$$ #REVLIST=0;mov(#REVLIST);#ENDGEN;
#defn   Procedure(_F_,*)     _F_:,#GENCODE $$$*$$$ #REVLIST=0;mov(#REVLIST);#ENDGEN;

#define putPause             pause;
#synon  putPause             Pause

/* nivel semántico: permite controlar datos en estilo natural*/
#define afterdoingit         emptystack?,not,do{ {"I cannot continue due to retentive data "},throw(1001) }
#synon  afterdoingit         secondly,finally,doingit
#define then                 emptystack?do{ {"I cannot continue because data is missing "},throw(1000) }


/* CONSTANTES */

/* Creacion de archivos */
#define CREATE_NORMAL    0
#define CREATE_READONLY  1
#define CREATE_HIDDEN    2
#define CREATE_SYSTEM    4

/*
  Constantes para la apertura de archivos
*/
#define OPEN_READ        0     // solo lectura
#define OPEN_WRITE       1     // solo escritura
#define OPEN_APPEND      2     // lectura y escritura (append)
#define OPEN_EXCLUSIVE   16    // RED: solo lectura exclusivo
#define OPEN_DWRITE      32    // RED: inahbita que otro escriba
#define OPEN_DREAD       48    // RED: inhabilita que otro lea
#define OPEN_SHARED      64    // RED::comparte lectura y escritura (64+0, 64+1...)
/* FSEEK constantes */
#define SEEK_SET         0
#define SEEK_CUR         1
#define SEEK_END         2

/* bits */
#define LOWBYTE      0
#define HIGHBYTE     1

/* CONSTANTES REGEX */
#define REG_BASIC     0
/* If this bit is set, then use extended regular expression syntax.
   If not set, then use basic regular expression syntax.  */
#define REG_EXTENDED  1

/* If this bit is set, then ignore case when matching.
   If not set, then case is significant.  */
#define REG_ICASE     2

/* If this bit is set, then anchors do not match at newline
     characters in the string.
   If not set, then anchors do match at newlines.  */
#define REG_NEWLINE   4

/* If this bit is set, then report only success or fail in regexec.
   If not set, then returns differ between not matching and errors.  */
#define REG_NOSUB     8

/* POSIX `eflags' bits (i.e., information for regexec).  */

/* If this bit is set, then the beginning-of-line operator doesn't match
     the beginning of the string (presumably because it's not the
     beginning of a line).
   If not set, then the beginning-of-line operator does match the
     beginning of the string.  */
#define REG_NOTBOL    1

/* Like REG_NOTBOL, except for the end-of-line.  */
#define REG_NOTEOL    2

/* Use PMATCH[0] to delimit the start and end of the search in the
   buffer.  */
#define REG_STARTEND  4

/* TECLAS */
#define K_UP                    5     /*   Up arrow, Ctrl-E              */
#define K_DOWN                  24    /*   Down arrow, Ctrl-X            */
#define K_LEFT                  19    /*   Left arrow, Ctrl-S            */
#define K_RIGHT                 4     /*   Right arrow, Ctrl-D           */
#define K_HOME                  1     /*   Home, Ctrl-A                  */
#define K_END                   6     /*   End, Ctrl-F                   */
#define K_PGUP                  18    /*   PgUp, Ctrl-R                  */
#define K_PGDN                  3     /*   PgDn, Ctrl-C                  */
#define K_CTRL_UP               397   /* * Ctrl-Up arrow                 */
#define K_CTRL_DOWN             401   /* * Ctrl-Down arrow               */
#define K_CTRL_LEFT             26    /*   Ctrl-Left arrow, Ctrl-Z       */
#define K_CTRL_RIGHT            2     /*   Ctrl-Right arrow, Ctrl-B      */
#define K_CTRL_HOME             29    /*   Ctrl-Home, Ctrl-]             */
#define K_CTRL_END              23    /*   Ctrl-End, Ctrl-W              */
#define K_CTRL_PGUP             31    /*   Ctrl-PgUp, Ctrl-Hyphen        */
#define K_CTRL_PGDN             30    /*   Ctrl-PgDn, Ctrl-^             */

#define K_ALT_UP                408   /* * Alt-Up arrow                  */
#define K_ALT_DOWN              416   /* * Alt-Down arrow                */
#define K_ALT_LEFT              411   /* * Alt-Left arrow                */
#define K_ALT_RIGHT             413   /* * Alt-Right arrow               */
#define K_ALT_HOME              407   /* * Alt-Home                      */
#define K_ALT_END               415   /* * Alt-End                       */
#define K_ALT_PGUP              409   /* * Alt-PgUp                      */
#define K_ALT_PGDN              417   /* * Alt-PgDn                      */

/* Misc. keys */

#define K_ENTER                 13    /*   Enter, Ctrl-M                 */
#define K_INTRO                 13    /*                                 */
#define K_RETURN                13    /*   Return, Ctrl-M                */
#define K_SPACE                 32    /*   Space bar                     */
#define K_ESC                   27    /*   Esc, Ctrl-[                   */
/* Editing keys */

#define K_INS                   22    /*   Ins, Ctrl-V                   */
#define K_DEL                   7     /*   Del, Ctrl-G                   */
#define K_BS                    8     /*   Backspace, Ctrl-H             */
#define K_TAB                   9     /*   Tab, Ctrl-I                   */
#define K_SH_TAB                271   /*   Shift-Tab                     */

#define K_CTRL_INS              402   /* * Ctrl-Ins                      */
#define K_CTRL_DEL              403   /* * Ctrl-Del                      */
#define K_CTRL_BS               127   /*   Ctrl-Backspace                */
#define K_CTRL_TAB              404   /* * Ctrl-Tab                      */

#define K_ALT_INS               418   /* * Alt-Ins                       */
#define K_ALT_DEL               419   /* * Alt-Del                       */
#define K_ALT_BS                270   /* * Alt-Backspace                 */
#define K_ALT_TAB               421   /* * Alt-Tab                       */

#define K_CTRL_SH_TAB           423   /* * Ctrl-Shift-Tab                */
#define K_SH_BS                 423   /* * Shift-Backspace               */

/* Control keys */

#define K_CTRL_A                1     /*   Ctrl-A, Home                  */
#define K_CTRL_B                2     /*   Ctrl-B, Ctrl-Right arrow      */
#define K_CTRL_C                3     /*   Ctrl-C, PgDn, Ctrl-ScrollLock */
#define K_CTRL_D                4     /*   Ctrl-D, Right arrow           */
#define K_CTRL_E                5     /*   Ctrl-E, Up arrow              */
#define K_CTRL_F                6     /*   Ctrl-F, End                   */
#define K_CTRL_G                7     /*   Ctrl-G, Del                   */
#define K_CTRL_H                8     /*   Ctrl-H, Backspace             */
#define K_CTRL_I                9     /*   Ctrl-I, Tab                   */
#define K_CTRL_J                10    /*   Ctrl-J                        */
#define K_CTRL_K                11    /*   Ctrl-K                        */
#define K_CTRL_L                12    /*   Ctrl-L                        */
#define K_CTRL_M                13    /*   Ctrl-M, Return                */
#define K_CTRL_N                14    /*   Ctrl-N                        */
#define K_CTRL_O                15    /*   Ctrl-O                        */
#define K_CTRL_P                16    /*   Ctrl-P                        */
#define K_CTRL_Q                17    /*   Ctrl-Q                        */
#define K_CTRL_R                18    /*   Ctrl-R, PgUp                  */
#define K_CTRL_S                19    /*   Ctrl-S, Left arrow            */
#define K_CTRL_T                20    /*   Ctrl-T                        */
#define K_CTRL_U                21    /*   Ctrl-U                        */
#define K_CTRL_V                22    /*   Ctrl-V, Ins                   */
#define K_CTRL_W                23    /*   Ctrl-W, Ctrl-End              */
#define K_CTRL_X                24    /*   Ctrl-X, Down arrow            */
#define K_CTRL_Y                25    /*   Ctrl-Y                        */
#define K_CTRL_Z                26    /*   Ctrl-Z, Ctrl-Left arrow       */

/* Alt keys */

#define K_ALT_A                 286   /*   Alt-A                         */
#define K_ALT_B                 304   /*   Alt-B                         */
#define K_ALT_C                 302   /*   Alt-C                         */
#define K_ALT_D                 288   /*   Alt-D                         */
#define K_ALT_E                 274   /*   Alt-E                         */
#define K_ALT_F                 289   /*   Alt-F                         */
#define K_ALT_G                 290   /*   Alt-G                         */
#define K_ALT_H                 291   /*   Alt-H                         */
#define K_ALT_I                 279   /*   Alt-I                         */
#define K_ALT_J                 292   /*   Alt-J                         */
#define K_ALT_K                 293   /*   Alt-K                         */
#define K_ALT_L                 294   /*   Alt-L                         */
#define K_ALT_M                 306   /*   Alt-M                         */
#define K_ALT_N                 305   /*   Alt-N                         */
#define K_ALT_O                 280   /*   Alt-O                         */
#define K_ALT_P                 281   /*   Alt-P                         */
#define K_ALT_Q                 272   /*   Alt-Q                         */
#define K_ALT_R                 275   /*   Alt-R                         */
#define K_ALT_S                 287   /*   Alt-S                         */
#define K_ALT_T                 276   /*   Alt-T                         */
#define K_ALT_U                 278   /*   Alt-U                         */
#define K_ALT_V                 303   /*   Alt-V                         */
#define K_ALT_W                 273   /*   Alt-W                         */
#define K_ALT_X                 301   /*   Alt-X                         */
#define K_ALT_Y                 277   /*   Alt-Y                         */
#define K_ALT_Z                 300   /*   Alt-Z                         */
#define K_ALT_BACKQUOTE         297   /*   Alt-`                         */
#define K_ALT_1                 376   /*   Alt-1                         */
#define K_ALT_2                 377   /*   Alt-2                         */
#define K_ALT_3                 378   /*   Alt-3                         */
#define K_ALT_4                 379   /*   Alt-4                         */
#define K_ALT_5                 380   /*   Alt-5                         */
#define K_ALT_6                 381   /*   Alt-6                         */
#define K_ALT_7                 382   /*   Alt-7                         */
#define K_ALT_8                 383   /*   Alt-8                         */
#define K_ALT_9                 384   /*   Alt-9                         */
#define K_ALT_0                 385   /*   Alt-0                         */
#define K_ALT_MINUS             386
#define K_ALT_EQUALS            387   /* * Alt-Equals                    */
#define K_ALT_OSB               282
#define K_ALT_CSB               283
#define K_ALT_BACKSLASH         299
#define K_ALT_SC                295
#define K_ALT_QUOTE             296
#define K_ALT_COMMA             307
#define K_ALT_PERIOD            308
#define K_ALT_SLASH             309   /*   Alt-Slash (fyi Ctrl-? doesn't
                                           work - maybe just under xp?)  */

/* Function keys */

#define K_F1                    28    /*   F1, Ctrl-Backslash            */
#define K_F2                    -1    /*   F2                            */
#define K_F3                    -2    /*   F3                            */
#define K_F4                    -3    /*   F4                            */
#define K_F5                    -4    /*   F5                            */
#define K_F6                    -5    /*   F6                            */
#define K_F7                    -6    /*   F7                            */
#define K_F8                    -7    /*   F8                            */
#define K_F9                    -8    /*   F9                            */
#define K_F10                   -9    /*   F10                           */
#define K_F11                   -40   /* * F11                           */
#define K_F12                   -41   /* * F12                           */


/* CONSTANTES MATEMATICAS */
#define M_SQRT2EPI     4.13273135412249293846 /* raiz cuadrada de 2*E*PI */
#define M_SQRT2PI      2.50662827463100050241 /* raiz de 2PI */
#define M_SQRT2        1.41421356237309504880 // 16887 24209 69807 85696
#define M_SQRT3        1.73205080756887729352 // 74463 41505 87236 69428
#define M_SQRT5        2.23606797749978969640 // 91736 68731 27623 54406
#define M_SQRTE        1.64872127070012814684 /* raiz cuadrada de e*/
#define M_SQRPI        9.86960440108935861883 /* pi al cuadrado */
#define M_SQRE         7.38905609893065022723 /* E al cuadrado */
#define M_E^PI         2.66514414269022518865 /* e elevado a PI*/
#define M_PI^E         22.45915771836104547342 /* PI elevado a E */
#define M_PHI          1.61803398874989484820 // 45868 34365 63811 77203
#define M_1_E          0.36787944117144232159 /* inverso de E */
#define M_E            2.7182818284590452354  /* e */
#define M_LOG2E        1.4426950408889634074  /* log_2 e */
#define M_LOG10E       0.43429448190325182765 /* log_10 e */
#define M_LN2          0.69314718055994530942 /* log_e 2 */
#define M_LN10         2.30258509299404568402 /* log_e 10 */
#define M_PI_2         1.57079632679489661923 /* pi/2 */
#define M_PI_4         0.78539816339744830962 /* pi/4 */
#define M_1_PI         0.31830988618379067154 /* 1/pi */
#define M_1_2PI        0.15915494309189533576 /* 1/2PI */
#define M_2_PI         0.63661977236758134308 /* 2/pi */
#define M_PI           3.14159265358979323846 // 26433 83279 50288 41971
#define M_TAU          6.283185307            /* TAU = 2*PI*/
#define M_2_SQRTPI     1.12837916709551257390 /* 2/sqrt(pi) */
#define M_SQRT1_2      0.70710678118654752440 /* 1/sqrt(2) */
#define M_NAN          {90}arcsin
#define M_INF          {1}divby(0)

