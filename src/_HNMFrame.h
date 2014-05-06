RClass(_RTClassName)
{
    RInherit(RObject);
    
    int HasPhase;
    int ResiHopFreq;
    
    Array_Define(_T1, SinuFreq);
    Array_Define(_T1, SinuAmpl);
    Array_Define(_T1, SinuPhse);
    
    Array_Define(_T1, ResiPeak);
};

#define _HNMContour _C(CSVP_HNMContour, _, _T1)
#define _Spectrum _C(CDSP2_Spectrum, _, _T1)

RTMethod(void, CSVP_HNMFrame, FromSpectrumAndF0, _Spectrum* Sorc, _T1 F0,
    int UFreq, int SampleRate);
RTMethod(void, CSVP_HNMFrame, FromWave, void* Sorc, int Center, int Size,
    int UFreq, int SampleRate);
RTMethod(void, CSVP_HNMFrame, FromWaveAndF0, void* Sorc, int Center, int Size, 
    _T1 F0, int UFreq, int SampleRate);

RTMethod(void, CSVP_HNMFrame, ToHNMContour, _HNMContour* Dest, int Size,
    int SampleRate);
RTMethod(void, CSVP_HNMFrame, FromHNMContour, _HNMContour* Sorc, _T1 F0, 
    int SinuNum, int SampleRate);
RTMethod(void, CSVP_HNMFrame, VFromHNMContour, _HNMContour* Sorc, _T1* F0, 
    int SinuNum, int SampleRate);

RTMethod(void, CSVP_HNMFrame, Synth, _T1* Dest, int Size, int SampleRate);

RTFunc(void, CSVP_HNMSinusoidFrmSynth, _T1* Dest, _T1* SorcFreq, _T1* SorcAmpl,
    int SorcNum, int Size, int SampleRate);
RTFunc(void, CSVP_HNMResidualFrmSynth, _T1* Dest, _T1* Sorc, int SorcHopFreq,
    int SorcNum, int Size, int SampleRate);

#undef  _HNMContour
#undef  _Spectrum

