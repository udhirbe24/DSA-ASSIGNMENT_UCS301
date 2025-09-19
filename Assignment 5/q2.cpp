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
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int deleteAllOccurrences(int key) {
    int count = 0;

   
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }

    return count;
}


int main() {
    
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(1);
    insertAtEnd(3);
    insertAtEnd(1);

    cout << "Original List: ";
    displayList();

    int key = 1;
    int occurrences = deleteAllOccurrences(key);

    cout << "Number of occurrences of " << key << " = " << occurrences << endl;

    cout << "List after deletion: ";
    displayList();

    return 0;
}