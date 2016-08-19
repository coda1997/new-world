#include<iostream>
#include"time.h"
#define ERROR 0
#define OK 1
using namespace std;
typedef int Status;
/*
标准的无序列表的存储结构
*/
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node* next;
}Node;
typedef struct Node* LinkList;
Status GetElem(LinkList, int, ElemType*);
Status ListInsert(LinkList*, int, ElemType);
Status ListDelete(LinkList, int, ElemType*);
void CreateListHead(LinkList*, int);
void CreateListTail(LinkList*, int);
Status ClearList(LinkList);
int main() {

}
/*
初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
操作结果：用e返回L中第i个数据元素的值
这里的参数列表为LinkList（指针），int，以及ElemType的指针类型
*/
Status GetElem(LinkList L, int i, ElemType* e) {
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while (p&&j < i) {
        p = p->next;
        j++;
    }
    if (!p || j>i)
        return ERROR;
    *e = p->data;
    return OK;
}
/*
操作结果：在L中第i个结点位置之前插入新的数据元素e，L的长度加1
*/
Status ListInsert(LinkList *L, int i, ElemType e) {
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p&&j < i) {
        p = p->next;
        j++;
    }
    if (!p || j>i)
        return ERROR;
    s = (LinkList)malloc(sizeof(Node));//使用的是c标准函数MALLOC
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList L, int i, ElemType* e) {
    int j;
    LinkList p, q;
    p = L;
    j = 1;
    while (p&&j < i) {
        p = p->next;
        j++;
    }
    if (!p || j>i)
        return ERROR;
    q = p->next;//这里的q为i位置的结点
    p->next = q->next;
    *e = q->data;
    free(q);//释放当前结点（第i位置）
    return OK;
}
/*随机产生n个元素的值，建立带头结点的单链表L（头插法）*/
void CreateListHead(LinkList* L, int n) {
    LinkList p;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for (i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%1+1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateListTail(LinkList* L, int n) {
    LinkList p, r;
    int i;
    srand(time(0));
    (*L) = (LinkList)malloc(sizeof(Node));
    r = *L;
    for (i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 1 + 1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
/*
这里是清除链表里面的元素，而不是整个把链表从内存上删除，也就是说最后链表是个空表
*/
Status ClearList(LinkList *L) {
    LinkList p, q;//这里使用两个指针是为了传递下一个结点的作用
    p = (*L)->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;

}