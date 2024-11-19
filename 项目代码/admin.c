#include "ku.c"
#include <windows.h>
void color(short x) // 自定义函根据参数改变颜色
{
    if (x >= 0 && x <= 15)                                           // 参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x); // 只有一个参数，改变字体颜色
    else                                                             // 默认的颜色白色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
void mycolor()
{
    
    for (int i = 0; i < 1000; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
        printf("%-3d", i);
        color(16);
        printf(" ");
        if (i % 16 == 0)
            printf("\n");
    }
    printf("请选择自己喜欢的配色\n");
    char b[30];
    scanf("%s", b);
    int a=atoi(b);
    for (int i = 0; i <= a; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
    }
}

void face()
{
    printf("*************************************************\n"); // 规范长度
    printf("***                健身中心系统                ***\n");
    printf("***                1 管理员系统                ***\n");
    printf("***                2  教练系统                 ***\n");
    printf("***                3  学员系统                 ***\n");
    printf("***                4    退出                   ***\n");
    printf("*************************************************\n"); // 规范长度
    printf("请选择您的身份登录或注册系统\n");
    char ch[30];
    scanf("%s", &ch);
    if(strcmp(ch,"1")==0)
    {
        if (adminlogin())
        {
            void adminoperator();
            adminoperator();
            return;
        }
        else
        {
            return;
        }
    }
    else if(strcmp(ch,"2")==0)
    {
        void coachDL();
        coachDL(); // 教练登录函数
        return;
    }
    else if(strcmp(ch,"3")==0)
    {
        void stuface();
        stuface(); // 学员登录函数
        return;
    }
    if(strcmp(ch,"4")==0)
    {
        printf("再见，祝您生活愉快\n");
        return;
    }
    else
    {
        printf("输入错误\n");
    }
    printf("是否继续进入系统？\n");
    printf("1：是\n");
    printf("2或其他：否\n");
    char order[30];
    scanf("%s", order);
    int orw=atoi(order);
    if (orw == 1)
    {
        face();
        return;
    }
    else
    {
        return;
    }
}

void stuface()
{
    printf("*************************************************\n"); // 规范长度
    printf("***              学员想注册还是登录呀？         ***\n");
    printf("***              1:注册                        ***\n");
    printf("***              2:登录                        ***\n");
    printf("*************************************************\n"); // 规范长度
    char ch[30];
    scanf("%s", ch);
    if (strcmp(ch, "1") == 0)
    {
        void stu_reg(); // 学员注册函数
        stu_reg();
    }
    else if (strcmp(ch, "2") == 0)
    {
        STUDENT* stulogin();
        STUDENT* coa = stulogin();
        if (coa != NULL)
        {
            void stumenu(STUDENT *student);
            stumenu(coa);
        }

        else
        {
            printf("登录失败\n");
        }
    }
    else
    {
        printf("输入错误\n");
    }
    printf("*************************************************\n"); // 规范长度
    printf("***               学员是否继续注册登录？        ***\n");
    printf("***               1:是                        ***\n");
    printf("***               2或其他:否                   ***\n");
    printf("*************************************************\n"); // 规范长度
    printf("请输入你的选择\n");
    char ch1[30];
    scanf("%s", ch1);
    if (strcmp(ch1, "1") == 0)
    {
        stuface();
        return;
    }
    else
    {
        return;
    }
}

// 管理员界面
void adminface() // 管理员界面
{
    printf("*************************************************\n");  // 规范长度
    printf("***                  管理员界面                ***\n"); // 界面名称
    printf("***                  1 信息管理                ***\n");
    printf("***                  2 教练管理                ***\n");
    printf("***                  3 课程管理                ***\n");
    printf("***                  4 信息查询                ***\n");
    printf("***                  5 信息排序                ***\n");
    printf("***                  6 信息统计                ***\n");
    printf("***                  7 系统维护                ***\n");
    printf("*************************************************\n"); // 规范长度
}

void adminoperator() // 管理员操作
{
    void adminface1(); // 管理员信息管理界面
    void adquery();
    void adminface2();
    adminface();
    char order[30];
    printf("请输入你的选择\n");
    scanf("%s", order);
    int or2=atoi(order);
    switch (or2)
    {
    case 1:
    {
        adminface1();
        break;
    }
    case 2:
    {
        adminface2();
        break;
    }
    case 3:
    {
        // 课程管理
        void adminface3(); // 管理员课程管理界面
        adminface3();      // 管理员课程管理界面
        break;
    }
    case 4: // 管理员信息查询
    {
        void adminface4();
        adminface4();
        break;
    }
    case 5: // 排序
    {
        void adminface5();
        adminface5();
        break;
    }
    case 6:
    {
        void adminface6();
        adminface6();
        break;
    }
    case 7:
    {
        void adminface7();
        adminface7();
        break;
    }
    default:
    {
        printf("输入错误\n");
        break;
    }
    }
    printf("是否继续进行管理员操作？\n");
    printf("1：是\n");
    printf("2或其他：否\n");
    char order1[30];
    scanf("%s", order1);
    int or1=atoi(order1);
    if (or1 == 1)
    {
        adminoperator();
        return;
    }
    else
    {
        return;
    }
}

void adminface1() // 管理员信息管理界面
{
    printf("*************************************************\n"); // 规范长度
    printf("***                 管理员界面                 ***\n");
    printf("***                 1 项目管理                 ***\n");
    printf("***                 2 教练管理                 ***\n");
    printf("*************************************************\n"); // 规范长度
    printf("请选择功能\n");
    char ch[30];
    scanf("%s", ch);
    int ch1 = atoi(ch);
    switch (ch1)
    {
    case 1:
    {
        adpro();
        break;
    }
    case 2:
    {
        adcoach(); // 教练管理
        break;
    }
    default:
        printf("输入错误\n");
        break;
    }
    printf("*************************************************\n"); // 规范长度
    printf("***              是否继续信息管理？             ***\n");
    printf("***              1 :是                        ***\n");
    printf("***              2或其他:否                    ***\n");
    printf("*************************************************\n"); // 规范长度
    char order[30];
    scanf("%s", order);
    int order1 = atoi(order);
    if (order1 == 1)
    {
        adminface1();
        return;
    }
    else
    {
        return;
    }
}

void adminface2()
{
    printf("管理员审核教练申请的项目\n");
    printf("同意后课程会添加到教练所教学课程，驳回会删除申请的课程信息\n");
    FILE *fp;
    fp = fopen("C:\\Users\\lenovo\\Desktop\\中转.txt", "rb");
    if (fp == NULL)
    {
        printf("文件打开失败\n");
    }
    else
    {
        char acc[30];
        char project[30]; // 所属项目名
        char name[30];    // 课程名
        char number[30];  // 课程号
        char place[30];   // 地点
        int time;         // 课程时间
        char date[30];    // 课程日期
        int score;        // 课程价格
        int max;          // 课程最大人数

        if (fscanf(fp, "%s %s %s %s %s %d %s %d %d ", acc, project, name, number, place, &time, date, &score, &max))
        {
            printf("教练：%s\n", acc);
            printf("课程名:%s 课程号:%s 课程地点:%s 课程时间:%d:%d 课程日期:%s 课程价格:%d 课程最大人数:%d\n", name, number, place, time/100,time%100, date, score, max);
        }

        else
        {
            printf("无需要审核的项目\n");
            fclose(fp);
            return;
        }
        printf(" 1 同意\n");
        printf("2或其他 驳回\n");
        printf("请输入你的选择\n");
        char ch[30];
        scanf("%s", ch);
        int ch1 = atoi(ch);
        if (ch1 == 1)
        {
            char road2[100] = "C:\\Users\\lenovo\\Desktop\\教练\\";
            strcat(road2, acc);
            strcat(road2, ".txt");
            FILE *fp2;
            fp2 = fopen(road2, "ab+");

            fprintf(fp2, "\n%s %s %s %s %d %s %d %d",  project, name, number, place, time, date, score, max);
            char road3[100] = "C:\\Users\\lenovo\\Desktop\\co课程\\";
            strcat(road3, name);
            strcat(road3, ".txt");
            FILE *fp3;
            fp3 = fopen(road3, "ab+");
            COACH *coach = insertco();
            COACH *cur = coach;
            while (cur)
            {
                if (strcmp(cur->account, acc) == 0)
                {
                    break;
                }
                cur = cur->next;
            }
            fprintf(fp3, "\n%s", cur->name);
            delcoalist(coach);
            fclose(fp2);

            fclose(fp3);
        }
        else
        {
            fp = fopen("C:\\Users\\lenovo\\Desktop\\中转.txt", "w");
            fprintf(fp, "\n");
        }
    }
    fclose(fp);
    filecopy();
    return;
} // 管理员教练管理界面

void adminface3() // 管理员课程管理界面
{
    printf("*************************************************\n"); // 规范长度
    printf("***                  课程管理                 ***\n");
    printf("***              1 修改课程信息               ***\n");
    printf("***              2   添加课程                 ***\n");
    printf("***              3 添加课程教练               ***\n");
    printf("***              4 删除课程教练               ***\n");
    printf("*************************************************\n"); // 规范长度
    printf("请输入你的选择\n");
    char order[30];
    scanf("%s", order);
    int order1 = atoi(order);
    switch (order1)
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
    case 3:
    {
        couaddcoa();
        break;
    }
    case 4:
    {
        coudelcoa();
        break;
    }
    default:
    {
        printf("输入错误\n");
        break;
    }
    }
    printf("**************************************************\n"); // 规范长度
    printf("***              是否继续管理员课程管理？       ***\n");
    printf("***              1:是                         ***\n");
    printf("***              2或其他:否                    ***\n");
    printf("*************************************************\n"); // 规范长度
    char ch[30];
    scanf("%s", ch);
    int ch1 = atoi(ch);
    if (ch1 == 1)
    {
        adminface3();
        return;
    }
    else
    {
        return;
    }
}

