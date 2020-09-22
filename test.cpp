#include "SquareMatrix.h"
#include <iostream>
#include <string>
using namespace std;

void Test1()
{
    SquareMatrix<int> matrix_a, matrix_b;
    matrix_a._size = 10;
    matrix_b._size = 20;
    cout<< "Matrix A Size: "<< matrix_a._size;<< endl;
    cout<< "Matrix B Size: "<< matrix_a._size;<< endl;

}
int main()
{
    Test1();
    return 0;
}
