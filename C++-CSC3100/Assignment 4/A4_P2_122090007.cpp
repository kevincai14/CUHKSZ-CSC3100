//
// Created by Quan on 2024/12/6.
//
#include <iostream>
#include <vector>
#include <tuple>
#include <cstdint>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, q;

void dfs(int s, int t, vector<vector<pair<int, int>>>& adjacency_list, vector<bool>& visited, int& global_max, int current_min) {
//    cout << current_min << endl;
    if (s == t) {
        global_max = max(global_max, current_min);
        return;
    }

    visited[s] = true;

    for (auto& neighbor : adjacency_list[s]) {
        int neighbor_node = neighbor.first;
        int weight = neighbor.second;

        if (weight <= global_max or current_min <= global_max) {
            continue;
        }

        if (!visited[neighbor_node]) {
            dfs(neighbor_node, t, adjacency_list, visited, global_max, min(current_min, weight));
        }
    }

    visited[s] = false;
}

int max_min_path(int s, int t, vector<vector<pair<int, int>>>& adjacency_list) {
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>> pq;
    pq.push({INT32_MAX, s});
    int global_max = 0;

    while (!pq.empty()) {
        auto [current_min, current_node] = pq.top();
        pq.pop();

        if (visited[current_node]) continue;
        visited[current_node] = true;

        if (current_node == t) {
            global_max = max(global_max, current_min);
            break;
        }

        for (const auto& neighbor : adjacency_list[current_node]) {
            int neighbor_node = neighbor.first;
            int weight = neighbor.second;

            if (!visited[neighbor_node]) {
                pq.push({min(current_min, weight), neighbor_node});
            }
        }
    }

    return global_max;
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

        int max_min_cost = max_min_path(s - 1, t - 1, adjacency_list);
//        int max_min_cost = 0;
        result.push_back(max_min_cost);
    }

    for (int i: result) {
        cout << i << endl;
    }
}