void adminface5() // 管理员信息排序界面
{
    printf("*************************************************\n"); // 规范长度
    printf("***                 信息排序                   ***\n");
    printf("***              1 课程名称排序                ***\n");
    printf("***              2 课程时间排序                ***\n");
    printf("***              3 课程日期排序                ***\n");
    printf("***              4 课程日期时间排序            ***\n");
    printf("***              5 课程价格排序                ***\n");
    printf("***              6 课程日期价格排序            ***\n");
    printf("***              7 教练姓名排序                ***\n");
    printf("***              8 教练等级排序                ***\n");
    printf("***              9 教练账号排序                ***\n");
    printf("***             10 教练等级账号排序            ***\n");
    printf("***             11 学员账号排序                ***\n");
    printf("***             12 学员余额排序                ***\n");
    printf("***             13 学员姓名排序                ***\n");
    printf("***             14 学员余额账号排序            ***\n");
    printf("*************************************************\n"); // 规范长度
    printf("请输入你的选择\n");
    char ch[30];
    scanf("%s", ch);
    int ch1 = atoi(ch);
    switch (ch1)
    {
    case 1:
    { // 课程名称
        COURSE *course = insertallse();
        Course_name_order(course);
        delcoulist(course);
        break;
    }
    case 2:
    { // 课程时间
        COURSE *course = insertallse();
        Course_time_order(course);
        delcoulist(course);
        break;
    }
    case 3:
    { // 课程日期
        COURSE *course = insertallse();
        Course_Date_order(course);
        delcoulist(course);
        break;
    }
    case 4:
    { // 课程日期时间
        COURSE *course = insertallse();
        Course_DaTi_order(course);
        delcoulist(course);
        break;
    }
    case 5:
    { // 课程价格
        COURSE *course = insertallse();
        Course_score_order(course);
        delcoulist(course);
        break;
    }
    case 6:
    { // 课程日期价格
        COURSE *course = insertallse();
        Course_DaSco_order(course);
        delcoulist(course);
        break;
    }
    case 7:
    { // 教练姓名
        Coa_name_order();
        break;
    }
    case 8:
    { // 教练等级
        Coa_level_order();
        break;
    }
    case 9:
    { // 教练账号
        Coa_account_order();
        break;
    }
    case 10:
    { // 教练等级账号排序
        Coa_LeAcc_order();
        break;
    }
    case 11:
    { // 学员账号
        Stu_account_order();
        break;
    }
    case 12:
    { // 学员余额
        Stu_score_order();
        break;
    }
    case 13:
    { // 学员姓名
        Stu_name_order();
        break;
    }
    case 14:
    { // 学员余额账号
        Stu_ScoAcc_order();
        break;
    }
    default:
    {
        printf("输入错误\n");
        break;
    }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***              是否继续管理员排序？           ***\n");
    printf("***              1:是                         ***\n");
    printf("***              2或其他:否                    ***\n");
    printf("*************************************************\n"); // 规范长度
    char  order[30];
    scanf("%s", order);
    int order1 = atoi(order);
    if (order1 == 1)
    {
        adminface5();
        return;
    }
    else
    {
        return;
    }
}

// 查询界面
void adminface4()
{
    printf("*************************************************\n"); // 规范长度
    printf("***                  查询界面                 ***\n");
    printf("***                 1 精确查询                ***\n");
    printf("***                 2 模糊查询                ***\n");
    printf("***                 3 组合查询                ***\n");
    printf("*************************************************\n"); // 规范长度
    printf("请输入你的选择\n");
    char order[20];
    scanf("%s", order);
    int or1=atoi(order);
    
    switch (or1)
    {
    case 1:
    {
        // 精确查询
        void adqur(); // 管理员精确查询
        adqur();
        break;
    }
    case 2:
    {
        void advaqur(); // 管理员模糊查询
        advaqur();
        break;
    }
    case 3:
    {
        void adcomqur(); // 管理员组合查询
        // 组合查询
        adcomqur();
        break;
    }
    default:
    {
        printf("输入错误\n");
        break;
    }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***              是否继续管理员查询？           ***\n");
    printf("***              1:是                         ***\n");
    printf("***              2或其他:否                    ***\n");
    printf("*************************************************\n"); // 规范长度
    char order1[20];
    scanf("%s", order1);
    int or2=atoi(order1);
    if (or2 == 1)
    {
        adminface4();
        return;
    }
    else
    {
        return;
    }
}

void adminface6()
{
    printf("*************************************************\n"); // 规范长度
    printf("***                  信息统计                 ***\n");
    printf("***               1 课程信息统计              ***\n"); // 输出课程信息，学员，教练
    printf("***               2 学员课程统计              ***\n");
    printf("***               3 教练课程统计              ***\n");
    printf("***               4 地点课程统计              ***\n");
    printf("***               5 时间课程统计              ***\n");
    printf("***               6 项目在某段时间的统计       ***\n");
    printf("***               7 上课时间及地点统计         ***\n");
    printf("*************************************************\n"); // 规范长度
    printf("请输入你的选择\n");
    char order[20];
    scanf("%s", order);
    int or1=atoi(order);
    switch (or1)
    {
    case 1:
    {
        printf("课程信息统计\n");
        coursecostu();
        break;
    }
    case 2:
    {
        printf("学员课程统计\n");
        stucourse();
        break;
    }
    case 3:
    {
        printf("教练课程统计\n");
        cocourse();
        break;
    }
    case 4:
    {
        printf("地点课程统计\n");
        courseplace();
        break;
    }
    case 5:
    {
        printf("项目在某段时间的统计\n");
        coursetime();
        break;
    }
    case 6:
    {
        printf("项目及时间统计\n");
        courseprotime();
        break;
    }
    case 7:
    {
        printf("上课时间及地点统计\n");
        courseplacetime();
        break;
    }
    default:
    {
        printf("输入错误\n");
        break;
    }
    }

    printf("*************************************************\n"); // 规范长度
    printf("***              是否继续管理员信息统计？       ***\n");
    printf("***              1:是                         ***\n");
    printf("***              2或其他:否                    ***\n");
    printf("*************************************************\n"); // 规范长度
    char order1[20];
    scanf("%s", order1);
    int or2=atoi(order1);
    if (or2 == 1)
    {
        adminface6();
        return;
    }
    else
    {
        return;
    }
}

void adqur() // 管理员精确查询
{
    printf("*************************************************\n"); // 规范长度
    printf("***                  精确查询                 ***\n");
    printf("***              1 查询学员报名信息            ***\n");
    printf("***              2 查询课程报名学员            ***\n");
    printf("***              3   查询教练信息              ***\n");
    printf("***              4 查询教练所教课程            ***\n");
    printf("***              5 查询学员所学课程            ***\n");
    printf("***              6     查询项目               ***\n");
    printf("***              7  查询学员教练              ***\n");
    printf("***              8  查询教练学员              ***\n");
    printf("***              9  查询课程信息              ***\n");
    printf("*************************************************\n"); // 规范长度
    printf("请输入你的选择\n");
    char order[20];
    scanf("%s", order);
    int or1=atoi(order);
    switch (or1)
    {
    case 1:
    {
        qustu();
        break;
    }
    case 2:
    {
        qucoustu(); // 单一查询健身课程报名学员
        break;
    }
    case 3:
    {
        qucoa(); // 精确查询教练信息
        break;
    }
    case 4:
    {
        // 教练账号及所教课程查询
        qucoacou();
        break;
    }
    case 5:
    {
        // 学生账号及所学课程查询
        qustucou();
        break;
    }
    case 6:
    {
        // 项目类型及课程查询
        quprocou();
        break;
    }
    case 7:
    {
        // 查询学员教练
        qustuco();
        break;
    }
    case 8:
    {
        // 查询教练学员
        qucoastu();
        break;
    }
    case 9:
    {
        qucour();
        break;
    }
    default:
    {
        printf("输入错误！\n");
        break;
    }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***              是否继续管理员精确查询？       ***\n");
    printf("***              1:是                         ***\n");
    printf("***              2或其他:否                    ***\n");
    printf("*************************************************\n"); // 规范长度
    char order1[20];
    scanf("%s", order1);
    int or2=atoi(order1);
    if (or2 == 1)
    {
        adqur();
        return;
    }
    else
    {
        return;
    }
}

void advaqur() // 管理员模糊查询
{
    printf("*************************************************\n"); // 规范长度
    printf("***                 模糊查询                   ***\n");
    printf("***             1 模糊查询学员                 ***\n");
    printf("***             2 模糊查询教练                 ***\n");
    printf("***             3 模糊查询项目                 ***\n");
    printf("***             4 查询价格区间课程             ***\n");
    printf("***             5 查询对应等级教练             ***\n");
    printf("***             6 模糊查询课程                 ***\n");
    printf("*************************************************\n"); // 规范长度
    printf("请输入你的选择\n");
    char order[20];
    scanf("%s", order);
    int or1=atoi(order);
    switch (or1)
    {
    case 1:
    {
        vaqustu();
        break;
    }
    case 2:
    {
        vaqucoa();
        break;
    }
    case 3:
    {
        vaqupro();
        break;
    }
    case 4:
    {
        qucouscore();
        break;
    }
    case 5:
    {
        qucoalevel();
        break;
    }
    case 6:
    {
        vaqucou();
        break;
    }
    default:
        printf("输入错误\n");
    }
    printf("*************************************************\n"); // 规范长度
    printf("***              是否继续管理员模糊查询？       ***\n");
    printf("***              1:是                         ***\n");
    printf("***              2或其他:否                    ***\n");
    printf("*************************************************\n"); // 规范长度
    char order1[20];
    scanf("%s", order1);
    int or2=atoi(order1);
    if (or2 == 1)
    {
        advaqur();
        return;
    }
    else
    {
        return;
    }
}

void adcomqur() // 管理员组合查询
{
    printf("*************************************************\n"); // 规范长度
    printf("***                  组合查询                  ***\n");
    printf("***          1 查询特定日期特定价格课程         ***\n");
    printf("***          2 查询特定课程特定级别课程         ***\n");
    printf("*************************************************\n"); // 规范长度
    printf("请输入你的选择\n");
    char order[20];
    scanf("%s", order);
    int or1=atoi(order);
    switch (or1)
    {
    case 1:
    {
        comqudasco();
        break;
    }
    case 2:
    {
        comqucoulev();
        break;
    }
    default:
        printf("输入错误\n");
    }
    printf("*************************************************\n"); // 规范长度
    printf("***              是否继续管理员组合查询         ***\n");
    printf("***              1:是                         ***\n");
    printf("***              2或其他:否                    ***\n");
    printf("*************************************************\n"); // 规范长度
    char order1[20];
    scanf("%s", order1);
    int or2=atoi(order1);
    if (or2 == 1)
    {
        adcomqur();
        return;
    }
    else
    {
        return;
    }
}

// 系统维护界面
void adminface7()
{
    printf("*************************************************\n"); // 规范长度
    printf("***                 系统维护                  ***\n");
    printf("***              1 修改管理员密码              ***\n");
    printf("***              2 重置教练密码                ***\n");
    printf("***              3 数据备份                   ***\n");
    printf("***              4 数据恢复                   ***\n");
    printf("*************************************************\n"); // 规范长度
    printf("请输入你的选择\n");
    char order[20];
    scanf("%s", order);
    int or1=atoi(order);
    switch (or1)
    {
    case 1:
    {
        adpass();
        break;
    }
    case 2:
    {
        resetcoapass();
        break;
    }
    case 3:
    {
        filecopy();
        break;
    }
    case 4:
    {
        redata(); // 数据恢复
        break;
    }
    default:
    {
        printf("输入错误\n");
        break;
    }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***              是否继续管理员系统维护？       ***\n");
    printf("***              1:是                         ***\n");
    printf("***              2或其他:否                    ***\n");
    printf("*************************************************\n"); // 规范长度
    char order1[20];
    scanf("%s", order1);
    int or2=atoi(order1);
    if (or2 == 1)
    {
        adminface7();
        return;
    }
    else
    {
        return;
    }
}

void adcoasort() // 教练信息排序
{
    printf("*****************************\n");
    printf("***         教练排序      ***\n");
    printf("***       1 姓名排序      ***\n");
    printf("***       2 等级排序      ***\n");
    printf("***       3 账号排序      ***\n");
    printf("***     4 等级账号排序    ***\n");
    printf("*****************************\n");
    printf("请输入你的选择\n");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
        void Coa_name_order(); // 按姓名排序
        Coa_name_order();      // 按姓名排序
        break;
    }
    case 2:
    {
        void Coa_level_order(); // 按等级排序
        Coa_level_order();      // 按等级排序
        break;
    }
    case 3:
    {
        void Coa_account_order(); // 按账号排序
        Coa_account_order();      // 按账号排序
        break;
    }
    case 4:
    {
        void Coa_LeAcc_order(); // 按等级和账号排序
        Coa_LeAcc_order();      // 按等级和账号排序
        break;
    }
    default:
    {
        printf("输入错误\n");
        break;
    }
    }
    printf("是否继续教练信息排序？\n");
    printf("1：是\n");
    printf("2或其他：否\n");
    char order;
    scanf("%d", &order);
    if (order == 1)
    {
        adcoasort();
        return;
    }
    else
    {
        return;
    }
}

void adstusort() // 学员信息排序
{
    printf("*****************************\n");
    printf("***        学员排序       ***\n");
    printf("***       1 姓名排序       ***\n");
    printf("***       2 余额排序       ***\n");
    printf("***       3 账号排序       ***\n");
    printf("***     4 余额账号排序       ***\n");
    printf("*****************************\n");
    printf("请输入你的选择\n");
    int ch;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
        Stu_name_order();
        break;
    }
    case 2:
    {
        Stu_score_order();
        break;
    }
    case 3:
    {
        Stu_account_order();
        break;
    }
    case 4:
    {
        Stu_ScoAcc_order();
        break;
    }
    default:
    {
        printf("输入错误\n");
    }
    }
    printf("是否继续学员信息排序？\n");
    printf("1：是\n");
    printf("2或其他：否\n");
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        adstusort();
        return;
    }
    else
    {
        return;
    }
}

