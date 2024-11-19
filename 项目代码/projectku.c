#define _CRT_SECURE_NO_WARNINGS 1
#include "struct.c"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

void regi() // 管理员注册函数！！！
{
    void inadmin(ADMIN * *admin, char name[30], char number[30], char account[30], char password[30]); // 管理员信息入表
    void ad(ADMIN * admin, FILE * fp);                                                                 // 添加管理员账号的条件
    ADMIN *insertad();                                                                                 // 导入管理员信息
    char *adfindap(ADMIN * admin, char account[30]);                                                   // 通过管理员账号返回密码
    void adoutfile(ADMIN * admin);                                                                     // 管理员信息由链表写入文件
    void deladlist(ADMIN * admin);                                                                     // 释放管理员链表
    ADMIN *admin = insertad();
    printf("您好，欢迎注册管理员\n");
    char acc[30];
    char pas[30];
    ADMIN *point = (ADMIN *)malloc(sizeof(ADMIN));
    printf("请验证管理员身份后添加账号\n");
    printf("请输入管理员账号\n");
    scanf("%s", acc);
    printf("请输入管理员密码\n");
    scanf("%s", pas);
    char *pa = adfindap(admin, acc);
    if (pa == NULL) // 注意判断顺序
    {
        printf("查无此人\n");
        return;
    }
    else if (strcmp(pa, pas) != 0)
    {
        printf("密码错误\n");
        return;
    }
    printf("请输入你的姓名\n");
    while (1)
    {
        // 判断输入
        if (scanf("%s", point->name) != EOF)
        {
            break;
        }
        else
        {
            printf("您的输入有误，请重新输入\n");
            continue;
        }
    }

    printf("请输入您的电话号码(11位)\n");

    while (1)
    {
        // 判断输入
        if (scanf("%s", point->number) && strlen(point->number) == 11)
        {
            break;
        }
        else
        {
            printf("您的输入有误，请重新输入\n");
            continue;
        }
    }
    printf("请为自己输入一个账号(不超过18位)\n");
    while (1)
    {
        // 判断输入
        if (scanf("%s", point->account))
        {
            printf("请记住您的账号\n");
            break;
        }
        else
        {
            printf("您的输入有误，请重新输入\n");
            continue;
        }
    }

    printf("请输入您的密码(不超过18位)(可以删除)\n");
    while (1)
    {
        int i;
        char str[30];
        for (i = 0; i < 20; i++)
        {
            if ((str[i] = _getch()) != '\b' && str[i] != '\r')
            {
                putchar('*');
            }
            // getch()从控制台输入一各字符但是不显示
            /*
                当在第i个字符输入退格键时，会把第i-1个字符赋值为'\0',
                并将i指向i-2 ,经过循环的i++后，i就指向了刚刚赋值为 '\0'的位置
            */
            if (str[i] == '\b' && i > 0)
            {
                str[--i] = '\0';
                i--;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
            // 如果在最开始就按退格键，就让i=-1
            if (str[i] == '\b' && i == 0)
            {
                i = -1;
            }
            // 如果输入的是回车，就退出输入循环
            if (str[i] == '\r')
            {
                break;
            }
        }
        printf("\n");
        str[i] = '\0';
        if (i <= 0)
        {
            printf("密码输入中出现错误，请重新输入\n");
            continue;
        }
        printf("请再次输入密码\n");
        char str1[30];
        for (i = 0; i < 20; i++)
        {
            if ((str1[i] = _getch()) != '\b' && str1[i] != '\r')
            {
                putchar('*');
            }
            if (str1[i] == '\b' && i >= 0)
            {
                str1[--i] = '\0';
                i--;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
            if (str1[i] == '\b' && i == 0)
            {
                i = -1;
            }
            if (str1[i] == '\r')
            {
                break;
            }
        }
        str1[i] = '\0';
        // 判断输入
        printf("\n");
        if (strcmp(str, str1) == 0)
        {
            strcpy(point->password, str);
            printf("请记住您的密码\n");
            break;
        }
        else
        {
            printf("您的输入有误，请重新输入\n");
            continue;
        }
    }

    inadmin(&admin, point->name, point->number, point->account, point->password);
    printf("daorulianb");
    free(point);
    point = NULL;
    adoutfile(admin); // 管理员信息由链表写入文件
    deladlist(admin); // 释放管理员链表
    printf("注册成功\n");
}
bool adminlogin()
{
    ADMIN *insertad();
    char acc[30];
    char pass[30];
    printf("请输入管理员账号\n");
    scanf("%s", acc);
    printf("请输入您的密码(不超过18位)(可以删除)\n");
    ADMIN *admin = insertad();
    ADMIN *cur = admin;
    int count = 0;
    while (cur != NULL)
    {
        if (strcmp(admin->account, acc) == 0)
        {
            count = 1;
            strcpy(pass, admin->password);
            break;
        }
        cur = cur->next;
    }
    char str[30];

    while (1)
    {
        int i;
        for (i = 0; i < 20; i++)
        {
            if ((str[i] = getch()) != '\b' && str[i] != '\r')
            {
                putchar('*');
            }
            // getch()从控制台输入一各字符但是不显示
            /*
                当在第i个字符输入退格键时，会把第i-1个字符赋值为'\0',
                并将i指向i-2 ,经过循环的i++后，i就指向了刚刚赋值为 '\0'的位置
            */
            if (str[i] == '\b' && i > 0)
            {
                str[--i] = '\0';
                i--;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
            // 如果在最开始就按退格键，就让i=-1
            if (str[i] == '\b' && i == 0)
            {
                i = -1;
            }
            // 如果输入的是回车，就退出输入循环
            if (str[i] == '\r')
            {
                break;
            }
        }
        printf("\n");
        str[i] = '\0';
        if (i <= 0)
        {
            printf("密码输入中出现错误，请重新输入\n");
            continue;
        }
        else
        {
            break;
        }
    }

    if (strcmp(pass, str) == 0)
    {
        return true;
    }
    else
    {
        printf("密码错误\n");
        return false;
    }
}
char *adfindap(ADMIN *admin, char account[30]) // 通过管理员账号返回密码
{
    ADMIN *pre = admin;
    while (pre != NULL && strcmp(pre->account, account) != 0)
    {
        pre = pre->next;
    }
    if (pre == NULL)
        return NULL;
    else
        return pre->password;
}
ADMIN *insertad() // 用于导入管理员信息到链表
{
    void inadmin(ADMIN * *admin, char *name, char *number, char *account, char *password); // 管理员信息入表
    FILE *fp;
    fp = fopen("C:\\Users\\lenovo\\Desktop\\管理员.txt", "rb");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return NULL;
    }
    ADMIN *admin = (ADMIN *)malloc(sizeof(ADMIN));
    admin = NULL;
    char name[30];
    char number[30];
    char account[30];
    char password[30];
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %s ", name, number, account, password);
        inadmin(&admin, name, number, account, password);
    }
    fclose(fp);
    return admin;
}
void inadmin(ADMIN **admin, char name[30], char number[30], char account[30], char password[30]) // 管理员信息入表
{
    ADMIN *newnode = (ADMIN *)malloc(sizeof(ADMIN)); // 不释放
    strcpy(newnode->name, name);
    strcpy(newnode->number, number);
    strcpy(newnode->account, account);
    strcpy(newnode->password, password);
    newnode->next = NULL;
    if (*admin == NULL)
    {
        *admin = newnode;
        return;
    }
    else
    {
        ADMIN *pre = *admin;
        ADMIN *cur = *admin;
        while (cur)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = newnode;
    }
}
void adoutfile(ADMIN *admin) // 管理员信息由链表写入文件
{
    FILE *fp;
    fp = fopen("C:\\Users\\lenovo\\Desktop\\管理员.txt", "wb");
    ADMIN *pre = admin;
    while (pre != NULL)
    {
        fprintf(fp, "\n%s %s %s %s", pre->name, pre->number, pre->account, pre->password);
        pre = pre->next;
    }
    printf("数据导入成功\n");
}
void deladlist(ADMIN *admin) // 释放管理员-链表
{
    ADMIN *pre = admin;
    while (admin)
    {
        pre = admin;
        admin = admin->next;
        free(pre);
        pre = NULL;
    }
}
void incoach(COACH **coach, char name[30], char number[30], char account[30], char password[30], int level) // 教练员信息入表
{
    COACH *newnode = (COACH *)malloc(sizeof(COACH)); // 不释放
    strcpy(newnode->name, name);
    strcpy(newnode->number, number);
    strcpy(newnode->account, account);
    strcpy(newnode->password, password);
    newnode->level = level;
    newnode->next = NULL;
    if (*coach == NULL)
    {
        *coach = newnode;
        return;
    }
    else
    {
        COACH *pre = *coach;
        COACH *cur = *coach;
        while (cur)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = newnode;
    }
}
COACH *insertco() // 用于导入教练信息到链表
{
    void incoach(COACH * *coach, char name[30], char number[30], char account[30], char password[30], int level); // 教练信息入表
    FILE *fp;
    fp = fopen("C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt", "rb+");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return NULL;
    }
    COACH *coach = (COACH *)malloc(sizeof(COACH));
    coach = NULL;
    char name[30];
    char number[30];
    char account[30];
    char password[30];
    int level;
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %s %d ", name, number, account, password, &level);
        incoach(&coach, name, number, account, password, level);
    }
    fclose(fp);
    return coach;
}
void mancoach() // 用于教练信息管理！！！
{
    void menumancoach(); // 管理教练功能菜单

    void delcoa();     // 删除教练
    void modcograde(); // 修改教练级别
    void coamodcou();  // 修改教练课程
    void addcoa();     // 增加教练
    menumancoach();
    // mancoach();        // 功能菜单
    COACH *insertco(); // 用于导入教练信息到链表
    FILE *fp;
    fp = fopen("C:\\Users\\lenovo\\Desktop\\教练员.txt", "rb");
    COACH *coach = insertco();
    int order;
    while (1)
    {
        scanf("%d", &order);
        switch (order)
        {
        case 1:
            return;
        case 2:
            coamodcou(); // 修改教练课程
        case 3:
            modcograde(); // 修改教练级别
        case 4:
            delcoa(); // 删除教练
        case 5:
            // 增加教练
            addcoa(); // 增加教练
        }
    }
}
void menumancoach() // 管理教练功能菜单
{
    printf("****************************\n");
    printf("       1     退出           \n");
    printf("       2 修改教练课程        \n");
    printf("       3 修改教练级别        \n");
    printf("       4   删除教练          \n");
    printf("       5   增加教练          \n");
}
void coamodcou() // 修改教练课程
{
    void coamodcou_(char *); // 教练删除课程
    void coaddse(char *co);  // 教练增加课程

    int order;
    while (1)
    {
        printf("****************************\n");
        printf("*          1 删除          *\n");
        printf("*          2 增加          *\n");
        printf("*          3 退出          *\n");
        printf("****************************\n");
        printf("请输入你的选择\n");
        char ore[30];
        scanf("%s", ore);
        order = atoi(ore);
        char acc[30];
        char co_road[50] = "C:\\Users\\lenovo\\Desktop\\教练\\";
        char co_end[30] = ".txt";

        FILE *fp;
        switch (order)
        {
        case 1:
            printf("请输入教练的账号\n");
            scanf("%s", acc);
            strcat(co_road, acc);
            strcat(co_road, co_end);
            fp = fopen(co_road, "rb+");
            if (fp == NULL)
            {
                printf("请确认账号输入是否正确\n");
                continue;
            }
            else
            {

                coamodcou_(co_road); // 教练删除课程
            }
            break;

        case 2:
            printf("请输入教练的账号\n");
            scanf("%s", acc);
            strcat(co_road, acc);
            strcat(co_road, co_end);
            fp = fopen(co_road, "rb+");
            if (fp == NULL)
            {
                printf("请确认账号输入是否正确\n");
                continue;
            }
            else
            {
                coaddse(co_road); // 教练增加课程
            }
            break;
        case 3:
            return;
        }
    }
}
void coamodcou_(char *co) // 教练删除课程
{
    void sedelcoa(char *course, char *nam); // 从课程里面删除教练
    COURSE *insertse(FILE * fp);
    FILE *fp = fopen(co, "rb+");
    COURSE *course = insertse(fp);
    char name[30]; // 课程所属项目
    printf("请输入你的姓名\n");
    scanf("%s", name);
    printf("请输入要删除的课程\n");
    char nam[30];
    scanf("%s", nam);
    sedelcoa(nam, name);
    COURSE *pre = course;
    COURSE *cur = course;
    while (cur != NULL && strcmp(cur->name, nam) != 0)
    {
        pre = cur;
        cur = cur->next;
    }

    if (cur == NULL)
    {
        printf("课程不存在\n");
    }
    else if (cur == course)
    {
        course = course->next;
        free(cur);
    }
    else
    {
        COURSE *temp = cur;
        pre->next = cur->next;
        free(temp);
        temp = NULL;
    }
    pre = course;
    fp = fopen(co, "w");
    while (pre != NULL)
    {
        fprintf(fp, "\n%s %s %s %s %d %s %d %d", pre->project, pre->name, pre->number, pre->place, pre->time, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
    printf("数据导入成功\n");
}
STUDENT *insertstu() // 用于导入学员信息到链表
{
    void instu(STUDENT * *stu, char name[30], char account[30], char password[30], int score, char number[30]); // 学员信息入表
    FILE *fp;
    fp = fopen("C:\\Users\\lenovo\\Desktop\\学员\\学员.txt", "rb+");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return NULL;
    }
    STUDENT *stu = (STUDENT *)malloc(sizeof(STUDENT));
    stu = NULL;
    char name[30];     // 姓名
    char account[30];  // 账号
    char password[30]; // 密码
    int score;         // 价格
    char number[30];   // 号码
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %d %s ", name, account, password, &score, number);
        instu(&stu, name, account, password, score, number);
    }
    fclose(fp);
    return stu;
}
void instu(STUDENT **stu, char name[30], char account[30], char password[30], int score, char number[30]) // 学员信息入表
{
    STUDENT *newnode = (STUDENT *)malloc(sizeof(STUDENT));
    strcpy(newnode->name, name);
    strcpy(newnode->account, account);
    strcpy(newnode->password, password);
    strcpy(newnode->number, number);
    newnode->score = score;
    newnode->next = NULL;
    if (*stu == NULL)
    {
        *stu = newnode;
        return;
    }
    else
    {
        STUDENT *pre = *stu;
        STUDENT *cur = *stu;
        while (cur)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = newnode;
    }
}
COURSE *insertse(FILE *fp) // 课程信息入表
{
    void incourse(COURSE * *course, char pro[30], char nam[30], char numbe[30], char place[30], int tim, char dat[30], int scor, int max); // 课程信息入表
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return NULL;
    }
    COURSE *course = (COURSE *)malloc(sizeof(COURSE));
    course = NULL;
    char project[30];
    char name[30];
    char number[30];
    char place[30];
    int time;
    char date[30];
    int score;
    int max;
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %s %d %s %d %d ", project, name, number, place, &time, date, &score, &max);
        incourse(&course, project, name, number, place, time, date, score, max);
    }
    fclose(fp);
    return course;
}
void incourse(COURSE **course, char pro[30], char nam[30], char numbe[30], char place[30], int tim, char dat[30], int scor, int max) // 课程信息入表
{
    COURSE *newnode = (COURSE *)malloc(sizeof(COURSE)); // 不释放
    strcpy(newnode->project, pro);
    strcpy(newnode->name, nam);
    strcpy(newnode->number, numbe);
    strcpy(newnode->place, place);
    newnode->time = tim;
    strcpy(newnode->date, dat);
    newnode->score = scor;
    newnode->max = max;
    newnode->flag = true;
    newnode->next = NULL;
    if (*course == NULL)
    {
        *course = newnode;
        return;
    }
    else
    {
        COURSE *cur = *course;
        COURSE *pre = *course;
        while (cur)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = newnode;
    }
}
void coaddse(char *co) // 教练增加课程
{
    char nam[30];    // 教练名
    char pro[30];    // 所属项目
    char name[30];   // 课程名
    char number[30]; // 课程号
    char place[30];  // 地点
    char tim[30];        // 课程时间
    char date[30];   // 课程日期
    char scor[30];       // 课程价格
    char max[30];         // 课程最大人数
    char road[100] = "C:\\Users\\lenovo\\Desktop\\co课程\\";
    printf("请输入教练的姓名\n");
    scanf("%s", nam);
    
    printf("请输入要添加的课程所属项目\n");
    scanf("%s", pro);
    printf("请输入要添加的课程名称\n");
    scanf("%s", name);
    strcat(road, name);
    strcat(road, ".txt");
    printf("请输入课程号\n");
    scanf("%s", number);
    printf("请输入课程地点\n");
    scanf("%s", place);
    printf("请输入课程时间(若时间为9:30请输入0930)\n");
    scanf("%s", &tim);
    int time=tim[0]*1000+tim[1]*100+tim[2]*10+tim[3];
    if(time>2359||time<0)
    {
        printf("时间不合法,请重试\n");
        coaddse(co);
    }
    printf("请输入课程星期(若为星期日，请输入星期日，星期一输入星期一一):\n");
    scanf("%s", date);
    if(strcmp(date,"星期日")!=0&&strcmp(date,"星期一")!=0&&strcmp(date,"星期二")!=0&&strcmp(date,"星期三")!=0&&strcmp(date,"星期四")!=0&&strcmp(date,"星期五")!=0&&strcmp(date,"星期六")!=0)
    {
        printf("日期不合法,请重试\n");
        coaddse(co);
        return;
    }
    printf("请输入课程价格\n");
    scanf("%s", scor);
    int score=atoi(scor);
    if(score<0)
    {
        printf("价格不合法,请重试\n");
        coaddse(co);
    }
    printf("请输入课程最大人数\n");
    scanf("%d", &max);
    if(max<0)
    {
        printf("人数不合法,请重试\n");
        coaddse(co);
    }
    FILE *fp;
    fp = fopen(co, "ab+"); // 没有则创建ASCI文件
    FILE *fb;
    fb = fopen(road, "ab+"); // 没有则创建ASCI文件
    if (fp)
    {
        fprintf(fp, "\n%s %s %s %s %d %s %d %s", pro, name, number, place, time, date, score, max);
        fprintf(fb, "\n%s", nam);
        printf("数据导入成功\n");
    }
    else
    {
        printf("文件打开失败\n");
    }
    fclose(fp);
}
NAME *insertna(FILE *fp) // 用于导入名到链表
{
    void inname(NAME * *name, char nam[30]);
    NAME *name = (NAME *)malloc(sizeof(NAME));
    name = NULL;
    char nam[30];
    while (!feof(fp))
    {
        fscanf(fp, "%s ", nam);
        inname(&name, nam);
    }
    fclose(fp);
    return name;
}
void inname(NAME **name, char nam[30]) // 课程入表
{
    NAME *newnode = (NAME *)malloc(sizeof(NAME)); // 不释放
    strncpy(newnode->name, nam, sizeof(newnode->name) - 1);
    newnode->next = NULL;
    if (newnode == NULL)
    {
        printf("内存分配失败\n");
        return;
    }
    if (*name == NULL)
    {
        *name = newnode;
        return;
    }
    else
    {
        NAME *cur = *name;
        NAME *pre = *name;
        while (cur)
        {
            pre = cur;
            if (cur)
            {
                cur = cur->next;
            }
        }
        pre->next = newnode;
    }
}
void sedelcoa(char *course, char *nam) // 从课程里面删除教练
{
    void filecopy();
    filecopy();
    NAME *insertna(FILE * fp); // 用于导入名到链表
    char road[100] = "C:\\Users\\lenovo\\Desktop\\co课程\\";
    strcat(road, course);
    strcat(road, ".txt");
    FILE *fp;
    fp = fopen(road, "r");
    if (fp == NULL)
    {
        printf("课程文件打开失败\n");
    }
    else
    {
        NAME *name = insertna(fp);
        NAME *pre = name;
        NAME *cur = name;
        while (cur != NULL && strcmp(cur->name, nam) != 0)
        {
            pre = cur;
            cur = cur->next;
        }

        if (cur == NULL)
        {
            printf("教练不存在...\n");
            return;
        }
        else if (cur == name)
        {
            name = name->next;
            free(cur);
        }
        else
        {
            NAME *temp = cur;
            pre->next = cur->next;
            free(temp);
            temp = NULL;
        }
        pre = name;
        fp = fopen(road, "w");
        while (pre != NULL)
        {
            fprintf(fp, "\n%s", pre->name);
            pre = pre->next;
        }
        printf("数据导入成功\n");
    }
}
void addcourse() // 仅用于添加课程是添加到指定文件
{
    void filecopy();
    char project[30]; // 所属项目名
    char name[30];    // 课程名
    char number[30];  // 课程号
    char place[30];   // 地点
    int time;         // 课程时间
    char date[30];    // 课程日期
    int score;        // 课程价格
    int max;          // 课程最大人数
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    FILE *fp4;
    char road1[100] = "C:\\Users\\lenovo\\Desktop\\课程\\";
    char road2[100] = "C:\\Users\\lenovo\\Desktop\\co课程\\";
    char road3[100] = "C:\\Users\\lenovo\\Desktop\\stu课程\\";

    printf("请输入要添加的课程所属项目\n");
    scanf("%s", project);
    printf("请输入要添加的课程名\n");
    scanf("%s", name);
    strcat(road1, name);
    strcat(road1, ".txt");

    strcat(road2, name);
    strcat(road2, ".txt");

    strcat(road3, name);
    strcat(road3, ".txt");

    printf("请输入要添加的课程号\n");
    scanf("%s", number);
    printf("请输入要添加的课程地点\n");
    scanf("%s", place);
    printf("请输入要添加的课程时间(9:30  0930)\n");
    scanf("%d", &time);
    printf("请输入要添加的课程日期\n");
    scanf("%s", date);
    printf("请输入要添加的课程价格\n");
    scanf("%d", &score);
    printf("请输入要添加的课程最大人数\n");
    scanf("%d", &max);

    fp1 = fopen(road1, "ab+"); // 在课程文件中添加

    fprintf(fp1, "\n%s %s %s %d %s %d %d", project, name, number, time, date, score, max);

    fp2 = fopen(road2, "ab+"); // 写入课程对应的教练文件

    fp3 = fopen(road3, "ab+"); // 写入课程对应的学生文件

    fp4 = fopen("C:\\Users\\lenovo\\Desktop\\课程\\课程.txt", "ab+"); // 写入课程大名单
    fprintf(fp4, "\n%s", name);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    filecopy();
}
void modcograde() // 修改教练级别
{
    void filecopy();
    void cooutfile(COACH * coach); // 教练信息由链表写入文件
    COACH *insertco();             // 用于导入教练信息到链表
    char road[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
    FILE *fp1;
    FILE *fp2;
    char acc[30];

    printf("请输入教练账号\n");
    scanf("%s", acc);
    strcat(road, acc);
    strcat(road, ".txt"); // 确定是否有此人
    fp1 = fopen(road, "r+");
    if (fp1 == NULL)
    {
        printf("请确认账号输入是否正确\n");
    }
    else
    {
        COACH *coach = insertco();
        int lev;
        printf("请输入要修改的教练级别(1-7)\n");
        scanf("%d", &lev);
        if (lev < 1 || lev > 7)
        {
            printf("输入错误\n");
        }
        else
        {
            COACH *cur = coach;
            while (cur != NULL && strcmp(cur->account, acc) != 0)
            {
                cur = cur->next;
            }
            cur->level = lev;
            cur= coach;
            fp1 = fopen("C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt", "w+");
            while(cur)
            {
                fprintf(fp1, "\n%s %s %s %s %d", cur->name, cur->number, cur->account, cur->password, cur->level);
                cur = cur->next;
            }
            void delcoalist(COACH * coach);
            delcoalist(coach);
            fclose(fp1);
        }
        printf("修改成功\n");
    }
    filecopy();
}
void cooutfile(COACH *coach) // 教练信息由链表写入文件
{
    FILE *fp;
    fp = fopen("C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt", "w");
    COACH *pre = coach;
    while (pre != NULL)
    {
        fprintf(fp, "\n%s %s %s %s %d", pre->name, pre->number, pre->account, pre->password, pre->level);
        pre = pre->next;
    }
    printf("数据导入成功\n");
}
void delcoa() // 删除教练
{
    void filecopy();
    filecopy();
    void delcoalist(COACH * coach);         // 释放教练链表
    COACH *insertco();                      // 用于导入教练信息到链表
    void sedelcoa(char *course, char *nam); // 从课程里面删除教练
    COURSE *insertse(FILE * fp);            // 课程信息入表
    // 从教练名单删除，教练信息删除，课程中删除
    printf("请输入要删除的教练账号\n");
    char acc[30];
    scanf("%s", acc);
    printf("请输入要删除的教练姓名\n");
    char name[30];
    scanf("%s", name);
    // 从课程里面删除教练
    char road[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
    strcat(road, acc);
    strcat(road, ".txt");
    FILE *fp1;
    fp1 = fopen(road, "r");
    if (fp1 == NULL)
    {
        printf("未找到教练文件，请确定账号输入是否正确\n");
    }
    else
    {
        COURSE *course = insertse(fp1); // 教练教的课程信息入表
        COURSE *curr = course;
        while (curr != NULL)
        {
            sedelcoa(curr->name, name);
            curr = curr->next;
        }
        remove(road); // 删除教练文件
        COACH *coach = insertco();
        COACH *pre = coach;
        COACH *cur = coach;
        while (cur != NULL && strcmp(cur->name, name) != 0)
        {
            pre = cur;
            cur = cur->next;
        }

        if (cur == coach)
        {
            coach = coach->next;
            free(cur);
            cur=NULL;
        }
        else
        {
            COACH *temp = cur;
            pre->next = cur->next;
            free(temp);
            temp = NULL;
        }
        pre = coach;
        FILE *fp2;
        char roadd[100]="C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt";
        fp2 = fopen(roadd, "w");
        //fp2 = fopen("C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt", "ab+");
        while (pre != NULL)
        {
            fprintf(fp2, "\n%s %s %s %s %d", pre->name, pre->number, pre->account, pre->password, pre->level);
            pre = pre->next;
        }
        printf("教练删除成功\n");
        delcoalist(coach);
    }
}
void addcoa() // 增加教练
{
    void filecopy();
    FILE *fp;
    fp = fopen("C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt", "ab+");
    char name[30];     // 姓名
    char number[30];   // 号码
    char account[30];  // 账号
    char password[30]; // 密码
    int level;         // 等级
    printf("请输入教练姓名\n");
    scanf("%s", name);
    printf("请输入教练号码\n");
    scanf("%s", number);
    printf("请输入教练账号\n");
    scanf("%s", account);
    printf("请输入教练密码\n");
    scanf("%s", password);
    printf("请输入教练等级\n");
    scanf("%d", &level);
    fprintf(fp, "\n%s %s %s %s %d ", name, number, account, password, level);
    char road[100]="C:\\Users\\lenovo\\Desktop\\教练\\";
    strcat(road, account);
    strcat(road, ".txt");
    FILE *fp1;
    fp1 = fopen(road, "w");
    fclose(fp1);
    fclose(fp);
    printf("教练添加成功\n");
    filecopy();
}
//  "C:\\Users\\lenovo\\Desktop\\co课程"
//  FILE *file = fopen("filename.txt", "w, ccs=ASCII");
COURSE *Stu_Course_list_head(STUDENT *stu) // 获得来访学员的课程链表头指针
{
    COURSE *head, *p1, *p2;
    head = NULL;
    FILE *p_student;
    char filename[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
    strcat(filename, stu->account);
    strcat(filename, ".txt");
    p_student = fopen(filename, "r"); // 文件名不可以,必须地址
    if (p_student == NULL)
    {
        printf("文件打开失败\n"); // 文件打开失败
        return NULL;              // 表示文件打开失败，让文件指针指向空指针,释放文件指针所占用的内存空间，
    }
    while (!feof(p_student)) // 判断是否到达文件末尾
    {
        p1 = (COURSE *)malloc(LEN_COURSE);                                                                                                      // 项目名 课程名 课程号 地点 课程时间 课程日期 课程价格 课程最大人数
        fscanf(p_student, "%s %s %s %s %d %s %d %d ", p1->project, p1->name, p1->number, p1->place, &p1->time, p1->date, &p1->score, &p1->max); // ，呜呜呜，注意最后不要少了空格呀
        p1->next = NULL;
        if (head == NULL)
        {
            head = p1;
            p2 = p1;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
        }
    }
    fclose(p_student);
    return head;
}

STUDENT *insertstucopy() // 用于导入备份学员信息到链表
{
    void instu(STUDENT * *stu, char name[30], char account[30], char password[30], int score, char number[30]); // 学员信息入表
    FILE *fp;
    fp = fopen("C:\\Users\\lenovo\\Desktop\\备份\\学员\\学员.txt", "rb+");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return NULL;
    }
    STUDENT *stu = (STUDENT *)malloc(sizeof(STUDENT));
    stu = NULL;
    char name[30];     // 姓名
    char account[30];  // 账号
    char password[30]; // 密码
    int score;         // 价格
    char number[30];   // 号码
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %d %s ", name, account, password, &score, number);
        instu(&stu, name, account, password, score, number);
    }
    fclose(fp);
    return stu;
}

COACH *insertcocopy() // 用于导入备份教练信息到链表
{
    void incoach(COACH * *coach, char name[30], char number[30], char account[30], char password[30], int level); // 教练信息入表
    FILE *fp;
    fp = fopen("C:\\Users\\lenovo\\Desktop\\备份\\教练\\教练员.txt", "rb+");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return NULL;
    }
    COACH *coach = (COACH *)malloc(sizeof(COACH));
    coach = NULL;
    char name[30];
    char number[30];
    char account[30];
    char password[30];
    int level;
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %s %d ", name, number, account, password, &level);
        incoach(&coach, name, number, account, password, level);
    }
    fclose(fp);
    return coach;
}

