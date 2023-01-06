
#proto ___get__input__generic___(__MSG__,__TIPO__)
#proto ___check_error_color_input___(__SW__)
#proto ___check_valid_input___(__BUFF__,__TCOMP__,__SW__,__TYPE__)
#define ReadString(__MSG__)   ____get__input__generic___(__MSG__,0)
#define ReadNumber(__MSG__)   ____get__input__generic___(__MSG__,1)
#define ReadMoney(__MSG__)   ____get__input__generic___(__MSG__,1),\
                            __VTMP_02919832=0,xtonum,mov(__VTMP_02919832),\
                            {2,__VTMP_02919832},money,
#define ReadEmail(__MSG__)   ____get__input__generic___(__MSG__,2)
#define ReadIp(__MSG__)   ____get__input__generic___(__MSG__,3)
#define ReadDate(__MSG__)   ____get__input__generic___(__MSG__,4)
#define ReadTime(__MSG__)   ____get__input__generic___(__MSG__,5)
#define ReadUrl(__MSG__)   ____get__input__generic___(__MSG__,6)
//#define checkerrorcolorinput(__X__)   ____check_error_color_input___(__X__)
//#define checkvalidinput(__BUFF__,__TCOMP__,__SW__,__TYPE__)   ____check_valid_input___(__BUFF__,__TCOMP__,__SW__,__TYPE__)

