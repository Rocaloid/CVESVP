#define _List_Spectrum _C(CSVP_List_Spectrum, _, _T1)
#define _Spectrum _C(CDSP2_Spectrum, _, _T1)

RClass(_RTClassName)
{
    RInherit(RObject);
    
    //Public
    int HopSize;
    _List_Spectrum SpecList;
    CSVP_PulseList PulseList;
    
    //Private
    void* Wave;
    int LastPosition;
};

RTMethod(void, CSVP_STFTIterlyzer, CtorSize, int FrameSize);
RTMethod(void, CSVP_STFTIterlyzer, Resize, int FrameSize);
RTMethod(void, CSVP_STFTIterlyzer, From, _RTClassName* Sorc);

RTMethod(void, CSVP_STFTIterlyzer, SetWave, void* Sorc);
RTMethod(void, CSVP_STFTIterlyzer, SetPosition, int Position);
RTMethod(void, CSVP_STFTIterlyzer, SetHopSize, int HopSize);
RTMethod(int , CSVP_STFTIterlyzer, GetPosition);
RTMethod(int , CSVP_STFTIterlyzer, GetHopSize);
RTMethod(int , CSVP_STFTIterlyzer, GetFrameSize);

RTMethod(void, CSVP_STFTIterlyzer, IterNextTo, int Position);
RTMethod(void, CSVP_STFTIterlyzer, IterPrevTo, int Position);

RTMethod(int , CSVP_STFTIterlyzer, Extract, _Spectrum* Dest, int Index);
RTMethod(int , CSVP_STFTIterlyzer, Fetch, _Spectrum* Dest, int Index);

#undef  _List_Spectrum
#undef  _Spectrum

