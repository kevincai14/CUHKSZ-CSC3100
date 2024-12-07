//
// Created by Quan on 2024/12/6.
//
#include <iostream>
#include <vector>
#include <tuple>
#include <cstdint>
#include <queue>
using namespace std;

int n, m, q;

int max_min_path(int s, int t, vector<vector<pair<int, int>>>& adjacency_list) {
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>> processing_node;
    processing_node.emplace(INT32_MAX, s);
    int global_max = 0;

    while (!processing_node.empty()) {
        pair<int, int> process_node = processing_node.top();
        int current_min = process_node.first;
        int current_node = process_node.second;
        processing_node.pop();

        if (visited[current_node]) {
            continue;
        }

        visited[current_node] = true;

        if (current_node == t) {
            global_max = max(current_min, global_max);
            return global_max;
        }

        for (auto neighbour : adjacency_list[current_node]) {
            int neighbor_node = neighbour.first;
            int weight = neighbour.second;

            if (!visited[neighbor_node]) {
                processing_node.emplace(min(current_min, weight), neighbor_node);
            }
        }
    }

    return global_max;
}

int main() {
    cin >> n >> m;

    vector<vector<pair<int, int>>> adjacency_list(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacency_list[u - 1].emplace_back(v - 1, w);
        adjacency_list[v - 1].emplace_back(u - 1, w);
    }

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
        result.push_back(max_min_cost);
    }

    for (int i: result) {
        cout << i << endl;
    }
}