#define _Sinusoid _C(CSVP_Sinusoid, _, _T1)

RClass(_RTClassName)
{
    RInherit(RObject);
    
    //Public
    int Size;
    
    _Sinusoid Hmnc;
    _T1*      Noiz;
};

RTMethod(void, CSVP_HNMFrame, CtorSize, int Size, int HNum);
RTMethod(void, CSVP_HNMFrame, Resize, int Size, int HNum);
RTMethod(void, CSVP_HNMFrame, From, _RTClassName* Sorc);

RTMethod(void, CSVP_HNMFrame, Clear);

#undef  _Sinusoid

