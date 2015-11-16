#include "Salary.h"

//输入一个人的信息
int  InputInfo(Node_t *node)
{
    float overtimeHour = 0;
    float perDayPaid = 0;
    float salary = 0;

    printf("请输入ID，姓名，类别，基本工资（空格隔开,下同）：\n(名字中如有空格，请用下划线表示)\n");
    scanf("%d %s %d %f", &(*node).salay.employeeInfo.ID,
        (*node).salay.employeeInfo.name,
        &(*node).salay.employeeInfo.level,
        &(*node).salay.employeeInfo.basic_salary);
    printf("\n请输入出勤天数，请假天数，病假天数，加班小时数：\n");
    scanf("%d %d %d %d", &(*node).salay.wages_should_be_paid.day_work,
        &(*node).salay.wages_should_be_paid.day_leave,
        &(*node).salay.wages_should_be_paid.day_illed,
        &(*node).salay.wages_should_be_paid.hours_overtime);

    printf("\n请输入津贴:  ");
    scanf("%f", &(*node).salay.allowance.allowance);
    (*node).salay.allowance.status = 0;
    printf("请输入奖金:  ");
    scanf("%f", &(*node).salay.reward.reward);
    (*node).salay.reward.status = 0;
    printf("请输入其他扣费:  ");
    scanf("%f", &(*node).salay.deduction.deduction);
    (*node).salay.deduction.status = 0;

    //计算应该发放的工资
    perDayPaid = (*node).salay.employeeInfo.basic_salary / 30.0f;
    overtimeHour = perDayPaid / 8.0f;
    salary = perDayPaid * (*node).salay.wages_should_be_paid.day_work
        + perDayPaid * (*node).salay.wages_should_be_paid.day_illed * 0.9f
        + overtimeHour * (*node).salay.wages_should_be_paid.hours_overtime;
    (*node).salay.wages_should_be_paid.salary = salary;

    (*node).salay.wages_real_be_paid = salary
        + (*node).salay.allowance.allowance
        + (*node).salay.reward.reward
        - (*node).salay.deduction.deduction;
    (*node).salay.bSalaryPaid = 0;

    return 0;
}
/*打印个人工资函数，mode 0 为简单打印， mode 1 为详细打印*/
void _PrintSalary(Node_t *node, int mode){
    switch(mode){
    case 0:
        //printf("%7s   %10s %10s %15s  %10s\n", "ID", "姓名", "应发工资", "奖金+津贴-扣费","实发工资");
        printf("%7d %10s %8.2f  %13.2f  %8.2f\n",
            (*node).salay.employeeInfo.ID,
            (*node).salay.employeeInfo.name,
            (*node).salay.wages_should_be_paid.salary,
            (*node).salay.allowance.allowance
            + (*node).salay.reward.reward
            - (*node).salay.deduction.deduction,
            (*node).salay.wages_real_be_paid);
        break;
    case 1:
    //    printf("%3s  %5s %10s   %10s %10s %10s %10s %10s %5s %5s\n", "ID", "姓名", "基本工资", "工作天数",
    //"休假天数", "病假天数", "加班小时", "奖金", "津贴", "各类扣费");
        printf("#%7d %10s %7.2f  (%2d %3d %3d %4d )  (%7.2f %7.2f %7.2f)\n",
            (*node).salay.employeeInfo.ID,
            (*node).salay.employeeInfo.name,
            (*node).salay.employeeInfo.basic_salary,
            (*node).salay.wages_should_be_paid.day_work,
            (*node).salay.wages_should_be_paid.day_leave,
            (*node).salay.wages_should_be_paid.day_illed,
            (*node).salay.wages_should_be_paid.hours_overtime,
            (*node).salay.reward.reward,
            (*node).salay.allowance.allowance,
            (*node).salay.deduction.deduction);
        break;
    }
}
/*循环打印数据*/
void printSalary(Node_t* node, int mode){
    Node_t *p = node;
    int n = 0;
    switch(mode){
    case 0:
        printf("%7s   %10s %10s %15s  %10s\n", "ID", "姓名", "应发工资", "奖金+津贴-扣费","实发工资");
        while(p->next){
            _PrintSalary(p, 0);
            p = p->next;
            n++;
            if(n == MAX_PRINT_LINE){
                n = 0;
                printf("press <Enter> to continue\n");
                getchar();
            }
        }
        break;
    case 1:
        printf("%3s  %5s %10s   %10s %10s %10s %10s %10s %5s %5s\n", "ID", "姓名", "基本工资", "工作天数",
    "休假天数", "病假天数", "加班小时", "奖金", "津贴", "各类扣费");
        while(p->next){
            _PrintSalary(p, 1);
            p = p->next;
            n++;
            if(n == MAX_PRINT_LINE){
                n = 0;
                printf("press <Enter> to continue\n");
                getchar();
            }
        }
        break;
    }
}

void printSalaryOneTime(Node_t *node, int mode){
    switch(mode){
    case 0:
        printf("%7s   %10s %10s %15s  %10s\n", "ID", "姓名", "应发工资", "奖金+津贴-扣费","实发工资");
        _PrintSalary(node, 0);
        break;
    case 1:
        printf("%3s  %5s %10s   %10s %10s %10s %10s %10s %5s %5s\n", "ID", "姓名", "基本工资", "工作天数",
    "休假天数", "病假天数", "加班小时", "奖金", "津贴", "各类扣费");
        _PrintSalary(node, 1);
        break;
    }
}
