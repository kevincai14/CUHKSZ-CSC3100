//
// Created by Quan on 2024/12/6.
//
#include <iostream>
#include <vector>
#include <tuple>
#include <cstdint>
using namespace std;

int n, m, q;

vector<vector<int>> dfs(int s, int t, vector<vector<int>>& adjacency_matrix, vector<int>& current_path, vector<bool>& visited) {
    vector<vector<int>> all_path;
    current_path.push_back(s);
    visited[s] = true;

    if (s == t) {
        all_path.push_back(current_path);
    } else {
        for (int neighbor = 0; neighbor < adjacency_matrix[s].size(); ++neighbor) {
            if (adjacency_matrix[s][neighbor] != INT32_MAX && !visited[neighbor]) {
                vector<vector<int>> sub_paths = dfs(neighbor, t, adjacency_matrix, current_path, visited);
                all_path.insert(all_path.end(), sub_paths.begin(), sub_paths.end());
            }
        }
    }

    current_path.pop_back();
    visited[s] = false;
    return all_path;
}

int max_min_path(int s, int t, vector<vector<int>>& adjacency_matrix) {
    vector<int> current_path;
    vector<bool> visited(n, false);
    vector<vector<int>> all_path = dfs(s, t, adjacency_matrix, current_path, visited);
//    for (auto i: all_path) {
//        for (auto j :i) {
//            cout << j+1 << " ";
//        }
//        cout << "end" <<endl;
//    }
//    for (auto i:adjacency_matrix) {
//        for (auto j: i) {
//            if (j == INT32_MAX) {
//                cout << "q" << " ";
//            } else {
//                cout << j << " ";
//            }
//        }
//        cout << endl;
//    }
//    cout << endl;

    int temp_max = 0;
    for (auto path: all_path) {
        int temp_min = INT32_MAX;
        for (int j = 0; j < path.size(); j++) {
            if (j + 1 < path.size()) {
                temp_min = min(temp_min, adjacency_matrix[path[j]][path[j + 1]]);
            }
        }
        temp_max = max(temp_max, temp_min);
    }
    return temp_max;
}

int main() {
    cin >> n >> m;
    vector<vector<int>> adjacency_matrix(n, vector<int>(n, INT32_MAX));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacency_matrix[u - 1][v - 1] = w;
        adjacency_matrix[v - 1][u - 1] = w;
    }
//    for (auto i: adjacency_matrix) {
//        for (auto j: i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }

    cin >> q;
    vector<vector<tuple<int, int, int>>> change_edge(q);
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        vector<tuple<int, int, int>> change_edge_temp(k);
        for (int j = 0; j < k; j++) {
            int u, v, w;
            cin >> u >> v >> w;
            change_edge_temp[j] = make_tuple(u, v, w);
        }
        change_edge[i] = change_edge_temp;
    }

    vector<vector<int>> start_end;
    for (int i = 0; i < q + 1; i++) {
        int s, t;
        cin >> s >> t;
        start_end.push_back({s, t});
    }
//    for (auto i: start_end) {
//        cout << i[0] << i[1];
//        cout << endl;
//    }

    vector<int> result;
    for (int i = 0; i < q + 1; i++) {
        int s = start_end[i][0];

        int t = start_end[i][1];
        if (i != 0) {
            for (auto j: change_edge[i - 1]) {
                int u = get<0>(j);
                int v = get<1>(j);
                int w = get<2>(j);
//                cout << w << endl;
//                cout << endl;
                if (u <= n and u>=1 and v >= 1 and v <= n and w >=0) {
                    if (adjacency_matrix[u - 1][v - 1] != INT32_MAX) {
                        adjacency_matrix[u - 1][v - 1] = w;
                        adjacency_matrix[v - 1][u - 1] = w;
                    }
                }
            }
        }
//        for (auto k:adjacency_matrix) {
//            for (auto j: k) {
//                if (j == INT32_MAX) {
//                    cout << "q" << " ";
//                } else {
//                    cout << j << " ";
//                }
//            }
//            cout << endl;
//        }
//        cout << endl;
        int max_min_cost = max_min_path(s - 1, t - 1, adjacency_matrix);
        result.push_back(max_min_cost);
    }

    for (int i: result) {
        cout << i << endl;
    }
}