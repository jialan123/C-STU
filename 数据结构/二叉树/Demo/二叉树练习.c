#include <stdio.h>
#include <stdlib.h>
 
#define MAXSIZE 100
 
 
// ��������ʵ��
 
// ���� �������� �ṹ��
typedef struct node{
	char data;
	struct node *left;
	struct node *right;
}Node, *Tree;
 
// ����ǰ���������������
// �����ң� ABD##E##C##
 
Tree create_tree(){
	Node *root = NULL;
	char ch;
	scanf("%c", &ch); // ���� ABD##E##C##
 
	if (ch != '#'){
		root = (Node*)malloc(sizeof(Node));
		root->data = ch;
 
		root->left = create_tree(); // �ݹ鴴��
		root->right = create_tree();
	}
	else{
		root = NULL;
	}
 
	return root;
}
 
 
// �ݹ�ǰ�����������
void preOrderRec(Tree root){
	if (root != NULL){
		printf(" %c - ", root->data);
		preOrderRec(root->left);
		preOrderRec(root->right);
	}
}
 
// ��-�ݹ�ǰ�����������
void preOrderNRec(Tree root){
	Tree stack[MAXSIZE], node;
	int top = 0;
 
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	else{
		top++;
		// ����һ��ջ
		stack[top] = root; // �����ڵ���ջ
		while (top > 0){
			//��ջ
			node = stack[top--];
			printf(" %c - ", node->data);
 
			// �Ȱ��������Ž�ȥ��ջ���Ƚ�ȥ���������������������ȳ�
			if (node->right != NULL){
				stack[++top] = node->right;  // ��ջ
			}
			if (node->left != NULL){
				stack[++top] = node->left;
			}
 
		}
 
	}
}
 
 
// �ݹ��������������
void inOrderRec(Tree root){
	if (root != NULL){
		inOrderRec(root->left);
		printf(" %c - ", root->data);
		inOrderRec(root->right);
	}
}
 
// ��-�ݹ�ʵ���������������
void inOrderNRec(Tree root){
	Tree stack[MAXSIZE], node;
	int top = 0;
	// �ж����Ƿ�Ϊ��
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	node = root;
 
	while (node != NULL || top > 0){
 
		// �����е��������ڵ���ջ
		while (node != NULL){
			stack[++top] = node;
			node = node->left;
		}
		//  ����ҽڵ�Ϊ�յĻ���ִ���������
		node = stack[top--];
		printf(" %c - ", node->data);
 
		// ɨ���ҽڵ�
		node = node->right;
	}
 
}
 
 
// �ݹ�������������
void backOrderRec(Tree root){
	if (root != NULL){
		backOrderRec(root->left);
		backOrderRec(root->right);
		printf(" %c - ", root->data);
		
	}
}
 
// �� - �ݹ�ʵ�ֺ������
void backOrderNRec(Tree root){
 
	Node *p = root;
	Node *stack[MAXSIZE];
	int num = 0;
	Node *have_visited = NULL;
 
	while (NULL != p || num>0)
	{
		while (NULL != p)
		{
			stack[num++] = p;
			p = p->left;
		}
		p = stack[num - 1];
		if (NULL == p->right || have_visited == p->right)
		{
			printf(" %c - ", p->data);
			num--;
			have_visited = p;
			p = NULL;
		}
		else
		{
			p = p->right;
		}
	}
	
}
 
void backOrderNRecSimple(Tree root){
	Tree stack[MAXSIZE], node;
	int top = 0;
	int count = 0;
	char array[MAXSIZE]; // ʹ��һ���������������ݣ������������ķ�ת
 
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
	else{
		top++;
		// ����һ��ջ
		stack[top] = root; // �����ڵ���ջ
		while (top > 0){
			//��ջ
			node = stack[top--];
			array[count++] = node->data; // ���䱣����һ�����鵱��
 
			// �Ȱ��������Ž�ȥ��ջ���Ƚ�ȥ���������������������ȳ�
			if (node->left != NULL){
				stack[++top] = node->left;  // ��ջ
			}
			if (node->right != NULL){
				stack[++top] = node->right;
			}
 
		}
 
	}
	// ��ת���飬���
	int i;
	for (i = count-1; i >= 0; i--){
		printf(" %c - ", array[i]);
	}
 
}
 
// ��α�������ӡ����������ֵ
void Level_traversal(Tree root){
 
	if (root == NULL){
		printf("tree is empty-- \n");
		return;
	}
 
	Tree stack[MAXSIZE], node;
	node = root;
	int front = 0;  // ʹ�� front�� rearģ�����
	int rear = 0;
 
	stack[rear++] = node;
 
	while (front != rear){
 
		node = stack[front++]; // ģ����У��Ȼ�ȡfront��ǰԪ�أ�Ȼ����ָ�� front ++ λԪ��
		printf(" %c - ", node->data);
		
		// �������������
		if (node->left != NULL){
			stack[rear++] = node->left;
		}
 
		if (node->right != NULL){
			stack[rear++] = node->right;
		}
	}
 
}
 
 
int main(){
 
	printf("starting ------ \n");
 
 
	Tree root = create_tree();
	printf("�ݹ�ǰ�����--- \n");
	preOrderRec(root);
	printf("\n");
	printf("�ݹ��������--- \n");
	inOrderRec(root);
	printf("\n");
	printf("�ݹ�������--- \n");
	backOrderRec(root);
	printf("\n");
	printf("------------------\n");
 
	printf("�ǵݹ�ʵ��ǰ�����--- \n");
	preOrderNRec(root);
	printf("\n");
 
	printf("�ǵݹ�ʵ���������--- \n");
	inOrderNRec(root);
	printf("\n");
 
	printf("�ǵݹ�ʵ�ֺ������--- \n");
	backOrderNRec(root);
	printf("\n");
 
	printf("�ǵݹ�ʵ�ֺ������  �򵥵ķ��� --- \n");
	backOrderNRecSimple(root);
	printf("\n");
 
	printf("��α��� --- \n");
	Level_traversal(root);
	printf("\n");
 
	
 
	// ABD##E##C##
 
 
	return 0;
}
