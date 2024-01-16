#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main() {
    static const int MAX_INSTRUCTIONS = 1000;
    static const int MAX_SEQUENCE = 1000;

    DoublyLinkedList dll;

    int N, M;
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        dll.Append(num);
    }


    dll.Set_cursor();

    for (int i=0; i<M; i++) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            // TO-DO
            dll.Left();
        }

        else if (cmd == 'R') {
            // TO-DO
            dll.Right();
        }

        else if (cmd == 'B') {
            // TO-DO
            dll.Backspace();
        }

        else if (cmd == 'P') {
            // TO-DO
            int $;
            cin >> $;
            dll.Insert($);
        }

        else if (cmd == 'V') {
            // TO-DO
            dll.Reverse();
        }

        else if (cmd == 'F') {
            // TO-DO
            int from, to;
            cin >> from >> to;
            dll.Find_and_replace(from, to);
        }
    }
    dll.Print();
    return 0;
}

