#define _STFTChain _C(CSVP_STFTChain, _, _T1)
#define _Spectrum _C(CDSP2_Spectrum, _, _T1)

RClass(_RTClassName)
{
    RInherit(RObject);
    
    void* Wave;
    _STFTChain Chain;
    
    int LastPosition;
};

RTMethod(void, CSVP_STFTIterlyzer, CtorSize, int FrameSize);
RTMethod(void, CSVP_STFTIterlyzer, Resize, int FrameSize);

RTMethod(void, CSVP_STFTIterlyzer, SetWave, void* Sorc);
RTMethod(void, CSVP_STFTIterlyzer, SetPosition, int Position);
RTMethod(void, CSVP_STFTIterlyzer, SetHopSize, int HopSize);
RTMethod(int , CSVP_STFTIterlyzer, GetPosition);
RTMethod(int , CSVP_STFTIterlyzer, GetHopSize);

RTMethod(void, CSVP_STFTIterlyzer, IterNextTo, int Position);

RTMethod(_Spectrum, CSVP_STFTIterlyzer, Extract, int Index);

#undef  _STFTChain
#undef  _Spectrum

