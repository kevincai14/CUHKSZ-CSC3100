//
// Created by Quan on 2024/9/19.
//
# include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>
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

void operate(string command, vector<int> &array) {
    if (command == "2") {
        int sum = 0;
        for (int i : array) {
            sum += i;
        }
        cout << sum << endl;
    } else if (command == "3") {
        int result = check_distinct(array);
        cout << result << endl;
    } else {
        update(get_array(command), array);
    }
}



int main() {
    vector<int> array;
    vector<string> source_v;
    int m;
    string line;

    while (cin) {
        getline(cin, line);
        source_v.push_back(line);
    }

    m = get_array((source_v[0]))[1];
    P = get_array(source_v[0])[2];
    array = get_array(source_v[1]);

    for (int i = 0; i < m; i++) {
        operate(source_v[i + 2], array);
    }
    system("pause");
}