void delcoalist(COACH *coach) // 释放教练链表
{
    COACH *pre = coach;
    while (coach)
    {
        pre = coach;
        coach = coach->next;
        free(pre);
        pre = NULL;
    }
}

void delcoulist(COURSE *course) // 释放课程链表
{
    COURSE *pre = course;
    while (course)
    {
        pre = course;
        course = course->next;
        free(pre);
        pre = NULL;
    }
}

void delnamelist(NAME *name) // 释放名称链表
{
    NAME *pre = name;
    while (name)
    {
        pre = name;
        name = name->next;
        free(pre);
        pre = NULL;
    }
}

void delstulist(STUDENT *stu) // 释放学生链表
{
    STUDENT *pre = stu;
    while (stu)
    {
        pre = stu;
        stu = stu->next;
        free(pre);
        pre = NULL;
    }
}

COURSE *insertallse() // 用于导入所有课程到链表
{
    NAME *insertna(FILE * fp);                                                                                                             // 用于导入名到链表
    void incourse(COURSE * *course, char pro[30], char nam[30], char numbe[30], char place[30], int tim, char dat[30], int scor, int max); // 课程信息入表
    FILE *fp1;                                                                                                                             // 课程名指针
    fp1 = fopen("C:\\Users\\lenovo\\Desktop\\课程\\课程.txt", "rb");
    if (fp1 == NULL)
    {
        printf("文件打开失败\n");
        return (COURSE *)NULL;
    }
    NAME *name = insertna(fp1);
    NAME *cur = name;
    COURSE *course = (COURSE *)malloc(sizeof(COURSE));
    course = NULL;
    while (cur)
    {
        char road2[100] = "C:\\Users\\lenovo\\Desktop\\课程\\";
        strcat(road2, cur->name);
        strcat(road2, ".txt");
        FILE *fp2;
        fp2 = fopen(road2, "rb+");
        char project[30]; // 所属项目名
        char name[30];    // 课程名
        char number[30];  // 课程号
        char place[30];   // 地点
        int time;         // 课程时间
        char date[30];    // 课程日期
        int score;        // 课程价格
        int max;          // 课程最大人数
        fscanf(fp2, "%s %s %s %s %d %s %d %d ", project, name, number, place, &time, date, &score, &max);
        incourse(&course, project, name, number, place, time, date, score, max);
        cur = cur->next;
    }
    return course;
}

bool pancour(char *courna) // 判断课程是否存在
{

    COURSE *course = insertallse();
    COURSE *cur = course;
    while (cur != NULL)
    {
        if (strcmp(cur->name, courna) == 0)
        {
            delcoulist(course);
            return true;
        }
        cur = cur->next;
    }
    delcoulist(course);
    return false;
}

void modcou() // 修改课程信息
{
    void filecopy();
    // 添加和修改课程信息
    printf("请输入要修改的课程名称\n");
    char na[30];
    scanf("%s", na);
    char road[100] = "C:\\Users\\lenovo\\Desktop\\课程\\";
    strcat(road, na);
    strcat(road, ".txt");
    FILE *fp1;
    fp1 = fopen(road, "rb+");
    if (fp1 == NULL)
    {
        printf("未找到该课程\n");
    }
    else
    {
        FILE *fp3;
        
        char project[30]; // 所属项目名
        char name[30];    // 课程名
        char number[30];  // 课程号
        char place[30];   // 地点
        int time;         // 课程时间
        char date[30];    // 课程日期
        int score;        // 课程价格
        int max;          // 课程最大人数
        fscanf(fp1, "%s %s %s %s %d %s %d %d ", project, name, number, place, &time, date, &score, &max);
        fp3 = fopen(road, "wb");
        printf("不能修改课程的名称，项目名\n");
        printf("请输入要修改的课程号\n");
        scanf("%s", number);
        printf("请输入要修改的课程地点\n");
        scanf("%s", place);
        printf("请输入要修改的课程时间(9:30  0930)\n");
        scanf("%d", &time);
        printf("请输入要修改的课程日期\n");
        scanf("%s", date);
        printf("请输入要修改的课程价格\n");
        scanf("%d", &score);
        printf("请输入要修改的课程最大人数\n");
        scanf("%d", &max);
        fprintf(fp3, "\n%s %s %s %s %d %s %d %d ", project, name, number, place, time, date, score, max);
        fclose(fp1);
        fclose(fp3);
        filecopy();
    }
}

void modcoacour() // 修改课程教练
{
    void couaddcoa(); // 课程添加教练
    void coudelcoa(); // 课程删除教练
    printf("*****************************\n");
    printf("***     课程修改教练      ***\n");
    printf("***      1 添加教练       ***\n");
    printf("***      2 删除教练       ***\n");
    printf("*****************************\n");
    printf("请输入你的选择\n");
    char order[20];
    scanf("%s", order);
    int order1 = atoi(order);
    switch (order1)
    {
    case 1:
    {
        couaddcoa();
        break;
    }
    case 2:
    {
        coudelcoa();
        break;
    }
    default:
    {
        printf("输入错误\n");
    }
    }
    printf("是否继续修改？\n");
    printf("1：是\n");
    printf("2或其他：否\n");
    char ch[20];
    scanf("%s", ch);
    int ch1 = atoi(ch);
    if (ch1 == 1)
    {
        modcoacour();
        return;
    }
    else
    {
        return;
    }
}

