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

int ClearList(List* L)					//单链表的整表删除
{
	List p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);							//循环，逐个释放各个节点
		p = q;
	}
	(*L)->next = NULL;					//将头节点的next置空
	return 0;
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
	
	if (i < 8)
	{
		printf("请输入的运动员大于8个!\n");
		return;
	}

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
	
	
	int numbers_now, i;
	int a, j, h, e, f;
	float numbers_needed;
	numbers_now = Length(L);

	int* myArray = (int*)malloc(numbers_now * sizeof(int));
	if (numbers_now <= 8)
	{
		printf("人数不足！");
		return 0;
	}


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



	if (k != 0)
	{
		printf("输入的人数不能等分");
		return 0;
	}
	//判断人能不能分完；

	

	printf("\n共 %d 组;\n", a);


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
void GetName(List* L)
{
	char ID[20];
	int j = 0;
	List p = (*L)->next;

	printf("请输入要查找的运动员的编号：");
	scanf("%s", &ID);

	for (p; p != NULL; p = p->next)
	{
		if (!strcmp(p->id, ID))
		{

			printf("姓名：%s,编号：%s，组号：%d，成绩：%d\n", p->name, p->id, p->group, p->grade);
			return;

		}


	}
	printf("未找到该选手!\n");

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


//输出晋级名单,a是输入组数
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

		printf("\n第 %d 组的人有：\n", i);

		r = H->next;
		for (j = 1; j <= length / a; j++)
		{
			printf("姓名：%s，成绩：%d\n", r->name, r->grade);
			r = r->next;

		}

		G = Max(&H);
		p = G->next;
		printf("第 %d 组的前三名为：\n", i);
		for (j = 0; j < 3; j++)
		{
			printf("姓名： %s，编号： %s, 成绩: %d\n", p->name, p->id, p->grade);

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
		printf("其他人中的前三名有：\n");
		G = Max(&Other);
		p = G->next;
		i = 0;
		while (p && i < 3)
		{
			printf("姓名： %s，编号： %s，成绩： %d\n", p->name, p->id, p->grade);
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
		printf("欢迎来到校运会径赛管理程序:\n");
		if (end == 0)
			printf("\t1.选手录入\n");
		else if (end == 1)
			printf("\t1.选手成绩录入\n");
		printf("\t2.选手删除\n");
		printf("\t3.抽签管理\n");
		printf("\t4.查找选手\n");
		printf("\t5.输入晋级名单\n");
		printf("\t0.退出程序\n");
		printf("***************************\n");
		printf("请输入你的选择:");
		scanf("%d", &i);
		switch (i)
		{
		//1数据录入功能。通过键盘录入的数据仅包括姓名和编号。
		// 成绩录入的功能，需要在抽签完成后开放。
		// 数据录入的功能在抽签后应该关闭。
		case 1:
			if (end == 0)
				GetId(&L);
			else if (end == 1)
				GetGrade(&L);
			break;

		//2数据删除的功能
		case 2:
			DelteData(&L);
			break;
		//3抽签管理
		case 3:
			if (end == 0)
				group = Drawing(&L);
			break;
		//4查找功能
		case 4:
			GetName(&L);
			break;
		//5输出晋级名单
		case 5:
			Output(&L, group);
			break;
		default:
			break;
		}


	} while (i);

	
	return 0;
}
