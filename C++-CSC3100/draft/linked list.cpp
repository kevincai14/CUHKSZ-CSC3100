//
// Created by Quan on 2024/10/29.
//
#include <iostream>
#include <vector>
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

bool check_cycle(Node* list1, Node* list2) {
    vector<Node*> result;
    Node* current1 = list1;
    Node* current2 = list2;
    while (current1 != nullptr) {
        result.push_back(current1);
        current1 = current1->next;
    }
    while (current2 != nullptr) {
        for (Node* i: result) {
            if (current2 == i) {
                return true;
            }
        }
        current2 = current2->next;
    }
    return false;
}


int main() {
    Node* head = new Node(1);
    head->add(2);
    head->add(3);
    head->add(2,9);

    Node * current = head->next->next->next;
    Node* head2 = new Node(1);
    head2->add(3);
    head2->add(3);
    head2->next->next->next = current;
    head2->show();

    cout << check_cycle(head, head2);
}
