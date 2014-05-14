#include "PulseList.h"
#include <RFNL.h>

#define First CSVP_PulseList* This

RCtor(CSVP_PulseList)
{
    Array_Ctor(int, This -> Pulses);
    RInit(CSVP_PulseList);
}

RDtor(CSVP_PulseList)
{
    Array_Dtor(int, This -> Pulses);
}

void CSVP_PulseList_CtorSize(First, int Size)
{
    Array_Ctor(int, This -> Pulses);
    Array_Resize(int, This -> Pulses, Size);
    RInit(CSVP_PulseList);
}

void CSVP_PulseList_Resize(First, int Size)
{
    Array_Resize(int, This -> Pulses, Size);
}

void CSVP_PulseList_From(First, CSVP_PulseList* Sorc)
{
    int Size = Sorc -> Pulses_Index + 1;
    Array_Resize(int, This -> Pulses, Size);
    This -> Pulses_Index = Sorc -> Pulses_Index;
    //TODO: CDSP2_VCopy_Int interface
    RFNL_VCopy_Gnrc_Int(This -> Pulses, Sorc -> Pulses, Size);
}

void CSVP_PulseList_Clear(First)
{
    Array_Resize(int, This -> Pulses, 0);
}

int  CSVP_PulseList_Fetch(First, int Index)
{
    return This -> Pulses[Index];
}

int  CSVP_PulseList_IndexBefore(First, int Position)
{
    int i;
    if(This -> Pulses_Index < 0) return - 1;
    if(Position < This -> Pulses[0]) return - 1;
    Array_IncFind(i, int, This -> Pulses, Position);
    return i - 1;
}

int  CSVP_PulseList_IndexAfter(First, int Position)
{
    int i;
    if(This -> Pulses_Index < 0) return 0;
    if(Position < This -> Pulses[0]) return 0;
    Array_IncFind(i, int, This -> Pulses, Position);
    return i;
}

int  CSVP_PulseList_Extract(First, int Index)
{
    int Ret = This -> Pulses[Index];
    Array_Remove(int, This -> Pulses, Index);
    return Ret;
}

int  CSVP_PulseList_ExtractBefore(First, int Position)
{
    return CSVP_PulseList_Extract(This,
        CSVP_PulseList_IndexBefore(This, Position));
}

int  CSVP_PulseList_ExtractAfter(First, int Position)
{
    return CSVP_PulseList_Extract(This,
        CSVP_PulseList_IndexAfter(This, Position));
}

void CSVP_PulseList_RemoveIndex(First, int Index)
{
    Array_Remove(int, This -> Pulses, Index);
}

void CSVP_PulseList_RemoveIndexRange(First, int LIndex, int HIndex)
{
    Array_RemoveRange(int, This -> Pulses, LIndex, HIndex);
}

void CSVP_PulseList_RemoveRange(First, int LPosition, int HPosition)
{
    int LIndex = CSVP_PulseList_IndexAfter(This, LPosition);
    int HIndex = CSVP_PulseList_IndexBefore(This, HPosition);
    Array_RemoveRange(int, This -> Pulses, LIndex, HIndex);
}

int  CSVP_PulseList_Add(First, int Position)
{
    int i;
    Array_IncFind(i, int, This -> Pulses, Position);
    Array_Insert(int, This -> Pulses, i, Position);
    return i;
}

