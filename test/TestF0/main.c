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
    
    String_FromChars(Path, "/tmp/yiyou.wav");
    
    CDSP2_Wave_Float_FromFile(& MyWave, & Path);
    
    CSVP_F0Iterlyzer_Float F0Iter;
    CSVP_F0Iterlyzer_Float_Ctor(& F0Iter);
    
    int VOT = CSVP_VOTFromWave_Float(& MyWave, 0, MyWave.Size / 2);
    
    printf("%d\n", VOT);
    
    CSVP_F0Iterlyzer_Float_SetHopSize(& F0Iter, 256);
    CSVP_F0Iterlyzer_Float_SetWave(& F0Iter, & MyWave);
    CSVP_F0Iterlyzer_Float_SetPosition(& F0Iter, VOT + 2000);
    CSVP_F0Iterlyzer_Float_PreAnalysisTo(& F0Iter, VOT + 10000);
    CSVP_F0Iterlyzer_Float_IterPrevTo(& F0Iter, 0);
    CSVP_F0Iterlyzer_Float_SetPosition(& F0Iter, VOT + 2000);
    CSVP_F0Iterlyzer_Float_IterNextTo(& F0Iter, MyWave.Size - 3000);
    
    int i;
    for(i = 0; i < 20000; i += 100)
        printf("%f\n", PMatch_Float_Float_Query(& F0Iter.F0List, i).Y);
    /*
    int i;
    float F0 = 0;
    for(i = 0; i < MyWave.Size; i += 500)
    {
        float tmp = CSVP_F0FromWave_Float(& MyWave, i, 100, 1500);
        printf("%f\n", tmp);
        F0 = tmp;
        //printf("%f at %f\n", tmp, (float)i / 48000);
    }
    */
    RDelete(& MyWave, & Path, & F0Iter);
    RFree(wind);
    return 0;
}

