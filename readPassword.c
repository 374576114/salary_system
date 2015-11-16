#include "Salary.h"

//读取密码，如果正确返回1,否则返回0
int readPassword(){
    int i;
    char buff[20];
    //password
    const char password[] = "123456";
    char ch;
    int tty = open("/dev/tty", O_RDONLY);
    if(tty == -1)
        exit(0);
    struct termios newt;
    struct termios oldt;
    tcgetattr(tty, &oldt);
    newt = oldt;
    //设置字符缓冲且不回显
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(tty, TCSANOW, &newt);
    for(i=0; i<20; i++){    //最多读20 字符
        read(tty, &ch, 1);
        if(ch == 10)
            break;
        buff[i] = ch;
    }
    tcsetattr(tty, TCSANOW, &oldt);
    close(tty);
    if(strcmp(password, buff) == 0)
        return 1;
    else
        return 0;
}

int _authentication(){
    char usr[] = "admin";
    char buff[100];
    int b=0;
    printf(" 请输入用户名（回车后继续输入密码）：\n ");
    scanf("%s", buff);
    if(strcmp(buff, usr) == 0){
        b=readPassword();
        if(b==0)
        printf("!!!!密码错误!!!!\n");
    }
    else
        printf("!!!用户名错误!!!\n");
    return b;
}

int authentication(){
    int i;
    int b = 0;
    system("clear");
    printf("\t欢迎使用工资管理系统\n");
    for(i=0; i<3; i++){
        b = _authentication();
        if(b==0 && i!=2)
            printf("还有%d次认证机会\n", 2-i);
        else
            break;
    }
    return b;
}
