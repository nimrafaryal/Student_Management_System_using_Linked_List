#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    Node* next;

    Node(int node_id, string student_name) {
        id = node_id;
        name = student_name;
        next = NULL;
    }
};

void addAtEnd(Node* &head, int id, string name) {
    Node* n = new Node(id, name);
    if (head == NULL) {
        head = n;
        return;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void deleteStudentById(Node* &head, int studentId) {
    if (head == NULL)
        cout << "\033[1;31mStudent Database is empty.\033[0m" << endl;
    else {
        Node* temp = head;
        Node* prev = NULL;
        if (temp != NULL && temp->id == studentId) {
            head = temp->next;
            delete temp;
            cout << "\033[1;32mStudent deleted successfully!\033[0m" << endl;
            return;
        }
        while (temp != NULL && temp->id != studentId) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "\033[1;31mStudent with ID " << studentId << " not found.\033[0m" << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "\033[1;32mStudent deleted successfully!\033[0m" << endl;
    }
}

void print(Node* head) {
    Node* temp = head;
    if (temp == NULL)
        cout << "\033[1;31mNULL\033[0m" << endl;
    else {
        while (temp != NULL) {
            cout << "\033[1;34m(" << temp->name << ", " << temp->id << ")\033[0m";
            if (temp->next != NULL) {
                cout << " \033[1;34m-> \033[0m";
            }
            temp = temp->next;
        }
    }
}

void bubbleSort(Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    bool swapped;
    Node* temp;
    Node* last = NULL;

    do {
        swapped = false;
        temp = head;

        while (temp->next != last) {
            if (temp->name > temp->next->name) {
                int tempId = temp->id;
                string tempName = temp->name;

                temp->id = temp->next->id;
                temp->name = temp->next->name;

                temp->next->id = tempId;
                temp->next->name = tempName;

                swapped = true;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);
}

bool searchByName(Node* head, string studentName, int &id) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->name == studentName) {
            id = temp->id;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    cout << "\033[1;33m*********************************************" << endl;
    cout << "*              STUDENT DATABASE             *" << endl;
    cout << "*            NIMRA FARYAL (22-CS-36)        *" << endl;;
    cout << "*********************************************\033[0m" << endl;

    string name;
    int id, n, studentId;
    Node* head = NULL;
    int student_id = 1; // Starting ID for students
    
    do {
        cout << "\n\n\033[1;32mPress 1 TO ADD A STUDENT.\033[0m" << endl;
        cout << "\033[1;32mPress 2 TO SEARCH BY STUDENT NAME.\033[0m" << endl;
        cout << "\033[1;32mPress 3 TO DELETE A STUDENT BY ID.\033[0m" << endl;
        cout << "\033[1;32mPress 4 TO DISPLAY ALL STUDENTS.\033[0m" << endl;
        cout << "\033[1;32mPress 0 TO EXIT.\033[0m" << endl << endl;
        cout << "\033[1;32mENTER YOUR CHOICE: \033[0m";
        cin >> n;

        switch (n) {
            case 1:
                cout << "\033[1;36mEnter the Name of Student: \033[0m";
                cin.ignore();
                getline(cin, name);
                addAtEnd(head, student_id++, name);
                cout << "\033[1;32mStudent added successfully!\033[0m" << endl;
                break;

            // ... (Remaining cases remain unchanged)
           case 2:
                cout<<"Enter student name to search: ";
                cin.ignore();
                getline(cin, name);
                if(searchByName(head, name, id))
                    cout<<"Student found! ID: "<<id<<endl;
                else
                    cout<<"Student not found."<<endl;
                break;
                
            case 3:
                cout<<"Enter student ID to delete: ";
                cin>>studentId;
                deleteStudentById(head, studentId);
                break;
                
            case 4:
                cout<<"Before Sorting: "<<endl;
                print(head);
                bubbleSort(head);
                cout<<"\nAfter Sorting: "<<endl;
                print(head);
                break;

            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                return 0; // Exiting the program
                break;

            default:
                cout << "\033[1;31mInvalid input\033[0m" << endl;
        }
    } while (true); // Loop until user chooses to exit

    return 0;
}
