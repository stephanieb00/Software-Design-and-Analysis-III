#pragma once

#include <iostream>
#include <cstddef>

using namespace std;

template<typename T>

class SquareMatrix
{
private:
    T *_ptr;
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

    //---------------------------- Big Five -------------------------------

    /*
        @param: destructor 
        @param: we want to be able to destroy _ptr which is 2D array in order to be able to deallocate memory 
                and we want to reset size to 0;
    */
    ~SquareMatrix()
    {
        for (size_t i = 0; i < count; i++)
        {
            _ptr = nullptr;
            delete[] _ptr[i];
        }//end of for loop
        _ptr = nullptr;
        delete _ptr;
        _size = 0;
    }//end of destructor
    
    /*
        @param: copy constructor
        @param: sets _size to the size of trg.
        @param: creates a 2D Dynamic array and sets it to the raw pointer.
        @param: since it is a square columns and rows are the same. 
    */
    SquareMatrix(const SquareMatrix<T>& trg)
    {
        _size = trg._size;
        _ptr = new T[_size];//creates an array of rows. 

        for (size_t i = 0; i < _size; i++)
        {
            _ptr[i] = new T[_size];//columns
            for (size_t j = 0; j < _size; j++)
            {
                _ptr[i][j] = trg._ptr[i][j]
            }//end of for loop.
        }//end of for loop. 
        


        //set the contents in the trg 2D array to the _ptr. 
        for (size_t i = 0; i < trg._size; i++)
        {
            for (size_t j = 0; j < trg._size; j++)
            {
                _ptr[i][j] = trg._ptr[i][j];
            }//end of for loop. 
        }//end of for loop.
        

    }//end of copy constructor.

    /*
        @param: move constructor
    */
    SquareMatrix(SquareMatrix<T>&& trg)
    {
        _ptr = trg._ptr;
        trg._ptr = nullptr; 
    }//end of move constructor.

    /*
        @param: copy assignment
        @return: *this
    */
    SquareMatrix& operator=(const SquareMatrix<T>& rhs)
    { 
        SquareMatrix copy = rhs; //places a copy of rhs into copy;
        std::swap(*this, copy); //swaps copy into *this. 
        return *this;
    }//end of copy assignment.

    /*
        @param: move assignment
        @param: use swap for three copies  
    */
    SquareMatrix& operator=(SquareMatrix<T>&& rhs)
    {
        std::swap(_ptr, rhs._ptr); //swaps rhs._ptr into _ptr. 
        std::swap(_size, rhs._size); //swaps rhs._size into _size. 

        return *this;
    }//end of move assignment.

    //-------------------------- End of Big Five -----------------------------
    
    /*
        @param: Function resize
        @param: release all of the previous memory.
        @param: Allocate new memory. Can be any value <T>
    */
  /*  void resize(size_t new_size)
    {
        //compare new_size and _size. If they are the same there is not need to resize.
        if (new_size == _size)
        {
            return;
        }
        
        //deallocate memory. Destroy previous content. 
        for (size_t i = 0; i < _size; i++)
        {
           delete _ptr[i];
        }//end of for loop.

        //Allocate the new data into _ptr. 
        _size = new_size; // _size will be whatever new_size is. 
        new_array = new T[_size][_size];

        for (size_t i = 0; i < _size; i++)
        {
            for (size_t j = 0; j < _size; j++)
            {
                _ptr[i][j] = new_array[i][j];
            }//for loop.
        }//end of for loop.
    }//end of resize() function.

    */

    /*
        @param: Operator ==
        @param: Return True if Matrices A and B have the same size and the same elements inside
        @param: true_checker is set to true and will be set to false when the elements are not equal to eachother
    */
   friend bool operator==(const SquareMatrix& matrix_a, const SquareMatrix& matrix_b)
   {
       bool true_checker = true; 
       //if both matrix have the same size then we want to check the elements else we return false. 
       if (matrix_a._size == matrix_b._size)
       {
           //go through each row and column of the matrix and check if they are identical. 
           for (size_t i = 0; i < matrix_a._size; i++)
           {
               for (size_t j = 0; j < matrix_a._size; j++)
               {
                   if (matrix_a._ptr[i][j] == matrix_a._ptr[i][j])
                   {
                       true_checker = true;
                   }//end of if statement
                   else
                   {
                       true_checker = false;
                   }//end of else statement. 
               }//end of for loop.       
           }//end of for loop
           return true_checker;
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
       SquareMatrix matrix_c;

       //we want to add the sums of the elements of both matrices when they have the same same. 
       if (matrix_a._size == matrix_b._size)
       {
           matrix_c._size= matrix_b._size;
           matrix_c._ptr = new T[matrix_c._size][matrix_c._size];
           for (size_t i = 0; i < matrix_c._size; i++)
           {
               for (size_t j = 0; j < matrix_c._size; j++)
               {
                   matrix_c[i][j] = matrix_a[i][j] + matrix_b[i][j];
               }//end of for statement
               
           }//end of for statement
       }//end of if statement. 
       

       return matrix_c;
   }//end of operator+() function. 
   
   /*
        @param: Function at(row, column)
        @param: returns a reference (&) to the element in the row and column that is given. 
        @return: if element found then return that element. else throw the std::out_of_range
   */
  T& at(size_t row, size_t column)
  {
      if (((row >= 0) && (row <= _size)) && ((column >= 0) && (column <=_size)))
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