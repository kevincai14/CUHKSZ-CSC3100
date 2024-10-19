//
// Created by Quan on 2024/10/19.
//
#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

int n;
int e_count = 0;
vector<int> waiting_list;

int check_loop(int L, int complexity = 0, int end_count = 0) {
    string F, i, x, y;
    cin >> F;

    if (F == "F") {
        e_count = 0;
        cin >> i >> x >> y;

        bool xy_state = isdigit(x[0]) and isdigit(y[0]);

        if (x != y and !xy_state) {
            complexity++;
        }

        return check_loop(L, complexity, end_count);

    } else if (F == "E") {
        end_count++;
        if (end_count == L / 2) {
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
        cout << i << endl;
    }
    system("pause");
}