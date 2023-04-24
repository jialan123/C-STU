#include "stdio.h"
#include "stdlib.h"

//������������
typedef void *datatype;

//����˳���ṹ��
typedef struct Seqlist {
    int size;       //˳���Ԫ�ظ���
    int capacity;   //˳�������
    datatype *data; //ָ������
} Seqlist;

//��ʼ��
void initSeqlist(Seqlist *list) {
    list->size = 0;
    list->capacity = 8; //��ʼ������Ϊ8
    list->data = calloc(list->capacity, sizeof(datatype));//��������
    if (!list->data) {
        printf("��������ʧ��!");
        return;
    }
}

//�������
void push_back(Seqlist *list, datatype val) {
    //�жϱ���
    if (list->size == list->capacity) {
        printf("��������\n");
        return;
    }
    //����
    list->data[list->size++] = val;
}

//��ӡ
void print(int a) {
    printf("%d ", a);
}

//���ûص�������ӡ
void transFrom(Seqlist *list, void (*dosomething)(datatype)) {
    for (int i = 0; i < list->size; ++i) {
        dosomething(list->data[i]);
    }
}

//���ÿ�ݱ���˳����
#define foreach(val, plist) \
for(int i = 0,_cont = 0 ;i < (plist)->size;++i,_cont = 0) \
    for(val = (plist)->data[i];_cont<1;++_cont)

int main() {
    Seqlist list;
    initSeqlist(&list);
    //����
    for (int i = 0; i < 5; ++i) {
        push_back(&list, i);
    }
    //��ӡ
    printf("------------------------\n");
    transFrom(&list, print);
    printf("\n------------------------\n");
    foreach(int num, &list) {
            printf("%d ", num);
        }
    printf("\n------------------------\n");
    const char *name[] = {"�ഺ���޺�", "����123", "İ�ϻ���", "123", "������Ϊ"};
    //����һ��˳���
    Seqlist name_list;
    initSeqlist(&name_list);
    for (int i = 0; i < 5; ++i) {
        push_back(&name_list, name[i]);
    }

    //���
    transFrom(&name_list, puts);
    printf("\n------------------------\n");
    foreach(const char *str, &name_list) {
            printf("%s ", str);
        }
    printf("\n------------------------\n");


    return 0;
}

int main2() {

}