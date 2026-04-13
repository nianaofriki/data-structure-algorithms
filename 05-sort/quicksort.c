// 快速排序
// 函数接口：
//     void quickSort(int arr[], int low, int high);  // 快速排序
//     int partition(int arr[], int low, int high);   // 划分函数
//     void printArray(int arr[], int n);             // 打印数组
#include <stdio.h>
// 交换两个数值
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 划分函数
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准
    int i = low - 1; // i指向小于基准的最后一个元素
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // 如果当前元素小于基准
            i++; // 增加i
            swap(&arr[i], &arr[j]); // 将当前元素交换到小于基准的部分
        }
    }
    swap(&arr[i + 1], &arr[high]); // 将基准放到正确的位置
    return i + 1; // 返回基准的位置
}
// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 划分数组
        quickSort(arr, low, pi - 1); // 递归排序基准左边的子数组
        quickSort(arr, pi + 1, high); // 递归排序基准右边的子数组
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
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}