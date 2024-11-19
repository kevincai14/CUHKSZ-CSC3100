//
// Created by Quan on 2024/11/18.
//
#include <iostream>
#include <iomanip>
#include <unordered_set>
using namespace std;

bool check_same(int arr[], int size) {
    unordered_set<int> seen;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            if (seen.find(arr[i]) != seen.end()) {
                return true;
            }
            seen.insert(arr[i]);
        }
    }
    return false;
}

int main() {
    int array[] = {2, 3, 1, 0};
    cout << check_same(array, 4);
}