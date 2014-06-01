#include "PSOLA.h"

#define Wave CDSP2_Wave_Float
#define InfWave CDSP2_InfWave_Float
#define IWave CDSP2_IWave_Float
#define PSOLAIterlyzer CSVP_PSOLAIterlyzer_Float

int main()
{
    CDSP2_SetArch(CDSP2_Arch_Gnrc);
    CDSP2_SetDebugOn(CDSP2_Debug_Check);
    
    String Path;
    Wave InWave, OutWave;
    PSOLAIterlyzer PAna;
    float* HannWind = RAlloc_Float(2048);
    
    RNew(Wave, & InWave, & OutWave);
    RNew(String, & Path);
    CDSP2_GenHanning_Float(HannWind, 2048);
    RCall(Wave, SetWindow)(& InWave, HannWind, 2048);
    RCall(Wave, SetWindow)(& OutWave, HannWind, 2048);
    
    RNew(PSOLAIterlyzer, & PAna);
    String_SetChars(& Path, "/tmp/a.wav");
    
    
    RCall(Wave, FromFile)(& InWave, & Path);
    RCall(PSOLAIterlyzer, SetWave)(& PAna, & InWave);
    RCall(PSOLAIterlyzer, SetPosition)(& PAna, 43000);
    RCall(PSOLAIterlyzer, PreAnalysisTo)(& PAna, 45000);
    
    RCall(PSOLAIterlyzer, IterNextTo)(& PAna, 274000);
    RCall(PSOLAIterlyzer, PrevTo)(& PAna, 20000);
    RCall(PSOLAIterlyzer, IterNextTo)(& PAna, 517000);
    
    int i;
    for(i = 0; i <= PAna.PulseList.Frames_Index; i ++)
    {
        int p = RCall(PSOLAIterlyzer, Fetch)(& PAna, i);
        printf("%f %f\n", (float)p / InWave.SampleRate
                        , (float)p / InWave.SampleRate);
    }
    
    RFree(HannWind);
    RDelete(& InWave, & OutWave, & Path, & PAna);
    return 0;
}

