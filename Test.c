#include"sortTest.h"

void InsertSortTest()
{
	int a[] = { 22,55,66,99,77,88,33,44,11 };
	int n = sizeof(a) / sizeof(int);
	InsertSort(a, n);
	printf("≤Â»Î≈≈–Ú :");
	Print(a, n);
}
void ShellSortTest()
{
	int a[] = { 2,5,6,9,7,8,3,4,1,0,12,86,23 };
	int n = sizeof(a) / sizeof(int);
	ShellSort(a, n);
	printf("œ£∂˚≈≈–Ú :");
	Print(a, n);
}
void BubbleSortTest()
{
	int a[] = { 11,7,8,3,4,1,0,12,86,23 };
	int n = sizeof(a) / sizeof(int);
	BubbleSort(a, n);
	printf("√∞≈›≈≈–Ú :");
	Print(a, n);
}
void SelectSortTest()
{
	int a[] = { 11,7,8,3,4,1,0,12,86,23,9,115 };
	int n = sizeof(a) / sizeof(int);
	SelectSort(a, n);
	printf("—°‘Ò≈≈–Ú :");
	Print(a, n);
}
void MergeSortTest()
{
	int a[] = { 11,7,8,3,4,1,0,12,86,23,9,115,58,66 };
	int n = sizeof(a) / sizeof(int);
	MergeSort(a, n);
	printf("πÈ≤¢≈≈–Ú :");
	Print(a, n);
}
void QuickSortTest1()
{
	int a[] = { 11,7,8,3,4,1,0,12,86,23,9,115,58,66,89,558 };
	int n = sizeof(a) / sizeof(int);
	QuickSort1(a, 0, n-1);
	printf("øÏÀŸ≈≈–Ú1:");
	Print(a, n);
}
void QuickSortTest2()
{
	int a[] = { 11,7,8,3,4,1,0,12,86,23,9,115,58,66,89,558 };
	int n = sizeof(a) / sizeof(int);
	QuickSort2(a, 0, n - 1);
	printf("øÏÀŸ≈≈–Ú2:");
	Print(a, n);
}
void QuickSortTest3()
{
	int a[] = { 11,7,8,3,4,1,0,12,86,23,9,115,58,66,89,558 };
	int n = sizeof(a) / sizeof(int);
	QuickSort3(a, 0, n - 1);
	printf("øÏÀŸ≈≈–Ú3:");
	Print(a, n);
}
void HeapSortTest()
{
	int a[] = { 11,7,8,3,4,1,0,12,86,23,9,115,58,66,89,558,41,233,999 };
	int n = sizeof(a) / sizeof(int);
	QuickSort3(a, 0, n - 1);
	printf("∂—≈≈–Ú   :");
	Print(a, n);
}
// ≤‚ ‘≈≈–Úµƒ–‘ƒ‹∂‘±»
void TestOP()
{
	srand(time(0));
	const int N = 10000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort1(a5, 0, N - 1);
	int end5 = clock();
	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();
	int begin7 = clock();
	BubbleSort(a7, N);
	int end7 = clock();
	printf("InsertSortTime:%d ms\n", end1 - begin1);
	printf("ShellSortTime :%d ms\n", end2 - begin2);
	printf("SelectSortTime:%d ms\n", end3 - begin3);
	printf("HeapSort      :%d ms\n", end4 - begin4);
	printf("QuickSort     :%d ms\n", end5 - begin5);
	printf("MergeSortTime :%d ms\n", end6 - begin6);
	printf("BubbleSortTime:%d ms\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}
int main()
{
	InsertSortTest();
	ShellSortTest();
	BubbleSortTest();
	SelectSortTest();
	MergeSortTest();
	QuickSortTest1();
	QuickSortTest2();
	QuickSortTest3();
	HeapSortTest();

	TestOP();
	return 0;
}