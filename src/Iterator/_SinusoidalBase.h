#define _Wave _C(CDSP2_Wave, _, _T1)
#define _List_Int CSVP_List_Int
#define _STFTIterlyzer _C(CSVP_STFTIterlyzer, _, _T1)

RClass(_RTClassName)
{
    RInherit(RObject);
    
    //Public
    _List_Int PulseList;
    
    //Private
    _Wave* Wave;
    int LastPosition;
    int InitPosition;
    _T1 RefF0;
    _T1 InitF0;
    
    _STFTIterlyzer* Sublyzer0;
    _STFTIterlyzer* Sublyzer1;
};

#undef  _Wave
#undef  _List_Int
#undef  _STFTIterlyzer

