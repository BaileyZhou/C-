
#define max_number 1000

typedef struct {
	int id;
	char name[50];//字符串的定义需要预设大小
	int age;
	char gender[10];
	float grade;
}Student;

extern Student students[max_number];
extern int student_count;

void add_student();
void delete_student();
void update_student();
void view_student();
void view_all_student();