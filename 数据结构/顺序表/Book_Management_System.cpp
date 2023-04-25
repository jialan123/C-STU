
#include<stdio.h>
#include <windows.h>
#include"Book_Management_System.h"


//��������ȫ�ֽṹ����������¼���е�ͼ����Ϣ�����еĶ�����Ϣ
Book astBook[BOOK_NUM];
Reader astReader[READER_NUM];

//��ʾ���˵�
void ShowMainMeun() {
    //��������
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t***********************************��ӭ����*******************************\n");
    printf("\t********************************ͼ��ݹ���ϵͳ****************************\n");
    printf("\t************************************���˵�********************************\n");
    printf("\t*********************************1.ͼ�����*******************************\n");
    printf("\t*********************************2.���߹���********************************\n");
    printf("\t*********************************3.�軹��Ǽ�******************************\n");
    printf("\t*********************************0.�˳�ϵͳ********************************\n");
    printf("\n");
    printf("\t\t��ѡ��(0-3)");
}

//��ʾ�鼮������Ӳ˵�
void ShowBookMenu() {
    system("cls");
    printf("\n\n\n\n");
    printf("\t|******************************��ӭ����***************************|\n");
    printf("\t|******************************ͼ��ݹ���ϵͳ********************|\n");
    printf("\t|*********************************�Ӳ˵�**************************|\n");
    printf("\t|******************************1.��ʾͼ����Ϣ*********************|\n");
    printf("\t|******************************2.����ͼ����Ϣ*********************|\n");
    printf("\t|******************************3.��ѯͼ����Ϣ*********************|\n");
    printf("\t|******************************4.ɾ��ͼ����Ϣ*********************|\n");
    printf("\t|******************************5.�޸�ͼ����Ϣ*********************|\n");
    printf("\t|******************************0.�������˵�***********************|\n");
    printf("\n");
    printf("\t\t��ѡ��(0-5):");
}

int ReadBookFile(const char *pcMode) {
    int iBookRecord = 0;
    FILE *pfBook; //�ļ�ָ��
    pfBook = fopen("book.txt", pcMode);
    if (pfBook == NULL) {
        return -1;
    }
    while (!feof(pfBook)) {
        if (fread(&astBook[iBookRecord], LEN_BOOK, 1, pfBook)) {
            iBookRecord++;
        }
    }
    fclose(pfBook);
    return iBookRecord;
}

void ShowBook() {
    int i, iBookRecord;  //��¼����
    system("cls");
    iBookRecord = ReadBookFile("rb");  //ֻ��
    if (iBookRecord == -1) {
        printf("���ļ���ʧ��,��������ͼ����Ϣ!\n");
    }
    if (iBookRecord == 0) {
        printf("�ļ���û��ͼ����Ϣ!\n");
    } else {
        printf("\t|**********************************************************************|\n");
        printf("\n\n");
        printf("\t%-6s%-16s%-10s%-20s%-4s\n", "���", "����", "����", "������", "���");
        for (i = 0; i < iBookRecord; i++) {
            printf("\t%-6d%-16s%-10s%-20s%-4d\n", BOOK_DATA);
        }
        printf("\n\n");
        printf("\t|**********************************************************************|\n");
        printf("\n\n");
    }
}

