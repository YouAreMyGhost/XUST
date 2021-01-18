#include"BinaryTree.h"


BinaryTreeNode* CreatNode(int x)
{
	BinaryTreeNode* Node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	Node->val = x;
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}
void PrevOrder(BinaryTreeNode* root)
{
	if (root == NULL)
	{ 
		printf("# ");
		return;
	}
	printf("%c ",root->val);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void MidOrder(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	MidOrder(root->left);
	printf("%c ", root->val);
	MidOrder(root->right);
}
void PostOrder(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}
//树的大小

void TreeSize(BinaryTreeNode* root,int *psize)
{
	if (root == NULL)
		return;

	//int size = 0;
	else
	(*psize)++;
	TreeSize(root->left,psize);
	TreeSize(root->right,psize) ;
}
int TreeSize1(BinaryTreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return TreeSize1(root->left) + TreeSize1(root->right)+1;
}
int TreeLeafSize(BinaryTreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	 
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

void test1()
{
	BinaryTreeNode* A = CreatNode('A');
	BinaryTreeNode* B = CreatNode('B');
	BinaryTreeNode* C = CreatNode('C');
	BinaryTreeNode* D = CreatNode('D');
	BinaryTreeNode* E = CreatNode('E');
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PrevOrder(A);printf("\n");

	MidOrder(A);printf("\n");

	int size = 0;
	TreeSize(A, &size);
	printf("TreeSize:%d\n",size);
	 
	printf("TreeSize1:%d\n", TreeSize1(A));
	printf("TreeLeafSize:%d\n", TreeLeafSize(A));

}
int main()
{
	test1();
	return 0;
}


