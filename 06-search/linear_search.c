// 顺序查找（线性查找）
// 函数接口：
//     int linearSearch(int arr[], int n, int target);  // 返回下标，未找到返回-1
//     int linearSearchSentinel(int arr[], int n, int target); // 哨兵优化版
#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
int linearSearchSentinel(int arr[], int n, int target) {
    int last = arr[n - 1];
    arr[n - 1] = target; // 设置哨兵
    int i = 0;
    while (arr[i] != target) {
        i++;
    }
    arr[n - 1] = last; // 恢复原数组
    if (i < n - 1 || arr[n - 1] == target) {
        return i;
    }
    return -1;
}
void printResult(int index, int target) {
    if (index != -1) {
        printf("元素 %d 的下标是: %d\n", target, index);
    } else {
        printf("元素 %d 未找到\n", target);
    }
}
int main() {
    int arr[] = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("无序数组: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");
    
    // 测试基础顺序查找
    printf("=== 基础顺序查找 ===\n");
    printResult(linearSearch(arr, n, 7), 7);
    printResult(linearSearch(arr, n, 10), 10);
    
    // 测试哨兵顺序查找（需要数组多一个位置，这里用原数组测试，注意最后一个元素会被覆盖，临时处理）
    // 为了演示，复制一个数组并增加一个元素作为哨兵位
    int arr2[10] = {5, 3, 8, 1, 9, 2, 7, 4, 6, 0}; // 多一个位置
    printf("\n=== 哨兵顺序查找 ===\n");
    printResult(linearSearchSentinel(arr2, 10, 7), 7);
    printResult(linearSearchSentinel(arr2, 10, 10), 10);
    
    return 0;
}