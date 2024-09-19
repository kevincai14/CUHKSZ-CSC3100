//
// Created by Quan on 2024/9/19.
//
# include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> get_array(string text) {
    int number;
    vector<int> array;

    stringstream ss(text);
    while (ss >> number) {
        array.push_back(number);
    }

    return array;
}

int check_distinct(vector<int> array) {
    int distinct = 0;
    for (int i : array) {

    }
}

void operate(string command, vector<int> &array) {
    if (command == "2") {
        int sum = 0;
        for (int i : array) {
            sum += i;
        }
        cout << sum << endl;
    }

    if (command == "3") {
        cout << check_distinct(array) << endl;
    }
}



int main() {
    int status = 0;
    int n, m, p;
    vector<int> array;

    string line;

    while (cin) {
        if (status == 0) {
            getline(cin, line);
            n = line[0];
            m = line[2];
            p = line[4];
            status++;
        } else if (status == 1) {
            array = get_array(line);
        } else{
            getline(cin, line);
            operate(line, array);
        }

    }

}
