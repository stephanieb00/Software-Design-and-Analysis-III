#include "SquareMatrix.h"
#include <iostream>
#include <string>
using namespace std;

void Test1()
{
    SquareMatrix<int> matrix_a, matrix_b;
    cout<< "Matrix A Size: "<< matrix_a.size()<< endl;
    cout<< "Matrix B Size: "<< matrix_a.size()<< endl;

}
int main()
{
    Test1();
    return 0;
}
