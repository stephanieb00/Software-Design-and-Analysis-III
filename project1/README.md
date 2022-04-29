# Home Project #1


Write a class template SquareMatrix that implements a square matrix of elements of a specified type. The class template should be fully in the SquareMatrix.h file.

The class uses “raw” pointers to handle the dynamically allocated 2D-array. “Raw” pointers are the classic pointers that you’ve used before. In addition to it, you will need a variable that stores the array size. For example, the size 10 means that the matrix is 10X10 elements large.

Implement the following methods:

Default constructor (aka zero-parameter constructor).

The whole Big Five.
Remember to support such constructions as a=b=c and a=a .

Function resize(new_size) . This function destroys all previous content of the matrix and releases all memory. Then it allocates new memory. New elements are not specified (can have any value).

Operator == . Matrices A and B are considered equal if their sizes are equal and all elements of A match the corresponding elements of B.

Operator + . The result of addition of two square matrices A and B of the same size is a square matrix C of the same size where each element of C is the sum of corresponding elements from A and B.
Consider the input to be always correct (matrix sizes match and matrix elements can be added).

Function at(row, column) that returns a reference to the element in the given row and column. It is important to return reference since we plan to use this function to modify the matrix content. It allows expressions like obj.at(0,4)=7 .

Function size() that returns the current size of the matrix.
