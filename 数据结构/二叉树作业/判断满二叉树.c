#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/* ����������ĸ߶� */
int height(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }
}

/* �ж϶������Ƿ����������� */
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

/* ����Ҷ�ӽڵ���Ŀ */
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
    /* ���������� */
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    /* �ж��Ƿ����������� */
    if (isFullBinaryTree(root)) {
        printf("����������\n");
    } else {
        printf("������������\n");
    }

    /* ����Ҷ�ӽڵ���Ŀ */
    printf("Ҷ�ӽڵ���ĿΪ��%d\n", countLeaves(root));

    return 0;
}

