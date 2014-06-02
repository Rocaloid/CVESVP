#define _T2 _C(CDSP2_Spectrum, _, _T1)
#define _T3 Spectrum
#include "_SizeNumList.h"
#undef  _T2
#undef  _T3

#define _T2 _C(CSVP_DataFrame, _, _T1)
#define _T3 DataFrame
#define _CSVP_NOSIZE

#include "_SizeNumList.h"

RTMethod(void, CSVP_List_DataFrame, FromWave, void* SorcWave,
    CSVP_List_Int* SorcPulse);

#undef  _CSVP_NOSIZE
#undef  _T2
#undef  _T3