void AddBook() {
    FILE *pfBook;
    int iBookRecord, iFlagExist, i;
    char cFlag;
    system("cls");
    iBookRecord = ReadBookFile("ab+"); // ab+׷�ӷ�ʽ�򿪻����½��������ļ�
    if (iBookRecord == -1) {
        printf("�ļ���ʧ��!\n");
        return;
    } else if (iBookRecord == 0) {
        printf("û��ͼ���¼!\n");
    } else {
        ShowBook();//���ͼ���¼��Ϊ0����ʾ����ͼ��
    }
    //ѭ��¼��ͼ����Ϣ
    printf("��ѡ���Ƿ�������Ϣ(y/n):");
    cFlag = getchar();
    getchar();
    if (cFlag == 'n') {
        return;
    }
    pfBook = fopen("book.txt", "ab+");
    if (pfBook == NULL) {
        printf("�ļ���ʧ��!\n");
        return;
    }
    while (cFlag == 'y') {
        //¼������
        if (iBookRecord >= BOOK_NUM) {
            printf("��¼����!");
            fclose(pfBook);
            return;
        }
        //ͼ���Ų����ظ�
        printf("������ͼ����:  ");
        do {
            iFlagExist = 0;
            scanf("%d", &astBook[iBookRecord].iNum);
            getchar();
            for (i = 0; i < iBookRecord; i++) {
                if (astBook[i].iNum == astBook[iBookRecord].iNum) {
                    iFlagExist = 1;
                    printf("��ͼ�����Ѿ�����,����������:   ");
                    break;
                }
            }
        } while (iFlagExist == 1);

        printf("������ͼ������:");
        scanf("%s", astBook[iBookRecord].acName);
        getchar();

        printf("������ͼ������:");
        scanf("%s", astBook[iBookRecord].acAuthor);
        getchar();

        printf("������ͼ�������:");
        scanf("%s", astBook[iBookRecord].acPress);
        getchar();

        printf("������ͼ������:");
        scanf("%d", &astBook[iBookRecord].iAmount);
        getchar();

        //��������ͼ����Ϣд�뵽�ļ���
        if (fwrite(&astBook[iBookRecord], LEN_BOOK, 1, pfBook) != 1) {
            printf("�޷��������Ϣ!\n");
            return;
        } else {
            printf("%d��ͼ����Ϣ�Ѿ�����!\n", astBook[iBookRecord].iNum);
            iBookRecord++;
        }
        printf("����������Ϣ��?(y/n)");
        cFlag = getchar();
        getchar();
    }
    fclose(pfBook);
    printf("���ͼ����Ϣִ�����!\n");
}

//��ѯ    ͨ��ͼ���Ų���
int SearchBook() {
    int iBookNum, iBookRecord, iBookId, i;
    system("cls");
    iBookRecord = ReadBookFile("rb");
    if (iBookRecord == -1) {
        printf("�ļ���ʧ��");
        printf("������������Ӳ˵�");
        _getch();
        return -2;  //�ļ���ʧ�ܷ���-2
    } else if (iBookRecord == 0) {
        printf("û��ͼ���¼!\n");
        printf("|������������Ӳ˵�|");
        _getch();
        return -3;//û�м�¼,����-3
    }

    //������ҳ���
    printf("������ͼ���ţ�");
    scanf("%d", &iBookNum);
    getchar();

    for (i = 0; i < iBookRecord; i++) {
        if (iBookNum == astBook[i].iNum) {
            iBookId = i;  //�ҵ���¼�����ؼ�¼���
            printf("%d��ͼ����Ϣ���£�\n", iBookNum);
            printf("\t------------------------------\n");
            printf("\t %-6s%-16s%-10s%-20s%-4s%\n", "ͼ����", "����", "����", "������", "�����");
            printf("\t  %-6d%-16s%-10s%-20s%-4d\n", BOOK_DATA);
            printf("\t-----------------------------------------------------------\n");
            break;
        }
    }

    if (i == iBookRecord) {
        printf("�Ҳ���%d��ͼ����Ϣ!\n,", iBookNum);
        iBookId = -1;//�Ҳ�����¼,����-1;
    }

    return iBookId;
}

void DeleteBook() {
    FILE *pfBook;
    int iBookId, iBookRecord, i;
    char cFlag;

    system("cls");
    iBookId = SearchBook();
    if (iBookId == -1) {
        return;
    }
    iBookRecord = ReadBookFile("rb");
    printf("�Ѿ��ҵ���ͼ�飬�Ƿ�ɾ������y/n)");
    cFlag = getchar();
    getchar();

    //ɾ��֮ǰ����ɾ��֮ǰ��ͼ���ţ���Ϊɾ��֮��ͼ������Ϣ�ᱻ����
    int index = astBook[iBookId].iNum;
    if (cFlag == 'n') {
        return;
    } else if (cFlag == 'y') {
        for (i = iBookId; i < iBookRecord - 1; i++) {
            astBook[i] = astBook[i + 1];//��������ǰ��
        }
        iBookRecord--;
    }

    pfBook = fopen("book.txt", "wb");
    if (pfBook != NULL) {
        for (int i = 0; i < iBookRecord; i++) {
            if (fwrite(&astBook[i], LEN_BOOK, 1, pfBook) != 1) {
                printf("�޷��������Ϣ��\n");
                return;

            }
        }
        fclose(pfBook);
        printf("%d��ͼ����Ϣ�Ѿ�ɾ����\n", index);
    }
}

