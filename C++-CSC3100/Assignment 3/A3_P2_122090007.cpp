//
// Created by Quan on 2024/11/18.
//
#include <iostream>
#include <iomanip>
#include <unordered_set>
using namespace std;

int n, k, bag_size, circle_length;
double max_take_away_value = 0;

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

void connect_shelf(Node** hash_table) {
    for (int i = 0; i < k; i++) {
        Node* current = hash_table[i];
        while (current->next_node != nullptr) {
            current = current->next_node;
        }
        current->next_node = hash_table[(i + 1) % k];
    }

    Node* current = hash_table[0];
//    while (current->item_id == 0) {
//        current = current->next_node;
//    }
//    hash_table[0] = current;
    Node* mark = hash_table[0];
//    while (current->next_node != mark) {
//        if (current->item_id != 0 and current->next_node->item_id == 0 and current->next_node->next_node->item_id != 0) {
//            current->next_node = current->next_node->next_node;
//        }
//        current = current->next_node;
//    }

    current = hash_table[0];
    mark = hash_table[0];
    circle_length = 1;
    while (current->next_node != mark) {
        current = current->next_node;
        circle_length++;
    }
}

bool check_same(int arr[], int size) {
    unordered_set<int> seen;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            if (seen.find(arr[i]) != seen.end()) {
                return true;
            }
            seen.insert(arr[i]);
        }
    }
    return false;
}

double max_value(Node* start_node, int used_bag_size = bag_size) {
    if (bag_size == 0) {
        return 0;
    }
    used_bag_size = min(used_bag_size, n);

    Node* current = start_node;
    for (int i = 0; i < circle_length; i++) {
        double value = 0;
        Node* bag_node = current;

        int* shelf_count = new int[k]();
        for (int j = 0; j < used_bag_size; j++) {
            value += bag_node->value;
            shelf_count[bag_node->shelf_num]++;

            bag_node = bag_node->next_node;
        }
        if (check_same(shelf_count, k)) {
            value = 0;
        }
        delete[] shelf_count;
        current = current->next_node;
        max_take_away_value = max(max_take_away_value, value);
    }

    if (max_take_away_value == 0) {
        used_bag_size--;
        return max_value(start_node, used_bag_size);
    }

    return max_take_away_value;
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

void show(Node* shelf) {
    auto current = shelf;
    for (int i = 0; i < circle_length; i++) {
        cout << current->item_id << ' ';
        current = current->next_node;
    }
    cout << endl;
}

int main() {
    cin >> n >> k >> bag_size;

    int item_id;
    double value;
    Node** hash_table = new Node*[k];

    for (int i = 0; i < k; i++) {
        hash_table[i] = new Node(i, 0, 0);
    }
    for (int i = 0; i < n; i++) {
        cin >> item_id >> value;
        add_items(item_id, value, hash_table);
    }
    show(hash_table);
    connect_shelf(hash_table);
    show(hash_table[0]);

    double result = max_value(hash_table[0]);
    cout << fixed << setprecision(1) << result;

    for (int i = 0; i < k; i++) {
        delete hash_table[i];
    }
    delete[] hash_table;

    system("pause");
}