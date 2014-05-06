#define _HNMFrame _C(CSVP_HNMFrame, _, _T1)

RClass(_RTClassName)
{
    RInherit(RObject);
    
    int HopSize;
    
    Array_Define(_HNMFrame, Frames);
};

RTMethod(void, CSVP_HNMChain, CtorSize, int Num, int FrameSize);
RTMethod(void, CSVP_HNMChain, Resize, int Num, int FrameSize);

RTMethod(void, CSVP_HNMChain, FromWave, void* Sorc, int Start, int Length);
RTMethod(void, CSVP_HNMChain, ToWave, void* Dest, int Start, int Length);

#undef  _HNMFrame

