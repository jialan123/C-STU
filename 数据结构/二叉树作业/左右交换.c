#include <stdio.h>
#include <stdlib.h>

/* 定义二叉树节点结构体 */
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

/* 创建新节点 */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* 交换左右子树 */
void swapSubtrees(Node* root) {
    if (root == NULL) {
        return;
    } else {
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        swapSubtrees(root->left);
        swapSubtrees(root->right);
    }
}

/* 先序遍历二叉树 */
void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    } else {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    /* 创建二叉树 */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    /* 交换左右子树并输出遍历序列 */
    printf("交换前： ");
    preorderTraversal(root);
    printf("\n");
    swapSubtrees(root);
    printf("交换后： ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}