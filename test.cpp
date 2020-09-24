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
    sh_matrix.at(0,0)=1;
    sh_matrix.at(0,1)=1;
    sh_matrix.at(1,0)=1;
    sh_matrix.at(1,1)=1;

}
int main()
{
    Test1();
    return 0;
}
