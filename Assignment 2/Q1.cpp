#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int target) {
for (int i = 0; i < n; i++) {
if (arr[i] == target)
return i;
}
return -1;
}
int binarySearch(int arr[], int n, int target) {
int low = 0, high = n - 1;
while (low <= high) {
int mid = (low + high) / 2;
if (arr[mid] == target)
return mid;
else if (arr[mid] < target)
low = mid + 1;
else
high = mid - 1;
}
return -1;
}
int main() {
int arr[] = {2, 4, 6, 8, 10, 12};
int n = sizeof(arr) / sizeof(arr[0]);
int target = 10;
int linearIndex = linearSearch(arr, n, target);
int binaryIndex = binarySearch(arr, n, target);
cout << linearIndex << endl;
cout << binaryIndex << endl;
return 0;
}
