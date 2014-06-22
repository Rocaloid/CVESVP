#define _List_Int CSVP_List_Int

RClass(_RTClassName)
{
    RInherit(RObject);
    
    //Public
    _List_Int PulseList;
    Array_Define(_T1, F0List);
    
    //Private
    void* Wave;
    int HopSize;
};

#undef  _List_Int

