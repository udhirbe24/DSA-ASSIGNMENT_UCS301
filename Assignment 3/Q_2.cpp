#include <iostream>
#include <string>
using namespace std;
#define MAX 100
class Stack {
 char arr[MAX];
 int top;
public:
 Stack() {
 top = -1;
 }
 void push(char ch) {
 if (top == MAX - 1) return;
 arr[++top] = ch;
 }
 char pop() {
 if (top == -1) return '\0';
 return arr[top--];
 }
 bool isEmpty() {
 return top == -1;
 }
};
int main() {
 string str, rev = "";
 cout << "Enter a string: ";
 cin >> str;
 Stack st;
 for (char c : str) {
 st.push(c);
 }
 while (!st.isEmpty()) {
 rev += st.pop();
 }
 cout << "Reversed string: " << rev << "\n";
 return 0;
}