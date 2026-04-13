// 队列 - 链式存储（链表实现）
// 函数接口：
//     void initQueue(Queue *q);        // 初始化队列
//     bool enqueue(Queue *q, int x);   // 入队
//     bool dequeue(Queue *q, int *x);  // 出队
//     bool isEmpty(Queue *q);          // 判空
//     int getSize(Queue *q);           // 获取队列长度
//     void destroyQueue(Queue *q);     // 销毁队列
//     void printQueue(Queue *q);       // 打印队列
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node { 
    int data;
    struct Node *next;
} Node;
typedef struct {
    Node *front, *rear;
    int size;
} Queue;
// 初始化队列
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
    q->size = 0;
}
// 判空
bool isEmpty(Queue *q) {
    return q->size == 0;
}
// 入队
bool enqueue(Queue *q, int x) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) return false; // 内存分配失败
    newNode->data = x;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode; // 第一个节点
    } else {
        q->rear->next = newNode; // 连接新节点
        q->rear = newNode;       // 更新rear
    }
    q->size++;
    return true;
}
// 出队
bool dequeue(Queue *q, int *x) {
    if (isEmpty(q)) return false; // 队空
    Node *temp = q->front;
    *x = temp->data; // 获取出队元素
    q->front = q->front->next; // 更新front
    free(temp); // 释放旧节点
    q->size--;
    if (isEmpty(q)) {
        q->rear = NULL; // 队空时rear也置NULL
    }
    return true;
}
// 获取队列长度
int getSize(Queue *q) {
    return q->size;
}
// 销毁队列
void destroyQueue(Queue *q) {
    while (!isEmpty(q)) {
        int temp;
        dequeue(q, &temp); // 逐个出队并释放内存
    }
}
// 打印队列
void printQueue(Queue *q) {
    printf("Queue: ");
    for (Node *p = q->front; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}
// 测试
int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printQueue(&q); // Queue: 10 20 30
    int x;
    dequeue(&q, &x);
    printf("Dequeued: %d\n", x); // Dequeued: 10
    printQueue(&q); // Queue: 20 30
    destroyQueue(&q);
    return 0;
}