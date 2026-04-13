// 单链表 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
// 初始化
bool initList(LinkList *L) {
    *L = (LNode *)malloc(sizeof(LNode));
    if (!*L) return false;   // 返回错误，不 exit
    (*L)->next = NULL;
    return true;
}
// void initList(LinkList *L) {
//     *L = (LinkList)malloc(sizeof(LNode));
//     if (!*L) exit(-1);
//     (*L)->next = NULL;
// }失败直接退出版本，灵活性不高
// 头插法
bool insertHead(LinkList L, ElemType e) {
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (!s) return false;
    s->data = e;
    s->next = L->next;
    L->next = s;
    return true;
}

// 尾插法
bool insertTail(LinkList L, ElemType e) {
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (!s) return false;
    s->data = e;
    s->next = NULL;
    
    LNode *p = L;
    while (p->next) p = p->next;
    p->next = s;
    return true;
}
// 按位序插入
bool insert(LinkList L, int pos, ElemType e) {
    if (pos < 0) return false;
    
    LNode *p = L;
    for (int i = 0; i < pos && p; i++)
        p = p->next;
    
    if (!p) return false;  // pos 超出范围
    
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (!s) return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
// 删除
bool delete(LinkList L, int pos, ElemType *e) {
    if (pos < 0) return false;
    
    LNode *p = L;
    for (int i = 0; i < pos && p->next; i++)
        p = p->next;
    
    if (!p->next) return false;  // pos 超出范围
    
    LNode *q = p->next;
    if (e) *e = q->data;  // 把被删的值传出去
    p->next = q->next;
    free(q);
    return true;
}
// 查找
int find(LinkList L, ElemType e) {
    LNode *p = L->next;
    int i = 0;
    while (p && p->data != e) {
        p = p->next;
        i++;
    }
    if (!p) return -1;  // 未找到
    return i;
}
// 获取第 i 个节点的值
bool getElem(LinkList L, int pos, ElemType *e) {
    if (pos < 0) return false;
    
    LNode *p = L;
    for (int i = 0; i < pos && p->next; i++)
        p = p->next;
    
    if (!p->next) return false;  // pos 超出范围
    
    if (e) *e = p->next->data;
    return true;
}
// 遍历
void traverse(LinkList L, void (*f)(ElemType)) {
    LNode *p = L->next;     // 跳过头结点，从第一个节点开始
    while (p) {
        f(p->data);
        p = p->next;
    }
}
// 销毁
void destroyList(LinkList *L) {
    LNode *p = (*L)->next; // 跳过头结点
    while (p) {
        LNode *q = p->next;
        free(p);
        p = q;
    }
    free(*L);  // 释放头结点
    *L = NULL;
}
// 求表长
int length(LinkList L) {
    int len = 0;
    LNode *p = L->next;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}
// 测试
void print(int e) { printf("%d ", e); }
int main() {
    LinkList L;
    initList(&L);
    
    insertTail(L, 1);
    insertTail(L, 2);
    insertTail(L, 3);
    
    traverse(L, print); // 输出: 1 2 3
    printf("\nLength: %d\n", length(L)); // 输出: Length: 3
    
    ElemType e;
    delete(L, 1, &e); // 删除第 1 个元素，e = 2
    printf("Deleted: %d\n", e); // 输出: Deleted: 2
    
    traverse(L, print); // 输出: 1 3
    printf("\n");
    
    destroyList(&L);
    return 0;
}