//
// Created by Quan on 2024/9/21.
//
#include <iostream>
using namespace std;

int n, q;

int* merge(int* left, int* right) {
    int size = 2 * q;
    int* merge_array = new int[size];
    for (int i = 0; i < q; i++) {
        merge_array[i] = left[i];
        merge_array[i + q] = right[q - 1 - i];
    }
//    for (int i = 0; i < 2 * q; i++) {
//        cout << merge_array[i] << " ";
//    }
    return merge_array;
}

int isValidPermutation(int* array, int* left, int* right) {
    int count = 0;
    int array_index = 0;

    if (array[0] != left[0] or array[n - 1] != right[0]) {
        return 0;
    }

    for (int i = 0; i < q; i++) {
        if (left[q - 1 - i] != left[q - 1 - i - 1] and right[q - 1 - i] != right[q - 1 - i - 1]) {
            return 0;
        }
    }


    auto merge_array = merge(left, right);
    for (int i = 0; i < 2 * q; i++) {


        while (array_index < n and merge_array[i] != array[array_index]) {
            array_index++;
        }

        if (i == q - 1 and merge_array[i + 1] == array[array_index + 1]) {
            break;
        }


        if (merge_array[i] == array[array_index]) {
            count++;
        }
    }
    delete[] merge_array;
    if (count == 2 * q) {
        return 1;
    } else {
        return 0;
    }

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