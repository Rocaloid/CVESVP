#define _Spectrum _C(CDSP2_Spectrum, _, _T1)

RTFunc(int, CSVP_F0FromSpectrumB, _Spectrum* Sorc, _T1 MinFreq, _T1 MaxFreq);
RTFunc(_T1, CSVP_F0FromSpectrum, _Spectrum* Sorc, _T1 MinFreq, _T1 MaxFreq);

RTFunc(_T1, CSVP_F0FromSuccSpectrum, _Spectrum* Sorc1, _Spectrum* Sorc2,
    int HopSize, _T1 MinFreq, _T1 MaxFreq);
RTFunc(_T1, CSVP_F0FromSuccSpectrumAndBin, _Spectrum* Sorc1, _Spectrum* Sorc2,
    int HopSize, int Bin);

RTFunc(int, CSVP_F0FromWaveB, void* Sorc, int Position,
    int MinFreq, int MaxFreq);
RTFunc(_T1, CSVP_F0FromWave, void* Sorc, int Position,
    int MinFreq, int MaxFreq);

RTFunc(int, CSVP_MedianF0FromWaveB, void* Sorc, int LPosition, int RPosition, 
    int MinFreq, int MaxFreq);
RTFunc(_T1, CSVP_SecureF0FromWave, void* Sorc, int Center, 
    int LPosition, int RPosition, int MinFreq, int MaxFreq);

#undef  _Spectrum

