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

//β�巨����������

bool ListInsertback(LinkList* L)
{
	LinkList p = (*L);
	LNode* k;
	int j = 1;
	int i = 1;
	int e = 0;

	for (j = 1; j > 0; j++, i++)
	{
		printf("������� %d λԪ�أ�\n", j);
		scanf_s("%d", &e);

		k = (LNode*)malloc(sizeof(LNode));

		k->data = e;
		p->next = k;
		p = k;

		printf("������ǰ����Ϊ %d , �Ƿ��˳�\n", j);
		printf("yes == 0\n");
		scanf_s("%d", &i);
		if (i == 0)
		{
			break;
		}
		

	}

}

/*
void CreateListTail(LinkList* L)			//β�巨����һ��������
{
	int i, n;
	LinkList p, r;
	(*L) = (LinkList)malloc(sizeof(LNode));
	r = *L;											//rΪָ��β���Ľڵ��ָ��
	printf("��������Ҫ����Ԫ�صĸ�����");
	scanf("%d", &n);
	printf("��������Ҫ�����Ԫ��ֵ(�ÿո����)��");
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));				//�����½ڵ�
		scanf("%d", &p->data);
		r->next = p;									//����β�ն˽ڵ��ָ��ָ���½ڵ�
		r = p;											//����ǰ���½ڵ㶨��Ϊ��β�ն˽ڵ�
	}
	r->next = NULL;										//��ʾ���������
}
*/

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

//����������p�ڵ�֮�����Ԫ�� e
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

//ǰ�����
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

	//͵�컻�գ���Ϊ�㲻֪���������ǰһ��Ԫ�ص�ָ��
	s->data = p->data;
	s->next = p->next;
	p->data = e;
	p->next = s;
	//�ǳ�����ķ���


}

//��λ��ɾ���ڵ�
bool DelteLNode(LinkList* L)
{
	int i = 0;
	int j = 1;

	LinkList s = (*L);
	LNode* p;

	printf("����������ɾ���ڵ��λ��\n");
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

//չʾ����
bool ShowList(LinkList* L)
{
	LNode* p = (*L)->next;
	int j = 1;

	if (p == NULL)
	{
		printf("������Ϊ�ձ�\n");
		return true;
	}

	while (p)
	{

		printf("�� %d ��Ԫ��Ϊ %d\n", j, p->data);
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
