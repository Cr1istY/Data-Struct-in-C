#include <stdio.h>
#include <malloc.h>

#define INITMAXSIZE 5

//定义顺序表
typedef struct {
	int* data;
	int Length;
	int MAXSIZE;
}SqList;

//初始化顺序表
void InitSqList(SqList *L)
{
	L->data = (int*)malloc(INITMAXSIZE * sizeof(int));
	//L->data[0] = 1;
	L->Length = 0;
	L->MAXSIZE = INITMAXSIZE;
}

//动态增加顺序表长度
void IncreaseSize(SqList* L, int len)
{
	int* p = L->data;
	int i = 0;
	L->data = (int*)realloc(p, (L->MAXSIZE + len) * sizeof(int));
	//L->data[0] = 2;
	//L->data = (int*)malloc(sizeof(int) * (L->MAXSIZE + len));
	//for (i = 0; i < L->Length; i++)
	//{
	//	L->data[i] = p[i];
	//}
	L->MAXSIZE = L->MAXSIZE + len;
	//realloc 分配成功自动将p指向NULL
	//free(p);
}

//插入  在顺序表L的第i位插入e元素
void ListInsert(SqList* L, int i, int e)
{
	IncreaseSize(L, 1);

	int j = L->Length - 1;

	for (j; j >= i; j--)
	{
		L->data[j] = L->data[j - 1];
	}

	L->data[i - 1] = e;

	//int* p = &L->data[i - 1];
	//L->data[i - 1] = e;
	//for (j = 0; j < L->Length - i; j++)
	//{
	//	L->data[i + j] = p[j];
	//}
	//
	//free(p);

}

//输入顺序表
void IntList(SqList* L)
{
	int i = 0;
	int j = 0;

	for (i = 0; i <= L->MAXSIZE; i++)
	{

		if (i == L->MAXSIZE)
		{
			printf("表已满，请输入扩容数\n");
			scanf_s("%d", &j);
			if (j != 0 && j > 0)
			{
				IncreaseSize(L, j);
			}
			else
			{
				break;
			}
		}

		printf("输入%d位的值：", i + 1);
		scanf_s("%d", &j);

		if (j < 0)
		{
			break;
		}
		else
		{
			L->data[i] = j;
			L->Length++;
		}
	}

}

//展示顺序表中的数据
void ShowList(SqList* L)
{
	int i = 0;
	for (i = 0; i < L->Length; i++)
	{
		printf("第%d位的元素为： %d\n", i + 1, L->data[i]);

	}


}

//删除第i位的元素
void DelteList(SqList* L)
{
	int i = 0;
	int j = 0;
	
	printf("请输入想删除元素的位数\n");
	scanf_s("%d", &i);

	for (j = i - 1; j < L->Length - 1; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	
	L->Length--;
}

//按位查找
void FindByLocation(SqList* L)
{
	int n = 0;

	printf("请输入要查找元素的位置\n");

	scanf_s("%d", &n);

	if (n > L->Length)
	{
		printf("Wrong!");
	}
	else
		printf("第 %d 位的元素为 %d\n", n, L->data[n - 1]);

}

//按元素查找
void FindLocation(SqList* L)
{
	int i = 0;
	int j = 0;
	printf("请输入要查找什么元素\n");
	scanf_s("%d", &i);
	for (j = 0; j <= L->Length; j++)
	{
		if (j == L->Length)
		{
			printf("Wrong！\n");
			break;
		}

		else if (i == L->data[j])
		{
			printf("您要查找的元素 %d 位于第 %d 位", i, j + 1);
			break;
		}


		
	}


}


int main(void)
{
	
	SqList L;
	InitSqList(&L);

	IntList(&L);

	//DelteList(&L);

	ShowList(&L);

	FindByLocation(&L);

	FindLocation(&L);

	return 0;
}
