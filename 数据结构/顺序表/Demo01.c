#include "stdio.h"
#include "stdlib.h"

//抽象数据类型
typedef void *datatype;

//定义顺序表结构体
typedef struct Seqlist {
    int size;       //顺序表元素个数
    int capacity;   //顺序表容量
    datatype *data; //指向数组
} Seqlist;

//初始化
void initSeqlist(Seqlist *list) {
    list->size = 0;
    list->capacity = 8; //初始化容量为8
    list->data = calloc(list->capacity, sizeof(datatype));//申请数组
    if (!list->data) {
        printf("数组申请失败!");
        return;
    }
}

//添加数据
void push_back(Seqlist *list, datatype val) {
    //判断表满
    if (list->size == list->capacity) {
        printf("容量已满\n");
        return;
    }
    //插入
    list->data[list->size++] = val;
}

//打印
void print(int a) {
    printf("%d ", a);
}

//利用回调函数打印
void transFrom(Seqlist *list, void (*dosomething)(datatype)) {
    for (int i = 0; i < list->size; ++i) {
        dosomething(list->data[i]);
    }
}

//利用快捷遍历顺序表宏
#define foreach(val, plist) \
for(int i = 0,_cont = 0 ;i < (plist)->size;++i,_cont = 0) \
    for(val = (plist)->data[i];_cont<1;++_cont)

int main() {
    Seqlist list;
    initSeqlist(&list);
    //插入
    for (int i = 0; i < 5; ++i) {
        push_back(&list, i);
    }
    //打印
    printf("------------------------\n");
    transFrom(&list, print);
    printf("\n------------------------\n");
    foreach(int num, &list) {
            printf("%d ", num);
        }
    printf("\n------------------------\n");
    const char *name[] = {"青春不限好", "夏日123", "陌上花开", "123", "事在人为"};
    //定义一个顺序表
    Seqlist name_list;
    initSeqlist(&name_list);
    for (int i = 0; i < 5; ++i) {
        push_back(&name_list, name[i]);
    }

    //输出
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