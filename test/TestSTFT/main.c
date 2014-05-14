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
    
    //-----
    CSVP_STFTIterlyzer_Float DyAna;
    CSVP_STFTIterlyzer_Float_CtorSize(& DyAna, 2048);
    CSVP_STFTIterlyzer_Float_SetHopSize(& DyAna, 256);
    CSVP_STFTIterlyzer_Float_SetWave(& DyAna, & MyWave);
    CSVP_STFTIterlyzer_Float_SetPosition(& DyAna, 100000);
    
    CSVP_STFTIterlyzer_Float_IterNextTo(& DyAna, 150000);
    CSVP_STFTIterlyzer_Float_SetPosition(& DyAna, 100000);
    CSVP_STFTIterlyzer_Float_IterPrevTo(& DyAna, 50000);
    
    //int i;
    //for(i = 0; i < 1024; i ++)
    //    printf("%f\n", log(DyAna.SpecList.Frames[500].Magn[i]));
    int i;
    for(i = 0; i <= DyAna.PulseList.Pulses_Index; i ++)
            printf("%d\n", DyAna.PulseList.Pulses[i]);
    
    CSVP_STFTIterlyzer_Float_Dtor(& DyAna);
    //-----
    
    String_SetChars(& Path, "/tmp/test3.wav");
    CDSP2_Wave_Float_ToFile(& NewWave, & Path);
    
    RDelete(& MyWave, & NewWave, & Path);
    RFree(wind);
    RFree(wind2);
    return 0;
}

