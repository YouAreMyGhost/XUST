#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataT;

typedef struct BinaryTreeNode
{
	DataT val;
	struct BinaryTreeNode* right;
	struct BinaryTreeNode* left;

}BinaryTreeNode;

void PrevOrder(BinaryTreeNode* root); 
void MidOrder(BinaryTreeNode* root);
void PostOrder(BinaryTreeNode* root);
void TreeSize(BinaryTreeNode*root,int *psize);
int TreeSize1(BinaryTreeNode* root);
int TreeLeafSize(BinaryTreeNode* root);


