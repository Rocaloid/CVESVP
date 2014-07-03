#include "HNM.h"
#include "EndPoint.h"
#include <CVEDSP2.h>
#include <RUtil2.h>
#include <stdlib.h>

#define Sinusoid CSVP_Sinusoid_Float
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
    Sinusoid SinFrame;
    Spectrum SinSpec;
    RCall(Sinusoid, CtorSize)(& SinFrame, 5);
    RCall(Spectrum, CtorSize)(& SinSpec, 2048);
    SinSpec.MagnType = CDSP2_LogMagn;
    
    int i;
    RCall(Sinusoid, Clear)(& SinFrame);
    for(i = 0; i < 5; i ++)
    {
        SinFrame.Freq[i] = 260 * i + 260;
        SinFrame.Ampl[i] = 0.5 - 0.01 * 1;
    }
    
    Wave XWave, YWave;
    RCall(Wave, CtorSize)(& XWave, 20);
    RCall(Wave, CtorSize)(& YWave, 44100 * 5);
    //Float* X = RCall(IWave, GetUnsafePtr)(& XWave);
    Float* Win = RAlloc_Float(2048);
    CDSP2_GenHanning_Float(Win, 2048);
    RCall(Wave, SetWindow)(& XWave, Win, 2048);
    RCall(Wave, SetWindow)(& YWave, Win, 2048);
    
    String Path;
    String_Ctor(& Path);
    String_SetChars(& Path, "/tmp/p/po-0.wsp");
    RCall(Wave, FromFile)(& XWave, & Path);
    RCall(Wave, Resize)(& YWave, XWave.Size * Stretch);
    //RCall(Sinusoid, ToSpectrum)(& SinFrame, & SinSpec);
    //RCall(Sinusoid, ToReal)(& SinFrame, X, 44100 * 5, 44100);
    //CDSP2_VCMul_Float(X, X, 0.05, 44100 * 5);
    /*
    for(i = 0; i < 1025; i ++)
        printf("%.20f\n", X[i]);*/
    //    printf("%.20f\n", SinSpec.Magn[i]);
    
    int VOT = CSVP_VOTFromWave_Float(& XWave, 0, XWave.Size / 2);
    printf("VOT: %d\n", VOT);
    
    HNMIterlyzer HNMIter;
    RCall(HNMIterlyzer, CtorSize)(& HNMIter, 2048);
    HNMIter.GenPhase = 1;
    
    RCall(HNMIterlyzer, SetHopSize)(& HNMIter, FFTSIZE);
    RCall(HNMIterlyzer, SetWave)(& HNMIter, & XWave);
    RCall(HNMIterlyzer, SetPosition)(& HNMIter, VOT + 1000);
    RCall(HNMIterlyzer, PreAnalysisTo)(& HNMIter, VOT + 5000);
    RCall(HNMIterlyzer, SetUpperFreq)(& HNMIter, 10000);
    printf("F0: %f\n", HNMIter._Base.InitF0);
    
    RCall(HNMIterlyzer, PrevTo)(& HNMIter, VOT);
    RCall(HNMIterlyzer, IterNextTo)(& HNMIter, XWave.Size - 510);
    
    HNMItersizer HNMSizer;
    RCall(HNMItersizer, CtorSize)(& HNMSizer, 2048);
        
    int Offset = HNMIter.PulseList.Frames[0];
    int Last;
    int j;
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
    
    int f = i - 10;
    
    for(j = 0; j < HNMIter.PhseList.Frames[f].Size; j ++)
        HNMIter.PhseList.Frames[f].Data[j] = 2.0 * M_PI
            + (float)rand() / RAND_MAX * (float) j;
    
    RCall(HNMItersizer, SetHopSize)(& HNMSizer, FFTSIZE);
    RCall(HNMItersizer, SetWave)(& HNMSizer, & YWave);
    RCall(HNMItersizer, SetPosition)(& HNMSizer, HNMIter.PulseList.Frames[f]);
    
    RCall(HNMItersizer, SetInitPhase)(& HNMSizer,
        & HNMIter.PhseList.Frames[f]);
    
    printf("%d %d\n", Last - 1000, HNMIter.PulseList.Frames[f]);
    
    RCall(HNMItersizer, PrevTo    )(& HNMSizer, 0);
    RCall(HNMItersizer, IterNextTo)(& HNMSizer, Last - 1000);
    
    String_SetChars(& Path, "/tmp/out.wav");
    RCall(Wave, ToFile)(& YWave, & Path);
    
    RFree(Win);
    RDelete(& Path);
    RDelete(& SinFrame, & SinSpec, & XWave, & YWave, & HNMIter, & HNMSizer);
    return 0;
}

