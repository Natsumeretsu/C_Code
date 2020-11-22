#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//单链表节点类型定义
typedef struct LNode //定义单链表节点类型
{
    int data;           //数据域
    struct LNode *next; //指针域
} LNode, *LinkList;

// 单链表的基本操作:

// List_HeadInsert(&L):采用头插法建立单链表
LinkList List_HeadInsert(LinkList L) //逆向建立单链表
{
    printf("List_HeadInsert:单链表建立开始\n");
    LNode *s; //创建一个指向结点类型的指针s
    int x;
    L = (LinkList)malloc(sizeof(LNode)); //创建头节点//将malloc返回的地址赋值给形参L(形参L：指向链表的指针),
    L->next = NULL;                      //头结点指针域初始化NULL
    printf("List_HeadInsert:输入数值以建立结点(9999为退出):\n");
    scanf("%d", &x);  //结点值输入
    while (x != 9999) //任意特殊值(9999)，表终止
    {
        s = (LNode *)malloc(sizeof(LNode)); //创建新的结点
        s->data = x;
        s->next = L->next;
        L->next = s;
        printf("List_HeadInsert:数值为%d的结点建立成功！\n", x);
        printf("List_HeadInsert:输入数值以继续建立结点(9999为退出):\n");
        scanf("%d", &x);
    }
    printf("List_HeadInsert:单链表建立结束\n");
    return L;
}

// List_TailInsert(&L):采用尾插法建立单链表
LinkList List_TailInsert(LinkList L)
{
    printf("List_TailInsert:单链表建立开始\n");
    int x;
    L = (LinkList)malloc(sizeof(LNode)); //头结点创建
    LNode *s, *r = L;                    //这里写*r = L为什么不会让r指向L？？要让头结点先创建才能使r指向。
    // r = L;
    // L = (LinkList)malloc(sizeof(LNode));//创建晚了，使得r变为野指针，要移到上面去。
    printf("List_TailInsert:输入数值以建立结点(9999为退出):\n");
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s; //将r指向新的表尾结点
        printf("List_TailInsert:数值为%d的结点建立成功！\n", x);
        printf("List_TailInsert:输入数值以继续建立结点(9999为退出):\n");
        scanf("%d", &x);
    }
    r->next = NULL; //尾结点指针置空
    printf("List_TailInsert:单链表建立结束\n");
    return L;
}

// GetElem(L,i):按序号查找结点值.获取表L中第i个位置的元素的值.
LNode *GetElem(LinkList L, int i)
{
    printf("GetElem:开始在单链表中搜索结点%d\n", i);
    int j = 1;
    LNode *p = L->next;
    if (i == 0) //当查询的结点为头结点的情况
    {
        printf("GetElem:所查询的节点是头结点L\n");
        return L;
    }
    if (i < 1) //当查询的结点为非法结点的情况
    {
        printf("GetElem:所查询的结点不存在！\n");
        return NULL;
    }
    printf("GetElem:当前处于结点%d\n", j);
    while (p && j < i) //退出条件一是j==i,此时p已经指向i结点//二是p==NUll则会退出循环返回NULL
    {
        p = p->next;
        j++;
        printf("GetElem:当前处于结点%d\n", j);
    }
    printf("GetElem:成功搜索到结点%d的值为%d,并将返回其地址,搜索结束\n", j, p->data);
    return p; //返回p==NULL和找到结点的情况
}

// LocateElem(L,e):按值查找表结点.在表L中查找具有给定关键字的元素.
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next; //将p指针指向链表的第一个结点
    while (p != NULL)   //遍历单链表(若此时p==NULL则退出循环[说明此时链表为空,将会返回空指针])
    {
        p = p->next;   //移动p指针
        if (p == NULL) //当遍历到p==NULL时,说明此时链表中没有所查值,返回p==NULL
        {
            printf("LocateElem:当前单链表中没有元素%d\n", e);
            break; //跳出循环
        }
        if (p->data == e) //当遍历到某个p.data==e时跳出循环,返回p
        {
            printf("LocateElem:找到元素%d，将返回元素对应的指针\n", e);
            break;
        }
    }
    return p; //返回p
}

// -------------------------------------------------------------------------

