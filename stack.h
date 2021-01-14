#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataT;

typedef struct Stack
{
	int *a;
	int * top;//栈顶下标
	int * capacity;//目标容量
}Stack;

//初始化
void StackInit(Stack* pst);
void StackDestroy(Stack* pst);
void StackPush(Stack* pst,DataT x);
void StackPop(Stack* pst);
int  StackSize(Stack* pst);
//返回1为空，返回0为非空
int StackEmpty(Stack* pst);
//获取栈顶的数据
DataT StackTop(Stack* pst);
