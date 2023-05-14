#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX_NUM 100 // 最大顶点数

// 邻接表中表示边的结构体
typedef struct EdgeNode {
    int adjvex;                 // 邻接点编号
    struct EdgeNode* next;      // 指向下一个邻接点的指针
} EdgeNode;

// 邻接表中表示顶点的结构体
typedef struct VertexNode {
    char data[20];              // 顶点数据
    EdgeNode* first_edge;       // 指向第一个邻接点的指针
} VertexNode;

// 邻接表表示图的结构体
typedef struct {
    VertexNode adj_list[MAX_VERTEX_NUM];    // 顶点数组
    int vertex_num;                         // 顶点数
    int edge_num;                           // 边数
} AdjListGraph;

// 初始化邻接表表示的图
void init_graph(AdjListGraph* G) {
    G->vertex_num = 0;
    G->edge_num = 0;
    for (int i = 0; i < MAX_VERTEX_NUM; i++) {
        strcpy(G->adj_list[i].data, "");
        G->adj_list[i].first_edge = NULL;
    }
}

// 向邻接表表示的图中添加一条边
void add_edge(AdjListGraph* G, int u, int v) {
    EdgeNode* new_edge = (EdgeNode*)malloc(sizeof(EdgeNode));
    new_edge->adjvex = v;
    new_edge->next = G->adj_list[u].first_edge;
    G->adj_list[u].first_edge = new_edge;
    G->edge_num++;
}

// 广度优先遍历
void BFS(AdjListGraph G, int start) {
    int visited[MAX_VERTEX_NUM] = {0};  // 标记数组，用于记录每个顶点是否被访问过
    int queue[MAX_VERTEX_NUM];          // 队列，用于存储待遍历的顶点
    int front = 0, rear = 0;            // 队列的头和尾指针

    printf("BFS traversal: ");
    visited[start] = 1;
    queue[rear++] = start;
    while (front != rear) {
        int v = queue[front++];
        printf("%s ", G.adj_list[v].data);
        EdgeNode* p = G.adj_list[v].first_edge;
        while (p != NULL) {
            int w = p->adjvex;
            if (!visited[w]) {
                visited[w] = 1;
                queue[rear++] = w;
            }
            p = p->next;
        }
    }
    printf("\n");
}

int main() {
    AdjListGraph G;
    init_graph(&G);

    // 输入图的顶点数和边数
    printf("Input the number of vertices: ");
    scanf("%d", &G.vertex_num);
    printf("Input the number of edges: ");
    scanf("%d", &G.edge_num);

    // 输入每个顶点的数据
    printf("Input the data of each vertex:\n");
    for (int i = 0; i < G.vertex_num; i++) {
        printf("Vertex %d: ", i);
        scanf("%s", G.adj_list[i].data);
    }

    // 输入每条边的起点和终点
    printf("Input the edges:\n");
    for (int i = 0; i < G.edge_num; i++) {
        int u, v;
        printf("Edge %d: ", i+1);
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    // 输入遍历起始位置
    int start;
    printf("Input the starting vertex for BFS: ");
    scanf("%d", &start);

    // 进行广度优先遍历
    BFS(G, start);

    return 0;
}