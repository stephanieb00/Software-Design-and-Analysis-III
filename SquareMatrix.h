#pragma once

#include <iostream>
#include <cstddef>

using namespace std;

template<typename T>

class SquareMatrix
{
private:
    T **_ptr; //2 dimensional array pointer. 
    size_t _size;
public:
    /*
        @param: default constructor
        @param: initialize _size and _ptr
    */
    SquareMatrix(){
        _size = 0;
        _ptr = nullptr;
    }//end of default constructor.
    
    /*
        @param: parameterized constructor
        @param: initialize _size and _ptr
        this is to help the operator+ function.
    */
    SquareMatrix(size_t size){
        _size = size;
        _ptr = new T*[_size];//creates an array of rows. 

        for (size_t i = 0; i < _size; i++)
        {
            _ptr[i] = new T[_size];//each row will have an array of columns
            for (size_t j = 0; j < _size; j++)
            {
                _ptr[i][j] = this->_ptr[i][j];
            }//end of for loop.
        }//end of for loop. 
    }//end of default constructor.
    //---------------------------- Big Five -------------------------------

    /*
        @param: destructor 
        @param: we want to be able to destroy _ptr which is 2D array in order to be able to deallocate memory 
                and we want to reset size to 0;
        @param: check for _ptr!=nullptr 
    */
    ~SquareMatrix()
    {
        if(_ptr!=nullptr){
            for (size_t i = 0; i < _size; i++)
            {
                delete[] _ptr[i];
            }//end of for loop 

            delete[] _ptr;
            //_ptr = nullptr;
            _size = 0;
        }//end of if statement
    }//end of destructor
    
    /*
        @param: copy constructor
        @param: sets _size to the size of trg.
        @param: creates a 2D Dynamic array and sets it to the raw pointer.
        @param: since it is a square columns and rows are the same size. 
    */
    SquareMatrix(const SquareMatrix& trg)
    {
        _size = trg._size;
        _ptr = new T*[_size];//creates an array of rows. 

        for (size_t i = 0; i < _size; i++)
        {
            _ptr[i] = new T[_size];//each row will have an array of columns
            for (size_t j = 0; j < _size; j++)
            {
                _ptr[i][j] = trg._ptr[i][j];
            }//end of for loop.
        }//end of for loop. 
    }//end of copy constructor.

    /*
        @param: move constructor 
        @param: we want to have _ptr have trg's array. 
    */
    SquareMatrix(SquareMatrix<T>&& trg)
    {
        _size = trg._size;
        _ptr = trg._ptr;
        trg._ptr = nullptr; 
    }//end of move constructor.

    /*
        @param: copy assignment
        @param: you need to create a copy of rhs in order to be able to swap the contents of it. 
                If not then using swap is not appropriate. 
        @return: *this
    */
    SquareMatrix& operator=(const SquareMatrix& rhs)
    { 
        SquareMatrix copy = rhs; //places a copy of rhs into copy;
        std::swap(*this, copy); //swaps copy(copy of rhs) into *this. 
        return *this;
    }//end of copy assignment.

    /*
        @param: move assignment
        @return: *this
    */
    SquareMatrix& operator=(SquareMatrix&& rhs)
    {
        
        std::swap(_ptr, rhs._ptr); //swaps rhs._ptr into _ptr. 
        std::swap(_size, rhs._size); //swaps rhs._size into _size. 
       
        return *this;

    }//end of move assignment.

    //-------------------------- End of Big Five -----------------------------
    
    /*
        @param: Function resize
        @param: release all of the previous memory.
        @param: Allocate new memory. Can be any value of <T>
    */
    void resize(size_t new_size)
    {
        //compare new_size and _size. If they are the same there is not need to resize.
        if (new_size == _size)
        {
            return;
        }
        
        //deallocate memory. Destroy previous content. 
        if(_ptr!=nullptr){
            for (size_t i = 0; i < _size; i++)
            {
                delete[] _ptr[i];
            }//end of for loop.
            delete[] _ptr;
        }//end of if statement
        //_ptr = nullptr;
        //_size = 0; //reset _size

        _size = new_size;
        _ptr = new T*[_size];//creates an array of rows. 

        //We want to create a matrix of the new size. 
        for (size_t i = 0; i < _size; i++)
        {
            _ptr[i] = new T[_size];//each pointer will have a row 
        }//end of for loop.  

    }//end of resize() function.

    /*
        @param: Operator ==
        @param: Return True if Matrices A and B have the same size and the same elements inside
        @param: We want to check if any elements of the matrix are not equal to eachother and if so then we want to return false
    */
   friend bool operator==(const SquareMatrix& matrix_a, const SquareMatrix& matrix_b)
   {
       //if both matrix have the same size then we want to check the elements else we return false. 
       if (matrix_a._size == matrix_b._size)
       {
           //go through each row and column of the matrix and check if they are identical. 
           for (size_t i = 0; i < matrix_a._size; i++)
           {
               for (size_t j = 0; j < matrix_a._size; j++)
               {
                   if (matrix_a._ptr[i][j] != matrix_b._ptr[i][j])
                   {
                       return false;
                   }//end of if statement
               }//end of for loop.       
           }//end of for loop
           return true;
       }//end of if statement.
       else
       {
           return false;
       }// end of else statement.
   }// end of operator==() function. 
   
    /*
        @param: Operator+... must be the same size.
        @post: matrix_c that is the sum of matrix_a and matrix_b
        @return: matrix_c
    */
   friend SquareMatrix operator+(const SquareMatrix& matrix_a, const SquareMatrix& matrix_b)
   {
       //we want to add the sums of the elements of both matrices when they have the same same. 
       if (matrix_a._size == matrix_b._size)
       {
           SquareMatrix matrix_c(matrix_a.size());
           //matrix_c._size= matrix_a._size;
           for (size_t i = 0; i <matrix_a._size; i++)
           {
               for (size_t j = 0; j < matrix_a._size; j++)
               {
                   matrix_c._ptr[i][j] = matrix_a._ptr[i][j] + matrix_b._ptr[i][j];
               }//end of for statement.
               
           }//end of for statement.
           return matrix_c;
       }//end of if statement. 
       else
       {
           throw std::out_of_range("The size of both these Matrices are not equal.");
       }//end of else statement.
   }//end of operator+() function. 
   
   /*
        @param: Function at(row, column)
        @param: returns a reference (&) to the element in the row and column that is given. 
        @return: if element found then return that element. else throw the std::out_of_range
   */
  T& at(size_t row, size_t column)
  {
      if (((row >= 0) && (row < _size)) && ((column >= 0) && (column <_size)))
      {
          return _ptr[row][column];
      }
      else
      {
          throw std::out_of_range("The suggested row or column doesn't exist");
      }//end of else statement 
  }// end of function at(). 

    /*
        @param: Function Size
        @returns: _size
    */
   size_t size() const
   {
       return _size;
   }//end of function size();


};

//Due October 5