#include <iostream>
using namespace std;
int main()
{
 int rows, cols;
 cout<<"Enter number of rows: ";
 cin>>rows;
 cout<<"Enter number of columns: ";
 cin>>cols;

 int arr[100][100];
 cout<<"\nEnter " <<rows*cols <<" elements for the matrix:"<<endl;

 for (int i=0; i<rows; i++) {
 for (int j=0; j<cols; j++) {
 cout<<"Element at ["<<i+1<<"]["<<j+1<<"]:";
 cin>>arr[i][j];
 }
 }

 cout<<"\nThe matrix is:"<<endl;
 for(int i=0; i<rows; i++) {
 for (int j=0; j<cols; j++) {
 cout<<arr[i][j]<<"\t";
 }
 cout<<endl;
 }

 cout<<"\nSum of each row:"<<endl;
 for (int i=0; i<rows; i++) {
 int rowSum = 0;
 for (int j=0; j<cols; j++) {
 rowSum +=arr[i][j];
 }
 cout<<"Row "<<i+1<<" sum = "<<rowSum<<endl;
 }
 cout<<"\nSum of each column:"<<endl;
 for(int j=0; j<cols; j++) {
 int colSum=0;
 for (int i=0; i<rows; i++) {
 colSum += arr[i][j];
 }
 cout<<"Column "<<j+1<<" sum = "<<colSum<<endl;
 }
 return 0;
}