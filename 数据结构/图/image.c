//
// Created by Administrator on 2023/5/6.
//
#include "image.h"

int main() {

    MGragh v;
    print_array(&v);
    int str;
    printf("\n������ʼ�㣺");
    scanf("%d", &str);
    DFSTraverse(&v, str);
}