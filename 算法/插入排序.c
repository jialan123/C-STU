#include<stdio.h>
#include<stdlib.h>

void InsertSort(int* a,int n){//插入排序
    int i;
    for(i = 0;i < n - 1; i++){
        int end = i;
        //单趟排序：由后往前插入，插入后调整让其依旧有序
        int temp = a[end+1];
        while(end>=0)
        {
            if(temp<a[end])
            {
                a[end+1] = a[end];
                end--;
            }
            else
                break;
        }
        temp = a[end + 1];
    }
}

void PrintSort(int* a,int n){//打印数组
    int i;
    for(i = 0;i < n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void TestInsertSort()
{
    int a[] = {9,5,12,14,15};
    InsertSort(a,sizeof(a)/sizeof(a[0]));
    PrintSort(a,sizeof(a)/sizeof(a[0]));
}//初始化，并且调用插入，打印

int main(){
    //插入排序
    TestInsertSort();
    getchar();
    return 0;
    
}
