#include <iostream>
using namespace std;

// FuncƟon to heapify subtree rooted at index i
void heapify(int arr[], int n, int i, bool isMaxHeap) {
 int extreme = i; // index of largest (for max heap) or smallest (for min heap)
 int left = 2 * i + 1; // leŌ child index
 int right = 2 * i + 2; // right child index
 if (isMaxHeap) {
 // For max heap (used for increasing order)
 if (left < n && arr[left] > arr[extreme])
 extreme = left;
 if (right < n && arr[right] > arr[extreme])
 extreme = right;
 } else {
 // For min heap (used for decreasing order)
 if (left < n && arr[left] < arr[extreme])
 extreme = left;
 if (right < n && arr[right] < arr[extreme])
 extreme = right;
 }
 // If the extreme is not the root, swap and conƟnue heapifying
 if (extreme != i) {
 swap(arr[i], arr[extreme]);
 heapify(arr, n, extreme, isMaxHeap);

 }
}
// FuncƟon to perform Heap Sort
void heapSort(int arr[], int n, bool increasing = true) {
 bool isMaxHeap = increasing; // Max heap for increasing, Min heap for decreasing
 // Step 1: Build heap
 for (int i = n / 2 - 1; i >= 0; i--)
 heapify(arr, n, i, isMaxHeap);
 // Step 2: Extract elements from heap one by one
 for (int i = n - 1; i > 0; i--) {
 swap(arr[0], arr[i]); // Move root to end
 heapify(arr, i, 0, isMaxHeap); // Heapify reduced heap
 }
 // If we used a Min Heap for decreasing order, the array is reversed.
 // So, reverse it to get proper decreasing order.
 if (!increasing) {
 for (int i = 0; i < n / 2; i++)
 swap(arr[i], arr[n - i - 1]);
 }
}
int main() {
 int n;
 cout << "Enter number of elements: ";

 cin >> n;
 int arr[n];
 cout << "Enter elements: ";
 for (int i = 0; i < n; i++)
 cin >> arr[i];
 int choice;
 cout << "\n1. Increasing Order\n2. Decreasing Order\nEnter your choice: ";
 cin >> choice;
 if (choice == 1)
 heapSort(arr, n, true);
 else
 heapSort(arr, n, false);
 cout << "\nSorted array: ";
 for (int i = 0; i < n; i++)
 cout << arr[i] << " ";
 cout << endl;
 return 0;
}