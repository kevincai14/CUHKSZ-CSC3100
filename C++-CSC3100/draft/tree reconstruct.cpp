//
// Created by Quan on 2024/12/15.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iomanip>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to recursively build the tree
TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                          vector<int>& postorder, int postStart, int postEnd,
                          unordered_map<int, int>& inorderIndexMap) {
    if (inStart > inEnd || postStart > postEnd)
        return nullptr;

    // The root value is the last element in the postorder range
    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    // Find the index of the root in the inorder traversal
    int rootIndex = inorderIndexMap[rootVal];

    // Calculate the size of the left subtree
    int leftTreeSize = rootIndex - inStart;

    // Recursively build the left and right subtrees
    root->left = buildTreeHelper(inorder, inStart, rootIndex - 1,
                                 postorder, postStart, postStart + leftTreeSize - 1, inorderIndexMap);
    root->right = buildTreeHelper(inorder, rootIndex + 1, inEnd,
                                  postorder, postStart + leftTreeSize, postEnd - 1, inorderIndexMap);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inorderIndexMap;

    // Create a hash map to store the indices of inorder elements
    for (int i = 0; i < inorder.size(); i++) {
        inorderIndexMap[inorder[i]] = i;
    }

    return buildTreeHelper(inorder, 0, inorder.size() - 1,
                           postorder, 0, postorder.size() - 1, inorderIndexMap);
}

// Helper function to print the tree in preorder for verification
void printTree(TreeNode* root) {
    if (!root) {
        cout << "树为空" << endl;
        return;
    }

    // 使用队列进行层次遍历
    queue<TreeNode*> q;
    q.push(root);

    int depth = 0; // 当前深度
    while (!q.empty()) {
        int size = q.size(); // 当前层的节点数
        cout << "深度 " << depth++ << ": ";

        while (size--) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                cout << setw(4) << node->val << " "; // 打印当前节点
                q.push(node->left);  // 将左子节点加入队列
                q.push(node->right); // 将右子节点加入队列
            } else {
                cout << setw(4) << "null"; // 打印空节点
            }
        }
        cout << endl;
    }
}

int main() {
    // Example input
    vector<int> inorder = {7,6,5,3,8,4,2,1};
    vector<int> postorder = {6,7,3,5,4,1,2,8};

    TreeNode* root = buildTree(inorder, postorder);


    printTree(root); // Expected output: 3 9 20 15 7

    return 0;
}
