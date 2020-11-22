#include "Sqlist_CommonElement.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//定义线性表的顺序存储类型描述
//一堆数组可以是静态分配,也可以是动态分配
typedef struct //类型重命名、静态分配
{
    ElemType data[MaxSize]; //存放数据
    int length;             //当前长度
} Sqlist;                   //结构体名：Sqlist

// typedef struct //类型重命名
// {
//     ElemType *data;        //指针指向首元素的地址
//     int Maxlength, length; //最大长度和当前长度
// } Seqlist;                 //结构体名：Seqlist

// C的动态分配语句为:
// L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize)
// C++的初始动态分配语句为:
// L.data = new ElemType[InitSize]

//注意:动态分配并不是链式存储,它同样属于顺序存储结构,
//物理结构没有变化,依然是随机存取方式,只是分配的空间大小可以在运行时决定.

//顺序表最主要的特点是随机访问,即通过首地址和元素序号可以在时间O(1)内找到指定元素
//顺序表的存储密度高,每个节点只存储数据元素.
//顺序表逻辑上相邻的元素物理上也相邻,所以插入和删除操作需要移动大量的元素

// 静态线性表的基本操作:

// Initlist(&L):初始化表.构造一个空的线性表.
bool Initlist(Sqlist *L)
{
    for (int i = 0; i < 10; i++)
    {
        L->data[i] = 0;
        printf("Initlist:初始化位序%d成功！\n", i + 1);
    }
    L->length = -1;
    return true;
}

//  Length(L):求表长.返回线性表L的长度,即L中元素的个数.
void Length(Sqlist L)
{
    // int count = 0;
    // for (int i = 0; i < L.length;i++)
    //     count++;
    printf("Length:表的长度为%d\n", L.length);
}

// : LocateElem(L,e):按值查找操作.在表L中查找具有给定关键字的元素.
void LocateElem(Sqlist L, ElemType e)
{
    int flag = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            flag = 1;
            printf("LocateElem:找到元素%d，在%d号位序.\n", e, i + 1);
        }
    }
    if (flag == 0)
        printf("LocateElem:未找到元素%d\n", e);
}

// : GetElem(L,i):按位查找.获取表L中第i个位序的元素的值.
void GetElem(Sqlist L, int i)
{
    if (i >= 0 && i < MaxSize) //判断所查找的位序i是否在列表范围内。
    {
        printf("GetElem:位序%d的元素是%d\n", i, L.data[i - 1]);
    }
    else
    {
        printf("GetElem:位序不合法！！\n");
    }
}

// : ListInsert(&L,i,e):插入操作.在表L中的第i个位序插入指定元素e.
bool ListInsert(Sqlist *L, int i, ElemType e)
{

    if (i < 0 || i > MaxSize) //判断所要插入的位序是否合法
    {
        printf("ListInsert:位序%d不合法！！\n", i);
        return false; //判断位序不合法
    }
    if (L->length <= MaxSize) //若有空位则可以插入
    {
        for (int j = L->length; j >= i; j--)
            L->data[j] = L->data[j - 1];
        L->length++;
        L->data[i - 1] = e;
        printf("ListInsert:位序%d插入元素%d成功。\n", i, e);
        return true;
    }
    else //若没有空位，不能插入
    {
        printf("ListInsert:顺序表已满！");
        return false;
    }
}
// : ListDelete(&L,i,&e):删除操作.删除表L中的第i个位序的元素,并用e返回删除元素的值.
int ListDelete(Sqlist *L, int i) //&e用return返回
{
    int e = 0;
    if (L->length == 0)
    {
        printf("ListDelete:当前列表为空！\n");
        return false;
    }
    if (i > 0 && i < MaxSize)
    {
        e = L->data[i - 1];
        for (int j = L->length; j >= i; j--)
        {
            L->data[j - 1] = L->data[j];
        }
        L->length--;
        printf("ListDelete:已成功删除位序为%d的元素%d\n", i, e);
        return e;
    }
}

// : PrintList(L):输出操作.按前后顺序输出线性表L的所有元素值.
int PrintList(Sqlist L)
{
    if (L.length == 0)
    {
        printf("PrintList:列表为空！！\n");
        return false;
    }
    for (int i = 0; i < L.length; i++)
        printf("PrintList:位序为%d的元素值为%d\n", i + 1, L.data[i]);
    return true;
}

// : Empty(L):判空操作.若L为空表,则返回true,否则返回false.
bool Empty(Sqlist L)
{
    if (L.length == 0)
    {
        printf("Empty:当前顺序表是空表！！\n");
        return true;
    }
    else
    {
        printf("Empty:当前顺序表不是空表！！长度为%d\n", L.length);
        return false;
    }
}

// : DestoryList(&L):销毁操作.销毁线性表,并释放线性表L所占用的空间.
// void DestoryList(Sqlist *L)//自动销毁？？

