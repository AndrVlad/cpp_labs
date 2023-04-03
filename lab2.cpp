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

void OutputList (Node *head) {
    if (head != 0) {
        cout << "ID: " << head->ID << endl;
        cout << "FIO: " << head->FIO << endl;
        cout << "Group: " << head->Group << endl;
        cout << "head = " << head << " head->next= " << head->next << endl;
        return OutputList(head->next);
    } else {
        cout << "\n";
    }
}

void AddInfo(Node *NewElem) {

    cout << "Input ID: " << endl;
    (cin >> NewElem->ID).get();
    cout << "Input FIO: " << endl;
    getline(cin, NewElem->FIO);
    cout << "Input Group: " << endl;
    cin >> NewElem->Group;
}

void ChangeInfo(Node *NewElem) {

    cout << "Input ID: " << endl;
    (cin >> NewElem->ID).get();
    cout << "Input FIO: " << endl;
    getline(cin, NewElem->FIO);
    cout << "Input Group: " << endl;
    cin >> NewElem->Group;
}


int main()
{
    char key;
    int n, counter = 0;
    string str;

    Node *head = 0;
    Node *last = 0;

    while (key != 'x') {

        cout << endl;
        cout << "1. Add new Student at begin of list" << endl;
        cout << "2. Add new Student at the end of list" << endl;
        cout << "3. Add new Student at i-position of list" << endl;
        cout << "4. Change data on i-position" << endl;
        cout << "5. Delete Student on i-position" << endl;
        cout << "6. Show list" << endl;
        cout << "7. Delete list and exit" << endl;
        cout << "Input x for exit" << endl;
        cin >> key;

        switch (key) {

            case '1': {

                Node *NewElem = new Node;
                Node *OldElem = head;

                if (head == 0) {

                    AddInfo(NewElem);
                    NewElem->next = head;
                    head = NewElem;

                } else {

                    while (head->next != 0) {
                        head = head->next;
                        cout << head;
                    }

                    AddInfo(NewElem);

                    head->next = NewElem;
                    NewElem->next = last;
                    head = OldElem;

                }
                counter++;
                break;
            }

            case '2': {

                Node *NewElem = new Node;

                AddInfo(NewElem);
                NewElem->next = head;
                head = NewElem;
                counter++;
                break;

            }

            case '3': {

                int n = 0;

                Node *NextElem = head;
                Node *CurrElem;
                Node *NewElem = new Node;
                cout << "Input i-num of element: " << endl;
                cin >> n;

                if (n > counter+1 || n == 0) {
                    cout << "Error" << endl;
                    break;
                }

                if (n == 1) {
                    NewElem->next = head;
                    head = NewElem;
                    AddInfo(NewElem);
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
                    AddInfo(NewElem);
                    CurrElem->next = NewElem;
                }

                counter++;
                break;
            }

            case '4': {

                int n = 0;

                Node *NextElem = head;
                Node *CurrElem;
                cout << "Input i-num of element, that change: " << endl;
                cin >> n;

                if (n == 1) {
                    CurrElem = head;
                    ChangeInfo(CurrElem);
                } else {

                    CurrElem = head;

                    for (int i = 0; i < n-1; i++) {
                        CurrElem = CurrElem->next;
                        cout << CurrElem;
                    }

                    ChangeInfo(CurrElem);
                }

                break;
            }

            case '5': {

                int n = 0;
                cout << "Choose number of element for delete" << endl;
                //cout << head;
                cin >> n;

                if (counter == 0) {

                    cout << "Empty list " << endl;
                    break;
                } else if (!(n <= counter)) {
                    cout << "Error " << endl;
                    break;
                }

                Node *PrevElem = head;

                if (n == 1) {
                    head = PrevElem->next;
                    delete PrevElem;
                    break;
                }

                n -= 2;
                cout << n;

                    while (n != 0) {
                        PrevElem = PrevElem->next;
                        cout << n;
                        cout << "Prev = " << PrevElem;
                        cout << "Prev->next = " << PrevElem->next;
                        n--;
                   }


                Node *DeleteElem = PrevElem->next;
                PrevElem->next = DeleteElem->next;
                delete DeleteElem;
                break;
            }

            case '6': {

                Node *OutElem = head;
                OutputList(head);
                break;
            }

            case '7': {

                Node *CurrElem = head;
                while (CurrElem != 0) {
                    Node *Template = CurrElem;
                    CurrElem = CurrElem->next;
                    delete Template;
                }

                head = 0;
                key = 'x';
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


            while (OutElem) {
                    cout << "->" << OutElem->value << "(" << OutElem << ")";
                    cout << "ID: " << OutElem->ID << endl;
                    cout << "FIO: " << OutElem->FIO << endl;
                    cout << "Group: " << OutElem->Group << endl;
                    OutElem = OutElem->next;
                }
                break;

*/
