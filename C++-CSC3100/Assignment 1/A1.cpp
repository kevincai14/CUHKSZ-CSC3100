//
// Created by Quan on 2024/9/19.
//
# include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_set>
using namespace std;

int P;


void update(vector<int> & array) {
    int k, x, y, c;
    cin >> k >> x >> y >> c;
    int a = (((x * x) + k * y + 5 * x) % P) * c;
    array[k - 1] = a;
}

int check_distinct(vector<int> &array) {
    unordered_set<int> distinct_set;
    for (int i: array) {
        auto a = distinct_set.insert(i);
        if (a.second == false) {
            distinct_set.insert(-i);
        }
    }
    return distinct_set.size();
}

//int check_distinct(vector<int> array) {
//    int distinct = 0;
//    vector<int> distinct_array;
//    for (int i : array) {
//        if (find(distinct_array.begin(), distinct_array.end(), i) == distinct_array.end()) {
//            distinct_array.push_back(i);
//            distinct++;
//        } else if (find(distinct_array.begin(), distinct_array.end(), -i) == distinct_array.end()) {
//            distinct_array.push_back(-i);
//            distinct++;
//        }
//    }
//    return distinct;
//}

int operate(int &command, vector<int> &array) {
    if (command == 2) {
        int sum = 0;
        for (int i : array) {
            sum += i;
        }
        return sum;
    } else if (command == 3) {
        int result = check_distinct(array);
        return result;
    } else if (command == 1) {
        update(array);
        return INT32_MAX;
    }
}



int main() {
//    vector<int> array;
    vector<string> source_v;
    int n,m;
    string line;

//    while (cin) {
//        getline(cin, line);
//        source_v.push_back(line);
//    }

//    m = get_array((source_v[0]))[1];
//    P = get_array(source_v[0])[2];

//    array = get_array(source_v[1]);
//    for (int i = 0; i < m; i++) {
//        operate(source_v[i + 2], array);
//        for (int i : array) {
//            cout << i << " ";
//        }
//        cout << endl;
//    }
    cin >> n >> m >> P;
    vector<int> array(n);
    vector<int> output;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < m; i++) {
        int command;
        cin >> command;
        int single_output = operate(command, array);
        if (single_output != INT32_MAX) {
            output.push_back(single_output);
        }
    }
    for (int i : output) {
        cout << i << endl;
    }
    system("pause");
}