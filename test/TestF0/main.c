#include "F0.h"
#include <CVEDSP2.h>

int main()
{
    CDSP2_SetArch(CDSP2_Arch_Gnrc);
    CDSP2_Wave_Float MyWave;
    CDSP2_Wave_Float_Ctor(& MyWave);
    CDSP2_Spectrum_Float MySpectrum, MySpectrum2;
    CDSP2_Spectrum_Float_CtorSize(& MySpectrum, 2048);
    CDSP2_Spectrum_Float_CtorSize(& MySpectrum2, 2048);
    
    Float* wind = RAlloc_Float(2048);
    CDSP2_GenHanning_Float(wind, 2048);
    CDSP2_Wave_Float_SetWindow(& MyWave, wind, 2048);
    
    //RNew(CDSP2_Wave_Float, & MyWave);
    String_FromChars(Path, "/tmp/test.wav");
    
    int ret = CDSP2_Wave_Float_FromFile(& MyWave, & Path);
    int i;
    
    //printf("ret: %d\n", ret);
    MySpectrum.MagnType = CDSP2_LogMagn;
    MySpectrum2.MagnType = CDSP2_LogMagn;
    CDSP2_Spectrum_Float_FromWaveW(& MySpectrum, & MyWave, 200000);
    CDSP2_Spectrum_Float_FromWaveW(& MySpectrum2, & MyWave, 200002);
    
    //for(i= 0; i < 300; i ++) printf("%f\n", MySpectrum.Phse[i]);
    int F0 = CSVP_F0FromSpectrumB_Float(& MySpectrum, 100, 1500, 48000);
    int F0_2 = CSVP_F0FromSpectrumB_Float(& MySpectrum2, 100, 1500, 48000);
    printf("F0: %d %f\n", F0, CSVP_F0FromSuccSpectrumAndBin_Float(& MySpectrum, & MySpectrum2, 2, F0, 48000));
    
    RDelete(& MyWave, & MySpectrum, & MySpectrum2, & Path);
    RFree(wind);
    return 0;
}

