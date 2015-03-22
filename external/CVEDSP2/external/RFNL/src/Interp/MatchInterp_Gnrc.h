//Generic PMatch Interpolation Header

#include <RUtil2.h>

#if 0
#include "_MatchInterp_Gnrc.h"
#endif

#ifdef __RFNL_Install
#define _RTAddress "RFNL/Interp/_MatchInterp_Gnrc.h"
#else
#define _RTAddress "Interp/_MatchInterp_Gnrc.h"
#endif

#define _ClassName
#define _Attr 2

#define _T1 Float
#define _T2 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Float
#define _T2 Double
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#define _T2 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#define _T2 Double
#include <RUtil2/Core/RTemplate.h>

#undef _RTAddress

