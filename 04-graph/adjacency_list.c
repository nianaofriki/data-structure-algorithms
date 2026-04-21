// 图 - 邻接表存储
// 邻接表 = 数组 + 链表，适合存储稀疏图（边少顶点多）
// 每个顶点对应一个链表，链表中存放与该顶点相邻的顶点
// 函数接口：
//     void initGraph(Graph *g, int n);        // 初始化 n 个顶点的图
//     void addEdge(Graph *g, int u, int v);   // 添加边 u-v（无向图）
//     void printGraph(Graph *g);              // 打印邻接表
//     void DFS(Graph *g, int start);          // 深度优先遍历
//     void BFS(Graph *g, int start);          // 广度优先遍历
//     void destroyGraph(Graph *g);            // 销毁图（释放内存）
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100   // 最大顶点数

typedef struct AdjNode {
    int vertex;                 // 相邻顶点的编号
    struct AdjNode *next;       // 指向下一个邻接点
} AdjNode;

typedef struct Graph {
    int vertexCount;                    // 顶点数
    AdjNode *adjList[MAX_VERTICES];   // 邻接表
} Graph;

void initGraph(Graph *g, int n) {
    g->vertexCount = n;
    for (int i = 0; i < n; i++) {
        g->adjList[i] = NULL;   // 初始时每个顶点都没有邻接点
    }
}
AdjNode* createNode(int vertex) {
    AdjNode *newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}
void addEdge(Graph *g, int u, int v) {
    if (u < 0 || u >= g->vertexCount || v < 0 || v >= g->vertexCount) {
        printf("顶点编号无效\n");
        return;
    }
    // 添加 u-v 边（无向图）
    AdjNode *newNode = createNode(v);
    newNode->next = g->adjList[u];
    g->adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = g->adjList[v];
    g->adjList[v] = newNode;
}
void printGraph(Graph *g) {
    printf("邻接表:\n");
    for (int i = 0; i < g->vertexCount; i++) {
        printf("%d: ", i);
        AdjNode *current = g->adjList[i];
        while (current) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}
void dfsRecursive(Graph *g, int v, bool visited[]) {
    printf("%d ", v);
    visited[v] = true;
    AdjNode *current = g->adjList[v];
    while (current) {
        if (!visited[current->vertex]) {
            dfsRecursive(g, current->vertex, visited);
        }
        current = current->next;
    }
}

void DFS(Graph *g, int start) {
    if (start < 0 || start >= g->vertexCount) {
        printf("顶点编号无效\n");
        return;
    }
    bool visited[MAX_VERTICES] = {false};   // 顶点访问标记
    printf("DFS (从 %d 开始): ", start);
    dfsRecursive(g, start, visited);
    printf("\n");
}
void BFS(Graph *g, int start) {
    if (start < 0 || start >= g->vertexCount) {
        printf("顶点编号无效\n");
        return;
    }
    bool visited[MAX_VERTICES] = {false};   // 标记是否访问过
    int queue[MAX_VERTICES];                 // 队列，存放待访问的顶点
    int front = 0, rear = 0;                // 队头、队尾指针

    // 起点入队并标记
    visited[start] = true;
    queue[rear++] = start;

    printf("BFS (从 %d 开始): ", start);
    while (front < rear) {                  // 队列不为空时循环
        int v = queue[front++];             // 出队一个顶点
        printf("%d ", v);                   // 输出

        // 把 v 的所有未访问的邻居入队
        AdjNode *current = g->adjList[v];
        while (current) {
            if (!visited[current->vertex]) {
                visited[current->vertex] = true;
                queue[rear++] = current->vertex;
            }
            current = current->next;
        }
    }
    printf("\n");
}
void destroyGraph(Graph *g) {
    for (int i = 0; i < g->vertexCount; i++) {
        AdjNode *current = g->adjList[i];
        while (current) {
            AdjNode *temp = current;
            current = current->next;
            free(temp);    // 释放邻接点内存
        }
        g->adjList[i] = NULL;   // 清空邻接表
    }
}
int main() {
    Graph g;
    initGraph(&g, 5);   // 初始化一个有 5 个顶点的图

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4);

    printGraph(&g);     // 打印邻接表

    DFS(&g, 0);        // 从顶点 0 开始深度优先遍历
    BFS(&g, 0);        // 从顶点 0 开始广度优先遍历

    destroyGraph(&g);   // 销毁图，释放内存
    return 0;
}