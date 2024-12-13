#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <string.h>

typedef struct Node {
	char name[20];
	char id[20];
	int group;
	int grade;
	struct Node* next;
}Node, *List;

int end = 0;

//��ʼ��
void InitList(List* L)
{
	(*L) = (List)malloc(sizeof(Node));
	if (!L)
	{
		printf("\nWrong!!!!");
		return;
	}
	(*L)->next = NULL;
	return;
}

int ClearList(List* L)					//�����������ɾ��
{
	List p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);							//ѭ��������ͷŸ����ڵ�
		p = q;
	}
	(*L)->next = NULL;					//��ͷ�ڵ��next�ÿ�
	return 0;
}


//����������
int Length(List* L)
{
	int length = 0;
	List p;
	p = (*L)->next;
	while (p)
	{
		p = p->next;
		length++;
	}


	return length;

}

//����¼�빦�ܡ�ͨ������¼������ݽ����������ͱ�š�
void GetId(List* L)
{
	int i = 0;
	int j = 0;
	List p, r;

	if (!L)
	{
		InitList(L);
	}
	
	r = (*L);
	printf("������Ҫ��¼�˶�Ա�ĸ�����");
	scanf("%d", &i);
	
	if (i < 8)
	{
		printf("��������˶�Ա����8��!\n");
		return;
	}

	for (j = 0; j < i; j++)
	{
		p = (List)malloc(sizeof(Node));
		printf("\n������� %d ���˶�Ա�������ͱ�ţ�", j + 1);
		scanf("%s %s", p->name, p->id);
		p->grade = 0;
		p->group = 0;

		r->next = p;
		r = p;
	}

	r->next = NULL;

	return;
}

List Get(List* L, List k)
{
	List p;
	p = (List)malloc(sizeof(Node));
	p->grade = k->grade;
	p->group = k->group;
	strcpy(p->id, k->id);
	strcpy(p->name, k->name);
	return p;
}


//����¼�빦�ܡ�ͨ������¼��ɼ���
void GetGrade(List* L)
{
	int i = 0;
	List p;
	p = (*L)->next;

	while (p)
	{
		printf("\n����������Ϊ��%s�����Ϊ: %s����ѡ�ֵĳɼ���", p->name, p->id);
		scanf("%d", &p->grade);
		p = p->next;
	}
	return;
}

//�޸ĵ�����ĳ���ڵ��ֵ
void GetGroup(List* L, int l, int k)
{
	int i = 0;
	List p = (*L)->next;

	for (i = 1; i < l; i++)
	{
		p = p->next;

	}

	p->group = k;

	return;

}

//����ɾ���Ĺ��ܡ�ͨ������¼��ѡ�ֵ��������ţ�Ȼ���������ɾ����Ӧ�����ݡ�
void DelteData(List* L)
{
	char e[20];
	int node = 0;
	List p = (*L)->next;
	List q = NULL;
	printf("\n����������ɾ�����˶�Ա�ı��:");
	scanf("%s", e);

	while (p)
	{
		if (!strcmp(p->id, e))
		{
			printf("�ҵ��ˣ���ţ�%s��������%s\n", p->id, p->name);
			if (p->next == NULL)
			{
				p = NULL;
				free(p);
				q->next = p;
			}
			else
			{
				q = p->next;
				p = q;
				free(q);
			}
			printf("ɾ�����\n");
			return;
		}
		q = p;

		p = p->next;

	}
	printf("û������˶�!!!\n");

	return;

}


//��ǩ����
int Drawing(List* L)
{
	List p = (*L)->next;
	
	
	int numbers_now, i;
	int a, j, h, e, f;
	float numbers_needed;
	numbers_now = Length(L);

	int* myArray = (int*)malloc(numbers_now * sizeof(int));
	if (numbers_now <= 8)
	{
		printf("�������㣡");
		return 0;
	}


	printf("���� %d ����\n", numbers_now);
	printf("������ÿ���������Ĭ��Ϊ8�ˣ�������������0����");
	scanf("%d", &i);
	if (i == 0)
	{
		i = 8;
	}
	numbers_needed = numbers_now / i;  //����
	a = numbers_needed;
	double k = numbers_needed - a;



	if (k != 0)
	{
		printf("������������ܵȷ�");
		return 0;
	}
	//�ж����ܲ��ܷ��ꣻ

	

	printf("\n�� %d ��;\n", a);


	srand((unsigned)time(NULL));

	for (e = 0; e < numbers_now; e++)
	{
		h = rand() % numbers_now + 1;
		myArray[e] = h;
		for (f = 0; f < e; f++)
		{
			while (myArray[f] == myArray[e])
			{
				h = rand() % numbers_now + 1;
				myArray[e] = h;
				f = 0;
			}

		}

	}
	//������һ�����ظ������飬����������λ��


	j = 1;

	for (e = 0; e < numbers_now; e++)
	{

		GetGroup(L, myArray[e], j);
		j++;
		if (j > a)
		{
			j = 1;
		}

	}

	printf("\n");
	end = 1;
	printf("��ǩ��ɣ�\n");

	for (p; p != NULL; p = p->next)
	{
		printf("������%s ��ţ�%s ��ţ�%d ", p->name, p->id, p->group);
		printf("\n");

	}
	return a;
}

