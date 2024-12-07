#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
//#include<stdbool.h>

typedef struct {
    char id[20];    // ���
    char name[50];  // ����
    char phone[20]; // �绰����
    int duration;   // ����ʱ��
} Volunteer;

#define MAX_VOLUNTEERS 100 // ���10��־Ը��
Volunteer volunteers[MAX_VOLUNTEERS] = {
        {"1", "Сһ", "12345678901", 1},
        {"2", "С��", "12345678902", 2},
        {"3", "С��", "12345678903", 3},
        {"4", "С��", "12345678904", 4},
        {"5", "С��", "12345678905", 5},
        {"6", "С��", "12345678906", 6},
        {"7", "С��", "12345678907", 7},
        {"8", "С��", "12345678908", 8},
        {"9", "С��", "12345678909", 9},
        {"10", "Сʮ", "12345678910", 10}
    };
int count = 10; // ��ǰ־Ը������

//������
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

//����־Ը��
void addVolunteer() 
{
    if (count >= MAX_VOLUNTEERS) 
    {
        printf("־Ը������������\n");
        return;
    }


    int n;


    printf("������Ҫ��ӵ�־Ը��������");
    scanf_s("%d", &n);
    //count = count;

    for (int i = 0; i < n; i++) 
    {

        printf("�������%dλ־Ը�ߵı�š��������绰���룺", i + 1);
        scanf("%s %s %s", &volunteers[count].id, &volunteers[count].name, &volunteers[count].phone);
        
        if (WrongTest(&volunteers[count].id))
        {
            printf("��������ͬ�����������롣\n");
            return;
        }
        
        volunteers[count].duration = 0; // ��ʼֵΪ0
        count++;

    }
}

//����־Ը��
void insertVolunteer(int position) 
{
    if (count >= MAX_VOLUNTEERS)
    {
        printf("־Ը������������\n");
        return;
    }

    if (position < 0 || position > count) 
    {
        printf("λ�ò����ڡ�\n");
        return;
    }

    for (int i = count; i > position; i--) 
    {
        volunteers[i] = volunteers[i - 1];
    }
    printf("������־Ը�ߵı�š��������绰���룺");
    scanf("%s %s %s", &volunteers[position].id, &volunteers[position].name, &volunteers[position].phone);
    if (WrongTest(&volunteers[count].id))
    {
        printf("��������ͬ�����������롣\n");
        return;
    }

    volunteers[position].duration = 0; // ��ʼֵΪ0
    count++;
}

//�޸�־Ը��
void modifyVolunteer() 
{
    char id[20];
    printf("������Ҫ�޸ĵ�־Ը�߱�ţ�");
    getchar();
    gets(id);
    for (int i = 0; i < count; i++) 
    {
        if (!strcmp(id, volunteers[i].id))
        {
            printf("�������µı�š��������绰���룺");
            scanf("%s %s %s", volunteers[i].id, volunteers[i].name, volunteers[i].phone);
            printf("�������µ�־Ը����ʱ����");
            scanf("%d", &volunteers[i].duration);
            return;
        }
    }
    printf("δ�ҵ����Ϊ%d��־Ը�ߡ�\n", id);
}

//ɾ��

void deleteVolunteer() 
{
    char id[20];

    printf("������Ҫɾ����־Ը�߱�ţ�");
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


    printf("δ�ҵ����Ϊ%s��־Ը�ߡ�\n", id);
}


//չʾ

void printAllVolunteers() 
{
    printf("־Ը�����᣺\n");

    for (int i = 0; i < count; i++) 
    {
        printf("%s %s %s %d\n", volunteers[i].id, volunteers[i].name, volunteers[i].phone, volunteers[i].duration);
    }

    printf("��������%d\n", count);
}

//��ʱ������

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

    printAllVolunteers(); // ��ӡ�����Ľ��
}




int main() {
    int choice;
    while (1) {
        printf("1. ���־Ը����Ϣ\n");
        printf("2. ����־Ը����Ϣ\n");
        printf("3. �޸�־Ը����Ϣ\n");
        printf("4. ɾ��־Ը����Ϣ\n");
        printf("5. ��ӡ����־Ը����Ϣ\n");
        printf("6. ����־Ը����ʱ������\n");
        printf("0. �˳�\n");
        printf("��ѡ�������");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            addVolunteer();
            break;
        case 2:
            printf("���������λ�ã�");
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
            printf("��Ч��ѡ��\n");
        }
    }
    return 0;
}