#include "PriorityQueue.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
//    static const int MAX_T = 10;
//    static const int MAX_N = 1000;
//    static const int MAX_M = 1000;
    int T, N, M;
    cin >> T;


    for (int i = 0; i < T; i++) {
        Printer PriorityQueue;
        cin >> N;
        cin.ignore();
        int j = 0;

        string input;
        while (getline(cin, input)&&(j<=N)) {

            j++;
            if (j==N+1){
                M = stoi(input);
                break;
            }

            if (input[0] == 'I') {
                string info, doc_id, doc_title;
                info = input.substr(2);

                doc_id = info.substr(0, info.find(' '));
                info = info.substr(info.find(' ') + 1);

                doc_title = info.substr(0, info.find(' '));
                info = info.substr(info.find(' ') + 1);

                int doc_pro = stoi(info);

                PriorityQueue.insertDoc(doc_id, doc_title, doc_pro);
            } else {
                if (input == "P") {
                    PriorityQueue.popDoc();
                } else if (input == "T") {
                    PriorityQueue.topDoc();
                } else if (input == "S") {
                    cout << PriorityQueue.sizePrinter() << endl;
                } else if (input == "E") {
                    cout << PriorityQueue.emptyPrinter() << endl;
                }

            }

        }

        if (PriorityQueue.sizePrinter() < M) {
            cout << "M > printer.size()" << endl;
        } else {
            Document temp = PriorityQueue.popM(M);
            cout << temp.getId() << ' ' << temp.getTitle() << endl;
        }
    }
    return 0;
}