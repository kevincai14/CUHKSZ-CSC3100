//
// Created by Quan on 2024/9/21.
//
#include <iostream>
#include <vector>
using namespace std;

int n, q;


int isValidPermutation(int* array, int* left, int* right) {
    if (array[0] != left[0] or array[n - 1] != right[0]) {
        return 0;
    }

    for (int i = 0; i < q - 1; i++) {
        if (left[q - 1 - i] != left[q - 1 - i - 1] and right[q - 1 - i] != right[q - 1 - i - 1]) {
            return 0;
        }
        if (left[i] == right[i]) {
            return 0;
        }
    }

    vector<int> merge;

    for (int i = 0; i < q; i++) {
        if (left[i] != left[i + 1]) {
            merge.push_back(left[i]);
        }
    }
    for (int i = 0; i < q; i++) {
        if (right[q - 1 - i] != right[q - 1 - i - 1]) {
            merge.push_back(right[q - 1 - i]);
        }
    }

    int index = 0;
    int count = 0;
    for (int i : merge) {
        while (index < n and i != array[index]) {
            index++;
        }
        count++;
    }
    if (count != merge.size()) {
        return 0;
    }


    return 1;

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
    cout << a;

    delete[] array;
    delete[] left;
    delete[] right;

//    system("pause");
}