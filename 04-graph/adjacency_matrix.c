// 图 - 邻接矩阵存储
// 函数接口：
//     void initGraph(Graph *g, int n);        // 初始化 n 个顶点的图
//     void addEdge(Graph *g, int u, int v);   // 添加边 u->v（无向图）
//     void printGraph(Graph *g);              // 打印邻接矩阵
//     void DFS(Graph *g, int start);          // 深度优先遍历
//     void BFS(Graph *g, int start);          // 广度优先遍历
//     void DFSTraverse(Graph *g);             // 非连通图的完整DFS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];  // 邻接矩阵
    int vertexCount;                         // 顶点数量
} Graph;

// 初始化图
void initGraph(Graph *g, int n) {
    g->vertexCount = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->matrix[i][j] = 0;
        }
    }
}

// 添加边（无向图，对称添加），u, v: 顶点编号（从0开始）
void addEdge(Graph *g, int u, int v) {
    if (u < 0 || u >= g->vertexCount || v < 0 || v >= g->vertexCount) {
        printf("顶点编号无效\n");
        return;
    }
    g->matrix[u][v] = 1;
    g->matrix[v][u] = 1;
}

// 打印邻接矩阵
void printGraph(Graph *g) {
    printf("邻接矩阵:\n");
    for (int i = 0; i < g->vertexCount; i++) {
        for (int j = 0; j < g->vertexCount; j++) {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}

//  DFS 递归辅助函数
void DFS_recursive(Graph *g, int start, bool visited[]) {
    printf("%d ", start);
    visited[start] = true;
    for (int i = 0; i < g->vertexCount; i++) {
        if (g->matrix[start][i] && !visited[i]) {
            DFS_recursive(g, i, visited);
        }
    }
}
// 深度优先遍历（从 start 开始），原理：一条路走到黑，再回溯，类似树的先序遍历+
void DFS(Graph *g, int start) {
    if (start < 0 || start >= g->vertexCount) {
        printf("顶点编号无效\n");
        return;
    }
    bool visited[MAX_VERTICES] = {false};  // 初始化所有顶点为未访问
    printf("DFS (从 %d 开始): ", start);
    dfsRecursive(g, start, visited);
    printf("\n");
}

// 广度优先遍历（从 start 开始），原理：一层一层往外扩展，使用队列，类似树的层序遍历
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
        for (int i = 0; i < g->vertexCount; i++) {
            if (g->matrix[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
// 非连通图的完整DFS（遍历所有连通分量），如果图不是连通的，从单个起点无法访问所有顶点，这个函数可以遍历所有顶点
void DFSTraverse(Graph *g) {
    bool visited[MAX_VERTICES] = {false};   // 顶点访问标记
    printf("DFS (非连通图): ");
    for (int i = 0; i < g->vertexCount; i++) {
        if (!visited[i]) {
            dfsRecursive(g, i, visited);
        }
    }
    printf("\n");
}
// 测试主函数
// 构建以下无向图：
//     0 --- 1
//    / \     \
//   2   3 --- 4
//   |
//   5
int main() {
    Graph g;
    initGraph(&g, 6);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 3, 4);
    addEdge(&g, 2, 5);
    printGraph(&g);
    DFS(&g, 0);
    BFS(&g, 0);
    DFSTraverse(&g);
    return 0;

}