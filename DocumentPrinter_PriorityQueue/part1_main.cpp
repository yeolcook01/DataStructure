#include "PriorityQueue.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    static const int MAX_N = 1000;
    int d, N;
    cin >> d;
    PriorityQueue PriorityQueue(d);
    cin >> N;
    cin.ignore();

    for (int i=0; i<N; i++){
        string input;
        getline(cin, input);
        char cmd = input[0];
        if (cmd == 'I'){
            int val = stol(input.substr(2));
            PriorityQueue.insertHeap(val);
        }

        else if (cmd == 'P') {
            PriorityQueue.popHeap();
        }
        else if (cmd == 'T') {
            PriorityQueue.topHeap();
        }
        else if (cmd == 'S') {
            cout << PriorityQueue.sizeHeap() << endl;
        }
        else if (cmd == 'E') {
            cout << PriorityQueue.emptyHeap() << endl;
        }


    }
    return 0;
}