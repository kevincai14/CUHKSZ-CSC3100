//
// Created by Quan on 2024/12/6.
//
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <tuple>
#include <climits>
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


vector<int> dijkstra(int s, vector<vector<pair<int, int>>> adjacency_list) {
    vector<int> dist(n, INT32_MAX);
    vector<bool> final(n, false);
    vector<int> parent(n, -1);

    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, final);
        final[u] = true;

        for (const auto &[v, weight]: adjacency_list[u]) {
            if (dist[u] != INT_MAX && !final[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }
    return dist;
}

pair<int, int> find_shortest_node(int s, vector<vector<pair<int, int>>>& adjacency_list, vector<tuple<int, int, int>>& required_path, int cost = 0) {
    cout << "resursive" << endl;
    if (required_path.empty()) {
        return {cost, s};
    }
    vector<int> dist = dijkstra(s, adjacency_list);
    tuple<int, int, int> nearest_path;
    int nearest_node = INT32_MAX;
    int nearest_dist = INT32_MAX;
    int next_start_node = INT32_MAX;
    for (int i = 0; i < required_path.size(); i++) {
        auto edge = required_path[i];
        int nearest_node_for_pair = INT32_MAX;
        int nearest_dist_for_pair = INT32_MAX;
        int far_node = INT32_MAX;

        int node1 = get<0>(edge);
        int node1_dist = dist[node1];
        int node2 = get<1>(edge);
        int node2_dist = dist[node2];

        if (node1_dist > node2_dist) {
            nearest_node_for_pair = node2;
            nearest_dist_for_pair = node2_dist;
            far_node = node1;
        } else {
            nearest_node_for_pair = node1;
            nearest_dist_for_pair = node1_dist;
            far_node = node2;
        }

        if (nearest_dist > nearest_dist_for_pair) {
            nearest_node = nearest_node_for_pair;
            nearest_dist = nearest_dist_for_pair;
            nearest_path = edge;
            next_start_node = far_node;
        }
    }
    cout << "nearest_path " << get<0>(nearest_path)+1 << get<1>(nearest_path)+1 <<get<2>(nearest_path)<<endl;
    cout << "nearest node " << nearest_node + 1 <<endl;
    cout << "node " << s+1<< " to next " << nearest_dist << endl;
    cout << "len of pass edge " << get<2>(nearest_path) << endl;
    cout << "next_node:" << next_start_node+1 << endl;

    cost += nearest_dist + get<2>(nearest_path);
    cout << "cost " << cost << endl;
    cout << endl;
    auto it = find(required_path.begin(), required_path.end(), nearest_path);
    if (it != required_path.end()) {
        required_path.erase(it);
    }
    return find_shortest_node(next_start_node, adjacency_list, required_path, cost);

}

int find_shortest_path(int s, int t, vector<vector<pair<int, int>>>& adjacency_list, vector<tuple<int, int, int>>& required_path) {
    pair<int, int> result;
    result = find_shortest_node(s, adjacency_list, required_path);
    int min_cost = result.first;
    int last_node = result.second;
    vector<int> dist = dijkstra(last_node, adjacency_list);
    min_cost += dist[t];
    return min_cost;
}

int main() {
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> adjacency_list(n);
    vector<tuple<int, int, int>> path_ei(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        path_ei[i] = make_tuple(u - 1, v - 1, w);
        adjacency_list[u - 1].emplace_back(v - 1, w);
        adjacency_list[v - 1].emplace_back(u - 1, w);
    }

    vector<vector<tuple<int, int, int>>> required_path(q);
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
        int shortest_time = find_shortest_path(s - 1, t - 1, adjacency_list, required_path[i]);
        result.push_back(shortest_time);
    }

    for (int i: result) {
        cout << i << endl;
    }
}
