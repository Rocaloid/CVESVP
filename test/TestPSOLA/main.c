#include "PSOLA.h"
#include "Misc/Lists.h"

#define Wave CDSP2_Wave_Float
#define InfWave CDSP2_InfWave_Float
#define IWave CDSP2_IWave_Float
#define PSOLAIterlyzer CSVP_PSOLAIterlyzer_Float
#define PSOLAItersizer CSVP_PSOLAItersizer_Float
#define List_DataFrame CSVP_List_DataFrame_Float
#define List_Int CSVP_List_Int
#define FWindow_T RFNL_FWindow_Gnrc_Float
#define FWindow CDSP2_FWindow_Float

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
    
    RCall(Wave, Resize)(& OutWave, 1000000);
    RCall(Wave, SetWindow)(& InWave, HannWind, 2048);
    RCall(Wave, SetWindow)(& OutWave, HannWind, 2048);
    
    RNew(PSOLAIterlyzer, & PAna);
    String_SetChars(& Path, "/tmp/a2.wav");
    
    
    RCall(Wave, FromFile)(& InWave, & Path);
    RCall(PSOLAIterlyzer, SetWave)(& PAna, & InWave);
    RCall(PSOLAIterlyzer, SetPosition)(& PAna, 15500);
    RCall(PSOLAIterlyzer, PreAnalysisTo)(& PAna, 45000);
    
    RCall(PSOLAIterlyzer, IterNextTo)(& PAna, 50000);
    RCall(PSOLAIterlyzer, PrevTo)(& PAna, 2000);
    RCall(PSOLAIterlyzer, IterNextTo)(& PAna, 45000);
    
    /*
    int i;
    for(i = 0; i <= PAna.PulseList.Frames_Index; i ++)
    {
        int p = RCall(PSOLAIterlyzer, Fetch)(& PAna, i);
        printf("%f %f\n", (float)p / InWave.SampleRate
                        , (float)p / InWave.SampleRate);
    }*/
    
    List_DataFrame PSOLAFrame;
    RCall(List_DataFrame, Ctor)(& PSOLAFrame);
    RCall(List_DataFrame, FromWave)(& PSOLAFrame, & InWave, & PAna.PulseList);
    
    PSOLAItersizer PSyn;
    RCall(PSOLAItersizer, Ctor)(& PSyn);
    RCall(List_DataFrame, From)(& PSyn.DataList, & PSOLAFrame);
    RCall(List_Int, From)(& PSyn.PulseList, & PAna.PulseList);
    
    int i;
    for(i = 0; i <= PSyn.PulseList.Frames_Index; i ++)
    {
        PSyn.PulseList.Frames[i] /= 2;
    }
    
    FWindow_T DyWin;
    RCall(FWindow_T, Ctor)(& DyWin);
    RCall(FWindow, SetPara)(& DyWin, 30, 3000, 20);
    RCall(FWindow, SetFunc)(& DyWin, 
        RFNL_Hanning_Size_Gnrc_Float, RFNL_Hanning_Valu_Gnrc_Float);
    RCall(FWindow, Initialize)(& DyWin);
    
    OutWave.SampleRate = InWave.SampleRate;
    RCall(PSOLAItersizer, SetWave)(& PSyn, & OutWave);
    RCall(PSOLAItersizer, SetWindow)(& PSyn, & DyWin);
    RCall(PSOLAItersizer, SetPosition)(& PSyn, 0);
    
    RCall(PSOLAItersizer, IterNextTo)(& PSyn, 100000);
    
    String_SetChars(& Path, "/tmp/out.wav");
    RCall(Wave, ToFile)(& OutWave, & Path);
    
    RFree(HannWind);
    RDelete(& InWave, & OutWave, & Path, & PAna, & PSyn, & PSOLAFrame, & DyWin);
    return 0;
}

