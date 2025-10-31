#include <iostream>
using namespace std;
// ---------- IMPROVED SELECTION SORT ----------
void improvedSelecƟonSort(int arr[], int n) {
 int start = 0, end = n - 1;
 while (start < end) {
 int minIndex = start;
 int maxIndex = start;
 // Find the minimum and maximum elements in the unsorted range
 for (int i = start; i <= end; i++) {
 if (arr[i] < arr[minIndex])
 minIndex = i;
 if (arr[i] > arr[maxIndex])
 maxIndex = i;
 }
 // Swap the minimum element to its correct posiƟon (start)
 swap(arr[start], arr[minIndex]);
 // Adjust maxIndex if it was poinƟng to start (because we just swapped)
 if (maxIndex == start)
 maxIndex = minIndex;
 // Swap the maximum element to its correct posiƟon (end)
 swap(arr[end], arr[maxIndex]);
 // Move the boundaries inward
 start++;
 end--;
 }
}
// ---------- DISPLAY FUNCTION ----------
void display(int arr[], int n) {
 for (int i = 0; i < n; i++)
 cout << arr[i] << " ";
 cout << endl;
}
// ---------- MAIN FUNCTION ----------
int main() {
 int n;
 cout << "Enter number of elements: ";
 cin >> n;
 int arr[n];
 cout << "Enter elements: ";
 for (int i = 0; i < n; i++)
 cin >> arr[i];
 improvedSelecƟonSort(arr, n);
 cout << "\nSorted array using Improved SelecƟon Sort:\n";
 display(arr, n);
 return 0;
}