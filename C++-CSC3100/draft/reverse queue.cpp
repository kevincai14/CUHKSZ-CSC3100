//
// Created by Quan on 2024/10/29.
//
#include <iostream>
#include <queue>
using namespace std;

// Function to reverse the queue using another queue
void reverse(queue<int>& Q, queue<int>& Q_1) {
    // Step 1: Dequeue all elements from Q and enqueue them to Q_1
    while (!Q.empty()) {
        int element = Q.front(); // Get the front element
        Q.pop(); // Dequeue from Q
        Q_1.push(element); // Enqueue to Q_1
    }

    // Step 2: Dequeue all elements from Q_1 and enqueue them back to Q
    while (!Q_1.empty()) {
        int element = Q_1.front(); // Get the front element
        Q_1.pop(); // Dequeue from Q_1
        Q.push(element); // Enqueue back to Q
    }
}

int main() {
    // Create the original queue and add elements
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);

    // Create another queue for reversal
    queue<int> Q_1;

    // Print original queue
    cout << "Original Queue: ";
    queue<int> temp = Q; // Create a temporary copy to display contents
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the queue
    reverse(Q, Q_1);

    // Print reversed queue
    cout << "Reversed Queue: ";
    while (!Q.empty()) {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << endl;

    return 0;
}
