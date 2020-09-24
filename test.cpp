#include "SquareMatrix.h"
#include <iostream>
#include <string>
using namespace std;

void Test1()
{
    SquareMatrix<int> matrix_a, matrix_b;
    cout<< "Matrix A Size: "<< matrix_a.size()<< endl;
    cout<< "Matrix B Size: "<< matrix_a.size()<< endl;
    SquareMatrix<int> matrix_c;
    cout<<matrix_c.size();

    SquareMatrix<short> sh_matrix;
    sh_matrix.resize(2);
    cout<< "Matrix sh_matrix Size: "<< sh_matrix.size()<< endl;
    sh_matrix.at(0,0)=1;
    sh_matrix.at(0,1)=1;
    sh_matrix.at(1,0)=1;
    sh_matrix.at(1,1)=1;
    cout<< "Printing at():"<<sh_matrix.at(1,1)<<endl;

    SquareMatrix<string> string_matrix;
    string_matrix.resize(2);
    cout<< "Matrix string_matrix Size: "<< string_matrix.size()<< endl;
    sh_matrix.at(0,0)= "Hello";
    sh_matrix.at(0,1)="Goodbye";
    sh_matrix.at(1,0)="Hola";
    sh_matrix.at(1,1)="Adios";
    cout<< "Should print adios"<<string_matrix.at(1,1)<<endl;
    cout<< "should print hello"<<string_matrix.at(0,0)<<endl;


    
}
int main()
{
    Test1();
    return 0;
}
