#include<iostream>
#include"time.h"
#define ERROR 0
#define OK 1
using namespace std;
typedef int Status;
/*
��׼�������б�Ĵ洢�ṹ
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
��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
�����������e����L�е�i������Ԫ�ص�ֵ
����Ĳ����б�ΪLinkList��ָ�룩��int���Լ�ElemType��ָ������
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
�����������L�е�i�����λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
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
    s = (LinkList)malloc(sizeof(Node));//ʹ�õ���c��׼����MALLOC
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
    q = p->next;//�����qΪiλ�õĽ��
    p->next = q->next;
    *e = q->data;
    free(q);//�ͷŵ�ǰ��㣨��iλ�ã�
    return OK;
}
/*�������n��Ԫ�ص�ֵ��������ͷ���ĵ�����L��ͷ�巨��*/
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
������������������Ԫ�أ�������������������ڴ���ɾ����Ҳ����˵��������Ǹ��ձ�
*/
Status ClearList(LinkList *L) {
    LinkList p, q;//����ʹ������ָ����Ϊ�˴�����һ����������
    p = (*L)->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;

}