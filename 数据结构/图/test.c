#include <stdio.h>
#include <stdlib.h>
/*三步走，从一个存储顶点的数组，里面又有点数和边数*/
/*数组是存储顶点信息的，后面有一个链表结点*/
/*这个链表结点又是一个结构体类型，包含一个一个点数和指向下一个的点数*/
#define MAX 100
typedef char VertexType;

typedef struct node {   //定义边表结点
    int adjvex;  //邻接点域
    struct node *next; //指向下一个邻接点域的指针域
} EdgeNode;

typedef struct vexnode { //定义顶点表结点
    VertexType data; //顶点域
    EdgeNode *firstedge; //指向第一条边结点
} VHeadeNode;

typedef struct {
    VHeadeNode adjlist[MAX];/*邻接表头结点数组*/
    int n, e;//顶点数，边数
} AdjList; //图的邻接表类型

void GreateAGraph(AdjList *g, int flag) {  //根据flag的值0，1选择是有向图还是无向图
    int i;
    if (flag == 0) {
        printf("=============建立一个无向图==============\n");
    } else {
        printf("=============建立一个有向图=============\n");
    }
    printf("请输入图的顶点数：");
    scanf("%d", &g->n);
    printf("请输入图的边数：");
    scanf("%d", &g->e);
    getchar();//掉这个回车，防止影响下一个字符的输入
    printf("顶：%d,边：%d", g->n, g->e);

    /*建立图的顶点信息*/
    printf("\n请的输入图的各顶点信息：\n");// A
    for (i = 0; i < g->n; i++) {
        printf("第%d个顶点信息:", i + 1);
        scanf("%c", &(g->adjlist[i].data)); //给图的每个结点的顶点域赋值  adjlist[0].data=A
        getchar();
        g->adjlist[i].firstedge = NULL; //首先点的边表头指针都设为空
    }
    for (i = 0; i < g->n; i++) {
        printf("+%c+", g->adjlist[i].data);//校验顶点输出
    }

    /*建立图的边表的信息*/
    printf("\n请输入边的信息，输入格式为：序号1，序号2（序号依次为0,1,2……）\n");
    int x, y;//关系结点数
    EdgeNode *p;
    for (i = 0; i < g->e; i++) //判断条件为输入的边数
    {
        printf("请输入第%d条边：", i);
        scanf("%d,%d", &x, &y);//输入第一条边，将编号为x的结点添加到邻接表中
        p = (EdgeNode *) malloc(sizeof(EdgeNode));
        p->adjvex = y; //把y放到邻接点域
        p->next = g->adjlist[x].firstedge;//头插法
        g->adjlist[x].firstedge = p;
        if (flag == 0) {
            p = (EdgeNode *) malloc(sizeof(EdgeNode));
            p->adjvex = x;//y的邻接点（邻接序号）
            p->next = g->adjlist[y].firstedge;//无向图的边相等，也将编号为y的结点添加到邻接表中
            g->adjlist[y].firstedge = p;
        }
    }
}

/*输出邻接表的函数*/
void DisPlay(AdjList *g) {
    int i;
    EdgeNode *p;
    printf("\n=======输出邻接表========\n");
    for (i = 0; i < g->n; i++) {
        printf("%2d [%c]", i, g->adjlist[i].data);
        p = g->adjlist[i].firstedge;
        while (p != NULL) {
            printf("-->[%d]", p->adjvex);
            p = p->next;
        }
        printf("\n");
    }
}

int main() {
    AdjList G;
    GreateAGraph(&G, 0);//建立无向图
    DisPlay(&G);
    return 0;
}