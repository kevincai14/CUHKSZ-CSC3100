//
// Created by Quan on 2024/10/19.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;

int check_list(int* A, int* A_num_count, int result = 0) {
    queue<int> delete_num;
    for (int i = 0; i < n; i++) {
        if (A_num_count[i] == 0 and A[i] != 0) {
            delete_num.push(i);
        }
    }

    if (delete_num.empty()) {
        return result;
    }


    while (!delete_num.empty()) {
        int index = delete_num.front();
        delete_num.pop();
        A_num_count[A[index] - 1]--;
        A[index] = 0;
        result++;
    }

    return check_list(A, A_num_count, result);
}


int main() {
    cin >> n;

    int* A = new int[n];
    int* A_num_count = new int[n]();

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A_num_count[A[i] - 1]++;
    }

    cout << check_list(A, A_num_count);

    delete[] A;
    delete[] A_num_count;
    system("pause");
}
