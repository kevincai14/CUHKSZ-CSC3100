//
// Created by Quan on 2024/12/6.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 定义 AVL 树节点
struct AVLNode {
    int value;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

// 获取节点高度
int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

// 计算平衡因子
int getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// 右旋
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// 左旋
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// 插入节点并保持平衡
AVLNode* insert(AVLNode* node, int value) {
    if (!node) return new AVLNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // 左左
    if (balance > 1 && value < node->left->value)
        return rightRotate(node);

    // 右右
    if (balance < -1 && value > node->right->value)
        return leftRotate(node);

    // 左右
    if (balance > 1 && value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // 右左
    if (balance < -1 && value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// 中序遍历打印
void inorderTraversal(AVLNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

// 打印树（水平结构）
void printTree(AVLNode* root, int space = 0, int levelSpace = 5) {
    if (!root) return;

    // 增加间距（每层缩进）
    space += levelSpace;

    // 打印右子树
    printTree(root->right, space);

    // 打印当前节点
    cout << endl;
    for (int i = levelSpace; i < space; i++) cout << " ";
    cout << root->value << "\n";

    // 打印左子树
    printTree(root->left, space);
}



int main() {
    AVLNode* root = nullptr;

    int values[] = {11,7,14,5,9,12,17,16,19};
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "中序遍历结果: ";
    inorderTraversal(root);
    cout << endl;

    cout << "\nAVL树结构: \n";
    printTree(root); // 调用打印树的函数
    cout << endl;
    root = insert(root, 27);
    printTree(root); // 调用打印树的函数
    return 0;
}



