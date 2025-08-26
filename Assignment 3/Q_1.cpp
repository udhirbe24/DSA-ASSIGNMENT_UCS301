#include <iostream>
using namespace std;
#define MAX 5
class Stack {
 int arr[MAX];
 int top;
public:
 Stack() {
 top = -1;
 }
 void push(int x) {
 if (isFull()) {
 cout << "Stack Overflow\n";
 return;
 }
 arr[++top] = x;
 cout << x << " pushed into stack\n";
 }
 void pop() {
 if (isEmpty()) {
 cout << "Stack Underflow\n";
 return;
 }
 cout << arr[top--] << " popped from stack\n";
 }
 bool isEmpty() {
 return top == -1;
 }
 bool isFull() {
 return top == MAX - 1;
 }
 void display() {
 if (isEmpty()) {
 cout << "Stack is Empty\n";
 return;
 }
 cout << "Stack elements: ";
 for (int i = top; i >= 0; i--) {
 cout << arr[i] << " ";
 }
 cout << "\n";
 }
 void peek() {
 if (isEmpty()) {
 cout << "Stack is Empty\n";
 return;
 }
 cout << "Top element: " << arr[top] << "\n";
 }
};
int main() {
 Stack st;
 int choice, val;
 do {
 cout << "\n--- Stack Menu ---\n";
 cout << "1. Push\n";
 cout << "2. Pop\n";
 cout << "3. isEmpty\n";
 cout << "4. isFull\n";
 cout << "5. Display\n";
 cout << "6. Peek\n";
 cout << "7. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter value: ";
 cin >> val;
 st.push(val);
 break;
 case 2:
 st.pop();
 break;
 case 3:
 cout << (st.isEmpty() ? "Stack is Empty\n" : "Stack is not Empty\n");
 break;
 case 4:
 cout << (st.isFull() ? "Stack is Full\n" : "Stack is not Full\n");
 break;
 case 5:
 st.display();
 break;
 case 6:
 st.peek();
 break;
 case 7:
 cout << "Exiting...\n";
 break;
 default:
 cout << "Invalid choice\n";
 }
 } while (choice != 7);
 return 0;
}
