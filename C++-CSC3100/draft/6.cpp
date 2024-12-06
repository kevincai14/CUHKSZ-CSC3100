int find_shortest_path(int s, int t, vector<vector<int>>& adjacency_matrix, vector<pair<int, int>>& required_path) {
    int min_cost = INT32_MAX;
    vector<vector<int>> allPaths = generateAllPaths(required_path);
    for (auto path: allPaths) {
//        for (auto f: path) {
//            cout << f;
//        }
//        cout<<endl;
        int cost = 0;
        cost += dijkstra(s, path[0] - 1, adjacency_matrix);
        for (int i = 0; i < path.size(); i += 2) {
            cost += adjacency_matrix[path[i] - 1][path[i + 1] - 1];
            if (i + 2 < path.size()) {
                cost += dijkstra(path[i + 1] - 1, path[i + 2] - 1, adjacency_matrix);
            }
        }
        cost += dijkstra(path[path.size() - 1] - 1, t, adjacency_matrix);
        min_cost = min(min_cost, cost);
    }

    return min_cost;
}


int find_shortest_path(int s, int t, vector<vector<int>>& adjacency_matrix, vector<pair<int, int>>& required_path) {
    int min_cost = 0;
    for (auto edge: required_path) {
        if (edge.first - 1 == s) {
            min_cost += adjacency_matrix[s][edge.second - 1];
            s = edge.second - 1;
        } else if (edge.second - 1 == s) {
            min_cost += adjacency_matrix[s][edge.first - 1];
            s = edge.first - 1;
        } else {
            if (dijkstra(s, edge.first - 1, adjacency_matrix) > dijkstra(s, edge.second - 1, adjacency_matrix)) {
                min_cost += dijkstra(s, edge.second - 1, adjacency_matrix);
                s = edge.first - 1;
            } else {
                min_cost += dijkstra(s, edge.first - 1, adjacency_matrix);
                s = edge.second - 1;
            }
            min_cost += adjacency_matrix[edge.first - 1][edge.second - 1];
        }
    }
    min_cost += dijkstra(s , t, adjacency_matrix);

    return min_cost;
}