void adcousort() // 课程信息排序
{
    printf("*****************************\n");
    printf("***        课程排序        ***\n");
    printf("***     1 课程名称排序     ***\n");
    printf("***     2 课程时间排序     ***\n");
    printf("***     3 课程星期排序     ***\n");
    printf("***     4 课程价格排序     ***\n");
    printf("***   5 课程星期价格排序   ***\n");
    printf("***   6 课程星期时间排序   ***\n");
    printf("***   7 课程项目名称排序   ***\n");
    printf("*****************************\n");
    printf("请输入你的选择\n");
    int ch;
    scanf("%d", &ch);
    COURSE *course = insertallse();
    switch (ch)
    {
    case 1:
    {
        Course_name_order(course);
        break;
    }
    case 2:
    {
        Course_time_order(course);
        break;
    }
    case 3:
    {
        Course_Date_order(course);
        break;
    }
    case 4:
    {
        Course_score_order(course);
        break;
    }
    case 5:
    {
        Course_DaSco_order(course);
        break;
    }
    case 6:
    {
        Course_DaTi_order(course);
        break;
    }
    case 7:
    {
        Course_ProCou_order(course);
        break;
    }
    default:
    {
        printf("输入错误\n");
        break;
    }
    }
    delcoulist(course);
    printf("是否继续课程信息排序？\n");
    printf("1：是\n");
    printf("2或其他：否\n");
    int order;
    scanf("%d", &order);
    if (order == 1)
    {
        adcousort();
        return;
    }
    else
    {
        return;
    }
}

