#include <iostream>
using namespace std;
int main()
{
 int row1,row2,colm1,colm2;
 cout<<"enter the no. of rows in matrix 1: ";
 cin>>row1;

 cout<<"enter the no. of rows in matrix 2: ";
 cin>>row2;

 cout<<"enter the no. of columns in matrix 1: ";
 cin>>colm1;

 cout<<"enter the no. of columns in matrix 2: ";
 cin>>colm2;

 int mat1[row1][colm1], mat2[row2][colm2];
 cout<<"\nEnter the elements of matrix 1: ";
 for(int i=0; i<row1; i++){
 for(int j=0; j<colm1;j++){
 cin>>mat1[i][j];
 }
 }
 cout<<"the first matrix is:\n";
 for(int i=0; i<row1; i++){
 for(int j=0; j<colm1;j++){
 cout<<mat1[i][j]<<" ";
 }
 cout<<"\n";
 }
 cout<<"\nEnter the elements of matrix 2: ";
 for(int i=0; i<row2; i++){
 for(int j=0; j<colm2;j++){
 cin>>mat2[i][j];
 }
 }
 cout<<"the second matrix is:\n";
 for(int i=0; i<row2; i++){
 for(int j=0; j<colm2;j++){
 cout<<mat2[i][j]<<" ";
 }
 cout<<"\n";
 }
 if(colm1!=row2){
 cout<<"mulƟplicaƟon is not possible";
 }
 int mat3[row1][colm2];
 for(int i=0; i<row1; i++){
 for(int j=0; j<colm2; j++){
 mat3[i][j]=0;
 for(int k=0; k<row2; k++){
 mat3[i][j]+=mat1[i][k]*mat2[k][j];
 }
 }
 }
 cout<<"the mulƟpliacƟon of matrix gives:\n ";
 for(int i=0; i<row1; i++){
 for(int j=0; j<colm2; j++){
 cout<<mat3[i][j]<<" ";
 }
 cout<<"\n";
 }
 return 0;
}