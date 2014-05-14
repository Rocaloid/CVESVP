#include "STFT.h"
#include <RUtil2.h>

#if 0
#include "_STFTIterlyzer.rc"
#include "_STFTItersizer.rc"
#endif

//-----

#include <RUtil2.h>

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/_STFTIterlyzer.rc"
#else
#define _RTAddress "_STFTIterlyzer.rc"
#endif

#define _ClassName CSVP_STFTIterlyzer_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>


//-----

#include <RUtil2.h>

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/_STFTItersizer.rc"
#else
#define _RTAddress "_STFTItersizer.rc"
#endif

#define _ClassName CSVP_STFTItersizer_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

