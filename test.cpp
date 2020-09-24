#include "SquareMatrix.h"
#include <iostream>
#include <string>
using namespace std;

void Test1()
{
    // This works
    SquareMatrix<int> matrix_a, matrix_b;
    cout<< "Matrix A Size: "<< matrix_a.size()<< endl;
    cout<< "Matrix B Size: "<< matrix_a.size()<< endl;
    SquareMatrix<int> matrix_c;
    cout<<matrix_c.size();

    //This works
    SquareMatrix<short> sh_matrix;
    sh_matrix.resize(2);
    cout<< "Matrix sh_matrix Size: "<< sh_matrix.size()<< endl;
    sh_matrix.at(0,0)=1;
    sh_matrix.at(0,1)=1;
    sh_matrix.at(1,0)=1;
    sh_matrix.at(1,1)=1;
    cout<< "Printing at():"<<sh_matrix.at(1,1)<<endl;

    //Strings Work
    SquareMatrix<string> string_matrix;
    string_matrix.resize(2);
    cout<< "Matrix string_matrix Size: "<< string_matrix.size()<< endl;
    string_matrix.at(0,0)= "Hello";
    string_matrix.at(0,1)="Goodbye";
    string_matrix.at(1,0)="Hola";
    string_matrix.at(1,1)="Adios";
    cout<< "Should print Adios: "<<string_matrix.at(1,1)<<endl;
    cout<< "should print Hello: "<<string_matrix.at(0,0)<<endl;
}
void Test2()
{
    SquareMatrix<int> matrix_a, matrix_b;
    cout<< "Matrix A Size: "<< matrix_a.size()<< endl;
    cout<< "Matrix B Size: "<< matrix_a.size()<< endl;

    matrix_a.resize(3);
    matrix_a.at(0,0)=1;
    matrix_a.at(0,1)=2;
    matrix_a.at(0,2)=3;
    matrix_a.at(1,0)=4;
    matrix_a.at(1,1)=5;
    matrix_a.at(1,2)=6;
    matrix_a.at(2,0)=7;
    matrix_a.at(2,1)=8;
    matrix_a.at(2,2)=9;

    matrix_b.resize(3);
    matrix_b.at(0,0)=9;
    matrix_b.at(0,1)=8;
    matrix_b.at(0,2)=7;
    matrix_b.at(1,0)=6;
    matrix_b.at(1,1)=5;
    matrix_b.at(1,2)=4;
    matrix_b.at(2,0)=3;
    matrix_b.at(2,1)=2;
    matrix_b.at(2,2)=1;

    cout<< "Matrix A Size: "<< matrix_a.size()<< endl;
    cout<< "Matrix B Size: "<< matrix_a.size()<< endl;
    cout<< "Should print Matrix A "<<matrix_a<<endl;
    cout<< "should print Matrix B "<<matrix_b<<endl;
    cout<< "Matrix A and be are equal or not: "<< matrix_a==matrix_b<< endl;
    cout<< "Matrix A + Matrix B equal: "<< matrix_a+matrix_b<< endl; 

}
int main()
{
    Test1();//works 
    Test2();//testing
    return 0;
}
