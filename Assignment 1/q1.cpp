#include <iostream>
using namespace std;
#define MAX_SIZE 100
int arr[MAX_SIZE];
int n = 0; // Number of elements in array
void createArray() {
 cout<<"Enter number of elements: ";
 cin>>n;
 if (n>MAX_SIZE) {
 cout<<"Exceeds maximum size. Seƫng to "<<MAX_SIZE<<endl;
 n=MAX_SIZE;
 }
 cout<<"Enter "<<n<<" elements: ";
 for (int i=0;i<n;i++) {
 cin>>arr[i];
 }
}
void displayArray() {
 if (n==0) {
 cout<<"Array is empty!"<<endl;
 return;
 }
 cout<<"Array elements: ";
 for (int i=0;i<n;i++) {
 cout<<arr[i]<<" ";
 }
 cout<<endl;
}
void insertElement() {
 if (n>=MAX_SIZE) {
 cout<<"Array is full! Cannot insert."<<endl;
 return;
 }
 int pos, val;
 cout<<"Enter posiƟon (0 to "<<n<<"): ";
 cin>>pos;
 cout<<"Enter value: ";
 cin>>val;
 if (pos<0||pos>n) {
 cout<<"Invalid posiƟon!"<<endl;
 return;
 }
 for (int i=n;i>pos;i--)
 arr[i]=arr[i - 1];
 arr[pos]=val;
 n++;
 cout<<"Element inserted."<<endl;
 }
void deleteElement() {
 if (n==0) {
 cout<<"Array is empty!"<<endl;
 return;
 }
 int pos;
 cout<<"Enter posiƟon (0 to "<<n-1<<"): ";
 cin>>pos;
 if (pos<0||pos>=n) {
 cout<<"Invalid posiƟon!"<<endl;
 return;
 }
 for (int i=pos;i<n-1;i++) {
 arr[i]=arr[i+1];
 }
 n--;
 cout<<"Element deleted."<<endl;
 }
void linearSearch() {
 if (n==0) {
 cout<<"Array is empty!"<<endl;
 return;
 }
 int key;
 cout<<"Enter element to search: ";
 cin>>key;
 for (int i=0;i<n;i++) {
 if (arr[i]==key) {
 cout<<"Element found at posiƟon "<<i<<endl;
 return;
 }
 }
 cout<<"Element not found."<<endl;
}
int main() {
 int choice;
 do {
 cout<<"\n——MENU——"<<endl;
 cout<<"1. CREATE"<<endl;
 cout<<"2. DISPLAY"<<endl;
 cout<<"3. INSERT"<<endl;
 cout<<"4. DELETE"<<endl;
 cout<<"5. LINEAR SEARCH"<<endl;
 cout<<"6. EXIT"<<endl;
 cout<<"Enter your choice: ";
 cin>>choice;
 switch (choice) {
 case 1: createArray();
 break;
 case 2: displayArray();
 break;
 case 3: insertElement();
 break;
 case 4: deleteElement();
 break;
 case 5: linearSearch();
 break;
 case 6: cout<<"ExiƟng program."<<endl;
 break;
 default: cout<<"Invalid choice! Try again."<<endl;
 }
 } while (choice!=6);
 return 0;
 }