//��ʾ�޸�ѡ����Ӳ˵�
void ShowModifyBookMenu() {
    printf("\n\n\n");
    printf("\t                             1.���                                                \n");
    printf("\t                             2.����                                                \n");
    printf("\t                             3.����                                                \n");
    printf("\t                             4.������                                              \n");
    printf("\t                             5.ͼ������                                          \n");
    printf("\t       ��������Ҫ�޸ĵ���Ϣ(������Ӧ������1-5):");
}

void SaveBookFile(int iBookId) {
    FILE *pfBook;
    pfBook = fopen("book.txt", "rb+");
    if (pfBook != NULL) {
        fseek(pfBook, LEN_BOOK * iBookId, SEEK_SET);
        if (fwrite(&astBook[iBookId], LEN_BOOK, 1, pfBook) != 1) {
            printf("�޷��������Ϣ��\n");
        }
    }
    fclose(pfBook);
}

void ModifyBook()  //�޸�ͼ����Ϣ
{
    int iBookId, iBookRecord, iFlagExist, iltem, iNum, i;

    system("cls");
    iBookId = SearchBook();
    if (iBookId == -1) {
        return;
    }
    if (iBookId == -3) {
        return;
    }
    //�ҵ�����ŵ�ͼ�飬���Խ����޸ĵĲ�����
    iBookRecord = ReadBookFile("rb");
    //��ʾ�޸�ѡ����Ӳ˵�
    ShowModifyBookMenu();
    scanf("%d", &iltem);
    getchar();
    switch (iltem) {
        case 1:
            printf("������ͼ����:");
            do {
                iFlagExist = 0;
                scanf("%d", &iNum);
                getchar();
                for (i = 0; i < iBookRecord; i++) {
                    if (iNum == astBook[i].iNum && i != iBookId) {
                        iFlagExist = 1;
                        printf("���󣬸�ͼ�����Ѿ����ڣ����������룺");
                        break;
                    }
                }
            } while (iFlagExist == 1);
            astBook[iBookId].iNum = iNum;
            break;
        case 2:
            printf("������ͼ������:");
            scanf("%s", astBook[iBookId].acName);
            getchar();
            break;
        case 3:
            printf("������ͼ������:");
            scanf("%s", astBook[iBookId].acAuthor);
            getchar();
            break;
        case 4:
            printf("������ͼ�������:");
            scanf("%s", astBook[iBookId].acPress);
            getchar();
            break;
        case 5:
            printf("������ͼ������:");
            scanf("%d", &astBook[iBookId].iAmount);
            getchar();
            break;
    }
    SaveBookFile(iBookId);
    printf("ͼ����Ϣ�޸ĳɹ�!\n");
}

int iltem;

void MangaeBook() //�鼮����
{

    ShowBookMenu();//��ʾ���ݹ�����Ӳ˵�
    scanf("%d", &iltem);
    getchar();
    while (iltem) {
        switch (iltem) {
            case 1:
                ShowBook();//��ʾͼ����Ϣ
                break;
            case 2:
                AddBook();//����ͼ����Ϣ
                break;
            case 3:
                SearchBook();//����ͼ����Ϣ
                break;
            case 4:
                DeleteBook();//ɾ��ͼ����Ϣ
                break;
            case 5:
                ModifyBook();//�޸�ͼ����Ϣ
                break;
            default:
                printf("\t\t��������ȷ�����֣�\n\t\t");

        }
        printf("\t|�밴����������Ӳ˵�|");
        _getch();//�ӿؼ���ȡ�ַ����������;
        ShowBookMenu();
        scanf("%d", &iltem);
        getchar();
    }
}

