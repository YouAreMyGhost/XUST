#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>

// ��������
void InsertSort(int* a, int n);
// ϣ������
void ShellSort(int* a, int n);
// ѡ������
void SelectSort(int* a, int n);
// ������
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);
// ð������
void BubbleSort(int* a, int n);

//// ��������ݹ�ʵ��

// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort1(int* a, int left, int right);

//// �������� �ǵݹ�ʵ��

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);
// ��������
void CountSort(int* a, int n);
void QuickSortNonR(int* a, int left, int right);
void Print(int* a, int n);
void TestOP();