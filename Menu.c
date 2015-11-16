#include "Salary.h"

const static char mainMenu[][20]={"1.一车间", "2.二车间", "3.机修车间", "4.厂办", "5.宣传部", "6.厂总情况", "0.不保存退出", "7.保存并退出"};
const static char departmentMenu[][40]={"1.信息初始化(慎选）","2.增加信息","3.删除信息","4.修改信息",
                            "5.查询ID","6.查寻个人工资信息","7.遍历打印粗略信息","8.遍历打印详细信息",
                            "9.发放工资","10.信息排序","11.保存信息","0.回主菜单"};
/*打印主界面,获取按键*/
int printMainMenu(){
    int n;
    system("clear");
    printf("  ______________工资管理系统主界面______________\n\n\n");
    printf(" \t -%s\t -%s\n", mainMenu+0, mainMenu+1);
    printf("\t -%s\t -%s\n", mainMenu+2, mainMenu+3);
    printf("\t -%s\t -%s\n", mainMenu+4, mainMenu+5);
    printf("\t -%s\t -%s\n\n\n", mainMenu+6, mainMenu+7);
    printf("  _________________________________________________\n\n\n");
    while(1){
        printf("  请输入要进入的模块 :   ");
        scanf("%d", &n);
        if(n>=0 && n<8)
            break;
        printf("  !!!!输入有误，请重新输入!!!!\n");
    }
    return n;
}
/*打印1-5个部门情况*/
int printDepartmentMenu(char *name){
    int i;
    int choice;
    char ch;
    system("clear");
    printf("   ________%s 模块_________\n", name);
    for(i=0; i<NUM_OF_MODULE; i++){
        printf("\t -%s \n", departmentMenu+i);
    }
    while(1){
        printf(" 请输入要进入的模块 :  ");
        scanf("%d", &choice);
        if(choice<NUM_OF_MODULE && choice>=0){
            if(choice == 1){
                printf(" 确定要初始化吗？（会删除原有信息）[Y/N] :");
                getchar();
                scanf("%c", &ch);
                if(ch=='Y' || ch=='y')
                    break;
                else
                    continue;
            }
            else
                break;
        }
        printf(" !!!!输入有误,请重新输入!!!\n");
    }
    return choice;
}

/*从主菜单中获取子菜单选项*/
int setModule(int choice, char **path, char **name){
    char *p = NULL;
    char *pName = NULL;
    p = (*path) = (char*)calloc(20, sizeof(char));
    pName = (*name) = (char*)calloc(20, sizeof(char));

    switch(choice){
        case 1:
            strcpy(p, PATH_DATA0);
            strcpy(pName, mainMenu+0);
            break;
        case 2:
            strcpy(p, PATH_DATA1);
            strcpy(pName, mainMenu+1);
            break;
        case 3:
            strcpy(p, PATH_DATA2);
            strcpy(pName, mainMenu+2);
            break;
        case 4:
            strcpy(p, PATH_DATA3);
            strcpy(pName, mainMenu+3);
            break;
        case 5:
            strcpy(p, PATH_DATA4);
            strcpy(pName, mainMenu+4);
            break;
        case 6:
            strcpy(pName, mainMenu+5);
            break;
        default:
            printf("  输入选项有误！");
            return -1;
    }
    if(choice == 6)
        return 1;   //一般情况1-5
    else
        return 0;   //特殊情况6
}
/*打印总厂情况，即菜单6*/
void printSumSalary(Deptment_t *p[]){
    int i;
    int sum_people=0;
    float sum_theory=0.0f, sum_real=0.0f;
    Deptment_t temp;
    system("clear");
    printf("   _______________总厂情况____________\n\n");
    printf("   %s %s   %s    %s\n\n", "部门名称",
            "总人数", "理论应发工资", "实际已发工资");
    for(i=0; i<NUM_OF_DEPARTMENT; i++){
        temp = *p[i];
        printf("  %15s %5d  %12.2f  %12.2f\n", temp.name,
                temp.num_people,
                temp.sum_theory,
                temp.sum_real);
        sum_people += temp.num_people;
        sum_theory += temp.sum_theory;
        sum_real += temp.sum_real;
    }
    printf("  %15s %5d  %12.2f  %12.2f\n", "全部总计", sum_people, sum_theory, sum_real);
    printf(" 按回车回到主菜单>> \n");
    getchar(); getchar();
}
