#define _Wave _C(CDSP2_Wave, _, _T1)
#define _List_Int CSVP_List_Int
#define _List_Sinusoid _C(CSVP_List_Sinusoid, _, _T1)
#define _STFTIterlyzer _C(CSVP_STFTIterlyzer, _, _T1)
#define _SinusoidalBase _C(CSVP_SinusoidalBase, _, _T1)

RClass(_RTClassName)
{
    RInherit(_SinusoidalBase);
    
    //Public
    _List_Int      PulseList;
    _List_Sinusoid SinuList;
};

RTMethod(void, CSVP_SinusoidIterlyzer, CtorSize, int Size);
RTMethod(void, CSVP_SinusoidIterlyzer, Resize, int Size);
RTMethod(void, CSVP_SinusoidIterlyzer, From, _RTClassName* Sorc);
RTMethod(void, CSVP_SinusoidIterlyzer, Clear);

RTMethod(void, CSVP_SinusoidIterlyzer, SetWave, void* Sorc);
RTMethod(void, CSVP_SinusoidIterlyzer, SetHopSize, int HopSize);
RTMethod(void, CSVP_SinusoidIterlyzer, SetPosition, int Position);
RTMethod(int , CSVP_SinusoidIterlyzer, GetPosition);
RTMethod(void, CSVP_SinusoidIterlyzer, SetRefFreq, _T1 RefF0);

RTMethod(int , CSVP_SinusoidIterlyzer, PreAnalysisTo, int Position);

RTMethod(int , CSVP_SinusoidIterlyzer, IterNextTo, int Position);
RTMethod(int , CSVP_SinusoidIterlyzer, PrevTo, int Position);

#undef  _Wave
#undef  _List_Int
#undef  _List_Sinusoid
#undef  _STFTIterlyzer
#undef  _SinusoidalBase

