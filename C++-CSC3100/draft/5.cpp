//
// Created by Quan on 2024/11/18.
//
#include <iostream>
#include <iomanip>
#include <unordered_set>
using namespace std;

void add_items(int item_id, double value, Node** hash_table) {
    int shelf_num = item_id % k;
    Node* new_node = new Node(shelf_num, item_id, value);
    Node* current = hash_table[shelf_num];

    if (current->item_id < item_id) {
        if (current->item_id == 0) {
            hash_table[shelf_num] = new_node;
            return;
        }
        new_node->next_node = current;
        hash_table[shelf_num] = new_node;
        return;
    }

    while (current->next_node != nullptr and current->next_node->item_id > item_id) {
        current = current->next_node;
    }

    new_node->next_node = current->next_node;
    current->next_node = new_node;
}