void couaddcoa() // 课程添加教练
{
    void filecopy();
    bool pancoach(char na[30]); // 判断教练是否存在
    printf("请输入课程\n");
    char na[30];
    scanf("%s", na);
    char road1[100] = "C:\\Users\\lenovo\\Desktop\\课程\\";
    strcat(road1, na);
    strcat(road1, ".txt");
    FILE *fp1;
    fp1 = fopen(road1, "rb");
    if(fp1 == NULL)
    {
        printf("未找到该课程\n");

    }
    else
    {
        fp1 = fopen(road1, "ab+");
    char road2[100] = "C:\\Users\\lenovo\\Desktop\\co课程\\";
    strcat(road2, na);
    strcat(road2, ".txt");
    FILE *fp2;
    fp2 = fopen(road2, "ab+");
    if (fp1 == NULL)
    {
        printf("未找到该课程\n");
    }
    else
    {
        char project[30]; // 所属项目名
        char name[30];    // 课程名
        char number[30];  // 课程号
        char place[30];   // 地点
        int time;         // 课程时间
        char date[30];    // 课程日期
        int score;        // 课程价格
        int max;          // 课程最大人数
        fscanf(fp1, "%s %s %s %s %d %s %d %d ", project, name, number, place, &time, date, &score, &max);

        printf("请输入要添加到课程的教练姓名\n");
        char coana[30];
        scanf("%s", coana);
        fprintf(fp2, "\n%s", coana); // 添加教练到课程
        if (pancoach(coana))
        {
            COACH *coach = insertco();
            COACH *cur = coach;
            char acc[30];
            while (cur)
            {
                if (strcmp(cur->name, coana) == 0)
                {
                    char road3[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
                    strcat(road3, cur->account);
                    strcat(road3, ".txt");
                    FILE *fp3;
                    fp3 = fopen(road3, "ab+");
                    fprintf(fp3, "\n%s %s %s %s %d %s %d %d ", project, name, number, place, time, date, score, max); // 添加到教练
                    fclose(fp3);
                    break;
                }
                cur = cur->next;
            }
            delcoalist(coach);
        }
        else
        {
            printf("该教练不存在\n");
        }
        fclose(fp1);
        fclose(fp2);
        filecopy();
    }
    }
}

void adpro() // 项目管理
{
    void filecopy(); // 文件备份
    printf("由于项目和课程挂钩，删除项目会删除项目对应所有课程，所以一次只能删除一个项目课程\n");
    printf("*****************************\n");
    printf("***       项目管理        ***\n");
    printf("***      1 添加课程       ***\n");
    printf("***      2 删除课程       ***\n");
    printf("***      3 修改项目       ***\n");
    printf("*****************************\n");
    printf("请输入你的选择\n");
    char order[20];
    scanf("%s", order);
    int order1 = atoi(order);
    switch (order1)
    {
    case 1:
    {
        char project[30]; // 所属项目名
        char name[30];    // 课程名
        char number[30];  // 课程号
        char place[30];   // 地点
        int time;         // 课程时间
        char date[30];    // 课程日期
        int score;        // 课程价格
        int max;          // 课程最大人数
        printf("请输入要添加的项目名\n");
        scanf("%s", project);
        FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\projectname.txt", "ab");
        fprintf(fp, "\n%s", project);
        fclose(fp);
        printf("请输入要添加的课程名\n");
        scanf("%s", name);
        printf("请输入要添加的课程号\n");
        scanf("%s", number);
        printf("请输入要添加的课程地点\n");
        scanf("%s", place);
        printf("请输入要添加的课程时间(9:30  0930)\n");
        scanf("%d", &time);
        printf("请输入要添加的课程日期\n");
        scanf("%s", date);
        printf("请输入要添加的课程价格\n");
        scanf("%d", &score);
        printf("请输入要添加的课程最大人数\n");
        scanf("%d", &max);
        char road1[100] = "C:\\Users\\lenovo\\Desktop\\课程\\";
        strcat(road1, name);
        strcat(road1, ".txt");
        FILE *fp1;
        fp1 = fopen(road1, "ab+");
        char road2[100] = "C:\\Users\\lenovo\\Desktop\\课程\\课程.txt";
        FILE *fp2;
        fp2 = fopen(road2, "ab+");
        fprintf(fp1, "\n%s %s %s %s %d %s %d %d", project, name, number, place, time, date, score, max);
        fprintf(fp2, "\n%s", name);
        char road3[100] = "C:\\Users\\lenovo\\Desktop\\co课程\\";
        char road4[100] = "C:\\Users\\lenovo\\Desktop\\stu课程\\";
        strcat(road3, name);
        strcat(road3, ".txt");
        strcat(road4, name);
        strcat(road4, ".txt");
        FILE *fp3;
        fp3 = fopen(road3, "ab+");
        FILE *fp4;
        fp4 = fopen(road4, "ab+");
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        fclose(fp4);
        // filecopy(); // 文件备份
        break;
    }
    case 2:
    {
        filecopy();
        printf("请输入要删除的课程\n");
        char nam[30];
        scanf("%s", nam);
        char road1[100] = "C:\\Users\\lenovo\\Desktop\\课程\\课程.txt";

        FILE *fp1;
        fp1 = fopen(road1, "rb");
        
        NAME *name = (NAME *)malloc(sizeof(NAME));
        name = NULL;
        char na[30];
        int count=0;
        while (!feof(fp1))
        {
            fscanf(fp1, "%s ", na);
            if (strcmp(na, nam) != 0)
            {
                
                inname(&name, na);
            }
            else
            {
                count++;
            }
        }
        if(count==0)
        {
            printf("未找到课程\n");
            break;
        }
        else
        {
        NAME *temp = name;
        fp1 = fopen(road1, "w");
        while (temp)
        {
            fprintf(fp1, "\n%s", temp->name);
            temp = temp->next;
        }
        }
        delnamelist(name);
        fclose(fp1);
        break;
    }

    case 3:
    {
        int count = 0;
        printf("项目修改仅支持修改项目名称\n");
        printf("如果需要修改对应课程信息\n");
        printf("可以前往管理员课程管理界面\n");
        printf("请输入要修改的项目名称\n");
        char pro[30];
        scanf("%s", pro);
        COURSE *course = insertallse();
        COURSE *temp = course;
        char project[30]; // 所属项目名
        char name[30];    // 课程名
        char number[30];  // 课程号
        char place[30];   // 地点
        int time;         // 课程时间
        char date[30];    // 课程日期
        int score;        // 课程价格
        int max;          // 课程最大人数
        while (temp)
        {

            if (strcmp(temp->project, pro) == 0)
            {
                char road[100] = "C:\\Users\\lenovo\\Desktop\\课程\\";
                strcat(road, temp->name);
                strcat(road, ".txt");
                FILE *fp;
                fp = fopen(road, "rb");
                if (fp == NULL)
                {
                    printf("未找到课程文件\n");
                }
                else
                {
                    count++;
                    fscanf(fp, "%s %s %s %s %d %s %d %d ", project, name, number, place, &time, date, &score, &max);
                    printf("请输入修改后的项目名\n");
                    char newpro[30];
                    scanf("%s", newpro);
                    strcpy(project, newpro);
                    fclose(fp);
                    fp = fopen(road, "wb");
                    fprintf(fp, "\n%s %s %s %s %d %s %d %d ", project, name, number, place, time, date, score, max);
                    fclose(fp);
                }
                break;
            }
            temp = temp->next;
        }
        delcoulist(course);
        if (count == 0)
        {
            printf("未找到该项目\n");
        }
        break;
    }
    }
    filecopy();
}

void filecopy() // 文件备份
{
    int copyFile(char *fileRead, char *fileWrite);

    // 管理员文件
    char ro1[100] = "C:\\Users\\lenovo\\Desktop\\管理员.txt";
    char ro2[100] = "C:\\Users\\lenovo\\Desktop\\备份\\管理员.txt";
    copyFile(ro1, ro2);

    // 课程文件夹
    int copyFile(char *fileRead, char *fileWrite);
    char road1[100] = "C:\\Users\\lenovo\\Desktop\\课程\\课程.txt";
    char road2[100] = "C:\\Users\\lenovo\\Desktop\\备份\\课程\\课程.txt";
    copyFile(road1, road2);

    FILE *fp1;
    fp1 = fopen(road1, "rb");
    NAME *coursename = insertna(fp1);
    NAME *cur1 = coursename;
    while (cur1)
    {
        char road3[100] = "C:\\Users\\lenovo\\Desktop\\课程\\";
        char road4[100] = "C:\\Users\\lenovo\\Desktop\\备份\\课程\\";
        strcat(road3, cur1->name);
        strcat(road4, cur1->name);
        strcat(road3, ".txt");
        strcat(road4, ".txt");
        copyFile(road3, road4);
        cur1 = cur1->next;
    }
    fclose(fp1);
    // 学员文件夹
    char road5[100] = "C:\\Users\\lenovo\\Desktop\\学员\\学员.txt";
    char road6[100] = "C:\\Users\\lenovo\\Desktop\\备份\\学员\\学员.txt";
    copyFile(road5, road6);
    STUDENT *student = insertstu();
    STUDENT *cur2 = student;
    while (cur2)
    {
        char road3[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
        char road4[100] = "C:\\Users\\lenovo\\Desktop\\备份\\学员\\";
        strcat(road3, cur2->account);
        strcat(road4, cur2->account);
        strcat(road3, ".txt");
        strcat(road4, ".txt");
        copyFile(road3, road4);
        cur2 = cur2->next;
    }
    // 教练文件夹
    char road7[100] = "C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt";
    char road8[100] = "C:\\Users\\lenovo\\Desktop\\备份\\教练\\教练员.txt";
    copyFile(road7, road8);
    COACH *coach = insertco();
    COACH *cur3 = coach;
    while (cur3)
    {
        char road3[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
        char road4[100] = "C:\\Users\\lenovo\\Desktop\\备份\\教练\\";
        strcat(road3, cur3->account);
        strcat(road4, cur3->account);
        strcat(road3, ".txt");
        strcat(road4, ".txt");
        copyFile(road3, road4);
        cur3 = cur3->next;
    }

    // stu课程文件夹
    NAME *na1 = coursename;
    while (na1)
    {
        char road3[100] = "C:\\Users\\lenovo\\Desktop\\stu课程\\";
        char road4[100] = "C:\\Users\\lenovo\\Desktop\\备份\\stu课程\\";
        strcat(road3, na1->name);
        strcat(road4, na1->name);
        strcat(road3, ".txt");
        strcat(road4, ".txt");
        copyFile(road3, road4);
        na1 = na1->next;
    }

    // co课程文件夹
    NAME *na2 = coursename;
    while (na2)
    {
        char road3[100] = "C:\\Users\\lenovo\\Desktop\\co课程\\";
        char road4[100] = "C:\\Users\\lenovo\\Desktop\\备份\\co课程\\";
        strcat(road3, na2->name);
        strcat(road4, na2->name);
        strcat(road3, ".txt");
        strcat(road4, ".txt");
        copyFile(road3, road4);
        na2 = na2->next;
    }

    char road9[100] = "C:\\Users\\lenovo\\Desktop\\课程\\placename.txt";
    char road10[100] = "C:\\Users\\lenovo\\Desktop\\备份\\课程\\placename.txt";
    copyFile(road9, road10);
    char road11[100] = "C:\\Users\\lenovo\\Desktop\\课程\\projectname.txt";
    char road12[100] = "C:\\Users\\lenovo\\Desktop\\备份\\课程\\projectname.txt";
    copyFile(road11, road12);
    char road13[100] = "C:\\Users\\lenovo\\Desktop\\中转.txt";
    char road14[100] = "C:\\Users\\lenovo\\Desktop\\备份\\中转.txt";
    copyFile(road13, road14);
}

void redata() // 数据恢复
{
    int copyFile(char *fileRead, char *fileWrite);
    char road1[100] = "C:\\Users\\lenovo\\Desktop\\课程\\课程.txt";
    char road2[100] = "C:\\Users\\lenovo\\Desktop\\备份\\课程\\课程.txt";
    copyFile(road2, road1);

    FILE *fp1;
    fp1 = fopen(road2, "rb");
    NAME *coursename = insertna(fp1);
    NAME *cur1 = coursename;
    while (cur1)
    {
        char road3[100] = "C:\\Users\\lenovo\\Desktop\\课程\\";
        char road4[100] = "C:\\Users\\lenovo\\Desktop\\备份\\课程\\";
        strcat(road3, cur1->name);
        strcat(road4, cur1->name);
        strcat(road3, ".txt");
        strcat(road4, ".txt");
        copyFile(road4, road3);
        cur1 = cur1->next;
    }
    fclose(fp1);

    // 学员文件夹
    char road5[100] = "C:\\Users\\lenovo\\Desktop\\学员\\学员.txt";
    char road6[100] = "C:\\Users\\lenovo\\Desktop\\备份\\学员\\学员.txt";
    copyFile(road6, road5);
    STUDENT *student = insertstucopy();
    STUDENT *cur2 = student;
    while (cur2)
    {
        char road3[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
        char road4[100] = "C:\\Users\\lenovo\\Desktop\\备份\\学员\\";
        strcat(road3, cur2->account);
        strcat(road4, cur2->account);
        strcat(road3, ".txt");
        strcat(road4, ".txt");
        copyFile(road3, road4);
        cur2 = cur2->next;
    }
    // 教练文件夹
    char road7[100] = "C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt";
    char road8[100] = "C:\\Users\\lenovo\\Desktop\\备份\\教练\\教练员.txt";
    copyFile(road7, road8);
    COACH *coach = insertcocopy();
    COACH *cur3 = coach;
    while (cur3)
    {
        char road3[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
        char road4[100] = "C:\\Users\\lenovo\\Desktop\\备份\\教练\\";
        strcat(road3, cur3->account);
        strcat(road4, cur3->account);
        strcat(road3, ".txt");
        strcat(road4, ".txt");
        copyFile(road3, road4);
        cur3 = cur3->next;
    }

    // stu课程文件夹
    NAME *na1 = coursename;
    while (na1)
    {
        char road3[100] = "C:\\Users\\lenovo\\Desktop\\stu课程\\";
        char road4[100] = "C:\\Users\\lenovo\\Desktop\\备份\\stu课程\\";
        strcat(road3, na1->name);
        strcat(road4, na1->name);
        strcat(road3, ".txt");
        strcat(road4, ".txt");
        copyFile(road3, road4);
        na1 = na1->next;
    }

    // co课程文件夹
    NAME *na2 = coursename;
    while (na2)
    {
        char road3[100] = "C:\\Users\\lenovo\\Desktop\\co课程\\";
        char road4[100] = "C:\\Users\\lenovo\\Desktop\\备份\\co课程\\";
        strcat(road3, na2->name);
        strcat(road4, na2->name);
        strcat(road3, ".txt");
        strcat(road4, ".txt");
        copyFile(road3, road4);
        na2 = na2->next;
    }

    char road9[100] = "C:\\Users\\lenovo\\Desktop\\课程\\placename.txt";
    char road10[100] = "C:\\Users\\lenovo\\Desktop\\备份\\课程\\placename.txt";
    copyFile(road10, road9);
    char road11[100] = "C:\\Users\\lenovo\\Desktop\\课程\\projectname.txt";
    char road12[100] = "C:\\Users\\lenovo\\Desktop\\备份\\课程\\projectname.txt";
    copyFile(road12, road11);
    char road13[100] = "C:\\Users\\lenovo\\Desktop\\中转.txt";
    char road14[100] = "C:\\Users\\lenovo\\Desktop\\备份\\中转.txt";
    copyFile(road14, road13);
}

// 教练管理
void adcoach() // 教练管理
{
    printf("*****************************\n");
    printf("***       教练管理        ***\n");
    printf("***      1 等级修改       ***\n");
    printf("***      2 增加教练       ***\n");
    printf("***      3 删除教练       ***\n");
    printf("*****************************\n");
    printf("请输入您的选择:\n");
    char choice[20];
    scanf("%s", choice);
    int choice1 = atoi(choice);
    switch (choice1)
    {
    case 1:
        modcograde();
        break;
    case 2:
        addcoa();
        break;
    case 3:
        delcoa();
        break;
    default:
        break;
    }
    printf("是否继续教练管理？\n");
    printf("1：是\n");
    printf("2或其他：否\n");
    char order[20];
    scanf("%s", order);
    int order1 = atoi(order);
    if (order1 == 1)
    {
        adcoach(); // 教练管理
        return;
    }
    else
    {
        return;
    }
}

int copyFile(char *fileRead, char *fileWrite)
{
    FILE *fpRead;                             // 指向要复制的文件
    FILE *fpWrite;                            // 指向复制后的文件
    int bufferLen = 1024 * 4;                 // 缓冲区长度
    char *buffer = (char *)malloc(bufferLen); // 开辟缓存
    int readCount;                            // 实际读取的字节数
    if ((fpRead = fopen(fileRead, "r")) == NULL || (fpWrite = fopen(fileWrite, "w")) == NULL)
    {
    }
    // 不断从fileRead读取内容，放在缓冲区，再将缓冲区的内容写入fileWrite
    while ((readCount = fread(buffer, 1, bufferLen, fpRead)) > 0)
    {
        fwrite(buffer, readCount, 1, fpWrite);
    }
    free(buffer);
    fclose(fpRead);
    fclose(fpWrite);
    return 1;
}

void admodcour() // 管理员添加修改课程
{
    void modcou();    // 修改课程信息
    void addcourse(); // 仅用于添加课程是添加到指定文件
    printf("*****************************\n");
    printf("***       调整课程        ***\n");
    printf("***      1 修改课程       ***\n");
    printf("***      2 添加课程       ***\n");
    printf("*****************************\n");
    printf("请输入你的选择\n");
    char ch[20];
    scanf("%s", ch);
    int ch1 = atoi(ch);
    switch (ch1)
    {
    case 1:
    {
        modcou();
        break;
    }
    case 2:
    {
        addcourse();
        break;
    }
    default:
    {
        printf("输入错误\n");
    }

        printf("是否继续调整课程？\n");
        printf("1：是\n");
        printf("2或其他：否\n");
        int order;
        scanf("%d", &order);
        if (order == 1)
        {
            admodcour();
            return;
        }
        else
        {
            return;
        }
    }
}

void coudelcoa() // 课程删除教练
{
    filecopy();
    bool pancoach(char na[30]); // 判断教练是否存在
    printf("请输入课程名称\n");
    char na[30];
    scanf("%s", na);
    char road1[100] = "C:\\Users\\lenovo\\Desktop\\课程\\";
    strcat(road1, na);
    strcat(road1, ".txt");
    FILE *fp1;
    fp1 = fopen(road1, "r");
    char road2[100] = "C:\\Users\\lenovo\\Desktop\\co课程\\";
    strcat(road2, na);
    strcat(road2, ".txt");
    FILE *fp2;
    fp2 = fopen(road2, "r");
    if (fp1 == NULL)
    {
        printf("未找到该课程\n");
    }
    else
    {
        printf("请输入要删除的教练姓名\n");
        char coana[30];
        scanf("%s", coana);
        if (pancoach(coana))
        {
            NAME *name = (NAME *)malloc(sizeof(NAME));
            name = NULL;
            char cona2[30];
            while (!feof(fp2))
            {
                fscanf(fp2, "%s ", cona2);
                if (strcmp(cona2, coana) != 0)
                {
                    inname(&name, cona2);
                }
            }
            NAME *cur = name;
            fp2 = fopen(road2, "w");
            while (cur)
            {
                fprintf(fp2, "\n%s", cur->name);
                cur = cur->next;
            }
            COACH *coach = insertco();
            COACH *cur1 = coach;
            FILE *fp3;
            char acc[30];
            while (cur1)
            {
                if (strcmp(cur1->name, coana) == 0)
                {
                    strcpy(acc, cur1->account);
                    break;
                }
                cur1 = cur1->next;
            }

            char road3[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
            strcat(road3, acc);
            strcat(road3, ".txt");
            fp3 = fopen(road3, "r");
            COURSE *course = (COURSE *)malloc(sizeof(COURSE));
            course = NULL;
            while (!feof(fp3))
            {
                char project[30]; // 所属项目名
                char name[30];    // 课程名
                char number[30];  // 课程号
                char place[30];   // 地点
                int time;         // 课程时间
                char date[30];    // 课程日期
                int score;        // 课程价格
                int max;          // 课程最大人数
                fscanf(fp3, "%s %s %s %s %d %s %d %d ", project, name, number, place, &time, date, &score, &max);
                if (strcmp(name, na) != 0)
                {
                    incourse(&course, project, name, number, place, time, date, score, max);
                }
            }
            COURSE *cur2 = course;
            fp3 = fopen(road3, "w");
            while (cur2)
            {
                fprintf(fp3, "\n%s %s %s %s %d %s %d %d", cur2->project, cur2->name, cur2->number, cur2->place, cur2->time, cur2->date, cur2->score, cur2->max);
                cur2 = cur2->next;
            }
            fclose(fp3);
            delcoalist(coach);
            delnamelist(name);
        }
        else
        {
            printf("该教练不存在\n");
        }
        fclose(fp1);
        fclose(fp2);
    }
}

bool pancoach(char na[30]) // 判断教练是否存在
{
    COACH *coach = insertco();
    COACH *cur = coach;
    while (cur)
    {
        if (strcmp(cur->name, na) == 0)
        {

            return true;
        }
        cur = cur->next;
    }
    delcoalist(coach);
    return false;
}

void adpass() // 管理员修改自己密码
{
    ADMIN *insertad();
    ADMIN *admin = insertad();
    ADMIN *cur = admin;
    printf("请输入你的账号\n");
    char acc[30];
    scanf("%s", acc);
    char pass[30];
    while (cur)
    {
        if (strcmp(cur->account, acc) == 0)
        {
            strcpy(pass, cur->password);
            break;
        }
        cur = cur->next;
    }
    if (cur == NULL)
    {
        printf("该账号不存在\n");
    }
    else
    {
        char oldpass[30];
        printf("请输入原始密码\n");
        scanf("%s", oldpass);
        if (strcmp(oldpass, pass) == 0)
        {
            printf("请输入新密码\n");
            scanf("%s", pass);
            strcpy(cur->password, pass);
            char road[100] = "C:\\Users\\lenovo\\Desktop\\管理员.txt";
            FILE *fp;
            fp = fopen(road, "w");
            if (fp == NULL)
            {
                printf("打开文件失败。\n");
                return;
            }
            cur = admin;
            fp = fopen(road, "ab");
            while (cur)
            {
                fprintf(fp, "\n%s %s %s %s", cur->name, cur->number, cur->account, cur->password);
                cur = cur->next;
            }
            fclose(fp);
            printf("密码修改成功\n");
        }
        else
        {
            printf("密码输入错误。\n");
        }
        
        
        deladlist(admin);
    }
    // printf("是否继续修改密码？\n");
    // printf("1：是\n");
    // printf("2或其他：否\n");
    // int order;
    // scanf("%d", &order);
    // if (order == 1)
    // {
    //     adpass();
    //     return;
    // }
    // else
    // {
    //     return;
    // }
}

void resetcoapass() // 重置教练密码
{
    COACH *insertco();
    COACH *coach = insertco();
    COACH *cur = coach;
    printf("请输入你的账号\n");
    char acc[30];
    scanf("%s", acc);
    char pass[30];
    while (cur)
    {
        if (strcmp(cur->account, acc) == 0)
        {
            strcpy(pass, cur->password);
            break;
        }
        cur = cur->next;
    }
    if (cur == NULL)
    {
        printf("该账号不存在\n");
    }
    else
    {
        char oldpass[30];
        printf("请输入原始密码\n");
        scanf("%s", oldpass);
        if (strcmp(oldpass, pass) == 0)
        {
            printf("请输入新密码\n");
            scanf("%s", pass);
            strcpy(cur->password, pass);

            char road[100] = "C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt";
            FILE *fp;
            fp = fopen(road, "w");
            if (fp == NULL)
            {
                printf("打开文件失败。\n");
            }
            cur = coach;
            while (cur)
            {
                fprintf(fp, "\n%s %s %s %s %d", cur->name, cur->number, cur->account, cur->password, cur->level);
                cur = cur->next;
            }
            printf("密码修改成功\n");
        }
        else
        {
            printf("密码输入错误。\n");
        }
        delcoalist(coach);
    }
    printf("是否继续修改密码？\n");
    printf("1：是\n");
    printf("2或其他：否\n");
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        resetcoapass();
        return;
    }
    else
    {
        return;
    }
}

// void delse(char *pro,char* se) // 用于从项目删除课程信息
// {
//     NAME *insertna(FILE *fp); // 用于导入课程名到链表
//     FILE *fp;
//     fp=fopen(pro,"r");
//     if (fp == NULL)
//     {
//         printf("文件打开失败\n");
//     }
//     else
//     {
//         NAME *pre = name;
//     NAME *cur = name;
//         while (cur != NULL && strcmp(cur->name, se) != 0)
//     {
//         pre = cur;
//         cur = cur->next;
//     }
//     if (cur == NULL)
//     {
//         printf("课程不存在\n");
//     }
//     else if (cur == name)
//     {
//         name = name->next;
//         free(cur);
//     }
//     else
//     {
//         NAME *temp = cur;
//         pre->next = cur->next;
//         free(temp);
//         temp = NULL;
//     }
//     pre = name;
//     fp = fopen(pro, "wb+");
//     while (pre != NULL)
//     {
//         fprintf(fp, "%s\n", pre->name);
//         pre = pre->next;
//     }
//     printf("数据导入成功\n");
//     }
// }

bool panrename(NAME *name, char nam[30]) // 名字判重
{
    NAME *cur = name;
    while (cur)
    {
        if (strcmp(cur->name, nam) == 0)
        {
            return false;
        }
        cur = cur->next;
    }
    return true;
}

// 排序
int Coach_judge(COACH *new_coach) // 判断教练的注册信息是否正确,错误就返回0
{
    COACH *p;
    p = insertco();
    int j = 1;
    for (; p != NULL; p = p->next)
    {
        if (strcmp(p->account, new_coach->account) == 0)
        {
            printf("账号重复了呀\n");
            printf("请重新注册\n");
            j = 0;
            break;
        }
        if (strcmp(p->number, new_coach->number) == 0)
        {
            printf("号码重复了哟\n");
            printf("请重新注册\n");
            j = 0;
            break;
        }
    }
    if (strlen(new_coach->number) != 11)
    {
        printf("电话号码长度不符哦\n");
        printf("请重新注册\n");
        j = 0;
    }
    if (strlen(new_coach->account) >= 18)
    {
        printf("您的账号过长了呀\n");
        printf("请重新注册\n");
        j = 0;
    }
    return j;
}

void Coach_password(COACH *new_coach) // 输入密码
{
    int n = 0, j = 1; // j用于判断
    printf("请输入您的密码(6~18位哟): ");
    while (1)
    {
        char c = _getch(); // 使用getch函数获取用户输入的字符，不回显到屏幕
        if (c == '\r')     // 用户按下回车键时结束输入，\r可以把光标移到行首,\n不行的
        {
            new_coach->password[n] = '\0'; // 将字符串结束符添加到密码末尾
            break;
        }
        else if (c == '\b' && n > 0) // 用户按下退格键时删除一个字符
        {
            printf("\b \b"); // 删除一个字符的显示,第一个\b让光标后移一位,空格负责覆盖，这时光标再次后移，看着好像不变一样,最后一个\b负责后移一位，否则光标在空格之后
            n--;
        }
        else
        {
            new_coach->password[n] = c;
            printf("*"); // 显示星号代替密码字符
            n++;
        }
    }

    if (n > 18)
    {
        j = 0;
        memset(new_coach->password, 0, sizeof(new_coach->password)); // 清空密码数组,用memset更快
        printf("\n您的密码太长了,房房记不住了呀\n");
        printf("请您重新输入吧");
        Coach_password(new_coach);
    }

    if (n < 6)
    {
        j = 0;
        memset(new_coach->password, 0, sizeof(new_coach->password)); // 清空密码数组
        printf("\n您的密码有点短了呀,房房不喜欢\n");
        printf("请您重新输入吧\n");
        Coach_password(new_coach);
    }

    if (j)
    {
        printf("\n输入成功啦,庆祝一下,再来一次吧\n");
        char de_pass[30];
        int n = 0;
        while (1) // 重复过程
        {
            char c = _getch(); // 使用getch函数获取用户输入的字符，不回显到屏幕
            if (c == '\r')     // 用户按下回车键时结束输入，\r可以把光标移到行首,\n不行的
            {
                de_pass[n] = '\0'; // 将字符串结束符添加到密码末尾
                break;
            }
            else if (c == '\b' && n > 0) // 用户按下退格键时删除一个字符
            {
                printf("\b \b"); // 删除一个字符的显示
                n--;
            }
            else
            {
                de_pass[n] = c;
                printf("*"); // 显示星号代替密码字符
                n++;
            }
        }
        if (strcmp(de_pass, new_coach->password) == 0)
        {
            printf("\nBingGo!完成!教练真厉害\n");
        }
        else
        {
            printf("\n呜呜呜,怎么不一样呀,房房记不住了呀,重新来一次呗\n");
            Coach_password(new_coach);
        }
    }
}

void Coach_reg() // 教练注册函数
{
    char name[30];     // 姓名
    char number[30];   // 号码
    char account[30];  // 账号
    char password[30]; // 密码
    int level;         // 等级
    COACH *new_coach = (COACH *)malloc(sizeof(COACH));
    printf("教练尊姓大名呀: ");
    scanf("%s", name);
    printf("留个电话号码呗: ");
    scanf("%19s", number);
    printf("输入一下您的等级吧: ");
    scanf("%d", &level);
    printf("起个账号名吧(注意C.前缀已经为您添加):C.");
    scanf("%19s", account);
    char acc[30] = "C.";
    strcat(acc, account);
    strcpy(account, acc);
    strcpy(new_coach->name, name);
    strcpy(new_coach->number, number);
    strcpy(new_coach->account, account);
    strcpy(new_coach->password, password);
    new_coach->level = level;

    Coach_password(new_coach);
    int judge = Coach_judge(new_coach);
    if (judge != 0)
    {
        // 将新教练加入到教练文件中
        char road[100] = "C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt";
        FILE *fp = fopen(road, "ab+");
        if (fp != NULL)
        {

            fprintf(fp, "\n%s %s %s %s %d ", new_coach->name, new_coach->number, new_coach->account, new_coach->password, new_coach->level);
        }
        else
        {
            printf("无法创建文档。\n");
        }
        fclose(fp); // 关闭文件流
        // 开辟该教练的文件
        char f2[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
        strcat(f2, new_coach->account);
        strcat(f2, ".txt");
        FILE *file2 = fopen(f2, "w+");
        if (file2 == NULL)
        {
            printf("创建教练文档失败\n");
        }
        else
        {
            printf("创建成功\n");
        }
        fclose(file2);
        return;
    }
    else
    {
        printf("教练注册失败,请重试\n");
        Coach_reg();
    }
}
STUDENT *bo_insertstu() // 用于导入学员信息到链表
{
    void instu(STUDENT * *stu, char name[30], char account[30], char password[30], int score, char number[30]); // 学员信息入表
    FILE *fp;
    fp = fopen("C:\\Users\\lenovo\\Desktop\\学员\\学员.txt", "rb+");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
        return NULL;
    }
    STUDENT *stu = (STUDENT *)malloc(sizeof(STUDENT));
    stu = NULL;
    char name[30];
    // 姓名
    char account[30];
    // 账号
    char password[30]; // 密码
    int score;
    // 价格
    char number[30];
    // 号码
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %s %d %s ", name, account, password, &score, number);
        instu(&stu, name, account, password, score, number);
    }
    fclose(fp);
    return stu;
}

// 学员排序函数
void Coa_stu_order(COACH *coa);                     // 学员排序界面
void Stu_name_order();                              // 学员姓名排序
void part_Stu_name_order();                         // 部分学员姓名排序
void Stu_score_order();                             // 按学员价格排序
void Stu_account_order();                           // 按账号排序
void Stu_ScoAcc_order();                            // 按价格和账号排序
void Stu_swapNodes(STUDENT *node1, STUDENT *node2); // 互换单一教练的课程链表的结点
NAME *Coa_stuName_head(COACH *coa);                 // 得到教练对应学员的名称链表的头指针
// 部分学员排序
void P_Stu_score_order(STUDENT *stu);  // 按价格排序(部分)
void P_Stu_ScoAcc_order(STUDENT *stu); // 按账号和价格排序(部分)

// 纯课程排序
void Course_time_order(COURSE *Cou_head);            // 按时间排序课程
void Course_name_order(COURSE *Cou_head);            // 按课程名排序课程
void Course_DaTi_order(COURSE *Cou_head);            // 按日期和时间排序
void Course_Date_order(COURSE *Cou_head);            // 按日期排序
void Course_score_order(COURSE *Cou_head);           // 课程价格排序
void Course_ProCou_order(COURSE *Cou_head);          // 项目和课程排序
void Course_DaSco_order(COURSE *Cou_head);           // 日期和价格
int compareDates(char *date1, char *date2);          // 比较中文星期的大小
void Course_swapNodes(COURSE *node1, COURSE *node2); // 互换单一教练的课程链表的结点
// 教练课程排序函数
COURSE *Course_list_head(COACH *coa);                // 得到来访教练的课程链表的头指针
int compareDates(char *date1, char *date2);          // 比较中文星期的大小
void Course_swapNodes(COURSE *node1, COURSE *node2); // 互换单一教练的课程链表的结点

COURSE *Coa_Course_list_head(COACH *coa); // 获得来访教练的课程链表头指针
void Coa_Course_time_order(COACH *coa);   // 按时间排序课程
void Coa_Course_name_order(COACH *coa);   // 按课程名排序课程
void Coa_Course_DaTi_order(COACH *coa);   // 按星期期和时间排序
void Coa_Course_Date_order(COACH *coa);   // 按星期排序
void Coa_Course_score_order(COACH *coa);  // 课程价格排序
void Coa_Course_ProCou_order(COACH *coa); // 项目和课程排序
void Coa_Course_DaSco_order(COACH *coa);  // 日期和价格

void swap_name_nodes(NAME *name1, NAME *name2); // 交换名称节点
void Stu_Coa_name_order(NAME *name);

// 教练排序函数
void Coa_CouOrder_fun();                             // 教练排序界面
int Coach_CouOrder_num();                            // 得到排序教练的功能的对应数字
void swap_Coach_Nodes(COACH *coach1, COACH *coach2); // 交换教练链表的结点
void Coa_name_order();                               // 按姓名排序
void Coa_level_order();                              // 按教练等级排序
void Coa_account_order();                            // 按教练账号
void Coa_LeAcc_order();                              // 按教练等级和账号排序

// 部分教练排序
void P_Coa_account_order(COACH *coa); // 按教练账号

NAME *Coa_stuName_head(COACH *coa) // 得到教练对应学员的名称链表的头指针
{
    char road1[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
    strcat(road1, coa->account);
    strcat(road1, ".txt");
    FILE *fp1;
    fp1 = fopen(road1, "rb");
    if (fp1 == NULL)
    {
        printf("未找到教练，请确认账号是否正确\n");
        return NULL;
    }
    else
    {
        int count = 0;
        COURSE *course = (COURSE *)malloc(sizeof(course));
        course = NULL;
        char project[30];
        char nam[30];
        char number[30];
        char place[30];
        int time;
        char date[30];
        int score;
        int max;
        // 课程入表
        while (!feof(fp1))
        {
            fscanf(fp1, "%s %s %s %s %d %s %d %d ", project, nam, number, place, &time, date, &score, &max);
            incourse(&course, project, nam, number, place, time, date, score, max);
        }
        COURSE *cur = course;
        NAME *name = (NAME *)malloc(sizeof(NAME));
        name = NULL;
        while (cur != NULL)
        {
            char road2[100] = "C:\\Users\\lenovo\\Desktop\\stu课程\\";
            strcat(road2, cur->name);
            strcat(road2, ".txt");
            FILE *fp2;
            fp2 = fopen(road2, "rb");
            if (fp2 == NULL)
            {
                printf("文件打开失败\n");
                return NULL;
            }
            while (!feof(fp2))
            {
                char na[30];
                fscanf(fp2, "%s ", na);
                if (panrename(name, na) == true)
                {
                    inname(&name, na);
                    count++;
                }
            }
            fclose(fp2);
            cur = cur->next;
        }
        fclose(fp1);
        return name;
    }
}

void Stu_swapNodes(STUDENT *node1, STUDENT *node2)
{
    // 交换 name
    char name[30];
    strcpy(name, node1->name);
    strcpy(node1->name, node2->name);
    strcpy(node2->name, name);

    // 交换 account
    char account[30];
    strcpy(account, node1->account);
    strcpy(node1->account, node2->account);
    strcpy(node2->account, account);

    // 交换 password
    char password[30];
    strcpy(password, node1->password);
    strcpy(node1->password, node2->password);
    strcpy(node2->password, password);

    // 交换 score
    int score = node1->score;
    node1->score = node2->score;
    node2->score = score;

    // 交换 number
    char number[30];
    strcpy(number, node1->number);
    strcpy(node1->number, node2->number);
    strcpy(node2->number, number);
}

void Stu_name_order()
{
    STUDENT *student_head = insertstu();
    // 选择排序
    STUDENT *current, *index, *min;

    if (student_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = student_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (strcmp(min->name, index->name) > 0) // 按姓名排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            Stu_swapNodes(min, current);
        }
    }

    STUDENT *pre = student_head;
    while (pre != NULL)
    {
        printf("姓名:%s 账号:%s 会员费:%d 号码:%s\n", pre->name, pre->account, pre->score, pre->number);
        pre = pre->next;
    }
}

void Stu_score_order()
{
    STUDENT *student_head = insertstu(); // 这里要得到学员名称的头指针
    // 选择排序
    STUDENT *current, *index, *min;

    if (student_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = student_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if ((min->score) > (index->score)) // 按价格排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            Stu_swapNodes(min, current);
        }
    }

    STUDENT *pre = student_head;
    while (pre != NULL)
    {
        printf("姓名:%s 账号:%s 会员费:%d 号码:%s\n", pre->name, pre->account, pre->score, pre->number);
        pre = pre->next;
    }
}

void Stu_account_order()
{
    STUDENT *student_head = insertstu(); // 这里要得到学员的头指针
    // 选择排序
    STUDENT *current, *index, *min;

    if (student_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = student_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (strcmp(min->account, index->account) > 0) // 按账号排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            Stu_swapNodes(min, current);
        }
    }

    STUDENT *pre = student_head;
    while (pre != NULL)
    {
        printf("姓名:%s 账号:%s 会员费:%d 号码:%s\n", pre->name, pre->account, pre->score, pre->number);
        pre = pre->next;
    }
}

void Stu_ScoAcc_order() // 按账号和价格排序
{
    STUDENT *stu_head = insertstu();
    // 选择排序
    STUDENT *current, *index, *min;

    if (stu_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = stu_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (index->score < min->score) // 按价格排序
            {
                min = index;
            }
            else if (index->score == min->score) // 如果价格相同，则按账号排序
            {
                if (strcmp(min->account, index->account) > 0)
                {
                    min = index;
                }
            }
        }

        if (min != current)
        {
            Stu_swapNodes(min, current);
        }
    }

    STUDENT *pre = stu_head;
    while (pre != NULL)
    {
        printf("姓名:%s 账号:%s 价格:%d 号码:%s\n", pre->name, pre->account, pre->score, pre->number);
        pre = pre->next;
    }
}

// 部分学员排序
void P_Stu_score_order(STUDENT *stu) // 按价格排序(部分)
{
    STUDENT *student_head = stu; // 这里要得到学员的头指针
    // 选择排序
    STUDENT *current, *index, *min;

    if (student_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = student_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if ((min->account) > (index->account)) // 按价格排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            Stu_swapNodes(min, current);
        }
    }

    STUDENT *pre = student_head;
    while (pre != NULL)
    {
        printf("姓名:%s 账号:%s 价格:%d 号码:%s\n", pre->name, pre->account, pre->score, pre->number);
        pre = pre->next;
    }
}

