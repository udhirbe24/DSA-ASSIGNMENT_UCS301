#include <iostream>
using namespace std;

#define CAP 10

int qArr[CAP];
int front = -1, rear = -1;

bool isFull() { return ((rear + 1) % CAP == front); }
bool isEmpty() { return (front == -1); }

void enQ(int val) {
if (isFull()) {
cout << "\nQueue Full\n";
return;
}
if (front == -1) front = 0;
rear = (rear + 1) % CAP;
qArr[rear] = val;
}

void deQ() {
if (isEmpty()) {
cout << "\nQueue Empty\n";
return;

Dsa TUT 4

}
cout << "\nDequeued: " << qArr[front] << "\n";
if (front == rear) front = rear = -1;
else front = (front + 1) % CAP;
}

void disp() {
if (isEmpty()) {
cout << "\nQueue Empty\n";
return;
}
cout << "\nQueue: ";
int i = front;
while (true) {
cout << qArr[i] << " ";
if (i == rear) break;
i = (i + 1) % CAP;
}
cout << "\n";
}

int main() {
int ch, val;
do {
cout << "\n1.EnQ 2.DeQ 3.Disp 0.Exit\n> ";
cin >> ch;

Dsa TUT 4

if (ch == 1) {
cout << "Value: ";
cin >> val;
enQ(val);
} else if (ch == 2) {
deQ();
} else if (ch == 3) {
disp();
}
} while (ch != 0);
return 0;
}