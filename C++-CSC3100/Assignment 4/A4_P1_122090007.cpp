//
// Created by Quan on 2024/12/6.
//
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

int n, m, q;

int minDistance(vector<int>& dist, vector<bool>& final) {
    int min_cost = INT32_MAX;
    int min_index = INT32_MAX;
    for (int i = 0; i < n; i++) {
        if (!final[i] and dist[i] < min_cost) {
            min_cost = dist[i];
            min_index = i;
        }
    }

    return min_index;
}


int dijkstra(int s, int t, vector<vector<int>>& adjacency_matrix) {
    vector<int> dist(n, INT32_MAX);
    vector<bool> final(n, false);
    vector<int> parent(n, -1);

    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, final);
        final[u] = true;

        for (int v = 0; v < n; v++) {
            if (adjacency_matrix[u][v] != INT32_MAX and dist[u] != INT32_MAX and !final[v] and dist[u] + adjacency_matrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjacency_matrix[u][v];
                parent[v] = u;
            }
        }
    }

    return dist[t];
}

int find_shortest_path(int s, int t, vector<vector<int>>& adjacency_matrix, vector<vector<int>>& required_path) {
    int result = 0;




    return dijkstra(s, t, adjacency_matrix);
}

int main() {
    cin >> n >> m >> q;

    vector<vector<int>> adjacency_matrix(n, vector<int>(n, INT32_MAX));

    for (int i = 0; i < n; i++) {
        adjacency_matrix[i][i] = 0;
    }

    vector<vector<int>> path_ei(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        path_ei[i].push_back(u);
        path_ei[i].push_back(v);
        adjacency_matrix[u - 1][v - 1] = w;
        adjacency_matrix[v - 1][u - 1] = w;
    }

    vector<vector<vector<int>>> required_path(q);
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