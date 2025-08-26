#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(string expr) {
 stack<char> st;
 for (char c : expr) {
 if (c == '(' || c == '{' || c == '[') {
 st.push(c);
 }
 else if (c == ')' || c == '}' || c == ']') {
 if (st.empty()) return false;
 char top = st.top();
 st.pop();
 if ((c == ')' && top != '(') ||
 (c == '}' && top != '{') ||
 (c == ']' && top != '[')) {
 return false;
 }
 }
 }
 return st.empty();
}
int main() {
 string expr;
 cout << "Enter expression: ";
 cin >> expr;
 if (isBalanced(expr))
 cout << "Balanced Expression\n";
 else
 cout << "Not Balanced Expression\n";
 return 0;
}