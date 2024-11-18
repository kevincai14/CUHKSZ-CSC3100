//
// Created by Quan on 2024/11/18.
//
#include <iostream>
using namespace std;

int n, k, bag_size;

struct Node {
    int shelf_num;
    int item_id;
    double value;
    Node* next_node;

    Node(int shelf_num, int item_id, double value) : shelf_num(shelf_num), item_id(item_id), value(value), next_node(nullptr) {}
};

void add_items(int item_id, double value, Node** hash_table) {
    int shelf_num = item_id % k;
    Node* new_node = new Node(shelf_num, item_id, value);
    Node* current = hash_table[shelf_num];

    if (current->item_id > item_id) {
        while (current->next_node->value > item_id) {
            if (current->next_node->next_node != nullptr) {
                current = current->next_node;
            }
        }
        Node* temp = current->next_node;
        current->next_node = new_node;
        new_node->next_node = temp;
    } else {
        hash_table[shelf_num] = new_node;
        new_node->next_node = current;
    }
}

void show(Node** hash_table) {
    for (int i = 0; i < k; i++) {
        auto current = hash_table[i];
        while (current->next_node != nullptr) {
            cout << current->item_id << ' ';
            current = current->next_node;
        }
        cout << current->item_id << ' ';
        cout << endl;
    }
}

int main() {
    cin >> n >> k >> bag_size;

    int item_id;
    double value;
    Node** hash_table = new Node*[n];

    for (int i = 0; i < k; i++) {
        hash_table[i] = new Node(0, 0, 0);
    }
    for (int i = 0; i < n; i++) {
        cin >> item_id >> value;
        add_items(item_id, value, hash_table);
    }
    show(hash_table);
    for (int i = 0; i < n; i++) {
        delete hash_table[i];
    }
    delete[] hash_table;

    system("pause");
}