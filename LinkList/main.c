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

//尾插法建立单链表

bool ListInsertback(LinkList* L)
{
	LinkList p = (*L);
	LNode* k;
	int j = 1;
	int i = 1;
	int e = 0;

	for (j = 1; j > 0; j++, i++)
	{
		printf("请输入第 %d 位元素：\n", j);
		scanf_s("%d", &e);

		k = (LNode*)malloc(sizeof(LNode));

		k->data = e;
		p->next = k;
		p = k;

		printf("单链表当前长度为 %d , 是否退出\n", j);
		printf("yes == 0\n");
		scanf_s("%d", &i);
		if (i == 0)
		{
			break;
		}
		

	}

}

/*
void CreateListTail(LinkList* L)			//尾插法创建一个单链表
{
	int i, n;
	LinkList p, r;
	(*L) = (LinkList)malloc(sizeof(LNode));
	r = *L;											//r为指向尾部的节点的指针
	printf("请输入您要插入元素的个数：");
	scanf("%d", &n);
	printf("请输入你要插入的元素值(用空格隔开)：");
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));				//生成新节点
		scanf("%d", &p->data);
		r->next = p;									//将表尾终端节点的指针指向新节点
		r = p;											//将当前的新节点定义为表尾终端节点
	}
	r->next = NULL;										//表示单链表结束
}
*/

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

//后插操作，在p节点之后插入元素 e
bool InsertNextNode(LNode* p, int e)
{
	LNode* s;
	if (p == NULL)
	{
		return false;
	}
	s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
	{
		return false;
	}

	s->data = e;
	s->next = p->next;
	p->next = s;

	return true;
}

//前插操作
bool InsertBeforeNode(LNode* p, int e)
{
	LNode* s;
	if (p == NULL)
	{
		return false;
	}
	s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
	{
		return false;
	}

	//偷天换日，因为你不知道单链表的前一个元素的指针
	s->data = p->data;
	s->next = p->next;
	p->data = e;
	p->next = s;
	//非常巧妙的方法


}

//按位序删除节点
bool DelteLNode(LinkList* L)
{
	int i = 0;
	int j = 1;

	LinkList s = (*L);
	LNode* p;

	printf("请输入你想删除节点的位序：\n");
	scanf_s("%d", &i);

	if (i < 1)
	{
		return false;
	}

	while (j <= i)
	{
		s = s->next;
		j++;
	}

	if (s == NULL)
	{
		return false;
	}

	if (s->next == NULL)
	{
		free(s);
		return true;
	}
	
	p = s->next;
	s->data = p->data;
	s->next = p->next;

	free(p);
	p = NULL;

	return true;



}

//展示链表
bool ShowList(LinkList* L)
{
	LNode* p = (*L)->next;
	int j = 1;

	if (p == NULL)
	{
		printf("单链表为空表\n");
		return true;
	}

	while (p)
	{

		printf("第 %d 的元素为 %d\n", j, p->data);
		p = p->next;
		j++;
	}
	return true;

}

int main(void)
{
	//int i = 0;

	LinkList L;

	InItLinkList(&L);

	ListInsertback(&L);

	ListInsert(&L);

	ShowList(&L);

	DelteLNode(&L);

	ShowList(&L);

	//printf("%d", i);

	return 0;
}
