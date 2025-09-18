#include <iostream>
#include <queue>
using namespace std;

struct Stk2Q {
queue<int> q1, q2;
void push(int val) {
q2.push(val);
while (!q1.empty()) {
q2.push(q1.front());
q1.pop();
}
swap(q1, q2);
}
void pop() {
if (q1.empty()) return;
q1.pop();
}
};

struct Stk1Q {
queue<int> q1;
void push(int val) {
int size = q1.size();
q1.push(val);

Dsa TUT 4

for (int i = 0; i < size; i++) {
q1.push(q1.front());
q1.pop();
}
}
void pop() {
if (q1.empty()) return;
q1.pop();
}
};

int main() {
// This example demonstrates usage, not a menu
cout << "Stack with Two Queues:\n";
Stk2Q s2q;
s2q.push(1);
s2q.push(2);
s2q.push(3);
cout << "Top is " << s2q.q1.front() << endl; // 3
s2q.pop();
cout << "Top is " << s2q.q1.front() << endl; // 2

cout << "\nStack with One Queue:\n";
Stk1Q s1q;
s1q.push(10);
s1q.push(20);

Dsa TUT 4

s1q.push(30);
cout << "Top is " << s1q.q1.front() << endl; // 30
s1q.pop();
cout << "Top is " << s1q.q1.front() << endl; // 20

return 0;
}