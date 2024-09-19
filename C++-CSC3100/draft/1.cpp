//
// Created by Quan on 2024/9/19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_set>
using namespace std;

int check_distinct(vector<int> array) {
    unordered_set<int> distinct_set;
    for (int i : array) {
        distinct_set.insert(i);
    }
    return distinct_set.size();
}
vector<int> get_array(string text) {
    int number;
    vector<int> array;

    stringstream ss(text);
    while (ss >> number) {
        array.push_back(number);
    }

    return array;
}
int main() {
    vector<int> a;
    int temp;
//    for (int i = 0; i < 5; i++) {
//        cin >> temp;
//        a.push_back(temp);
//    }
//    int b = check_distinct(a);
//    cout << b;
//    system("pause");
    string b;

    getline(cin, b);
    a = get_array(b);
//    for (int i : a) {
//        cout << i << endl;
//    }
    int c = check_distinct(a);
    cout << c;
    system("pause");
}