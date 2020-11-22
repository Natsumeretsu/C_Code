#include "Seqlist_CommonElement.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct //
{
    ElemType *data;
    // *data = NULL;//定义时不能初始化？
    int MaxSize, length;
} Seqlist;

// 线性表的基本操作:
// Initlist(&L):初始化表.构造一个空的线性表.
void Initlist(Seqlist *L)
{
    L->data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    L->MaxSize = 10;
    L->length = 0;
    for (int i = 0; i < L->MaxSize; i++) //清除脏数据
    {
        L->data[i] = -1;
    }
    printf("InitList:初始化表成功,当前长度为%d,最大长度为%d\n", L->length, L->MaxSize);
}

// Length(L):求表长.返回线性表L的长度,即L中元素的个数.
int Length(Seqlist L)
{
    printf("Length:当前表中元素个数为%d\n", L.length);
    return L.length;
}

// LocateElem(L,e):按值查找操作.在表L中查找具有给定关键字的元素.
void LocateElem(Seqlist L, int e)
{
    int flag = 0;
    for (int i = 0; i <= L.length; i++)
        if (L.data[i] == e)
        {
            flag = 1;
            printf("LocateElem:找到元素%d，在顺序表中的位序为%d\n", e, i + 1);
        }
    if (!flag)
        printf("LocateElem:未在顺序表中找到元素%d\n", e);
}

// GetElem(L,i):按位查找.获取表L中第i个位置的元素的值.
bool GetElem(Seqlist L, int i)
{
    if (i < 0 || i > L.length)
    {
        printf("GetElem:所查找的位置错误！！\n");
        return false;
    }
    printf("GetElem:位序为%d的元素是%d\n", i, L.data[i - 1]);
    return true;
}

// ListInsert(&L,i,e):插入操作.在表L中的第i个位置插入指定元素e.
bool ListInsert(Seqlist *L, int i, int e)
{
    if (L->length == L->MaxSize) //若内存不足自动扩展一个InitSize(10*ElemType)
    {
        Seqlist L2;
        L2.data = (ElemType *)malloc(sizeof(ElemType) * (InitSize + L->MaxSize));
        for (int tem = 0; tem <= L->MaxSize; tem++) //转移数据
        {
            L2.data[tem] = L->data[tem];
        }
        L2.MaxSize = L->MaxSize + InitSize;                  //新顺序表MaxSize+IniteSize
        for (int npos = InitSize; npos < L2.MaxSize; npos++) //初始化新申请的内存空间
        {
            L2.data[npos] = -1;
        }
        L2.length = L->length;
        // free(L->data);
        L->data = L2.data;
    }
    for (int j = L->length; j >= i - 1; j--) //移位操作
    {
        L->data[j + 1] = L->data[j]; //将位序为i的元素及其后面的元素全都向后移动一位。
    }
    L->data[i - 1] = e; //向所要插入的位置插入元素
    L->length++;
    printf("ListInsert:位序%d插入元素%d成功\n", i, e);
    return true;
}

// ListDelete(&L,i,&e):删除操作.删除表L中的第i个位置的元素,并用e返回删除元素的值.
int ListDelete(Seqlist *L, int i)
{
    int e = 0;
    if (i <= 0 || i > L->length)
    {
        printf("ListDelete:要删除的位置%d错误！\n", i);
        return -1;
    }
    e = L->data[i - 1]; //用e返回删除元素的值
    for (int pos = i - 1; pos < L->length; pos++)
    {
        L->data[pos] = L->data[pos + 1];
    }
    L->length--;
    printf("ListDelete:位序%d的元素%d已被成功删除！\n", i, e);
    return e;
}
// PrintList(L):输出操作.按前后顺序输出线性表L的所有元素值.
void PrintList(Seqlist L)
{
    for (int pos = 0; pos <= L.length - 1; pos++)
        printf("PrintList:序列为%d的元素值是%d\n", pos + 1, L.data[pos]);
}
// Empty(L):判空操作.若L为空表,则返回true,否则返回false.
bool Empty(Seqlist L)
{
    if (L.data)
    {
        printf("Empty:当前表不为空！\n");
        Length(L);
        return false;
    }
    printf("Empty:当前表为空！\n");
    // Length(L);
    return true;
}
// DestoryList(&L):销毁操作.销毁线性表,并释放线性表L所占用的空间.
bool DestoryList(Seqlist *L)
{
    if (L->data == NULL) //暂时没用
    {
        printf("DestoryList:当前表没有初始化！\n");
        return false;
    }
    free(L->data);
    L->length = 0;
    L->MaxSize = 0;
    printf("DestoryList:线性表销毁成功！\n");
    return true;
}