#include "HNM.h"
#include "F0.h"
#include "EndPoint.h"
#include "Phase.h"
#include "Spectral/Pitch.h"
#include <CVEDSP2.h>
#include <RUtil2.h>
#include <stdlib.h>

#define Sinusoid CSVP_Sinusoid_Float
#define HNMFrame CSVP_HNMFrame_Float
#define HNMContour CSVP_HNMContour_Float
#define DataFrame CDSP2_DataFrame_Float
#define Spectrum CDSP2_Spectrum_Float
#define SinusoidalBase CSVP_SinusoidalBase_Float
#define SinusoidIterlyzer CSVP_SinusoidIterlyzer_Float
#define HNMIterlyzer CSVP_HNMIterlyzer_Float
#define HNMItersizer CSVP_HNMItersizer_Float
#define SinusoidItersizer CSVP_SinusoidItersizer_Float
#define Wave CDSP2_Wave_Float
#define IWave CDSP2_IWave_Float

#define Stretch 1
#define Speed 1.5
#define FFTSIZE 256

int main()
{
    int i, j;
    
    Wave XWave, YWave;
    RCall(Wave, CtorSize)(& XWave, 20);
    RCall(Wave, CtorSize)(& YWave, 44100 * 5);
    Float* Win = RAlloc_Float(2048);
    CDSP2_GenHanning_Float(Win, 2048);
    RCall(Wave, SetWindow)(& XWave, Win, 2048);
    RCall(Wave, SetWindow)(& YWave, Win, 2048);
    
    String Path;
    String_Ctor(& Path);
    String_SetChars(& Path, "/tmp/yao.wav");
    RCall(Wave, FromFile)(& XWave, & Path);
    RCall(Wave, Resize)(& YWave, XWave.Size * Stretch + 5000);
    
    int VOT = CSVP_VOTFromWave_Float(& XWave, 0, XWave.Size - 5000);
    printf("VOT: %d\n", VOT);
    
    CSVP_F0Iterlyzer_Float F0Iter;
    CSVP_F0Iterlyzer_Float_Ctor(& F0Iter);
    F0Iter.Option.Adlib = 1;
    F0Iter.Option.LFreq = 50;
    F0Iter.Option.HFreq = 700;
    F0Iter.Option.Method = CSVP_F0_YIN;
    
    CSVP_F0Iterlyzer_Float_SetHopSize(& F0Iter, 256);
    CSVP_F0Iterlyzer_Float_SetWave(& F0Iter, & XWave);
    CSVP_F0Iterlyzer_Float_SetPosition(& F0Iter, VOT + 2000);
    CSVP_F0Iterlyzer_Float_PreAnalysisTo(& F0Iter, VOT + 10000);
    
    CSVP_F0Iterlyzer_Float_IterNextTo(& F0Iter, XWave.Size - 5000);
    CSVP_F0Iterlyzer_Float_PrevTo(& F0Iter, 0);
    
    CSVP_F0PostProcess_Float(& F0Iter.F0List, 4000, 0.15, 100, 700);
    printf("Got F0.\n");
    
    HNMIterlyzer HNMIter;
    RCall(HNMIterlyzer, CtorSize)(& HNMIter, 2048);
    HNMIter.GenPhase = 1;
    
    RCall(HNMIterlyzer, SetHopSize)(& HNMIter, FFTSIZE);
    RCall(HNMIterlyzer, SetWave)(& HNMIter, & XWave);
    RCall(HNMIterlyzer, SetPosition)(& HNMIter, VOT + 1000);
    RCall(HNMIterlyzer, SetUpperFreq)(& HNMIter, 10000);
    RCall(HNMIterlyzer, SetPitch)(& HNMIter, & F0Iter.F0List);
    
    RCall(HNMIterlyzer, PrevTo)(& HNMIter, VOT);
    RCall(HNMIterlyzer, IterNextTo)(& HNMIter, XWave.Size);
    
    HNMItersizer HNMSizer;
    RCall(HNMItersizer, CtorSize)(& HNMSizer, 2048);
    
    HNMContour TempCont;
    HNMFrame   TempHNM;
    RCall(HNMContour, Ctor)(& TempCont);
    RCall(HNMFrame, Ctor)(& TempHNM);
    
    CSVP_PitchModel PM;
    CSVP_PitchModel_Ctor(& PM);
    
    int Offset = HNMIter.PulseList.Frames[0];
    int Last;
    for(i = 0; i <= HNMIter.PulseList.Frames_Index; i ++)
    {
        HNMFrame* OrigHNM = & HNMIter.HNMList.Frames[i];
        
        float F0 = OrigHNM -> Hmnc.Freq[0] * 1.5;
        
        CSVP_PitchConvertHNMFrame_Float(& TempCont, OrigHNM, & PM, F0, 12000,
            XWave.SampleRate);
        RCall(HNMFrame, From)(& TempHNM, OrigHNM);
        RCall(HNMFrame, FromContour)(& TempHNM, & TempCont, F0, 12000);
        
        if(i % 10 == 0)
        {
            float PhaseAdj = CSVP_PitchModel_GetPhseCoh(& PM, F0);
            CSVP_PhaseSyncH_Float(& HNMIter.PhseList.Frames[i], 0);
            CSVP_PhaseContract_Float(& HNMIter.PhseList.Frames[i], PhaseAdj);
            RCall(HNMItersizer, AddPhase)(& HNMSizer,
                & HNMIter.PhseList.Frames[i], Offset);
        }
        
        // Uncomment to plot the spectral env.
        /*
        if(Offset > 10000)
        {
            for(j = 0; j < 1024; j ++)
                printf("%f\n", TempCont.Hmnc[j]);
            exit(0);
        }*/
        
        for(j = 0; j < Stretch; j ++)
        {
            RCall(HNMItersizer, Add)(& HNMSizer, & TempHNM, Offset);
            Offset += FFTSIZE;
        }
    }
    Last = HNMSizer.PulseList.Frames[i * Stretch - 1];
    RDelete(& TempCont, & TempHNM, & PM);
        
    RCall(HNMItersizer, SetHopSize)(& HNMSizer, FFTSIZE);
    RCall(HNMItersizer, SetWave)(& HNMSizer, & YWave);
    
    RCall(HNMItersizer, SetPosition)(& HNMSizer,
        HNMSizer.SubsizerS -> PhseMatch.PulseList.X[5]);
    RCall(HNMItersizer, SetInitPhase)(& HNMSizer,
        & HNMSizer.SubsizerS -> PhseMatch.PhseList.Frames[5]);
    printf("%f\n", HNMSizer.SubsizerS -> PhseMatch.PulseList.X[5]);
    
    HNMSizer.Option.PhaseControl = 1;
        
    RCall(HNMItersizer, PrevTo    )(& HNMSizer, 0);
    RCall(HNMItersizer, IterNextTo)(& HNMSizer, Last - 8000);
    RCall(HNMItersizer, IterNextTo)(& HNMSizer, Last - 1000);
    RCall(HNMItersizer, IterNextTo)(& HNMSizer, Last);
    
    String_SetChars(& Path, "/tmp/out.wav");
    RCall(Wave, ToFile)(& YWave, & Path);
        
    
    RFree(Win);
    RDelete(& Path);
    RDelete(& XWave, & YWave, & HNMIter, & HNMSizer, & F0Iter);
    return 0;
}

