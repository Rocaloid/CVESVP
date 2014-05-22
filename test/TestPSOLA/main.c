#include "PSOLA.h"

#define Wave CDSP2_Wave_Float
#define InfWave CDSP2_InfWave_Float
#define IWave CDSP2_IWave_Float
#define PSOLAIterlyzer CSVP_PSOLAIterlyzer_Float

int main()
{
    CDSP2_SetArch(CDSP2_Arch_Gnrc);
    
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
    String_SetChars(& Path, "/tmp/test.wav");
    
    RCall(Wave, FromFile)(& InWave, & Path);
    RCall(PSOLAIterlyzer, SetWave)(& PAna, & InWave);
    RCall(PSOLAIterlyzer, SetPosition)(& PAna, 20000);
    RCall(PSOLAIterlyzer, PreAnalysisTo)(& PAna, 30000);
    
    RFree(HannWind);
    RDelete(& InWave, & OutWave, & Path, & PAna);
    return 0;
}

