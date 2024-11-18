//
// Created by Quan on 2024/11/17.
//
#include <iostream>
using namespace std;

int max_hp = 0;

struct Node {
    int attack_power;
    Node* first_child;
    Node* next_sibling;

    Node(int attack_power = 0) : attack_power(attack_power), first_child(nullptr), next_sibling(nullptr) {}
};

void insert(Node** node_array, int u, int v, int w) {
    Node* current = node_array[u - 1];
    Node* insert_node = node_array[v - 1];
    insert_node->attack_power = w;

    if (current->first_child != nullptr) {
        current = current->first_child;
        while (current->next_sibling != nullptr) {
            current = current->next_sibling;
        }
        current->next_sibling = insert_node;
    } else {
        current->first_child = insert_node;
    }
}

void hp_count(Node* root, int mp = 0, int hp = 0) {
    if (root == nullptr) {
        return;
    }
    int hp_new = hp + max(0, root->attack_power - mp);
    max_hp = max(max_hp, hp_new);

    hp_count(root->first_child, mp + 1, hp_new);
    hp_count(root->next_sibling, mp, hp);
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    Node** node_array = new Node*[n];

    for (int i = 0; i < n; i++) {
        Node* node = new Node();
        node_array[i] = node;
    }
    Node* root = node_array[0];

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        insert(node_array, u, v, w);
    }
    hp_count(root);
    cout << max_hp;

    for (int i = 0; i < n; i++) {
        delete node_array[i];
    }
    delete[] node_array;

    system("pause");
}