//��Ŀ���ƣ�ѧ������ϵͳ
//��Ŀ��Դ��ChatGPT
//��Ŀ��ţ�001
//��ϵ�ˣ��ܱ�binyinyuan@foxmail.com

//��Ŀ����������һ��������ѧ������ϵͳ�����ǿ��Ը��ݸ�ϵͳ��ӡ�ɾ������ѯ�͸���ѧ���������Ϣ�ͳɼ�

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  _CRT_SECURE_NO_WARNINGS
#define max_number 1000 //ѧ���������

typedef struct {
	int id;
	char name[50];// ���49���ַ���һ���ַ�2���ֽڣ�Ҳ����16���ء�����һ����2~3���ֽڣ�Ӣ��ÿ����ĸΪһ���ֽ�
	int age;
	char gender[10];
	float grade;
}Student;// ����Student�Ľṹ��

Student students[max_number];
int student_count = 0;//ȫ�ֱ���

void add_student()
{
	if (student_count >= max_number)
	{
		printf("���ݿ�����.\n");
		return;
	}

	Student newStudent;//����newStudent�Ľṹ��
	printf("������ѧ��ID��");
	scanf("%d", &newStudent.id);
	printf("������ѧ�����֣�");
	scanf("%s", &newStudent.name);
	printf("������ѧ�����䣺");
	scanf("%d", &newStudent.age);
	printf("������ѧ���Ա�");
	scanf("%s", &newStudent.gender);
	printf("������ѧ���ɼ���");
	scanf("%f", &newStudent.grade);

	students[student_count] = newStudent;
	student_count++;
	printf("\n �����ѧ���ɹ���\n");
}

void delete_student()
{
	int id = 0;
	printf("������Ҫɾ��ѧ����ID��");
	scanf("%d", &id);

	for (int i = 0;i <= student_count; i++)
	{
		if (students[i].id == id)
		{
			for (int j = i; j < student_count - 1; j++)
			{
				students[j] = students[j + 1];
			}
		}
	}
	student_count--;
	printf("ɾ���ɹ�����\n");
	return;
}

void update_student()
{
	int id = 0;
	printf("��������Ҫ����ѧ��ID");
	scanf("%d", &id);
	
	for (int i = 0; i < student_count; i++)
	{
		if(students[i].id == id)
		{
			printf("�������µ�ѧ�����ƣ�");
			scanf("%s", &students[i].name);

			printf("�������µ�ѧ������");
			scanf("%d", &students[i].age);

			printf("�������µ�ѧ���Ա�");
			scanf("%s", &students[i].gender);

			printf("�������µ�ѧ���ɼ�");
			scanf("%f", &students[i].grade);

			printf("��Ϣ���³ɹ�����\n");
			return;
		}
	}
	printf("ID������������ȷ��ID��\n");
}

void view_student()
{
	int id;
	printf("��������Ҫ��ѯѧ����ID��");
	scanf("%d", &id);

	for (int i = 0; i < student_count; i++)
	{
		if (students[i].id == id)
		{
			printf("ѧ�����ƣ�%s\n", students[i].name);
			printf("ѧ�����䣺%d\n", students[i].age);
			printf("ѧ���Ա�%s\n", students[i].gender);
			printf("ѧ���ɼ���%f\n", students[i].grade);
			
			printf("��Ϣ��ѯ�ɹ�����\n");
			return;
		}
	}
	printf("ID������������ȷ��ID��\n");
}

void view_all_student()
{	
	if (student_count == 0)
	{
		printf("��Ϣ��ѯʧ�ܣ�����ǰ����ѧ������Ϊ0����");
		return;
	}
	for (int i = 0; i < student_count; i++)
	{
		printf("ѧ�����ƣ�%s��ѧ�����䣺%d��ѧ���Ա�%s��ѧ���ɼ���%f", students[i].name, students[i].age, students[i].gender, students[i].grade);
	}
	printf("��Ϣ��ѯ�ɹ�����\n");
	return;
}

int main()
{
	int choice=0;
	//int a = 1;
	//printf("%d\n", a);//��ӡһ��Ҫʹ��˫����
	//return 0;
	
	while (1)
	{
		printf("\n------ѧ������ϵͳ------\n");
		printf("����ѡ��һ�²�����\n");
		printf("1�����ѧ����Ϣ\n");
		printf("2��ɾ��ѧ����Ϣ\n");
		printf("3������ѧ����Ϣ\n");
		printf("4������ѧ����Ϣ\n");
		printf("5����������ѧ��\n");
		printf("6���˳�\n");

		printf("���������Ĳ���ѡ�");
		scanf("%d", &choice);//˫�����ڲ������뺺��������ֻ�������ʽ�������ַ�

		switch (choice) //�������ֱ��ִ�У���whileѭ���л�ֱ��������������һ��ѭ����
		{
			case 1:
				add_student();
				break;
			case 2:
				delete_student();
				break;
			case 3:
				update_student();
				break;
			case 4:
				view_student();
				break;
			case 5:
				view_all_student();
				break;
			case 6:
				exit(0);
			default:
				printf("��Чѡ��������ѡ��!\n");
		}
	}
	
	return 0;
}