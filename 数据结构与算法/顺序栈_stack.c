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
typedef struct
{
    SElemType data[MAXSIZE];
    int top;

}SqStack;

typedef struct Node *LinkList;
Status visit(SElemType c)
{
    printf("%d ",c);
    return OK;
}

//  构造一个空栈S
Status InitStack(SqStack *S)
{
//     S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType));
    S->top=-1;
    return OK;
}

// 把S置为空栈
Status ClearStack(SqStack *S)
{
    S->top=-1;
    return OK;
}
// 从栈底到栈顶依次对栈中每个元素显示
Status StackTraverse(SqStack S)
{
    int i;
    i=0;
    while(i<=S.top)
    {
        visit(S.data[i++]);
    }
    printf("\n");
    return OK;
}
//进栈操作
Status Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1) {
        return ERROR;
    }
    S->top ++;
    S->data[S->top] = e;

    return OK;
}

//出栈操作
Status Pop(SqStack *S, SElemType e)
{
    if (S->top == -1) {
        return ERROR;
    }
    e =  S->data[S->top] ;
    S->top --;
    return OK;
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        int j;
        SqStack s;
        int e;
        if(InitStack(&s)==OK)
            for(j=1;j<=10;j++)
                Push(&s,j);
        printf("栈中元素依次为：");
        StackTraverse(s);
        Pop(&s,&e);
    }
    return 0;
}

*/

