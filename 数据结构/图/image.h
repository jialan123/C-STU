#ifndef C_STU_IMAGE_H
#define C_STU_IMAGE_H
#endif //C_STU_IMAGE_H


#include "stdio.h"

#define MAX 20
typedef char VertexType;
typedef int EdgeType;

//无向图结构体
typedef struct {
    VertexType vex[MAX];//顶点表
    EdgeType Edge[MAX][MAX];//邻接矩阵
    int vernum, arcnum;//顶点数，弧数
} MGragh;

//边结构体
typedef struct EdgeNode {
    int adjvex;
    struct EdgeNode *next;
} EdgeNode;

//顶点域结构体
typedef struct VertexNode {
    VertexType data;
    EdgeNode *firstedge;
} VertexNode, Adjlist;

typedef struct AdjListGraph {
    Adjlist *adjlist;
    int vex, edge;//顶点数和边数
} AdjListGraph;//邻接表

//初始化数据
void Init(MGragh *g) {
    printf("请输入顶点信息和边数：");
    scanf("%d %d", &g->vernum, &g->arcnum);
    printf("输入顶点信息：");
    for (int i = 1; i <= g->vernum; ++i) {
        scanf("%d", &g->vex[i]);
    }
    for (int i = 1; i <= g->vernum; ++i) {
        for (int j = 1; j <= g->vernum; ++j) {
            g->Edge[i][j] = 0;
        }
    }
    int q, b;
    printf("\n输入边的信息：");
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

//深层遍历
void DFSTraverse(MGragh *g, int str) {
    int next;
    EdgeType visited[MAX];
    for (int i = 1; i <= g->vernum + 1; ++i) {
        visited[i] = 0;
    }//初始化访问数组
    printf("邻接矩阵深层遍历结果为：");
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
