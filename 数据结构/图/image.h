#ifndef C_STU_IMAGE_H
#define C_STU_IMAGE_H
#endif //C_STU_IMAGE_H


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
} VertexNode, Adjlist;

typedef struct AdjListGraph {
    Adjlist *adjlist;
    int vex, edge;//�������ͱ���
} AdjListGraph;//�ڽӱ�

//��ʼ������
void Init(MGragh *g) {
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
    printf("\n����ߵ���Ϣ��");
    for (int k = 1; k <= g->arcnum; ++k) {
        scanf("%d%d", &q, &b);
        g->Edge[q][b] = g->Edge[b][q] = 1;
    }

}

void print_array(MGragh *g) {
    Init(g);
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
    printf("v%d", g->vex[str]);
    visited[str] = 1;

    for (int j = 1; j <= g->vernum; ++j) {
        if (g->Edge[str][j] == 1 && visited[j] == 0) {
            printf("v%d", j);
            visited[j] = 1;
            str = j;
        }
    }


}
