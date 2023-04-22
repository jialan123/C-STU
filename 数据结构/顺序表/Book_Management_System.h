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
//两个结构体封装图书和读者的基本信息
typedef struct Book {
    int iNum; //图书编号
    char acName[15];//图书名称
    char acAuthor[15];//图书作者
    char acPress[15]; //图书出版社
    int iAmount; //图书库存量
} Book;
typedef struct Reader {
    int iNum; //读者编号
    char acName[15]; //读者姓名
    char acSex[4];  //读者性别
    int iMax; //读者最大可借阅量
    int iAmount; //读者当前可借阅量
    int BookId[10]; //读者已经借阅图书列表
} Reader;


//功能函数声明

//显示主菜单
void ShowMainMeun();

//显示书籍管理的子菜单
void ShowBookMenu();

//读取图书信息到文件里面
int ReadBookFile(const char *pcMode);

//显示图书信息
void ShowBook();

//添加图书信息
void AddBook();

//查询    通过图书编号查找
int SearchBook();

//删除图书信息
void DeleteBook();

//显示修改图书信息选项的子菜单
void ShowModifyBookMenu();

//保存图书信息到文件
void SaveBookFile(int iBookId);

//修改图书信息
void ModifyBook();

//书籍管理
void MangaeBook();

//显示读者管理的子菜单
void ShowReaderMenu();

//从文件里面读取读者信息
int ReadReaderFile(const char *fopenMode);

//显示读者信息
void ShowReader();

//新增读者信息
void AddReader();

//查找读者信息
int SearchReader();

//删除读者信息
void DeleteReader();

//显示读者信息可以修改的选项
void ShowModifyReaderMenu();

//保存读者信息到文件里面
void SaveReaderFile(int iReaderId);

//修改读者信息
void ModifyReader();

//读者管理模块
void MangaeReader();

//显示借还功能菜单
void ShowBorrowReturnMenu();

//借书
void BorrowBook();

//还书
void ReturnBook();

//借还书模块
void BorrowReturnManger();