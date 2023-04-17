#include"Btree.h"
int main() {
    char a[17]={'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#'};
    int b=0;
    int *pi=&b;
    BTNode *Btree=BinaryTreeCreate(a, 16, pi);
    printf("\n");
//前序遍历
    BinaryTreePrevOrder(Btree);
    printf("\n");
//中序遍历
    BinaryTreeInOrder(Btree);
    printf("\n");
//后序遍历
    BinaryTreePostOrder(Btree);
    printf("\n");
    //乘次遍历
    BinaryTreeLevelOrder(Btree);
    printf("\n");

    int number=BinaryTreeSize(Btree);
    printf("%d",number);
    printf("\n");
    //查找为x的结点
    BTNode *find=BinaryTreeFind(Btree, 'A');
    printf("%c\n",find->_data);

    //查询第k层的结点个数
    int w=BinaryTreeLevelKSize(Btree, 3);
    printf("%d\n",w);

    //查询叶子结点的个数
    int count=BinaryTreeLeafSize(Btree);
    printf("%d\n",count);

//判断当前是否为一棵完全二叉树
    int r=BinaryTreeComplete(Btree);

    //求二叉树的高度
    int x=BinaryTreeHeight(Btree);
    printf("二叉树的高度是%d\n",x);
//    int c=fmax(2,1);
//    printf("%d\n",c);
//销毁二叉树
    BinaryTreeDestroy(&Btree);
    return 0;
}
