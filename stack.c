#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


typedef int DataT;

typedef struct Stack
{
	int* a;
	int top;//栈顶下标
	int capacity;//目标容量
}Stack;

//初始化
void StackInit(Stack* pst)
{
	assert(pst);
	pst->a = (int *)malloc(sizeof(DataT)*4);
	pst->top = 0;
	pst->capacity = 4;
}
//销毁
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

//入栈
void StackPush(Stack* pst,DataT x)
{
	assert(pst);
	//空间不够则增容
	if (pst->top == pst->capacity)
	{
		pst->capacity *= 2;
		DataT* tmp = (DataT*)realloc(pst->a, sizeof(DataT) * pst->capacity);
		if (tmp == NULL)
		{
			printf("内存不足\n");
			exit(-1);
		}
		else
		{
			pst->a = tmp;
		}
	}
	pst->a[pst->top] = x;
	pst->top++;
}
//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->top > 0);
	--pst->top;
}
int  StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}
//返回1为空，返回0为非空
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;
}
//获取栈顶的数据
DataT StackTop(Stack* pst) 
{
	assert(pst);
	assert(pst->top > 0);

	return pst->a[pst->top - 1];
}
void test1()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 5);
	StackPop(&st);

	//printf("%d",StackTop(&st));

	while (!StackEmpty(&st))
	{
		printf("%d ",StackTop(&st));
		StackPop(&st);
	}
	printf("\n");
}
int main()
{
	test1();
	return 0;
}