// 所有函数
void coachDL();           // 教练登录函数
COACH *Coach_list_head(); // 得到教练链表的头指针
COACH *Coach_p();         // 得到来访教练的指针
void Coach_reg();
int Coach_judge(COACH *new_coach);
void Coach_password(COACH *coa);
void Coa_pass_chg(COACH *coa);
NAME *insertName(); // 用于导入名到链表,得到课程名链表的头指针
void Coa_Course_order(COACH *coa);
void delnamelist(NAME *name); // 释放名称链表
void Coa_change_pro1(COACH *coach); // 教练更改项目类型,开创内容

void coachface(COACH *coa);            // 教练的登录界面
void coachface2(COACH *coa); // 教练的查询界面，形参是来访教练的指针

void coachDL() // 教练登录界面
{
    printf("*************************************************\n"); // 规范长度
    printf("***              教练想注册还是登录呀？       ***\n");
    printf("***              1:注册                       ***\n");
    printf("***              2:登录                       ***\n");
    printf("*************************************************\n"); // 规范长度
    int i;
    scanf("%d", &i);
    if (i == 1)
    {
        Coach_reg();
    }
    else if (i == 2)
    {
        COACH *Coach_p();

        COACH *coa = Coach_p();
        if (coa != NULL)
        {
            coachface(coa);
        }

        else
        {
            printf("登录失败\n");
        }
    }
    else
    {
        printf("输入错误\n");
    }
    printf("*************************************************\n"); // 规范长度
    printf("***               教练是否想登录呀？          ***\n");
    printf("***               1:是                        ***\n");
    printf("***               2或其他:否                  ***\n");
    printf("*************************************************\n"); // 规范长度
    printf("请输入你的选择\n");
    int ch;
    scanf("%d", &ch);
    if (ch == 1)                                        
    {
        coachDL();
        return;
    }
    else
    {
        return;
    }
}

