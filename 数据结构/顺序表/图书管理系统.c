#include "stdio.h"
#include "conio.h"      //gtech()函数使用头文件
#include "windows.h"    //Sleep()使用的头文件
#include "string.h"     //strcmp()使用的头文件
#include "assert.h"

//定义用户结构体:读者编号，读者姓名，性别，可借书数，读者已借书的编号
typedef struct User {
    int iNum;
    char acName[15];
    char acSex[4];
    char position[20];
    int iMax;   //student20本，teacher40本
    int iAmount;
    int aiBookld[100];
    int balance;
    int day;
    struct User *next;
} User;

//定义书本结构体：图书编号，图书名，图书作者，出版社，库存量
typedef struct Book {
    int iNum;           //书的编号
    char acName[15];    //书的名称
    char acAuthor[15];  //书的作者
    char acPress[15];   //书的出版社
    int iAmount;        //书的库存量
    struct Book *next;
} Book;


//菜单
void ShowMainMenu() {
    system("cls");//清屏操作
    printf("\n\n\n");
    printf("\t|--------------还原进入图书馆里系统--------------|\n");
    printf("\t|         读者管理系统            \n");
    printf("\t|         1.查询图书馆的总信息            \n");
    printf("\t|         2.查询图书馆藏书信息            \n");
    printf("\t|         3.存入新书            \n");
    printf("\t|         4.旧书信息            \n");
    printf("\t|         5.根据书名检索书刊信息            \n");
    printf("\t|         6.查询读者借阅信息            \n");
    printf("\t|         7.查询读者信息            \n");
    printf("\t|         8.读者借书            \n");
    printf("\t|         9.读者还书            \n");
    printf("\t|         10.文件保存            \n");
    printf("\t|         11.从文件读取            \n");
    printf("\t|         0.退出           \n");
    printf("\t|-----------------------------------------------|");
    printf("\n新打开程序需求添加程序员\n");
    printf("\n");
    printf("\t\t请选择（0-11）：");
}

//存入新书
Book *AddBook(Book *book1) {
    Book *book = book1;

    if (book == NULL) {
        Book *tmp = (Book *) malloc(sizeof(Book));
        tmp->next = NULL;
        assert(tmp);
        printf("输入书的编号：");
        scanf("%d", &tmp->iNum);
        getchar();
        printf("输入书的名称：");
        gets(&tmp->acName);
        printf("输入书的作者：");
        gets(&tmp->acAuthor);
        printf("输入书的出版社：");
        gets(&tmp->acPress);
        printf("输入书的库存量：");
        scanf("%d", &tmp->iAmount);
        book = tmp;

        printf("\n按任意键返回\n");
        getchar();
        return book;
    }
}

//图书馆的总信息
void ShowLiblnfo(const Book *book1, const User *user1) {
    Book *book = book1;
    User *user = user1;
    int bookNUm = 0, readerNUm = 0, mangerNUm = 0;
    while (book != NULL) {
        bookNUm++;
        book = book->next;
    }
    while (user != NULL) {
        readerNUm++;
        user = user->next;
    }
    printf("本图书馆共有%d本，读者%d人\n", bookNUm, readerNUm);
    printf("按任意键返回\n");
    getchar();
    return;
}

//图书馆藏书信息
void ShowLibBook(Book *book1) {
    Book *book = book1;
    while (book != NULL) {
        printf("%d\t%s\t%s\t%s\t%d\n", book->iNum, book->acName, book->acAuthor, book->acPress, book->iAmount);
        book = book->next;
    }
    printf("\n按任意键返回\n");
    getchar();
    return;
}

//旧书处理
Book *DealoldBook(Book *book1) {
    Book *book = book1;
    Book *prev = book1;
    printf("输入要处理旧书编号：");
    int id;
    scanf("%d", &id);
    getchar();
    while (book != NULL) {
        if (id == book->iNum) {
            if (book1 == book) {
                book = book->next;
                free(prev);
                return book;
            }
            prev->next = book->next;
            free(book);
            printf("已将旧书处理掉!\n");
            printf("按任意键返回");
            getchar();
            return book1;
        }
    }
}

