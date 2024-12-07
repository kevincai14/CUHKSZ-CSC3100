//
// Created by Quan on 2024/12/7.
//
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstdint>
using namespace std;

int n, m, s, t;

int find_min_hp(int start, int end, vector<vector<pair<int, int>>>& adjacency_list) {
    int current_hp = 0;
    int current_sp = 1;
    int current_path_hp_cost = INT32_MAX;
    int min_path_cost = INT32_MAX;
    int min_monster = INT32_MAX;

    for (auto node: adjacency_list[start]) {
        if (node.second < min_monster) {
            min_monster = node.second;
            start = node.first;
        }
    }
    current_path_hp_cost = min_monster / current_sp;
    min_path_cost = current_path_hp_cost;

    while (true) {
        current_hp += current_path_hp_cost;
        current_sp++;

        min_monster = INT32_MAX;
        for (auto node: adjacency_list[start]) {
            if (node.second < min_monster) {
                min_monster = node.second;
                start = node.first;
            }
        }
        current_path_hp_cost = min_monster / current_sp;
        if (current_path_hp_cost == 0) {
            break;
        }

        if (current_path_hp_cost > min_path_cost) {
            break;
        }
        min_path_cost = min(current_path_hp_cost, min_path_cost);
    }

    while (min_path_cost / current_sp != 0) {
        current_hp += min_path_cost / current_sp;
        current_sp++;
    }

    return current_hp;
}

int main() {
    cin >> n >> m >> s >> t;

    vector<vector<pair<int, int>>> adjacency_list(n);
    for (int i = 0; i < m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        adjacency_list[u - 1].emplace_back(v - 1, a);
        adjacency_list[v - 1].emplace_back(u - 1, a);
    }

    cout << find_min_hp(t - 1, s - 1, adjacency_list);


}