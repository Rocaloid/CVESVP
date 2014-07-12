#include "HNM.h"
#include "F0.h"
#include "EndPoint.h"
#include "Phase.h"
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

#define Stretch 5
#define FFTSIZE 128

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
    String_SetChars(& Path, "/tmp/t/ta0.wsp");
    RCall(Wave, FromFile)(& XWave, & Path);
    RCall(Wave, Resize)(& YWave, XWave.Size * Stretch);
    
    int VOT = CSVP_VOTFromWave_Float(& XWave, 0, XWave.Size / 2);
    //printf("VOT: %d\n", VOT);
    
    CSVP_F0Iterlyzer_Float F0Iter;
    CSVP_F0Iterlyzer_Float_Ctor(& F0Iter);
    F0Iter.Option.Adlib = 1;
    F0Iter.Option.LFreq = 50;
    F0Iter.Option.HFreq = 400;
    
    CSVP_F0Iterlyzer_Float_SetHopSize(& F0Iter, 256);
    CSVP_F0Iterlyzer_Float_SetWave(& F0Iter, & XWave);
    CSVP_F0Iterlyzer_Float_SetPosition(& F0Iter, VOT + 2000);
    CSVP_F0Iterlyzer_Float_PreAnalysisTo(& F0Iter, VOT + 10000);
    
    CSVP_F0Iterlyzer_Float_IterNextTo(& F0Iter, XWave.Size - 1000);
    CSVP_F0Iterlyzer_Float_PrevTo(& F0Iter, 0);
    
    CSVP_F0PostProcess_Float(& F0Iter.F0List, 4000, 0.15);
    
    HNMIterlyzer HNMIter;
    RCall(HNMIterlyzer, CtorSize)(& HNMIter, 2048);
    HNMIter.GenPhase = 1;
    
    RCall(HNMIterlyzer, SetHopSize)(& HNMIter, FFTSIZE);
    RCall(HNMIterlyzer, SetWave)(& HNMIter, & XWave);
    RCall(HNMIterlyzer, SetPosition)(& HNMIter, VOT + 1000);
    RCall(HNMIterlyzer, SetUpperFreq)(& HNMIter, 8000);
    RCall(HNMIterlyzer, SetPitch)(& HNMIter, & F0Iter.F0List);
    
    RCall(HNMIterlyzer, PrevTo)(& HNMIter, VOT);
    RCall(HNMIterlyzer, IterNextTo)(& HNMIter, XWave.Size - 510);
    
    HNMItersizer HNMSizer;
    RCall(HNMItersizer, CtorSize)(& HNMSizer, 2048);
    
    int Offset = HNMIter.PulseList.Frames[0];
    int Last;
    for(i = 0; i <= HNMIter.PulseList.Frames_Index; i ++)
    {
        //HNMIter.PulseList.Frames[i] -= Offset;
        for(j = 0; j < Stretch; j ++)
        {
            RCall(HNMItersizer, Add)(& HNMSizer, & HNMIter.HNMList.Frames[i],
                Offset);
            Offset += FFTSIZE;
        }
    }
    Last = HNMSizer.PulseList.Frames[i * Stretch - 1];
    
    int f = 50;
    
    //for(j = 0; j < HNMIter.PhseList.Frames[f].Size; j ++)
    //    HNMIter.PhseList.Frames[f].Data[j] = 2.0 * M_PI;
//            + (float)rand() / RAND_MAX * (float) j;
    
    RCall(HNMItersizer, SetHopSize)(& HNMSizer, FFTSIZE);
    RCall(HNMItersizer, SetWave)(& HNMSizer, & YWave);
    RCall(HNMItersizer, SetPosition)(& HNMSizer, HNMIter.PulseList.Frames[f]);
    
    RCall(HNMItersizer, SetInitPhase)(& HNMSizer,
        & HNMIter.PhseList.Frames[f]);
    RCall(HNMItersizer, AddPhase)(& HNMSizer,
        & HNMIter.PhseList.Frames[f + 5], HNMIter.PulseList.Frames[f + 5]);
    RCall(HNMItersizer, AddPhase)(& HNMSizer,
        & HNMIter.PhseList.Frames[f + 8], HNMIter.PulseList.Frames[f + 8]);
    
    //printf("%d %d\n", Last - 1000, HNMIter.PulseList.Frames[f]);
    
    RCall(HNMItersizer, PrevTo    )(& HNMSizer, 0);
    RCall(HNMItersizer, IterNextTo)(& HNMSizer, Last - 1000);
    
    String_SetChars(& Path, "/tmp/out.wav");
    RCall(Wave, ToFile)(& YWave, & Path);
    
    HNMContour TestCont;
    HNMFrame TestFrame;
    RCall(HNMFrame, Ctor)(& TestFrame);
    RCall(HNMContour, Ctor)(& TestCont);
    RCall(HNMFrame, ToContour)(& HNMIter.HNMList.Frames[i / 2], & TestCont);
    RCall(HNMFrame, FromContour)(& TestFrame, & TestCont, 200, 8000);
    //for(i = 0; i < TestFrame.Hmnc.Size; i ++)
    //    printf("%f, %f\n", TestFrame.Hmnc.Freq[i], TestFrame.Hmnc.Ampl[i]);
    
    DataFrame* P1, *P2;
    DataFrame P;
    RCall(DataFrame, Ctor)(& P);
    P1 = & HNMIter.PhseList.Frames[20];
    P2 = & HNMIter.PhseList.Frames[50];
    CSVP_PhaseSync_Float(P1, HNMIter.HNMList.Frames[20].Hmnc.Freq, 0);
    CSVP_PhaseSync_Float(P2, HNMIter.HNMList.Frames[50].Hmnc.Freq, 0);
    CSVP_PhaseInterp_Float(& P, P1, P2, 0.5);
    for(i = 0; i < 5; i ++)
        printf("%f\n", P.Data[i]);
    
    RFree(Win);
    RDelete(& Path, & TestCont, & TestFrame, & P);
    RDelete(& XWave, & YWave, & HNMIter, & HNMSizer, & F0Iter);
    return 0;
}

