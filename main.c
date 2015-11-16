#include "Salary.h"

const static char mainMenu[][20]={"一车间部", "二车间部", "  机修车间", "厂办公室", "宣传部门", "厂总情况"};

void _initData5Files(char *path, int index, Node_t *oneDepart[]){
    int fd;
    fd = open(path, O_CREAT|O_EXCL, 0666);
    if(fd != -1){   //该文当不存在存在
        system("clear");
        printf("   初始化 %s  部门数据.....\n", mainMenu+index);
        readDataFromKeyboard(&oneDepart[index]);
        writeDataToFile(oneDepart[index], path);
    }
    else        //文档存在
        readDataFromFile(&oneDepart[index], path);
    close(fd);
}

/*把数据读到内存中*/
int initData5Files(Node_t *oneDepart[]){
    _initData5Files(PATH_DATA0, 0, oneDepart);
    _initData5Files(PATH_DATA1, 1, oneDepart);
    _initData5Files(PATH_DATA2, 2, oneDepart);
    _initData5Files(PATH_DATA3, 3, oneDepart);
    _initData5Files(PATH_DATA4, 4, oneDepart);
}
int operation(){
    /*填充总厂情况数组*/
    Node_t *oneDepart[5] = {0}; //五个部门数据
    Deptment_t *allSumDepart[5] = {0}; //总数据
    int choice, n, _choice, b=1;
    int i;
    char *path=NULL,*name=NULL;

    initData5Files(oneDepart);
    while(1){
        _choice = printMainMenu();
        if(_choice == 0) //退出
            break;
        else if (_choice == 7){
            writeDataToFile(oneDepart[0], PATH_DATA0);
            writeDataToFile(oneDepart[1], PATH_DATA1);
            writeDataToFile(oneDepart[2], PATH_DATA2);
            writeDataToFile(oneDepart[3], PATH_DATA3);
            writeDataToFile(oneDepart[4], PATH_DATA4);
            break;
        }
        if(setModule(_choice, &path, &name)){ //6打印总情况
            summary5Department(oneDepart, allSumDepart);
            printSumSalary(allSumDepart);
            continue;
        }

        b = 1;
        while(b){
        n = printDepartmentMenu(name);
        /*执行各个功能*/
        choice = _choice - 1;
        switch(n){
            case 0:
                b = 0;
                break;
            case 1:
                deleteAllData(oneDepart[choice]);
                oneDepart[choice] = NULL;
                system("clear");
                readDataFromKeyboard(&oneDepart[choice]);
                //printSalary(oneDepart[choice], 1);
                printf("信息初始化完毕，按回车回到主菜单>>\n");
                getchar();getchar();
                continue;
            case 2:
                setbuf(stdin, NULL);
                addData(oneDepart[choice]);
                //printSalary(oneDepart[choice], 1);
                printf("按回车回到菜单>>\n");
                getchar();getchar();
                continue;
            case 3:
                setbuf(stdin, NULL);
                deleteData(&oneDepart[choice]);
                //printSalary(oneDepart[choice], 1);
                printf("按回车回到菜单>>\n");
                getchar();getchar();
                continue;
            case 4:
                modifyData(oneDepart[choice]);
                //printSalary(oneDepart[choice], 1);
                printf("按回车回到菜单>>\n");
                getchar();getchar();
                continue;
            case 5:
                searchData(oneDepart[choice]);
                printf("按回车回到菜单>>\n");
                getchar();getchar();
                continue;
            case 6:
                printInfoByID(oneDepart[choice]);
                printf("按回车回到菜单>>\n");
                getchar();getchar();
                continue;
            case 7:
                printSalary(oneDepart[choice], 0);
                printf("按回车回到菜单>>\n");
                getchar();getchar();
                continue;
            case 8:
                printSalary(oneDepart[choice], 1);
                printf("按回车回到菜单>>\n");
                getchar();getchar();
                continue;
            case 9:
                sendSalary(oneDepart[choice]);
                printf("按回车回到菜单>>\n");
                getchar();getchar();
                continue;
            case 10:
                sortData(oneDepart[choice]);
                printf("按回车回到菜单>>\n");
                getchar();getchar();
                continue;
            case 11:
                //printSalary(oneDepart[choice], 1);
                writeDataToFile(oneDepart[choice], path);
                printf("保存成功！\n");
                printf("按回车回到菜单>>\n");
                getchar();getchar();
                continue;
            default:
                printf("按回车回到菜单>>\n");
                getchar();getchar();
                continue;
            }
        }
    }
    system("clear");
    printf("\n\n\n_____________谢谢使用该系统_______________\n\n\n");
    return 0;
}


int main(){
    if(!authentication()){
        printf("  \n!!!!! 认证失败，退出程序!!!!!\n");
        return 0;
    }
    operation();
    return 0;
}
