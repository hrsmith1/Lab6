#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printing(int matrix[100][100], int n){
    for (int i = 0; i<n; ++i){
        for (int j = 0; j<n; ++j){
            cout << matrix[i][j];
            cout<<" ";
        }
        cout <<"\n";
    }
}
void sum(int matrix1[100][100], int matrix2[100][100], int n){
    int sumMatrix [100][100];
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    cout<<"Matrix(A+B)"<<endl;
    printing(sumMatrix, n);
}
void difference(int matrix1[100][100], int matrix2[100][100], int n){
    int difMatrix [100][100];
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            difMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    cout<<"Matrix(A-B)"<<endl;
    printing(difMatrix, n);
}
void multiplying(int matrix1[100][100], int matrix2[100][100], int n){
    int product [100][100];
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            int x = 0;
            int prod = 0;
            while(x<n){
                prod += matrix1[i][x]*matrix2[x][j];
                x++;
            }
            product[i][j]=prod;
        }
    }
    cout <<"Matrix Product (A*B)"<<endl;
    printing(product, n);
}
void readfile(string filename){
    int matrix1[100][100];
    int matrix2[100][100];
    ifstream inputfile;
    inputfile.open(filename);
    int n;
    inputfile >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            inputfile >> matrix1[i][j];
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            inputfile >> matrix2[i][j];
        }
    } 
    cout << "Matrix A"<< endl;
    printing(matrix1, n);
    cout << "Matrix B"<< endl;
    printing(matrix2, n);
    sum(matrix1, matrix2, n);
    multiplying(matrix1, matrix2, n);
    difference(matrix1, matrix2, n);

}
int main(){
    string filename;
    cout << "Enter the file name:";
    cin >> filename;
    cout << "Hannah Smith"<<endl;
    cout << "Lab #6: Matrix manipulation"<<endl;
    readfile(filename);
}
