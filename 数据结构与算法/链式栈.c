//
//  main.m
//  数据结构与算法
//
//  Created by Jianmei on 2017/11/14.
//  Copyright © 2017年 Jianmei. All rights reserved.
//

/*
#import <Foundation/Foundation.h>
#pragma mark 线性表之顺序存储结构
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int SElemType;
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
    
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
} LinkStack;

Status visit(SElemType c)
{
    printf("%d ",c);
    return OK;
}

//  构造一个空栈S
Status InitStack(LinkStack *S)
{
    S->top=(LinkStackPtr)malloc(MAXSIZE*sizeof(SElemType));
    if (!S->top) {
        return ERROR;
    }
    S->top = NULL;
    S->count = 0;
    return OK;
    
    
}

// 把S置为空栈
Status ClearStack(LinkStack *S)
{
    S->top=NULL;
    LinkStackPtr p,q;
    p=S->top;
    while (p) {
        q = p;
        p = p->next;
        free(p);
    }
    S->count = 0;
    return OK;
}
// 从栈底到栈顶依次对栈中每个元素显示
Status StackTraverse(LinkStack S)
{
    LinkStackPtr p;
    p = S.top;
    while(p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
Status StackEmpty(LinkStack S)
{
    if (S.count==0)
        return TRUE;
    else
        return FALSE;
}
//进栈操作
Status Push(LinkStack *S, SElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count ++;
    
    
    return OK;
}

//出栈操作
Status Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;
    if (StackEmpty(*S)) {
        return ERROR;
    }
    p = S->top;
    S->top = S->top->next;
    *e = p->data;
    free(p);
    S->count --;
    return OK;
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        int j;
        LinkStack s;
        int e;
        if(InitStack(&s)==OK)
            for(j=1;j<=10;j++)
                Push(&s,j);
        printf("栈中元素依次为：");
        StackTraverse(s);
        Pop(&s,&e);
        printf("弹出的栈顶元素 e=%d\n",e);
    }
    return 0;
}
*/
