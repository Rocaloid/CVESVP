#define _PMatch _C(PMatch_, _T1, _, _T1)
#define _List_Int CSVP_List_Int

RClass(_RTClassName)
{
    RInherit(RObject);
    
    //Public
    _PMatch F0List;
    CSVP_F0Option Option;
    
    //Private
    void* Wave;
    int HopSize;
    int LastPosition;
    _T1 RefF0;
};

RTMethod(void, CSVP_F0Iterlyzer, From, _RTClassName* Sorc);
RTMethod(void, CSVP_F0Iterlyzer, Clear);

RTMethod(void, CSVP_F0Iterlyzer, SetWave, void* Sorc);
RTMethod(void, CSVP_F0Iterlyzer, SetHopSize, int HopSize);
RTMethod(void, CSVP_F0Iterlyzer, SetPosition, int Position);
RTMethod(int , CSVP_F0Iterlyzer, GetPosition);
RTMethod(void, CSVP_F0Iterlyzer, SetRefFreq, _T1 RefF0);

RTMethod(int , CSVP_F0Iterlyzer, PreAnalysisTo, int Position);

RTMethod(int , CSVP_F0Iterlyzer, IterNextTo, int Position);
RTMethod(int , CSVP_F0Iterlyzer, IterPrevTo, int Position);

#undef  _List_Int
#undef  _PMatch