// 教练操作界面
void coachface(COACH *coa)
{
    COACH *head;
    head = Coach_list_head();
    NAME *Course_head;
    void coachface3(COACH * coa);
    Course_head = insertName();
    printf("*************************************************\n");
    printf("***               1 修改擅长项目              ***\n");
    printf("***               2 进入查询界面              ***\n");
    printf("***               3   教练学员                ***\n");
    printf("***               4 健身课程排序              ***\n");
    printf("***               5   信息统计                ***\n");
    printf("***               6 系统维护(更改密码)        ***\n");
    printf("*************************************************\n");
    int n;
    printf("输入您想实现的功能吧(1~6的数字哟):");
    scanf("%d", &n);
    switch (n)
    {
    case 1: // 修改教练擅长项目
    {
        Coa_change_pro1(coa);
        break;
    }
    case 2: // 进入查询界面
    {
        coachface2(coa);
        break;
    }
    case 3: // 教练学员
    {
        NAME *name = Coa_stuName_head(coa); // 得到教练对应学员的名称链表的头指针
        part_Stu_name_order(name);
        printf("**************************************************\n"); // 规范长度
        printf("***              是否继续排序您的学员？       ***\n");
        printf("***              1:是                         ***\n");
        printf("***              2或其他:否                    ***\n");
        printf("*************************************************\n"); // 规范长度
        int i;
        scanf("%d", &i);
        if (i == 1)
        {
            part_Stu_name_order(name);
            break;
        }
        else
        {
            break;
        }
        break;
    }
    case 4: // 健身课程排序
    {
        Coa_Course_order(coa);
        break;
    }
    case 5: // 信息统计
    {
        coachface3(coa);
        break;
    }
    case 6: // 系统维护(更改密码)
    {
        
        Coa_pass_chg(coa);
        break;
    }
    default:
    {
        printf("输入错误\n");
        break;
    }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***               教练是否想继续操作呀？      ***\n");
    printf("***               1:是                        ***\n");
    printf("***               2或其他:否                  ***\n");
    printf("*************************************************\n"); // 规范长度
    int i;
    scanf("%d", &i);
    if (i == 1)
    {
        coachface(coa);
    }
    else
    {
        return;
    }
}

// 教练查询界面
void coachface2(COACH *coa)
{

    printf("*************************************************\n");
    printf("***                     教练查询             ***\n");
    printf("***              1  教练信息查询             ***\n");
    printf("***              2 自己课程信息简单查询      ***\n");
    printf("***              3 全部课程信息模糊查询      ***\n");
    printf("***              4 课程日期价格组合查询      ***\n");
    printf("***              5   学员信息模糊查询        ***\n");
    printf("***              6 自己学员信息详细查询      ***\n");
    printf("***************************************************\n");

    int n;
    printf("输入您想实现的功能吧(1~6的数字哟):");
    scanf("%d", &n);
    switch (n)
    {
    case 1: // 教练信息查询
    {
        coaquinf(coa);
        break;
    }

    case 2: // 课程信息简单查询
    {
        coaqucou(coa);
        break;
    }

    case 3: // 课程信息模糊查询
    {
        vaqucou();
        break;
    }

    case 4: // 课程信息组合查询
    {
        comqudasco(); // 课程日期价格组合查询
        break;
    }

    case 5: // 学员信息模糊查询
    {
        vaqustu();
        break;
    }

    case 6: // 自己学员信息详细查询
    {
        coaqustu(coa);
        break;
    }
    default:
    {
        printf("给房房整不会了呀,再来一次吧\n");
        coachface2(coa);
        break;
    }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***             教练是否想继续查询呀？          ***\n");
    printf("***             1:是                          ***\n");
    printf("***             2或其他:否                    ***\n");
    printf("*************************************************\n"); // 规范长度
    int i;
    scanf("%d", &i);
    if (i == 1)
    {
        coachface2(coa);
        return;
    }
    else
    {
        return;
    }
}
// 教练
void Coa_Course_order(COACH *coa)
{
    printf("*************************************************\n");
    printf("***             1 按时间排序                   ***\n");
    printf("***             2 按课程名排序                 ***\n");
    printf("***             3 按日期排序                   ***\n");
    printf("***             4 按日期和时间排序             ***\n");
    printf("***             5 按价格排序                   ***\n");
    printf("***             6 项目和课程排序               ***\n");
    printf("***             7 日期和价格排序               ***\n");
    printf("*************************************************\n");
    int n;
    printf("输入您想实现的功能吧(0~5的数字哟):");
    scanf("%d", &n);
    switch (n)
    {
    case 1: // 按时间排序  
    {
        Coa_Course_time_order(coa);
        break;
    }
    case 2: // 按课程名排序
    {
        Coa_Course_name_order(coa);
        break;
    }
    case 3: // 按日期排序
    {
        Coa_Course_Date_order(coa);
        break;
    }
    case 4: // 按日期和时间排序
    {
        Coa_Course_DaTi_order(coa);
        break;
    }
    case 5: // 按价格排序
    {
        Coa_Course_score_order(coa);
        break;
    }
    case 6: // 项目和课程排序
    {
        Coa_Course_ProCou_order(coa);
        break;
    }
    case 7: // 日期和价格排序
    {
        Coa_Course_DaSco_order(coa);
        break;
    }
    default:
    {
        printf("给房房整不会了呀,再来一次吧\n");
        Coa_Course_order(coa);
    }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***               教练是否想继续排序课程呀？    ***\n");
    printf("***               1:是                        ***\n");
    printf("***               2或其他:否                   ***\n");
    printf("*************************************************\n"); // 规范长度
    int i;
    scanf("%d", &i);
    if (i == 1)
    {
        Coa_Course_order(coa);
        return;
    }
    else
    {
        return;
    }
}
// 教练统计界面
void coachface3(COACH *coa)
{
    printf("*************************************************\n");
    printf("***         1 按项目统计课程                   ***\n");
    printf("***         2 按上课地点统计课程                ***\n");
    printf("***         3 按上课时间统计课程                ***\n");
    printf("***         4 按项目，上课时间统计课程          ***\n");
    printf("***         5 按上课地点，上课时间统计课程       ***\n");
    printf("***         6 某时间范围内负责的课程数          ***\n");
    printf("***         7 学员参加自己负责的健身课程的数目   ***\n");
    printf("*************************************************\n");
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
    {
        cocoursepro(coa);
        break;
    }
    case 2:
    {
        cocourseplace(coa);
        break;
    }
    case 3:
    {
        cocoursetime(coa);
        break;
    }
    case 4:
    {
        cocourseprotime(coa);
        break;
    }
    case 5:
    {
        cocourseplacetime(coa);
        break;
    }
    case 6:
    {
        cocourseperiod(coa);
        break;
    }
    case 7:
    {
        cocoursestu(coa);
        break;
    }
    default:
    {
        printf("想继续查询请按1,想退出请按2\n");
        int a;
        scanf("%d", &a);
        if (a == 1)
        {
            coachface3(coa);
        }
        if (a == 2)
        {
            printf("拜拜教练,祝您教学愉快\n");
        }
        break;
    }
    }
    printf("*************************************************\n"); // 规范长度
    printf("***               教练是否想继续统计呀？        ***\n");
    printf("***               1:是                         ***\n");
    printf("***               2或其他:否                   ***\n");
    printf("*************************************************\n"); // 规范长度
    int i;
    scanf("%d", &i);
    if (i == 1)
    {
        coachface3(coa);
        return;
    }
    else
    {
        return;
    }
}


void menuf1(STUDENT *student) // 学员第一个功能菜单
{
    void stumenu(STUDENT * student);
    printf("*************************************************\n");//规范长度
    printf("***             请选择您想使用的功能:           ***\n");
    printf("***             1.修改个人信息                  ***\n");
    printf("*************************************************\n");//规范长度
    int choice1;
    scanf("%d", &choice1);
    switch (choice1)
    {

    case 1:
        changenum(student);
        break;
    
    default:
    printf("输入错误\n");
    break;
    }
    printf("*************************************************\n"); // 规范长度
    printf("***          您是否想继续修改个人信息？         ***\n");
    printf("***           1.是，返回功能菜单               ***\n");
    printf("***           2.否，返回主菜单                 ***\n");
    printf("*************************************************\n"); // 规范长度
    int choice11;
    scanf("%d", &choice11);
    switch (choice11)
    {
    case 1:
    {
        menuf1(student);
        return;
    }
    default:
    {
        return;
    }
    }
}

void menuf2(STUDENT *student)
{
    void stumenu(STUDENT * student);
    printf("*************************************************\n");//规范长度
    printf("***            请选择您想使用的功能            ***:\n");
    printf("***            1.报名课程                      ***\n");
    printf("***            2.取消课程                      ***\n");
    printf("*************************************************\n");//规范长度
    int choice2;
    scanf("%d", &choice2);
    switch (choice2)
    {
    case 1:
    {
        searchcourse(student);
        break;
    }
    case 2:
    {
        deletecourse(student);
        break;
    }
    default:
    {
        printf("输入错误\n");
        break;
    }
    }

    printf("*************************************************\n"); // 规范长度
    printf("***         你是否想继续使用课程管理？          ***\n");
    printf("***         1.是，返回功能菜单                 ***\n");
    printf("***         2.否，返回主菜单                   ***\n");
    printf("*************************************************\n"); // 规范长度
    int choice21;
    scanf("%d", &choice21);
    switch (choice21)
    {
    case 1:
        menuf2(student);
        return;
    default:
        return;
    }
}

void menuf3(STUDENT *student)
{

    void stumenu(STUDENT * student);
    printf("*************************************************\n");//规范长度
    printf("***             请选择您想查询的信息          ***:\n");
    printf("***             1.查询课程报名记录             ***\n");
    printf("***             2.查询健身课程                 ***\n");
    printf("***             3.查询健身教练                 ***\n");
    printf("***             4.模糊查询健身课程             ***\n");
    printf("***             5.模糊查询健身教练             ***\n");
    printf("***             6.模糊查询健身项目             ***\n");
    printf("***             7.查询对应日期课程             ***\n");
    printf("***             8.查询对应价格课程             ***\n");
    printf("***             9.查询对应等级教练             ***\n");
    printf("*************************************************\n");//规范长度
    int choice3;
    scanf("%d", &choice3);
    switch (choice3)
    {
    case 1:
    {
        coastucour(student);
        break;
    }

    case 2:
    {
        qucour();
        break;
    }

    case 3:
    {
        qucoa();
        break;
    }
    case 4:
    {
        vaqucou();
        break;
    }
    case 5:
    {

        vaqucoa();
        break;
    }
    case 6:
    {
        vaqupro();
        break;
    }
    case 7:
    {
        qucoudate();
        break;
    }
    case 8:
    {
        qucouscore();
        break;
    }
    case 9:
    {
        qucoalevel();
        break;
    }
    default:
        printf("输入错误\n");
        break;
    }
    printf("*************************************************\n");//规范长度
    printf("***             你是否想继续查询？              ***\n");
    printf("***             1.是                          ***\n");
    printf("***             2或其他.否                     ***\n");
    printf("*************************************************\n");//规范长度
    int choice31;
    scanf("%d", &choice31);
    switch (choice31)
    {
    case 1:
        
        menuf3(student);
        return;
    default:
        return;
    }
}

void menuf4(STUDENT *student)
{
    void stumenu(STUDENT * student);
    printf("****************************************************\n");
    printf("***          请选择您想要的排序：               ***\n");
    printf("***          1.对健身课程按时间排序             ***\n");
    printf("***          2.对健身课程按星期排序             ***\n");
    printf("***          3.对健身课程按星期和时间排序        ***\n");
    printf("***          4.对健身课程按课程名排序            ***\n");
    printf("***          5.对健身课程按价格排序              ***\n");
    printf("******************************************************\n");
    int choice4;
    scanf("%d", &choice4);

    COURSE *Stu_Cou_head = Stu_Course_list_head(student);
    COURSE *tem = Stu_Cou_head;
    switch (choice4)
    {
    case 1:
    {
        Course_time_order(Stu_Cou_head); // 这里的形参是学员的课程链表的头指针,按学员的课程的时间排序
        break;
    }
    case 2:
    {
        Course_Date_order(Stu_Cou_head);
        break;
    }
    case 3:
    {
        Course_DaTi_order(Stu_Cou_head);
        break;
    }
    case 4:
    {
        Course_name_order(Stu_Cou_head);
        break;
    }
    case 5:
    {
        Course_score_order(Stu_Cou_head);
        break;
    }
    default:
    {
        printf("输入错误\n");
        break;
    }
        delcoulist(tem);
    }
    printf("*************************************************\n"); // 规范长度
    printf("***           你是否想继续使用排序？            ***\n");
    printf("***           1.是，返回功能菜单               ***\n");
    printf("***           2.否，返回主菜单                 ***\n");
    printf("*************************************************\n"); // 规范长度
    int choice41;
    scanf("%d", &choice41);
    switch (choice41)
    {
    case 1:
        menuf4(student);
        return;
    default:
        return;
    }
}

void menuf5(STUDENT *student)
{
    void stumenu(STUDENT * student);
    printf("*************************************************\n");//规范长度
    printf("***      请选择对什么信息进行统计：             ***\n");
    printf("***         1 按项目统计课程                   ***\n");
    printf("***         2 按上课地点统计课程               ***\n");
    printf("***         3 按上课时间统计课程               ***\n");
    printf("***         4 按项目，上课时间统计课程          ***\n");
    printf("***         5 按上课地点，上课时间统计课程      ***\n");
    printf("***         6.统计某时间内课程数               ***\n");
    printf("***         7.统计某时间内健身花销             ***\n");
    printf("*************************************************\n");//规范长度

    int choice5;
    scanf("%d", &choice5);
    switch (choice5)
    {
    case 1:
    {
        stucoursepro(student);
        break;
    }
    case 2:
    {
        stucourseplace(student);
        break;
    }
    case 3:
    {
        stucoursetime(student);
        break;
    }
    case 4:
    {
        stucourseprotime(student);
        break;
}
    case 5:
    {
        stucourseplacetime(student);
        break;
    }
    case 6:
    {
        stucourseperiod(student);
        break;
    }
    case 7:
    {
        courseperiod(student);
        break;
    }
    default:
        printf("输入错误\n");
        break;
    }
    printf("*************************************************\n"); // 规范长度
    printf("***           你是否想继续使用统计？            ***\n");
    printf("***           1.是，返回功能菜单               ***\n");
    printf("***           2.否，返回主菜单                 ***\n");
    printf("*************************************************\n"); // 规范长度
    int choice51;
    scanf("%d", &choice51);
    switch (choice51)
    {
    case 1:
    {
        menuf5(student);
        return;
    }
    default:
    {
        return;
    }
    }
}

void menuf6(STUDENT *student)
{
    void stumenu(STUDENT * student);
    printf("请输入原密码：\n");
    char oldpass[30];
    printf("这是您原先的密码：%s\n", student->password);
    printf("请输入新的密码\n");
    char pass[30];
    scanf("%s", pass);
    STUDENT *stuhead = insertstu();
    STUDENT *tem = stuhead;//头
    while (stuhead != NULL)
    {
        if (strcmp(stuhead->account, student->account) == 0)
        {
            strcpy(stuhead->password, pass);
        }
        stuhead = stuhead->next;
    }
    char road[100]="C:\\Users\\lenovo\\Desktop\\学员\\学员.txt";
    FILE *fpr = fopen(road, "w");
    if (fpr == NULL)
    {
        printf("打开文件失败。\n");
    }
    else
    {
    stuhead = tem;
    while (stuhead != NULL)
    {
        fprintf(fpr,"\n%s %s %s %d %s",stuhead->name,stuhead->account,stuhead->password,stuhead->score,stuhead->number);
        stuhead = stuhead->next;
    }
    }
    fclose(fpr);
    delstulist(tem);
    printf("*************************************************\n"); // 规范长度
    printf("***           你是否想继续修改密码？        ***\n");
    printf("***           1.是，返回功能菜单            ***\n");
    printf("***           2.否，返回主菜单              ***\n");
    printf("*************************************************\n"); // 规范长度
    int choice51;
    scanf("%d", &choice51);
    switch (choice51)
    {
    case 1:
    {
        menuf6(student);
        return;
    }
    default:
    {
        return;
    }
    }
}
void stumenu(STUDENT *student)
{
    printf("*************************************************\n");//规范长度
    printf("***               欢迎使用健身房系统            ***\n");
    printf("***               请选择您想使用的功能:         ***\n");
    printf("***               1.修改个人信息               ***\n");
    printf("***               2.管理课程报名信息            ***\n");
    printf("***               3.信息查询                   ***\n");
    printf("***               4.信息排序                   ***\n");
    printf("***               5.信息统计                   ***\n");
    printf("***               6.维护密码                   ***\n");
    printf("*************************************************\n");//规范长度
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        menuf1(student);
        break;
    }
    case 2:
    {
        menuf2(student);
        break;
    }
    case 3:
    {
        menuf3(student);
        break;
    }
    case 4:
    {
        menuf4(student);
        break;
    }
    case 5:
    {
        menuf5(student);
        break;
    }
    case 6:
    {
        menuf6(student);
        break;
    }
    default:
    {
        printf("输入错误\n");
        break;
    }
    }
    printf("你是否想继续使用系统？\n");
    printf("1.是\n");
    printf("2.否，退出系统\n");
    int choiced;
    scanf("%d", &choiced);
    if (choiced == 1)
    {
        stumenu(student);
        return;
    }
    else
    {
        printf("欢迎下次光临\n");
        return;
    }
}

