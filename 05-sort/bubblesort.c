// 冒泡排序
// 函数接口：
//     void bubbleSort(int arr[], int n);        // 冒泡排序
//     void bubbleSortOptimized(int arr[], int n); // 优化版（提前结束）
//     void printArray(int arr[], int n);        // 打印数组
#include <stdio.h>
// 交换两个数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 冒泡排序
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
// 优化版（提前结束）
void bubbleSortOptimized(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // 标记本轮是否有交换
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1; // 有交换，继续下一轮
            }
        }
        if (!swapped) {
            break; // 没有交换，数组已排序，提前结束
        }
    }
}
// 打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    bubbleSortOptimized(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}