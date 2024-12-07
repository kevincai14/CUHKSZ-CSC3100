//
// Created by Quan on 2024/12/7.
//
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstdint>
using namespace std;

int n, m, s, t;

void dfs(int start, int end, vector<vector<pair<int, int>>>& adjacency_list, vector<int>& current_path, vector<bool>& visited, vector<vector<int>>& all_path) {
    current_path.push_back(start);
    visited[start] = true;

    if (start == end) {
        all_path.push_back(current_path);
    } else {
        for (auto neighbor : adjacency_list[start]) {
            int neighbor_node = neighbor.first;
            if (!visited[neighbor_node]) {
                dfs(neighbor_node, end, adjacency_list, current_path, visited, all_path);
            }
        }
    }
    current_path.pop_back();
    visited[start] = false;
}

int find_min_hp(int start, int end, vector<vector<pair<int, int>>>& adjacency_list) {
    vector<int> current_path;
    vector<bool> visited(n, false);
    vector<vector<int>> all_path;

    dfs(start, end, adjacency_list, current_path, visited, all_path);
//    for (auto i: all_path) {
//        for (auto j:i) {
//            cout << j+1 << " ";
//        }
//        cout << endl;
//    }
    int min_hp = INT32_MAX;
    for (auto path: all_path) {
        int hp = 0;
        int sp = 0;
        for (int i = 0; i < path.size() - 1; i++) {
            sp++;
            int a;
            for (auto pair: adjacency_list[path[i]]) {
                if (pair.first == path[i + 1]) {
                    a = pair.second;
                }
            }
            hp += a / sp;
        }
        min_hp = min(hp, min_hp);
    }

    return min_hp;
}

int main() {
    cin >> n >> m >> s >> t;

    vector<vector<pair<int, int>>> adjacency_list(n);
    for (int i = 0; i < m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        adjacency_list[u - 1].emplace_back(v - 1, a);
        adjacency_list[v - 1].emplace_back(u - 1, a);
    }

    cout << find_min_hp(t - 1, s - 1, adjacency_list);


}