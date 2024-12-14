//
// Created by Quan on 2024/12/13.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 插入操作：将元素插入到堆中
void heapInsert(vector<int>& heap, int value) {
    heap.push_back(value); // 将新值添加到堆尾
    int currentIndex = heap.size() - 1;
    int parentIndex = (currentIndex - 1) / 2;

    // 上滤操作：调整新值的位置以满足大根堆性质
    while (currentIndex > 0 && heap[currentIndex] > heap[parentIndex]) {
        swap(heap[currentIndex], heap[parentIndex]); // 交换当前节点和父节点
        currentIndex = parentIndex; // 更新当前节点索引为父节点索引
        parentIndex = (currentIndex - 1) / 2; // 计算新的父节点索引
    }
}

// 删除堆顶（最大值）操作
void heapDelete(vector<int>& heap) {
    if (heap.empty()) return;

    // 将堆尾元素移到堆顶
    heap[0] = heap.back();
    heap.pop_back(); // 删除最后一个元素

    int currentIndex = 0;
    int leftChild = 2 * currentIndex + 1;
    int rightChild = 2 * currentIndex + 2;

    // 下滤操作：调整堆顶以满足大根堆性质
    while (leftChild < heap.size()) {
        int largest = currentIndex;

        // 比较左右子节点，找出最大值
        if (heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        // 如果堆顶已满足堆性质，退出循环
        if (largest == currentIndex) break;

        swap(heap[currentIndex], heap[largest]); // 交换堆顶和最大子节点
        currentIndex = largest; // 更新当前节点索引
        leftChild = 2 * currentIndex + 1; // 重新计算左右子节点索引
        rightChild = 2 * currentIndex + 2;
    }
}

// 打印堆内容
void printHeap(const vector<int>& heap) {
    for (int value : heap) {
        cout << value << " ";
    }
    cout << endl;
}

// 示例代码
int main() {
    vector<int> maxHeap;

    // 插入元素
    heapInsert(maxHeap, 10);
    heapInsert(maxHeap, 20);
    heapInsert(maxHeap, 5);
    heapInsert(maxHeap, 15);
    heapInsert(maxHeap, 30);

    cout << "Heap after insertions: ";
    printHeap(maxHeap);

    // 删除堆顶
    heapDelete(maxHeap);
    cout << "Heap after deleting max: ";
    printHeap(maxHeap);

    return 0;
}
