#include <iostream>
#include <vector>
#include <climits> // 包含 INT32_MAX
using namespace std;

// 深度优先搜索函数
vector<vector<int>> dfs(int s, int t, vector<vector<int>>& adjacency_matrix, vector<int>& current_path, vector<bool>& visited) {
    vector<vector<int>> all_path;  // 当前递归层的所有路径
    current_path.push_back(s);     // 添加当前节点到路径
    visited[s] = true;             // 标记当前节点为已访问

    if (s == t) {
        // 如果到达目标点，保存当前路径
        all_path.push_back(current_path);
    } else {
        // 遍历邻接矩阵中的所有可能邻居
        for (int neighbor = 0; neighbor < adjacency_matrix[s].size(); ++neighbor) {
            if (adjacency_matrix[s][neighbor] != INT32_MAX && !visited[neighbor]) {
                // 如果存在有效路径且该邻居未被访问，递归搜索
                vector<vector<int>> sub_paths = dfs(neighbor, t, adjacency_matrix, current_path, visited);
                all_path.insert(all_path.end(), sub_paths.begin(), sub_paths.end());
            }
        }
    }

    current_path.pop_back();  // 回溯，移除当前节点
    visited[s] = false;       // 恢复当前节点的访问状态
    return all_path;
}

int main() {
    int q = INT32_MAX; // 定义无穷大值
    vector<vector<int>> adjacency_matrix = {
            {q, 2, 3, 6, q},  // 节点 0 的邻居
            {2, q, 1, q, 1},  // 节点 1 的邻居
            {3, 1, q, 4, 1},  // 节点 2 的邻居
            {6, q, 4, q, 1},
            {q, 1, 1, 1 , q}// 节点 3 的邻// 节点 4 的邻居
    };

    int start = 0, end = 3;  // 起点和终点
    vector<int> current_path; // 用于存储当前路径
    vector<bool> visited(adjacency_matrix.size(), false); // 记录节点访问状态

    // 获取所有从 start 到 end 的路径
    vector<vector<int>> all_paths = dfs(start, end, adjacency_matrix, current_path, visited);

    // 输出所有路径
    cout << "所有路径：" << endl;
    if (all_paths.empty()) {
        cout << "无路径！" << endl;
    } else {
        for (const auto& path : all_paths) {
            for (int node : path) {
                cout << node+1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
