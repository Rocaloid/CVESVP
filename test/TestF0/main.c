#include "F0.h"
#include "EndPoint.h"
#include <CVEDSP2.h>

int main()
{
    CDSP2_SetArch(CDSP2_Arch_Gnrc);
    
    CDSP2_Wave_Float MyWave;
    CDSP2_Wave_Float_Ctor(& MyWave);
    
    Float* wind = RAlloc_Float(2048);
    CDSP2_GenHanning_Float(wind, 2048);
    CDSP2_Wave_Float_SetWindow(& MyWave, wind, 2048);
    
    String_FromChars(Path, "/tmp/t/ta0.wsp");
    
    CDSP2_Wave_Float_FromFile(& MyWave, & Path);
    
    CSVP_F0Iterlyzer_Float F0Iter;
    CSVP_F0Iterlyzer_Float_Ctor(& F0Iter);
    F0Iter.Option.Adlib = 1;
    F0Iter.Option.LFreq = 50;
    F0Iter.Option.HFreq = 800;
    F0Iter.Option.Threshold = 0.01;
    
    int Onset = CSVP_OnsetFromWave_Float(& MyWave, 0.0005, 0, MyWave.Size);
    int VOT = CSVP_VOTFromWave_Float(& MyWave, Onset, Onset + 10000);
    
    CSVP_F0Iterlyzer_Float_SetHopSize(& F0Iter, 128);
    CSVP_F0Iterlyzer_Float_SetWave(& F0Iter, & MyWave);
    CSVP_F0Iterlyzer_Float_SetPosition(& F0Iter, VOT + 2000);
    CSVP_F0Iterlyzer_Float_PreAnalysisTo(& F0Iter, VOT + 10000);
    
    CSVP_F0Iterlyzer_Float_PrevTo(& F0Iter, 0);
    CSVP_F0Iterlyzer_Float_IterNextTo(& F0Iter, MyWave.Size - 3000);
    CSVP_F0PostProcess_Float(& F0Iter.F0List, 4000, 0.15);
    
    int i;
    for(i = 0; i <= F0Iter.F0List.X_Index; i ++)
        printf("%d, %f\n", (int)F0Iter.F0List.X[i], F0Iter.F0List.Y[i]);
    /*
    for(i = 0; i < MyWave.Size - 3000; i += 100)
        printf("%f\n", PMatch_Float_Float_Query(& F0Iter.F0List, i).Y);
    */
    RDelete(& MyWave, & Path, & F0Iter);
    RFree(wind);
    return 0;
}

