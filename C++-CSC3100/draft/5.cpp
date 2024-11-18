//
// Created by Quan on 2024/11/18.
//
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
        new_node->next_node = current->next_node;
        current->next_node = new_node;

    } else {
        hash_table[shelf_num] = new_node;
        new_node->next_node = current;
    }
}