//�����˶�Ա
void GetName(List* L)
{
	char ID[20];
	int j = 0;
	List p = (*L)->next;

	printf("������Ҫ���ҵ��˶�Ա�ı�ţ�");
	scanf("%s", &ID);

	for (p; p != NULL; p = p->next)
	{
		if (!strcmp(p->id, ID))
		{

			printf("������%s,��ţ�%s����ţ�%d���ɼ���%d\n", p->name, p->id, p->group, p->grade);
			return;

		}


	}
	printf("δ�ҵ���ѡ��!\n");

	return;

}


List Max(List* L)
{
	List p = (*L)->next;
	List H, h;
	List max;
	InitList(&H);
	List r = H;

	int i = 0;
	int j = 0;
	int length = 0;
	length = Length(L);

	max = p->next;

	for (i = 1; i <= length; i++)
	{
		for (j = 1; j <= length; j++)
		{
			if (p->grade > max->grade)
			{
				max = p;
			}

			p = p->next;
		}

		h = (List)malloc(sizeof(Node));
		h = Get(&H, max);
		r->next = h;
		r = h;
		r->next = NULL;
		max->grade = -1;

		p = (*L)->next;
		max = p->next;
	}

	return H;

}


//�����������,a����������
void Output(List* L, int a)
{
	List p = (*L)->next;
	List H, G;
	List h;
	InitList(&G);
	InitList(&H);
	List r = H;
	List Other;
	InitList(&Other);
	List o = Other;
	List t;

	int i = 0;
	int j = 0;
	int length = 0;
	length = Length(L);

	for (i = 1; i <= a; i++)
	{


		for (j = 1; j <= length; j++)
		{
			if (p->group == i)
			{
				h = (List)malloc(sizeof(Node));

				h = Get(&H, p);

				r->next = h;
				r = h;
			}
			p = p->next;

		}
		r->next = NULL;

		printf("\n�� %d ������У�\n", i);

		r = H->next;
		for (j = 1; j <= length / a; j++)
		{
			printf("������%s���ɼ���%d\n", r->name, r->grade);
			r = r->next;

		}

		G = Max(&H);
		p = G->next;
		printf("�� %d ���ǰ����Ϊ��\n", i);
		for (j = 0; j < 3; j++)
		{
			printf("������ %s����ţ� %s, �ɼ�: %d\n", p->name, p->id, p->grade);

			p = p->next;

		}

		while (p)
		{

			t = (List)malloc(sizeof(Node));
			t = Get(&H, p);
			o->next = t;
			o = t;
			p = p->next;

		}
		ClearList(&H);
		InitList(&H);
		r = H;
		p = (*L)->next;
		printf("\n");

	}
	o->next = NULL;
	length = Length(&Other);
	
	if (Length > 3)
	{
		printf("�������е�ǰ�����У�\n");
		G = Max(&Other);
		p = G->next;
		i = 0;
		while (p && i < 3)
		{
			printf("������ %s����ţ� %s���ɼ��� %d\n", p->name, p->id, p->grade);
			p = p->next;
			i++;
		}
		return;
	}


	else
		return;
}

int main(void)
{
	List L;
	int i, group;
	InitList(&L);
	List p;
	p = (List*)malloc(sizeof(Node));
	char id[20];
	do
	{
		printf("��ӭ����У�˻ᾶ���������:\n");
		if (end == 0)
			printf("\t1.ѡ��¼��\n");
		else if (end == 1)
			printf("\t1.ѡ�ֳɼ�¼��\n");
		printf("\t2.ѡ��ɾ��\n");
		printf("\t3.��ǩ����\n");
		printf("\t4.����ѡ��\n");
		printf("\t5.�����������\n");
		printf("\t0.�˳�����\n");
		printf("***************************\n");
		printf("���������ѡ��:");
		scanf("%d", &i);
		switch (i)
		{
		//1����¼�빦�ܡ�ͨ������¼������ݽ����������ͱ�š�
		// �ɼ�¼��Ĺ��ܣ���Ҫ�ڳ�ǩ��ɺ󿪷š�
		// ����¼��Ĺ����ڳ�ǩ��Ӧ�ùرա�
		case 1:
			if (end == 0)
				GetId(&L);
			else if (end == 1)
				GetGrade(&L);
			break;

		//2����ɾ���Ĺ���
		case 2:
			DelteData(&L);
			break;
		//3��ǩ����
		case 3:
			if (end == 0)
				group = Drawing(&L);
			break;
		//4���ҹ���
		case 4:
			GetName(&L);
			break;
		//5�����������
		case 5:
			Output(&L, group);
			break;
		default:
			break;
		}


	} while (i);

	
	return 0;
}
