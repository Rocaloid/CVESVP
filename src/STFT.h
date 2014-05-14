#ifndef CVESVP_STFT_H
#define CVESVP_STFT_H

#include "Misc/Lists.h"
#include <CVEDSP2.h>
#include <RUtil2.h>

#if 0
#include "_STFTItersizer.h"
#include "_STFTIterlyzer.h"
#endif

//-----
#include <RUtil2.h>

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/_STFTIterlyzer.h"
#else
#define _RTAddress "_STFTIterlyzer.h"
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
#define _RTAddress "CVESVP/_STFTItersizer.h"
#else
#define _RTAddress "_STFTItersizer.h"
#endif

#define _ClassName CSVP_STFTItersizer_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

#endif

