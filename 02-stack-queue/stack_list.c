// 栈 - 链式存储（链表实现）
// 函数接口：
//     void initStack(Stack *s);        // 初始化栈
//     bool push(Stack *s, int x);      // 入栈
//     bool pop(Stack *s, int *x);      // 出栈
//     bool top(Stack *s, int *x);      // 取栈顶元素
//     bool isEmpty(Stack *s);          // 判空
//     int getSize(Stack *s);           // 获取栈大小
//     void destroyStack(Stack *s);     // 销毁栈

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 栈结点
typedef struct Node {
    int data;
    struct Node *next;
} Node;
// 栈结构（包含栈顶指针和元素个数）
typedef struct {
    Node *top;      // 栈顶指针
    int size;       // 元素个数
} Stack;
// 初始化栈
void initStack(Stack *s) {
    s->top = NULL;  // 栈顶指针初始化为NULL
    s->size = 0;     // 元素个数初始化为0
}
// 判空
bool isEmpty(Stack *s) {
    return s->size == 0;  // 栈大小为0表示栈空
}
// 入栈
bool push(Stack *s, int x) {
    Node *newNode = (Node *)malloc(sizeof(Node));  // 创建新结点
    if (!newNode) {
        printf("内存分配失败，入栈失败！\n");
        return false;
    }
    newNode->data = x;       // 设置结点数据
    newNode->next = s->top; // 新结点指向当前栈顶
    s->top = newNode;       // 更新栈顶指针
    s->size++;              // 栈大小加1
    return true;
}
// 出栈
bool pop(Stack *s, int *x) {
    if (isEmpty(s)) {
        printf("栈为空，出栈失败！\n");
        return false;
    }
    Node *temp = s->top;    // 临时指针指向当前栈顶
    *x = temp->data;       // 获取栈顶元素数据
    s->top = temp->next;   // 更新栈顶指针
    free(temp);            // 释放原栈顶结点内存
    s->size--;             // 栈大小减1
    return true;
}
// 取栈顶元素
bool top(Stack *s, int *x) {
    if (isEmpty(s)) {
        printf("栈为空，无法获取栈顶元素！\n");
        return false;
    }
    *x = s->top->data;     // 获取栈顶元素数据
    return true;
}
// 获取栈中元素个数
int getSize(Stack *s) {
    return s->size;        // 返回栈大小
}
// 销毁栈
void destroyStack(Stack *s) {
    Node *current = s->top; // 从栈顶开始销毁结点
    while (current) {
        Node *temp = current; // 临时指针指向当前结点
        current = current->next; // 移动到下一个结点
        free(temp); // 释放当前结点内存
    }
    s->top = NULL; // 栈顶指针置空
    s->size = 0;    // 栈大小重置为0
}
// 测试主函数
int main() {
    Stack s;
    initStack(&s);
    printf("栈是否为空：%s\n", isEmpty(&s) ? "是" : "否");
    printf("栈中元素个数：%d\n", getSize(&s));
    printf("入栈：1 2 3 4 5\n");
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    printf("出栈：");
    int x;
    while (!isEmpty(&s)) {
        pop(&s, &x);
        printf("%d ", x);
    }
    printf("\n");
    destroyStack(&s); // 销毁栈，释放内存
    return 0;
}
