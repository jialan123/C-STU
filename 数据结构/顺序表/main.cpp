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
    //��ʾ�������Ľ���;
    ShowMainMeun();
    int iItem;
    scanf("%d", &iItem);
    while (iItem) {
        switch (iItem) {
            case 1:
                MangaeBook();//ͼ�����ģ��
                break;
            case 2:
                MangaeReader();//���߹���ģ��
                break;
            case 3:

                BorrowReturnManger();//�軹��ģ��
                break;
            default:
                printf("\t\t��������ȷ������!\n\t������3�����ת�����˵�");
                Sleep(3000);
        }
        ShowMainMeun();
        scanf("%d", &iItem);
        getchar();
    }
    return 0;
}