#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX_NUM 100 // ��󶥵���

// �ڽӱ��б�ʾ�ߵĽṹ��
typedef struct EdgeNode {
    int adjvex;                 // �ڽӵ���
    struct EdgeNode* next;      // ָ����һ���ڽӵ��ָ��
} EdgeNode;

// �ڽӱ��б�ʾ����Ľṹ��
typedef struct VertexNode {
    char data[20];              // ��������
    EdgeNode* first_edge;       // ָ���һ���ڽӵ��ָ��
} VertexNode;

// �ڽӱ��ʾͼ�Ľṹ��
typedef struct {
    VertexNode adj_list[MAX_VERTEX_NUM];    // ��������
    int vertex_num;                         // ������
    int edge_num;                           // ����
} AdjListGraph;

// ��ʼ���ڽӱ��ʾ��ͼ
void init_graph(AdjListGraph* G) {
    G->vertex_num = 0;
    G->edge_num = 0;
    for (int i = 0; i < MAX_VERTEX_NUM; i++) {
        strcpy(G->adj_list[i].data, "");
        G->adj_list[i].first_edge = NULL;
    }
}

// ���ڽӱ��ʾ��ͼ�����һ����
void add_edge(AdjListGraph* G, int u, int v) {
    EdgeNode* new_edge = (EdgeNode*)malloc(sizeof(EdgeNode));
    new_edge->adjvex = v;
    new_edge->next = G->adj_list[u].first_edge;
    G->adj_list[u].first_edge = new_edge;
    G->edge_num++;
}

// ������ȱ���
void BFS(AdjListGraph G, int start) {
    int visited[MAX_VERTEX_NUM] = {0};  // ������飬���ڼ�¼ÿ�������Ƿ񱻷��ʹ�
    int queue[MAX_VERTEX_NUM];          // ���У����ڴ洢�������Ķ���
    int front = 0, rear = 0;            // ���е�ͷ��βָ��

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

    // ����ͼ�Ķ������ͱ���
    printf("Input the number of vertices: ");
    scanf("%d", &G.vertex_num);
    printf("Input the number of edges: ");
    scanf("%d", &G.edge_num);

    // ����ÿ�����������
    printf("Input the data of each vertex:\n");
    for (int i = 0; i < G.vertex_num; i++) {
        printf("Vertex %d: ", i);
        scanf("%s", G.adj_list[i].data);
    }

    // ����ÿ���ߵ������յ�
    printf("Input the edges:\n");
    for (int i = 0; i < G.edge_num; i++) {
        int u, v;
        printf("Edge %d: ", i+1);
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }

    // ���������ʼλ��
    int start;
    printf("Input the starting vertex for BFS: ");
    scanf("%d", &start);

    // ���й�����ȱ���
    BFS(G, start);

    return 0;
}