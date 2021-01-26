#include"sortTest.h"


typedef struct Heap
{
	int* a;
	int size;
	int cap;
}Heap;

//交换
void Swap(int* p, int* q)
{
	int tmp = *q;
	*q = *p;
	*p = tmp;
}
//三数取中
int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else // a[begin] > a[mid]
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}
void Print(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
// 插入排序
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				//a[end+1] = a[end];
				Swap(&a[end], &a[end + 1]);
				--end;
			}
			else
			{
				break;
			}
		}
		//a[end + 1] = tmp;
	}
	return a;
}
// 希尔排序
void ShellSort(int* a, int n)
{
	assert(a);
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					//a[end+1] = a[end];
					Swap(&a[end], &a[end + gap]);
					end -= gap;
				}
				else
				{
					break;
				}
			}
			//a[end + 1] = tmp;
		}
	}
	return a;
}
//选择排序
void SelectSort(int* a, int n)
{
	assert(a);
	int end = n - 1, begin = 0;
	while (begin < end)
	{
		int min,max;
		min = max = begin;
		for (int i = begin+1; i <= end; i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}

		Swap(&a[begin], &a[min]);
		//防止第一个元素为max
		if (begin == max)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);

		begin++; end--;
	}
}
//堆排序
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//找出左右孩子中小的
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}
		//如果父亲大于孩子，则交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
//冒泡排序
void BubbleSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
	return a;
}

//// 快速排序递归实现

// 快速排序左右指针法
int PartSort1(int* a, int left, int right)
{
	//int key = a[right];
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[midIndex], &a[right]);
	int keyi = right;
	while (right > left)
	{
		while (right > left && a[left] <= a[keyi])  left++;
		while (right > left && a[right] >= a[keyi])  right--;
		Swap(&a[right], &a[left]);
	}

	Swap(&a[keyi], &a[right]);
	return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[midIndex], &a[right]);

	int key = a[right];
	
	while (right > left)
	{
		while (right > left && a[left] <= key)  left++;
		a[right] = a[left];
		while (right > left && a[right] >= key)  right--;
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[midIndex], &a[right]);

	int prev = left - 1;
	int cur = left;
	int keyindex = right;

	while (cur < right)
	{
		if (a[cur] < a[keyindex] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		++cur;
	}

	Swap(&a[++prev], &a[keyindex]);

	return prev;
}
void QuickSort1(int* a, int left, int right)
{
	assert(a);
	if (left >= right) return;
	
	int meet = PartSort1(a, left, right);
	QuickSort1(a, left, meet - 1);
	QuickSort1(a, meet + 1, right);
	return a;
}
void QuickSort2(int* a, int left, int right)
{
	assert(a);
	if (left >= right) return;

	int meet = PartSort2(a, left, right);
	QuickSort2(a, left, meet - 1);
	QuickSort2(a, meet + 1, right);
	return a;
}
void QuickSort3(int* a, int left, int right)
{
	assert(a);
	if (left >= right) return;

	int meet = PartSort1(a, left, right);
	QuickSort3(a, left, meet - 1);
	QuickSort3(a, meet + 1, right);
	return a;
}

//// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{

}

// 归并排序递归实现
void _MergeSort(int* a, int L,int R,int* tmp)
{
	if (L >= R)
		return;

	int M = (L + R) / 2;
	_MergeSort(a, L, M, tmp);
	_MergeSort(a, M + 1, R, tmp);

	int begin1 = L, end1 = M;
	int begin2 = M + 1, end2 = R;
	int i = L;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] > a[begin2])
			tmp[i++] = a[begin2++];
		else
			tmp[i++] = a[begin1++];
	}

	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	
	for (int i = L; i <= R; i++)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	return a;
	free(tmp);
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	
}
// 计数排序
void CountSort(int* a, int n)
{
	assert(a);
	
}
