#include <iostream>
#include <vector>
#include "Field.h"

void Test1()
{
    std::vector<std::vector<int>> vector1(5, std::vector<int> (6));
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            vector1[i][j] = j + 1;  
        }//end of for loop
    }//end of for loop
    for(int i = 0; i < vector1.size(); i++) 
    {
        for(int j = 0; j < vector1[0].size(); j++) 
        {
            std::cout << vector1[i][j] << " ";
        }//end of for loop.
        std::cout << std::endl;
    }//end of for loop.
    Field field1 = Field(vector1);
    std::cout << "Field 1"<<std::endl;
    std::cout << field1.Weight(1,2,4,0) <<std::endl;
    std::cout << field1.PathCost() <<std::endl;
    //std::cout << field1.Weight(-1,2,4,0) <<std::endl;//works
    std::cout << field1.Weight(0,0,5,4) <<std::endl;//works

}

void Test2()
{
    Field field2 = Field({ {1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,4,5,6} });
    std::cout << "Field 2 "<<std::endl;
    std::cout << field2.Weight(1,2,4,0) <<std::endl;
    std::cout << field2.PathCost() <<std::endl;
}

int main()
{
    Test1();
    Test2();
    return 0;
}