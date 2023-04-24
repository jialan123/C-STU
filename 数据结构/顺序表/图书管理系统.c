#include "stdio.h"
#include "conio.h"      //gtech()����ʹ��ͷ�ļ�
#include "windows.h"    //Sleep()ʹ�õ�ͷ�ļ�
#include "string.h"     //strcmp()ʹ�õ�ͷ�ļ�
#include "assert.h"

//�����û��ṹ��:���߱�ţ������������Ա𣬿ɽ������������ѽ���ı��
typedef struct User {
    int iNum;
    char acName[15];
    char acSex[4];
    char position[20];
    int iMax;   //student20����teacher40��
    int iAmount;
    int aiBookld[100];
    int balance;
    int day;
    struct User *next;
} User;

//�����鱾�ṹ�壺ͼ���ţ�ͼ������ͼ�����ߣ������磬�����
typedef struct Book {
    int iNum;           //��ı��
    char acName[15];    //�������
    char acAuthor[15];  //�������
    char acPress[15];   //��ĳ�����
    int iAmount;        //��Ŀ����
    struct Book *next;
} Book;


//�˵�
void ShowMainMenu() {
    system("cls");//��������
    printf("\n\n\n");
    printf("\t|--------------��ԭ����ͼ�����ϵͳ--------------|\n");
    printf("\t|         ���߹���ϵͳ            \n");
    printf("\t|         1.��ѯͼ��ݵ�����Ϣ            \n");
    printf("\t|         2.��ѯͼ��ݲ�����Ϣ            \n");
    printf("\t|         3.��������            \n");
    printf("\t|         4.������Ϣ            \n");
    printf("\t|         5.�������������鿯��Ϣ            \n");
    printf("\t|         6.��ѯ���߽�����Ϣ            \n");
    printf("\t|         7.��ѯ������Ϣ            \n");
    printf("\t|         8.���߽���            \n");
    printf("\t|         9.���߻���            \n");
    printf("\t|         10.�ļ�����            \n");
    printf("\t|         11.���ļ���ȡ            \n");
    printf("\t|         0.�˳�           \n");
    printf("\t|-----------------------------------------------|");
    printf("\n�´򿪳���������ӳ���Ա\n");
    printf("\n");
    printf("\t\t��ѡ��0-11����");
}

//��������
Book *AddBook(Book *book1) {
    Book *book = book1;

    if (book == NULL) {
        Book *tmp = (Book *) malloc(sizeof(Book));
        tmp->next = NULL;
        assert(tmp);
        printf("������ı�ţ�");
        scanf("%d", &tmp->iNum);
        getchar();
        printf("����������ƣ�");
        gets(&tmp->acName);
        printf("����������ߣ�");
        gets(&tmp->acAuthor);
        printf("������ĳ����磺");
        gets(&tmp->acPress);
        printf("������Ŀ������");
        scanf("%d", &tmp->iAmount);
        book = tmp;

        printf("\n�����������\n");
        getchar();
        return book;
    }
}

//ͼ��ݵ�����Ϣ
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
    printf("��ͼ��ݹ���%d��������%d��\n", bookNUm, readerNUm);
    printf("�����������\n");
    getchar();
    return;
}

//ͼ��ݲ�����Ϣ
void ShowLibBook(Book *book1) {
    Book *book = book1;
    while (book != NULL) {
        printf("%d\t%s\t%s\t%s\t%d\n", book->iNum, book->acName, book->acAuthor, book->acPress, book->iAmount);
        book = book->next;
    }
    printf("\n�����������\n");
    getchar();
    return;
}

//���鴦��
Book *DealoldBook(Book *book1) {
    Book *book = book1;
    Book *prev = book1;
    printf("����Ҫ��������ţ�");
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
            printf("�ѽ����鴦���!\n");
            printf("�����������");
            getchar();
            return book1;
        }
    }
}

//�������������鿯��Ϣ
void foundBook(Book *book1) {
    Book *book = book1;
    printf("������Ҫ������id:");
    int id;
    scanf("%d", &id);
    while (book != NULL) {
        if (id == book->iNum) {
            printf("�������ϵ���£�\n");
            printf("%d\t%s\t%s\t%s\t%d\n", book->iNum, book->acName, book->acAuthor, book->acPress, book->iAmount);
            printf("�����������");
            getchar();
            return;
        }
        book = book->next;
    }
    printf("û���ҵ����飡\n");
    printf("�����������");
    getchar();
    return;
}

//��ѯ���߽�����Ϣ
void foundReader_Info(User *read1) {
    User *reader = read1;
    printf("������ߺţ�");
    int id;
    scanf("%d", &id);
    getchar();
    while (reader) {
        if (id == reader->iNum) {
            printf("���ĵ���ı�����£�\n");
            for (int i = 0; i < reader->iMax; i++) {
                if (reader->aiBookld[i] != 0) {
                    printf("%d\n", reader->aiBookld[i]);
                }
            }
            printf("�����������");
            getchar();
            return;
        }
        reader = reader->next;
    }
    printf("û�иö���");
    printf("�����������");
    getchar();
    return;
}

