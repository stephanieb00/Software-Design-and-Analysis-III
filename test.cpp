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
    cout<<"Matrix C Size:"<<matrix_c.size()<<endl;

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
    SquareMatrix<int> matrix_a, matrix_b,matrix_c;
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

    matrix_c.resize(3);
    matrix_c.at(0,0)=1;
    matrix_c.at(0,1)=2;
    matrix_c.at(0,2)=3;
    matrix_c.at(1,0)=4;
    matrix_c.at(1,1)=5;
    matrix_c.at(1,2)=6;
    matrix_c.at(2,0)=7;
    matrix_c.at(2,1)=8;
    matrix_c.at(2,2)=9;

    cout<<"Matrix A"<<endl;
    for (size_t i = 0; i < matrix_a.size(); i++)
    {
        for (size_t j = 0; j <matrix_a.size() ; j++)
        {
           cout<<matrix_a.at(i,j);
        }
        cout<<endl;
    }
    cout<<"Matrix B"<<endl;
    for (size_t i = 0; i < matrix_b.size(); i++)
    {
        for (size_t j = 0; j <matrix_b.size() ; j++)
        {
           cout<<matrix_b.at(i,j);
        }
        cout<<endl;
    }

    cout<< "Matrix A Size: "<< matrix_a.size()<< endl;
    cout<< "Matrix B Size: "<< matrix_a.size()<< endl;
    cout<< "Should print 3 "<<matrix_a.at(0,2)<<endl;
    cout<< "should print 7 "<<matrix_b.at(0,2)<<endl;
    if (matrix_a == matrix_b)
    {
        cout<< "Matrix A and B is equal" << endl;
    }
    else{
        cout<< "Matrix A and B is not equal "<< endl;
    }//should print not equal

    if (matrix_a == matrix_c)
    {
        cout<< "Matrix A and C is equal" << endl;
    }
    else{
        cout<< "Matrix A and C is not equal "<< endl;
    }//should print equal
}

void Test3()
{
    SquareMatrix<int> matrix_a, matrix_b,matrix_c;
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

    matrix_c = matrix_a+ matrix_b;

    //This Should all print out 10. 
    cout<<"Matrix C"<<endl;
    for (size_t i = 0; i < matrix_c.size(); i++)
    {
        for (size_t j = 0; j <matrix_c.size() ; j++)
        {
           cout<<matrix_c.at(i,j);
        }
        cout<<endl;
    }

}
int main()
{
    Test1();//works 
    Test2();//works
    Test3();//works
    return 0;
}