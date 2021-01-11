#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//���
int ContinuousXor(int* arr, int sz)
{
	int ret = 0;
	for (int i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	return ret;
}
//�ҳ�����һ�ε�����
void FindOnce(int* arr, int sz, int* num1, int* num2)
{
	//��������������������Ľ��tmp
	int tmp = ContinuousXor(arr, sz);
	int index = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		//�ҳ�tmpΪ1����һλ	
		if ((tmp >> i) & 1 == 1)
		{
			index = i;
			break;
		}
	}
	for (i = 0; i < sz; i++)
	{
		//�õ�iλ�Ƿ�Ϊ1�������Ϊ����ֱ����	
		if ((arr[i] >> index) & 1 == 1)
			*num1 ^= arr[i];
		else
			*num2 ^= arr[i];
	}
}

int main()
{
	int arr[] = { 4, 3, 3, 5, 6, 6, 7, 7 };
	int num1 = 0;
	int num2 = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	FindOnce(arr, sz, &num1, &num2);
	printf("��arr������%d��%d��������һ��\n", num1, num2);
	return 0;
}