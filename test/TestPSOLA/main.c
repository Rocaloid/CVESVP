#include "PSOLA.h"
#include "Misc/Lists.h"
#include "EndPoint.h"

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
    float* HannWind = RAlloc_Float(2048);
    
    RNew(Wave, & InWave, & OutWave);
    RNew(String, & Path);
    CDSP2_GenHanning_Float(HannWind, 2048);
    
    RCall(Wave, Resize)(& OutWave, 100000);
    RCall(Wave, SetWindow)(& InWave, HannWind, 2048);
    RCall(Wave, SetWindow)(& OutWave, HannWind, 2048);
    /*
    char* Paths[23] = 
        {
            
            "/tmp/t/ta1.wsp", 
            "/tmp/t/te-0.wsp", 
            "/tmp/t/te-1.wsp", 
            "/tmp/t/te0.wsp", 
            "/tmp/t/te1.wsp", 
            "/tmp/t/ti1.wsp", 
            "/tmp/t/to-0.wsp",
            "/tmp/t/to-1.wsp", 
            "/tmp/t/to0.wsp", 
            "/tmp/t/tu1.wsp",
            
            "/tmp/ch/ch_r0.wsp", 
            "/tmp/ch/cha0.wsp", 
            "/tmp/ch/che-0.wsp", 
            "/tmp/ch/che0.wsp", 
            "/tmp/ch/che1.wsp",
            "/tmp/ch/cho-0.wsp", 
            "/tmp/ch/cho0.wsp",
            
            "/tmp/p/pa0.wsp",
            "/tmp/p/pe-0.wsp",
            "/tmp/p/pe0.wsp",
            "/tmp/p/pi0.wsp",
            "/tmp/p/po-0.wsp",
            "/tmp/p/po0.wsp"
        };
    
    int VOTs[23] = {10022, 11878, 12167, 12745, 11356,
                    13957, 12653, 11141, 13459, 14024,
                    14473, 13518, 13528, 15481, 16585, 14130, 15735, 
                    13893, 13019, 13662, 12861, 11492, 12261};
    
    int i;
    int a = 0;
    int m = 0;
    for(i = 0; i < 23; i ++)
    {
        String_SetChars(& Path, Paths[i]);
        RCall(Wave, FromFile)(& InWave, & Path);
        int VOT = CSVP_VOTFromWave_Float(& InWave, 50, 20000);
        int e = abs(VOT - VOTs[i]);
        a += e;
        if(e > m) m = e;
        printf("%s: %d %d %d\n", Paths[i], VOT - VOTs[i], VOT,
            CSVP_OnsetFromWave_Float(& InWave, 0.0005, 50, 20000));
    }
    printf("avg: %f, max: %d\n", (float)a / 23.0, m);
    */
    
    #ifdef __WIN32__
    String_SetChars(& Path, "C:\\xxx.wav");
    #else
    String_SetChars(& Path, "/tmp/t15/zhuang.wav");
    #endif
    RCall(Wave, FromFile)(& InWave, & Path);
    
    int VOT = CSVP_VOTFromWave_Float(& InWave, 0, InWave.Size / 2);
    int Onset = CSVP_OnsetFromWave_Float(& InWave, 0.0005, 0, InWave.Size);
    
    PSOLAIterlyzer PAna;
    RNew(PSOLAIterlyzer, & PAna);
    RCall(PSOLAIterlyzer, SetWave)(& PAna, & InWave);
    RCall(PSOLAIterlyzer, SetPosition)(& PAna, VOT + 2000);
    RCall(PSOLAIterlyzer, SetBound)(& PAna, VOT);
    if(! RCall(PSOLAIterlyzer, PreAnalysisTo)(& PAna, VOT + 6000))
    {
        printf("Preanalysis failed.\n");
        return 1;
    }
    
    RCall(PSOLAIterlyzer, IterNextTo)(& PAna, InWave.Size);
    
    if(! RCall(PSOLAIterlyzer, PrevTo)(& PAna, Onset))
    {
        printf("Backward analysis failed.\n");
        //return 1;
    }
    
    
    int i;
    
    for(i = 0; i <= PAna.PulseList.Frames_Index; i ++)
    {
        int p = RCall(PSOLAIterlyzer, Fetch)(& PAna, i);
        printf("%f %f\n", (float)p / InWave.SampleRate
                        , (float)p / InWave.SampleRate);
    }
    
    
    List_DataFrame PSOLAFrame;
    RCall(List_DataFrame, Ctor)(& PSOLAFrame);
    RCall(List_DataFrame, FromWave)(& PSOLAFrame, & InWave, & PAna.PulseList);
    
    PSOLAItersizer PSyn;
    RCall(PSOLAItersizer, Ctor)(& PSyn);
    RCall(List_DataFrame, From)(& PSyn.DataList, & PSOLAFrame);
    RCall(List_Int, From)(& PSyn.PulseList, & PAna.PulseList);
    
    for(i = 1; i <= PSyn.PulseList.Frames_Index; i ++)
    {
        PSyn.PulseList.Frames[i] = PSyn.PulseList.Frames[i - 1] + 
            (PAna.PulseList.Frames[i] - PAna.PulseList.Frames[i - 1]) * 3;
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
    RCall(PSOLAItersizer, RepositionFrom)(& PSyn, 0);
    
    RCall(PSOLAItersizer, IterNextTo)(& PSyn, InWave.Size);
    #ifdef __WIN32__
    String_SetChars(& Path, "C:\\out.wav");
    #else
    String_SetChars(& Path, "/tmp/out.wav");
    #endif
    RCall(Wave, ToFile)(& OutWave, & Path);
    
    RFree(HannWind);
    //RDelete(& InWave, & OutWave, & Path);
    RDelete(& InWave, & OutWave, & Path, & PAna, & PSyn, & PSOLAFrame, & DyWin);
    return 0;
}

