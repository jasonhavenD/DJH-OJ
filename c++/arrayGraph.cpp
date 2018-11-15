// 数组存储的图
//
// Created by jasonhaven on 18-11-9.
//
#include <bits/stdc++.h>

#define MaxVertexNum 20 //顶点的最大个数
typedef int VertexType;//图中顶点的数据类型
typedef int VRType; //表示顶点之间的关系的变量类型
typedef char InfoType; //存储弧或者边额外信息的指针变量类型

typedef enum {
    DG, DN, UDG, UDN
} GraphKind;//枚举图的 4 种类型:有向图,有向网，无向图，无向网

typedef struct {
    VRType adj;//对于无权图，用 1 或 0 表示是否相邻；对于带权图，表示权值
    InfoType *info;//弧或边额外含有的信息指针
} ArcCell, ArcMatrix[MaxVertexNum][MaxVertexNum];

typedef struct {
    VertexType vexs[MaxVertexNum];//一维数组，存储图中顶点数据
    ArcMatrix arcs;//二维数组，记录顶点之间的关系
    int vexnum, arcnum;
    GraphKind kind; //记录图的种类
} MGraph;

/*
 * 根据顶点本身数据，判断出顶点在二维数组中的位置
 * */
int LocateVex(MGraph *G, VertexType v) {
    int i = 0;
    for (i = 0; i < G->vexnum; i++) {
        if (G->vexs[i] == v)return i;
    }
    printf("no this vertex.\n");
    return -1;
}


/*
 * 构造无向图 UDG
 * */
void CreateUDG(MGraph *G) {
    int i, j;
    printf("输入顶点数,边数：");
    scanf("%d,%d", &(G->vexnum), &(G->arcnum));//输入顶点数，边数
    printf("输入顶点数组:\n");
    for (i = 0; i < G->vexnum; i++) {//输入顶点
        scanf("%d", &(G->vexs[i]));
    }
    for (i = 0; i < G->vexnum; i++) {//初始化
        for (j = 0; j < G->vexnum; j++) {
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    printf("输入边矩阵:\n");
    for (i = 0; i < G->arcnum; i++) {
        int v1, v2;
        scanf("%d,%d", &v1, &v2);
        int n = LocateVex(G, v1);
        int m = LocateVex(G, v2);
        if (m == -1 || n == -1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj = 1;//无向图的二阶矩阵沿主对角线对称
        G->arcs[m][n].adj = 1;//无向图的二阶矩阵沿主对角线对称
    }
}

/*
 * 构造有向图 DG
 * */
void CreateDG(MGraph *G) {
    int i, j;
    printf("输入顶点数,边数：");
    scanf("%d,%d", &(G->vexnum), &(G->arcnum));//输入顶点数，边数
    printf("输入顶点数组:\n");
    for (i = 0; i < G->vexnum; i++) {//输入顶点
        scanf("%d", &(G->vexs[i]));
    }
    for (i = 0; i < G->vexnum; i++) {//初始化
        for (j = 0; j < G->vexnum; j++) {
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    printf("输入边矩阵:\n");
    for (i = 0; i < G->arcnum; i++) {
        int v1, v2;
        scanf("%d,%d", &v1, &v2);
        int n = LocateVex(G, v1);
        int m = LocateVex(G, v2);
        if (m == -1 || n == -1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj = 1;
    }
}

/*
 * 构造无向网 UDN
 * */
void CreateUDN(MGraph *G) {
    int i, j;
    printf("输入顶点数,边数：");
    scanf("%d,%d", &(G->vexnum), &(G->arcnum));//输入顶点数，边数
    printf("输入顶点数组:\n");
    for (i = 0; i < G->vexnum; i++) {//输入顶点
        scanf("%d", &(G->vexs[i]));
    }
    for (i = 0; i < G->vexnum; i++) {//初始化
        for (j = 0; j < G->vexnum; j++) {
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    printf("输入边矩阵:\n");
    for (i = 0; i < G->arcnum; i++) {
        int v1, v2;
        VRType adj;
        scanf("%d,%d,%d", &v1, &v2, &adj);
        int n = LocateVex(G, v1);
        int m = LocateVex(G, v2);
        if (m == -1 || n == -1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj = adj;
        G->arcs[m][n].adj = adj;
    }
}

/*
 * 构造有向网 DN
 * */
void CreateDN(MGraph *G) {
    int i, j;
    printf("输入顶点数,边数：");
    scanf("%d,%d", &(G->vexnum), &(G->arcnum));//输入顶点数，边数
    printf("输入顶点数组:\n");
    for (i = 0; i < G->vexnum; i++) {//输入顶点
        scanf("%d", &(G->vexs[i]));
    }
    for (i = 0; i < G->vexnum; i++) {//初始化
        for (j = 0; j < G->vexnum; j++) {
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    printf("输入边矩阵:\n");
    for (i = 0; i < G->arcnum; i++) {
        int v1, v2;
        VRType adj;
        scanf("%d,%d,%d", &v1, &v2, &adj);
        int n = LocateVex(G, v1);
        int m = LocateVex(G, v2);
        if (m == -1 || n == -1) {
            printf("no this vertex\n");
            return;
        }
        G->arcs[n][m].adj = adj;
    }
}

void CreateGraph(MGraph *G) {
    //选择图的类型
    printf("输入图的类型：");
    scanf("%d", &(G->kind));//0,1,2,3 = DG, DN, UDG, UDN
    //根据所选类型，调用不同的函数实现构造图的功能
    switch (G->kind) {
        case DG:
            printf("有向图\n");
            return CreateDG(G);
        case DN:
            printf("有向网\n");
            return CreateDN(G);
        case UDG:
            printf("无向图\n");
            return CreateUDG(G);
        case UDN:
            printf("无向网\n");
            return CreateUDN(G);
        default:
            printf("请重新输入！");
            return;
    }
}

void PrintGrapth(MGraph G) {
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            printf("%d ", G.arcs[i][j].adj);
        }
        printf("\n");
    }
}

int main() {
    MGraph G;
    CreateGraph(&G);
    PrintGrapth(G);//输出图的二阶矩阵
    return 0;
}
/*
输入图的类型：1
有向网
输入顶点数,边数：6,10
输入顶点数组:
1 2 3 4 5 6
输入边矩阵:
1,2,5
2,3,4
3,1,8
1,4,7
4,3,5
3,6,9
6,1,3
4,6,6
6,5,1
5,4,5
0 5 0 7 0 0
0 0 4 0 0 0
8 0 0 0 0 9
0 0 5 0 0 6
0 0 0 5 0 0
3 0 0 0 1 0
 * */