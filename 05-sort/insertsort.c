// 插入排序
// 原理：将未排序元素插入到已排序序列的合适位置
// 时间复杂度：最好 O(n)，最坏 O(n²)，平均 O(n²)
// 空间复杂度：O(1)
// 稳定性：稳定
// 类比：打扑克牌时，把新抓的牌插入到手中已排好序的牌中
#include <stdio.h>
void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // 当前要插入的元素
        int j = i - 1;   // 已排序部分的最后一个元素索引
        // 将大于 key 的元素向右移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // 插入 key 到正确位置
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    insertSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}