void ShowReaderMenu()//��ʾ���߹�����Ӳ˵�
{
    system("cls");
    printf("\n\n\n\n");//Ų�������м�
    printf("\n\n\n\n\n");//Ŀ���ǽ������м�һ��
    printf("\t|****************��ӭ����****************|\n");
    printf("\t|*************���߹���ϵͳ***************|\n");
    printf("\t|*****************�Ӳ˵�*****************|\n");
    printf("\t|**************1.��ʾ������Ϣ************|\n");
    printf("\t|**************2.����������Ϣ************|\n");
    printf("\t|**************3.��ѯ������Ϣ************|\n");
    printf("\t|**************4.ɾ��������Ϣ************|\n");
    printf("\t|**************5.�޸Ķ�����Ϣ************|\n");
    printf("\t|**************0.�������˵�**************|\n");
    printf("\t|****************************************|\n");
    printf("\n");
    printf("\t\t��ѡ��(0-5):");
}

int ReadReaderFile(const char *fopenMode) {
    int iReaderRecord = 0;
    FILE *pfReader;
    pfReader = fopen("reader.txt", fopenMode);
    if (pfReader == NULL) {
        return -1;
    }
    while (!feof(pfReader)) {
        if (fread(&astReader[iReaderRecord], LEN_READER, 1, pfReader)) {
            iReaderRecord++;
        }
    }
    fclose(pfReader);
    return iReaderRecord;
}

void ShowReader() //��ʾ������Ϣ
{
    int i, iReaderRecord;
    system("cls");
    iReaderRecord = ReadReaderFile("rb");
    if (iReaderRecord == -1) {
        printf("���ļ���ʧ�ܣ����������Ӷ�����Ϣ!\n");
    } else {
        printf("\t|**********************************************************|\n");
        printf("\n\n");
        printf("\t%-6s%-16s%-10s%-20s%-20s\n", "���", "����", "�Ա�", "���ɽ�������", "��ǰ�ɽ�������");
        for (i = 0; i < iReaderRecord; i++) {
            printf("\t%-6d%-16s%-10s%-20d%-20d\n", READER_DATA);
            //�˴��Ӻ궨��,�������̫��,�Ӻ���Լ��ٴ�����
        }
        printf("\n\n");
        printf("\t|******************************************************|\n");
        printf("\n\n");

    }
}

void AddReader()//����������Ϣ
{
    FILE *pfReader;//�ļ�ָ��
    int iReaderRecord, iFlagExist, i;
    char cFlag;

    system("cls");
    iReaderRecord = ReadReaderFile("ab+");  //ab+׷�ӷ�ʽ�򿪻����½��������ļ�
    if (iReaderRecord == -1) {
        printf("�ļ���ʧ�ܣ�\n");
    } else if (iReaderRecord == 0) {
        printf("û�ж��߼�¼");

    } else {
        ShowReader();//������߼�¼��Ϊ0�����ShowReader��ʾ���ж�����Ϣ
    }

    //ѭ��¼�������Ϣ
    printf("��ѡ���Ƿ����������Ϣ (y/n):");
    cFlag = getchar();
    getchar();
    if (cFlag == 'n') {
        return;

    }

    pfReader = fopen("reader.txt", "ab+");
    if (pfReader == NULL) {
        printf("�ļ���ʧ�ܣ�\n");
        return;
    }
    while (cFlag == 'y') {
        if (iReaderRecord >= READER_NUM)  //������������Χ���ܼ���д��
        {
            printf("��¼����");
            fclose(pfReader);
            return;
        }
        printf("��������߱��:");
        do {
            iFlagExist = 0;
            scanf("%d", &astReader[iReaderRecord].iNum);
            getchar();
            for (i = 0; i < iReaderRecord; i++) {
                if (astReader[i].iNum == astReader[iReaderRecord].iNum) {
                    iFlagExist = 1;
                    printf("�ö��߱���Ѿ����ڣ�����������:");
                    break;
                }

            }
        } while (iFlagExist == 1);

        //�������߻�����Ϣ
        printf("�������������:");
        scanf("%s", astReader[iReaderRecord].acName);
        getchar();

        printf("����������Ա�");
        scanf("%s", astReader[iReaderRecord].acSex);
        getchar();

        printf("������������ɽ�����:"); //10 ��Χ
        scanf("%d", &astReader[iReaderRecord].iMax);
        getchar();

        printf("��������ߵ�ǰ�ɽ�����:"); //
        //�����ѽ������� = iMax - iAmount
        scanf("%d", &astReader[iReaderRecord].iAmount);
        getchar();

        //�������Ķ�����Ϣд�뵽�ļ���
        if (fwrite(&astReader[iReaderRecord], LEN_READER, 1, pfReader) != 1) {
            printf("�޷��������Ϣ��\n");
            return;
        } else {
            printf("%d�Ŷ�����Ϣ�Ѿ����棡\n", astReader[iReaderRecord].iNum);
            iReaderRecord++;
        }
        printf("�������������Ϣ��?(y/n)");
        cFlag = getchar();
        getchar();
    }
    fclose(pfReader);
    printf("��Ӷ�����Ϣִ����ϣ�\n");
}

