#include<stdio.h>
#include<stdlib.h>
//定义结构体
typedef struct treeDate
{
    char data;
    struct treeDate* lchild;
    struct treeDate* rchild;
}Tree,*LPTREE;
//根节点
LPTREE creatNode(char data){
    LPTREE newNode = (LPTREE) malloc(sizeof(Tree));
    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}
//初始化
void insertNode(LPTREE parentNode,LPTREE lchild,LPTREE rchild){
    parentNode->lchild = lchild;
    parentNode->rchild = rchild;
}
//打印
void printDate(LPTREE curDate)
{
    printf("%c\t",curDate->data);
}
//先序遍历，递归
void priOder(LPTREE root){
    if(root!=NULL){
        printDate(root);
        priOder(root->lchild);
        priOder(root->rchild);
    }
}
//非递归
void preOrderByStack(LPTREE root){
    if(root == NULL)
        return;
    //准备栈
    LPTREE stack[10];//存储每次打印节点位置
    int stackTop = -1;//栈顶标记

    LPTREE pMove = root;//从根节点开始打印
    
    while(stackTop != -1 || pMove){
        //根左右
        //找到最左边
        while(pMove){
            //把路径入栈+打印走过的节点
            printf("%c\t",pMove->data);
            stack[++stackTop]=pMove;
            pMove = pMove->lchild;
        }

        if(stackTop!=-1){
            pMove = stack[stackTop];//获取栈顶元素
            stackTop--;//出栈
            pMove = pMove->rchild;
        }
    }
}

//中序遍历，递归
void midOder(LPTREE root){
    if(root!=NULL){
        midOder(root->lchild);
        printDate(root);
        midOder(root->rchild);
    }
}

//中序遍历，非递归
void midOderByStack(LPTREE root){

    if(root==NULL){
        return;
    }
    //栈的准备
    LPTREE stack[10];
    int stackTop = -1;

    //定义移动的指针
    LPTREE pMove = root;
    while(stackTop!=-1||pMove){
        //走到最左边，把走过的节点入栈
        while(pMove){
            stack[++stackTop] = pMove;
            pMove = pMove->lchild;
        }
        //出栈
        if(stackTop!=-1){
            pMove = stack[stackTop--];
            printf("%c\t",pMove->data);
            pMove = pMove->rchild;
        }
    }
}

//后序遍历，递归
void lastOder(LPTREE root){
    if(root!=NULL){
        lastOder(root->lchild);
        lastOder(root->rchild);
        printDate(root);
    }
}

//后序遍历，非递归
void lastOderByStack(LPTREE root){
    if(root == NULL){
        return;
    }
    //创建栈
    LPTREE stack[10];
    int stackTop = -1;

    LPTREE pMove = root;
    LPTREE pLastVisit = NULL;//访问标记
    while(pMove){
        stack[++stackTop] = pMove;
        pMove = pMove->lchild;
    }
    while(stackTop != -1){
        pMove = stack[stackTop--];
        //当前节点左右是否被访问
        if(pMove->rchild == NULL || pMove->rchild == pLastVisit){
            //如果被访问打印当前节点数据
            printf("%c\t",pMove->data);
            pLastVisit = pMove;//改变标记的位置
        }else
        {
            //右边没有被访问访问
            stack[++stackTop] = pMove;
            pMove = pMove->rchild;
            while (pMove)
            {
                stack[++stackTop] = pMove;
                pMove = pMove->lchild;
            }
            
        }
        
    }

}

int main(){
    LPTREE A = creatNode('A');
    LPTREE B = creatNode('B');
    LPTREE C = creatNode('C');
    LPTREE D = creatNode('D');
    LPTREE E = creatNode('E');
    LPTREE F = creatNode('F');
    LPTREE G = creatNode('G');

    insertNode(A,B,C);
    insertNode(B,D,NULL);
    insertNode(D,NULL,G);
    insertNode(C,E,F);

    printf("先序遍历：\n");
    priOder(A);
    printf("\n");
    preOrderByStack(A);
    printf("\n");

    printf("------------------\n");
    printf("中序遍历:\n");
    midOder(A);
    printf("\n");
    midOderByStack(A);
    printf("\n");

    printf("------------------");
    printf("后序遍历：\n");
    lastOder(A);
    printf("\n");
    lastOderByStack(A);
    printf("\n");

    system("pause");
    return 0;
}
