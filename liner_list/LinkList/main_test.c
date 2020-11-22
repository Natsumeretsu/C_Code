#include "LinkList_CommonOperation.h"
#include <stdio.h>
// #include <stdlib.h>
//线性表的链式表示
void main(void)
{
    LinkList L;      //声明一个指向单链表的指针L
    LNode *TemNode;  //接收GetElem的返回值
    LNode *TemNode2; //接收LocateElem的返回值
    // L=List_HeadInsert(L);
    L = List_TailInsert(L);
    // TemNode = GetElem(L, 1);
    // printf("Test.GetElem:返回结点的值为%d\n", TemNode->data);
    LocateElem(L, 224516);
    LocateElem(L, 3333);
    // TemNode2 = LocateElem(L, 224516);
    // printf("Test.LocateElem返回的值的值为：%d,地址为：%p\n", TemNode2->data, TemNode2);
    LinkListLength(L); //查看插入前链表的长度
    GetElem(L, 3);
    // BackLinkListInsert(L, 3, 9999999);
    FormerLinkListInsert(L, 3, 9999999);
    LinkListLength(L); //查看插入后前链表的长度
    GetElem(L, 3);
    LinkListDelete(L, 3);
    GetElem(L, 3);
    PrintLinkList(L);
    LinkListEmpty(L);
    DestoryLinkList(L); //销毁
    LinkListEmpty(L);   //销毁后判空
    LinkListLength(L);
}