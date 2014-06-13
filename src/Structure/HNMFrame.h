#ifndef CSVP_HNMFRAME_H
#define CSVP_HNMFRAME_H

#include <CVEDSP2.h>
#include <RUtil2.h>

#if 0
#include "_Sinusoid.h"
#include "_HNMFrame.h"
#endif

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/Structure/_Sinusoid.h"
#else
#define _RTAddress "Structure/_Sinusoid.h"
#endif

#define _ClassName CSVP_Sinusoid_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

#include <RUtil2.h>

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/Structure/_HNMFrame.h"
#else
#define _RTAddress "Structure/_HNMFrame.h"
#endif

#define _ClassName CSVP_HNMFrame_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

#endif

