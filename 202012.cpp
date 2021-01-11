#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main()
{
	int n = 0;
	int a[100] = { 1,1,2,2,3,3,4,4,5,6,6,7,7,8,8,9,9 };
	for (int i = 0; i < 99; i++)
	{
		n = n ^ a[i];
	}
	printf("%d", n);
	return 0;
}


//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main()
//{
//    int n=0;
//    int a[100];
//    scanf("%d", &a);
//    int len = strlen(a);
//    for (int i = 0; i < len; i++)
//    {
//        n = n ^ a[i];
//    }
//    printf("%d", n);
//    return 0;
//}
//
//int getStandard(int array[], int i, int j) 
//{
//    int key = array[i];
//    while (i < j) 
//    {
//        // 因为默认基准是从左边开始，所以从右边开始比较
//        // 当队尾的元素大于等于基准数据 时,就一直向前挪动 j 指针
//        while (i < j && array[j] >= key) 
//        {
//            j--;
//        }
//        // 当找到比 array[i] 小的时，就把后面的值 array[j] 赋给它
//        if (i < j) 
//        {
//            array[i] = array[j];
//        }
//        // 当队首元素小于等于基准数据 时,就一直向后挪动 i 指针
//        while (i < j && array[i] <= key) 
//        {
//            i++;
//        }
//        // 当找到比 array[j] 大的时，就把前面的值 array[i] 赋给它
//        if (i < j) 
//        {
//            array[j] = array[i];
//        }
//    }
//    // 跳出循环时 i 和 j 相等,此时的 i 或 j 就是 key 的正确索引位置
//    // 把基准数据赋给正确位置
//    array[i] = key;
//    return i;
//}
//void QuickSort(int array[], int low, int high) 
//{
//    //开始默认基准为 low
//    if (low < high) 
//    {
//        //分段位置下标
//        int standard = getStandard(array, low, high);
//        //递归调用排序
//        //左边排序
//        QuickSort(array, low, standard - 1);
//        //右边排序
//        QuickSort(array, standard + 1, high);
//    }
//}
//int main1()
//{
//    int array[] = { 49, 38, 65, 97, 76, 13, 27, 49, 10 };
//    int size = sizeof(array) / sizeof(int);
//    QuickSort(array, 0, size - 1);
//    for (int i = 0; i < size; i++)
//    {
//        printf("%d ", array[i]);
//    }
//}
//int YangHui(int a)
//{
//	int arr[100][300];
//	int a[1][1] = { 1 };
//	for (int i = 0; i < 100; i++)
//	{
//		for (int j = 0; j < 300; j += 2)
//		{
//			arr[i][0] = 1;
//			arr[i][j] = 1;
//		}
//	}
//	for (int i = 2; i <= 100; i++)
//	{
//		for (int j = 0; j <= i + 2; j++)
//		{
//			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1] + arr[i - 1][j - 2];
//		}
//	}
//	return arr[100][300];
//}
//int main()
//{
//	int arr[10][20];
//	int a[1][1] = { 1 };
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 20; j += 2)
//		{
//			arr[i][0] = 1;
//			arr[i][j] = 1;
//		}
//	}
//	
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//    int main()
//	{
//	    char a[100];
//		scanf("%s", &a);
//		int len = strlen(a);
//		for (int i = len - 1; i >= 0; i--)
//		{
//			printf("%c", a[i]);
//		}
//		
//		return 0;
//	}
//float BallJump(float jump)
//{
//    float ball = jump;
//    for (int i = 1; i <= 5; i++)
//    {
//		
//		ball += jump;
//		
//		jump = jump / 2;
//    }
//	ball -= (jump*2);
//	printf("%f\n%f", ball, jump);
//	return 1;
//}
//int main()
//{
//    int a;
//    scanf("%d", &a);
//	BallJump(a);
//    return 0;
//}
//int Fib(int f)
//{
//    int a = 1,b = 1;
//    int F;
//    if (f == 1 || f == 2)
//    {
//        return 1;
//    }
//
//    for (int i = 3; i <= f; i++)
//    {
//        F = a + b;
//        a = b;
//        b = F;
//    }
//    return F;
//
//}
//int main()
//{
//    int a;
//    scanf("%d", &a);
//    printf("%d", Fib(a));
//    return 0;
//}
//{
//	int bow;
//	int drink = 0;
//	scanf("%d", &bow);
//	while (bow >= 3)
//	{
//		drink+= bow / 3;
//		bow = bow / 3 + bow % 3;
//	}
//	if (bow == 2)
//	{
//		drink += 1;
//	}
//	printf("%d", drink);
//
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//int Strlen(char* arr)
//{
//	int len = 0;
//	while (arr[len] != '\0')
//	{
//		len++;
//	}
//	return len;
//}
//char* Strcpy(char* arr, char* arr1)
//{
//	assert(arr);
//	assert(arr1);
//	char* str = arr1;
//	int len = Strlen(arr);
//	for (int i = 0; i < len; i++)
//	{
//		arr1[i] = arr[i];
//	}
//	return str;
//}
//int main()
//{
//	char arr[1000] = "\0";
//	scanf("%s", &arr);
//	char arr1[1000] = "\0";
//	Strcpy(arr, arr1);
//	
//	printf("%s\n", arr1);
//	printf("%d\n", Strlen(arr1));
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i, j, n=0;
//	char ch, a[80], b[80];
//	ch = getchar();
//	for (i = 0; ch != '\n'; i++) 
//	{
//		a[i] = ch;
//		n++;
//		ch = getchar();
//	}
//	for (i = 0, j = n - 1; i < n; i++, j--)
//	{
//		b[j] = a[i];
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf("%c", b[i]);
//	}
//
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main() 
//{
//	char a1[100], a2[100];
//	scanf("%c", &a1);
//
//	int len = strlen(a1);
//	
//	for (int i = len - 1; i >= 0; i++)
//	{
//		for (int j = 0; j <= len - 1; j--)
//		{
//			a2[j] = a1[i];
//		}
//	}
//	for (int i = 0; i <= len - 1; i++)
//
//	{
//		printf("%c", a2);
//	}
//	return 0;
//}




