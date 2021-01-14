#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int DataT;

typedef struct Stack
{
	int *a;
	int * top;//ջ���±�
	int * capacity;//Ŀ������
}Stack;

//��ʼ��
void StackInit(Stack* pst);
void StackDestroy(Stack* pst);
void StackPush(Stack* pst,DataT x);
void StackPop(Stack* pst);
int  StackSize(Stack* pst);
//����1Ϊ�գ�����0Ϊ�ǿ�
int StackEmpty(Stack* pst);
//��ȡջ��������
DataT StackTop(Stack* pst);
