#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


Node* head = NULL;


void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void displayList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


void findMiddle() {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;       
        fast = fast->next->next; 
    }

    cout << "Middle element is: " << slow->data << endl;
}


int main() {
   
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);

    cout << "Linked List: ";
    displayList();

    findMiddle();

    return 0;
}