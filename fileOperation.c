#include "Salary.h"
/*从文本中读取数据*/
int readDataFromFile(Node_t **pHead, const char *path){
    Node_t *p = NULL;
    Node_t temp;
    int fd;
    int nCount = 0;

    fd = open(path, O_RDONLY);
    if(fd == -1){
        printf("Cannot open the file\n");
        exit(1);
    }
    p = (*pHead) = (Node_t *)calloc(1, sizeof(Node_t));
    do{
        nCount = read(fd, &temp, sizeof(Node_t));
        if(nCount == 0){
            //printf("end input \n");
            break;
        }
        *p = temp;
        p->next = (Node_t *)calloc(1, sizeof(Node_t));
        p = p->next;
    }while(1);

    close(fd);
    return 0;
}
/*把内存中数据写到文件中*/
int writeDataToFile(Node_t *pHead, const char *path){
    Node_t *p = pHead;
    int fd, i;

    //fd = open(path, O_WRONLY|O_CREAT|O_TRUNC, 0666);
    fd = open(path, O_WRONLY|O_CREAT|O_TRUNC ,0666);
    if(fd == -1){
        printf("Cannot create the file\n");
        exit(1);
    }
    while(p->next){
        write(fd, p, sizeof(Node_t));
        p = p->next;
    }
    close(fd);
    return 0;
}
/*从键盘中读取数据*/
int readDataFromKeyboard(Node_t **pHead){
    Node_t *p = NULL;
    int i;
    int nPeople;
    p = (*pHead) = (Node_t*)calloc(1, sizeof(Node_t));
    printf("请输入本部门人数： ");
    scanf("%d", &nPeople);
    for(i=0; i<nPeople; i++){
        InputInfo(p);
        p->next = (Node_t*)calloc(1, sizeof(Node_t));
        p = p->next;
    }
    return 0;
}