int SearchReader() {
    int iReaderNum, iReaderRecord, iReaderId, i;
    system("cls");
    iReaderRecord = ReadReaderFile("rb");  //��"rb����ʽ���ļ������ʧ���򷵻�
    if (iReaderRecord == -1) {
        printf("�ļ���ʧ��!\n");
        printf("|������������Ӳ˵�|");
        _getch();  //....
        return -2;  //�ļ���ʧ�ܣ�����-2
    } else if (iReaderRecord == 0) {
        printf("û�ж��߼�¼!\n");
        printf("|������������Ӳ˵�|");
        _getch();
        return -3; //û�м�¼����-3
    }

    //����Ϊ���ҳ���
    printf("��������߱��:");
    scanf("%d", &iReaderNum);
    getchar();
    for (i = 0; i < iReaderRecord; i++) {
        if (iReaderNum == astReader[i].iNum) {
            iReaderId = i;//�ҵ���¼�����ؼ�¼��
            printf("\t|---------------------------------------------\n");
            printf("\t %-6s%-16s%-10s%-20s%-20s\n", "���", "����", "�Ա�", "���ɽ�����", "��ǰ�ɽ�������");
            printf("\t  %-6d%-16s%-10s%-20d%-20d\n", READER_DATA);
            printf("\t|--------------------------------------------\n");
            break;
        }
    }
    if (i == iReaderRecord) {
        printf("�Ҳ���%d�Ŷ�����Ϣ!\n", iReaderNum);
        iReaderId = -1;//�Ҳ�����¼,����-1;
    }
    return iReaderId;
}

void DeleteReader()//ɾ��������Ϣ
{
    FILE *pfReader; //�ļ�ָ��
    int iReaderId, iReaderRecord, i;
    char cFlag;

    system("cls");
    iReaderId = SearchReader();
    if (iReaderId == -1) {
        printf("û���ҵ��ö��ߣ���������ȷ�Ķ��߱�š�");
        return;

    }
    iReaderRecord = ReadReaderFile("rb");
    printf("�Ѿ��ҵ��ö��ߣ��Ƿ�ɾ����(y/n��");
    cFlag = getchar();
    getchar();

    int index = astReader[iReaderId].iNum;  //index����ɾ��֮ǰ�Ķ��߱��,��Ϊɾ��
    //֮���µĶ��߱�žͻḲ�ǵ�ԭ���Ķ��߱��
    if (cFlag == 'n') {
        return;
    } else if (cFlag == 'y') {
        for (i = iReaderId; i < iReaderRecord - 1; i++) // -1
        {
            astReader[i] = astReader[i + 1];

        }
        iReaderRecord--;
    }

    pfReader = fopen("reader.txt", "wb");
    if (pfReader != NULL) {
        for (i = 0; i < iReaderRecord; i++) {
            if (fwrite(&astReader[i], LEN_READER, 1, pfReader) != 1) {
                printf("�޷��������Ϣ!\n");
                return;
            }
        }
        fclose(pfReader);
        printf("%d�Ŷ�����Ϣ��ɾ��!\n", index);
    }
}

void ShowModifyReaderMenu() //��ʾ�޸ĵ�ѡ��
{
    printf("\n");
    printf("\t                    1.���                                   \n");
    printf("\t                    2.����                                   \n");
    printf("\t                    3.�Ա�                                   \n");
    printf("\t                    4.���ɽ�������                  \n");
    printf("��������Ҫ�޸ĵ���Ϣ(������Ӧ������:1-4):");
}

