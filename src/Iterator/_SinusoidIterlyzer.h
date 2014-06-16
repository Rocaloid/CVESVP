#define _Wave _C(CDSP2_Wave, _, _T1)
#define _List_Int CSVP_List_Int
#define _List_Sinusoid _C(CSVP_List_Sinusoid, _, _T1)
#define _STFTIterlyzer _C(CSVP_STFTIterlyzer, _, _T1)
#define _SinusoidalBase _C(CSVP_SinusoidalBase, _, _T1)

RClass(_RTClassName)
{
    RInherit(_SinusoidalBase);
    
    //Public
    _List_Sinusoid SinusoidList;
};

#undef  _Wave
#undef  _List_Int
#undef  _List_Sinusoid
#undef  _STFTIterlyzer
#undef  _SinusoidalBase

