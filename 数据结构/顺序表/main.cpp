//
// Created by Administrator on 2023/4/24.
//
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <windows.h>
//console
#include<conio.h>
#include"Book_Management_System.h"

int main() {
    //显示主函数的界面;
    ShowMainMeun();
    int iItem;
    scanf("%d", &iItem);
    while (iItem) {
        switch (iItem) {
            case 1:
                MangaeBook();//图书管理模块
                break;
            case 2:
                MangaeReader();//读者管理模块
                break;
            case 3:

                BorrowReturnManger();//借还书模块
                break;
            default:
                printf("\t\t请输入正确的数字!\n\t程序将于3秒后跳转到主菜单");
                Sleep(3000);
        }
        ShowMainMeun();
        scanf("%d", &iItem);
        getchar();
    }
    return 0;
}