//
// Created by Administrator on 2023/4/27.
//
#include "stdio.h"
#include "conio.h"      //gtech()����ʹ��ͷ�ļ�
#include "windows.h"    //Sleep()ʹ�õ�ͷ�ļ�
#include "string.h"     //strcmp()ʹ�õ�ͷ�ļ�
#include "assert.h"
#include "stdlib.h"
//#define Maxsize 100;

#define typedef void* datatype;


//�û��������������˺ţ����룬��ַ��ְλ
typedef
struct User {
    const char Uname;
    int User;
    int Password;
    const char Dress;
    const char Position;
} User;

//�û��������������˺ţ����룬��ַ��ְλ
typedef
struct {
    const char Uname;
    int User;
    int Password;
    const char Dress;
    const char Position;
    struct Cashier *next;
} Cashier;

//����
typedef
struct Money {
    double money;
    struct User *data[20];
};

//�ܲ˵�
void Totalmenu() {
    system("cls");//��������
    printf("\n\n\n");
    printf("\t|--------------�Ż�����ϵͳ--------------|\n");
    printf("\t|         1.����Ա�˵�            \n");
    printf("\t|         2.�û��˵�            \n");
    printf("\t|         3.����Ա�˵�          \n");
    printf("\t|         0.�˳�           \n");
    printf("\t|-----------------------------------------------|\n");
    printf("\n");
    printf("\t\t��ѡ��0-3����");
}

//����Ա�˵�
void CashierMenu() {
    system("cls");//��������
    printf("\n\n\n");
    printf("\t|--------------����Ա����ϵͳ--------------|\n");
    printf("\t|         1.����Ա�˺ŵ�½            \n");
    printf("\t|         2.�޸�����            \n");
    printf("\t|         3.ע���µ������˻�           \n");
    printf("\t|         4.�鿴�ͻ��˻�            \n");
    printf("\t|         5.�����û��˻�           \n");
    printf("\t|-----------------------------------------------|\n");
    printf("\n");
    printf("\t\t��ѡ��0-5����");
}

//����Աѡ��
void CashierMenuChoose() {
    CashierMenu();
    int n;
    scanf("%d", &n);
    getchar();
}


//�û��˵�
void UserMenu() {
    system("cls");//��������
    printf("\n\n\n");
    printf("\t|--------------�û�����ϵͳ--------------|\n");
    printf("\t|         1.�˺ŵ�½            \n");
    printf("\t|         2.���¸�����ϸ��Ϣ            \n");
    printf("\t|         3.�޸�����            \n");
    printf("\t|         4.�鿴���            \n");
    printf("\t|         5.�鿴���˽�����ʷ            \n");
    printf("\t|         6.ת��            \n");
    printf("\t|         7.���            \n");
    printf("\t|         8.�ύ�ֽ�            \n");
    printf("\t|         0.�˳�           \n");
    printf("\t|-----------------------------------------------|\n");
    printf("\n");
    printf("\t\t��ѡ��0-8����");
}

//�û��˵�ѡ��
void LoginMenuChoose() {
    UserMenu();
    int n;
    scanf("%d", &n);
    getchar();
}






