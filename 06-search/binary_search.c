// 二分查找（折半查找）
// 函数接口：
//     int binarySearch(int arr[], int n, int target);  // 返回下标，未找到返回 -1
//     int binarySearchRecursive(int arr[], int left, int right, int target); // 递归版
#include <stdio.h>
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // 防止溢出
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2; // 防止溢出
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, right, target);
    } else {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
}
void printResult(int index, int target) {
    if (index != -1) {
        printf("元素 %d 的下标是: %d\n", target, index);
    } else {
        printf("元素 %d 未找到\n", target);
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // 二分查找需要有序数组
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("有序数组: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");
    
    // 测试基础二分查找
    printf("=== 基础二分查找 ===\n");
    printResult(binarySearch(arr, n, 7), 7);
    printResult(binarySearch(arr, n, 10), 10);
    
    // 测试递归二分查找
    printf("\n=== 递归二分查找 ===\n");
    printResult(binarySearchRecursive(arr, 0, n - 1, 7), 7);
    printResult(binarySearchRecursive(arr, 0, n - 1, 10), 10);
    
    return 0;
}