void P_Stu_ScoAcc_order(STUDENT *stu) // 按账号和价格排序(部分)
{
    STUDENT *stu_head = stu;
    // 选择排序
    STUDENT *current, *index, *min;

    if (stu_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = stu_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (index->score < min->score) // 按价格排序
            {
                min = index;
            }
            else if (index->score == min->score) // 如果价格相同，则按账号排序
            {
                if (strcmp(min->account, index->account) > 0)
                {
                    min = index;
                }
            }
        }

        if (min != current)
        {
            Stu_swapNodes(min, current);
        }
    }
    STUDENT *pre = stu_head;
    while (pre != NULL)
    {
        printf("姓名:%s 账号:%s 价格:%d 号码:%s\n", pre->name, pre->account, pre->score, pre->number);
        pre = pre->next;
    }
}

// 课程排序
void Course_time_order(COURSE *Cou_head) // 按时间排序课程
{
    COURSE *Course_head = Cou_head;
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if ((index->time) < (min->time)) // 按时间排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }

    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
}

void Course_name_order(COURSE *Cou_head) // 按课程名排序课程
{
    COURSE *Course_head = Cou_head;
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (strcmp(min->name, index->name) > 0) // 按课程名排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }

    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }

    // Coa_change_course(coa,pre);//形参是教练指针和课程的指针,把更改后的内容写到文件里
}

void Course_Date_order(COURSE *Cou_head) // 按日期排序
{
    COURSE *Course_head = Cou_head;
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (compareDates(min->date, index->date) > 0) // 按日期排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }

    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }

    // Coa_change_course(coa,pre);//形参是教练指针和课程的指针,把更改后的内容写到文件里
}

void Course_DaTi_order(COURSE *Cou_head) // 按日期和时间排序
{
    COURSE *Course_head = Cou_head;
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (compareDates(index->date, min->date) < 0) // 按日期排序
            {
                min = index;
            }
            else if (strcmp(index->date, min->date) == 0) // 如果日期相同，则按时间排序
            {
                if (index->time < min->time)
                {
                    min = index;
                }
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }
    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
}

void Course_score_order(COURSE *Cou_head) // 按价格排序
{
    COURSE *Course_head = Cou_head;
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if ((index->score) < (min->score)) // 按时间排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }

    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
}

