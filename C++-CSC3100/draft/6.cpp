//
// Created by Quan on 2024/12/6.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 生成单个组合的排列
vector<string> generatePairPermutations(pair<int, int> p) {
    vector<string> permutations;
    permutations.push_back(to_string(p.first) + to_string(p.second));
    permutations.push_back(to_string(p.second) + to_string(p.first));
    return permutations;
}

// 合并路径
void combinePaths(const vector<vector<string>>& paths, vector<string>& results, string current, int index) {
    if (index == paths.size()) {
        results.push_back(current);
        return;
    }
    for (const auto& path : paths[index]) {
        combinePaths(paths, results, current + path, index + 1);
    }
}

// 主函数
void generateAllPaths(vector<pair<int, int>> pairs) {
    // 排列组合的结果
    vector<string> results;

    // 对组合顺序生成全排列
    sort(pairs.begin(), pairs.end());
    do {
        // 每个组合内部的路径生成
        vector<vector<string>> allPaths;
        for (const auto& p : pairs) {
            allPaths.push_back(generatePairPermutations(p));
        }

        // 合并路径
        combinePaths(allPaths, results, "", 0);
    } while (next_permutation(pairs.begin(), pairs.end()));

    // 输出结果
    for (const auto& result : results) {
        cout << result << endl;
    }
}

int main() {
    // 输入两两组合
    vector<pair<int, int>> pairs = {{1, 2},{3,4}};

    // 生成所有路径
    generateAllPaths(pairs);

    return 0;
}
