#ifndef CSVP_LIST_INT_H
#define CSVP_LIST_INT_H

#define First CSVP_List_Int* This

#include <RUtil2.h>

RClass(CSVP_List_Int)
{
    RInherit(RObject);
    
    //Public
    Array_Define(int, Frames);
};

void CSVP_List_Int_CtorSize(First, int Size);
void CSVP_List_Int_Resize(First, int Size);
void CSVP_List_Int_From(First, CSVP_List_Int* Sorc);
void CSVP_List_Int_Clear(First);

int  CSVP_List_Int_Fetch(First, int Index);
int  CSVP_List_Int_IndexBefore(First, int Position);
int  CSVP_List_Int_IndexAfter(First, int Position);
int  CSVP_List_Int_Extract(First, int Index);
int  CSVP_List_Int_ExtractBefore(First, int Position);
int  CSVP_List_Int_ExtractAfter(First, int Position);
void CSVP_List_Int_Remove(First, int Index);
void CSVP_List_Int_RemoveRange(First, int LIndex, int HIndex);
void CSVP_List_Int_RemoveRangeP(First, int LPosition, int HPosition);

int  CSVP_List_Int_Add(First, int Position);

#undef  First
#endif

