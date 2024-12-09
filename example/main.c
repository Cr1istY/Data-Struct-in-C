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


List GetName(List* L, char ID[20]);



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

void Get(List* L, List k)
{
	List p;

	p->grade = k->grade;
	p->group = k->group;
	strcpy(p->id, k->id);
	strcpy(p->name, k->name);


	return;
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
	
	
	int numbers_now, i, count;
	int a, j, h, e, f;
	float numbers_needed;
	numbers_now = Length(L);

	int* myArray = (int*)malloc(numbers_now * sizeof(int));
	//if (numbers_now <= 8)
	//{
	//	printf("�������㣡");
	//	return;
	//}


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

	if (k == 0)
	{
		k = (int)numbers_needed;
	}
	else
	{
		
		printf("������������ܵȷ�");
		return 0;
	}
	//�ж����ܲ��ܷ��ꣻ




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
List GetName(List* L, char ID[20])
{
	int j = 0;
	List p = (*L)->next;

	for (p; p != NULL; p = p->next)
	{
		if (ID == p->id)
		{
			return p;

		}


	}
	return NULL;

}

//�����������
void Output(List* L, int a)
{
	List p = (*L)->next;
	List H, G;
	List h;
	InitList(G);
	InitList(H);
	List r = H;



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

				Get(H, p);

				r->next = h;
				r = h;


			}
			p = p->next;

		}
		r->next = NULL;

		printf("\n�� %d ������У�");
		
		r = H->next;
		for (j = 1; j <= length / a; j++)
		{
			printf("%s", r->name);
			r = r->next;

		}

	}








	return;





}





int main(void)
{
	List L;
	InitList(&L);


	GetId(&L);

	//DelteData(&L);
	Drawing(&L);



	return 0;
}
