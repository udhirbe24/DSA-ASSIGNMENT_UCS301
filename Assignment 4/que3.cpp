#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void printQ(queue<int> q) {
while (!q.empty()) {
cout << q.front() << " ";
q.pop();
}
cout << "\n";
}

int main() {
queue<int> q;
int n;
cout << "Enter even count: ";
cin >> n;

if (n % 2 != 0) {
cout << "Count must be even.\n";
return 1;
}

cout << "Enter " << n << " elements: ";

Dsa TUT 4

for (int i = 0; i < n; ++i) {
int val;
cin >> val;
q.push(val);
}

stack<int> stk;
int h = n / 2;

for (int i = 0; i < h; ++i) {
stk.push(q.front());
q.pop();
}
while (!stk.empty()) {
q.push(stk.top());
stk.pop();
}
for (int i = 0; i < h; ++i) {
q.push(q.front());
q.pop();
}
for (int i = 0; i < h; ++i) {
stk.push(q.front());
q.pop();
}
while (!stk.empty()) {

Dsa TUT 4

q.push(stk.top());
stk.pop();
q.push(q.front());
q.pop();
}

cout << "Interleaved: ";
printQ(q);

return 0;
}