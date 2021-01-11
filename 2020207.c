#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//异或
int ContinuousXor(int* arr, int sz)
{
	int ret = 0;
	for (int i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	return ret;
}
//找出出现一次的数字
void FindOnce(int* arr, int sz, int* num1, int* num2)
{
	//先求出这个数组连续异或后的结果tmp
	int tmp = ContinuousXor(arr, sz);
	int index = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		//找出tmp为1的那一位	
		if ((tmp >> i) & 1 == 1)
		{
			index = i;
			break;
		}
	}
	for (i = 0; i < sz; i++)
	{
		//用第i位是否为1将数组分为两组分别异或	
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
	printf("在arr数组中%d与%d仅出现了一次\n", num1, num2);
	return 0;
}