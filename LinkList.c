/*
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

typedef struct LNode {

	int data;
	LNode* next;

}LNode, *LinkList;

//��ʼ��һ����ͷ�ڵ�ĵ�����
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

//��ʼ��һ����ͷ�ڵ�ĵ�����

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

//����λ�����
bool ListInsert(LinkList* L)
{
	int i = 0;
	int j = 0;
	int k = 1;
	LinkList p = (*L);
	LinkList s;

	printf("������Ҫ�����Ԫ��\n");
	scanf_s("%d", &i);
	printf("������Ҫ����Ԫ�ص�λ��\n");
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
		printf("����ʧ��\n");
		return false;
	}

	s = (LinkList)malloc(sizeof(LNode));
	s->data = i;

	s->next = p->next;
	p->next = s;

	return true;
}

//չʾ����
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

		printf("�� %d ��Ԫ��Ϊ %d", j, p->data);

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