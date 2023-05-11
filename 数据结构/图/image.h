#ifndef C_STU_IMAGE_H
#define C_STU_IMAGE_H
#endif //C_STU_IMAGE_H


#include <stdlib.h>
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
} VertexNode;

typedef struct AdjListGraph {
    VertexNode *adjlist;
    int vex, edge;//顶点数和边数
} AdjListGraph;//邻接表

void Init();
int start();
void print_array(MGragh *g);
void DFSTraverse(MGragh *g, int str);

EdgeType LocateVex(AdjListGraph *q, VertexType vex);

void CreatALGraph();
void traverse_ALn(AdjListGraph *q, int start);
void print_ALn(AdjListGraph *g);

//接收数据
void Init() {
    MGragh *g;
    g = (MGragh *) malloc(sizeof(MGragh));
    printf("\n=======邻接矩阵======\n");
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
    printf("\n输入边的信息：\n");
    for (int k = 1; k <= g->arcnum; ++k) {
        printf("输入边信息(用空格分割)：");
        scanf("%d %d", &q, &b);
        g->Edge[q][b] = g->Edge[b][q] = 1;
    }


    print_array(g);
    int str = start();
    DFSTraverse(g, str);

}

int start() {
    int str;
    printf("\n输入起始点：");
    scanf("%d", &str);
    return str;
}

//打印深层遍历
void print_array(MGragh *g) {
    printf("深层遍历矩阵为：\n");
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

//获得位置下标
EdgeType LocateVex(AdjListGraph *q, VertexType vex) {
    for (int i = 0; i < q->vex; ++i) {
        if (q->adjlist[i].data == vex)
            return i;
    }
}

//初始化并输入
void CreatALGraph() {
    AdjListGraph *g;

    EdgeNode *NewNode1, *NewNode2;

    //动态申请空间
    g = (AdjListGraph *) malloc(sizeof(AdjListGraph));


    printf("\n=======邻接表======\n");
    //输入顶点g->vex，边g->edge
    printf("输入顶点数与边数(用空格隔开)：");
    scanf("%d %d", &g->vex, &g->edge);

    //输入顶点信息
    printf("输入顶点信息(用空格隔开)：");
    for (int i = 1; i <= g->vex; ++i) {
        scanf(" %c", &g->adjlist[i].data);
        g->adjlist[i].firstedge = NULL;
    }
    int j, k;
    char v1, v2;

    //建立临界点与顶点的关系
    for (int i = 1; i <= g->edge; ++i) {
        printf("输入边信息(用空格分割)：");
        scanf(" %c %c", &v1, &v2);

        //获得临界点data
        j = LocateVex(g, v1);
        k = LocateVex(g, v2);

        //头插法

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

//起始点遍历
void traverse_ALn(AdjListGraph *q, int start) {
    EdgeNode *g;
    AdjListGraph *b;
    //遍历数组
    EdgeType visited[q->vex];
    for (int i = 1; i <= q->vex; ++i) {
        visited[i] = 0;
    }
    visited[0] = 1;
    printf("以%d为起始点的遍历结果为：\n", start);
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

//打印邻接表
void print_ALn(AdjListGraph *g) {
    EdgeNode *p;//指向当前操作的边

    //输出
    printf("邻接表打印结果为：\n");
    for (int i = 1; i <= g->vex; ++i) {
        printf("v%c ", g->adjlist[i].data);
        //printf("v%d",g->vex);
        for (p = g->adjlist[i].firstedge; p != NULL; p = p->next) {
            printf("--> v%d ", p->adjvex);
        }
        printf("\n");
    }
}


