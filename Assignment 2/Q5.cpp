#include <iostream>
using namespace std;
class DiagonalMatrix {
 int *A, n;
public:
 DiagonalMatrix(int size) {
 n = size;
 A = new int[n];
 for (int i = 0; i < n; i++) A[i] = 0;
 }
 void set(int i, int j, int x) {
 if (i == j) A[i - 1] = x;
 }
 int get(int i, int j) {
 if (i == j) return A[i - 1];
 else return 0;
 }
 void display() {
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++) {
 cout << get(i, j) << " ";
 }
 cout << endl;
 }
 }
 ~DiagonalMatrix() { delete[] A; }
};
class LowerTriangular {
 int *A, n;
public:
 LowerTriangular(int size) {
 n = size;
 A = new int[n * (n + 1) / 2];
 for (int i = 0; i < n * (n + 1) / 2; i++) A[i] = 0;
 }
 void set(int i, int j, int x) {
 if (i >= j) A[i * (i - 1) / 2 + (j - 1)] = x;
 }
 int get(int i, int j) {
 if (i >= j) return A[i * (i - 1) / 2 + (j - 1)];
 else return 0;
 }
 void display() {
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++) {
 cout << get(i, j) << " ";
 }
 cout << endl;
 }
 }
 ~LowerTriangular() { delete[] A; }
};
class UpperTriangular {
 int *A, n;
public:
 UpperTriangular(int size) {
 n = size;
 A = new int[n * (n + 1) / 2];
 for (int i = 0; i < n * (n + 1) / 2; i++) A[i] = 0;
 }
 void set(int i, int j, int x) {
 if (i <= j) A[(j * (j - 1) / 2) + (i - 1)] = x;
 }
 int get(int i, int j) {
 if (i <= j) return A[(j * (j - 1) / 2) + (i - 1)];
 else return 0;
 }
 void display() {
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++) {
 cout << get(i, j) << " ";
 }
 cout << endl;
 }
 }
 ~UpperTriangular() { delete[] A; }
};
class SymmetricMatrix {
 int *A, n;
public:
 SymmetricMatrix(int size) {
 n = size;
 A = new int[n * (n + 1) / 2];
 for (int i = 0; i < n * (n + 1) / 2; i++) A[i] = 0;
 }
 void set(int i, int j, int x) {
 if (i >= j) A[i * (i - 1) / 2 + (j - 1)] = x;
 else A[j * (j - 1) / 2 + (i - 1)] = x;
 }
 int get(int i, int j) {
 if (i >= j) return A[i * (i - 1) / 2 + (j - 1)];
 else return A[j * (j - 1) / 2 + (i - 1)];
 }
 void display() {
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++) {
 cout << get(i, j) << " ";
 }
 cout << endl;
 }
 }
 ~SymmetricMatrix() { delete[] A; }
};
class TridiagonalMatrix {
 int *A, n;
public:
 TridiagonalMatrix(int size) {
 n = size;
 A = new int[3 * n - 2];
 for (int i = 0; i < 3 * n - 2; i++) A[i] = 0;
 }
 void set(int i, int j, int x) {
 if (i - j == 1) A[i - 2] = x;
 else if (i == j) A[n - 1 + (i - 1)] = x;
 else if (j - i == 1) A[2 * n - 1 + (i - 1)] = x;
 }
 int get(int i, int j) {
 if (i - j == 1) return A[i - 2];
 else if (i == j) return A[n - 1 + (i - 1)];
 else if (j - i == 1) return A[2 * n - 1 + (i - 1)];
 else return 0;
 }
 void display() {
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++) {
 cout << get(i, j) << " ";
 }
 cout << endl;
 }
 }
 ~TridiagonalMatrix() { delete[] A; }
};
int main() {
 int choice, n, x;
 cout << "Enter dimension of matrix: ";
 cin >> n;
 cout << "\nMatrix Types:\n";
 cout << "1. Diagonal Matrix\n";
 cout << "2. Tri-diagonal Matrix\n";
 cout << "3. Lower Triangular Matrix\n";
 cout << "4. Upper Triangular Matrix\n";
 cout << "5. Symmetric Matrix\n";
 cout << "Enter choice: ";
 cin >> choice;
 if (choice == 1) {
 DiagonalMatrix m(n);
 cout << "Enter elements:\n";
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++) {
 cin >> x;
 m.set(i, j, x);
 }
 }
 cout << "Stored Matrix:\n";
 m.display();
 }
 else if (choice == 2) {
 TridiagonalMatrix m(n);
 cout << "Enter elements:\n";
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++) {
 cin >> x;
 m.set(i, j, x);
 }
 }
 cout << "Stored Matrix:\n";
 m.display();
 }
 else if (choice == 3) {
 LowerTriangular m(n);
 cout << "Enter elements:\n";
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++) {
 cin >> x;
 m.set(i, j, x);
 }
 }
 cout << "Stored Matrix:\n";
 m.display();
 }
 else if (choice == 4) {
 UpperTriangular m(n);
 cout << "Enter elements:\n";
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++) {
 cin >> x;
 m.set(i, j, x);
 }
 }
 cout << "Stored Matrix:\n";
 m.display();
 }
 else if (choice == 5) {
 SymmetricMatrix m(n);
 cout << "Enter elements:\n";
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++) {
 cin >> x;
 m.set(i, j, x);
 }
 }
 cout << "Stored Matrix:\n";
 m.display();
 }
 else {
 cout << "Invalid choice\n";
 }
 return 0;
}