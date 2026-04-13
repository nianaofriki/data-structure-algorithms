// 栈 - 顺序存储（数组实现）
// 函数接口：
// void initStack(Stack *s);        // 初始化栈
// bool push(Stack *s, int x);      // 入栈，成功返回true
// bool pop(Stack *s, int *x);      // 出栈，元素存入*x，成功返回true
// bool top(Stack *s, int *x);      // 取栈顶元素（不出栈），成功返回true
// bool isEmpty(Stack *s);          // 判空，空返回true
// int getSize(Stack *s);           // 获取栈中元素个数
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;            // 栈顶指针（指向栈顶元素的位置，初始为-1）
} Stack;

void initStack(Stack *s) {
    s->top = -1;        // 初始化栈顶指针
}

// 判空
bool isEmpty(Stack *s) {
    return s->top == -1;
}
// 判满
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}
// 入栈
bool push(Stack *s, int x) {
    if (isFull(s)) {
        printf("栈已满，入栈失败！\n");
        return false;
    }
    s->data[++s->top] = x;
    return true;
}
// 出栈
bool pop(Stack *s, int *x) {
    if (isEmpty(s)) {
        printf("栈为空，出栈失败！\n");
        return false;
    }
    *x = s->data[s->top--];
    return true;
}
// 取栈顶元素
bool top(Stack *s, int *x) {
    if (isEmpty(s)) {
        printf("栈为空，无法获取栈顶元素！\n");
        return false;
    }
    *x = s->data[s->top];
    return true;
}
// 获取栈中元素个数
int getSize(Stack *s) {
    return s->top + 1;
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
    while (pop(&s, &x)) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;

}