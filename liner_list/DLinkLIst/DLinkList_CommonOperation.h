#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//双链表的定义
typedef struct DNode
{
    int data;
    struct DNode *next, *prior;
} DNode, *DLinkList;

// 双链的基本操作:

// InitDLinkList_tail(&L):初始化表;构造一个空的双链表.
DLinkList InitDLinkList_tail(DLinkList L)
{
    printf("InitDLinkList_tail：开始初始化双链表\n");
    L = (DNode *)malloc(sizeof(DNode)); //构建双链表头结点
    DNode *r = L, *s;
    int x;
    printf("InitDLinkList_tail：请输入第一个双链结点中想要存储的数据(9999为结束输入):\n");
    scanf("%d", &x);
    L->prior = NULL;
    L->next = NULL;   //头结点next指针置NULL,防止x=9999情况next为野指针
    while (x != 9999) //循环建立双链表直到9999退出返回双链表L
    {
        s = (DNode *)malloc(sizeof(DNode)); //为新建的双向结点初始化空间
        s->data = x;                        //为新结点初始化数据x
        r->next = s;                        //让前驱结点的next指向s
        s->prior = r;                       //让新结点的prior指向前驱结点
        s->next = NULL;                     //让新结点的next指向NULL
        r = s;                              //移动r指向新结点
        printf("InitDLinkList_tail：请输入当前双链结点中想要存储的数据(9999为结束输入):\n");
        scanf("%d", &x);
    }
    printf("InitDLinkList_tail：双链表建立结束\n");
    return L;
}

// InitDLinkList_Head(&L):初始化表;构造一个空的双链表.//与尾插法建立双链表稍微有一点不同
DLinkList InitDLinkList_Head(DLinkList L)
{
    printf("InitDLinkList_Head：开始初始化双链表\n");
    L = (DNode *)malloc(sizeof(DNode)); //构建双链表头结点
    DNode *s = NULL;
    int x;
    printf("InitDLinkList_Head：请输入第一个双链结点中想要存储的数据(9999为结束输入):\n");
    scanf("%d", &x);
    L->data = true; //记录是否为第一个节点
    L->next = NULL; //头结点置空
    while (x != 9999)
    {
        s = (DNode *)malloc(sizeof(DNode)); //为新创建的结点分配空间
        s->data = x;                        //给要新创建的结点s的data赋值x
        s->next = L->next;                  //让s的next指向第一个结点
        if (L->data == false)               //确保下一个结点不是NULL
            L->next->prior = s;             //让第一个结点的prior指向s
        L->data = false;
        s->prior = L; //让s的prior指向头结点
        L->next = s;  //让头结点的next指向s
        s = NULL;     //重置s指针
        printf("InitDLinkList_Head：请输入当前双链结点中想要存储的数据(9999为结束输入):\n");
        scanf("%d", &x);
    }
    printf("InitDLinkList_Head：双链表建立结束\n");
    return L;
}

// Length(L):求表长;返回双链表L的长度,即L中元素的个数.
int Length(DLinkList L)
{
    int count = 0;      //计数器
    DNode *p = L->next; //将p指向第一个结点
    while (p)
    {
        count++;
        p = p->next;
    }
    printf("Length:当前列表中有%d个结点\n", count);
    return count; //返回当前双链表的结点个数
}

// LocateElem(L,e):按值查找操作;在表L中查找具有给定关键字的元素.
int LocateElem(DLinkList L, int e)
{
    DNode *p = L->next;
    while (p)
    {
        if (p->data == e)
        {
            printf("LocateElem:找到值%d\n", p->data);
            return p->data;
        }
        p = p->next;
    }
    printf("LocateElem:未在表中找到值%d\n", e);
    return -1;
}

// GetElem(L,i):按位查找;获取表L中第i个位置的元素的值.
DNode *GetElem(DLinkList L, int i)
{
    int pos = 1;
    DNode *p = L->next;
    if (i < 0 || i > Length(L)) //查找的i不合法或大于双链表结点数的情况
    {
        printf("GetElem:没有当前位置的结点!\n");
        p = NULL; //本来是指向第一个结点的,但第一个节点也有两种可能不存在或存在,统一情况指向NULL
        return p;
    }
    if (i == 0) //i为头结点的情况
    {
        printf("GetElem:所要查找的为头结点!\n");
        p = L;
        return p;
    }
    while (p) //在双链表中进行遍历查找直到p=NULL
    {
        if (pos == i) //当要遍历到的位置和要查找的位置相同时
        {
            printf("GetElem:找到第%d个结点,值为%d\n", pos, p->data);
            return p; //返回p指针
        }
        pos++;       //计数器加1
        p = p->next; //移动指针p至下一个节点
    }
}

