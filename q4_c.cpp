#include <iostream>
using namespace std;
int main()
{
 int n,m;
 cout<<"Enter the no of rows: ";
 cin>>n;
 cout<<"Enter the no of columns: ";
 cin>>m;
 cout<<"Enter the elements of the matrix:";
 int mat1[n][m];
 for(int i=0; i<n;i++){
 for(int j=0; j<m; j++){
 cin>>mat1[i][j];
 }
 }
 cout<<"The original matrix is:\n";
 for(int i=0; i<n;i++){
 for(int j=0; j<m; j++){
 cout<<mat1[i][j]<<" ";
 }
 cout<<"\n";
 }

 cout<<"The transposed array is: \n";
 for(int i=0;i<m;i++){
 for(int j=0; j<n; j++){
 cout<<mat1[j][i]<<" ";
 }
 cout<<"\n";
 }
 return 0;
}