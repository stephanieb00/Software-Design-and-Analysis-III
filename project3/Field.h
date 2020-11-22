#include <vector>
#include <iostream>
#include <cstddef>

#pragma once

class Field
{
public:
    //Field()
    Field(const std::vector<std::vector<int>>& trg);//copy constructor.
    Field(std::vector<std::vector<int>> && trg);//move constructor.
    int Weight( int x1, int y1, int x2, int y2 );
    int PathCost();

private:
    /*
    @param: we have two matrices. 
            The original that is passed through and then the one that we change.
            and the precomputed one we use for the Weight function. 
            Because weight needs to be able to call this vector we should have it be able
            to be accessed outside the function.
    */
   std::vector<std::vector<int>> original_matrix;// weighed matrix couldn't access trg so you need a matrix to be accessed. 
   std::vector<std::vector<int>> weighed_matrix;
   std::vector<std::vector<int>> cheapest_cost;
   
};

//#include "Field.cpp"