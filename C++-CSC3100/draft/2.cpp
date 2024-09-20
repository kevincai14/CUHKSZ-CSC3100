//
// Created by Quan on 2024/9/20.
//
#include <iostream>

using namespace std;
int main() {
    int n,m,l;
    cin >> n >> m ;
    cout << n + m;
    cin >> l;
    cout << l;
    int* distinct_count = new int[n]();
    for (int i = 0; i < n; i++) {
        cout << distinct_count[i] << endl;
    }
    system("pause");
}