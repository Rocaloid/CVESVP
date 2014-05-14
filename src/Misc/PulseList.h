#ifndef CSVP_PULSELIST_H
#define CSVP_PULSELIST_H

#define First CSVP_PulseList* This

#include <RUtil2.h>

RClass(CSVP_PulseList)
{
    RInherit(RObject);
    
    //Public
    Array_Define(int, Pulses);
};

void CSVP_PulseList_CtorSize(First, int Size);
void CSVP_PulseList_Resize(First, int Size);
void CSVP_PulseList_From(First, CSVP_PulseList* Sorc);
void CSVP_PulseList_Clear(First);

int  CSVP_PulseList_Fetch(First, int Index);
int  CSVP_PulseList_IndexBefore(First, int Position);
int  CSVP_PulseList_IndexAfter(First, int Position);
int  CSVP_PulseList_Extract(First, int Index);
int  CSVP_PulseList_ExtractBefore(First, int Position);
int  CSVP_PulseList_ExtractAfter(First, int Position);
void CSVP_PulseList_RemoveRange(First, int LPosition, int HPosition);

int  CSVP_PulseList_Add(First, int Position);

#undef  First
#endif

