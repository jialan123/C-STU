#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define QueueMax 100
typedef char DataType;
 
typedef struct Node {
	//������������
	DataType data;
	struct Node* leftChild;
	struct Node* rightChild;
}BiTreeNode, * BiTree;
 
typedef struct
{//�������
	BiTree data[QueueMax];
	int head;
	int rear;
	int len;
}Queue;
 
 
//��    �룺ABDGL###H###CEIM###JN##O##F#K#P##
BiTree CreatePreTree();  //����������
int Count1(BiTree bt);//��������Ҷ�ӽڵ������
int Count2(BiTree bt);//��Ϊ2�Ľڵ������
int Treehigh(BiTree bt);//�����������
void ChangeTree(BiTree bt);//������������
Queue InitQueue();  //��ʼ������
int IsEmptyQueue(Queue seq);  //�����п�
int IsFullQueue(Queue seq);   //��������
void PushQueue(Queue* seq, BiTree T);  //���
void PopQueue(Queue* seq, BiTree* T);  //����
void LevelOrder(BiTree T);  //�������
void PreOrder(BiTreeNode* root, void visit(DataType item));//ǰ�����
void InOrder(BiTreeNode* root, void visit(DataType item));//�������
void PostOrder(BiTreeNode* root, void visit(DataType item));//�������
void visit(DataType item);//���ʺ���
void Destory(BiTree bt); //�ͷſռ�
 
int main()
{
	BiTree T;
	char sel = ' ';
	while (sel != '0')
	{
		printf("------��������ʾϵͳ-------\n");
		printf("   �汾:1.0   ����:XXX ����:2022-05-07\n");
		printf("------------------------------------------\n");
		printf("       1.����������\n");
		printf("       2.�������в���\n");
		printf("       3.�������в���\n");
		printf("       4.�������в���\n");
		printf("       5.�����������Ҷ�ӽڵ�Ͷ�Ϊ2�Ľڵ������\n");
		printf("       6.��������������\n");
		printf("       7.�����������нڵ��������������\n");
		printf("       8.�������в���\n");
		printf("       9.ɾ��������\n");
		printf("       0.�˳�ϵͳ\n");
		printf("������ѡ��[0-9]:");
		sel = _getch();
		switch (sel)
		{
		case '1':
			printf("����������.\n");
			T = CreatePreTree();
			system("pause");
			break;
		case '2':
			printf("�������в���.\n");
			printf("ǰ�����:");
			PreOrder(T, visit);//ǰ�����
			system("pause");
			break;
		case '3':
			printf("�������в���.\n");
			printf("\n�������:");
			InOrder(T, visit);//�������
			system("pause");
			break;
		case '4':
			printf("�������в���.\n");
			printf("\n�������:");
			PostOrder(T, visit);//�������
			system("pause");
			break;
		case '5':
			printf("�����������Ҷ�ӽڵ�Ͷ�Ϊ2�Ľڵ������.\n");
			printf("Ҷ�ӽڵ㣺%d��  \n", Count1(T));
			printf("��Ϊ2�Ľڵ�:%d��\n", Count2(T));
			system("pause");
			break;
		case '6':
			printf("��������������.\n");
			printf("�����������Ϊ��%d\n", Treehigh(T));
			system("pause");
			break;
		case '7':
			printf("�����������нڵ��������������.\n");
			ChangeTree(T);
			system("pause");
			break;
		case '8':
			printf("�������в���.\n");
			printf("\n�������:\n");
			LevelOrder(T);//�������
			system("pause");
			break;
		case '9':
			printf("ɾ��������.\n");
			Destory(T);
			printf("ɾ���ɹ�\n");
			system("pause");
			break;
		case '0':
			printf("\nллʹ�ã��ټ���\n");
			break;
		default:
			printf("�������ѡ��Ϸ���������ѡ��\n");
		}
	}
	return 0;
}
void visit(DataType item)
{
	printf("%c ", item);
}
 
