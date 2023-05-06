//
// Created by Administrator on 2023/4/27.
//
#include "rankDate.h"


int main() {
    int n;
    Cashier * cashier = NULL;
    Totalmenu();
    scanf("%d", &n);
    while (n) {
        switch (n) {
            case 0:
                return 0;
                break;
            case 1:
                CashierMenuChoose();
                break;
            case 2:
                LoginMenuChoose();
                break;
            default:
                printf("\t\t请输入正确的数字!\n\t程序将于3秒后跳转到主菜单");
                Sleep(3000);
        }
        Totalmenu();/*调用ShowMainMenu函数绘制界面*/
        scanf("%d", &n);/*提示用户输入数字*/
        getchar();
    }
}