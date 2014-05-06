#include "F0.h"
#include <CVEDSP2.h>

int main()
{
    CDSP2_SetArch(CDSP2_Arch_Gnrc);
    CDSP2_Wave_Float MyWave;
    CDSP2_Wave_Float_Ctor(& MyWave);
    CDSP2_Spectrum_Float MySpectrum;
    CDSP2_Spectrum_Float_CtorSize(& MySpectrum, 2048);
    
    Double* wind = RAlloc_Double(2048);
    CDSP2_VSet_Double(wind, 1, 2048);
    CDSP2_Hanning_Double(wind, wind, 2048);
    CDSP2_IWave_Double_SetWindow(& MyWave, wind, 2048);
    
    //RNew(CDSP2_Wave_Float, & MyWave);
    String_FromChars(Path, "/tmp/test.wav");
    
    int ret = CDSP2_Wave_Float_FromFile(& MyWave, & Path);
    printf("ret: %d\n", ret);
    MySpectrum.MagnType = CDSP2_LogMagn;
    CDSP2_Spectrum_Float_FromWave(& MySpectrum, & MyWave, 97000);
    
    int i;
    //for(i= 0; i < 300; i ++)
    //    printf("%f\n", MySpectrum.Magn[i]);
    int F0 = CSVP_F0FromSpectrumB_Float(& MySpectrum, 100, 1500, 44100);
    printf("F0: %d\n", F0 * 44100 / 2048);
    
    RDelete(& MyWave, & MySpectrum, & Path);
    RFree(wind);
    return 0;
}

