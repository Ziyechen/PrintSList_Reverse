#pragma once

#include <iostream>
#include <stack>
using namespace std;

//输入一个链表的头结点，从头到尾反过来打印每个结点的值
//链表结点定义如下:
struct ListNode
{
	int m_nKey;
	ListNode *m_pNext;

	ListNode(int data)
		:m_nKey(data)
		, m_pNext(NULL)
	{}
};

//递归实现
void PrintListReverse(ListNode *pHead)
{
	if (pHead == NULL)
		return;

	if (pHead->m_pNext)
	{
		PrintListReverse(pHead->m_pNext);
	}
	cout << pHead->m_nKey << " ";
}

//非递归实现
void PrintListReverse_NonR(ListNode *pHead)
{
	if (pHead == NULL)
		return;

	stack<ListNode *> s;

	ListNode *cur = pHead;
	while (cur)
	{
		s.push(cur);
		cur = cur->m_pNext;
	}

	while (!s.empty())
	{
		ListNode *tmp = s.top();
		s.pop();

		cout << tmp->m_nKey << " ";
	}
	cout << endl;
}

//向单链表中插入元素
void PushBack(ListNode *&pHead, int data)
{
	ListNode *tmp = new ListNode(data);

	if (pHead == NULL)
	{
		pHead = tmp;
	}
	else
	{
		ListNode *tail = pHead;
		while (tail->m_pNext != NULL)
		{
			tail = tail->m_pNext;
		}
		tail->m_pNext = tmp;
	}
}
//测试用例
void TestPrintListReverse()
{
	ListNode *pHead = NULL;
	PushBack(pHead, 1);
	PushBack(pHead, 2);
	PushBack(pHead, 3);
	PushBack(pHead, 4);
	PushBack(pHead, 5);

	//PrintListReverse(pHead);
	PrintListReverse_NonR(pHead);
}
