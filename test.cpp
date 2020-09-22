#include <SquareMatrix.h>
#include <iostream>
#include <string>
using namespace std;

void Test1()
{
    SquareMatrix<int> matrix_a, matrix_b;
    cout<< "Matrix A Size: "<< matrix_a._size;<< endl;
    cout<< "Matrix B Size: "<< matrix_a._size;<< endl;

    SquareMatrix<int> matrix_c{1};
    cout<<"Matrix C" << matrix_c <<endl;
    matrix_a.resize(6);
    cout<< "Matrix A Size: "<< matrix_a._size;<< endl;
    SquareMatrix<int> matrix_d{matrix_a}; 
    cout<<"Matrix D" << matrix_d <<endl;
    SquareMatrix<int> matrix_e = move(matrix_d); 
    cout<<"Matrix E" << matrix_e <<endl;
    matrix_b = move(e);
    cout<<"Matrix B" << matrix_b <<endl;
    cout<<"Matrix E" << matrix_e <<endl;




}
int main()
{
    Test1();
    return 0;
}
