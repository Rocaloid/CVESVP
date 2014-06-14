RClass(_RTClassName)
{
    RInherit(RObject);
    
    //Public
    _T1* Data;
    int  Size;
};

RTMethod(void, CSVP_DataFrame, CtorSize, int Size);
RTMethod(void, CSVP_DataFrame, Resize, int Size);
RTMethod(void, CSVP_DataFrame, From, _RTClassName* Sorc);

RTMethod(void, CSVP_DataFrame, Clear);

RTMethod(void, CSVP_DataFrame, FromWave, void* Sorc, int Center, int HalfWidth);

