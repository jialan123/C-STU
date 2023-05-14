//
// Created by 温文瀚_ on 2023/5/14.
//
#include <stdio.h>
#include <stdlib.h>
#define VertexMax 10 //最大顶点数为100
#define Maxsize 10 //队列最大元素个数100

typedef char VertexType; //每个顶点数据类型为字符型
typedef int dataType; //队列元素类型

/*图结构体*/
typedef struct
{
    VertexType Vertex[VertexMax];//存放顶点元素的一维数组
    int AdjMatrix[VertexMax][VertexMax];//邻接矩阵二维数组
    int vexnum,arcnum;//图的顶点数和边数
}MGraph;

/*队列结构体*/
typedef struct
{
    dataType *base;
    int front;
    int rear;
}CyQueue;

/*无向图UDG的基本操作*/
int LocateVex(MGraph *G,VertexType v)//查找元素v在一维数组 Vertex[] 中的下标，并返回下标
{
    int i;

    for(i=0;i<G->vexnum;i++)
    {
        if(v==G->Vertex[i])
        {
            return i;
        }
    }

    printf("No Such Vertex!\n");
    return -1;
}

void CreateUDG(MGraph *G)
{
    int i,j;

    printf("输入顶点个数和边数：\n");
    printf("顶点数 n=");
    scanf("%d",&G->vexnum);
    printf("边  数 e=");
    scanf("%d",&G->arcnum);
    printf("\n");

    printf("\n");


    printf("输入顶点元素(无需空格隔开)：");
    scanf("%s",G->Vertex);
    printf("\n");

    for(i=0;i<G->vexnum;i++)
        for(j=0;j<G->vexnum;j++)
        {
            G->AdjMatrix[i][j]=0;
        }


    int n,m;
    VertexType v1,v2;

    printf("请输入边的信息：\n");
    for(i=0;i<G->arcnum;i++)
    {
        printf("输入第%d条边信息：",i+1);
        scanf(" %c %c",&v1,&v2);
        n=LocateVex(G,v1);
        m=LocateVex(G,v2);

        if(n==-1||m==-1)
        {
            printf("NO This Vertex!\n");
            return;
        }

        G->AdjMatrix[n][m]=1;
        G->AdjMatrix[m][n]=1;
    }

}

void print(MGraph G)
{
    int i,j;
    printf("\n-------------------------------");
    printf("\n 邻接矩阵：\n\n");

    printf("\t ");
    for(i=0;i<G.vexnum;i++)
        printf("  %c",G.Vertex[i]);
    printf("\n");

    for(i=0;i<G.vexnum;i++)
    {
        printf("\t%c",G.Vertex[i]);

        for(j=0;j<G.vexnum;j++)
        {
            printf("  %d",G.AdjMatrix[i][j]);
        }
        printf("\n");
    }
}

/*循环队列基本操作*/
void create(CyQueue *q)
{
    q->base=(dataType *)malloc(Maxsize*sizeof(dataType));
    if(!q->base)
    {
        printf("Space allocation failed!\n");
        return;
    }
    q->front=q->rear=0;
    return;
}

void EnQueue(CyQueue *q,dataType value)
{
    if((q->rear+1)%Maxsize==q->front)
    {
        printf("Cyclic Queue is Full!\n");
        return;
    }
    q->base[q->rear]=value;
    q->rear=(q->rear+1)%Maxsize;
    return;
}

void DeQueue(CyQueue *q,dataType *value)
{
    if(q->front==q->rear)
    {
        printf("Cyclic Queue is Empty!\n");
        return;
    }
    *value=q->base[q->front];
    q->front=(q->front+1)%Maxsize;
    return;
}

int QueueEmpty(CyQueue *q)
{
    if (q->front==q->rear)//队列为空返回1，不为空返回0
    {
        return 1;
    }
    return 0;
}

/*广度优先遍历BFS*/
int visited[VertexMax];//定义"标志"数组为全局变量

void BFS(MGraph *G,int i)
{
    int j;
    CyQueue q;
    create(&q);
    //1.设置起始点
    printf("%c",G->Vertex[i]);//1.输出当前结点
    visited[i]=1;//2.将已访问的结点标志成1
    EnQueue(&q,i);//3.将第一个结点入队

    //2.由起始点开始，对后续结点进行操作
    while(!QueueEmpty(&q))
    {

        DeQueue(&q,&i);

        for(j=0;j<G->vexnum;j++)
        {
            if(G->AdjMatrix[i][j]==1&&visited[j]==0)
            {
                printf("%c",G->Vertex[j]);//输出符合条件的顶点
                visited[j]=1;//设置成已访问状态1
                EnQueue(&q,j);//入队
            }
        }
    }
}

void BFSTraverse(MGraph *G)
{
    int i;

    //数组初始化为全0
    for(i=0;i<G->vexnum;i++)
    {
        visited[i]=0;
    }

    for(i=0;i<G->vexnum;i++)
    {
        if(visited[i]==0)
        {
            BFS(G,i);
        }
    }
}

int main()
{
    MGraph G;
    CreateUDG(&G);
    print(G);

    printf("\n\n广度优先遍历：");
    BFSTraverse(&G);

    return 0;
}
