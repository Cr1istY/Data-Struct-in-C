/*
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

typedef struct LNode {

	int data;
	LNode* next;

}LNode, *LinkList;

//初始化一个带头节点的单链表
bool InItLinkList(LinkList L)
{
	L = (LNode*)malloc(sizeof(LNode));

	if (L == NULL)
	{
		return false;
	}

	else
	{
		L->next = NULL;
	}


}

int main(void)
{
	int i = 0;

	LinkList L;

	i = InItLinkList(L);
	
	printf("%d", i);

	return 0;
}

*/

/*

#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

typedef struct LNode {

	int data;
	struct LNode* next;

}LNode, *LinkList;

//typedef LNode* LinkList;

//初始化一个带头节点的单链表

bool InItLinkList(LinkList* L)
{
	(*L) = (LNode*)malloc(sizeof(LNode));

	if ((*L) == NULL)
	{
		return false;
	}

	else
	{
		(*L)->next = NULL;
		return true;
	}


}

//按照位序插入
bool ListInsert(LinkList* L)
{
	int i = 0;
	int j = 0;
	int k = 1;
	LinkList p = (*L);
	LinkList s;

	printf("请输入要插入的元素\n");
	scanf_s("%d", &i);
	printf("请输入要插入元素的位序\n");
	scanf_s("%d", &j);

	if (j <= 0)
		return false;

	while (p != NULL && k < j)
	{
		p = p->next;
		k++;

	}

	//k == j

	if (!p || k > j)
	{
		printf("插入失败\n");
		return false;
	}

	s = (LinkList)malloc(sizeof(LNode));
	s->data = i;

	s->next = p->next;
	p->next = s;

	return true;
}

//展示链表
bool ShowList(LinkList* L)
{
	LinkList p = (*L)->next;
	int i = 0;
	int j = 1;

	if (p == NULL)
	{
		return false;
	}

	for (p; p != NULL; p = p->next, j++)
	{

		printf("第 %d 的元素为 %d", j, p->data);

	}
	return true;

}

int main(void)
{
	//int i = 0;

	LinkList L;

	InItLinkList(&L);

	ListInsert(&L);

	ShowList(&L);

	//printf("%d", i);

	return 0;
}


*/