void SaveReaderFile(int iReaderId) {
    FILE *pfReader;
    pfReader = fopen("reader.txt", "rb+");
    if (pfReader != NULL) {
        fseek(pfReader, LEN_READER * iReaderId, SEEK_SET);
        if (fwrite(&astReader[iReaderId], LEN_READER, 1, pfReader) != 1) {
            printf("�޷��������Ϣ��\n");

        }
        fclose(pfReader);
    }
}

void ModifyReader() //�޸Ķ�����Ϣ
{
    int iReaderId, iReaderRecord, iBorrow, iltem, iNum, iMax, iFlagExist, i;
    system("cls");
    iReaderId = SearchReader();
    if (iReaderId == -1) {
        return;
    }
    //�ҵ�����ŵĶ��ߣ����Խ����޸�
    iReaderRecord = ReadReaderFile("rb");
    ShowModifyReaderMenu();//��ʾ�޸�ѡ��
    scanf("%d", &iltem);
    getchar();

    switch (iltem) {
        case 1:
            printf("��������߱��");
            do {
                iFlagExist = 0;
                scanf("%d", &iNum);
                getchar();
                for (i = 0; i < iReaderRecord; i++) {
                    if (iNum == astReader[i].iNum && i != iReaderId) {
                        iFlagExist = 1;
                        printf("���󣬸ö��߱���Ѿ����ڣ�����������:");
                    }
                }
            } while (iFlagExist == -1);
            astReader[iReaderId].iNum = iNum;
            break;
        case 2:
            printf("�������������");
            scanf("%s", &astReader[iReaderId].acName);
            getchar();
            break;
        case 3:
            printf("����������Ա�:F/M:");
            while (scanf("%s", astReader[iReaderId].acSex) > 0) {
                getchar();
                if (strcmp(astReader[iReaderId].acSex, "F") == 0 || strcmp(astReader[iReaderId].acSex, "M") == 0) {
                    break;
                }
                printf("����ֻ������'F'����'M'������������\n");
            }

            break;
        case 4:
            //iBorrow���Ѿ����ĵ�����
            iBorrow = astReader[iReaderId].iMax - astReader[iReaderId].iAmount;
            printf("������������ɽ�������(��ΧΪ5-10):\n");
            while (scanf("%d", &iMax) == 1) {
                getchar();
                if (iMax >= 5 && iMax <= 10) {
                    if (iBorrow > iMax) //  Ϊʲôû�е���
                    {
                        printf("�ö���Ŀǰͼ������������ڸ���������Ҫ�Ȼ���!\n");
                        return;
                    } else {
                        astReader[iReaderId].iMax = iMax;
                        astReader[iReaderId].iAmount = iMax - iBorrow;
                        for (i = iBorrow; i < iMax; i++) {
                            astReader[iReaderId].BookId[i] = 0;  //?
                        }
                        break;
                    }
                }
                printf("���󣬶������ɽ��ĵ��鷶ΧΪ5-10������������\n");

            }
            break;

    }
    SaveReaderFile(iReaderId);
    printf("�ö�����Ϣ�Ѿ��޸ĳɹ�!\n");
}

void MangaeReader()//���߹���ģ��
{
    int rselect;
    ShowReaderMenu();//��ʾ���߹�����Ӳ˵�
    scanf("%d", &rselect);
    getchar();

    while (rselect) {
        switch (rselect) {
            case 1:
                ShowReader();//��ʾ������Ϣ;
                break;
            case 2:
                AddReader();//����������Ϣ;
                break;
            case 3:
                SearchReader();//���Ҷ�����Ϣ;
                break;
            case 4:
                DeleteReader();//ɾ��������Ϣ;
                break;
            case 5:
                ModifyReader();//�޸Ķ�����Ϣ;
                break;
            defalut:
                printf("\t\t ��������ȷ������!\n\t\t");
        }
        printf("|������������Ӳ˵�|");
        _getch();
        ShowReaderMenu();
        scanf("%d", &rselect);
        getchar();
    }
}

void ShowBorrowReturnMenu() {
    system("cls");
    printf("\n\n\n\n");
    printf("\t|****************��ӭ����****************|\n");
    printf("\t|***************�軹��Ǽ�***************|\n");
    printf("\t|*****************�Ӳ˵�*****************|\n");
    printf("\t|***************1.����Ǽ�***************|\n");
    printf("\t|***************2.����Ǽ�***************|\n");
    printf("\t|**************0.�������˵�**************|\n");
    printf("\t|****************************************|\n");
    printf("\n");
    printf("\t\t��ѡ��(0-2):");

}

