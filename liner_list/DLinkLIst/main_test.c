#include "DLinkList_CommonOperation.h"
#include <stdio.h>

void main()
{
    DLinkList L;
    L = InitDLinkList_tail(L);
    PrintDLinkList(L);
    // L = InitDLinkList_Head(L);
    // Length(L);
    // LocateElem(L, 1);
    // LocateElem(L, 111);
    // GetElem(L, 1);
    // GetElem(L, 2);
    DLinkListInsert_Head(L, 3, 10086);
    // DLinkListInsert_Tail(L, 3, 10086);
    PrintDLinkList(L);
    DestoryDLinkList(L);
}