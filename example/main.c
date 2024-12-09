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



//初始化
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


//计算链表长度
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

//数据录入功能。通过键盘录入的数据仅包括姓名和编号。
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
	printf("请输入要记录运动员的个数：");
	scanf("%d", &i);
	
	for (j = 0; j < i; j++)
	{
		p = (List)malloc(sizeof(Node));
		printf("\n请输入第 %d 个运动员的姓名和编号：", j + 1);
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


//数据录入功能。通过键盘录入成绩。
void GetGrade(List* L)
{
	int i = 0;
	List p;
	p = (*L)->next;

	while (p)
	{

		printf("\n请输入姓名为：%s，编号为: %s，的选手的成绩：", p->name, p->id);
		scanf("%d", &p->grade);
		
		p = p->next;


	}


	return;
}

//修改单链表某个节点的值
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

//数据删除的功能。通过键盘录入选手的姓名或编号，然后从链表中删除对应的数据。
void DelteData(List* L)
{
	char e[20];
	int node = 0;
	List p = (*L)->next;
	List q = NULL;
	printf("\n请输入你想删除的运动员的编号:");
	scanf("%s", e);

	while (p)
	{
		if (!strcmp(p->id, e))
		{
			printf("找到了，编号：%s，姓名：%s\n", p->id, p->name);
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
			printf("删除完成\n");
			return;
		}
		q = p;

		p = p->next;

	}
	printf("没有这个人儿!!!\n");

	return;

}


//抽签管理
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
	//	printf("人数不足！");
	//	return;
	//}


	printf("共有 %d 个人\n", numbers_now);
	printf("请输入每组的人数（默认为8人，不更改请输入0）：");
	scanf("%d", &i);
	if (i == 0)
	{
		i = 8;
	}
	numbers_needed = numbers_now / i;  //组数
	a = numbers_needed;
	double k = numbers_needed - a;

	if (k == 0)
	{
		k = (int)numbers_needed;
	}
	else
	{
		
		printf("输入的人数不能等分");
		return 0;
	}
	//判断人能不能分完；




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
	//生成了一个不重复的数组，包含了所有位置


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
	printf("抽签完成！\n");

	for (p; p != NULL; p = p->next)
	{
		printf("姓名：%s 编号：%s 组号：%d ", p->name, p->id, p->group);
		printf("\n");

	}



	return a;
}

//查找运动员
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

//输出晋级名单
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

		printf("\n第 %d 组的人有：");
		
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
