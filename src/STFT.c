#include "STFT.h"
#include <RUtil2.h>

#if 0
#include "_STFT.rc"
#endif

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/_STFT.rc"
#else
#define _RTAddress "_STFT.rc"
#endif

#define _ClassName CSVP_STFTChain_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

