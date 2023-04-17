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

/* 计算二叉树节点总数 */
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int main() {
    /* 创建二叉树 */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    /* 计算节点总数 */
    int nodeCount = countNodes(root);
    printf("节点总数是：%d\n", nodeCount);

    return 0;
}