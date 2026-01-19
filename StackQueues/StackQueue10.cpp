#include <iostream>
#include <queue>
#include <chrono>
using namespace std;

int main() {
    priority_queue<string> pq;

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < 50000; i++) {
        pq.push("Task_" + to_string(i));
    }

    auto end = chrono::high_resolution_clock::now();

    cout << "Insertion time (ms): "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << endl;

    return 0;
}