//int temp;
//int a[10] = { 21,45,65,12,56,33,11,42,69,87 };
//for (int i = 0; i <10; i++)//第i次遍历
//{
//	for (int j = i + 1; j < 10 ; j++)
//		//第i次遍历，将从起始位置到末端这几个数字中最小的放在第i个位置
//	{
//		if (a[i] > a[j])//找到更小的就换
//		{
//			temp = a[j];
//			a[j] = a[i];
//			a[i] = temp;
//			
//		}
//	}
//}
//for (int i = 0; i < 10; i++)
//{
//	printf("%d ", a[i]);
//}


/*int a[20][20];
for (int i = 0; i < 20; i++)
{

	a[i][i] = 1;
	a[i][0] = 1;
}
for (int i = 2; i < 20; i++)
{
	for (int j = 1; j <= i - 1; j++)
	{
		a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
	}
}
for (int i = 0; i < 20; i++)
{
	for (int j = 0; j <= i; j++)
	{
		printf("%d ", a[i][j]);
	}
	printf("\n");
}*/
//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int a[n][n];
//	for (int i = 0; i < n; i++)
//	{
//		a[i][i] = 1;
//		a[i][0] = 1;
//	}
//	for (int i = 2; i < n; i++)
//	{
//		for (int j = 1; j < n; j++)
//		{
//			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//		}
//	}
//	for (int i = 0; i < n; i++) 
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//}

//void Killer(int X)
//{
//
//	for (X = 'A'; X <= 'D'; X++)
//	{
//		if ((X != 'A') + (X == 'C') + (X == 'D') + (X != 'D') == 3)
//		{
//			printf("凶手是%c", X);
//		}
//	}
//	}
//	int main()
//	{
//		int X=0;
//		Killer(X);
//		return 0;
//	}
