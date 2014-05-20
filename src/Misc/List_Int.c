#include "List_Int.h"
#include <RFNL.h>

#define First CSVP_List_Int* This

RCtor(CSVP_List_Int)
{
    Array_Ctor(int, This -> Frames);
    RInit(CSVP_List_Int);
}

RDtor(CSVP_List_Int)
{
    Array_Dtor(int, This -> Frames);
}

void CSVP_List_Int_CtorSize(First, int Size)
{
    Array_Ctor(int, This -> Frames);
    Array_Resize(int, This -> Frames, Size);
    RInit(CSVP_List_Int);
}

void CSVP_List_Int_Resize(First, int Size)
{
    Array_Resize(int, This -> Frames, Size);
}

void CSVP_List_Int_From(First, CSVP_List_Int* Sorc)
{
    int Size = Sorc -> Frames_Index + 1;
    Array_Resize(int, This -> Frames, Size);
    This -> Frames_Index = Sorc -> Frames_Index;
    //TODO: CDSP2_VCopy_Int interface
    RFNL_VCopy_Gnrc_Int(This -> Frames, Sorc -> Frames, Size);
}

void CSVP_List_Int_Clear(First)
{
    Array_Resize(int, This -> Frames, 0);
}

int  CSVP_List_Int_Fetch(First, int Index)
{
    return This -> Frames[Index];
}

int  CSVP_List_Int_IndexBefore(First, int Position)
{
    int i;
    if(This -> Frames_Index < 0) return - 1;
    if(Position < This -> Frames[0]) return - 1;
    Array_IncFind(i, int, This -> Frames, Position);
    return i - 1;
}

int  CSVP_List_Int_IndexAfter(First, int Position)
{
    int i;
    if(This -> Frames_Index < 0) return 0;
    if(Position < This -> Frames[0]) return 0;
    Array_IncFind(i, int, This -> Frames, Position);
    return i;
}

int  CSVP_List_Int_Extract(First, int Index)
{
    int Ret = This -> Frames[Index];
    Array_Remove(int, This -> Frames, Index);
    return Ret;
}

int  CSVP_List_Int_ExtractBefore(First, int Position)
{
    return CSVP_List_Int_Extract(This,
        CSVP_List_Int_IndexBefore(This, Position));
}

int  CSVP_List_Int_ExtractAfter(First, int Position)
{
    return CSVP_List_Int_Extract(This,
        CSVP_List_Int_IndexAfter(This, Position));
}

void CSVP_List_Int_Remove(First, int Index)
{
    Array_Remove(int, This -> Frames, Index);
}

void CSVP_List_Int_RemoveRange(First, int LIndex, int HIndex)
{
    Array_RemoveRange(int, This -> Frames, LIndex, HIndex);
}

void CSVP_List_Int_RemoveRangeP(First, int LPosition, int HPosition)
{
    int LIndex = CSVP_List_Int_IndexAfter(This, LPosition);
    int HIndex = CSVP_List_Int_IndexBefore(This, HPosition);
    Array_RemoveRange(int, This -> Frames, LIndex, HIndex);
}
int  CSVP_List_Int_Add(First, int Position)
{
    int i;
    Array_IncFind(i, int, This -> Frames, Position);
    Array_Insert(int, This -> Frames, i, Position);
    return i;
}

