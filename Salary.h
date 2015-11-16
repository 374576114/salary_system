#ifndef SALARY_H_INCLUDE
#define SALARY_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>

#define NUM_OF_DEPARTMENT 5 //公司部门个数

#define PATH_DATA0 "./Data0.dat"
#define PATH_DATA1 "./Data1.dat"
#define PATH_DATA2 "./Data2.dat"
#define PATH_DATA3 "./Data3.dat"
#define PATH_DATA4 "./Data4.dat"

#define MAX_PRINT_LINE 15//每页最大打印行数
#define NUM_OF_MODULE 12 //子菜单项数
/*员工各种信息结构体*/
//基本信息
typedef struct EmployeeBasicInformation{
    int ID; //员工类别
    char name[20];  //员工姓名
    int level;  //员工类别
    float basic_salary; //员工每月基本工资
}employeeInfo_t;
//基本工作信息
typedef struct EmployeeSalaryBasicInformation{
    int day_work;//工作天数
    int day_leave;//请假天数（普通请假）
    int day_illed; //病假天数
    int hours_overtime; //加班时间
    float salary;   //应付工资
}salary_t;
/*
            奖金以,津贴,扣费
**奖金说明存放一个int 记录，可以从另一个表中读取其详细信息
**对于此次系统编写，不涉及此表编写，则对应status设为0
**即不存储也不读取其相应信息
*/
typedef struct EmployeeAllowanceInformation{
    float allowance;  //津贴
    int status;      //津贴说明
}allowance_t;

typedef struct EmployeeRewardInformation{
    float reward; //奖金
    int status;   //奖金说明
}reward_t;

typedef struct EmployeeDeduction{
    float deduction;  //各种扣费
    int status;      //扣费说明
}deduction_t;
//每月工资基本项
typedef struct EmployeePerMonSalary{
    employeeInfo_t employeeInfo;
    salary_t wages_should_be_paid;
    allowance_t allowance;
    reward_t reward;
    deduction_t deduction;
    float wages_real_be_paid;   //理论赢发放工资
    int bSalaryPaid;    //工资是否已经发放
    float received;     //实际发放工资
}salaryPerMon_t;
/*信息存储节点的结构体*/
typedef struct NodeInfo{
    salaryPerMon_t salay;
    struct NodeInfo *next;
}Node_t;
/*部门信息*/
typedef struct DepartmentInfo{
    char name[20];
    int num_people;    //部门总人数
    float sum_theory;   //理论实发总工资
    float sum_real;     //实际已经发放工资
}Deptment_t;


int readPassword(void);/*读取密码*/
void printSalary(Node_t *node, int mode);/*打印个人工资函数*/
void printSalaryOneTime(Node_t *node, int mode);/*只打印一个*/
int readDataFromFile(Node_t **pHead, const char *path);/*从文本中读取数据*/
int writeDataToFile(Node_t *pHead, const char *path);/*写书据到文本*/
int readDataFromKeyboard(Node_t **pHead);/*从键盘读取数据*/
void searchData(Node_t *p);
int modifyData(Node_t *pHead);
int deleteData(Node_t **pHead);
void addData(Node_t *pHead);
void sortData(Node_t *pHead);
int sendSalary(Node_t *pHead);
int summaryAll(Node_t *pHead, Deptment_t *pDep, char *name);

int printMainMenu();
int printDepartmentMenu(char *name);
int setModule(int choice, char **path, char **name);
void printSumSalary(Deptment_t *p[]);
int summary5Department(Node_t *oneDepart[], Deptment_t *pSumDep[]);
void deleteAllData(Node_t *pHead);
int printInfoByID(Node_t *pHead);


#endif // SALARY_H_INCLUDED
