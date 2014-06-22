#include "HNM.h"
#include <CVEDSP2.h>
#include <RUtil2.h>

#define Sinusoid CSVP_Sinusoid_Float
#define Spectrum CDSP2_Spectrum_Float
#define SinusoidalBase CSVP_SinusoidalBase_Float
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
        SinFrame.Freq[i] = 60 * i + 60;
        SinFrame.Ampl[i] = i * 0.2;
    }
    
    Wave XWave;
    RCall(Wave, CtorSize)(& XWave, 44100 * 5);
    Float* X = RCall(IWave, GetUnsafePtr)(& XWave);
    Float* Win = RAlloc_Float(2048);
    CDSP2_GenHanning_Float(Win, 2048);
    RCall(Wave, SetWindow)(& XWave, Win, 2048);
    
    RCall(Sinusoid, ToSpectrum)(& SinFrame, & SinSpec);
    RCall(Sinusoid, ToReal)(& SinFrame, X, 44100 * 5, 44100);
    CDSP2_VCMul_Float(X, X, 0.05, 44100 * 5);
    /*
    for(i = 0; i < 1025; i ++)
        printf("%.20f\n", X[i]);*/
    //    printf("%.20f\n", SinSpec.Magn[i]);
    
    SinusoidalBase IterBase;
    RCall(SinusoidalBase, CtorSize)(& IterBase, 2048);
    RCall(SinusoidalBase, SetHopSize)(& IterBase, 256);
    RCall(SinusoidalBase, SetWave)(& IterBase, & XWave);
    RCall(SinusoidalBase, SetPosition)(& IterBase, 5000);
    RCall(SinusoidalBase, PreAnalysisTo)(& IterBase, 15000);
    
    printf("%f\n", IterBase.InitF0);
    
    RFree(Win);
    RDelete(& SinFrame, & SinSpec, & XWave, & IterBase);
    return 0;
}

