#define _List_Int CSVP_List_Int
#define _STFTIterlyzer _C(CSVP_STFTIterlyzer, _, _T1)

RClass(_RTClassName)
{
    RInherit(RObject);
    
    //Public
    _List_Int PulseList;
    
    //Private
    void* Wave;
    int Size;
    
    int LastPosition;
    int InitPosition;
    _T1 RefF0;
    _T1 InitF0;
    
    _STFTIterlyzer* Sublyzer0;
    _STFTIterlyzer* Sublyzer1;
};

RTMethod(void, CSVP_SinusoidalBase, CtorSize, int Size);
RTMethod(void, CSVP_SinusoidalBase, Resize, int Size);
RTMethod(void, CSVP_SinusoidalBase, From, _RTClassName* Sorc);

RTMethod(void, CSVP_SinusoidalBase, SetWave, void* Sorc);
RTMethod(void, CSVP_SinusoidalBase, SetHopSize, int HopSize);
RTMethod(void, CSVP_SinusoidalBase, SetPosition, int Position);
RTMethod(int , CSVP_SinusoidalBase, GetPosition);
RTMethod(void, CSVP_SinusoidalBase, SetRefFreq, _T1 RefF0);

RTMethod(int , CSVP_SinusoidalBase, PreAnalysisTo, int Position);

#undef  _List_Int
#undef  _STFTIterlyzer

