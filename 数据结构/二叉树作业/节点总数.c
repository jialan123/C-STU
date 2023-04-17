#include <stdio.h>
#include <stdlib.h>

/* ����������ڵ�ṹ�� */
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

/* �����½ڵ� */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* ����������ڵ����� */
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int main() {
    /* ���������� */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    /* ����ڵ����� */
    int nodeCount = countNodes(root);
    printf("�ڵ������ǣ�%d\n", nodeCount);

    return 0;
}