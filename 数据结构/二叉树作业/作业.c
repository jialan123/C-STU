#include <stdio.h>
#include <stdlib.h>
typedef char datatype;

//����ڵ����������������������ж���������


/* ����������ڵ�ṹ�� */
typedef struct node {
    datatype data;
    struct node *lchild;
    struct node *rchild;;
} Node,*Bintree;

/*�����򴴽�������*/
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
        T->lchild=CreateTree(T->lchild);/*����������*/
        T->rchild=CreateTree(T->rchild);/*����������*/
        return T;
    }
}

/* ����������ĸ߶� */
int height(Bintree root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->lchild);
        int rightHeight = height(root->rchild);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

/* �ж϶������Ƿ����������� */
int isFullBinaryTree(Bintree root) {
    if (root == NULL) {
        return 1;
    } else {
        int leftHeight = height(root->lchild);
        int rightHeight = height(root->rchild);
        if (leftHeight == rightHeight && isFullBinaryTree(root->lchild) && isFullBinaryTree(root->rchild)) {
            printf("����������");
            return 1;
        } else {
            printf("������������");
            return 0;
        }
    }
}

// �������ڵ����
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

/* ������������ */
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

/* ������������� */
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
    /* ���������� */
    Bintree t;
    printf("���������:\n");
    t = CreateTree(t);
    printf("-----------------------------\n");
    printf("�ڵ������ǣ�%d\n", BinaryTreeSize(t));
    printf("-----------------------------\n");
    isFullBinaryTree(t);
    printf("\n-----------------------------");
    swapSubtrees(t);
    printf("\n������Ϊ��\n");
    preorderTraversal(t);
    printf("\n-----------------------------\n");
    printf("�������Ϊ��%d\n", height(t));
    system("pause");
    return 0;
}
