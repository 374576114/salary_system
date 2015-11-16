#include "Salary.h"
/*发放工资系统*/
const static char mainMenu[][20]={"一车间部", "二车间部", "  机修车间", "厂办公室", "宣传部门", "厂总情况"};

int sendSalary(Node_t *pHead){
    Node_t *p = pHead;
    float money;
    float temp;
    float sum_send = 0.0;

    system("clear");
    printf("\t发工资系统，输入实发金额，如果中间需要退出，输入-1即可\n");
    while(p->next){
        if((*p).salay.bSalaryPaid == 0){
            printSalaryOneTime(p, 0);
            printf("请输入实发金额：   ");
            scanf("%f", &money);
            if(money == -1.0F){
                printf("\t结束此次发放，下次可以继续发放工资！\n\t已经发放工资总数： %.2f\n", sum_send);
                return 0;
            }
            temp = money - (*p).salay.wages_real_be_paid;
            if(temp>=0.1F || temp<=-0.1F){
                printf("\t!!!发放金额有误，请重新发放!!!!\n");
                continue;
            }
            sum_send += money;
            (*p).salay.received = money;
            (*p).salay.bSalaryPaid = 1;
        }
        p = p->next;
    }
    printf("\t工资已经发放完毕！\n\t此次已经发放工资总数： %.2f\n", sum_send);
    return 0;
}

/*汇总一个部门的所有信息*/
int summaryAll(Node_t *pHead, Deptment_t *pDep, char *name){
    Node_t *p = pHead;
    int n = 0;
    float sum = 0.0F, sum_send = 0.0F;

    (*pDep).sum_real = sum_send;
    while(p->next){
        n++;
        sum += (*p).salay.wages_real_be_paid;
        if((*p).salay.bSalaryPaid == 1){
            sum_send += (*p).salay.received;
        }
        p = p->next;
    }
    (*pDep).sum_real = sum_send;
    (*pDep).num_people = n;
    (*pDep).sum_theory = sum;
    strcpy((*pDep).name, name);
    return 0;
}
/*汇总5个部门信息*/
int summary5Department(Node_t *oneDepart[], Deptment_t *pSumDep[]){
    int i;
    for(i=0; i<NUM_OF_DEPARTMENT; i++){
        pSumDep[i] = (Deptment_t *)calloc(1, sizeof(Deptment_t));
        summaryAll(oneDepart[i], pSumDep[i], mainMenu[i]);
    }
}
