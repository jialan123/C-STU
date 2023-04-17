#include <stdio.h>
#include <stdlib.h>

void Swap(int* i, int* j);
void Swapbuffer(int* arr,int n);
void PrintLine(int* arr,int n);



void Swap(int* i, int* j) //交换数据
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void Swapbuffer(int* arr,int n)//冒泡排序
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        int test = 0;
        //单趟
        for(j = 1;j < n - i; j++)
        {
            if(arr[j - 1]>arr[j])
            {
                test = 1;
                Swap(&arr[j-1],&arr[j]);
            }
        }

        if(!test){
            break;
        }
    }
}

void PrintLine(int* arr,int n){//打印
    int i;
    for(i = 0;i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int i;
    int arr[5];

    for(i = 0; i < 5; i++)//输入
    {
        scanf("%d",&arr[i]);
    }
    Swapbuffer(arr,5);
    PrintLine(arr,5);
    getchar();
    return 0;
}
