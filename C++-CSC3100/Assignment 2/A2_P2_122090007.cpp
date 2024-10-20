//
// Created by Quan on 2024/10/19.
//
#include <iostream>
#include <cctype>
#include <vector>
#include <stack>
using namespace std;

int n;

void list_update(vector<int> & complexity_list, int index) {
    int max_num;
    if (index + 1 == complexity_list.size()) {
        max_num = 0;
    } else {
        max_num = 0;
        for (int i = index + 1; i < complexity_list.size(); i++) {
            if (complexity_list[i] > max_num) {
                max_num = complexity_list[i];
                complexity_list[i] = 0;
            }
        }
    }
    complexity_list[index] += max_num;
}


int complexity_check() {
    int L;
    cin >> L;

    string F, i, x, y;
    int end_count = 0;
    int F_count = 0;
    vector<int> complexity_list;
    stack<int> F_index;

    while (true) {
        cin >> F;
        if (F == "F") {
            cin >> i >> x >> y;
            F_index.push(F_count++);

            bool xy_isdigit = isdigit(x[0]) and isdigit(y[0]);

            if (x != y and !xy_isdigit) {
                complexity_list.push_back(1);
            } else {
                complexity_list.push_back(0);
            }

        } else if (F == "E") {
            end_count++;

            int index = F_index.top();
            list_update(complexity_list, index);

            F_index.pop();

            if (end_count == L / 2) {
                return complexity_list[0];
            }
        }
    }
}


int main() {
    cin >> n;
    vector<int> result;
    for (int i = 0; i < n; i++) {
        result.push_back(complexity_check());
    }

    for (int i : result) {
        if (i == 0) {
            cout << "O(1)" << endl;
        } else {
            cout << "O(n^" << i << ")"<< endl;
        }
    }
    system("pause");
}