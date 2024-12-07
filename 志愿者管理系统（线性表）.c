#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
//#include<stdbool.h>

typedef struct {
    char id[20];    // 编号
    char name[50];  // 姓名
    char phone[20]; // 电话号码
    int duration;   // 服务时长
} Volunteer;

#define MAX_VOLUNTEERS 100 // 最多10名志愿者
Volunteer volunteers[MAX_VOLUNTEERS] = {
        {"1", "小一", "12345678901", 1},
        {"2", "小二", "12345678902", 2},
        {"3", "小三", "12345678903", 3},
        {"4", "小四", "12345678904", 4},
        {"5", "小五", "12345678905", 5},
        {"6", "小六", "12345678906", 6},
        {"7", "小七", "12345678907", 7},
        {"8", "小八", "12345678908", 8},
        {"9", "小九", "12345678909", 9},
        {"10", "小十", "12345678910", 10}
    };
int count = 10; // 当前志愿者数量

//检测错误
int WrongTest(char id[20])
{

    int i = 0;

    for (int i = 0; i < count; i++)
    {
        if (!strcmp(id, volunteers[i].id))
        {

            return 1;

        }
    }
    return 0;


}

//填入志愿者
void addVolunteer() 
{
    if (count >= MAX_VOLUNTEERS) 
    {
        printf("志愿者名册已满。\n");
        return;
    }


    int n;


    printf("请输入要添加的志愿者数量：");
    scanf_s("%d", &n);
    //count = count;

    for (int i = 0; i < n; i++) 
    {

        printf("请输入第%d位志愿者的编号、姓名、电话号码：", i + 1);
        scanf("%s %s %s", &volunteers[count].id, &volunteers[count].name, &volunteers[count].phone);
        
        if (WrongTest(&volunteers[count].id))
        {
            printf("输入编号相同，请重新输入。\n");
            return;
        }
        
        volunteers[count].duration = 0; // 初始值为0
        count++;

    }
}

//插入志愿者
void insertVolunteer(int position) 
{
    if (count >= MAX_VOLUNTEERS)
    {
        printf("志愿者名册已满。\n");
        return;
    }

    if (position < 0 || position > count) 
    {
        printf("位置不存在。\n");
        return;
    }

    for (int i = count; i > position; i--) 
    {
        volunteers[i] = volunteers[i - 1];
    }
    printf("请输入志愿者的编号、姓名、电话号码：");
    scanf("%s %s %s", &volunteers[position].id, &volunteers[position].name, &volunteers[position].phone);
    if (WrongTest(&volunteers[count].id))
    {
        printf("输入编号相同，请重新输入。\n");
        return;
    }

    volunteers[position].duration = 0; // 初始值为0
    count++;
}

//修改志愿者
void modifyVolunteer() 
{
    char id[20];
    printf("请输入要修改的志愿者编号：");
    getchar();
    gets(id);
    for (int i = 0; i < count; i++) 
    {
        if (!strcmp(id, volunteers[i].id))
        {
            printf("请输入新的编号、姓名、电话号码：");
            scanf("%s %s %s", volunteers[i].id, volunteers[i].name, volunteers[i].phone);
            printf("请输入新的志愿服务时长：");
            scanf("%d", &volunteers[i].duration);
            return;
        }
    }
    printf("未找到编号为%d的志愿者。\n", id);
}

//删除

void deleteVolunteer() 
{
    char id[20];

    printf("请输入要删除的志愿者编号：");
    getchar();
    gets(id);

    for (int i = 0; i < count; i++) 
    {
        if (!strcmp(id, volunteers[i].id))
        {
            for (int j = i; j < count - 1; j++) 
            {
                volunteers[j] = volunteers[j + 1];
            }
            count--;
            return;
        }
    }


    printf("未找到编号为%s的志愿者。\n", id);
}


//展示

void printAllVolunteers() 
{
    printf("志愿者名册：\n");

    for (int i = 0; i < count; i++) 
    {
        printf("%s %s %s %d\n", volunteers[i].id, volunteers[i].name, volunteers[i].phone, volunteers[i].duration);
    }

    printf("总人数：%d\n", count);
}

//按时长排序

void sortVolunteersByDuration() 
{
    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = 0; j < count - i - 1; j++) 
        {
            if (volunteers[j].duration > volunteers[j + 1].duration) 
            {
                Volunteer temp = volunteers[j];
                volunteers[j] = volunteers[j + 1];
                volunteers[j + 1] = temp;
            }
        }
    }

    printAllVolunteers(); // 打印排序后的结果
}




int main() {
    int choice;
    while (1) {
        printf("1. 添加志愿者信息\n");
        printf("2. 插入志愿者信息\n");
        printf("3. 修改志愿者信息\n");
        printf("4. 删除志愿者信息\n");
        printf("5. 打印所有志愿者信息\n");
        printf("6. 根据志愿服务时长排序\n");
        printf("0. 退出\n");
        printf("请选择操作：");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            addVolunteer();
            break;
        case 2:
            printf("请输入插入位置：");
            int position;
            scanf_s("%d", &position);
            insertVolunteer(position);
            break;
        case 3:
            modifyVolunteer();
            break;
        case 4:
            deleteVolunteer();
            break;
        case 5:
            printAllVolunteers();
            break;
        case 6:
            sortVolunteersByDuration();
            break;
        case 0:
            return 0;
        default:
            printf("无效的选择。\n");
        }
    }
    return 0;
}