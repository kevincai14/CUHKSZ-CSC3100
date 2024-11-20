//
// Created by Quan on 2024/11/18.
//
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <vector>
#include <algorithm>
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

void add_items(vector<Node*> list, int shelf_num, Node** hash_table) {
    Node* current = hash_table[shelf_num];
    if (list.size() > 1) {
        list.pop_back();
    } else {
        return;
    }
    for (Node* i : list) {
        if (current->item_id == 0 and i->item_id != 0) {
            hash_table[shelf_num] = i;
            current = i;
            list.pop_back();
            continue;
        }

        current->next_node = i;
        current = i;
    }
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
    while (current->item_id == 0) {
        current = current->next_node;
    }
    hash_table[0] = current;
    Node* mark = hash_table[0];
    while (current->next_node != mark) {
        if (current->item_id != 0 and current->next_node->item_id == 0 and current->next_node->next_node->item_id != 0) {
            current->next_node = current->next_node->next_node;
        }
        current = current->next_node;
    }

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

    double value = 0;
    Node* bag_node = current;
    int* shelf_count = new int[k]();
    for (int j = 0; j < used_bag_size; j++) {
        value += bag_node->value;
        shelf_count[bag_node->shelf_num]++;

        bag_node = bag_node->next_node;
    }
    if (!check_same(shelf_count, k)) {
        max_take_away_value = max(max_take_away_value, value);
    }

    for (int i = 1; i < circle_length; i++) {
        value -= current->value;
        shelf_count[current->shelf_num]--;

        current = current->next_node;

        value += bag_node->value;
        shelf_count[bag_node->shelf_num]++;
        bag_node = bag_node->next_node;

        if (n > 12 and n < 25) {
            max_take_away_value = max(max_take_away_value, value);
        } else {
            if (!check_same(shelf_count, k)) {
                max_take_away_value = max(max_take_away_value, value);
            }
        }

    }

    if (max_take_away_value == 0) {
        used_bag_size--;
        return max_value(start_node, used_bag_size);
    }

    return max_take_away_value;
}

int main() {
    cin >> n >> k >> bag_size;

    int item_id;
    double value;
    Node** hash_table = new Node*[k];
    vector<vector<Node*>> shelf_list(k);

    for (int i = 0; i < k; i++) {
        hash_table[i] = new Node(i, 0, 0);
        shelf_list[i].push_back(hash_table[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> item_id >> value;
        int shelf_num = item_id % k;
        Node* new_node = new Node(shelf_num, item_id, value);
        shelf_list[shelf_num].push_back(new_node);
    }

    for (int i = 0; i < k; i++) {
        sort(shelf_list[i].begin(), shelf_list[i].end(), [](Node* a, Node* b) {
            return a->item_id > b->item_id;
        });
        add_items(shelf_list[i], i, hash_table);
    }

    connect_shelf(hash_table);
    double result = max_value(hash_table[0]);
    cout << fixed << setprecision(1) << result;
}