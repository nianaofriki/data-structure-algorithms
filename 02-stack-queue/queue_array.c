// 队列 - 顺序存储（数组实现，循环队列）
// 函数接口：
//     void initQueue(Queue *q);        // 初始化队列
//     bool enqueue(Queue *q, int x);   // 入队，成功返回true
//     bool dequeue(Queue *q, int *x);  // 出队，元素存入*x，成功返回true
//     bool isEmpty(Queue *q);          // 判空
//     bool isFull(Queue *q);           // 判满
//     int getSize(Queue *q);           // 获取队列长度
//     void printQueue(Queue *q);       // 打印队列（测试用）
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;
// 初始化队列
void initQueue(Queue *q) {
    q->front = q->rear = 0;
}
//判空
bool isEmpty(Queue *q) {
    return q->front == q->rear;
}
//判满
bool isFull(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}
//入队
bool enqueue(Queue *q, int x) {
    if (isFull(q)) return false; // 队满
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAX_SIZE; // 循环移动rear
    return true;
}
//出队
bool dequeue(Queue *q, int *x) {
    if (isEmpty(q)) return false; // 队空
    *x = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE; // 循环移动front
    return true;
}
//获取队列长度
int getSize(Queue *q) {
    return (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
}
//打印队列（测试用）
void printQueue(Queue *q) {
    printf("Queue: ");
    for (int i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->data[i]);
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
    printf("Queue size: %d\n", getSize(&q)); // Queue size: 2
    return 0;
}