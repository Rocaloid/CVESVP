#define _InfWave _C(CDSP2_InfWave, _, _T1)
#define _List_Int CSVP_List_Int
#define _STFTIterlyzer _C(CSVP_STFTIterlyzer, _, _T1)
#define _STFTItersizer _C(CSVP_STFTItersizer, _, _T1)

RClass(_RTClassName)
{
    RInherit(RObject);
    
    //Public
    _List_Int PulseList;
    
    //Private
    void* Wave;
    _InfWave* LPFWave;
    _STFTIterlyzer* Sublyzer;
    _STFTItersizer* Subsizer;
    int LastPosition;
    int InitPosition;
    
    int PeakSign;
    int RefPeriod;
    _T1 LPF;
};

RTMethod(void, CSVP_PSOLAIterlyzer, CtorSize, int FrameSize);
RTMethod(void, CSVP_PSOLAIterlyzer, Resize, int FrameSize);
RTMethod(void, CSVP_PSOLAIterlyzer, From, _RTClassName* Sorc);

RTMethod(void, CSVP_PSOLAIterlyzer, SetWave, void* Sorc);
RTMethod(void, CSVP_PSOLAIterlyzer, SetPosition, int Position);
RTMethod(int , CSVP_PSOLAIterlyzer, GetPosition);
RTMethod(void, CSVP_PSOLAIterlyzer, SetRefFreq, _T1 Freq);
RTMethod(void, CSVP_PSOLAIterlyzer, SetLPF, _T1 Freq);

RTMethod(void, CSVP_PSOLAIterlyzer, PreAnalysisTo, int Position);

RTMethod(void, CSVP_PSOLAIterlyzer, IterNextTo, int Position);
RTMethod(void, CSVP_PSOLAIterlyzer, PrevTo, int Position);

RTMethod(int , CSVP_PSOLAIterlyzer, Extract, int Index);
RTMethod(int , CSVP_PSOLAIterlyzer, Fetch, int Index);

#undef  _InfWave
#undef  _List_Int
#undef  _STFTIterlyzer
#undef  _STFTItersizer

