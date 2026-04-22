// 选择排序
// 原理：每轮选择最小元素放到已排序末尾
// 时间复杂度：O(n²)
// 空间复杂度：O(1)
// 稳定性：不稳定（例如 [5, 8, 5, 2] 会改变两个5的相对顺序）
// 类比：每次从剩余元素中挑最小的拿出来
#include <stdio.h>
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // 假设当前元素是最小的
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // 更新最小元素索引
            }
        }
        // 交换最小元素和当前元素
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}