// DLinkListInsert_head(&L,i,e):插入操作;在表L中的第i个位置插入指定元素e.
DLinkList DLinkListInsert_Head(DLinkList L, int i, int e)
{
    DNode *s = (DNode *)malloc(sizeof(DNode));
    DNode *p = GetElem(L, i - 1);
    s->data = e;
    if (!p) //判断GetElem返回的p指针是否为NULL
    {
        printf("DLinkListInsert_Head:没有当前位置!插入失败!\n");
        return L;
    }
    if (!p->next) //若p->next==NULL,即GetElem返回的p结点可能为头结点或尾结点.
    {
        s->next = p->next; //让新节点的next指向p的后继结点,当前即为NULL
        p->next = s;       //让p结点的next指向新结点
        s->prior = p;      //让新结点的prior指向p结点
        //所以此处的if删除了让p结点的后继结点指向新结点的操作,原因就是p结点可能后继结点不存在
        //自然也不存在prior域可以指向新结点
        printf("DLinkListInsert_Head:成功在结点%d前插入新结点值%d\n", i, e);
        return L;
    }
    s->next = p->next;  //让新结点next指向p的后继节点
    p->next->prior = s; //让p结点的后继结点的prior指向新结点
    s->prior = p;       //让新结点s的prior指向p结点
    p->next = s;        //让p结点的next指向新结点
    printf("DLinkListInsert_Head:成功在结点%d前插入新结点值%d\n", i, e);
    return L;
}

// DLinkListInsert_Tail(&L,i,e):插入操作;在表L中的第i个位置插入指定元素e.
DLinkList DLinkListInsert_Tail(DLinkList L, int i, int e)
{
    DNode *s = (DNode *)malloc(sizeof(DNode));
    DNode *p = GetElem(L, i); //与前插法相比就把i-1变成i
    s->data = e;
    if (!p) //判断GetElem返回的p指针是否为NULL
    {
        printf("DLinkListInsert_Head:没有当前位置!插入失败!\n");
        return L;
    }
    if (!p->next) //若p->next==NULL,即GetElem返回的p结点可能为头结点或尾结点.
    {
        s->next = p->next; //让新节点的next指向p的后继结点,当前即为NULL
        p->next = s;       //让p结点的next指向新结点
        s->prior = p;      //让新结点的prior指向p结点
        //所以此处的if删除了让p结点的后继结点指向新结点的操作,原因就是p结点可能后继结点不存在
        //自然也不存在prior域可以指向新结点
        printf("DLinkListInsert_Tail:成功在结点%d后插入新结点值%d\n", i, e);
        return L;
    }
    s->next = p->next;  //让新结点next指向p的后继节点
    p->next->prior = s; //让p结点的后继结点的prior指向新结点
    s->prior = p;       //让新结点s的prior指向p结点
    p->next = s;        //让p结点的next指向新结点
    printf("DLinkListInsert_Tail:成功在结点%d后插入新结点值%d\n", i, e);
    return L;
}

// DLinkListDelete(&L,i,&e):删除操作;删除表L中的第i个位置的元素,并用e返回删除元素的值.(返回指向被删除节点的指针)
DLinkList DLinkListDelete(DLinkList L, int i)
{
    DNode *del = GetElem(L, i);
    if (!del) //当del指向NULL,即双链表中不存在这个结点
    {
        printf("DLinkListDelete:错误!尝试删除不存在的结点!\n");
        return L;
    }
    if (!del->next && i == 0) //尝试删除头结点的情况
    {
        printf("DLinkListDelete:禁止尝试删除头结点!\n");
        return L;
    }
    if (!del->next) //删除尾结点的情况
    {
        del->prior->next = NULL;
        del->prior = NULL;
        printf("DLinkListDelete:成功删除尾结点%d其值为%d\n", i, del->data);
        free(del);
        return L;
    }
    //通常情况
    del->prior->next = del->next;
    del->next->prior = del->prior;
    del->next = NULL;
    del->prior = NULL;
    printf("DLinkListDelete:成功删除结点%d,其值为%d\n", i, del->data);
    free(del);
    return L;
}

// PrintDLinkList(L):输出操作;按前后顺序输出双链表L的所有元素值.
int PrintDLinkList(DLinkList L)
{
    DNode *p = L->next; //指向第一个结点
    int pos = 0;
    while (p)
    {
        pos++;
        printf("PrintDLinkList:结点%d的值为%d\n", pos, p->data);
        p = p->next;
    }
    if (pos == 0 && !p) //当为空表的情况//设置pos是因为上面的while执行完毕也会使得p=NULL
    {
        printf("PrintDLinkList:当前为空表!\n");
        return 0;
    }
    printf("PrintDLinkList:双链表所有元素输出完毕\n");
    return 0;
}

// Empty(L):判空操作;若L为空表,则返回true,否则返回false.
bool Empty(DLinkList L)
{
    if (!L->next) //双链表为空的情况,即头结点next指针指向NULL
    {
        printf("Empty:双链表为空!\n");
        return true;
    }
    printf("Empty:双链表不为空!\n");
    return false;
}

// DestoryDLinkList(&L):销毁操作;销毁双链表,并释放双链表L所占用的空间.
DLinkList DestoryDLinkList(DLinkList L)
{
    free(L);
    printf("DestoryDLinkList:成功销毁双链表!\n");
    return L;
}