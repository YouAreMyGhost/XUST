#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int DataType;

typedef struct ListNode
{
    int val;
    struct ListNode* prev;
    struct ListNode* next;
}ListNode;

ListNode* ListCreate(DataType x)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->prev = NULL;
    node->next = NULL;
    node->val = x;
    return node;
}

ListNode* ListInit()
{
    ListNode* phead = ListCreate(0);
    phead->next = phead;
    phead->prev = phead;
    return phead;
}

void ListDestory(ListNode* phead)
{
    assert(phead);
    ListNode* cur = phead;
    while (cur != phead)
    {
        ListNode* Next = cur->next;
        free(cur);
        cur = Next;
    }
    phead->next = phead;
    phead->prev = phead;
}

void ListPrint(ListNode* phead)
{
    printf("head<->");
    assert(phead);
    ListNode* cur = phead->next;
    while (cur != phead)
    {
        
        printf("%d<->", cur->val);
        cur = cur->next;
    }
    printf("head");
    printf("\n");
}

void ListPushBack(ListNode* phead, DataType x)
{
    assert(phead);
    ListNode* tail = phead->prev;
    ListNode* newNode = ListCreate(x);
    newNode->prev = tail;
    tail->next = newNode;
    newNode->next = phead;
    phead->prev = newNode;
}

void ListPopBack(ListNode* phead)
{
    assert(phead);
    assert(phead->prev != phead);
    ListNode* tail = phead->prev;
    phead->prev = tail->prev;
    tail->prev->next = phead;
    free(tail);
    tail = NULL;
}

void ListPushFront(ListNode* phead, DataType x)
{
    assert(phead);
    ListNode* newNode = ListCreate(x);
    ListNode* first = phead->next;
    phead->next = newNode;
    newNode->prev = phead;

    newNode->next = first;
    first->prev = newNode;
}

void ListPopFront(ListNode* phead)
{
    assert(phead);
    assert(phead->prev != phead);
    ListNode* first = phead->next;
    ListNode* second = phead->next->next;
    phead->next = second;
    second->prev = phead;
    free(first);
    first = NULL;
}

ListNode* ListFind(ListNode* phead, DataType x)
{
    assert(phead);
    ListNode* cur = phead->next;

    while (phead->prev != phead)
    {
       
        if (cur->val == x)
        {
            return cur;
        }
        else
        {
            cur=cur->next;
        }
    }
    return NULL;
}

void ListInsert(ListNode* pos, DataType x)
{
    assert(pos);
    ListNode* newNode = ListCreate(x);
    ListNode* posPrev = pos->prev;
    newNode->next = pos;
    pos->prev = newNode;

    posPrev->next = newNode;
    newNode->prev = posPrev;
}

void ListErase(ListNode* pos)
{
    assert(pos);
    ListNode* posNext = pos->next;
    ListNode* posPrev = pos->prev;
    posPrev->next = posNext;
    posNext->prev = posPrev;
    free(pos);
}

void test1()
{
    ListNode* phead = ListInit();
    ListPushBack(phead, 4);
    ListPushBack(phead, 3);
    ListPushBack(phead, 2);
    ListPushBack(phead, 1);
    printf("尾插：");
    ListPrint(phead);

    ListPopBack(phead);
    printf("尾删：");
    ListPrint(phead);

    ListPushFront(phead, 3);
    ListPushFront(phead, 2);
    ListPushFront(phead, 1);
    printf("头插：");
    ListPrint(phead);

    ListPopFront(phead);
    printf("头删：");
    ListPrint(phead);

    ListInsert(phead->next->next->next, 0);
    ListInsert(phead->next->next->next->next->next, 0);
    printf("中间插入：");
    ListPrint(phead);

    ListErase(phead->next->next->next->next);
    printf("中间删除：");
    ListPrint(phead);
}
int main()
{
    test1();

    return 0;

}



