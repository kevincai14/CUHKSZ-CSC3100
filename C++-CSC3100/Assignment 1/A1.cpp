//
// Created by Quan on 2024/9/19.
//
# include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n,m,P;
int* distinct_count = new int[10000000]();
int distinct_value = 0;

void update(int* array) {
    int k, x, y, c;
    cin >> k >> x >> y >> c;
    int a = (((x * x) + k * y + 5 * x) % P) * c;
    int old_value = array[k - 1];
    distinct_count[abs(old_value)]--;
    if (distinct_count[abs(old_value)] <= 1 and old_value != 0) {
        distinct_value--;
    } else if (old_value == 0 and distinct_count[abs(old_value)] == 0) {
        distinct_value--;
    }
    array[k - 1] = a;
    distinct_count[abs(a)]++;
    if (distinct_count[abs(a)] <= 2 and a != 0) {
        distinct_value++;
    } else if (a == 0 and distinct_count[abs(a)] == 1) {
        distinct_value++;
    }


}

int check_distinct(int* array) {
//    for (int i = 0; i < n; i++) {
//        distinct_count[abs(array[i])]++;
//    }
    for (int i = 0; i < P; i++) {
        if (distinct_count[i] == 1 and i != 0) {
            distinct_value += 1;
        } else if (distinct_count[i] >= 2 and i != 0) {
            distinct_value += 2;
        } else if (i == 0 and distinct_count[i] != 0) {
            distinct_value += 1;
        }
    }
    return distinct_value;
}


int operate(int &command, int* array) {
    if (command == 2) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += array[i];
        }
        return sum;
    } else if (command == 3) {
        int result = distinct_value;
        return result;
    } else if (command == 1) {
        update(array);
        return INT32_MAX;
    }
}

int main() {
    cin >> n >> m >> P;
    int output_count = 0;
    int* array = new int[n];
    int* output = new int[m];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        distinct_count[abs(array[i])]++;
    }

    check_distinct(array);


    for (int i = 0; i < m; i++) {
        int command;
        cin >> command;
        int single_output = operate(command, array);
        if (single_output != INT32_MAX) {
            output[output_count++] = single_output;
        }
    }
    for (int i = 0; i < output_count; i++) {
        cout << output[i] << endl;
    }


    delete[] array;
    delete[] output;
    delete[] distinct_count;
    system("pause");
}