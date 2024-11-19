#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#define LEN_COACH sizeof(COACH)
#define LEN_COURSE sizeof(COURSE)
typedef struct student
{
	char name[30];	   // 姓名
	char account[30];  // 账号
	char password[30]; // 密码
	int score;		   // 价格
	char number[30];   // 号码
	struct student *next;
} STUDENT;
typedef struct coach
{
	char name[30];	   // 姓名
	char number[30];   // 号码
	char account[30];  // 账号
	char password[30]; // 密码
	int level;		   // 等级
	struct coach *next;
} COACH;
typedef struct admin
{
	char name[30];	   // 姓名
	char number[30];   // 号码
	char account[30];  // 账号
	char password[30]; // 密码
	struct admin *next;
} ADMIN;
typedef struct course
{
	char project[30]; // 所属项目名
	char name[30];	  // 课程名
	char number[30];  // 课程号
	char place[30];	  // 地点
	int time;		  // 课程时间
	char date[30];	  // 课程日期
	int score;		  // 课程价格
	int max;		  // 课程最大人数
	bool flag;		  // 课程是否可用
	struct course *next;
} COURSE;
typedef struct name // 用于修改课程的链表
{
	char name[30];
	struct name *next;
} NAME;