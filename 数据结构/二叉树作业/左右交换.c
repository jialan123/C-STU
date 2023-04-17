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

/* ������������ */
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

/* ������������� */
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
    /* ���������� */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    /* ������������������������� */
    printf("����ǰ�� ");
    preorderTraversal(root);
    printf("\n");
    swapSubtrees(root);
    printf("������ ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}