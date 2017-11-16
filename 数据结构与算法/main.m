//
//  main.m
//  数据结构与算法
//
//  Created by Jianmei on 2017/11/14.
//  Copyright © 2017年 Jianmei. All rights reserved.
//

#import <Foundation/Foundation.h>
#pragma mark 线性表之顺序存储结构
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
    
}Node;

typedef struct Node *LinkList;

Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

Status InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    if (!(*L)) {
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}
/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j=1;
    LinkList p;
    p = L->next;
    while (p && j<i) {
        p = p->next;
        ++j;
    }
    if (!p || j>i) {
        return ERROR;
    }
    *e = p->data;
    return OK;
    
}

/* 初始条件：线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(LinkList *L,int i,ElemType e)
{
    int j = 1;
    LinkList p,s;
    p = *L;
    while (p && j<i) {
        j++;
        p = p->next;
    }
    if (!p||j>i) {
        return ERROR;
    }
    s =(LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
    
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L, int i,ElemType *e)
{
    int j = 1;
    LinkList p,q;
    p = *L;
    
    while (p->next &&j<i) {
        p = p->next;
        j++;
    }
    if (!(p->next)||j>i) {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int locateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p = L->next;
    while (p) {
        i++;
        if (p->data == e) {
            return i;
        }
        p = p->next;
    }
    return 0;
    
}

/* 初始条件：线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L)
{
    LinkList p = L->next;
    while (p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
    
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead (LinkList *L,int n)
{
    LinkList p;
    int i;
    srand(time(0));                         /* 初始化随机数种子 */
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for (i = 0; i<n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
    
}
/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListFoot (LinkList *L,int n)
{
    LinkList p,r;
    int i;
    srand(time(0));                         /* 初始化随机数种子 */
    *L = (LinkList)malloc(sizeof(Node));
    r = *L;
    for (i = 0; i<n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    
}
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
/*
        LinkList L;
        ElemType e;
        Status i;
        int j,k;
        i=InitList(&L);
        printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
        for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
        printf("在L的表头依次插入1～5后：L.data=");
        ListTraverse(L);
        ListDelete(&L, 3, &e);
        ListTraverse(L);
 */
        LinkList L;
        int n;
        CreateListFoot(&L, 10);
        ListTraverse(L);

    }
    return 0;
}
