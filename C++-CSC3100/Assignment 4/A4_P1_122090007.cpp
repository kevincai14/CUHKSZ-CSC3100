//
// Created by Quan on 2024/12/6.
//
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

int n, m, q;

vector<int> bellmanFord(int s, int t, vector<vector<int>>& adjacency_matrix) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (adjacency_matrix[u][v] != INT_MAX and dist[u] != INT_MAX and dist[u] + adjacency_matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjacency_matrix[u][v];
                    parent[v] = u;
                }
            }
        }
    }
//    cout <<"start";
//    for (auto i: parent) {
//        cout << i ;
//        cout<< endl;
//    }
//    cout << "end"<<endl;

//    for (int u = 0; u < n; ++u) {
//        for (int v = 0; v < n; ++v) {
//            if (adjacency_matrix[u][v] != INT_MAX && dist[u] != INT_MAX &&
//                dist[u] + adjacency_matrix[u][v] < dist[v]) {
//                throw runtime_error("Graph contains a negative weight cycle.");
//            }
//        }
//    }
    vector<int> path;
    int current = t;
    while (current != 0) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}


int find_shortest_path(int s, int t, vector<vector<int>>& adjacency_matrix, vector<pair<int, int>>& required_path) {
    vector<vector<int>> negative_edge = adjacency_matrix;
    for (auto i: required_path) {
        negative_edge[i.first - 1][i.second - 1] = -1000;
        negative_edge[i.second - 1][i.first - 1] = -1000;
    }
//    for (auto i: negative_edge) {
//        for (auto j: i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }


    vector<int> path = bellmanFord(s, t, negative_edge);

    int cost = 0;
    for (int i = 0; i < path.size(); i++) {
        if (i + 1 < path.size()) {
            cost += adjacency_matrix[path[i]][path[i + 1]];
        }
    }
//    for (auto i: path) {
//        cout << i+1 << " ";
//    }

    return cost;
}

int main() {
    cin >> n >> m >> q;

    vector<vector<int>> adjacency_matrix(n, vector<int>(n, INT32_MAX));

    for (int i = 0; i < n; i++) {
        adjacency_matrix[i][i] = 0;
    }

    vector<pair<int, int>> path_ei(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        path_ei[i] = {u, v};
        adjacency_matrix[u - 1][v - 1] = w;
        adjacency_matrix[v - 1][u - 1] = w;
    }

    vector<vector<pair<int, int>>> required_path(q);
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int ei;
            cin >> ei;
            required_path[i].push_back(path_ei[ei - 1]);
        }
    }

    vector<int> result;
    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        int shortest_time = find_shortest_path(s - 1, t - 1, adjacency_matrix, required_path[i]);
        result.push_back(shortest_time);
    }

    for (int i: result) {
        cout << i << endl;
    }
}