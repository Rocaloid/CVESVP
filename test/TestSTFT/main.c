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
    /*
    CSVP_STFTChain_Float SChain;
    CSVP_STFTChain_Float_CtorSize(& SChain, 300000 / 256 * 1.5, 2048);
    CSVP_STFTChain_Float_SetHopSize(& SChain, 256);
    
    CSVP_STFTChain_Float_WFromWave(& SChain, & MyWave, wind, 0, 300000);
    CSVP_STFTChain_Float_WToWave(& SChain, & NewWave, wind2, 0, 300000);
    */
    
    CSVP_STFTIterlyzer_Float DyAna;
    CSVP_STFTIterlyzer_Float_CtorSize(& DyAna, 2048);
    CSVP_STFTIterlyzer_Float_SetWave(& DyAna, & MyWave);
    CSVP_STFTIterlyzer_Float_SetHopSize(& DyAna, 256);
    CSVP_STFTIterlyzer_Float_SetPosition(& DyAna, 200000);
    
    CSVP_STFTIterlyzer_Float_IterNextTo(& DyAna, 230000);
    CDSP2_Spectrum_Float tmp = CSVP_STFTIterlyzer_Float_Extract(& DyAna, 100);
    RDelete(& tmp);
    CSVP_STFTIterlyzer_Float_IterNextTo(& DyAna, 400000);
    
    CSVP_STFTChain_Float_ToWaveW(& DyAna.Chain, & NewWave, 0, 200000);
    
    CSVP_STFTIterlyzer_Float_Dtor(& DyAna);
    
    String_SetChars(& Path, "/tmp/test3.wav");
    
    CDSP2_Wave_Float_ToFile(& NewWave, & Path);
    
    
    //CSVP_STFTChain_Float_Dtor(& SChain);
    RDelete(& MyWave, & NewWave, & Path);
    RFree(wind);
    RFree(wind2);
    return 0;
}

