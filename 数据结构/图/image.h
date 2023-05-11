#ifndef C_STU_IMAGE_H
#define C_STU_IMAGE_H
#endif //C_STU_IMAGE_H


#include <stdlib.h>
#include "stdio.h"

#define MAX 20
typedef char VertexType;
typedef int EdgeType;

//����ͼ�ṹ��
typedef struct {
    VertexType vex[MAX];//�����
    EdgeType Edge[MAX][MAX];//�ڽӾ���
    int vernum, arcnum;//������������
} MGragh;

//�߽ṹ��
typedef struct EdgeNode {
    int adjvex;
    struct EdgeNode *next;
} EdgeNode;

//������ṹ��
typedef struct VertexNode {
    VertexType data;
    EdgeNode *firstedge;
} VertexNode;

typedef struct AdjListGraph {
    VertexNode *adjlist;
    int vex, edge;//�������ͱ���
} AdjListGraph;//�ڽӱ�

void Init();
int start();
void print_array(MGragh *g);
void DFSTraverse(MGragh *g, int str);

EdgeType LocateVex(AdjListGraph *q, VertexType vex);

void CreatALGraph();
void traverse_ALn(AdjListGraph *q, int start);
void print_ALn(AdjListGraph *g);

//��������
void Init() {
    MGragh *g;
    g = (MGragh *) malloc(sizeof(MGragh));
    printf("\n=======�ڽӾ���======\n");
    printf("�����붥����Ϣ�ͱ�����");
    scanf("%d %d", &g->vernum, &g->arcnum);
    printf("���붥����Ϣ��");
    for (int i = 1; i <= g->vernum; ++i) {
        scanf("%d", &g->vex[i]);
    }
    for (int i = 1; i <= g->vernum; ++i) {
        for (int j = 1; j <= g->vernum; ++j) {
            g->Edge[i][j] = 0;
        }
    }
    int q, b;
    printf("\n����ߵ���Ϣ��\n");
    for (int k = 1; k <= g->arcnum; ++k) {
        printf("�������Ϣ(�ÿո�ָ�)��");
        scanf("%d %d", &q, &b);
        g->Edge[q][b] = g->Edge[b][q] = 1;
    }


    print_array(g);
    int str = start();
    DFSTraverse(g, str);

}

int start() {
    int str;
    printf("\n������ʼ�㣺");
    scanf("%d", &str);
    return str;
}

//��ӡ������
void print_array(MGragh *g) {
    printf("����������Ϊ��\n");
    printf("=======================\n");
    for (int i = 1; i <= g->vernum; ++i) {
        for (int j = 1; j <= g->vernum; ++j) {
            printf("%d ", g->Edge[i][j]);
        }
        printf("\n");
    }
    printf("=======================\n");
}

//������
void DFSTraverse(MGragh *g, int str) {

    int next;
    EdgeType visited[MAX];
    for (int i = 1; i <= g->vernum + 1; ++i) {
        visited[i] = 0;
    }//��ʼ����������
    printf("�ڽӾ������������Ϊ��");
    printf("v%d ", g->vex[str]);
    visited[str] = 1;

    for (int j = 1; j <= g->vernum; ++j) {
        if (g->Edge[str][j] == 1 && visited[j] == 0) {
            printf("v%d ", j);
            visited[j] = 1;
            str = j;
        }
    }
    printf("\n");
}

//���λ���±�
EdgeType LocateVex(AdjListGraph *q, VertexType vex) {
    for (int i = 0; i < q->vex; ++i) {
        if (q->adjlist[i].data == vex)
            return i;
    }
}

//��ʼ��������
void CreatALGraph() {
    AdjListGraph *g;

    EdgeNode *NewNode1, *NewNode2;

    //��̬����ռ�
    g = (AdjListGraph *) malloc(sizeof(AdjListGraph));


    printf("\n=======�ڽӱ�======\n");
    //���붥��g->vex����g->edge
    printf("���붥���������(�ÿո����)��");
    scanf("%d %d", &g->vex, &g->edge);

    //���붥����Ϣ
    printf("���붥����Ϣ(�ÿո����)��");
    for (int i = 1; i <= g->vex; ++i) {
        scanf(" %c", &g->adjlist[i].data);
        g->adjlist[i].firstedge = NULL;
    }
    int j, k;
    char v1, v2;

    //�����ٽ���붥��Ĺ�ϵ
    for (int i = 1; i <= g->edge; ++i) {
        printf("�������Ϣ(�ÿո�ָ�)��");
        scanf(" %c %c", &v1, &v2);

        //����ٽ��data
        j = LocateVex(g, v1);
        k = LocateVex(g, v2);

        //ͷ�巨

        //v1->v2
        NewNode1 = (EdgeNode *) malloc(sizeof(EdgeNode));
        NewNode1->adjvex = j;
        NewNode1->next = g->adjlist[k].firstedge;
        g->adjlist[k].firstedge = NewNode1;

        //v2->v1
        NewNode2 = (EdgeNode *) malloc(sizeof(EdgeNode));
        NewNode2->adjvex = k;
        NewNode2->next = g->adjlist[j].firstedge;
        g->adjlist[j].firstedge = NewNode2;
    }
    print_ALn(g);
    int str = start();
    traverse_ALn(g, str);
}

//��ʼ�����
void traverse_ALn(AdjListGraph *q, int start) {
    EdgeNode *g;
    AdjListGraph *b;
    //��������
    EdgeType visited[q->vex];
    for (int i = 1; i <= q->vex; ++i) {
        visited[i] = 0;
    }
    visited[0] = 1;
    printf("��%dΪ��ʼ��ı������Ϊ��\n", start);
    printf("v%d ", start);
    visited[start] = 1;
    for (int i = 1; i < q->vex; i++) {
        for (g = q->adjlist[start].firstedge; g != NULL; g = g->next) {
            if (visited[g->adjvex] == 0) {
                printf("v%d ", g->adjvex);
                g->next = q->adjlist[g->adjvex].firstedge;
                visited[g->adjvex] = 1;
            }

        }
    }
}

//��ӡ�ڽӱ�
void print_ALn(AdjListGraph *g) {
    EdgeNode *p;//ָ��ǰ�����ı�

    //���
    printf("�ڽӱ��ӡ���Ϊ��\n");
    for (int i = 1; i <= g->vex; ++i) {
        printf("v%c ", g->adjlist[i].data);
        //printf("v%d",g->vex);
        for (p = g->adjlist[i].firstedge; p != NULL; p = p->next) {
            printf("--> v%d ", p->adjvex);
        }
        printf("\n");
    }
}


