#define _Sinusoid _C(CSVP_Sinusoid, _, _T1)
#define _DataFrame _C(CDSP2_DataFrame, _, _T1)
#define _Spectrum _C(CDSP2_Spectrum, _, _T1)

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

RTMethod(void, CSVP_HNMFrame, FromSpectrum, _Spectrum* Sorc, _T1 F0,
    int SinuNum);
RTMethod(void, CSVP_HNMFrame, FromSpectrumWithPhase, _DataFrame* Dest,
    _Spectrum* Sorc, _T1 F0, int SinuNum);

#undef  _Sinusoid
#undef  _DataFrame
#undef  _Spectrum