void Course_ProCou_order(COURSE *Cou_head) // 项目和课程排序
{
    COURSE *Course_head = Cou_head;
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (compareDates(index->project, min->project) < 0) // 按项目排序
            {
                min = index;
            }
            else if (strcmp(index->project, min->project) == 0) // 如果项目相同，则按课程排序
            {
                if (strcmp(index->name, min->name) < 0)
                {
                    min = index;
                }
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }

    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
}

void Course_DaSco_order(COURSE *Cou_head) // 日期和价格
{
    COURSE *Course_head = Cou_head;
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (compareDates(index->date, min->date) < 0) // 按日期排序
            {
                min = index;
            }
            else if (strcmp(index->date, min->date) == 0) // 如果日期相同，则按价格排序
            {
                if (index->score < min->score)
                {
                    min = index;
                }
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }

    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
}

void Course_swapNodes(COURSE *node1, COURSE *node2)
{
    COURSE temp; // 临时结点用于交换数据

    // 交换两个结点的数据
    strcpy(temp.project, node1->project);
    strcpy(temp.name, node1->name);
    strcpy(temp.number, node1->number);
    strcpy(temp.place, node1->place);
    temp.time = node1->time;
    strcpy(temp.date, node1->date);
    temp.score = node1->score;
    temp.max = node1->max;

    strcpy(node1->project, node2->project);
    strcpy(node1->name, node2->name);
    strcpy(node1->number, node2->number);
    strcpy(node1->place, node2->place);
    node1->time = node2->time;
    strcpy(node1->date, node2->date);
    node1->score = node2->score;
    node1->max = node2->max;

    strcpy(node2->project, temp.project);
    strcpy(node2->name, temp.name);
    strcpy(node2->number, temp.number);
    strcpy(node2->place, temp.place);
    node2->time = temp.time;
    strcpy(node2->date, temp.date);
    node2->score = temp.score;
    node2->max = temp.max;
}

COURSE *Coa_Course_list_head(COACH *coa) // 获得来访教练的课程链表头指针
{
    COURSE *head, *p1, *p2;
    head = NULL;
    FILE *p_coach;
    char filename[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
    char coa_acc[30];
    strcpy(coa_acc, coa->account);
    strcat(filename, coa_acc);
    strcat(filename, ".txt");
    p_coach = fopen(filename, "r"); // 文件名不可以,必须地址
    if (p_coach == NULL)
    {
        printf("文件打开失败\n"); // 文件打开失败
        return NULL;              // 表示文件打开失败，让文件指针指向空指针,释放文件指针所占用的内存空间，
    }
    while (!feof(p_coach)) // 判断是否到达文件末尾
    {
        p1 = (COURSE *)malloc(LEN_COURSE);                                                                                                    // 项目名 课程名 课程号 地点 课程时间 课程日期 课程价格 课程最大人数
        fscanf(p_coach, "%s %s %s %s %d %s %d %d ", p1->project, p1->name, p1->number, p1->place, &p1->time, p1->date, &p1->score, &p1->max); // ，呜呜呜，注意最后不要少了空格呀
        p1->next = NULL;
        if (head == NULL)
        {
            head = p1;
            p2 = p1;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
        }
    }
    fclose(p_coach);
    return head;
}

void Coa_Course_time_order(COACH *coa) // 按时间排序教练的课程
{
    COURSE *Course_head = Coa_Course_list_head(coa); // 得到来访教练的课程链表的头指针
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if ((index->time) < (min->time)) // 按时间排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }

    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
}

void Coa_Course_name_order(COACH *coa) // 按课程名排序课程
{
    COURSE *Course_head = Coa_Course_list_head(coa);
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (strcmp(min->name, index->name) > 0) // 按课程名排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }

    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
}

int compareDates(char *date1, char *date2) // 比较中文星期的大小
{
    // 定义一个星期的顺序数组，用于将中文星期转换为数字
    char *weekdays[] = {(char *)"星期一", (char *)"星期二", (char *)"星期三", (char *)"星期四", (char *)"星期五", (char *)"星期六", (char *)"星期日"};
    int weekday1 = -1, weekday2 = -1; // 随意设置，不为0~6即可

    // 查找date1和date2在星期数组中的位置
    for (int i = 0; i < 7; i++)
    {
        if (strcmp(date1, weekdays[i]) == 0)
        {
            weekday1 = i;
        }
        if (strcmp(date2, weekdays[i]) == 0)
        {
            weekday2 = i;
        }
    }

    // 如果都是星期，比较星期的顺序
    if (weekday1 != -1 && weekday2 != -1)
    {
        return weekday1 - weekday2;
    }
    else
    {
        // 如果不是星期，直接比较字符串
        return strcmp(date1, date2);
    }
}

void Coa_Course_Date_order(COACH *coa) // 按日期排序
{
    COURSE *Course_head = Coa_Course_list_head(coa);
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (compareDates(min->date, index->date) > 0) // 按日期排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }

    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
}

void Coa_Course_DaTi_order(COACH *coa) // 按日期和时间排序
{
    COURSE *Course_head = Coa_Course_list_head(coa);
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (compareDates(index->date, min->date) < 0) // 按日期排序
            {
                min = index;
            }
            else if (strcmp(index->date, min->date) == 0) // 如果日期相同，则按时间排序
            {
                if (index->time < min->time)
                {
                    min = index;
                }
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }

    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
}

void Coa_Course_score_order(COACH *coa) // 按价格排序
{
    COURSE *Course_head = Coa_Course_list_head(coa);
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if ((index->score) < (min->score)) // 按时间排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }

    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
}

void Coa_Course_ProCou_order(COACH *coa) // 项目和课程排序
{
    COURSE *Course_head = Coa_Course_list_head(coa);
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (compareDates(index->project, min->project) < 0) // 按项目排序
            {
                min = index;
            }
            else if (strcmp(index->project, min->project) == 0) // 如果项目相同，则按课程排序
            {
                if (strcmp(index->name, min->name) < 0)
                {
                    min = index;
                }
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }

    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
}

void Coa_Course_DaSco_order(COACH *coa) // 日期和价格
{
    COURSE *Course_head = Coa_Course_list_head(coa);
    // 选择排序
    COURSE *current, *index, *min;

    if (Course_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Course_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (compareDates(index->date, min->date) < 0) // 按日期排序
            {
                min = index;
            }
            else if (strcmp(index->date, min->date) == 0) // 如果日期相同，则按价格排序
            {
                if (index->score < min->score)
                {
                    min = index;
                }
            }
        }

        if (min != current)
        {
            Course_swapNodes(min, current);
        }
    }
    COURSE *pre = Course_head;
    while (pre != NULL)
    {
        int h = pre->time / 100; // 小时
        int m = pre->time % 100; // 分钟
        printf("项目名：%s 课程名：%s 课程号：%s 课程地点：%s 时间：%02d:%02d 日期：%s 费用：%d 最大报名人数%d\n", pre->project, pre->name, pre->number, pre->place, h, m, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
}

// 教练的学员按姓名排序
void part_Stu_name_order(NAME *name)
{
    NAME *name_head = name;
    NAME *current, *index, *min;

    if (name_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = name_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (strcmp(min->name, index->name) > 0) // 按姓名排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            swap_name_nodes(min, current);
        }
    }

    NAME *pre = name_head;
    while (pre != NULL)
    {
        printf("姓名:%s\n", pre->name);
        pre = pre->next;
    }
}

void swap_name_nodes(NAME *name1, NAME *name2)
{
    // 交换 name
    char tempName[30];
    strcpy(tempName, name1->name);
    strcpy(name1->name, name2->name);
    strcpy(name2->name, tempName);
}

void swap_Coach_Nodes(COACH *coach1, COACH *coach2)
{
    // 交换 name
    char tempName[30];
    strcpy(tempName, coach1->name);
    strcpy(coach1->name, coach2->name);
    strcpy(coach2->name, tempName);
    // 交换 number
    char tempNumber[30];
    strcpy(tempNumber, coach1->number);
    strcpy(coach1->number, coach2->number);
    strcpy(coach2->number, tempNumber);
    // 交换 account
    char tempAccount[30];
    strcpy(tempAccount, coach1->account);
    strcpy(coach1->account, coach2->account);
    strcpy(coach2->account, tempAccount);
    // 交换 password
    char tempPassword[30];
    strcpy(tempPassword, coach1->password);
    strcpy(coach1->password, coach2->password);
    strcpy(coach2->password, tempPassword);
    // 交换 level
    int tempLevel = coach1->level;
    coach1->level = coach2->level;
    coach2->level = tempLevel;
}
// 学员的教练
void Stu_Coa_name_order(NAME *name)
{
    NAME *name_head = name;
    NAME *current, *index, *min;

    if (name_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = name_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (strcmp(min->name, index->name) > 0) // 按姓名排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            swap_name_nodes(min, current);
        }
    }

    NAME *pre = name_head;
    while (pre != NULL)
    {
        printf("姓名:%s\n", pre->name);
        pre = pre->next;
    }
}

void Coa_name_order() // 按姓名排序
{
    COACH *Coa_head = insertco();
    // 选择排序
    COACH *current, *index, *min;

    if (Coa_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Coa_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (strcmp(min->name, index->name) > 0)
            {
                min = index;
            }
        }

        if (min != current)
        {
            swap_Coach_Nodes(min, current);
        }
    }

    COACH *pre = Coa_head; // 注意不要写成Coach_list_head()，否则输出无变化
    while (pre != NULL)
    {
        printf("姓名:%s 号码:%s 账号:%s 等级:%d\n", pre->name, pre->number, pre->account, pre->level);
        pre = pre->next;
    }
}

void Coa_level_order() // 按等级排序
{
    COACH *Coa_head = insertco();
    // 选择排序
    COACH *current, *index, *min;

    if (Coa_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Coa_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if ((min->level) > (index->level))
            {
                min = index;
            }
        }

        if (min != current)
        {
            swap_Coach_Nodes(min, current);
        }
    }

    COACH *pre = Coa_head;
    while (pre != NULL)
    {
        printf("姓名:%s 号码:%s 账号:%s 等级:%d\n", pre->name, pre->number, pre->account, pre->level);
        pre = pre->next;
    }
}

void Coa_account_order() // 按账号排序
{
    COACH *Coa_head = insertco();
    // 选择排序
    COACH *current, *index, *min;

    if (Coa_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Coa_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (strcmp(min->account, index->account) > 0) // 按课程名排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            swap_Coach_Nodes(min, current);
        }
    }

    COACH *pre = Coa_head;
    while (pre != NULL)
    {
        printf("姓名:%s 号码:%s 账号:%s 等级:%d\n", pre->name, pre->number, pre->account, pre->level);
        pre = pre->next;
    }
}

void Coa_LeAcc_order() // 按等级和账号排序
{
    COACH *Coa_head = insertco();
    // 选择排序
    COACH *current, *index, *min;

    if (Coa_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Coa_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if ((index->level) < (min->level)) // 按等级排序
            {
                min = index;
            }
            else if ((index->level) == (min->level)) // 如果等级相同，则按账号排序
            {
                if (strcmp(index->account, min->account) < 0)
                {
                    min = index;
                }
            }
        }

        if (min != current)
        {
            swap_Coach_Nodes(min, current);
        }
    }

    COACH *pre = Coa_head;
    while (pre != NULL)
    {
        printf("姓名:%s 号码:%s 账号:%s 等级:%d\n", pre->name, pre->number, pre->account, pre->level);
        pre = pre->next;
    }
}

void P_Coa_account_order(COACH *coa) // 按教练账号
{
    COACH *Coa_head = coa;
    // 选择排序
    COACH *current, *index, *min;

    if (Coa_head == NULL)
    {
        printf("课程链表为空，无法排序\n");
        return;
    }

    for (current = Coa_head; current->next != NULL; current = current->next)
    {
        min = current;
        for (index = current->next; index != NULL; index = index->next)
        {
            if (strcmp(min->account, index->account) > 0) // 按课程名排序
            {
                min = index;
            }
        }

        if (min != current)
        {
            swap_Coach_Nodes(min, current);
        }
    }

    COACH *pre = Coa_head;
    while (pre != NULL)
    {
        printf("姓名:%s 号码:%s 账号:%s 等级:%d\n", pre->name, pre->number, pre->account, pre->level);
        pre = pre->next;
    }
}

void Coa_change_pro1(COACH *coa) // 教练更改项目类型
{
    printf("输入项目名: ");
    char a[30];
    scanf("%s", a);

    printf("输入课程名: ");
    char a1[30];
    scanf("%s", a1);

    printf("输入课程号: ");
    char a2[30];
    scanf("%s", a2);

    printf("输入地点: ");
    char a3[30];
    scanf("%s", a3);

    printf("请输入课程时间(若时间为9:30请输入0930)\n"); // int
    int a4;
    scanf("%d", &a4);
    if(a4>2359||a4<0)
    {
        printf("时间不合法,请重试\n");
        Coa_change_pro1(coa);
        return;
    }

    printf("输入课程星期(周日请输入日，周一请输入一): ");
    char a5[30];
    scanf("%s", a5);
    if(strcmp(a5,"日")!=0&&strcmp(a5,"一")!=0&&strcmp(a5,"二")!=0&&strcmp(a5,"三")!=0&&strcmp(a5,"四")!=0&&strcmp(a5,"五")!=0&&strcmp(a5,"六")!=0)
    {
        printf("日期不合法,请重试\n");
        Coa_change_pro1(coa);
        return;
    }

    printf("输入课程价格: "); // int
    int a6;
    scanf("%d", &a6);
    if(a6<0)
    {
        printf("价格不合法,请重试\n");
        Coa_change_pro1(coa);
        return;
    }

    printf("输入课程人数: "); // int
    int a7;
    scanf("%d", &a7);
    if(a7<0)
    {
        printf("人数不合法,请重试\n");
        Coa_change_pro1(coa);
        return;
    }

    char filename[100] = "C:\\Users\\lenovo\\Desktop\\中转.txt";
    FILE *file = fopen(filename, "ab+");
    if (file != NULL)
    {
        if (fprintf(file, "\n%s %s %s %s %s %d %s %d %d", coa->account, a, a1, a2, a3, a4, a5, a6, a7) < 0)
        {
            printf("写入文件失败\n");
            return;
        }
        else
        {
            printf("文档创建成功并写入内容\n");
        }
        fclose(file); // 关闭文件流
    }
    else
    {
        printf("无法创建文档。\n");
    }
    char j[20];
    printf("**************************************************\n"); // 规范长度
    printf("***              是否继续提交课程申请？          ***\n");
    printf("***              1:是                          ***\n");
    printf("***              2或其他:否                     ***\n");
    printf("**************************************************\n"); // 规范长度
    scanf("%s", j);
    int k = atoi(j);
    if (k == 1)
    {
        Coa_change_pro1(coa);
        return;
    }
    else
    {
        return;
    }
}

COACH *Coach_list_head() // 获得教练链表头指针
{
    COACH *head, *p1, *p2;
    head = NULL;
    FILE *p_coach;
    p_coach = fopen("C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt", "r"); // 文件名不可以,必须地址
    if (p_coach == NULL)
    {
        printf("文件打开失败\n"); // 文件打开失败
        return NULL;              // 表示文件打开失败，让文件指针指向空指针,释放文件指针所占用的内存空间，
    }
    while (!feof(p_coach)) // 判断是否到达文件末尾
    {
        p1 = (COACH *)malloc(LEN_COACH);
        fscanf(p_coach, "%s %s %s %s %d ", p1->name, p1->number, p1->account, p1->password, &p1->level);
        p1->next = NULL;
        if (head == NULL)
        {
            head = p1;
            p2 = p1;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
        }
    }
    fclose(p_coach);
    return head;
}

