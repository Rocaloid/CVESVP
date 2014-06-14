#include "Structure/HNMFrame.h"
#include <CVEDSP2.h>
#include <RUtil2.h>

#define Sinusoid CSVP_Sinusoid_Float
#define Spectrum CDSP2_Spectrum_Float
int main()
{
    Sinusoid SinFrame;
    Spectrum SinSpec;
    RCall(Sinusoid, CtorSize)(& SinFrame, 5);
    RCall(Spectrum, CtorSize)(& SinSpec, 2048);
    SinSpec.MagnType = CDSP2_LogMagn;
    
    int i;
    for(i = 0; i < 5; i ++)
    {
        SinFrame.Freq[i] = 900 * i + 900;
        SinFrame.Ampl[i] = i * 0.2;
    }
    
    Float* X = RAlloc_Float(2048);
    RCall(Sinusoid, ToSpectrum)(& SinFrame, & SinSpec);
    RCall(Sinusoid, ToReal)(& SinFrame, X, 2048, 44100);
    for(i = 0; i < 1025; i ++)
        printf("%.20f\n", SinSpec.Magn[i]);
    
    RFree(X);
    RDelete(& SinFrame, & SinSpec);
    return 0;
}

