#include "Btree.h"
 
BTNode* BuyNode(BTDataType x)
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    assert(node);
 
    node->_data = x;
    node->_left = NULL;
    node->_right = NULL;
 
    return node;
}
 
 
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
    if(a[*pi] == '#' || *pi >= n)
    {
        printf("NULL ");
        (*pi)++;
        return NULL;
    }
    BTNode *dst= BuyNode(a[*pi]);
    printf("%c ",dst->_data);
    (*pi)++;
 
    dst->_left = BinaryTreeCreate(a,n,pi);
    dst->_right = BinaryTreeCreate(a,n,pi);
 
    return dst;
}
 
 
//�������
void BinaryTreePrevOrder(BTNode* root)
{
    if(root == NULL)
    {
        return;
    }
 
    printf("%c ",root->_data);
    BinaryTreePrevOrder(root->_left);
    BinaryTreePrevOrder(root->_right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
    BinaryTreePrevOrder(root->_left);
    if(root == NULL)
    {
        return;
    }
 
    printf("%c ",root->_data);
    BinaryTreePrevOrder(root->_right);
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
    BinaryTreePrevOrder(root->_left);
    BinaryTreePrevOrder(root->_right);
    if(root == NULL)
    {
        return;
    }
 
    printf("%c ",root->_data);
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{
    Queue q;
    QueueInit(&q);
    assert(root);
    QueuePush(&q, root);
    while(!QueueEmpty(&q))
    {
        BTNode *temp= QueueFront(&q);
        printf("%c ",temp->_data);
        if(temp->_left)
        {
            QueuePush(&q,temp->_left);
        }
        if(temp->_right)
        {
            QueuePush(&q,temp->_right);
        }
 
        QueuePop(&q);
    }
    QueueDestory(&q);
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->_left==NULL&&root->_right==NULL)
    {
        return 1;
    }
    return BinaryTreeSize(root->_left)+BinaryTreeSize(root->_right)+1;
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->_data==x)
    {
        return root;
    }
    BinaryTreeFind(root->_left, x);
    BinaryTreeFind(root->_right,x);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
    if(root==NULL)
    {
        return 0;
    }
    if(k==1)
    {
        return 1;
    }
    return BinaryTreeLevelKSize(root->_left, k-1)+BinaryTreeLevelKSize(root->_right, k-1);
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->_left==NULL&&root->_right==NULL)
    {
        return 1;
    }
    return BinaryTreeLeafSize(root->_left)+BinaryTreeLeafSize(root->_right);
}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
    if(root==NULL)
    {
        return 1;
    }
    Queue q;
    QueueInit(&q);
    QueuePush(&q,root);
    while(!QueueEmpty(&q))
    {
        BTNode *temp= QueueFront(&q);
        QueuePop(&q);
        if(temp==NULL)
        {
            break;
        }
        QueuePush(&q,temp->_left);
        QueuePush(&q,temp->_right);
 
    }
    while(!QueueEmpty(&q))
    {
        BTNode *temp= QueueFront(&q);
        QueuePop(&q);
        if(temp!=NULL)
        {
            printf("������ȫ������\n");
            return 0;
        }
    }
    printf("����ȫ������\n");
    return 1;
}

// ����������
void BinaryTreeDestroy(BTNode** root)
{
    if(root==NULL)
    {
        return ;
    }
    if(*root==NULL)
    {
        return;
    }
    BinaryTreeDestroy(&((*root)->_left));
    BinaryTreeDestroy(&((*root)->_right));
    free(*root);
    *root=NULL;
    return;
}

//��������ĸ߶�
int BinaryTreeHeight(BTNode*root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->_right==NULL&&root->_left==NULL)
    {
        return 1;
    }
    return (BinaryTreeHeight(root->_left)>=BinaryTreeHeight(root->_right) ? BinaryTreeHeight(root->_left)+1 :BinaryTreeHeight(root->_right)+1);
}

//���еĴ���
void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
    assert(pq);
    QNode* cur = pq->head;
    while (cur)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }

    pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
    assert(pq);
    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    assert(newnode);

    newnode->data = x;
    newnode->next = NULL;

    if (pq->tail == NULL)
    {
        assert(pq->head == NULL);
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}

void QueuePop(Queue* pq)
{
    assert(pq);
    assert(pq->head && pq->tail);

    if (pq->head->next == NULL)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        QNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }
}

bool QueueEmpty(Queue* pq)
{
    assert(pq);

    //return pq->head == NULL && pq->tail == NULL;
    return pq->head == NULL;
}

size_t QueueSize(Queue* pq)
{
    assert(pq);
    QNode* cur = pq->head;
    size_t size = 0;
    while (cur)
    {
        size++;
        cur = cur->next;
    }

    return size;
}

QDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
    assert(pq);
    assert(pq->tail);

    return pq->tail->data;
}
