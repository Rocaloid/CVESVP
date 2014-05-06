#ifndef CVESVP_HNM_H
#define CVESVP_HNM_H

#include <CVEDSP2.h>
#include <RUtil2.h>

#if 0
#include "_HNMFrame.h"
#include "_HNMContour.h"
#include "_HNMChain.h"
#endif

//--------

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/_HNMContour.h"
#else
#define _RTAddress "_HNMContour.h"
#endif

#define _ClassName CSVP_HNMContour_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

//--------

#include <RUtil2.h>

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/_HNMFrame.h"
#else
#define _RTAddress "_HNMFrame.h"
#endif

#define _ClassName CSVP_HNMFrame_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

//--------

#include <RUtil2.h>

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/_HNMChain.h"
#else
#define _RTAddress "_HNMChain.h"
#endif

#define _ClassName CSVP_HNMChain_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

#endif

