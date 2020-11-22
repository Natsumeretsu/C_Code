//线性表的静态分配和基本操作
#include "Sqlist_CommonElement.h"
#include "Sqlist_CommonOperation.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Sqlist L;             //声明顺序表
    Initlist(&L);         //初始化顺序表
    Length(L);            //显示顺序表的长度
    Empty(L);             //判空操作
    ListInsert(&L, 1, 9); //在位序1插入9
    Empty(L);             //判空操作
    Length(L);
    GetElem(L, 1);
    LocateElem(L, 9);
    PrintList(L);      //打印顺序表
    ListDelete(&L, 1); //删除位序1的9
    Empty(L);          //判空操作
    GetElem(L, 1);
    LocateElem(L, 9);
    PrintList(L); //打印顺序表
    getchar();
}