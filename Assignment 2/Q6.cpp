#include <iostream>
using namespace std;
struct Term {
 int row, col, value;
};
void readSparse(Term a[], int &rows, int &cols, int &nonZero) {
 cout << "Enter rows and columns: ";
 cin >> rows >> cols;
 cout << "Enter number of non-zero elements: ";
 cin >> nonZero;
 a[0].row = rows;
 a[0].col = cols;
 a[0].value = nonZero;
 cout << "Enter row, column, value for each non-zero element:\n";
 for (int i = 1; i <= nonZero; i++)
 cin >> a[i].row >> a[i].col >> a[i].value;
}
void displaySparse(Term a[]) {
 int n = a[0].value;
 cout << "Row Col Val\n";
 for (int i = 0; i <= n; i++)
 cout << a[i].row << " " << a[i].col << " " << a[i].value << endl;
}
void transposeSparse(Term a[], Term b[]) {
 int n = a[0].value;
 b[0].row = a[0].col;
 b[0].col = a[0].row;
 b[0].value = n;
 int q = 1;
 for (int col = 0; col < a[0].col; col++) {
 for (int i = 1; i <= n; i++) {
 if (a[i].col == col) {
 b[q].row = a[i].col;
 b[q].col = a[i].row;
 b[q].value = a[i].value;
 q++;
 }
 }
 }
}
void addSparse(Term a[], Term b[], Term c[]) {
 if (a[0].row != b[0].row || a[0].col != b[0].col) {
 cout << "Addition not possible\n";
 return;
 }
 int i = 1, j = 1, k = 1;
 while (i <= a[0].value && j <= b[0].value) {
 if (a[i].row < b[j].row ||
 (a[i].row == b[j].row && a[i].col < b[j].col))
 c[k++] = a[i++];
 else if (b[j].row < a[i].row ||
 (b[j].row == a[i].row && b[j].col < a[i].col))
 c[k++] = b[j++];
 else {
 c[k] = a[i];
 c[k++].value = a[i++].value + b[j++].value;
 }
 }
 while (i <= a[0].value) c[k++] = a[i++];
 while (j <= b[0].value) c[k++] = b[j++];
 c[0].row = a[0].row;
 c[0].col = a[0].col;
 c[0].value = k - 1;
}
void multiplySparse(Term a[], Term b[], Term c[]) {
 if (a[0].col != b[0].row) {
 cout << "Multiplication not possible\n";
 return;
 }
 Term bT[100];
 transposeSparse(b, bT);
 int k = 1;
 for (int i = 1; i <= a[0].value;) {
 int r = a[i].row;
 for (int j = 1; j <= bT[0].value;) {
 int col = bT[j].row;
 int sum = 0;
 int p = i, q = j;
 while (p <= a[0].value && a[p].row == r &&
 q <= bT[0].value && bT[q].row == col) {
 if (a[p].col < bT[q].col) p++;
 else if (a[p].col > bT[q].col) q++;
 else sum += a[p++].value * bT[q++].value;
 }
 if (sum != 0) {
 c[k].row = r;
 c[k].col = col;
 c[k].value = sum;
 k++;
 }
 while (q <= bT[0].value && bT[q].row == col) q++;
 }
 while (i <= a[0].value && a[i].row == r) i++;
 }
 c[0].row = a[0].row;
 c[0].col = b[0].col;
 c[0].value = k - 1;
}
int main() {
 Term a[100], b[100], c[100];
 int rows, cols, nonZero;
 cout << "Matrix A:\n";
 readSparse(a, rows, cols, nonZero);
 displaySparse(a);
 cout << "\nMatrix B:\n";
 readSparse(b, rows, cols, nonZero);
 displaySparse(b);
 cout << "\nTranspose of A:\n";
 transposeSparse(a, c);
 displaySparse(c);
 cout << "\nAddition (A + B):\n";
 addSparse(a, b, c);
 displaySparse(c);
 cout << "\nMultiplication (A * B):\n";
 multiplySparse(a, b, c);
 displaySparse(c);
 return 0;
}