//��ѯ������Ϣ
void foundReaderInfo(User *reader1) {
    User *reader = reader1;
    printf("�������id:");
    int id;
    scanf("%d", id);
    getchar();
    while (reader) {
        if (id == reader->iNum) {
            printf("����id��%d\n", reader->iNum);
            printf("����������%s\n", reader->acName);
            printf("�����Ա�%s\n", reader->acSex);
            printf("����ְλ��%s\n", reader->position);
            printf("�����Ѿ������������Ϊ��%d\n", reader->iAmount);
            printf("�����������");
            getchar();
            return;
        }
        reader = reader->next;
    }
    printf("û���ҵ��ö��ߣ�\n");
    printf("�����������");
    getchar();
    return;
}

//���߽���#############
User *LendBook(User *reader1, Book *book1) {
    User *reader = reader1;
    Book *book = book1;

    User *prev = reader1;
    User *tmpp = reader1;

    printf("�������id��");
    int id;
    scanf("%d", &id);
    getchar();

    if (reader == NULL) {
        User *tmp = (User *) malloc(sizeof(User));
        tmp->next = NULL;
        tmp->iAmount = 0;
        tmp->iNum = id;

        printf("�������������");
        scanf("%s", &tmp->acName);
        getchar();

        printf("��������Ա�");
        scanf("%s", &tmp->acSex);
        getchar();

        printf("�������ְλ��<student\tor\tteacher>");
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
        printf("����Ҫ�����ı�ţ�");
        int id_book;
        scanf("%d", &id_book);
        getchar();
        while (book != NULL) {
            if (id_book == book->iNum) {
                if (book->iAmount <= 1) {
                    printf("����ʧ�ܣ���ͼ��ⲻ��\n");
                    printf("�����������");
                    getchar();
                    return NULL;
                }
                if ((tmp->iAmount) + 1 > tmp->iMax) {
                    printf("����ʧ�ܣ��ö��߽��������Ѵ�����\n");
                    printf("�����������");
                    getchar();
                    return NULL;
                }
                book->iAmount--;
                tmp->aiBookld[tmp->iAmount] = id_book;
                tmp->iAmount;
                reader = tmp;
                printf("���ĳɹ�!\n");
                printf("�����������");
                getchar();
                return reader1;
            }
            book = book->next;
        }
        printf("û���ҵ����飡\n");
        printf("�����������\n");
        if (reader != NULL) {
            while (reader != NULL) {
                if (id == reader->iNum) {
                    printf("ͼ��ݵ�ǰ���鼮�⣺\n");
                    ShowLibBook(book);
                    printf("����Ҫ�����ı�ţ�");
                    int id_book;
                    scanf("%d", &id_book);
                    getchar();
                    while (book != NULL) {
                        if (id_book == book->iNum) {
                            printf("����ʧ�ܣ�����ͼ��ݿ�治��\n");
                            printf("�����������");
                            getchar();
                            return reader1;
                        }
                        if (tmpp->iAmount + 1 > tmpp->iMax) {
                            printf("����ʧ�ܣ��ö��߽���ͼ�������Ѵ�����\n");
                            printf("�����������");
                            getchar();
                            return reader1;
                        }
                        reader->iAmount++;
                        reader->aiBookld[tmpp->iAmount] = id_book;
                        return reader1;
                    }
                    book = book->next;
                }
                printf("û���ҵ����飡\n");
                printf("�����������\n");
            }
            reader = reader->next;
        }
    }
}

//���߻���
User *returnBook(User *reader1, Book *book1) {
    User *reader = reader1;
    Book *book = book1;
    printf("������ߺţ�");
    int id;
    scanf("%d", &id);
    getchar();

    if (reader != NULL) {
        while (reader != NULL) {
            printf("����Ҫ������ı�ţ�");
            int id_book;
            scanf("%d", &id_book);
            getchar();
            for (int i = 0; i < reader->iMax; ++i) {
                if (reader->aiBookld[i] == id_book) {
                    reader->aiBookld[i] = 0;
                    while (book) {
                        if (id_book == book->iNum) {
                            book->iAmount++;
                            printf("����ɹ���\n");
                            printf("����������أ�\n");
                            getchar();
                            return reader1;
                        }
                        book = book1->next;
                    }
                }
            }
            printf("û���ҵ����飬���ͼ���id\n");
            printf("����������أ�\n");
            getchar();
            return reader1;

        }
        reader = reader->next;
    }
    printf("û���ҵ��ö��ߣ������ߵ�id�Ƿ���ȷ��\n");
    printf("����������أ�\n");
    getchar();
    return reader1;
}

//�ļ�����
void save(Book *book1) {
    FILE *fp;
    Book *pCur = book1;
    int iCount = 0;

    if (pCur == NULL) {
        printf("\nû��ѧ����¼��\n");
        return;
    }
    if ((fp = fopen("book.txt", "wb")) == NULL) {
        printf("�����ļ�ʧ�ܣ�\n");
        getchar();
        exit(1);
    }
    while (pCur) {
        fwrite(pCur, sizeof(Book), 1, fp);
        pCur = pCur->next;
        iCount++;
    }
    printf("\n");

    printf("�����ļ���������Ŀ��%d\n", iCount);
    fclose(fp);
}

//���ļ���ȡ
Book *read1() {
    FILE *fp;
    Book *pHead = NULL, *pTemp = NULL, *pCur = NULL;

    if ((fp = fopen("book.txt", "r")) == NULL) {
        printf("\n�ļ���ʧ�ܣ������ļ�����\n");
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
                printf("\t������������������!\n");
                Sleep(2000);
        }
        ShowMainMenu();/*����ShowMainMenu�������ƽ���*/
        scanf("%d", &iltem);/*��ʾ�û���������*/
        getchar();
    }
}