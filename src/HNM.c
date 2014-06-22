#include "HNM.h"
#include "F0.h"
#include <RUtil2.h>

#if 0
#include "Iterator/_SinusoidalBase.rc"
#include "Iterator/_SinusoidIterlyzer.rc"
#endif

#define ANALSIZE 2048
#define ANALHOP 256

#define _RTAddress "Iterator/_SinusoidalBase.rc"

#define _ClassName CSVP_SinusoidalBase_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

//-----

#include <RUtil2.h>

#define _RTAddress "Iterator/_SinusoidIterlyzer.rc"

#define _ClassName CSVP_SinusoidIterlyzer_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

