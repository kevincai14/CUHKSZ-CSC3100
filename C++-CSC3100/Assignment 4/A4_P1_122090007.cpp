//
// Created by Quan on 2024/12/6.
//
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, q;

vector<vector<int>> generatePairPermutations(pair<int, int> p) {
    vector<vector<int>> permutations;
    permutations.push_back({p.first, p.second});
    permutations.push_back({p.second, p.first});
    return permutations;
}

void combinePaths(const vector<vector<vector<int>>>& paths, vector<vector<int>>& results, vector<int> current, int index) {
    if (index == paths.size()) {
        results.push_back(current);
        return;
    }
    for (const auto& path : paths[index]) {
        vector<int> newPath = current;
        newPath.insert(newPath.end(), path.begin(), path.end());
        combinePaths(paths, results, newPath, index + 1);
    }
}

vector<vector<int>> generateAllPaths(vector<pair<int, int>> pairs) {
    vector<vector<int>> results;

    sort(pairs.begin(), pairs.end());
    do {
        vector<vector<vector<int>>> allPaths;
        for (const auto& p : pairs) {
            allPaths.push_back(generatePairPermutations(p));
        }

        combinePaths(allPaths, results, {}, 0);
    } while (next_permutation(pairs.begin(), pairs.end()));

    return results;
}

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


vector<int> dijkstra(int s, vector<vector<int>>& adjacency_matrix) {
    vector<int> dist(n, INT32_MAX);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();

        if (u_dist > dist[u]) continue;

        for (int v = 0; v < n; v++) {
            if (adjacency_matrix[u][v] != INT32_MAX) {
                int weight = adjacency_matrix[u][v];
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    return dist;
}

vector<vector<int>> all_pairs_shortest_path(vector<vector<int>>& adjacency_matrix) {
    vector<vector<int>> dist(n);
    for (int i = 0; i < n; i++) {
        dist[i] = dijkstra(i, adjacency_matrix);
    }

    return dist;
}


int find_shortest_path(int s, int t, vector<vector<int>>& adjacency_matrix, vector<pair<int, int>>& required_path) {
    int min_cost = INT32_MAX;
    vector<vector<int>> allPaths = generateAllPaths(required_path);
    vector<vector<int>> all_dist = all_pairs_shortest_path(adjacency_matrix);
    for (auto path: allPaths) {
        int cost = 0;
        cost += all_dist[s][path[0] - 1];
        for (int i = 0; i < path.size(); i += 2) {
            cost += adjacency_matrix[path[i] - 1][path[i + 1] - 1];
            if (i + 2 < path.size()) {
                cost += all_dist[path[i + 1] - 1][path[i + 2] - 1];
            }
        }
        cost += all_dist[path[path.size() - 1] - 1][t];
        min_cost = min(min_cost, cost);
    }

    return min_cost;
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