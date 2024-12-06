//
// Created by Quan on 2024/12/6.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 生成单个组合的排列
vector<vector<int>> generatePairPermutations(pair<int, int> p) {
    vector<vector<int>> permutations;
    permutations.push_back({p.first, p.second});
    permutations.push_back({p.second, p.first});
    return permutations;
}

// 合并路径
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

// 主函数，将所有结果存储为 vector<int>
vector<vector<int>> generateAllPaths(vector<pair<int, int>> pairs) {
    // 排列组合的结果
    vector<vector<int>> results;

    // 对组合顺序生成全排列
    sort(pairs.begin(), pairs.end());
    do {
        // 每个组合内部的路径生成
        vector<vector<vector<int>>> allPaths;
        for (const auto& p : pairs) {
            allPaths.push_back(generatePairPermutations(p));
        }

        // 合并路径
        combinePaths(allPaths, results, {}, 0);
    } while (next_permutation(pairs.begin(), pairs.end()));

    return results;
}

int main() {
    // 输入示例
    vector<pair<int, int>> pairs = {{1, 2}, {3, 4},{5,6}};

    // 生成所有路径
    vector<vector<int>> allPaths = generateAllPaths(pairs);

    // 输出结果
    for (const auto& path : allPaths) {
        for (const auto& node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