BiTree CreatePreTree()//���������� 
{
	char c;
	scanf("%c", &c);
	if (c == '#')  //�ո� 
		return NULL;
	else
	{
		BiTree T = (BiTree)malloc(sizeof(BiTreeNode));
		T->data = c;
		T->leftChild = CreatePreTree();
		T->rightChild = CreatePreTree();
		return T;
	}
}
void PreOrder(BiTreeNode* root, void visit(DataType item)) {
	//ǰ�����������root�����ʲ���Ϊvisit
	if (root != NULL)
	{
		visit(root->data);
		PreOrder(root->leftChild, visit);
		PreOrder(root->rightChild, visit);
	}
}
void InOrder(BiTreeNode* root, void visit(DataType item)) {
	//�������������root�����ʲ���Ϊvisit
	if (root != NULL)
	{
		InOrder(root->leftChild, visit);
		visit(root->data);
		InOrder(root->rightChild, visit);
	}
}
 
void PostOrder(BiTreeNode* root, void visit(DataType item)) {
	//�������������root�����ʲ���Ϊvisit
	if (root != NULL)
	{
		PostOrder(root->leftChild, visit);
		PostOrder(root->rightChild, visit);
		visit(root->data);
	}
}
 
Queue InitQueue()
{  //��ʼ������
	Queue seq;
	int i;
	for (i = 0; i < QueueMax; i++)
	{
		seq.data[i] = NULL;
	}
	seq.head = 0;
	seq.rear = -1;
	seq.len = 0;
	return seq;
}
 
int IsEmptyQueue(Queue seq)
{  //�����п�
	if (seq.len == 0)  return 1;
	return 0;
}
 
int IsFullQueue(Queue seq)
{  //��������
	if (seq.len == QueueMax)  return 1;
	return 0;
}
 
void PushQueue(Queue* seq, BiTree T)
{  //���
	if (IsFullQueue(*seq)) {
		printf("��������\n");
		return;
	}
	seq->rear = (seq->rear + 1) % QueueMax;
	seq->len++;
	seq->data[seq->rear] = T;
}
 
void PopQueue(Queue* seq, BiTree* T)
{  //����
	if (IsEmptyQueue(*seq)) {
		printf("�����ѿ�\n");
		return;
	}
	seq->head = (seq->head + 1) % QueueMax;
	*T = seq->data[seq->head];
	seq->len--;
}
 
void LevelOrder(BiTree T)
{  //�������
	if (T == NULL) return;
	BiTree tmp = T;
	Queue seq = InitQueue();
	int curlevel = 1;
	int nextlevel = 0;
	PushQueue(&seq, tmp);
	while (!IsEmptyQueue(seq))//���в���
	{
		printf("%c ", tmp->data);
		curlevel--;
		if (tmp->leftChild != NULL)
		{
			PushQueue(&seq, tmp->leftChild);
			nextlevel++;
		}
		if (tmp->rightChild != NULL)
		{
			PushQueue(&seq, tmp->rightChild);
			nextlevel++;
		}
		if (curlevel == 0)
		{
			printf("\n");
			curlevel = nextlevel;
			nextlevel = 0;
		}
		PopQueue(&seq, &tmp);
	}
}
 
 
int Count1(BiTree bt)
{
	if (bt == NULL) return 0;
	else if (bt->leftChild == NULL && bt->rightChild == NULL)
		return 1;
	else
		return (Count1(bt->leftChild) + Count1(bt->rightChild));
}
int Count2(BiTree bt)
{
	int num = 0;
	if (bt)
	{
		if (bt->leftChild != NULL && bt->rightChild != NULL)
		{
			num = 1;
		}
		num += Count2(bt->leftChild) + Count2(bt->rightChild);
	}
	return num;
}
 
int Treehigh(BiTree bt)
{
	int lefthigh, righthigh, high;
	if (bt == NULL)  high = 0;//����
	else
	{
		lefthigh = Treehigh(bt->leftChild);
		righthigh = Treehigh(bt->rightChild);
		int i = lefthigh > righthigh ? lefthigh : righthigh;//�ҵ����������
		high = i + 1;//�������+1=�������
	}
	return high;
}
 
void ChangeTree(BiTree bt)
{
	BiTree temp = (BiTree)malloc(sizeof(BiTreeNode));
	if (bt)
	{
		temp = bt->rightChild;
		bt->rightChild = bt->leftChild;
		bt->leftChild = temp;//������������bt�������ҽ�㽻���ɹ�
		ChangeTree(bt->leftChild);
		ChangeTree(bt->rightChild);
	}
	else return;
}
 
void Destory(BiTree T) //����������ͷŽ��ռ�
{
	if (T != NULL)
	{
		if (T->leftChild != NULL)    Destory(T->leftChild);
		if (T->rightChild != NULL) Destory(T->rightChild);
		free(T);
	}
}
