#pragma once

template<typename T>

class SquareMatrix
{
private:
    T* _ptr;
    size_t _size;
public:
    SquareMatrix(); //default constructor

    //Big Five
    ~SquareMatrix(); //deconstructo 
    SquareMatrix(const SquareMatrix& trg); //copy constructor
    SquareMatrix(SquareMatrix&& trg); //move constructor
    SquareMatrix& operator=(const SquareMatrix& rhs); //copy assignment
    SquareMatrix& operator=(SquareMatrix&& rhs); //move assignment

};

SquareMatrix::SquareMatrix(/* args */)
{
}

SquareMatrix::~SquareMatrix()
{
}


//Due October 5