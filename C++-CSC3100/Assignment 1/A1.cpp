//
// Created by Quan on 2024/9/19.
//
#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int n,m,P;
int distinct_value = 0;
unordered_map<int, int> value_counter;
int zero_count = 0;

void update(int* array) {
    int k, x, y, c;
    cin >> k >> x >> y >> c;

    int old_value = array[k - 1];

    if (old_value == 0) {
        zero_count--;
    } else {
        value_counter[abs(old_value)]--;
        if (value_counter[abs(old_value)] == 0) {
            value_counter.erase(abs(old_value));
        }
    }

    int a = (((x * x) + k * y + 5 * x) % P) * c;
    array[k - 1] = a;

    if (a == 0) {
        zero_count++;
    } else {
        value_counter[abs(a)]++;
    }
}

int check_distinct(int* array) {
    for (const auto &entry : value_counter) {
        if (entry.second >= 2) {
            distinct_value += 2;
        } else {
            distinct_value += 1;
        }
    }


    if (zero_count > 0) {
        distinct_value++;
    }

    return distinct_value;
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

int operate(int &command, int* array) {
    if (command == 2) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += array[i];
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
    int* array = new int[n];
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
    delete[] array;
    system("pause");
}