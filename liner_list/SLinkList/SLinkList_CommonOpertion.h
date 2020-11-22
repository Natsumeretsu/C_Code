#define MaxSize 10
#define ElemType int

//定义静态链表
typedef struct{
    ElemType data;
    int next;
} SLinkList[MaxSize];