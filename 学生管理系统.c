//项目名称；学生管理系统
//项目来源：ChatGPT
//项目编号：001
//联系人：周斌，binyinyuan@foxmail.com

//项目描述：这是一个基本的学生管理系统，我们可以根据该系统添加、删除、查询和更新学生的相关信息和成绩

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define  _CRT_SECURE_NO_WARNINGS
#define max_number 1000 //学生最大数量

typedef struct {
	int id;
	char name[50];// 最大49个字符，一个字符2个字节，也就是16比特。中文一般在2~3个字节，英文每个字母为一个字节
	int age;
	char gender[10];
	float grade;
}Student;// 创建Student的结构体

Student students[max_number];
int student_count = 0;//全局变量

void add_student()
{
	if (student_count >= max_number)
	{
		printf("数据库已满.\n");
		return;
	}

	Student newStudent;//创建newStudent的结构体
	printf("输入新学生ID：");
	scanf("%d", &newStudent.id);
	printf("输入新学生名字：");
	scanf("%s", &newStudent.name);
	printf("输入新学生年龄：");
	scanf("%d", &newStudent.age);
	printf("输入新学生性别：");
	scanf("%s", &newStudent.gender);
	printf("输入新学生成绩：");
	scanf("%f", &newStudent.grade);

	students[student_count] = newStudent;
	student_count++;
	printf("\n 添加新学生成果！\n");
}

void delete_student()
{
	int id = 0;
	printf("输入需要删除学生的ID：");
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
	printf("删除成功！！\n");
	return;
}

void update_student()
{
	int id = 0;
	printf("请输入需要更新学生ID");
	scanf("%d", &id);
	
	for (int i = 0; i < student_count; i++)
	{
		if(students[i].id == id)
		{
			printf("请输入新的学生名称：");
			scanf("%s", &students[i].name);

			printf("请输入新的学生年龄");
			scanf("%d", &students[i].age);

			printf("请输入新的学生性别");
			scanf("%s", &students[i].gender);

			printf("请输入新的学生成绩");
			scanf("%f", &students[i].grade);

			printf("信息更新成功！！\n");
			return;
		}
	}
	printf("ID错误！请输入正确的ID！\n");
}

void view_student()
{
	int id;
	printf("请输入你要查询学生的ID：");
	scanf("%d", &id);

	for (int i = 0; i < student_count; i++)
	{
		if (students[i].id == id)
		{
			printf("学生名称：%s\n", students[i].name);
			printf("学生年龄：%d\n", students[i].age);
			printf("学生性别：%s\n", students[i].gender);
			printf("学生成绩：%f\n", students[i].grade);
			
			printf("信息查询成功！！\n");
			return;
		}
	}
	printf("ID错误！请输入正确的ID！\n");
}

void view_all_student()
{	
	if (student_count == 0)
	{
		printf("信息查询失败！！当前库中学生数量为0！！");
		return;
	}
	for (int i = 0; i < student_count; i++)
	{
		printf("学生名称：%s，学生年龄：%d，学生性别：%s，学生成绩：%f", students[i].name, students[i].age, students[i].gender, students[i].grade);
	}
	printf("信息查询成功！！\n");
	return;
}

int main()
{
	int choice=0;
	//int a = 1;
	//printf("%d\n", a);//打印一定要使用双引号
	//return 0;
	
	while (1)
	{
		printf("\n------学生管理系统------\n");
		printf("请您选择一下操作：\n");
		printf("1：添加学生信息\n");
		printf("2：删除学生信息\n");
		printf("3：更新学生信息\n");
		printf("4：查阅学生信息\n");
		printf("5：查阅所有学生\n");
		printf("6：退出\n");

		printf("请输入您的操作选项：");
		scanf("%d", &choice);//双引号内不能输入汉字描述，只能输入格式化操作字符

		switch (choice) //如果不能直接执行，在while循环中会直接跳出，进入下一个循环。
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
				printf("无效选择，请重新选择!\n");
		}
	}
	
	return 0;
}