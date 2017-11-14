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
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...

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

    }
    return 0;
}
