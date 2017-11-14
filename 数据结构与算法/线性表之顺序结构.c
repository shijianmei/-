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
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
    
}SqList;


//获得元素操作
Status GetElem(SqList L,int i,ElemType *e)
{
    if (L.length==0 || i<1 || i>L.length) {
        return FALSE;
    }
    *e = L.data[i-1];
    return OK;
}

/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SqList *L,int i,ElemType e)
{
    int k;
    if (L->length==MAXSIZE)  /* 顺序线性表已经满 */
        return ERROR;
    if (i<1 || i>L->length+1)/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
        return ERROR;
    
    if (i<= L->length) {
        for (k = L->length-1; k>=i-1; k--) {
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1]=e;          /* 将新元素插入 */
    L->length++;
    
    return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList *L,int i, ElemType *e)
{
    int k;
    if (L->length == 0) {
        return ERROR;
    }
    if (i<1 || i>L->length) {
        return ERROR;
    }
    *e = L->data[i-1];
    if (i<L->length) {
        for (k=i; k<L->length; k++) {
            L->data[k-1] = L->data[k];
        }
    }
    
    L->length--;
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
        visit(L.data[i]);
    printf("\n");
    return OK;
}
/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList *L)
{
    L->length=0;
    return OK;
}

Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        
#pragma mark 顺序存储结构
        SqList L ;
        Status i;
        L.length = 0;
        printf("初始化L后：L.length=%d\n",L.length);
        for(int j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
        printf("在L的表头依次插入1～5后：L.data=");
        ListTraverse(L);
        int e;
        ListDelete(&L, 3, &e);
        ListTraverse(L);
        //        ListInsert(& list, 2, 23);
        
        //        ListTraverse(list);
        
    }
    return 0;
}

