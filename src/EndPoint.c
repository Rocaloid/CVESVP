#include "EndPoint.h"
#include <RUtil2.h>

#define SIZE_FFT 256
#define SIZE_HOP 64

#if 0
#include "_VOT.rc"
#endif

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/_VOT.rc"
#else
#define _RTAddress "_VOT.rc"
#endif

#define _ClassName _
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

