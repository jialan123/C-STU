//
// Created by Administrator on 2023/4/27.
//
#include "stdio.h"
#include "conio.h"      //gtech()函数使用头文件
#include "windows.h"    //Sleep()使用的头文件
#include "string.h"     //strcmp()使用的头文件
#include "assert.h"
#include "stdlib.h"
//#define Maxsize 100;

#define typedef void* datatype;


//用户表，包含姓名，账号，密码，地址，职位
typedef
struct User {
    const char Uname;
    int User;
    int Password;
    const char Dress;
    const char Position;
} User;

//用户表，包含姓名，账号，密码，地址，职位
typedef
struct {
    const char Uname;
    int User;
    int Password;
    const char Dress;
    const char Position;
    struct Cashier *next;
} Cashier;

//余额表
typedef
struct Money {
    double money;
    struct User *data[20];
};

//总菜单
void Totalmenu() {
    system("cls");//清屏操作
    printf("\n\n\n");
    printf("\t|--------------优化管理系统--------------|\n");
    printf("\t|         1.出纳员菜单            \n");
    printf("\t|         2.用户菜单            \n");
    printf("\t|         3.管理员菜单          \n");
    printf("\t|         0.退出           \n");
    printf("\t|-----------------------------------------------|\n");
    printf("\n");
    printf("\t\t请选择（0-3）：");
}

//出纳员菜单
void CashierMenu() {
    system("cls");//清屏操作
    printf("\n\n\n");
    printf("\t|--------------出纳员管理系统--------------|\n");
    printf("\t|         1.出纳员账号登陆            \n");
    printf("\t|         2.修改密码            \n");
    printf("\t|         3.注册新的银行账户           \n");
    printf("\t|         4.查看客户账户            \n");
    printf("\t|         5.管理用户账户           \n");
    printf("\t|-----------------------------------------------|\n");
    printf("\n");
    printf("\t\t请选择（0-5）：");
}

//出纳员选项
void CashierMenuChoose() {
    CashierMenu();
    int n;
    scanf("%d", &n);
    getchar();
}


//用户菜单
void UserMenu() {
    system("cls");//清屏操作
    printf("\n\n\n");
    printf("\t|--------------用户管理系统--------------|\n");
    printf("\t|         1.账号登陆            \n");
    printf("\t|         2.更新个人详细信息            \n");
    printf("\t|         3.修改密码            \n");
    printf("\t|         4.查看余额            \n");
    printf("\t|         5.查看个人交易历史            \n");
    printf("\t|         6.转账            \n");
    printf("\t|         7.提款            \n");
    printf("\t|         8.提交现金            \n");
    printf("\t|         0.退出           \n");
    printf("\t|-----------------------------------------------|\n");
    printf("\n");
    printf("\t\t请选择（0-8）：");
}

//用户菜单选择
void LoginMenuChoose() {
    UserMenu();
    int n;
    scanf("%d", &n);
    getchar();
}






