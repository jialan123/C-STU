#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/* 计算二叉树的高度 */
int height(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

/* 判断二叉树是否是满二叉树 */
int isFullBinaryTree(Node* root) {
    if (root == NULL) {
        return 1;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == rightHeight && isFullBinaryTree(root->left) && isFullBinaryTree(root->right)) {
            return 1;
        } else {
            return 0;
        }
    }
}

/* 计算叶子节点数目 */
int countLeaves(Node* root) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        return countLeaves(root->left) + countLeaves(root->right);
    }
}

int main() {
    /* 创建二叉树 */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    /* 判断是否是满二叉树 */
    if (isFullBinaryTree(root)) {
        printf("是满二叉树\n");
    } else {
        printf("不是满二叉树\n");
    }

    /* 计算叶子节点数目 */
    printf("叶子节点数目为：%d\n", countLeaves(root));

    return 0;
}

