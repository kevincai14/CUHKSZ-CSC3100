//
// Created by Quan on 2024/10/19.
//
#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

int n;
int e_count = 0;

int check_loop(int L, int complexity = 0, int end_count = 0) {
    string F, i, x, y;
    cin >> F;

    if (F == "F") {
        cin >> i >> x >> y;

        bool xy_state = isdigit(x[0]) and isdigit(y[0]);

        if (x != y and !xy_state and e_count != 1) {
            complexity++;
        }
        e_count = 0;

        return check_loop(L, complexity, end_count);

    } else if (F == "E") {
        e_count++;
        end_count++;
        if (end_count == L / 2) {
            e_count = 0;
            return complexity;
        } else {
            return check_loop(L, complexity, end_count);
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