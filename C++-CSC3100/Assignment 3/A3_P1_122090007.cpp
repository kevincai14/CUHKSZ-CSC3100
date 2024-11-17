//
// Created by Quan on 2024/11/17.
//
#include <iostream>
#include <algorithm>
using namespace std;

int max_hp = 0;

struct Node {
    int node_num;
    int attack_power;
    Node* first_child;
    Node* next_sibling;

    Node(int node_num, int attack_power = 0) : node_num(node_num), attack_power(attack_power), first_child(nullptr), next_sibling(nullptr) {}
};

Node* search(Node* root, int node_num) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->node_num == node_num) {
        return root;
    }

    Node* next = search(root->first_child, node_num);
    if (next != nullptr) {
        return next;
    }

    return search(root->next_sibling, node_num);
}

void insert(Node* root, int u, int v, int w) {
    Node* current = search(root, u);
    Node* insert_node = new Node(v, w);
    if (current == nullptr) {
        current = search(root, v);
        insert_node = new Node(u, w);
        return;
    }//porblem!!!!!!!!!!!!!!!!!!!!!!!

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
    max_hp = max(hp_new, max_hp);

    hp_count(root->first_child, mp + 1, hp_new);
    hp_count(root->next_sibling, mp, hp);
}

int find_min_hp(Node* root) {
    hp_count(root);
    return max_hp;
}

//void printTree(Node* node, int level = 0) {
//    if (node == nullptr) return;
//    cout << string(level * 4, ' ') << "Node " << node->node_num << ", Attack Power: " << node->attack_power << endl;
//    printTree(node->first_child, level + 1);
//    printTree(node->next_sibling, level);
//}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    Node* root = new Node(t);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        insert(root, u, v, w);
    }
//    printTree(root);
    cout << find_min_hp(root);

    delete root;
    system("pause");
}