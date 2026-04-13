// 顺序表
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INIT_SIZE 4
typedef int ElemType;

typedef struct {
    ElemType *data;//方便操作
    int length;
    int capacity;
} SqList;

// 扩容
static bool expand(SqList *L) {
    int newCap = L->capacity * 2;
    ElemType *p = (ElemType *)realloc(L->data, newCap *sizeof(ElemType));
    if (!p) return false;
    L->data = p;
    L->capacity = newCap;
    return true;
}
// 法二--便于解释原理（malloc）
// static bool expand(SqList *L) {
//     ElemType *newData = (ElemType *)malloc(sizeof(ElemType) * L->capacity * 2);
//     if (newData == NULL) {
//         return false;
//     }
//     for (int i = 0; i < L->length; i++) {
//         newData[i] = L->data[i];
//     }
//     free(L->data);
// }
// 初始化
void initList(SqList *L) {
    L->data = malloc(INIT_SIZE * sizeof(ElemType)); 
    if (!L->data) exit(-1);//防止失败，程序崩溃
    L->length = 0;
    L->capacity = INIT_SIZE;
}
// 销毁
void destroyList(SqList *L) {
    free(L->data);
    L->data = NULL;
    L->length = 0;
    L->capacity = 0;
}
// 插入
bool insert(SqList *L, int pos, ElemType value) {
    if (pos < 0 || pos > L->length) return false;//依旧优先考虑特殊情况
    if (L->length == L->capacity) {
        if (!expand(L)) return false;
    }//扩容失败
    for (int i = L->length - 1; i >= pos; i--) {
        L->data[i + 1] = L->data[i];
    }
    L->data[pos] = value;
    L->length++;
    return true;
}
// 删除
bool delete(SqList *L, int i, ElemType *e) {
    if (i < 0 || i >= L->length) return false;
    
    if (e) *e = L->data[i];  // 把被删的值传出去
    
    for (int j = i; j < L->length - 1; j++)
        L->data[j] = L->data[j+1];
    
    L->length--;
    return true;
}
// 法二
// bool delete(SqList *L, int pos) {   
//     if (pos < 0 || pos >= L->length) return false;
//     for (int i = pos; i < L->length - 1; i++) {
//         L->data[i] = L->data[i + 1];
//     }
//     L->length--;
//     return true;
// }
// 查找
int find(SqList *L, ElemType value) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == value) return i;
    }
    return -1;
}
// 遍历
void traverse(SqList *L, void (*f)(ElemType)) {
    for (int i = 0; i < L->length; i++)
        f(L->data[i]);
}
// 测试
void print(int e) { printf("%d ", e); }

int main() {
    SqList L;
    initList(&L);
    
    // 插入4个元素（初始容量为4，刚好够用）
    insert(&L, 0, 1);
    insert(&L, 1, 2);
    insert(&L, 2, 3);
    insert(&L, 3, 4);
    
    printf("初始: ");
    traverse(&L, print);
    printf("\n");
    
    // 再插入一个，自动扩容
    insert(&L, 4, 5);
    printf("插入5后: ");
    traverse(&L, print);
    printf("\n");
    
    delete(&L, 1,NULL);  // 删除元素2
    printf("删除索引1后: ");
    traverse(&L, print);
    printf("\n");
    
    int index = find(&L, 3);
    printf("元素3的位置: %d\n", index);
    
    destroyList(&L);
    return 0;
}