void stu_reg() // 学员注册函数
{
    char name[30];     // 姓名
    char account[30];  // 账号
    char password[30]; // 密码
    int score;         // 等级
    char number[30];   // 号码
    STUDENT *new_stu = (STUDENT *)malloc(sizeof(STUDENT));
    printf("请输入你的姓名：");
    scanf("%s", name);
    printf("请输入您的电话号码");
    scanf("%s", number);
    printf("请输入你的充值金额");
    scanf("%d", &score);
    printf("请输入你的账号");
    scanf("%s", account);
    printf("请输入你的密码");
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
    printf("请再次输入你的密码\n");
    char str1[30];
    while (1)
    {
        int i;
        for (i = 0; i < 20; i++)
        {
            if ((str1[i] = getch()) != '\b' && str1[i] != '\r')
            {
                putchar('*');
            }
            // getch()从控制台输入一各字符但是不显示
            /*
                当在第i个字符输入退格键时，会把第i-1个字符赋值为'\0',
                并将i指向i-2 ,经过循环的i++后，i就指向了刚刚赋值为 '\0'的位置
            */
            if (str1[i] == '\b' && i > 0)
            {
                str1[--i] = '\0';
                i--;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
            // 如果在最开始就按退格键，就让i=-1
            if (str1[i] == '\b' && i == 0)
            {
                i = -1;
            }
            // 如果输入的是回车，就退出输入循环
            if (str1[i] == '\r')
            {
                break;
            }
        }
        printf("\n");
        str1[i] = '\0';
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
    bool judge=panstu(account);
    strcpy(new_stu->name, name);
    strcpy(new_stu->number, number);
    strcpy(new_stu->account, account);
    
    new_stu->score = score;
    new_stu->next = NULL;
    if (judge != true)
    {
        if(strcmp(str,str1)!=0)
        {
            printf("两次密码不一致\n");
            return;
        }
        strcpy(new_stu->password, str);
        // 将新教练加入到教练文件中
        char road[100] = "C:\\Users\\lenovo\\Desktop\\学员\\学员.txt";
        FILE *fp = fopen(road, "ab+");
        if (fp != NULL)
        {
            fprintf(fp, "\n%s %s %s %d %s ", new_stu->name, new_stu->account, new_stu->password,  new_stu->score,new_stu->number);
        }
        else
        {
            printf("无法创建文档。\n");
        }
        fclose(fp); // 关闭文件流
        // 开辟该教练的文件
        char f2[100] = "C:\\Users\\lenovo\\Desktop\\学员\\";
        strcat(f2, new_stu->account);
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
        printf("该用户已存在\n");
    }
}
