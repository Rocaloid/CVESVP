RClass(_RTClassName)
{
    RInherit(RObject);
    
    int UFreq;
    int SampleRate;
    
    Array_Define(_T1, Sinusoid);
    Array_Define(_T1, Residual);
};

/*
#define _Spectrum _C(CDSP2_Spectrum, _, _T1)

RTMethod(void, CSVP_HNMContour, FromSpectrum, _Spectrum* Sorc, _T1 F0,
    int UFreq, int SampleRate);
RTMethod(void, CSVP_HNMContour, FromWave, void* Sorc, _T1 F0, int UFreq,
    int Center, int Size, int SampleRate);

#undef  _Spectrum
*/

