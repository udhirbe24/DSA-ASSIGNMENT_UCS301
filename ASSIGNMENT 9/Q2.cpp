#include <iostream>
#include <vector>
using namespace std;
class PriorityQueue {
 vector<int> heap;
 bool isMaxHeap; // true = Max Heap, false = Min Heap
 // Helper funcƟon to maintain heap property upwards
 void heapifyUp(int index) {
 int parent = (index - 1) / 2;
 while (index > 0) {
 bool shouldSwap = isMaxHeap ? heap[index] > heap[parent] : heap[index] <
heap[parent];
 if (shouldSwap) {
 swap(heap[index], heap[parent]);
 index = parent;
 parent = (index - 1) / 2;
 } else
 break;
 }
 }
 // Helper funcƟon to maintain heap property downwards
 void heapifyDown(int index) {
 int n = heap.size();
 while (true) {

 int left = 2 * index + 1;
 int right = 2 * index + 2;
 int extreme = index;
 if (isMaxHeap) {
 if (left < n && heap[left] > heap[extreme]) extreme = left;
 if (right < n && heap[right] > heap[extreme]) extreme = right;
 } else {
 if (left < n && heap[left] < heap[extreme]) extreme = left;
 if (right < n && heap[right] < heap[extreme]) extreme = right;
 }
 if (extreme != index) {
 swap(heap[index], heap[extreme]);
 index = extreme;
 } else
 break;
 }
 }
public:
 // Constructor
 PriorityQueue(bool maxHeap = true) { isMaxHeap = maxHeap; }
 // Insert element into the heap
 void insert(int value) {
 heap.push_back(value);
 heapifyUp(heap.size() - 1);

 }
 // Remove and return the highest (or lowest) priority element
 int extract() {
 if (heap.empty()) {
 cout << "Priority Queue is empty!\n";
 return -1;
 }
 int root = heap[0];
 heap[0] = heap.back();
 heap.pop_back();
 heapifyDown(0);
 return root;
 }
 // Peek top element
 int peek() {
 if (heap.empty()) {
 cout << "Priority Queue is empty!\n";
 return -1;
 }
 return heap[0];
 }
 // Display all elements
 void display() {
 if (heap.empty()) {
 cout << "Priority Queue is empty!\n";

 return;
 }
 for (int val : heap)
 cout << val << " ";
 cout << endl;
 }
 bool isEmpty() {
 return heap.empty();
 }
};
int main() {
 int choice, type;
 cout << "Choose type of Priority Queue:\n";
 cout << "1. Max Priority Queue\n2. Min Priority Queue\nEnter choice: ";
 cin >> type;
 PriorityQueue pq(type == 1); // true for MaxHeap, false for MinHeap
 do {
 cout << "\n--- Priority Queue Menu ---\n";
 cout << "1. Insert Element\n2. Extract Top\n3. Peek Top\n4. Display Queue\n5. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1: {

 int val;
 cout << "Enter value to insert: ";
 cin >> val;
 pq.insert(val);
 break;
 }
 case 2: {
 int top = pq.extract();
 if (top != -1)
 cout << "Extracted: " << top << endl;
 break;
 }
 case 3: {
 int top = pq.peek();
 if (top != -1)
 cout << "Top element: " << top << endl;
 break;
 }
 case 4:
 cout << "Current Queue: ";
 pq.display();
 break;
 case 5:
 cout << "ExiƟng...\n";
 break;
 default:
 cout << "Invalid choice!\n";
 }

 } while (choice != 5);
 return 0;
}