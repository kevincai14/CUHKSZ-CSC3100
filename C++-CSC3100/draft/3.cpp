//
// Created by Quan on 2024/9/21.
//
#include <iostream>
#include <unordered_map>
using namespace std;

// 判断是否是有效排列的函数
int isValidPermutation(int* array, int* left, int* right, int n, int q) {
    // 用于存储每个元素在排列中的位置
    unordered_map<int, int> pos;
    for (int i = 0; i < n; ++i) {
        pos[array[i]] = i;  // 记录每个元素的位置
    }

    // 初始化当前的区间为整个数组
    int current_left = 0, current_right = n - 1;

    // 从后往前验证每一步操作
    for (int i = q - 1; i >= 0; --i) {
        int l = left[i];  // 当前操作的 l_i
        int r = right[i]; // 当前操作的 r_i

        // 获取 l 和 r 在排列中的位置
        int l_pos = pos[l];
        int r_pos = pos[r];

        // 如果 l 不在 r 左边，返回 false
        if (l_pos >= r_pos) {
            return 0;
        }

        // 更新当前区间（可以认为左、右边界进行了拆分并合并）
        current_left = l_pos;   // 更新左边界
        current_right = r_pos;  // 更新右边界
    }

    // 所有操作都成功，返回 true
    return 1;
}

int main() {
    int n, q;
    cin >> n >> q;

    // 动态分配数组
    int* array = new int[n];
    int* left = new int[q];
    int* right = new int[q];

    // 输入排列
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // 输入 left 和 right 数组
    for (int i = 0; i < q; i++) {
        cin >> left[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> right[i];
    }

    // 调用函数验证排列
    int result = isValidPermutation(array, left, right, n, q);
    cout << result << endl;

    // 释放动态分配的内存
    delete[] array;
    delete[] left;
    delete[] right;

    return 0;
}
