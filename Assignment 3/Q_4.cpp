#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char op) {
 if (op == '^') return 3;
 if (op == '*' || op == '/') return 2;
 if (op == '+' || op == '-') return 1;
 return -1;
}
string infixToPostfix(string expr) {
 stack<char> st;
 string result = "";
 for (char c : expr) {
 if (isalnum(c)) {
 result += c;
 }
 else if (c == '(') {
 st.push(c);
 }
 else if (c == ')') {
 while (!st.empty() && st.top() != '(') {
 result += st.top();
 st.pop();
 }
 if (!st.empty() && st.top() == '(') st.pop();
 }
 else {
 while (!st.empty() && precedence(st.top()) >= precedence(c)) {
 if (c == '^' && st.top() == '^') break;
 result += st.top();
 st.pop();
 }
 st.push(c);
 }
 }
 while (!st.empty()) {
 result += st.top();
 st.pop();
 }
 return result;
}
int main() {
 string expr;
 cout << "Enter infix expression: ";
 cin >> expr;
 cout << "Postfix expression: " << infixToPostfix(expr) << "\n";
 return 0;
}