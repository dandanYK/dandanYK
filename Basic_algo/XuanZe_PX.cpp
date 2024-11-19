//
// Created by 黄展博 on 2024/11/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sort(vector<int>& nums) {
    int n = nums.size();
    // sortedIndex 是一个分割线
    // 索引 < sortedIndex 的元素都是已排序的
    // 索引 >= sortedIndex 的元素都是未排序的
    // 初始化为 0，表示整个数组都是未排序的
    int sortedIndex = 0;
    while (sortedIndex < n) {
        // 找到未排序部分 [sortedIndex, n) 中的最小值
        int minIndex = sortedIndex;
        for (int i = sortedIndex + 1; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
        }
        // 交换最小值和 sortedIndex 处的元素
        if (minIndex != sortedIndex) {
            swap(nums[sortedIndex], nums[minIndex]);
        }

        // sortedIndex 后移一位
        sortedIndex++;
    }
}

int main() {
    std::vector<int> nums = {5, 2, 8, 3, 9, 1};
    sort(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
