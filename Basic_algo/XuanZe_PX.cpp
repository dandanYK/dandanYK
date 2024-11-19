#include <iostream>

using namespace std;

// 选择排序函数
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    // 定义一个静态数组并初始化
    int arr[] = {5, 2, 8, 3, 9, 1};
    // 计算数组的大小
    int n = sizeof(arr) / sizeof(arr[0]);
    // 调用排序函数
    sort(arr, n);

    // 输出排序后的数组
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
