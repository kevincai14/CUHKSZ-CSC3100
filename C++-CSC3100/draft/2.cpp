#include <iostream>
#include <cstdint>
#include <unordered_set>
using namespace std;

int P;

void update(int* array, int n) {
    int k, x, y, c;
    cin >> k >> x >> y >> c;
    if (k >= 1 && k <= n) { // Ensure k is within bounds
        int a = (((x * x) + k * y + 5 * x) % P) * c;
        array[k - 1] = a;
    }
}

int check_distinct(int* array, int n) {
    unordered_set<int> distinct_set;
    for (int i = 0; i < n; ++i) {
        distinct_set.insert(array[i]);
        distinct_set.insert(-array[i]);
    }
    return distinct_set.size();
}

int operate(int command, int* array, int n) {
    if (command == 2) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += array[i];
        }
        return sum;
    } else if (command == 3) {
        return check_distinct(array, n);
    } else if (command == 1) {
        update(array, n);
        return INT32_MAX; // Use this to indicate no output
    }
    return 0;
}

int main() {
    int n, m;

    cin >> n >> m >> P;

    // Create and initialize array
    int* array = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    int* output = new int[m];
    int output_count = 0;

    // Process commands
    for (int i = 0; i < m; ++i) {
        int command;
        cin >> command;
        int result = operate(command, array, n);
        if (result != INT32_MAX) {
            output[output_count++] = result;
        }
    }

    // Print results
    for (int i = 0; i < output_count; ++i) {
        cout << output[i] << endl;
    }

    // Clean up
    delete[] array;
    delete[] output;
    system("pause");
    return 0;
}
