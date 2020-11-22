//顺序表的动态分配和基本操作
#include "Seqlist_CommonElement.h"
#include "Seqlist_CommonOperation.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Seqlist L;
    // L.data = NULL;//不管是否赋值为NULL指向的地址都是0x8？
    Initlist(&L);
    // L.data[0] = 9;
    // L.data[1] = 8;
    // L.data[2] = 7;
    // printf("%d\n", L.data[1]);
    for (int pos = 1; pos <= 10; pos++)
        ListInsert(&L, pos, 12315);
    Length(L);
    for (int pos = 1; pos <= 3; pos++)
        ListInsert(&L, pos+10, 10001);
    Length(L);
    ListDelete(&L, 11);
    Length(L);
    ListInsert(&L, 13, 10086);
    LocateElem(L, 8);
    LocateElem(L, 10001);
    LocateElem(L, 10086);
    GetElem(L, 1);
    Length(L);
    PrintList(L);
    Empty(L);
    DestoryList(&L);
    Length(L);
    return 0;
}