void BorrowBook()//����
{
    //�����Ƿ���Խ��飿  �治����
    system("cls");
    int iBookId, iReaderId, iBorrow, i;
    //����Ҫ����Ķ��ߵı�ţ��жϱ���Ƿ���ڣ�����ڣ���ʾ�����Ѿ����ĵ�ͼ����Ϣ
    iReaderId = SearchReader();
    if (iReaderId == -1) {
        return;
    }
    iBorrow = astReader[iReaderId].iMax - astReader[iReaderId].iAmount;
    if (iBorrow == 0) {
        printf("�ö���Ŀǰû�н����κ���.");
    } else {
        printf("\t�ö��ߵ�ǰ����ͼ��Ϊ��");
        for (i = 0; i < iBorrow; i++) {
            printf("%d", astReader[iReaderId].BookId[i]);

        }
        if (astReader[iReaderId].iAmount == 0) {
            printf("�ö��߿ɽ�ͼ������Ϊ0�����ܼ������飡\n");
        }

    }
    //ͼ���Ƿ���Խ��ģ�  ����Ƿ���
    printf("�����������Ҫ���ĵ�ͼ����Ϣ\n");
    _getch();
    iBookId = SearchBook();
    if (iBookId == -1) {
        return;
    }
    if (astBook[iBookId].iAmount == 0) {
        printf("���Ϊ�㣬���ɽ���\n");
        return;
    }
    //����
    astReader[iReaderId].BookId[iBorrow] = astBook[iBookId].iNum;
    //ͼ�������1
    astBook[iBookId].iAmount--;
    //��ǰ���߿ɽ�����������1
    astReader[iReaderId].iAmount--;
    SaveBookFile(iBookId);
    SaveReaderFile(iReaderId);
    printf("����ɹ�\n");
}

void ReturnBook()//����
{
    system("cls");
    int iBookId, iReaderId, iBorrow, i;
    //�����Ƿ����
    iReaderId = SearchReader();
    if (iReaderId == -1) {
        return;
    }
    iBorrow = astReader[iReaderId].iMax - astReader[iReaderId].iAmount;
    if (iBorrow == 0) {
        printf("\t�ö���û�н����κ���������黹��\n");
        return;
    } else {
        printf("\t�ö��ߵ�ǰ����ͼ��Ϊ��");
        for (i = 0; i < iBorrow; i++) {
            printf("%d", astReader[iReaderId].BookId[i]);

        }
    }
    printf("�����������Ҫ�黹��ͼ����Ϣ\n");
    _getch();
    //ͼ���ڲ���
    iBookId = SearchBook();
    if (iBookId == -1) {
        return;
    }

    //�����б������Ƿ����Ȿ��
    for (i = 0; i < iBorrow; i++) {
        if (astReader[iReaderId].BookId[i] == astBook[iBookId].iNum) {
            //����
            for (int j = i; i < iBorrow - 1; j++)   //����ǰ��
            {
                astReader[iReaderId].BookId[j] = astReader[iReaderId].BookId[j + 1];
            }
            astReader[iReaderId].BookId[iBorrow - 1] = 0;
            //ͼ�����1
            astBook[iBookId].iAmount++;
            //��ǰ���߿ɽ���������1
            astReader[iReaderId].iAmount++;

            break;
        }
    }
    if (i == iBorrow) {
        printf("�ö���û�н����Ȿ�飬����黹��\n");
    }
    SaveBookFile(iBookId);
    SaveReaderFile(iReaderId);
    printf("����ɹ�\n");
}

void BorrowReturnManger()//�軹��ģ��
{
    ShowBorrowReturnMenu();//�軹����Ӳ˵�
    int iltem;
    scanf("%d", &iltem);
    getchar();
    while (iltem) {
        switch (iltem) {
            case 1:
                BorrowBook();//����
            case 2:
                ReturnBook();//����
            default:
                printf("��������ȷ�����֣�\n");
        }
        printf("������������Ӳ˵�");
        _getch();
        ShowBorrowReturnMenu();
        scanf("%d", &iltem);
        getchar();
    }
}

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