#pragma once

#include<stdio.h>
#include <windows.h>
//console
#include<conio.h>

#define BOOK_NUM  200
#define READER_NUM  100


#define BOOK_DATA  astBook[i].iNum,astBook[i].acName,astBook[i].acAuthor,astBook[i].acPress,astBook[i].iAmount
#define LEN_BOOK  sizeof(struct Book)

#define LEN_READER sizeof(struct Reader)
#define READER_DATA astReader[i].iNum,astReader[i].acName,astReader[i].acSex,astReader[i].iMax,astReader[i].iAmount
//�����ṹ���װͼ��Ͷ��ߵĻ�����Ϣ
typedef struct Book {
    int iNum; //ͼ����
    char acName[15];//ͼ������
    char acAuthor[15];//ͼ������
    char acPress[15]; //ͼ�������
    int iAmount; //ͼ������
} Book;
typedef struct Reader {
    int iNum; //���߱��
    char acName[15]; //��������
    char acSex[4];  //�����Ա�
    int iMax; //�������ɽ�����
    int iAmount; //���ߵ�ǰ�ɽ�����
    int BookId[10]; //�����Ѿ�����ͼ���б�
} Reader;


//���ܺ�������

//��ʾ���˵�
void ShowMainMeun();

//��ʾ�鼮������Ӳ˵�
void ShowBookMenu();

//��ȡͼ����Ϣ���ļ�����
int ReadBookFile(const char *pcMode);

//��ʾͼ����Ϣ
void ShowBook();

//���ͼ����Ϣ
void AddBook();

//��ѯ    ͨ��ͼ���Ų���
int SearchBook();

//ɾ��ͼ����Ϣ
void DeleteBook();

//��ʾ�޸�ͼ����Ϣѡ����Ӳ˵�
void ShowModifyBookMenu();

//����ͼ����Ϣ���ļ�
void SaveBookFile(int iBookId);

//�޸�ͼ����Ϣ
void ModifyBook();

//�鼮����
void MangaeBook();

//��ʾ���߹�����Ӳ˵�
void ShowReaderMenu();

//���ļ������ȡ������Ϣ
int ReadReaderFile(const char *fopenMode);

//��ʾ������Ϣ
void ShowReader();

//����������Ϣ
void AddReader();

//���Ҷ�����Ϣ
int SearchReader();

//ɾ��������Ϣ
void DeleteReader();

//��ʾ������Ϣ�����޸ĵ�ѡ��
void ShowModifyReaderMenu();

//���������Ϣ���ļ�����
void SaveReaderFile(int iReaderId);

//�޸Ķ�����Ϣ
void ModifyReader();

//���߹���ģ��
void MangaeReader();

//��ʾ�軹���ܲ˵�
void ShowBorrowReturnMenu();

//����
void BorrowBook();

//����
void ReturnBook();

//�軹��ģ��
void BorrowReturnManger();