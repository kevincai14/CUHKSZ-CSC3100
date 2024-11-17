//
// Created by Quan on 2024/11/17.
//
#include <iostream>
using namespace std;

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
    }

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

void printTree(Node* node, int level = 0) {
    if (node == nullptr) return;
    cout << string(level * 4, ' ') << "Node " << node->node_num << ", Attack Power: " << node->attack_power << endl;
    printTree(node->first_child, level + 1);
    printTree(node->next_sibling, level);
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    Node* root = new Node(t);

    delete root;
    system("pause");
}