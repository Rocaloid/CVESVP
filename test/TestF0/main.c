#include "F0.h"
#include <CVEDSP2.h>

int main()
{
    CDSP2_SetArch(CDSP2_Arch_Gnrc);
    CDSP2_Wave_Float MyWave;
    CDSP2_Wave_Float_Ctor(& MyWave);
    
    Float* wind = RAlloc_Float(2048);
    CDSP2_GenHanning_Float(wind, 2048);
    CDSP2_Wave_Float_SetWindow(& MyWave, wind, 2048);
    
    String_FromChars(Path, "/tmp/test.wav");
    
    CDSP2_Wave_Float_FromFile(& MyWave, & Path);
    
    int i;
    for(i = 0; i < MyWave.Size; i += 500)
        printf("%f\n", CSVP_F0FromWave_Float(& MyWave, i, 2048, 100, 1500, 48000));
    
    RDelete(& MyWave, & Path);
    RFree(wind);
    return 0;
}

