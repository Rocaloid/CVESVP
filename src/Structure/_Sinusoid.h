RClass(_RTClassName)
{
    RInherit(RObject);

    //Public
    int Size;
    Array_Define(_T1, Freq);
    Array_Define(_T1, Ampl);
};

RTMethod(void, CSVP_Sinusoid, CtorSize, int Size);
RTMethod(void, CSVP_Sinusoid, Resize, int Size);
RTMethod(void, CSVP_Sinusoid, From, _RTClassName* Sorc);

RTMethod(void, CSVP_Sinusoid, ToReal, _T1* Dest, int Size);

