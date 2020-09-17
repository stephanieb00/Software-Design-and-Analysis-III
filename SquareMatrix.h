#pragma once

template<typename T>

class SquareMatrix
{
private:
    T* _ptr;
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
        @param: we want to be able to destroy _ptr in order to be able to deallocate memory 
                and we want to reset size to 0;
    */
    ~SquareMatrix()
    {
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
    SquareMatrix(const SquareMatrix& trg)
    {
        _size = trg._size;
        _ptr = new SquareMatrix<T>[_size][_size];//dynamic 2D Array.

        //set the contents in the trg 2D array to the _ptr. 
        for (size_t i{0}; i < trg._size; i++)
        {
            for (size_t j{0}; j < trg._size; j++)
            {
                _ptr[i][j] = trg._ptr[i][j]
            }//end of for loop. 
        }//end of for loop.
        

    }//end of copy constructor.

    /*
        @param: move constructor
    */
    SquareMatrix(SquareMatrix&& trg)
    {
        _ptr = trg._ptr;
        trg._ptr = nullptr; 
    }//end of move constructor.

    /*
        @param: copy assignment
        @return: *this
    */
    SquareMatrix& operator=(const SquareMatrix& rhs)
    { 
        SquareMatrix copy = rhs; //places a copy of rhs into copy;
        std::swap(*this, copy); //swaps copy into *this. 
        return *this;
    }//end of copy assignment.

    /*
        @param: move assignment
        @param: use swap for three copies  
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
        @param: Allocate new memory. Can be any value <T>
    */
    void resize(size_t new_size)
    {
        //compare new_size and _size. If they are the same there is not need to resize.
        if (new_size == _size)
        {
            return;
        }
        
        //deallocate memory. Destroy previous content. 
        for (size_t i{0}; i < _size; i++)
        {
           delete _ptr[i];
        }//end of for loop.

        //Allocate the new data into _ptr. 
        _size = new_size; // _size will be whatever new_size is. 
        new_array = new SquareMatrix<T>[_size][_size];

        for (size_t i{0}; i < _size; i++)
        {
            for (size_t j{0}; j < _size; j++)
            {
                _ptr[i][j] = new_array[i][j];
            }//for loop.
        }//end of for loop.
    }//end of resize function.

    /*
        @param: Function Size
        @returns: _size
    */
   size_t size()
   {
       return _size;
   }//end of function size;


};


//Due October 5