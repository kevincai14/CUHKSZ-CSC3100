//
// Created by Quan on 2024/9/19.
//
# include <iostream>
#include <cstdint>
using namespace std;

int n,m,P;
int* distinct_count;
int distinct_value = 0;
int sum = 0;

void update(int* array) {
    int k, x, y, c;
    cin >> k >> x >> y >> c;

    int a = (((x * x) + k * y + 5 * x) % P) * c;

    int old_value = array[k - 1];

    int abs_value_old = abs(old_value);
    distinct_count[abs_value_old]--;

    if (distinct_count[abs_value_old] <= 1 and old_value != 0) {
        distinct_value--;
    } else if (old_value == 0 and distinct_count[abs_value_old] == 0) {
        distinct_value--;
    }

    array[k - 1] = a;
    sum += (a - old_value);

    int abs_new = abs(a);
    distinct_count[abs_new]++;

    if (distinct_count[abs_new] <= 2 and a != 0) {
        distinct_value++;
    } else if (a == 0 and distinct_count[abs_new] == 1) {
        distinct_value++;
    }
}

int check_distinct() {
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
    switch (command) {
        case 1:
            update(array);
            return INT32_MAX;
        case 2: {
            return sum;
        }
        case 3:
            return distinct_value;
        default:
            return INT32_MAX;
    }
}


int main() {
    cin >> n >> m >> P;
    int output_count = 0;
    int* array = new int[n];
    int* output = new int[m];
    distinct_count = new int[P]();

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        sum += temp;
        array[i] = temp;
        distinct_count[abs(array[i])]++;
    }

    check_distinct();

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