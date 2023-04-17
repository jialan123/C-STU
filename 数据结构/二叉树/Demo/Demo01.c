#include<stdio.h>
#include<stdlib.h>
//����ṹ��
typedef struct treeDate
{
    char data;
    struct treeDate* lchild;
    struct treeDate* rchild;
}Tree,*LPTREE;
//���ڵ�
LPTREE creatNode(char data){
    LPTREE newNode = (LPTREE) malloc(sizeof(Tree));
    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}
//��ʼ��
void insertNode(LPTREE parentNode,LPTREE lchild,LPTREE rchild){
    parentNode->lchild = lchild;
    parentNode->rchild = rchild;
}
//��ӡ
void printDate(LPTREE curDate)
{
    printf("%c\t",curDate->data);
}
//����������ݹ�
void priOder(LPTREE root){
    if(root!=NULL){
        printDate(root);
        priOder(root->lchild);
        priOder(root->rchild);
    }
}
//�ǵݹ�
void preOrderByStack(LPTREE root){
    if(root == NULL)
        return;
    //׼��ջ
    LPTREE stack[10];//�洢ÿ�δ�ӡ�ڵ�λ��
    int stackTop = -1;//ջ�����

    LPTREE pMove = root;//�Ӹ��ڵ㿪ʼ��ӡ
    
    while(stackTop != -1 || pMove){
        //������
        //�ҵ������
        while(pMove){
            //��·����ջ+��ӡ�߹��Ľڵ�
            printf("%c\t",pMove->data);
            stack[++stackTop]=pMove;
            pMove = pMove->lchild;
        }

        if(stackTop!=-1){
            pMove = stack[stackTop];//��ȡջ��Ԫ��
            stackTop--;//��ջ
            pMove = pMove->rchild;
        }
    }
}

//����������ݹ�
void midOder(LPTREE root){
    if(root!=NULL){
        midOder(root->lchild);
        printDate(root);
        midOder(root->rchild);
    }
}

//����������ǵݹ�
void midOderByStack(LPTREE root){

    if(root==NULL){
        return;
    }
    //ջ��׼��
    LPTREE stack[10];
    int stackTop = -1;

    //�����ƶ���ָ��
    LPTREE pMove = root;
    while(stackTop!=-1||pMove){
        //�ߵ�����ߣ����߹��Ľڵ���ջ
        while(pMove){
            stack[++stackTop] = pMove;
            pMove = pMove->lchild;
        }
        //��ջ
        if(stackTop!=-1){
            pMove = stack[stackTop--];
            printf("%c\t",pMove->data);
            pMove = pMove->rchild;
        }
    }
}

//����������ݹ�
void lastOder(LPTREE root){
    if(root!=NULL){
        lastOder(root->lchild);
        lastOder(root->rchild);
        printDate(root);
    }
}

//����������ǵݹ�
void lastOderByStack(LPTREE root){
    if(root == NULL){
        return;
    }
    //����ջ
    LPTREE stack[10];
    int stackTop = -1;

    LPTREE pMove = root;
    LPTREE pLastVisit = NULL;//���ʱ��
    while(pMove){
        stack[++stackTop] = pMove;
        pMove = pMove->lchild;
    }
    while(stackTop != -1){
        pMove = stack[stackTop--];
        //��ǰ�ڵ������Ƿ񱻷���
        if(pMove->rchild == NULL || pMove->rchild == pLastVisit){
            //��������ʴ�ӡ��ǰ�ڵ�����
            printf("%c\t",pMove->data);
            pLastVisit = pMove;//�ı��ǵ�λ��
        }else
        {
            //�ұ�û�б����ʷ���
            stack[++stackTop] = pMove;
            pMove = pMove->rchild;
            while (pMove)
            {
                stack[++stackTop] = pMove;
                pMove = pMove->lchild;
            }
            
        }
        
    }

}

int main(){
    LPTREE A = creatNode('A');
    LPTREE B = creatNode('B');
    LPTREE C = creatNode('C');
    LPTREE D = creatNode('D');
    LPTREE E = creatNode('E');
    LPTREE F = creatNode('F');
    LPTREE G = creatNode('G');

    insertNode(A,B,C);
    insertNode(B,D,NULL);
    insertNode(D,NULL,G);
    insertNode(C,E,F);

    printf("���������\n");
    priOder(A);
    printf("\n");
    preOrderByStack(A);
    printf("\n");

    printf("------------------\n");
    printf("�������:\n");
    midOder(A);
    printf("\n");
    midOderByStack(A);
    printf("\n");

    printf("------------------");
    printf("���������\n");
    lastOder(A);
    printf("\n");
    lastOderByStack(A);
    printf("\n");

    system("pause");
    return 0;
}
