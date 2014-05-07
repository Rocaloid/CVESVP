#include "STFT.h"
#include <CVEDSP2.h>

int main()
{
    CDSP2_SetArch(CDSP2_Arch_Gnrc);
    
    
    CDSP2_Wave_Float MyWave, NewWave;
    CDSP2_Wave_Float_Ctor(& MyWave);
    CDSP2_Wave_Float_CtorSize(& NewWave, 48000 * 20);
    
    Float* wind = RAlloc_Float(2048);
    Float* wind2 = RAlloc_Float(2048);
    
    CDSP2_GenHanning_Float(wind, 2048);
    CDSP2_GenBlackman_Float(wind2, 2048);
    CDSP2_Wave_Float_SetWindow(& MyWave, wind, 2048);
    CDSP2_Wave_Float_SetWindow(& NewWave, wind, 2048);
    
    String_FromChars(Path, "/tmp/test.wav");
    
    CDSP2_Wave_Float_FromFile(& MyWave, & Path);
    
    CSVP_STFTChain_Float SChain;
    CSVP_STFTChain_Float_CtorSize(& SChain, 300000 / 256 * 1.5, 2048);
    SChain.HopSize = 256;
    
    CSVP_STFTChain_Float_WFromWave(& SChain, & MyWave, wind2, 0, 300000);
    CSVP_STFTChain_Float_ToWaveW(& SChain, & NewWave, 0, 300000);
    
    CSVP_STFTChain_Float_Dtor(& SChain);
    RDelete(& MyWave, & NewWave, & Path);
    RFree(wind);
    RFree(wind2);
    return 0;
}