//根据书名检索书刊信息
void foundBook(Book *book1) {
    Book *book = book1;
    printf("输入你要查的书的id:");
    int id;
    scanf("%d", &id);
    while (book != NULL) {
        if (id == book->iNum) {
            printf("该书的星系如下：\n");
            printf("%d\t%s\t%s\t%s\t%d\n", book->iNum, book->acName, book->acAuthor, book->acPress, book->iAmount);
            printf("按任意键返回");
            getchar();
            return;
        }
        book = book->next;
    }
    printf("没有找到该书！\n");
    printf("按任意键返回");
    getchar();
    return;
}

//查询读者借阅信息
void foundReader_Info(User *read1) {
    User *reader = read1;
    printf("输入读者号：");
    int id;
    scanf("%d", &id);
    getchar();
    while (reader) {
        if (id == reader->iNum) {
            printf("借阅的书的编号如下：\n");
            for (int i = 0; i < reader->iMax; i++) {
                if (reader->aiBookld[i] != 0) {
                    printf("%d\n", reader->aiBookld[i]);
                }
            }
            printf("按任意键返回");
            getchar();
            return;
        }
        reader = reader->next;
    }
    printf("没有该读者");
    printf("按任意键返回");
    getchar();
    return;
}

//查询读者信息
void foundReaderInfo(User *reader1) {
    User *reader = reader1;
    printf("输入读者id:");
    int id;
    scanf("%d", id);
    getchar();
    while (reader) {
        if (id == reader->iNum) {
            printf("读者id：%d\n", reader->iNum);
            printf("读者姓名：%s\n", reader->acName);
            printf("读者性别：%s\n", reader->acSex);
            printf("读者职位：%s\n", reader->position);
            printf("读者已经借阅书的数量为：%d\n", reader->iAmount);
            printf("按任意键返回");
            getchar();
            return;
        }
        reader = reader->next;
    }
    printf("没有找到该读者：\n");
    printf("按任意键返回");
    getchar();
    return;
}

//读者借书#############
User *LendBook(User *reader1, Book *book1) {
    User *reader = reader1;
    Book *book = book1;

    User *prev = reader1;
    User *tmpp = reader1;

    printf("输入读者id：");
    int id;
    scanf("%d", &id);
    getchar();

    if (reader == NULL) {
        User *tmp = (User *) malloc(sizeof(User));
        tmp->next = NULL;
        tmp->iAmount = 0;
        tmp->iNum = id;

        printf("输入读者姓名：");
        scanf("%s", &tmp->acName);
        getchar();

        printf("输入读者性别：");
        scanf("%s", &tmp->acSex);
        getchar();

        printf("输入读者职位：<student\tor\tteacher>");
        scanf("%s", &tmp->position);
        getchar();

        if (strcmp(tmp->position, "stduent") == 0) {
            tmp->iMax == 20;
            tmp->day = 30;
        } else {
            tmp->iMax = 40;
            tmp->day = 60;
        }
        for (int i = 0; i < tmp->iMax; ++i) {
            tmp->aiBookld[i] = 0;
        }
        printf("输入要借的书的编号：");
        int id_book;
        scanf("%d", &id_book);
        getchar();
        while (book != NULL) {
            if (id_book == book->iNum) {
                if (book->iAmount <= 1) {
                    printf("借阅失败，该图书库不足\n");
                    printf("按任意键返回");
                    getchar();
                    return NULL;
                }
                if ((tmp->iAmount) + 1 > tmp->iMax) {
                    printf("借阅失败，该读者借阅数量已达上线\n");
                    printf("按任意键返回");
                    getchar();
                    return NULL;
                }
                book->iAmount--;
                tmp->aiBookld[tmp->iAmount] = id_book;
                tmp->iAmount;
                reader = tmp;
                printf("借阅成功!\n");
                printf("按任意键返回");
                getchar();
                return reader1;
            }
            book = book->next;
        }
        printf("没有找到该书！\n");
        printf("按任意键返回\n");
        if (reader != NULL) {
            while (reader != NULL) {
                if (id == reader->iNum) {
                    printf("图书馆当前的书籍测：\n");
                    ShowLibBook(book);
                    printf("输入要借的书的编号：");
                    int id_book;
                    scanf("%d", &id_book);
                    getchar();
                    while (book != NULL) {
                        if (id_book == book->iNum) {
                            printf("借阅失败，该书图书馆库存不足\n");
                            printf("按任意键返回");
                            getchar();
                            return reader1;
                        }
                        if (tmpp->iAmount + 1 > tmpp->iMax) {
                            printf("借阅失败，该读者借阅图书数量已达上线\n");
                            printf("按任意键返回");
                            getchar();
                            return reader1;
                        }
                        reader->iAmount++;
                        reader->aiBookld[tmpp->iAmount] = id_book;
                        return reader1;
                    }
                    book = book->next;
                }
                printf("没有找到该书！\n");
                printf("按任意键返回\n");
            }
            reader = reader->next;
        }
    }
}

