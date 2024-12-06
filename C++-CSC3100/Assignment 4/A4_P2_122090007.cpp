//
// Created by Quan on 2024/12/6.
//
#include <iostream>
#include <vector>
#include <tuple>
#include <cstdint>
using namespace std;

int n, m, q;

void dfs(int s, int t, vector<vector<pair<int, int>>>& adjacency_list, vector<int>& current_path, vector<bool>& visited, vector<vector<int>>& all_path) {
    current_path.push_back(s);
    visited[s] = true;

    if (s == t) {
        all_path.push_back(current_path);
    } else {
        for (auto& neighbor : adjacency_list[s]) {
            int neighbor_node = neighbor.first;
            if (!visited[neighbor_node]) {
                dfs(neighbor_node, t, adjacency_list, current_path, visited, all_path);
            }
        }
    }

    current_path.pop_back();
    visited[s] = false;
}

int max_min_path(int s, int t, vector<vector<pair<int, int>>>& adjacency_list) {
    vector<int> current_path;
    vector<bool> visited(n, false);
    vector<vector<int>> all_path;
    dfs(s, t, adjacency_list, current_path, visited, all_path);

    int temp_max = 0;
    for (auto path: all_path) {
        int temp_min = INT32_MAX;
        for (int j = 0; j < path.size() - 1; j++) {
            int u = path[j];
            int v = path[j + 1];

            int edge_weight = INT32_MAX;
            for (auto& neighbor : adjacency_list[u]) {
                if (neighbor.first == v) {
                    edge_weight = neighbor.second;
                    break;
                }
            }
            temp_min = min(edge_weight, temp_min);
        }
        temp_max = max(temp_max, temp_min);
    }
    return temp_max;
}

int main() {
    cin >> n >> m;
    if (n <= 0 or m <= 0) {
        cout << 0;
        return 0;
    }

    vector<vector<pair<int, int>>> adjacency_list(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacency_list[u - 1].push_back({v - 1, w});
        adjacency_list[v - 1].push_back({u - 1, w});
    }

    cin >> q;
    vector<vector<tuple<int, int, int>>> change_edge;
    if (q > 0) {
        vector<vector<tuple<int, int, int>>> change_edge_in_if(q);
        for (int i = 0; i < q; i++) {
            int k;
            cin >> k;
            vector<tuple<int, int, int>> change_edge_temp(k);
            for (int j = 0; j < k; j++) {
                int u, v, w;
                cin >> u >> v >> w;
                change_edge_temp[j] = make_tuple(u, v, w);
            }
            change_edge_in_if[i] = change_edge_temp;
        }
        change_edge = change_edge_in_if;
    }

    vector<vector<int>> start_end;
    for (int i = 0; i < q + 1; i++) {
        int s, t;
        cin >> s >> t;
        start_end.push_back({s, t});
    }

    vector<int> result;
    for (int i = 0; i < q + 1; i++) {
        int s = start_end[i][0];
        int t = start_end[i][1];

        if (i != 0) {
            for (auto j: change_edge[i - 1]) {
                int u = get<0>(j);
                int v = get<1>(j);
                int w = get<2>(j);
                if (u >= 1 and u <= n and v >= 1 and v <= n and w >= 0) {
                    u--;
                    v--;
                    for (auto& neighbor : adjacency_list[u]) {
                        if (neighbor.first == v) {
                            neighbor.second = w;
                            break;
                        }
                    }
                    for (auto& neighbor : adjacency_list[v]) {
                        if (neighbor.first == u) {
                            neighbor.second = w;
                            break;
                        }
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
        int max_min_cost = max_min_path(s - 1, t - 1, adjacency_list);
//        int max_min_cost = 0;
        result.push_back(max_min_cost);
    }

    for (int i: result) {
        cout << i << endl;
    }
}