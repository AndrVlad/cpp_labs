#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Node {
    int ID;
    string FIO;
    string Group;
    Node *next;
};

OutputList (Node *head) {
    if (head != 0) {
        cout << head->ID << endl;
        return OutputList(head->next);
    } else {
        cout << "\n";
    }
}

int main()
{
    char key;
    string str;

    Node *head = 0;

    while (key != 'x') {

        cout << endl;
        cout << "1. Add new Student at begin of list" << endl;
        cout << "2. Add new Student at the end of list" << endl;
        cout << "3. Add new Student at i-position of list" << endl;
        cout << "4. Change data on i-position" << endl;
        cout << "5. Delete Student on i-position" << endl;
        cout << "6. Show list" << endl;
        cout << "7. Delete list and exit" << endl;
        cin >> key;

        switch (key) {

            case '1': {

                Node *NewElem = new Node;
                cout << "Input ID: " << endl;
                (cin >> NewElem->ID).get();
                cout << "Input FIO: " << endl;
                getline(cin, NewElem->FIO);
                cout << "Input Group: " << endl;
                cin >> NewElem->Group;
                NewElem->next = head;
                head = NewElem;
                break;

            }

            case '2': {

                Node *NewElem = new Node;
                cout << "Input ID: " << endl;
                (cin >> NewElem->ID).get();
                cout << "Input FIO: " << endl;
                getline(cin, NewElem->FIO);
                cout << "Input Group: " << endl;
                cin >> NewElem->Group;
                NewElem->next = head;
                head = NewElem;
                break;
            }

            case '6': {

                Node *OutElem = head;
                while (OutElem) {
                    //cout << "->" << OutElem->value << "(" << OutElem << ")";
                    cout << "ID: " << OutElem->ID << endl;
                    cout << "FIO: " << OutElem->FIO << endl;
                    cout << "Group: " << OutElem->Group << endl;
                    OutElem = OutElem->next;
                }
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
