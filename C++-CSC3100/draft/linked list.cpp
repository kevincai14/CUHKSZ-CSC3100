//
// Created by Quan on 2024/10/29.
//
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
    void show();
    void add(int i);
    void add(int i, int index);
};

void Node:: show() {
    Node* current = this;  // 使用指针遍历链表
    while (current != nullptr) {  // 当当前节点不为空时
        cout << current->data << " ";  // 打印当前节点的数据
        current = current->next;  // 移动到下一个节点
    }
    cout << endl;  // 打印换行符
}

void Node:: add(int i) {
    Node* current = this;  // 使用指针遍历链表
    while (current-> next != nullptr) {  // 当当前节点不为空时
        current = current->next;  // 移动到下一个节点
    }
    current->next = new Node(i);
}

void Node:: add(int index, int i) {
    Node* current = this;  // 使用指针遍历链表
    int result = 0;
    while (result != index) {  // 当当前节点不为空时
        current = current->next;
        result++;
    }
    Node* temp = current->next;
    current->next = new Node(i);
    current->next->next = temp;
}


int main() {
    Node* head = new Node(1);
    head->add(2);
    head->add(3);
    head->add(2,9);
//    cout << "Node data: " << a->next->data << endl;
    head->show();
}