//读者还书
User *returnBook(User *reader1, Book *book1) {
    User *reader = reader1;
    Book *book = book1;
    printf("输入读者号：");
    int id;
    scanf("%d", &id);
    getchar();

    if (reader != NULL) {
        while (reader != NULL) {
            printf("输入要还的书的编号：");
            int id_book;
            scanf("%d", &id_book);
            getchar();
            for (int i = 0; i < reader->iMax; ++i) {
                if (reader->aiBookld[i] == id_book) {
                    reader->aiBookld[i] = 0;
                    while (book) {
                        if (id_book == book->iNum) {
                            book->iAmount++;
                            printf("还书成功！\n");
                            printf("按任意键返回！\n");
                            getchar();
                            return reader1;
                        }
                        book = book1->next;
                    }
                }
            }
            printf("没有找到该书，检查图书的id\n");
            printf("按任意键返回！\n");
            getchar();
            return reader1;

        }
        reader = reader->next;
    }
    printf("没有找到该读者，检查读者的id是否正确！\n");
    printf("按任意键返回！\n");
    getchar();
    return reader1;
}

//文件保存
void save(Book *book1) {
    FILE *fp;
    Book *pCur = book1;
    int iCount = 0;

    if (pCur == NULL) {
        printf("\n没有学生记录！\n");
        return;
    }
    if ((fp = fopen("book.txt", "wb")) == NULL) {
        printf("创建文件失败！\n");
        getchar();
        exit(1);
    }
    while (pCur) {
        fwrite(pCur, sizeof(Book), 1, fp);
        pCur = pCur->next;
        iCount++;
    }
    printf("\n");

    printf("保存文件的数据数目：%d\n", iCount);
    fclose(fp);
}

//从文件读取
Book *read1() {
    FILE *fp;
    Book *pHead = NULL, *pTemp = NULL, *pCur = NULL;

    if ((fp = fopen("book.txt", "r")) == NULL) {
        printf("\n文件打开失败！请检查文件名！\n");
        exit(0);
    }
    pTemp = (Book *) malloc(sizeof(Book));
    while (fread(pTemp, sizeof(Book), 1, fp)) {
        if (!pHead) {
            pHead = pCur = pTemp;
        } else {
            pCur->next = pTemp;
            pCur = pTemp;
        }
        pTemp = (Book *) malloc(sizeof(Book));
    }
    fclose(fp);
    return pHead;
}

int main() {
    Book *book = NULL;
    User *user = NULL;

    int iltem;
    ShowMainMenu();
    scanf("%d", &iltem);
    getchar();
    while (1) {
        switch (iltem) {
            case 0:
                return 0;
                break;
            case 1:
                ShowLiblnfo(book, user);
                break;
            case 2:
                ShowLibBook(book);
                break;
            case 3:
                AddBook(book);
                break;
            case 4:
                DealoldBook(book);
                break;
            case 5:
                foundBook(book);
                break;
            case 6:
                foundReader_Info(user);
                break;
            case 7:
                foundReaderInfo(user);
                break;
            case 8:
                LendBook(user, book);
                break;
            case 9:
                returnBook(user, book);
                break;
            case 10:
                save(book);
                break;
            case 11:
                read1();
                break;
            default:
                printf("\t输入有误，请重新输入!\n");
                Sleep(2000);
        }
        ShowMainMenu();/*调用ShowMainMenu函数绘制界面*/
        scanf("%d", &iltem);/*提示用户输入数字*/
        getchar();
    }
}