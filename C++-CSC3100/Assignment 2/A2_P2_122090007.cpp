//
// Created by Quan on 2024/10/19.
//
#include <iostream>
#include <cctype>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n;

int max_f(vector<int> complexity_list, int index) {
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

void fill0(vector<int> & complexity_list, int index) {
    if (index + 1 == complexity_list.size()) {
        complexity_list = complexity_list;                      //fixxxxxxxxxxxxxxxxxx
    } else {
        for (int i = index + 1; i < complexity_list.size(); i++) {
            complexity_list[i] = 0;
        }
    }
}

int check_loop(int L) {
    string F, i, x, y;
    int end_count = 0;
    int F_count = 0;
    vector<int> complexity_list;
    stack<int> F_index;

    while (true) {
        cin >> F;
        if (F == "F") {
            cin >> i >> x >> y;
            F_index.push(F_count);
            F_count++;                   //combine with above F_index.push(F_count++)
            bool xy_state = isdigit(x[0]) and isdigit(y[0]);

            if (x != y and !xy_state) {
                complexity_list.push_back(1);
            } else {
                complexity_list.push_back(0);
            }

        } else if (F == "E") {
            end_count++;

            int index = F_index.top();
            int max_num = max_f(complexity_list, index);
            complexity_list[index] += max_num;
            fill0(complexity_list, index);

            F_index.pop();

            if (end_count == L / 2) {
                return complexity_list[0];
            }
        }
    }

}

int complexity_check() {
    int L;
    cin >> L;
    return check_loop(L);
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