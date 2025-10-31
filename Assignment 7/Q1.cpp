#include <iostream>
using namespace std;
// ---------- SELECTION SORT ----------
void selecƟonSort(int arr[], int n) {
 for(int i = 0; i < n - 1; i++) {
 int minIndex = i;
 for(int j = i + 1; j < n; j++) {
 if(arr[j] < arr[minIndex])
 minIndex = j;
 }
 swap(arr[i], arr[minIndex]);
 }
}
// ---------- INSERTION SORT ----------
void inserƟonSort(int arr[], int n) {
 for(int i = 1; i < n; i++) {
 int key = arr[i];
 int j = i - 1;
 while(j >= 0 && arr[j] > key) {
 arr[j + 1] = arr[j];
 j--;
 }
 arr[j + 1] = key;
 }
}
// ---------- BUBBLE SORT ----------
void bubbleSort(int arr[], int n) {
 for(int i = 0; i < n - 1; i++) {
 for(int j = 0; j < n - i - 1; j++) {
 if(arr[j] > arr[j + 1])
 swap(arr[j], arr[j + 1]);
 }
 }
}
// ---------- MERGE SORT ----------
void merge(int arr[], int l, int m, int r) {
 int n1 = m - l + 1;
 int n2 = r - m;
 int L[n1], R[n2];
 for(int i = 0; i < n1; i++)
 L[i] = arr[l + i];
 for(int j = 0; j < n2; j++)
 R[j] = arr[m + 1 + j];
 int i = 0, j = 0, k = l;
 while(i < n1 && j < n2) {
 if(L[i] <= R[j])
 arr[k++] = L[i++];
 else
 arr[k++] = R[j++];
 }
 while(i < n1)
 arr[k++] = L[i++];
 while(j < n2)
 arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r) {
 if(l < r) {
 int m = (l + r) / 2;
 mergeSort(arr, l, m);
 mergeSort(arr, m + 1, r);
 merge(arr, l, m, r);
 }
}
// ---------- QUICK SORT ----------
int parƟƟon(int arr[], int low, int high) {
 int pivot = arr[high];
 int i = low - 1;
 for(int j = low; j < high; j++) {
 if(arr[j] < pivot) {
 i++;
 swap(arr[i], arr[j]);
 }
 }
 swap(arr[i + 1], arr[high]);
 return (i + 1);
}
void quickSort(int arr[], int low, int high) {
 if(low < high) {
 int pi = parƟƟon(arr, low, high);
 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
 }
}
// ---------- DISPLAY FUNCTION ----------
void display(int arr[], int n) {
 for(int i = 0; i < n; i++)
 cout << arr[i] << " ";
 cout << endl;
}
// ---------- MAIN FUNCTION ----------
int main() {
 int n, choice;
 cout << "Enter number of elements: ";
 cin >> n;
 int arr[n];
 cout << "Enter elements: ";
 for(int i = 0; i < n; i++)
 cin >> arr[i];
 cout << "\nChoose SorƟng Method:\n";
 cout << "1. SelecƟon Sort\n";
 cout << "2. InserƟon Sort\n";
 cout << "3. Bubble Sort\n";
 cout << "4. Merge Sort\n";
 cout << "5. Quick Sort\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch(choice) {
 case 1:
 selecƟonSort(arr, n);
 cout << "Sorted using SelecƟon Sort:\n";
 break;
 case 2:
 inserƟonSort(arr, n);
 cout << "Sorted using InserƟon Sort:\n";
 break;
 case 3:
 bubbleSort(arr, n);
 cout << "Sorted using Bubble Sort:\n";
 break;
 case 4:
 mergeSort(arr, 0, n - 1);
 cout << "Sorted using Merge Sort:\n";
 break;
 case 5:
 quickSort(arr, 0, n - 1);
 cout << "Sorted using Quick Sort:\n";
 break;
 default:
 cout << "Invalid choice!\n";
 return 0;
 }
 display(arr, n);
 return 0;
}