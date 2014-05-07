RClass(_RTClassName)
{
    RInherit(RObject);

    int HopSize;
    int FrameSize;
    int FrameNum;
    
    Array_Define(_C(CDSP2_Spectrum, _, _T1), Frames);
};

RTMethod(void, CSVP_STFTChain, CtorSize, int Num, int FrameSize);
RTMethod(void, CSVP_STFTChain, Resize, int Num, int FrameSize);

RTMethod(void, CSVP_STFTChain, FromWaveW, void* Sorc, int Start, int Length);
RTMethod(void, CSVP_STFTChain, WFromWave, void* Sorc, _T1* Window, int Start,
    int Length);

RTMethod(void, CSVP_STFTChain, ToWaveW, void* Dest, int Start, int Length);
RTMethod(void, CSVP_STFTChain, WToWave, void* Dest, _T1* Window, int Start,
    int Length);

RTFunc(_T1, CSVP_WinFactorFromWindow, _T1* Sorc, int HopSize, int Length);

