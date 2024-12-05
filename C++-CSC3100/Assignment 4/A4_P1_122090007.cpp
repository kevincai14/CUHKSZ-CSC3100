//
// Created by Quan on 2024/12/6.
//
#include <iostream>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    int adjacency_matrix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjacency_matrix[i][j] = INT32_MAX;
            if (i == j) {
                adjacency_matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacency_matrix[u - 1][v - 1] = w;
        adjacency_matrix[w - 1][u - 1] = w;
    }

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        for (int j = 0; j++)
    }
}