COACH *Coach_p()
{
    COACH *co = (COACH *)malloc(LEN_COACH);
    COACH *insertco();
    char acc[30];
    char pass[30];
    printf("请输入教练账号\n");
    scanf("%s", acc);
    printf("请输入您的密码(不超过18位)(可以删除)\n");
    COACH *coach = insertco();
    COACH *cur = coach;
    int count = 0;
    while (cur != NULL)
    {
        if (strcmp(cur->account, acc) == 0)
        {
            count = 1;
            strcpy(pass, cur->password);
            strcpy(co->account, cur->account);
            strcpy(co->password, cur->password);
            strcpy(co->name, cur->name);
            strcpy(co->number, cur->number);
            co->level = cur->level;
            break;
        }
        cur = cur->next;
    }
    char str[30];

    while (1)
    {
        int i;
        for (i = 0; i < 20; i++)
        {
            if ((str[i] = getch()) != '\b' && str[i] != '\r')
            {
                putchar('*');
            }
            // getch()从控制台输入一各字符但是不显示
            /*
                当在第i个字符输入退格键时，会把第i-1个字符赋值为'\0',
                并将i指向i-2 ,经过循环的i++后，i就指向了刚刚赋值为 '\0'的位置
            */
            if (str[i] == '\b' && i > 0)
            {
                str[--i] = '\0';
                i--;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
            // 如果在最开始就按退格键，就让i=-1
            if (str[i] == '\b' && i == 0)
            {
                i = -1;
            }
            // 如果输入的是回车，就退出输入循环
            if (str[i] == '\r')
            {
                break;
            }
        }
        printf("\n");
        str[i] = '\0';
        if (i <= 0)
        {
            printf("密码输入中出现错误，请重新输入\n");
            continue;
        }
        else
        {
            break;
        }
    }

    if (strcmp(pass, str) == 0)
    {
        return co;
    }
    else
    {
        printf("账号或密码错误\n");
        return NULL;
    }
}

NAME *insertName() // 用于导入课程名到链表,返回课程名的链表的头指针
{
    NAME *head, *p1, *p2;
    head = NULL;
    FILE *p_course;
    p_course = fopen("C:\\Users\\lenovo\\Desktop\\课程\\课程.txt", "r"); // 文件名不可以,必须地址
    if (p_course == NULL)
    {
        printf("文件打开失败\n"); // 文件打开失败
        return NULL;              // 表示文件打开失败，让文件指针指向空指针,释放文件指针所占用的内存空间，
    }
    while (!feof(p_course)) // 判断是否到达文件末尾
    {
        p1 = (NAME *)malloc(LEN_COACH);
        fscanf(p_course, "%s ", p1->name);
        p1->next = NULL;
        if (head == NULL)
        {
            head = p1;
            p2 = p1;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
        }
    }
    fclose(p_course);
    p1 = head;
    return head;
}

STUDENT *stulogin()
{
    STUDENT *co = (STUDENT *)malloc(sizeof(STUDENT));
    STUDENT *insertstu();
    char acc[30];
    char pass[30];
    printf("请输入学员账号\n");
    scanf("%s", acc);
    printf("请输入您的密码(不超过18位)(可以删除)\n");
    STUDENT *student = insertstu();
    STUDENT *cur = student;
    int count = 0;
    while (cur != NULL)
    {
        if (strcmp(cur->account, acc) == 0)
        {
            count = 1;
            strcpy(pass, cur->password);
            strcpy(co->account, cur->account);
            strcpy(co->password, cur->password);
            strcpy(co->name, cur->name);
            strcpy(co->number, cur->number);
            co->score = cur->score;
            break;
        }
        cur = cur->next;
    }
    char str[30];

    while (1)
    {
        int i;
        for (i = 0; i < 20; i++)
        {
            if ((str[i] = getch()) != '\b' && str[i] != '\r')
            {
                putchar('*');
            }
            // getch()从控制台输入一各字符但是不显示
            /*
                当在第i个字符输入退格键时，会把第i-1个字符赋值为'\0',
                并将i指向i-2 ,经过循环的i++后，i就指向了刚刚赋值为 '\0'的位置
            */
            if (str[i] == '\b' && i > 0)
            {
                str[--i] = '\0';
                i--;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
            // 如果在最开始就按退格键，就让i=-1
            if (str[i] == '\b' && i == 0)
            {
                i = -1;
            }
            // 如果输入的是回车，就退出输入循环
            if (str[i] == '\r')
            {
                break;
            }
        }
        printf("\n");
        str[i] = '\0';
        if (i <= 0)
        {
            printf("密码输入中出现错误，请重新输入\n");
            continue;
        }
        else
        {
            break;
        }
    }

    if (strcmp(pass, str) == 0)
    {
        return co;
    }
    else
    {
        printf("账号或密码错误\n");
        return NULL;
    }
}

void Coa_pass_chg(COACH *coa)
{
    char boo[20];
    printf("这是您现在的密码: %s\n确认要修改吗?\n", coa->password);
    printf("想改的话,输入'1'吧\n算了的话,就输入其他吧\n");
    scanf("%s", boo);
    int boo1 = atoi(boo);
    if (boo1 == 1)
    {
        Coach_password(coa);

        FILE *fp; // 这里把密码写到文件里
        fp = fopen("C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt", "rb");
        COACH *coach = insertco();
        COACH *pre = coach;
        while (pre != NULL)
        {

            if (strcmp(pre->account, coa->account) == 0)
            {
                strcpy(pre->password, coa->password);
                break;
            }
            pre = pre->next;
        }
        pre = coach;
        fp = fopen("C:\\Users\\lenovo\\Desktop\\教练\\教练员.txt", "wb");
        while (pre != NULL)
        {
            fprintf(fp, "\n%s %s %s %s %d ", pre->name, pre->number, pre->account, pre->password, pre->level);
            pre = pre->next;
        }
        delcoalist(coach);
        printf("\n好棒,成功了呀\n");
    }
    printf("**************************************************\n"); // 规范长度
    printf("***              是否继续密码修改？              ***\n");
    printf("***              1:是                          ***\n");
    printf("***              2或其他:否                     ***\n");
    printf("**************************************************\n"); // 规范长度
    char i[20];
    scanf("%s", i);
    int i1 = atoi(i);
    
    if (i1 == 1)
    {
        Coa_pass_chg(coa);
        return;
    }
    else
    {
        return;
    }
}
// 统计

void setf(char account[])
{
    char a[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
    char c[10] = ".txt";
    strcat(a, account);
    strcat(a, c);
    FILE *fpr = fopen(a, "a");
    if (fpr == NULL)
        printf("创建文件失败");
    else
        fclose(fpr);
}

void courseperiod(STUDENT *student) // 统计某时间段内课程花销(ok)
{
    int cost = 0;
    printf("请输入起始时间(星期几)：\n");
    // int y, m, d;
    char start[30];
    scanf("%s", start);
    // int week1 = get_Week(y, m, d);
    printf("请输入结束时间(星期几)(结束时间应大于起始时间！)：\n");
    // int y1, m1, d1;
    char end[30];
    scanf("%s", end);
    if (compareDates(start, end) > 0)
    {
        char temp[30];
        strcpy(temp, start);
        strcpy(start, end);
        strcpy(end, temp);
    }
    char path[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
    strcat(path, student->account);
    strcat(path, ".txt");
    FILE *fpr = fopen(path, "rb");

    if (fpr == NULL)
    {
        printf("文件打开失败，请确认是否存在该文件\n");
    }
    else
    {
        char project[30]; // 项目
        char name[30];    // 课程名
        char number[30];  // 课程号
        char place[30];   // 上课地点
        int time;         // 开始时间
        char date[30];    // 上课日期
        int score;        // 花费
        int max;          // 最大人数
        while (!feof(fpr))
        {
            fscanf(fpr, "%s %s %s %s %d %s %d %d ", project, name, number, place, &time, date, &score, &max);
            if (compareDates(start, end) < 0)
            {
                if (compareDates(start, date) <= 0 && compareDates(date, end) <= 0)
                {
                    cost += score;
                }
            }
            else if (compareDates(start, end) == 0)
            {
                if (strcmp(start, date) == 0)
                {
                    cost += score;
                }
            }
        }
        fclose(fpr);

        printf("总花费：%d\n", cost);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        courseperiod(student);
        return;
    }
    else
    {
        return;
    }
}

void cocourseperiod(COACH *coach) // 教练某时间范围内负责的课程数(ok)(教练使用)
{
    int count = 0;
    printf("请输入起始时间(星期几)：\n");
    // int y, m, d;
    char start[30];
    scanf("%s", start);
    // int week1 = get_Week(y, m, d);
    printf("请输入结束时间(星期几)(结束时间应大于起始时间！)：\n");
    // int y1, m1, d1;
    char end[30];
    scanf("%s", end);
    if (compareDates(start, end) > 0)
    {
        char temp[30];
        strcpy(temp, start);
        strcpy(start, end);
        strcpy(end, temp);
    }
    char path[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
    strcat(path, coach->account);
    strcat(path, ".txt");
    FILE *fpr = fopen(path, "r");
    if (fpr == NULL)
    {
        printf("文件打开失败\n");
    }
    else
    {
        char project[30]; // 项目
        char name[30];
        // 课程名
        char number[30];
        // 课程号
        char place[30];
        // 上课地点
        int time;
        // 开始时间
        char date[30];
        // 上课日期
        int score;
        // 花费
        int max;
        // 最大人数
        while (!feof(fpr))
        {
            fscanf(fpr, "%s %s %s %s %d %s %d %d ", project, name, number, place, &time, date, &score, &max);
            if (compareDates(start, end) < 0)
            {
                if (compareDates(start, date) <= 0 && compareDates(date, end) <= 0)
                {
                    count++;
                }
                else if (compareDates(start, end) == 0)
                {
                    if (strcmp(start, date) == 0)
                    {
                        count++;
                    }
                }
            }
        }
        fclose(fpr);
        printf("该教练负责的课程数量为%d\n", count);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;

    scanf("%d", &order);
    if (order == 1)
    {
        cocourseperiod(coach);
        return;
    }
    else
    {
        return;
    }
}

void stucourseperiod(STUDENT *student) // 学员统计某时间范围内上课数量(ok)
{

    int count = 0;
    printf("请输入起始时间:(星期几)\n");
    // int y, m, d;
    char start[30];
    scanf("%s", start);
    // int week1 = get_Week(y, m, d);
    printf("请输入结束时间（星期几)(结束时间应大于等于起始时间，如果不满足将自动调换顺序！)：\n");
    // int y1, m1, d1;
    char end[30];
    scanf("%s", end);
    if (compareDates(start, end) > 0)
    {
        char temp[30];
        strcpy(temp, start);
        strcpy(start, end);
        strcpy(end, temp);
    }
    char path[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
    strcat(path, student->account);
    strcat(path, ".txt");
    FILE *fpr = fopen(path, "r");
    if (fpr == NULL)
    {
        printf("文件打开失败\n");
    }
    else
    {
        char Project1[30];
        char Name1[30];
        char Number1[30];
        char Place1[30];
        int Time1; // 开始时间
        char Date1[30];
        int Score1;
        int Max1;

        while (!feof(fpr))
        {
            fscanf(fpr, "%s %s %s %s %d %s %d %d ", Project1, Name1, Number1, Place1, &Time1, Date1, &Score1, &Max1);

            if (compareDates(start, end) < 0)
            {
                if (compareDates(start, Date1) <= 0 && compareDates(Date1, end) <= 0)
                {
                    count++;
                }
            }
            else if (compareDates(start, end) == 0)
            {
                if (strcmp(start, Date1) == 0)
                {
                    count++;
                }
            }
        }
        fclose(fpr);
        printf("您在这段时间内共%d门课程\n", count);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        stucourseperiod(student);
        return;
    }
    else
    {
        return;
    }
}

void coursepro() // 按项目名称统计课程(1)(ok)
{
    printf("请选择您想按什么项目统计课程数量：\n");
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\projectname.txt", "r");

    NAME *proheadna = insertna(fp);
    NAME *proheadna1 = proheadna;
    int i = 1;
    int j = 1;
    printf("*************************************************\n"); // 规范长度
    while (proheadna != NULL)
    {
        printf("%d.%s\n", i, proheadna->name);
        proheadna = proheadna->next;
        i++;
    }
    printf("*************************************************\n"); // 规范长度
    fclose(fp);

    int a;
    char project[30];
    scanf("%d", &a);
    if (a < 1 || a > i)
    {
        printf("输入有误\n");
    }
    else
    {
        while (proheadna1 != NULL)
        {
            if (a == j)
            {
                strcpy(project, proheadna1->name);
                break;
            }
            else
            {
                j++;
                proheadna1 = proheadna1->next;
            }
        }
        delnamelist(proheadna);
        int count = 0;
        // 先将课程名读入链表
        // 每读一个课程名就到course文件夹里找对应的文件，打开验证项目名称是否相等
        COURSE *cohead = insertallse(); // 将课程信息读入链表
                                        /*while (cohead != NULL)
                                        {
                                            printf("%s\n", cohead->project);
                                            cohead=cohead->next;
                                        }*/
        while (cohead != NULL)
        {

            if (strcmp(cohead->project, project) == 0)
            {
                count++;
            }
            else
            {
                cohead->flag = false;
            }
            cohead = cohead->next;
        }
        delnamelist(proheadna);
        delcoulist(cohead);

        printf("该项目下共有%d门课程\n", count);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        coursepro();
        return;
    }
    else
    {
        return;
    }
}
// 统计课程的教练数量，学员数量
void coursecostu() // 某课程下有多少教练学员
{
    int count1 = 0;
    int count2 = 0;
    printf("请输入您想查询的课程：\n");
    char coursename[30];
    scanf("%s", coursename);
    char path1[100] = "C:\\Users\\lenovo\\Desktop\\co课程\\";
    strcat(path1, coursename);
    strcat(path1, ".txt");
    FILE *fpr1 = fopen(path1, "rb");

    char path2[100] = "C:\\Users\\lenovo\\Desktop\\stu课程\\";
    strcat(path2, coursename);
    strcat(path2, ".txt");
    FILE *fpr2 = fopen(path2, "rb");
    if (fpr1 == NULL || fpr2 == NULL)
    {
        printf("课程不存在\n");
    }
    else
    {
        NAME *conahead = insertna(fpr1);
        NAME *cur1 = conahead;
        while (cur1 != NULL)
        {
            count1++;
            cur1 = cur1->next;
        }
        delnamelist(conahead);

        NAME *stunahead = insertna(fpr2);
        NAME *cur2 = stunahead;
        while (cur2 != NULL)
        {
            count2++;
            cur2 = cur2->next;
        }
        delnamelist(stunahead);
        // fclose(fpr1);
        // fclose(fpr2);
        printf("该课程下有%d个教练，%d个学员\n", count1, count2);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        coursecostu();
        return;
    }
    else
    {
        return;
    }
}

void courseco() // 某课程下有多少学员
{
    int count = 0;
    printf("请输入您想查询的课程：\n");
    char coursename[30];
    scanf("%s", coursename);
    char path[100] = "";
    strcat(path, coursename);
    strcat(path, ".txt");
    FILE *fpr = fopen(path, "r");
    if (fpr = NULL)
    {
        printf("这个课程不存在，请重新输入！\n");
    }
    else
    {
        NAME *conahead = insertna(fpr);
        while (conahead != NULL)
        {
            count++;
            conahead = conahead->next;
        }
        delnamelist(conahead);
        fclose(fpr);
        printf("该课程下有%d个学员\n", count);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        courseco();
        return;
    }
    else
    {
        return;
    }
}

void courseplace() // 按上课地点统计课程(2)(ok)(管理员)
{
    printf("请选择您想按什么上课地点统计课程数量：\n");
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\placename.txt", "r");
    NAME *proheadna = insertna(fp);
    NAME *proheadna1 = proheadna;
    int i = 1;
    int j = 1;
    printf("*************************************************\n"); // 规范长度
    while (proheadna != NULL)
    {
        printf("%d.%s\n", i, proheadna->name);
        proheadna = proheadna->next;
        i++;
    }
    printf("*************************************************\n"); // 规范长度
    fclose(fp);

    int a;
    char place[30];
    scanf("%d", &a);
    if (a < 1 || a > i)
    {
        printf("输入有误\n");
    }
    else
    {
        while (proheadna1 != NULL)
        {
            if (a == j)
            {
                strcpy(place, proheadna1->name);
                break;
            }
            else
            {
                j++;
                proheadna1 = proheadna1->next;
            }
        }
        delnamelist(proheadna);

        // 先将课程名读入链表
        // 每读一个课程名就到course文件夹里找对应的文件，打开验证项目名称是否相等
        int count = 0;
        COURSE *cohead = insertallse(); // 将课程信息读入链表
        while (cohead != NULL)
        {

            if (strcmp(cohead->place, place) == 0)
            {
                count++;
            }
            else
            {
                cohead->flag = false;
            }
            cohead = cohead->next;
        }
        delnamelist(proheadna);
        delcoulist(cohead);

        printf("该地点共%d门课程\n", count);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        courseplace();
        return;
    }
    else
    {
        return;
    }
}

void coursetime() // 按上课时间统计课程(3)(ok)
{
    printf("*************************************************\n"); // 规范长度
    printf("***    请选择您想按什么上课时间统计课程数量       ***\n");
    printf("***           1.上午(0:00-11:59)                ***\n"
           "***           2.下午(12:00-17:59)               ***\n"
           "***           3.晚上(18:00-23:59)               ***\n");
    printf("*************************************************\n"); // 规范长度
    int a;
    scanf("%d", &a);
    int count = 0;
    if (a < 1 || a > 3)
    {
        printf("输入有误\n");
    }
    else
    {
        COURSE *cohead = insertallse();
        if (a == 1)
        {
            while (cohead != NULL)
            {
                if (cohead->time >= 0 && cohead->time <= 1159)
                {
                    count++;
                }
                cohead = cohead->next;
            }
        }
        else if (a == 2)
        {
            while (cohead != NULL)
            {
                if (cohead->time >= 1200 && cohead->time <= 1759)
                {
                    count++;
                }
                cohead = cohead->next;
            }
        }
        else if (a == 3)
        {
            while (cohead != NULL)
            {
                if (cohead->time >= 1800 && cohead->time <= 2359)
                {
                    count++;
                }
                cohead = cohead->next;
            }
        }
        delcoulist(cohead);
        printf("该时间段共%d门课程\n", count);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        coursetime();
        return;
    }
    else
    {
        return;
    }
}

void courseprotime() // 按项目上课时间统计课程(4多属性)(OK)
{
    int count = 0;
    printf("*************************************************\n"); // 规范长度
    printf("请选择您想按什么项目统计课程数量：\n");
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\projectname.txt", "r");
    NAME *proheadna = insertna(fp);
    NAME *proheadna1 = proheadna;
    int i = 1;
    int j = 1;
    while (proheadna != NULL)
    {
        printf("%d.%s\n", i, proheadna->name);
        proheadna = proheadna->next;
        i++;
    }
    printf("*************************************************\n"); // 规范长度
    fclose(fp);

    int a;
    char project[30];
    scanf("%d", &a);
    if (a < 1 || a > i)
    {
        printf("输入有误\n");
    }
    else
    {
        while (proheadna1 != NULL)
        {
            if (a == j)
            {
                strcpy(project, proheadna1->name);
                break;
            }
            else
            {
                j++;
                proheadna1 = proheadna1->next;
            }
        }
        delnamelist(proheadna);
        // 先将课程名读入链表
        // 每读一个课程名就到course文件夹里找对应的文件，打开验证项目名称是否相等

        COURSE *cohead = insertallse(); // 将课程信息读入链表
        COURSE *cohead1 = cohead;       // 保存课程头指针

        while (cohead != NULL)
        {
            if (strcmp(cohead->project, project) != 0)
            {
                cohead->flag = false;
            }
            cohead = cohead->next;
        }

        printf("*************************************************\n"); // 规范长度
        printf("***    请选择您想按什么上课时间统计课程数量       ***\n");
        printf("***           1.上午(0:00-11:59)                ***\n"
               "***           2.下午(12:00-17:59)               ***\n"
               "***           3.晚上(18:00-23:59)               ***\n");
        printf("*************************************************\n"); // 规范长度
        int c;
        scanf("%d", &c);
        if (c < 1 || c > 3)
        {
            printf("输入有误\n");
        }
        else
        {
            if (c == 1)
            {
                while (cohead1 != NULL)
                {
                    if ((cohead1->time >= 0 && cohead1->time <= 1159) && (cohead1->flag == true))
                    {
                        count++;
                    }
                    cohead1 = cohead1->next;
                }
            }
            else if (c == 2)
            {
                while (cohead1 != NULL)
                {
                    if ((cohead1->time >= 1200 && cohead1->time <= 1759) && (cohead1->flag == true))
                    {
                        count++;
                    }
                    cohead1 = cohead1->next;
                }
            }
            else if (c == 3)
            {
                while (cohead1 != NULL)
                {
                    if ((cohead1->time >= 1800 && cohead1->time <= 2359) && (cohead1->flag == true))
                    {
                        count++;
                    }
                    cohead1 = cohead1->next;
                }
            }

            delcoulist(cohead);

            printf("该项目，上课时间下共%d门课程\n", count);
        }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        courseprotime();
        return;
    }
    else
    {
        return;
    }
}

void courseplacetime() // 按上课地点上课时间统计课程(5多属性)(ok)
{
    int count = 0;
    printf("*************************************************\n"); // 规范长度
    printf("请选择您想按什么上课地点统计课程数量：\n");
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\placename.txt", "r");
    NAME *proheadna = insertna(fp);
    NAME *proheadna1 = proheadna;
    int i = 1;
    int j = 1;
    while (proheadna != NULL)
    {
        printf("%d.%s\n", i, proheadna->name);
        proheadna = proheadna->next;
        i++;
    }
    printf("*************************************************\n"); // 规范长度
    fclose(fp);

    int b;
    char place[30];
    scanf("%d", &b);
    if (b < 1 || b > i)
    {
        printf("输入有误\n");
    }
    else
    {
        while (proheadna1 != NULL)
        {
            if (b == j)
            {
                strcpy(place, proheadna1->name);
                break;
            }
            else
            {
                j++;
                proheadna1 = proheadna1->next;
            }
        }
        delnamelist(proheadna);
        // 先将课程名读入链表
        // 每读一个课程名就到course文件夹里找对应的文件，打开验证项目名称是否相等

        COURSE *cohead = insertallse(); // 将课程信息读入链表
        COURSE *cohead1 = cohead; // 保存课程头指针
        while (cohead != NULL)
        {
            if (strcmp(place, cohead->place) != 0)
            {
                cohead->flag = false;
            }
            cohead = cohead->next;
        }
        cohead=cohead1;
        printf("*************************************************\n"); // 规范长度
        printf("***    请选择您想按什么上课时间统计课程数量       ***\n");
        printf("***           1.上午(0:00-11:59)                ***\n"
               "***           2.下午(12:00-17:59)               ***\n"
               "***           3.晚上(18:00-23:59)               ***\n");
        printf("*************************************************\n"); // 规范长度
        int a;
        scanf("%d", &a);
        if (a < 1 || a > 3)
        {
            printf("输入错误！\n");
        }
        else
        {
            if (a == 1)
            {
                while (cohead1 != NULL)
                {
                    if ((cohead1->time >= 0 && cohead1->time <= 1159) && (cohead1->flag == true))
                    {
                        count++;
                    }
                    cohead1 = cohead1->next;
                }
            }
            else if (a == 2)
            {
                while (cohead1 != NULL)
                {
                    if ((cohead1->time >= 1200 && cohead1->time <= 1759) && (cohead1->flag == true))
                    {
                        count++;
                    }
                    cohead1 = cohead1->next;
                }
            }
            else if (a == 3)
            {
                while (cohead1 != NULL)
                {
                    if ((cohead1->time >= 1800 && cohead1->time <= 2359) && (cohead1->flag == true))
                    {
                        count++;
                    }
                    cohead1 = cohead1->next;
                }
            }
            else
            {
                printf("输入错误\n");
            }
            delcoulist(cohead);

            printf("该上课地点，上课时间下共%d门课程\n", count);
        }
    }
    return;
}

void cocoursestu(COACH *coach) // 教练统计某学生上自己的课的数量(ok)(教练使用)
{
    int count = 0;
    char path1[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
    strcat(path1, coach->account);
    strcat(path1, ".txt");
    FILE *cofp = fopen(path1, "r");
    printf("请输入您想查询的学员账号：\n");
    char stuaccount[30];
    scanf("%s", stuaccount);
    char path2[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
    strcat(path2, stuaccount);
    strcat(path2, ".txt");
    FILE *stufp = fopen(path2, "r");
    if (cofp == NULL || stufp == NULL)
    {
        printf("文件打开失败\n");
    }
    else
    {
        char coproject[30];
        char coname[30];
        char conumber[30];
        char coplace[30];
        int cotime;
        char codate[30];
        int coscore;
        int comax;
        char stuproject[30];
        char stuname[30];   // 课程名
        char stunumber[30]; // 课程号
        char stuplace[30];  // 上课地点
        int stutime;        // 开始时间
        char studate[30];   // 上课日期
        int stuscore;       // 花费
        int stumax;         // 最大人数
        while (fscanf(cofp, "%s %s %s %s %d %s %d %d ", coproject, coname, conumber, coplace, &cotime, codate, &coscore, &comax) != -1)
        {

            while (fscanf(stufp, "%s %s %s %s %d %s %d %d ", stuproject, stuname, stunumber, stuplace, &stutime, studate, &stuscore, &stumax) != -1)
            {

                if (strcmp(coname, stuname) == 0)
                {
                    count++;

                    break;
                }
            }
            printf("\n");
            rewind(stufp);
        }
        fclose(stufp);
        fclose(cofp);
        printf("该学员一共上了%d节您的课", count);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        cocoursestu(coach);
        return;
    }
    else
    {
        return;
    }
}

void cocourse() // 某教练教的课程数量(ok)
{
    printf("请输入想查询的教练账号：\n");
    char account[30];
    scanf("%s", account);
    char path[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
    strcat(path, account);
    strcat(path, ".txt");
    FILE *fpr = fopen(path, "r");
    if (fpr == NULL)
    {
        printf("没有该教练的信息\n");
    }
    else
    {
        char project[30]; // 项目
        char name[30];    // 课程名
        char number[30];  // 课程号
        char place[30];   // 上课地点
        int time;         // 开始时间
        char date[30];    // 上课日期
        int score;        // 花费
        int max;          // 最大人数
        char na[30] = {0};
        int count = 0;
        while (fscanf(fpr, "%s %s %s %s %d %s %d %d ", project, name, number, place, &time, date, &score, &max) != -1)
        {
            if (strcmp(name, na) != 0)
            {
                count++;
                strcpy(na, name);
            }
        }
        fclose(fpr);
        printf("该教练教的课程数量为%d门\n", count);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        cocourse();
        return;
    }
    else
    {
        return;
    }
}

void stucourse() // 某学生报的课程数量(ok)
{
    printf("请输入想查询的学员账号：\n");
    char account[30];
    scanf("%s", account);
    char path[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
    strcat(path, account);
    strcat(path, ".txt");
    FILE *fpr = fopen(path, "r");
    if (fpr == NULL)
    {
        printf("该学员不存在\n");
    }
    else
    {
        char project[30]; // 项目
        char name[30];    // 课程名
        char number[30];  // 课程号
        char place[30];   // 上课地点
        int time;         // 开始时间
        char date[30];    // 上课日期
        int score;        // 花费
        int max;          // 最大人数
        char na[30] = {0};
        int count = 0;
        while (fscanf(fpr, "%s %s %s %s %d %s %d %d ", project, name, number, place, &time, date, &score, &max) != -1)
        {
            if (strcmp(name, na) != 0)
            {
                count++;
                strcpy(na, name);
            }
        }
        fclose(fpr);
        printf("该学员报的课程数量为%d门\n", count);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        stucourse();
        return;
    }
    else
    {
        return;
    }
}

void number() // 输入电话
{
    int b = 1;
    FILE *fpr;
    fpr = fopen("C:\\Users\\lenovo\\Desktop\\学员\\学员.txt", "a");
    while (b)
    {
        printf("请输入电话号码（11位）：\n");
        char num[30];
        scanf("%s", num);
        int len = strlen(num);
        if (len != 11)
        {
            printf("号码长度不正确！\n");
            continue;
        }
        else
        {
            fputs(num, fpr);
            fputs(" ", fpr);
            b = 0;
        }
        break;
    }
}

void cocoursepro(COACH *coa) // 教练按项目名称统计课程(1)(ok)
{
    printf("请选择您想按什么项目统计课程数量：\n");
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\projectname.txt", "r");
    NAME *proheadna = insertna(fp);
    NAME *proheadna1 = proheadna;
    NAME *tem = proheadna;
    int i = 1;
    int j = 1;
    printf("*************************************************\n"); // 规范长度
    while (proheadna != NULL)
    {
        printf("%d.%s\n", i, proheadna->name);
        proheadna = proheadna->next;
        i++;
    }
    printf("*************************************************\n"); // 规范长度
    fclose(fp);

    int a;
    char project[30];
    scanf("%d", &a);
    if (a < 1 || a > i)
    {
        printf("输入有误\n");
    }
    else
    {
        while (proheadna1 != NULL)
        {
            if (a == j)
            {
                strcpy(project, proheadna1->name);
                break;
            }
            else
            {
                j++;
                proheadna1 = proheadna1->next;
            }
        }
        delnamelist(tem);
        int count = 0;
        // 先将课程名读入链表
        // 每读一个课程名就到course文件夹里找对应的文件，打开验证项目名称是否相等
        char path[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
        strcat(path, coa->account);
        strcat(path, ".txt");
        FILE *fpr = fopen(path, "r");
        if (fpr == NULL)
        {
            printf("该教练不存在\n");
        }
        else
        {
            COURSE *cohead = insertse(fp); // 将课程信息读入链表
                                           /*while (cohead != NULL)
                                           {
                                               printf("%s\n", cohead->project);
                                               cohead=cohead->next;
                                           }*/
            while (cohead != NULL)
            {

                if (strcmp(cohead->project, project) == 0)
                {
                    count++;
                }
                else
                {
                    cohead->flag = false;
                }
                cohead = cohead->next;
            }
            delnamelist(proheadna);
            delcoulist(cohead);
            fclose(fpr);
            printf("该项目下共有%d门课程\n", count);
        }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        cocoursepro(coa);
        return;
    }
    else
    {
        return;
    }
}

void cocourseplace(COACH *coa) // 教练按上课地点统计课程(2)(ok)(管理员)
{
    printf("*************************************************\n"); // 规范长度
    printf("请选择您想按什么上课地点统计课程数量：\n");
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\placename.txt", "r");
    NAME *proheadna = insertna(fp);
    NAME *proheadna1 = proheadna;
    NAME *tem = proheadna;
    int i = 1;
    int j = 1;
    while (proheadna != NULL)
    {
        printf("%d.%s\n", i, proheadna->name);
        proheadna = proheadna->next;
        i++;
    }
    printf("*************************************************\n"); // 规范长度
    fclose(fp);

    int a;
    char place[30];
    scanf("%d", &a);
    if (a < 1 || a > i)
    {
        printf("输入有误\n");
    }
    else
    {
        while (proheadna1 != NULL)
        {
            if (a == j)
            {
                strcpy(place, proheadna1->name);
                break;
            }
            else
            {
                j++;
                proheadna1 = proheadna1->next;
            }
        }
        delnamelist(tem);

        // 先将课程名读入链表
        // 每读一个课程名就到course文件夹里找对应的文件，打开验证项目名称是否相等
        int count = 0;
        char path[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
        strcat(path, coa->account);
        strcat(path, ".txt");
        FILE *fpr = fopen(path, "r");
        if (fpr == NULL)
        {
            printf("文件打开失败\n");
        }
        else
        {
            COURSE *cohead = insertse(fpr); // 将课程信息读入链表
            COURSE *tem = cohead;
            while (cohead != NULL)
            {

                if (strcmp(cohead->place, place) == 0)
                {
                    count++;
                }
                else
                {
                    cohead->flag = false;
                }
                cohead = cohead->next;
            }

            delcoulist(tem);
            fclose(fpr);
            printf("该地点共%d门课程\n", count);
        }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        cocourseplace(coa);
        return;
    }
    else
    {
        return;
    }
}

void cocoursetime(COACH *coa) // 教练按上课时间统计课程(3)(ok)
{
    printf("*************************************************\n"); // 规范长度
    printf("***    请选择您想按什么上课时间统计课程数量       ***\n");
    printf("***           1.上午(0:00-11:59)                ***\n"
           "***           2.下午(12:00-17:59)               ***\n"
           "***           3.晚上(18:00-23:59)               ***\n");
    printf("*************************************************\n"); // 规范长度
    int a;
    scanf("%d", &a);
    int count = 0;
    if (a < 1 || a > 3)
    {
        printf("输入有误\n");
    }
    else
    {
        char path[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
        strcat(path, coa->account);
        strcat(path, ".txt");
        FILE *fpr = fopen(path, "r");
        COURSE *cohead = insertse(fpr);
        COURSE *tem = cohead;
        if (a == 1)
        {
            while (cohead != NULL)
            {
                if (cohead->time >= 0 && cohead->time <= 1159)
                {
                    count++;
                }
                cohead = cohead->next;
            }
        }
        else if (a == 2)
        {
            while (cohead != NULL)
            {
                if (cohead->time >= 1200 && cohead->time <= 1759)
                {
                    count++;
                }
                cohead = cohead->next;
            }
        }
        else if (a == 3)
        {
            while (cohead != NULL)
            {
                if (cohead->time >= 1800 && cohead->time <= 2359)
                {
                    count++;
                }
                cohead = cohead->next;
            }
        }
        delcoulist(tem);
        if(count==0)
        {
            printf("未找到符合条件的课程或输入错误");
        }
        else
        {
            printf("该时间段共%d门课程\n", count);
        }
        
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        cocoursetime(coa);
        return;
    }
    else
    {
        return;
    }
}

void cocourseprotime(COACH *coa) // 按项目上课时间统计课程(4多属性)(OK)
{
    int count = 0;
    printf("*************************************************\n"); // 规范长度
    printf("请选择您想按什么项目统计课程数量：\n");
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\projectname.txt", "r");
    NAME *proheadna = insertna(fp);
    NAME *proheadna1 = proheadna;
    NAME *tem = proheadna;
    int i = 1;
    int j = 1;
    while (proheadna != NULL)
    {
        printf("%d.%s\n", i, proheadna->name);
        proheadna = proheadna->next;
        i++;
    }
    printf("*************************************************\n"); // 规范长度
    fclose(fp);

    int a;
    char project[30];
    scanf("%d", &a);
    if (a < 1 || a > i)
    {
        printf("输入有误\n");
    }
    else
    {
        while (proheadna1 != NULL)
        {
            if (a == j)
            {
                strcpy(project, proheadna1->name);
                break;
            }
            else
            {
                j++;
                proheadna1 = proheadna1->next;
            }
        }
        delnamelist(tem);
        // 先将课程名读入链表
        // 每读一个课程名就到course文件夹里找对应的文件，打开验证项目名称是否相等
        char path[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
        strcat(path, coa->account);
        strcat(path, ".txt");
        FILE *fpr = fopen(path, "r");
        if (fpr == NULL)
        {
            printf("文件打开失败\n");
        }
        else
        {
            COURSE *cohead = insertse(fpr); // 将课程信息读入链表
            COURSE *cohead1 = cohead;       // 保存课程头指针
            COURSE *tem1 = cohead;
            while (cohead != NULL)
            {
                if (strcmp(cohead->project, project) != 0)
                {
                    cohead->flag = false;
                }
                cohead = cohead->next;
            }
            printf("*************************************************\n"); // 规范长度
            printf("***    请选择您想按什么上课时间统计课程数量       ***\n");
            printf("***           1.上午(0:00-11:59)                ***\n"
                   "***           2.下午(12:00-17:59)               ***\n"
                   "***           3.晚上(18:00-23:59)               ***\n");
            printf("*************************************************\n"); // 规范长度
            int c;
            scanf("%d", &c);
            if (c < 1 || c > 3)
            {
                printf("输入有误\n");
            }
            else
            {
                if (c == 1)
                {
                    while (cohead1 != NULL)
                    {
                        if ((cohead1->time >= 0 && cohead1->time <= 1159) && (cohead1->flag == true))
                        {
                            count++;
                        }
                        cohead1 = cohead1->next;
                    }
                }
                else if (c == 2)
                {
                    while (cohead1 != NULL)
                    {
                        if ((cohead1->time >= 1200 && cohead1->time <= 1759) && (cohead1->flag == true))
                        {
                            count++;
                        }
                        cohead1 = cohead1->next;
                    }
                }
                else if (c == 3)
                {
                    while (cohead1 != NULL)
                    {
                        if ((cohead1->time >= 1800 && cohead1->time <= 2359) && (cohead1->flag == true))
                        {
                            count++;
                        }
                        cohead1 = cohead1->next;
                    }
                }

                delcoulist(tem1);
                fclose(fpr);
                if(count == 0)
                {
                    printf("未找到符合条件的课程或输入错误\n");
                }
                else
                {
                printf("该项目，上课时间下共%d门课程\n", count);
                }
            }
        }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        cocourseprotime(coa);
        return;
    }
    else
    {
        return;
    }
}

void cocourseplacetime(COACH *coa) // 按上课地点上课时间统计课程(5多属性)(ok)
{
    int count = 0;
    printf("*************************************************\n"); // 规范长度
    printf("请选择您想按什么上课地点统计课程数量：\n");
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\placename.txt", "r");
    NAME *proheadna = insertna(fp);
    NAME *proheadna1 = proheadna;
    NAME *tem = proheadna;
    int i = 1;
    int j = 1;
    while (proheadna != NULL)
    {
        printf("%d.%s\n", i, proheadna->name);
        proheadna = proheadna->next;
        i++;
    }
    printf("*************************************************\n"); // 规范长度
    fclose(fp);

    int b;
    char place[30];
    scanf("%d", &b);
    if (b < 1 || b > i)
    {
        printf("输入有误\n");
    }
    else
    {
        while (proheadna1 != NULL)
        {
            if (b == j)
            {
                strcpy(place, proheadna1->name);
                break;
            }
            else
            {
                j++;
                proheadna1 = proheadna1->next;
            }
        }
        delnamelist(tem);
        // 先将课程名读入链表
        // 每读一个课程名就到course文件夹里找对应的文件，打开验证项目名称是否相等
        char path[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
        strcat(path, coa->account);
        strcat(path, ".txt");
        FILE *fpr = fopen(path, "r");
        if (fpr == NULL)
        {
            printf("文件打开失败\n");
        }
        else
        {
            COURSE *cohead = insertse(fpr); // 将课程信息读入链表

            COURSE *cohead1 = cohead; // 保存课程头指针

            COURSE *tem1 = cohead;
            while (cohead != NULL)
            {
                if (strcmp(place, cohead->place) != 0)
                {
                    cohead->flag = false;
                }
                cohead = cohead->next;
            }
            printf("*************************************************\n"); // 规范长度
            printf("***    请选择您想按什么上课时间统计课程数量       ***\n");
            printf("***           1.上午(0:00-11:59)                ***\n"
                   "***           2.下午(12:00-17:59)               ***\n"
                   "***           3.晚上(18:00-23:59)               ***\n");
            printf("*************************************************\n"); // 规范长度
            int a;
            scanf("%d", &a);
            if (a < 1 || a > 3)
            {
                printf("输入错误！\n");
            }
            else
            {
                if (a == 1)
                {
                    while (cohead1 != NULL)
                    {
                        if ((cohead1->time >= 0 && cohead1->time <= 1159) && (cohead1->flag == true))
                        {
                            count++;
                        }
                        cohead1 = cohead1->next;
                    }
                }
                else if (a == 2)
                {
                    while (cohead1 != NULL)
                    {
                        if ((cohead1->time >= 1200 && cohead1->time <= 1759) && (cohead1->flag == true))
                        {
                            count++;
                        }
                        cohead1 = cohead1->next;
                    }
                }
                else if (a == 3)
                {
                    while (cohead1 != NULL)
                    {
                        if ((cohead1->time >= 1800 && cohead1->time <= 2359) && (cohead1->flag == true))
                        {
                            count++;
                        }
                        cohead1 = cohead1->next;
                    }
                }
                delcoulist(tem1);
                fclose(fpr);
                printf("该上课地点，上课时间下共%d门课程\n", count);
            }
        }
        printf("*************************************************\n"); // 规范长度
        printf("***                是否继续统计？              ***\n");
        printf("***                1：是                      ***\n");
        printf("***                2或其他：否                ***\n");
        printf("*************************************************\n"); // 规范长度
        int order;
        scanf("%d", &order);
        if (order == 1)
        {
            cocourseplacetime(coa);
            return;
        }
        else
        {
            return;
        }
    }
}

void stucoursepro(STUDENT *student) // 学员按项目名称统计课程(1)(ok)
{
    printf("*************************************************\n"); // 规范长度
    printf("请选择您想按什么项目统计课程数量：\n");
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\projectname.txt", "r");
    NAME *proheadna = insertna(fp);
    NAME *proheadna1 = proheadna;
    NAME *tem = proheadna;
    int i = 1;
    int j = 1;
    while (proheadna != NULL)
    {
        printf("%d.%s\n", i, proheadna->name);
        proheadna = proheadna->next;
        i++;
    }
    printf("*************************************************\n"); // 规范长度
    fclose(fp);

    int a;
    char project[30];
    scanf("%d", &a);
    if (a < 1 || a > i)
    {
        printf("输入有误\n");
    }
    else
    {
        while (proheadna1 != NULL)
        {
            if (a == j)
            {
                strcpy(project, proheadna1->name);
                break;
            }
            else
            {
                j++;
                proheadna1 = proheadna1->next;
            }
        }
        delnamelist(tem);
        int count = 0;
        // 先将课程名读入链表
        // 每读一个课程名就到course文件夹里找对应的文件，打开验证项目名称是否相等
        char path[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
        strcat(path, student->account);
        strcat(path, ".txt");
        FILE *fpr = fopen(path, "r");
        if (fpr == NULL)
        {
            printf("该学员不存在\n");
        }
        else
        {
            COURSE *cohead = insertse(fp); // 将课程信息读入链表
                                           /*while (cohead != NULL)
                                           {
                                               printf("%s\n", cohead->project);
                                               cohead=cohead->next;
                                           }*/
            while (cohead != NULL)
            {
                printf("%s\n", cohead->name);
                if (strcmp(cohead->project, project) == 0)
                {
                    count++;
                }
                else
                {
                    cohead->flag = false;
                }
                cohead = cohead->next;
            }
            delnamelist(proheadna);
            delcoulist(cohead);
            fclose(fpr);
            printf("该项目下共有%d门课程\n", count);
        }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        stucoursepro(student);
        return;
    }
    else
    {
        return;
    }
}

void stucourseplace(STUDENT *student) // 学员按上课地点统计课程(2)(ok)
{
    printf("*************************************************\n"); // 规范长度
    printf("请选择您想按什么上课地点统计课程数量：\n");
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\placename.txt", "r");
    NAME *proheadna = insertna(fp);
    NAME *proheadna1 = proheadna;
    NAME *tem = proheadna;
    int i = 1;
    int j = 1;
    while (proheadna != NULL)
    {
        printf("%d.%s\n", i, proheadna->name);
        proheadna = proheadna->next;
        i++;
    }
    printf("*************************************************\n"); // 规范长度
    fclose(fp);

    int a;
    char place[30];
    scanf("%d", &a);
    if (a < 1 || a > i)
    {
        printf("输入有误\n");
    }
    else
    {
        while (proheadna1 != NULL)
        {
            if (a == j)
            {
                strcpy(place, proheadna1->name);
                break;
            }
            else
            {
                j++;
                proheadna1 = proheadna1->next;
            }
        }
        delnamelist(tem);

        // 先将课程名读入链表
        // 每读一个课程名就到course文件夹里找对应的文件，打开验证项目名称是否相等
        int count = 0;
        char path[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
        strcat(path, student->account);
        strcat(path, ".txt");
        FILE *fpr = fopen(path, "r");
        if (fpr == NULL)
        {
            printf("文件打开失败\n");
        }
        else
        {
            COURSE *cohead = insertse(fpr); // 将课程信息读入链表
            COURSE *tem = cohead;
            while (cohead != NULL)
            {

                if (strcmp(cohead->place, place) == 0)
                {
                    count++;
                }
                else
                {
                    cohead->flag = false;
                }
                cohead = cohead->next;
            }

            delcoulist(tem);
            fclose(fpr);
            printf("该地点共%d门课程\n", count);
        }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        stucourseplace(student);
        return;
    }
    else
    {
        return;
    }
}

void stucoursetime(STUDENT *student) // 学员按上课时间统计课程(3)(ok)
{
    printf("*************************************************\n"); // 规范长度
    printf("***    请选择您想按什么上课时间统计课程数量       ***\n");
    printf("***           1.上午(0:00-11:59)                ***\n"
           "***           2.下午(12:00-17:59)               ***\n"
           "***           3.晚上(18:00-23:59)               ***\n");
    printf("*************************************************\n"); // 规范长度
    int a;
    scanf("%d", &a);
    int count = 0;
    if (a < 1 || a > 3)
    {
        printf("输入有误\n");
    }
    else
    {
        char path[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
        strcat(path, student->account);
        strcat(path, ".txt");
        FILE *fpr = fopen(path, "r");
        COURSE *cohead = insertse(fpr);
        COURSE *tem = cohead;
        if (a == 1)
        {
            while (cohead != NULL)
            {
                if (cohead->time >= 0 && cohead->time <= 1159)
                {
                    count++;
                }
                cohead = cohead->next;
            }
        }
        else if (a == 2)
        {
            while (cohead != NULL)
            {
                if (cohead->time >= 1200 && cohead->time <= 1759)
                {
                    count++;
                }
                cohead = cohead->next;
            }
        }
        else if (a == 3)
        {
            while (cohead != NULL)
            {
                if (cohead->time >= 1800 && cohead->time <= 2359)
                {
                    count++;
                }
                cohead = cohead->next;
            }
        }
        delcoulist(tem);
        printf("该时间段共%d门课程\n", count);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        stucoursetime(student);
        return;
    }
    else
    {
        return;
    }
}

void stucourseprotime(STUDENT *student) // 按项目上课时间统计课程(4多属性)(OK)
{
    int count = 0;
    printf("*************************************************\n"); // 规范长度
    printf("请选择您想按什么项目统计课程数量：\n");
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\projectname.txt", "r");
    NAME *proheadna = insertna(fp);
    NAME *proheadna1 = proheadna;
    NAME *tem = proheadna;
    int i = 1;
    int j = 1;
    while (proheadna != NULL)
    {
        printf("%d.%s\n", i, proheadna->name);
        proheadna = proheadna->next;
        i++;
    }
    printf("*************************************************\n"); // 规范长度
    fclose(fp);

    int a;
    char project[30];
    scanf("%d", &a);
    if (a < 1 || a > i)
    {
        printf("输入有误\n");
    }
    else
    {
        while (proheadna1 != NULL)
        {
            if (a == j)
            {
                strcpy(project, proheadna1->name);
                printf("您选择的项目是%s\n", project);
                break;
            }

            else
            {
                j++;
                proheadna1 = proheadna1->next;
            }
        }
        delnamelist(proheadna1);
        // 先将课程名读入链表
        // 每读一个课程名就到course文件夹里找对应的文件，打开验证项目名称是否相等
        char path[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
        strcat(path, student->account);
        strcat(path, ".txt");
        FILE *fpr = fopen(path, "r");
        if (fpr == NULL)
        {
            printf("文件打开失败\n");
        }
        else
        {
            COURSE *cohead = insertse(fpr); // 将课程信息读入链表
            COURSE *cohead1 = cohead;       // 保存课程头指针
            COURSE *tem1 = cohead;
            while (cohead != NULL)
            {

                if (strcmp(cohead->project, project) != 0)
                {
                    cohead->flag = false;
                }
                cohead = cohead->next;
            }
            printf("*************************************************\n"); // 规范长度
            printf("***    请选择您想按什么上课时间统计课程数量        ***\n");
            printf("***           1.上午(0:00-11:59)                ***\n"
                   "***           2.下午(12:00-17:59)               ***\n"
                   "***           3.晚上(18:00-23:59)               ***\n");
            printf("*************************************************\n"); // 规范长度
            int c;
            scanf("%d", &c);
            if (c < 1 || c > 3)
            {
                printf("输入有误\n");
            }
            else
            {
                if (c == 1)
                {
                    while (cohead1 != NULL)
                    {

                        if ((cohead1->time >= 0 && cohead1->time <= 1159) && (cohead1->flag == true))
                        {
                            printf("%s ", cohead1->project);
                            count++;
                        }
                        cohead1 = cohead1->next;
                    }
                }
                else if (c == 2)
                {
                    while (cohead1 != NULL)
                    {
                        if ((cohead1->time >= 1200 && cohead1->time <= 1759) && (cohead1->flag == true))
                        {
                            count++;
                        }
                        cohead1 = cohead1->next;
                    }
                }
                else if (c == 3)
                {
                    while (cohead1 != NULL)
                    {
                        if ((cohead1->time >= 1800 && cohead1->time <= 2359) && (cohead1->flag == true))
                        {
                            count++;
                        }
                        cohead1 = cohead1->next;
                    }
                }

                printf("该项目，上课时间下共%d门课程\n", count);
                delcoulist(tem1);
                fclose(fpr);
            }
        }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***                是否继续统计？              ***\n");
    printf("***                1：是                      ***\n");
    printf("***                2或其他：否                ***\n");
    printf("*************************************************\n"); // 规范长度
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        stucourseprotime(student);
        return;
    }
    else
    {
        return;
    }
}

void stucourseplacetime(STUDENT *student) // 按上课地点上课时间统计课程(5多属性)(ok)
{
    int count = 0;
    printf("*************************************************\n"); // 规范长度
    printf("请选择您想按什么上课地点统计课程数量：\n");
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\placename.txt", "r");
    NAME *proheadna = insertna(fp);
    NAME *proheadna1 = proheadna;
    NAME *tem = proheadna;
    int i = 1;
    int j = 1;
    while (proheadna != NULL)
    {
        printf("%d.%s\n", i, proheadna->name);
        proheadna = proheadna->next;
        i++;
    }
    printf("*************************************************\n"); // 规范长度
    fclose(fp);

    int b;
    char place[30];
    scanf("%d", &b);
    if (b < 1 || b > i)
    {
        printf("输入有误\n");
    }
    else
    {
        while (proheadna1 != NULL)
        {
            if (b == j)
            {
                strcpy(place, proheadna1->name);
                break;
            }
            else
            {
                j++;
                proheadna1 = proheadna1->next;
            }
        }
        delnamelist(tem);
        // 先将课程名读入链表
        // 每读一个课程名就到course文件夹里找对应的文件，打开验证项目名称是否相等
        char path[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
        strcat(path, student->account);
        strcat(path, ".txt");
        FILE *fpr = fopen(path, "r");
        if (fpr == NULL)
        {
            printf("文件打开失败\n");
        }
        else
        {
            COURSE *cohead = insertse(fpr); // 将课程信息读入链表

            COURSE *cohead1 = cohead; // 保存课程头指针

            COURSE *tem1 = cohead;
            while (cohead != NULL)
            {
                if (strcmp(place, cohead->place) != 0)
                {
                    cohead->flag = false;
                }
                cohead = cohead->next;
            }
            printf("*************************************************\n"); // 规范长度
            printf("***    请选择您想按什么上课时间统计课程数量       ***\n");
            printf("***           1.上午(0:00-11:59)                ***\n"
                   "***           2.下午(12:00-17:59)               ***\n"
                   "***           3.晚上(18:00-23:59)               ***\n");
            printf("*************************************************\n"); // 规范长度
            int a;
            scanf("%d", &a);
            if (a < 1 || a > 3)
            {
                printf("输入错误！\n");
            }
            else
            {
                if (a == 1)
                {
                    while (cohead1 != NULL)
                    {
                        if ((cohead1->time >= 0 && cohead1->time <= 1159) && (cohead1->flag == true))
                        {
                            count++;
                        }
                        cohead1 = cohead1->next;
                    }
                }
                else if (a == 2)
                {
                    while (cohead1 != NULL)
                    {
                        if ((cohead1->time >= 1200 && cohead1->time <= 1759) && (cohead1->flag == true))
                        {
                            count++;
                        }
                        cohead1 = cohead1->next;
                    }
                }
                else if (a == 3)
                {
                    while (cohead1 != NULL)
                    {
                        if ((cohead1->time >= 1800 && cohead1->time <= 2359) && (cohead1->flag == true))
                        {
                            count++;
                        }
                        cohead1 = cohead1->next;
                    }
                }
                delcoulist(tem1);
                fclose(fpr);
                printf("该上课地点，上课时间下共%d门课程\n", count);
            }
        }
        printf("*************************************************\n"); // 规范长度
        printf("***                是否继续统计？              ***\n");
        printf("***                1：是                      ***\n");
        printf("***                2或其他：否                ***\n");
        printf("*************************************************\n"); // 规范长度
        int order;
        scanf("%d", &order);
        if (order == 1)
        {
            stucourseplacetime(student);
            return;
        }
        else
        {
            return;
        }
    }
}

// void charge(STUDENT *student)//
// {
//     printf("这是您的余额：%s\n", student->score);
//     printf("请输入您要充值的金额：\n");
//     int money;
//     scanf("%d", &money);
//     STUDENT *stuhead = insertstu();
//     STUDENT *temp = stuhead;
//     STUDENT *cur = stuhead;
//     while (temp != NULL)
//     {
//         if (strcmp(temp->account, student->account) == 0)
//         {
//             temp->score=money;
//             break;
//         }
//         temp = temp->next;
//     }
//     temp = stuhead;
//     char road[100]="C:\\Users\\lenovo\\Desktop\\学员\\学员.txt";
//     FILE *fp = fopen(road, "wb+");
//     while (temp != NULL)
//     {
//         fprintf(fp,"%s %s %s %d %s \n", temp->name, temp->account, temp->password, temp->score, temp->number);
//         temp=temp->next;
//     }
//     fclose(fp);
//     delstulist(cur);

//     printf("充值成功，您的余额为：%s\n", student->score);
// }

void searchcourse(STUDENT *student) // 报名课程
{
    FILE *fp = fopen("C:\\Users\\lenovo\\Desktop\\课程\\课程.txt", "r");
    NAME *cohead = insertna(fp);
    NAME *tem = cohead;
    while (cohead != NULL)
    {
        printf("%s\n", cohead->name);
        cohead = cohead->next;
    }
    delnamelist(tem);
    fclose(fp);

    printf("请选择您想执行的功能：\n:"
           " 1.查询课程的详细信息\n"
           " 2.返回主菜单\n");
    int a;
    scanf("%d", &a);
    if (a < 1 || a > 2)
    {
        printf("输入错误！\n");
    }
    else
    {
        if (a == 1) // 查询详细信息
        {
            printf("请输入您要查询的课程名:\n");
            char coname[30];
            scanf("%s", coname);
            char path1[100] = "C:\\Users\\lenovo\\Desktop\\课程\\";
            strcat(path1, coname);
            strcat(path1, ".txt");
            FILE *fpr = fopen(path1, "r");
            if (fpr == NULL)
            {
                printf("课程不存在！\n");
                return;
            }
            else
            {
                char project[30];
                char name[30];
                char number[30];
                char place[30];
                int time; // 开始时间
                char date[30];
                int score; // 花费
                int max;
                fscanf(fpr, "%s %s %s %s %d %s %d %d ", project, name, number, place, &time, date, &score, &max);
                printf("项目名：%s\n课程名：%s\n课程地点：%s\n课程时间：%02d:%02d\n课程日期：%s\n课程价格：%d\n课程最大人数：%d\n", name, number, place, time/100,time%100, date, score, max);
                printf("请选择您想执行的功能：\n"
                       "1.报名该课程\n"
                       "2.返回课程列表\n");

                int a;
                scanf("%d", &a);
                if (a < 1 || a > 2)
                {
                    printf("输入错误！\n");
                }
                else
                {
                    if (a == 1) // 报名
                    {

                        char path[100] = "C:\\Users\\lenovo\\Desktop\\课程\\";
                        strcat(path, coname);
                        strcat(path, ".txt");
                        FILE *fpr1 = fopen(path, "r"); // 读取课程信息
                        char project[30];
                        char name[30];
                        char number[30];
                        char place[30];
                        int time; // 开始时间
                        char date[30];
                        int score; // 花费
                        int max;
                        fscanf(fpr1, "%s %s %s %s %d %s %d %d ", project, name, number, place, &time, date, &score, &max);
                        printf("项目名：%s\n课程名：%s\n课程地点：%s\n课程时间：%02d:%02d\n课程日期：%s\n课程价格：%d\n课程最大人数：%d\n", name, number, place, time/100,time%100, date, score, max);
                        char path1[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
                        strcat(path1, student->account);
                        strcat(path1, ".txt");
                        FILE *fpr2 = fopen(path1, "a"); // 将课程信息写入学员账号名文件
                        fprintf(fpr2, "\n%s %s %s %s %d %s %d %d", project, name, number, place, time, date, score, max);
                        fclose(fpr2);
                        fclose(fpr1);

                        char path2[100] = "C:\\Users\\lenovo\\Desktop\\stu课程\\";
                        strcat(path2, coname);
                        strcat(path2, ".txt");
                        FILE *fpr3 = fopen(path2, "a"); // 打开课程名称文件

                        fprintf(fpr3, "\n%s", student->name); // 将学生姓名写入课程名称文件
                        fclose(fpr3);

                        printf("报名成功，现在回到主菜单！\n");
                    }
                    else if (a == 2) // 返回课程列表
                    {
                        searchcourse(student);
                    }
                }

                fclose(fpr);
            }
        }
        else if (a == 2) // 返回主菜单
        {
            return;
        }
    }
    printf("是否继续报名其他课程？\n");
    printf("1：是\n");
    printf("2或其他：否\n");
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        searchcourse(student);
        return;
    }
    else
    {
        return;
    }
}
void deletecourse(STUDENT*student) // 学员删除课程
{
    char path[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
    strcat(path, student->account);
    strcat(path, ".txt");
    FILE *fp = fopen(path, "rb+");
    COURSE *course = insertse(fp);
    char coname[30]; // 课程所属项目
    printf("请输入要删除的课程\n");
    scanf("%s", coname);
    COURSE *pre = course;
    COURSE *cur = course;
    COURSE *p1=course;
    while(p1!=NULL)
    {
        printf("%s\n",p1->name);
        p1=p1->next;
    }
    printf("打印报名结束\n");
    while (cur != NULL && strcmp(cur->name,coname) != 0)
    {
        pre = cur;
        cur = cur->next;
    }

   if (cur == course)
    {
        course = course->next;
        free(cur);
        cur=NULL;
    }
    else
    {
        COURSE *temp = cur;
        pre->next = cur->next;
        free(temp);
        temp = NULL;
    }
    pre=course;
    fclose(fp);
    fp = fopen(path, "w");
    fp = fopen(path, "ab");
    while (pre != NULL)
    {
        fprintf(fp, "\n%s %s %s %s %d %s %d %d", pre->project, pre->name, pre->number, pre->place, pre->time, pre->date, pre->score, pre->max);
        pre = pre->next;
    }
    // 从课程里面删除学员

    char road[100] = "C:\\Users\\lenovo\\Desktop\\stu课程\\";
    strcat(road, coname);
    strcat(road, ".txt");
    FILE *fp1;
    fp1 = fopen(road, "r");
    if (fp1 == NULL)
    {
        printf("文件打开失败\n");
    }
    else
    {
        NAME *name = insertna(fp1);
        NAME *pre1 = name;
        NAME *cur1= name;
        while (cur1 != NULL && strcmp(cur1->name, student->name) != 0)     
        {
            pre1 = cur1;
            cur1 = cur1->next;
        }

        if (cur1 == NULL)
        {
            printf("学员不存在...\n");
            return;
        }
        else if (cur1 == name)
        {
            name = name->next;
            free(cur1);
        }
        else
        {
            NAME *temp = cur1;
            pre1->next = cur1->next;
            free(temp);
            temp = NULL;
        }
        pre1 = name;
        fp1 = fopen(road, "w");
        fp1 = fopen(road, "ab");
        while (pre1 != NULL)
        {
            fprintf(fp1, "\n%s", pre1->name);
            pre1 = pre1->next;
        }
        delnamelist(name);
    }
    
    delcoulist(course);
    fclose(fp1);
    
    printf("数据导入成功\n");
    fclose(fp);
}

void changenum(STUDENT *student)
{
    printf("这是您原先的手机号码：%s\n", student->number);
    printf("请输入新的手机号码\n");
    char num[30];
    scanf("%s", num);
    STUDENT *stuhead = insertstu();
    STUDENT *temp = stuhead;
    STUDENT *cur = stuhead;
    while (temp != NULL)
    {
        if (strcmp(temp->account, student->account) == 0)
        {
            strcpy(temp->number, num);
            break;
        }
        temp = temp->next;
    }
    temp = stuhead;
    char road[100] = "C:\\Users\\lenovo\\Desktop\\学员\\学员.txt";
    FILE *fp = fopen(road, "wb+");
    while (temp != NULL)
    {
        fprintf(fp, "\n%s %s %s %d %s ", temp->name, temp->account, temp->password, temp->score, temp->number);
        temp = temp->next;
    }
    fclose(fp);
    delstulist(cur);
    printf("修改成功，现在回到主菜单！\n");
} // 修改课程人数

bool panstu(char acc[30])//判断学员是否存在
{
    STUDENT *stud=insertstu();
    STUDENT *stu=stud;
    while(stu!=NULL)
    {
        if(strcmp(stu->account,acc)==0)
        {
            delstulist(stu);
            return true;
        }
        stu=stu->next;
    }
    delstulist(stu);
    return false;
}