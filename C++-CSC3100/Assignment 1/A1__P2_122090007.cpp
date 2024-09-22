//
// Created by Quan on 2024/9/21.
//
#include <iostream>
#include <map>
using namespace std;

int n, q;

int isValidPermutation(int* array, int* left, int* right) {

    map<int, int> index;
    for (int i = 0; i < n; i++) {
        index[array[i]] = i;
    }

    int left_bound = 0;
    int right_bound = n - 1;

    for (int i = 0; i < q; i++) {
        int l = left[q - 1 - i];
        int r = right[q - 1 - i];

        int l_index = index[l];
        int r_index = index[r];

        if (l_index >= r_index) {
            return 0;
        }

        left_bound = l_index;
        right_bound = r_index;
    }

    if (left_bound == 0 and right_bound == n - 1) {
        return 1;
    }

    return 0;
}


int main() {
    cin >> n >> q;

    int* array = new int[n];
    int* left = new int[q];
    int* right = new int[q];

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> left[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> right[i];
    }

    int a = isValidPermutation(array, left, right);
    cout << a << endl;

    delete[] array;
    delete[] left;
    delete[] right;

//    system("pause");
}
