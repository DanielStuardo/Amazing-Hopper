
#proto ___Select___Date___(__F__)
#proto ___Select___Item___(__X__,__R__,__C__,__I__)
#proto ___Select___Day___(__X__,__D__)
#proto ___Select___Red___Item___(__X__,__F__,__C__,__F1__,__C1__)
#synon ____Select___Date___     SelectDate

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

