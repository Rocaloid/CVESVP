#ifndef CVESVP_LISTS_H
#define CVESVP_LISTS_H

#include <CVEDSP2.h>
#include "Structure/DataFrame.h"

#if 0
#include "_List.h"
#include "_TypeList.h"
#endif

#include "List_Int.h"

//-----
#include <RUtil2.h>

#ifdef __CSVP_Install
#define _RTAddress "CVESVP/Misc/_TypeList.h"
#else
#define _RTAddress "Misc/_TypeList.h"
#endif

#define _ClassName CSVP_List_
#define _Attr 1

#define _T1 Float
#include <RUtil2/Core/RTemplate.h>

#define _T1 Double
#include <RUtil2/Core/RTemplate.h>

#endif