// LinkListInsert(&L,i,e):插入操作.在表L中的第i个位置插入指定元素e.

// Former_LinkListInsert:前插法
LinkList FormerLinkListInsert(LinkList L, int i, int e)
{
    printf("FormerLinkListInsert:即将在结点%d前插入数据%d\n", i, e);
    LNode *p = GetElem(L, i - 1); //将p指针指向所要插入结点的前一个结点
    LNode *q = (LNode *)malloc(sizeof(LNode));
    q->data = e;
    if (!p) //若i大于当前链表的结点数即GetElem返回值为NULL,自动在表尾添加其元素//或者返回原列表
    {
        p = L->next;
        while (p->next == NULL)
        {
            p = p->next;
        }
        p->next = q;
        printf("FormerLinkListInsert:所要插入的位置大于链表!已自动在表尾添加元素\n");
        return L;
    }
    // if (!p)
    // {
    //     printf("FormerLinkListInsert:所要插入的位置大于链表!添加失败请重试!\n");
    //     return L;
    // }
    q->next = p->next;
    p->next = q;
    printf("FormerLinkListInsert:成功在第%d个结点前插入数据%d\n", i, e);
    return L;
}

// Back_LinkListInsert:后插法
LinkList BackLinkListInsert(LinkList L, int i, int e)
{
    printf("BackLinkListInsert:即将在结点%d后插入数据%d\n", i, e);
    LNode *p = GetElem(L, i); //将p指针指向所要插入的结点
    LNode *q = (LNode *)malloc(sizeof(LNode));
    q->data = e;
    if (!p) //若i大于当前链表的结点数,即GetElem返回值为NULL,自动在表尾添加其元素//或者返回原列表
    {
        p = L->next;
        while (p->next == NULL)
        {
            p = p->next;
        }
        p->next = q;
        printf("BackLinkListInsert:所要插入的位置大于链表!已自动在表尾添加元素\n");
        return L;
    }
    // if (!p)
    // {
    //     printf("BackLinkListInsert:所要插入的位置大于链表!添加失败请重试!\n");
    //     return L;
    // }
    q->next = p->next;
    p->next = q;
    printf("BackLinkListInsert:成功在第%d个结点后插入数据%d\n", i, e);
    return L;
}

//--------------------------------------------------------------------------

// LinkListLength(L):求链表长;返回链表L的长度,即L中结点的个数.(不包含头结点)
void LinkListLength(LinkList L)
{
    int count = 0;      //统计结点数
    LNode *p = L->next; //指向第一个结点.
    while (p)
    {
        p = p->next;
        count++;
    }
    printf("LinkListLength:当前链表长度为%d\n", count);
}

// LinkListDelete(&L,i):删除操作;删除表L中的第i个位置的结点,并用返回删除结点的指针
LinkList LinkListDelete(LinkList L, int i)
{
    LNode *p = GetElem(L, i - 1); //将p指针指向即将被删除的节点的前一个结点
    LNode *q = GetElem(L, i);     //将q指针指向即将被删除的节点
    if (!q)                       //若被删除的结点不存在,返回原表
    {
        printf("LinkListDelete:结点%d不存在!\n", i);
        return L;
    }
    p->next = q->next;
    free(q);
    printf("LinkListDelete:成功删除结点%d\n", i);
    return L;
}
// PrintList(L):输出操作.按前后顺序输出线性表L的所有元素值.
void PrintLinkList(LinkList L)
{
    LNode *p = L->next; //将p指向第一个结点
    int count = 1;      //记录当前所在的结点
    while (p)
    {
        printf("PrintLinkList:结点%d的值为%d\n", count, p->data);
        p = p->next;
        count++;
    }
}

// Empty(L):判空操作.若L为空表,则返回true,否则返回false.
bool LinkListEmpty(LinkList L)
{
    if (L->next)
    {
        printf("LinkListEmpty:链表为非空\n");
        return false;
    }
    printf("LinkListEmpty:链表为空\n");
    return true;
}

// DestoryList(&L):销毁操作.销毁链表,并释放链表L所占用的空间.
void DestoryLinkList(LinkList L)
{
    free(L);
    printf("DestoryLinkList:成功销毁链表\n");
    L->next = NULL;
}