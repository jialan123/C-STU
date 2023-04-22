#include <stdio.h>
#include <stdlib.h>
typedef char datatype;

//计算节点总数，交换左右子树，判断满二叉树


/* 定义二叉树节点结构体 */
typedef struct node {
    datatype data;
    struct node *lchild;
    struct node *rchild;;
} Node,*Bintree;

/*按先序创建二叉树*/
Bintree CreateTree(Bintree T)
{
    datatype ch;
    scanf("%c",&ch);
    if(ch=='#')
        return NULL;
    else
    {
        T=(Bintree)malloc(sizeof(Node));
        T->data=ch;
        T->lchild=CreateTree(T->lchild);/*创建左子树*/
        T->rchild=CreateTree(T->rchild);/*创建右子树*/
        return T;
    }
}

/* 计算二叉树的高度 */
int height(Bintree root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->lchild);
        int rightHeight = height(root->rchild);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

/* 判断二叉树是否是满二叉树 */
int isFullBinaryTree(Bintree root) {
    if (root == NULL) {
        return 1;
    } else {
        int leftHeight = height(root->lchild);
        int rightHeight = height(root->rchild);
        if (leftHeight == rightHeight && isFullBinaryTree(root->lchild) && isFullBinaryTree(root->rchild)) {
            printf("是满二叉树");
            return 1;
        } else {
            printf("不是满二叉树");
            return 0;
        }
    }
}

// 二叉树节点个数
int BinaryTreeSize(Bintree root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->lchild==NULL&&root->rchild==NULL)
    {
        return 1;
    }
    return BinaryTreeSize(root->lchild)+BinaryTreeSize(root->rchild)+1;
}

/* 交换左右子树 */
void swapSubtrees(Bintree root) {
    if (root == NULL) {
        return;
    } else {
        Bintree temp = root->lchild;
        root->lchild = root->rchild;
        root->rchild = temp;
        swapSubtrees(root->lchild);
        swapSubtrees(root->rchild);
    }
}

/* 先序遍历二叉树 */
void preorderTraversal(Bintree root) {
    if (root == NULL) {
        return;
    } else {
        printf("%c ", root->data);
        preorderTraversal(root->lchild);
        preorderTraversal(root->rchild);
    }
}

int main() {
    /* 创建二叉树 */
    Bintree t;
    printf("输入二叉树:\n");
    t = CreateTree(t);
    printf("-----------------------------\n");
    printf("节点总数是：%d\n", BinaryTreeSize(t));
    printf("-----------------------------\n");
    isFullBinaryTree(t);
    printf("\n-----------------------------");
    swapSubtrees(t);
    printf("\n交换后为：\n");
    preorderTraversal(t);
    printf("\n-----------------------------\n");
    printf("数的深度为：%d\n", height(t));
    system("pause");
    return 0;
}
