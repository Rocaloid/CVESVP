#ifndef CSVP_HNM_H
#define CSVP_HNM_H

#include "Misc/Lists.h"
#include "Misc/List_Int.h"
#include "STFT.h"
#include <CVEDSP2.h>
#include <RUtil2.h>

#if 0
#include "Iterator/_SinusoidalBase.h"
#include "Iterator/_SinusoidIterlyzer.h"
#endif

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/Iterator/_SinusoidalBase.h"
#else
#define _RTAddress "Iterator/_SinusoidalBase.h"
#endif

#define _ClassName CSVP_SinusoidalBase_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

//-----

#include <RUtil2.h>

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/Iterator/_SinusoidIterlyzer.h"
#else
#define _RTAddress "Iterator/_SinusoidIterlyzer.h"
#endif

#define _ClassName CSVP_SinusoidIterlyzer_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

#endif

