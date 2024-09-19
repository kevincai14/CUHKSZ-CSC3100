//
// Created by Quan on 2024/9/19.
//
// dead. runtime error.
# include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <cstdint>
using namespace std;

int P;

vector<int> get_array(string text) {
    int number;
    vector<int> array;

    stringstream ss(text);
    while (ss >> number) {
        array.push_back(number);
    }

    return array;
}

void update(vector<int> parameter, vector<int> & array) {
    int k = parameter[1];
    int x = parameter[2];
    int y = parameter[3];
    int c = parameter[4];
    int a = (((x * x) + k * y + 5 * x) % P) * c;
    array[k - 1] = a;
}

int check_distinct(vector<int> array) {
    unordered_set<int> distinct_set;
    for (int i: array) {
        auto a = distinct_set.insert(i);
        if (a.second == false) {
            distinct_set.insert(-i);
        }
    }
    return distinct_set.size();
}

int operate(string command, vector<int> &array) {
    if (command == "2") {
        int sum = 0;
        for (int i : array) {
            sum += i;
        }
        return sum;
    } else if (command == "3") {
        int result = check_distinct(array);
        return result;
    } else {
        update(get_array(command), array);
        return INT32_MAX;
    }
}

int main() {
    vector<int> array;
//    vector<string> source_v;
    vector<int> output;
    int status = 0;
//    int m;
    string line;

    while (getline(cin, line)) {
//        getline(cin, line);
        if (status == 0) {
//            m = get_array((line))[1];
            P = get_array(line)[2];
            status++;
        } else if (status == 1) {
            array = get_array(line);
            status++;
        } else {
//            single_output.push_back(operate(line, array));
            int single_output =  operate(line, array);
            if (single_output != INT32_MAX) {
                output.push_back(single_output);
            }
        }
    }
    for (int i : output) {
        cout << i << endl;
    }
    system("pause");
}