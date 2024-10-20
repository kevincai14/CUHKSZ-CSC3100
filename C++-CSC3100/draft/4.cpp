//
// Created by Quan on 2024/10/19.
//
#include <iostream>
#include <vector>
#include <algorithm> // std::max_element

using namespace std;
int list_update(vector<int> complexity_list, int index) {
    if (index + 1 == complexity_list.size()) {
        return 0;
    } else {
        int max_num = 0;
        for (int i = index + 1; i < complexity_list.size(); i++) {
            if (complexity_list[i] > max_num) {
                max_num = complexity_list[i];
            }
        }
        return max_num;
    }
}
int main() {
    vector<int> complexity_list = {1,9,7,1};
    int index = 0;


//    auto max_num = max_element(complexity_list.begin() + index + 1, complexity_list.end());

    int max_num = list_update(complexity_list, index);
    complexity_list[index] += max_num;
        cout << "maxnum" << max_num << endl;
    fill(complexity_list.begin() + index + 1, complexity_list.end(), 0);


    for (int value : complexity_list) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}

