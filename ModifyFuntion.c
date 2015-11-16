#include "Salary.h"

/*查找某个姓名，显示找到匹配的ID*/
void searchData(Node_t *p){
    char name[20];
    int b = 0;
    printf("请输入要查找的姓名: ");
    scanf("%s", name);
    while(p->next){
        if(strcmp(name, (*p).salay.employeeInfo.name) == 0){
            printf("ID:%7d\t 姓名:%s\n", (*p).salay.employeeInfo.ID, (*p).salay.employeeInfo.name);
            b++;
        }
        p = p->next;
    }
    if(b == 0)
        printf("没有找到匹配\n");
}
/*修改信息*/
int modifyData(Node_t *pHead){
    Node_t *p = pHead;
    Node_t temp1={0}, temp2={0};
    int Id = 0;
    temp1.next = &temp2;
    temp2.next = NULL;
    printf("请输入要修改的ID:   ");
    scanf("%d", &Id);
    while(p->next){
        if((*p).salay.employeeInfo.ID == Id){
            system("clear");
            printf("  已经找到该ID，请重新输入此人信息\n");
            InputInfo(p);
            temp1 = *p;
            printf("修改成功！以下为修改后的信息\n");
            printSalaryOneTime(&temp1, 1);
            return 0;
        }
        p = p->next;
    }
    printf(" 没有找到该ID信息\n");
    return -1;
}
/*删除信息*/
int deleteData(Node_t **pHead){
    Node_t *p = *pHead;
    Node_t *pPre = *pHead;
    char ch;
    int ID;
    printf("请输入要删除信息人的ID:  ");
    scanf("%d", &ID);
    if((**pHead).salay.employeeInfo.ID == ID){
        printSalaryOneTime(*pHead, 1);
        printf("确定删除此信息？ [Y/N] :");
        getchar();
        ch = getchar();
        if(ch == 'n' || ch =='N'){
            printf("未删除！\n");
            return 0;
        }
        if(ch == 'y' || ch == 'Y'){
            (*pHead) = (*pHead)->next;
            printf("删除成功!\n");
            return 0;
        }
        printf("未删除！\n");
        return 0;
    }

    pPre = *pHead;
    p = pPre->next;
    while(p->next){
        if((*p).salay.employeeInfo.ID == ID){
            printSalaryOneTime(p, 1);
            getchar();
            printf("确定删除此信息？ [y /n] :");
            ch = getchar();
            if(ch == 'n' || ch =='N'){
                printf("未删除！\n");
                return 0;
            }
            if(ch == 'y' || ch == "Y"){
                pPre->next = p->next;
                free(p);
                printf("删除成功!\n");
                return 0;
            }
            printf("未删除！\n");
            return 0;
        }
        pPre = p;
        p = p->next;
    }
    printf("未找到该ID信息！\n");
    return 0;
}
/*增加信息*/
void addData(Node_t *pHead){
    Node_t *p = pHead;
    Node_t *ptemp = NULL;
    int ID;
    char ch;
    printf("确定要增加一个信息吗？[Y/N]:");
    ch = getchar();
    if(ch=='Y'||ch=='y'){
        ptemp = (Node_t *)calloc(1, sizeof(Node_t));
        InputInfo(ptemp);
        printf("增加信息成功！\n");
        ptemp->next = p->next;
        p->next = ptemp;
    }
    else{
        printf("未增加信息！\n");
    }
}
/*排序信息*/
void sortData(Node_t *pHead){
    Node_t temp={0};
    Node_t *p = pHead;
    int n = 0;
    int i, j;

    while(p->next){
        n++;
        p = p->next;
    }
    //冒泡排序
    for(i=0; i<n-1; i++){
        p = pHead;
        for(j=0; j<n-1-i; j++){
            if((*p).salay.employeeInfo.ID > (*(p->next)).salay.employeeInfo.ID){
            //printf("%d %d \n",(*p).salay.employeeInfo.ID,   (*(p->next)).salay.employeeInfo.ID);
                temp.salay = (*p).salay;
                (*p).salay = (*(p->next)).salay;
                (*(p->next)).salay = temp.salay;
            }
            p = p->next;
        }
    }
    printf("排序成功！\n");
}
void deleteAllData(Node_t *pHead){
    Node_t *p1, *p2;
    p1 = pHead;
    while(p1->next){
        p2 = p1->next;
        free(p1);
        p1 = p2;
    }
    free(p1);
}
int printInfoByID(Node_t *pHead){
    Node_t *p = pHead;
    int ID;
    printf("请输入要查找信息人的ID：  ");
    scanf("%d", &ID);
    while(p->next){
        if((*p).salay.employeeInfo.ID == ID){
            printSalaryOneTime(p, 1);
            return 0;
        }
        p = p->next;
    }
    printf(" 没有找到该ID\n");
    return 0;

}
