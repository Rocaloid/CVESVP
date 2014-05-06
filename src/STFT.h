#ifndef CVESVP_STFT_H
#define CVESVP_STFT_H

#include <CVEDSP2.h>
#include <RUtil2.h>

#if 0
#include "_STFT.h"
#endif

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/_STFT.h"
#else
#define _RTAddress "_STFT.h"
#endif

#define _ClassName CSVP_STFTChain_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

#endif

