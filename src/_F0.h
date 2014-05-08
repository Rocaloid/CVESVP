#define _Spectrum _C(CDSP2_Spectrum, _, _T1)

RTFunc(int, CSVP_F0FromSpectrumB, _Spectrum* Sorc, int MinFreq, int MaxFreq);
RTFunc(_T1, CSVP_F0FromSpectrum, _Spectrum* Sorc, int MinFreq, int MaxFreq);

RTFunc(_T1, CSVP_F0FromSuccSpectrumAndBin, _Spectrum* Sorc1, _Spectrum* Sorc2,
    int HopSize, int Bin);

RTFunc(_T1, CSVP_F0FromWave, void* Sorc, int Position, int WinSize,
    int MinFreq, int MaxFreq);

#undef  _Spectrum

