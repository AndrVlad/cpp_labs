#include <iostream>
#include <string>
using namespace std;

struct Node {
    int ID;
    string FIO;
    string Group;
    Node *next;
};

int main()
{
    char key;

    Node *head = 0;

    while (key != 'x') {

        cout << endl;
        cout << "1. Add new Student from begin" << endl;
        cout << "2. Read elem" << endl;
        cout << "3. Add elem after" << endl;
        cout << "4. Add elem before" << endl;
        cout << "5. Delete elem after" << endl;
        cin >> key;

        switch (key) {

            case '1': {

                Node *NewElem = new Node;
                cout << "Input ID: " << endl;
                (cin >> NewElem->ID).get();
                cout << "Input FIO: " << endl;
                cin.getline(NewElem->FIO, 200);
                cout << "Input Group: " << endl;
                cin >> NewElem->Group;
                NewElem->next = head;
                head = NewElem;
                break;
            }

        }

    }


    return 0;
}

// ���������� ������ 1-������

        /*    for (int i = 0; i < 2; i++) {
        Node *CurElem = head;
        cout << CurElem->value;
        head = CurElem->next;
        }

        */



/*

case '2': {

                Node *OutElem = head;
                while (OutElem) {
                    cout << "->" << OutElem->value << "(" << OutElem << ")";
                    OutElem = OutElem->next;
                }
                break;
            }

            case '3': {

                int n = 0;
                cout << "Choose number of element for add after that" << endl;
                cout << head;
                cin >> n;
                Node *PrevElem = head;
                Node *NewElem = new Node;
                n--;

                    while (n != 0) {
                        PrevElem = PrevElem->next;
                        cout << PrevElem;
                        cout << PrevElem->next;
                        n--;
                   }

                NewElem->next = PrevElem->next;
                cout << "Input value of element" << endl;
                cin >> NewElem->value;
                PrevElem->next = NewElem;

                break;
            }

            case '4': {

                int n = 0;

                Node *NextElem = head;
                Node *CurrElem;
                Node *NewElem = new Node;

                cout << "Choose number of element for add before that" << endl;
                cout << head;
                cin >> n;

                if (n == 1) {
                    NewElem->next = head;
                    head = NewElem;
                    cout << "Input value of element" << endl;
                    cin >> NewElem->value;
                } else {

                    for (int i = 0; i < n-1; i++) {
                        NextElem = NextElem->next;
                        cout << NextElem;
                    }

                    CurrElem = head;

                    while (CurrElem->next != NextElem) {
                        CurrElem = CurrElem->next;
                    }
                    cout << "Curr" << CurrElem << endl;
                    NewElem->next = NextElem;
                    cout << "Input value of element" << endl;
                    cin >> NewElem->value;
                    CurrElem->next = NewElem;
                }

                break;
            }

            case '5': {

                int n = 0;
                cout << "Choose number of next element for delete" << endl;
                cout << head;
                cin >> n;
                Node *PrevElem = head;
                n--;

                    while (n != 0) {
                        PrevElem = PrevElem->next;
                        cout << PrevElem;
                        cout << PrevElem->next;
                        n--;
                   }


                Node *DeleteElem = PrevElem->next;
                PrevElem->next = PrevElem->next->next;
                delete DeleteElem;
                break;
            }
*/
