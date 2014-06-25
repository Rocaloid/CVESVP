#include "HNM.h"
#include "EndPoint.h"
#include <CVEDSP2.h>
#include <RUtil2.h>

#define Sinusoid CSVP_Sinusoid_Float
#define Spectrum CDSP2_Spectrum_Float
#define SinusoidalBase CSVP_SinusoidalBase_Float
#define SinusoidIterlyzer CSVP_SinusoidIterlyzer_Float
#define SinusoidItersizer CSVP_SinusoidItersizer_Float
#define Wave CDSP2_Wave_Float
#define IWave CDSP2_IWave_Float

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
    String_SetChars(& Path, "/tmp/p/pa1.wsp");
    RCall(Wave, FromFile)(& XWave, & Path);
    RCall(Wave, Resize)(& YWave, XWave.Size);
    //RCall(Sinusoid, ToSpectrum)(& SinFrame, & SinSpec);
    //RCall(Sinusoid, ToReal)(& SinFrame, X, 44100 * 5, 44100);
    //CDSP2_VCMul_Float(X, X, 0.05, 44100 * 5);
    /*
    for(i = 0; i < 1025; i ++)
        printf("%.20f\n", X[i]);*/
    //    printf("%.20f\n", SinSpec.Magn[i]);
    
    SinusoidIterlyzer SinuIter;
    RCall(SinusoidIterlyzer, CtorSize)(& SinuIter, 2048);
    SinuIter.GenPhase = 1;
    
    RCall(SinusoidIterlyzer, SetHopSize)(& SinuIter, 256);
    RCall(SinusoidIterlyzer, SetWave)(& SinuIter, & XWave);
    RCall(SinusoidIterlyzer, SetPosition)(& SinuIter, 15000);
    RCall(SinusoidIterlyzer, PreAnalysisTo)(& SinuIter, 20000);
    
    //printf("%f\n", SinuIter._Base.InitF0);
    int VOT = CSVP_VOTFromWave_Float(& XWave, 0, XWave.Size / 2);
    
    printf("VOT: %d\n", VOT);
    
    RCall(SinusoidIterlyzer, PrevTo)(& SinuIter, VOT);
    RCall(SinusoidIterlyzer, IterNextTo)(& SinuIter, 20000);
    RCall(SinusoidIterlyzer, IterNextTo)(& SinuIter, XWave.Size - 2000);
    /*
    for(i = 0; i <= SinuIter.PulseList.Frames_Index; i ++)
    {
        int j;
        printf("Frame %d at %d:\n", i, SinuIter.PulseList.Frames[i]);
        Sinusoid* Sinu = & SinuIter.SinuList.Frames[i];
        for(j = 0; j <= Sinu -> Freq_Index; j ++)
            printf("  %dth Harmonic, F = %fHz, A = %f.\n", j + 1,
                Sinu -> Freq[j], Sinu -> Ampl[j]);
    }*/
    
    SinusoidItersizer SinuSizer;
    RCall(SinusoidItersizer, Ctor)(& SinuSizer);
    CSVP_List_Int_From(& SinuSizer.PulseList, & SinuIter.PulseList);
    CSVP_List_Sinusoid_Float_From(& SinuSizer.SinuList, & SinuIter.SinuList);
    RCall(SinusoidItersizer, SetWave)(& SinuSizer, & YWave);
    RCall(SinusoidItersizer, SetPosition)(& SinuSizer, 15000);
    
    RCall(SinusoidItersizer, PrevTo)(& SinuSizer, VOT + 256);
    RCall(SinusoidItersizer, IterNextTo)(& SinuSizer, XWave.Size - 3000);
    
    String_SetChars(& Path, "/tmp/out.wav");
    RCall(Wave, ToFile)(& YWave, & Path);
    
    RFree(Win);
    RDelete(& Path);
    RDelete(& SinFrame, & SinSpec, & XWave, & YWave, & SinuIter, & SinuSizer);
    return 0;
}

