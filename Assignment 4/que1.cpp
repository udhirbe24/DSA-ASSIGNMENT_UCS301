#include <iostream>
using namespace std;

#define CAP 10

int qArr[CAP];
int front = -1, rear = -1;

bool isFull() { return rear == CAP - 1; }
bool isEmpty() { return front == -1; }

void enQ(int val) {
if (isFull()) {
cout << "\nQueue Full\n";
return;
}
if (front == -1) front = 0;
rear++;
qArr[rear] = val;
}

void deQ() {
if (isEmpty() || front > rear) {
cout << "\nQueue Empty\n";
return;
}

Dsa TUT 4
cout << "\nDequeued: " << qArr[front] << "\n";
front++;
if (front > rear) front = rear = -1;
}

void disp() {
if (isEmpty()) {
cout << "\nQueue Empty\n";
return;
}
cout << "\nQueue: ";
for (int i = front; i <= rear; i++) cout << qArr[i] << " ";
cout << "\n";
}

int main() {
int ch, val;
do {
cout << "\n1.EnQ 2.DeQ 3.Disp 0.Exit\n> ";
cin >> ch;
if (ch == 1) {
cout << "Value: ";
cin >> val;
enQ(val);
} else if (ch == 2) {
deQ();

Dsa TUT 4

} else if (ch == 3) {
disp();
}
} while (ch != 0);
return 0;
}