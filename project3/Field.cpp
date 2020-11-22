#include <iostream>
#include <algorithm>
#include "Field.h"
#include <vector>

/*
    Copy Constructor:
    @param: They are given a vector of vectors that has integers. 2D numbers.
    @Example: 
        Original Matrix
        1  2  3  4  5  6  
        1  2  3  4  5  6  
        1  2  3  4  5  6  
        1  2  3  4  5  6  
        1  2  3  4  5  6  
        1  2  3  4  5  6  

        length: 6
        width: 6

        Then: 
        1  3  6  10  15  21
        2  6  12  20  30  42
        3  9  18  30  45  63
        4  12  24  40  60  84
        5  15  30  50  75  105
    @param: o(n) space and time.
    @params: In class we discussed that the weight of (1,1,2,2) would be 10. sum = 18-3-6+1
    @params: O(n*m): n is the number of vectors while m is the number of ints in each vector, which is still linear.

*/
Field::Field(const std::vector<std::vector<int>>& trg)
{
    original_matrix= trg;//will be useful for pathcost and now it is also used because trg. 
    /*
    std:: cout<<"Testing Original Matrix:"<< std::endl; //pass.
    for(int i = 0; i < original_matrix.size(); i++) 
    {
        for(int j = 0; j < original_matrix[0].size(); j++) 
        {
            std::cout << original_matrix[i][j] << " ";
        }//end of for loop.
        std::cout << std::endl;
    }//end of for loop.
    */

    //we want to set our weighed_matrix to the same size as the original matrix. 

    //We want to take care of the edge case.
    //At point (0,0) which is the right corner we want the weighed_matrix to be the same as the original matrix.
    //std::vector<std::vector<int>> weighed_matrix;
    weighed_matrix.resize(trg.size(),std::vector<int>(trg[0].size()));
    cheapest_cost.resize(trg.size(),std::vector<int>(trg[0].size()));
    //something is going wrong here!!! above fixed it. 
    weighed_matrix[0][0] = original_matrix[0][0];


    //std:: cout<<"Testing Purpose for weighed_matrix[0][0] ="<< weighed_matrix[0][0]<<std::endl; //pass


    int x_size = original_matrix[0].size();
    //std::cout<<"Testing row_size" <<x_size<<std::endl;

    //int util1 = 0;//y axis
    //int util2 = 0;//x axis
    //We have a 2D vector which means that we will need to be able to access each element from the y axis and x-axis.
    /*
    @param: We will have a for loop inside the for loop. The i will represent the y axis. and the util will represent the x-axis. 
            We want to be take care of the edge cases. 
            At (alpha,0) which is any element (any x value) where the y coordinate is 0, 
                we want the weighed_matrix to equal the original matrix at that point + the weighed_matrix at point(0, util-1)
            At (0, alpha) which is where the y coordinate can be any number but the x coordiate is 0. 
                we want the weighed_matrix to equal original matrix + the weighed_matrix at point(i-1, 0)

    @param: originally planned to do one for loop and have a helper variable take care of the x axis values.
            However, if the y axis is smaller than the x axis then it would not work!!!
            Therefore instead of util, we opted for a nested loop with i representing the y values and a representing the x values
    */
    for (size_t i = 0; i < original_matrix.size(); i++)
    {
        //i is the vector of vectors... the y.

        //Testing if the for loop has been entered. and testing the x axis.
        //std::cout<< i << std::endl; 

        for (size_t j = 0; j < x_size; j++)
        {
            //j is the rows... the vector... the x.
            if (j!=0)
            {
                weighed_matrix[0][j] = original_matrix[0][j]+ weighed_matrix[0][j-1];// x = 0

            }//end of if statement 
            if (i != 0)
            {
                weighed_matrix[i][0] = original_matrix[i][0] + weighed_matrix[i-1][0];// y = 0
            }//end of if statement 
        }//end of for loop.
    }//end of for loop.
    /*
    std::cout <<"Testing the edge cases of the for loop. "<<std::endl;
    for(int i = 0; i < weighed_matrix.size(); i++) 
    {
        for(int j = 0; j < weighed_matrix[0].size(); j++) 
        {
            std::cout << weighed_matrix[i][j] << " ";
        }//end of for loop
        std::cout << std::endl;
    }//end of for loop
    */
    /*
   @param: We need to calculate for the middle of the matrix.
            Everything from (1,1) to (trg.size(),trg[0].size());
            (i, util) = trg[i][util] + weighted_matrix[i][util-1]+ weighed_matrix[i-1][util] - weighed_matrix[i-1][util-1]
    @param: Originally planned to not have nested loop however due to uncertainty of the sizes of the y or x axis 
            Opted to simply use a nested loop. 
   */
    for (size_t i = 1; i < original_matrix.size(); i++)
    {
        for (size_t j = 1; j < x_size; j++)
        {
            weighed_matrix[i][j] = original_matrix[i][j]+ weighed_matrix[i][j-1]+weighed_matrix[i-1][j] - weighed_matrix[i-1][j-1];
   
        }//end of for loop. 
        
    }//end of for loop. 
    
   /*
   for (size_t i = 0; i < x_size; i++)
   {
        std:: cout<<"util"<<util<< std::endl; //pass.
        std::cout<< "i"<<i<<std::endl;

       if (util <= original_matrix[0].size())
       {
           //std:: cout<<"For Loop if statement= "<< weighed_matrix[0][util]<<std::endl; //pass.
           if (util!=0)
           {
               weighed_matrix[util][0] = original_matrix[util][0]+ weighed_matrix[util-1][0];// x = 0
           }
           //std:: cout<<"For Loop: "<< weighed_matrix[i-1][0]<<std::endl; //pass.
           if (i != 0)
           {
               weighed_matrix[0][i] = original_matrix[0][i] + weighed_matrix[0][i-1];// y = 0
           }//end of if statement
           
           //weighed_matrix[i][0] = original_matrix[i][0] + weighed_matrix[i-1][0];// y = 0
           //std:: cout<<"For Loop:"<< std::endl; //fail
           util++;
       }
   }//end of for loop.
   */   
  /*
   std::cout<<"Testing For The Inside of the Matrix. from (2,2) to (end of x axis, end of y axis.)"<<std::endl;
   for(int i = 0; i < weighed_matrix.size(); i++) 
   {
        for(int j = 0; j < weighed_matrix[0].size(); j++) 
        {
            std::cout << weighed_matrix[i][j] << " ";
        }//end of for loop.
        std::cout << std::endl;
    }//end of for loop.
    */
  /*
  std::cout<<"second for loop"<<std::endl;
   for (size_t i = 2; i < original_matrix.size(); i++)
   {
       std::cout<<"second for loop"<<std::endl;
       if (util2 <= x_size)
       {
           weighed_matrix[i][util] = original_matrix[i][util]+ weighed_matrix[i][util-1]+weighed_matrix[i-1][util] - weighed_matrix[i-1][util-1];
           util++;
       }
   }//end of for loop
   */
}//end of Field Copy constructor. 


/*
    Move Constructor:
    @param: They are given a vector of vectors that has integers. 2D numbers.
    @Example: 
        Original Matrix
        1  2  3  4  5  6  
        1  2  3  4  5  6  
        1  2  3  4  5  6  
        1  2  3  4  5  6  
        1  2  3  4  5  6  
        1  2  3  4  5  6  

        length: 6
        width: 6

        Then: 
        1  3  6  10  15  21
        2  6  12  20  30  42
        3  9  18  30  45  63
        4  12  24  40  60  84
        5  15  30  50  75  105
    @param: o(n) space and time.
    @params: In class we discussed that the weight of (1,1,2,2) would be 10. sum = 18-3-6+1
    @params: This will do the same stuff that the copy constructor did. 
        Professor said: " No matter how you supply the 2D-array, the same array produces the same Weight outputs."
*/
Field::Field(std::vector<std::vector<int>> && trg)
{
    original_matrix= trg;//will be useful for pathcost and now it is also used because trg. 
    /*
    std:: cout<<"Testing Original Matrix:"<< std::endl; //pass.
    for(int i = 0; i < original_matrix.size(); i++) 
    {
        for(int j = 0; j < original_matrix[0].size(); j++) 
        {
            std::cout << original_matrix[i][j] << " ";
        }//end of for loop.
        std::cout << std::endl;
    }//end of for loop.
    */

    //we want to set our weighed_matrix to the same size as the original matrix. 

    //We want to take care of the edge case.
    //At point (0,0) which is the right corner we want the weighed_matrix to be the same as the original matrix.
    //std::vector<std::vector<int>> weighed_matrix;
    weighed_matrix.resize(trg.size(),std::vector<int>(trg[0].size()));
    cheapest_cost.resize(trg.size(),std::vector<int>(trg[0].size()));
    //something is going wrong here!!! above fixed it. 
    weighed_matrix[0][0] = original_matrix[0][0];


    //std:: cout<<"Testing Purpose for weighed_matrix[0][0] ="<< weighed_matrix[0][0]<<std::endl; //pass


    int x_size = original_matrix[0].size();
    //std::cout<<"Testing row_size" <<x_size<<std::endl;

    //int util1 = 0;//y axis
    //int util2 = 0;//x axis
    //We have a 2D vector which means that we will need to be able to access each element from the y axis and x-axis.
    /*
    @param: We will have a for loop inside the for loop. The i will represent the y axis. and the util will represent the x-axis. 
            We want to be take care of the edge cases. 
            At (alpha,0) which is any element (any x value) where the y coordinate is 0, 
                we want the weighed_matrix to equal the original matrix at that point + the weighed_matrix at point(0, util-1)
            At (0, alpha) which is where the y coordinate can be any number but the x coordiate is 0. 
                we want the weighed_matrix to equal original matrix + the weighed_matrix at point(i-1, 0)

    @param: originally planned to do one for loop and have a helper variable take care of the x axis values.
            However, if the y axis is smaller than the x axis then it would not work!!!
            Therefore instead of util, we opted for a nested loop with i representing the y values and a representing the x values
    */
    for (size_t i = 0; i < original_matrix.size(); i++)
    {
        //i is the vector of vectors... the y.

        //Testing if the for loop has been entered. and testing the x axis.
        //std::cout<< i << std::endl; 

        for (size_t j = 0; j < x_size; j++)
        {
            //j is the rows... the vector... the x.
            if (j!=0)
            {
                weighed_matrix[0][j] = original_matrix[0][j]+ weighed_matrix[0][j-1];// x = 0

            }//end of if statement 
            if (i != 0)
            {
                weighed_matrix[i][0] = original_matrix[i][0] + weighed_matrix[i-1][0];// y = 0
            }//end of if statement 
        }//end of for loop.
    }//end of for loop.
    /*
    std::cout <<"Testing the edge cases of the for loop. "<<std::endl;
    for(int i = 0; i < weighed_matrix.size(); i++) 
    {
        for(int j = 0; j < weighed_matrix[0].size(); j++) 
        {
            std::cout << weighed_matrix[i][j] << " ";
        }//end of for loop
        std::cout << std::endl;
    }//end of for loop
    */
    /*
   @param: We need to calculate for the middle of the matrix.
            Everything from (1,1) to (trg.size(),trg[0].size());
            (i, util) = trg[i][util] + weighted_matrix[i][util-1]+ weighed_matrix[i-1][util] - weighed_matrix[i-1][util-1]
    @param: Originally planned to not have nested loop however due to uncertainty of the sizes of the y or x axis 
            Opted to simply use a nested loop. 
   */
    for (size_t i = 1; i < original_matrix.size(); i++)
    {
        for (size_t j = 1; j < x_size; j++)
        {
            weighed_matrix[i][j] = original_matrix[i][j]+ weighed_matrix[i][j-1]+weighed_matrix[i-1][j] - weighed_matrix[i-1][j-1];
   
        }//end of for loop. 
        
    }//end of for loop. 
    
}//end of move constructor. 


/*
@param: if coordinates go beyond the array boundaries, throw the out_of_range exception.
@param:(x1,y1) and (x2,y2)
        We want to see which is smaller between x1 and x2 then we want to go from the column of either or.
        We want to do the same for y1 and y2 so we can go from the smaller row number to the bigger one. 
        O(1) run time.

@Example: 
        1 |3  6  10 15|  21
        2 |6  12 20 30|  42
        3 |9  18 30 45|  63
           ---------
        4  12 24 40  60  84
        5  15 30 50 75  105

        (1,2,4,0)
        (1,2) && (4,0)
        four points: Top Left: (0,2) 
                     Bottom Left: (1,2)
                     Top Right: (4,0)
                     Bottom Right: (4,2)
        x values: 1 and 4:
            the minimum will be the left value  which is 1. 
            the maximum will be the right value which is 4.
        y values: 2 and 0:
            the minimum will be the top value which is 0 
            the maximum will be the bottom value which is 2.

        (4,2) = 30 
        (0,2) = 3
        (4,0) = 10 
        (1,2) = 9

        we want to take away 3 from our weight( Bottom Right);
        45-3 = 42. 
        this will solve this problem because it is an edge case. 
        however if it wasn't we would need to account for what is about the smallest y value(from_value)

        Now what happens when it isn't an edge case. 
        In class we discussed that the weight of (1,1,2,2) would be 10. sum = 18-3-6+1
        (1,1) and (2,2)
        (2,2) = 18
        (1,2) = 9
        (2,1) = 12
        (1,1) = 6.

        18-3+6+1
        The 18 is (2,2) bottom right. 
        the 3 comes from the the (left - 1, bottom)
        the 6 comes from (left, top-1)
        the 1 comes from (0,0) which we get by doing (left-1, top-1)

@return: return_wieght
*/

int Field::Weight( int x1, int y1, int x2, int y2 )
{
    int return_weight = 0;

    //Find the minimum  and maximum between the both x values and then the y values. 
    int from_x_value = std::min(x1,x2);
    int to_x_value = std::max(x1,x2);
    int from_y_value = std::min(y1,y2);
    int to_y_value = std::max(y1,y2);
    /*
    std::cout<<"Lets test our values"<<std::endl;
    std::cout<< "from_x_value: "<< from_x_value<< std::endl;
    std::cout<< "to_x_value: "<< to_x_value<< std::endl;
    std::cout<< "from_y_value: "<< from_y_value<< std::endl;
    std::cout<< "to_y_value: "<< to_y_value<< std::endl;
    */
    /*
    @Param:Lets make sure the coordinates don't go beyond the array boundaries. 
        The vector inside the vector Starts at 0 and ends at weighed_matrix[0].size().
        The vector starts at 0 and ends at weighed_matrix.size() .
        If any of the matrix is 0 then the weight would be 0 as well. 
        Using the minimum values we got we will test if they are less than 0. 
        Using the maximum we will test if they are bigger than the size of of both y and x axis.
    */

    if ((from_x_value < 0) || (from_y_value < 0))
    {
        throw std::out_of_range("The suggested row or column doesn't exist");
    } //end of if statement.

    else if ((to_x_value > weighed_matrix[0].size()-1) || (to_y_value > weighed_matrix.size()-1))
    {
        throw std::out_of_range("The suggested row or column doesn't exist");
    }//end of if statement. 
    
    else
    {
        //Find the minimum  and maximum between the both x values and then the y values. 

        //New coordinates(from_y,value, from_x_value) and (to_y_value, to_x_value) 

        //Which means we need to calculate for four points because a rectuangle has 4 points.
        //(to_x_value, to_y_value) || (to_y_value, from_x_value) || (from_y_value, to_x_value)
        //(from_y_value, from_x_value)

        //Lets get the value from the the outer most corner. which is (to_x_value, to_y_value)
        return_weight = weighed_matrix[to_y_value][to_x_value]; //now we have from (0,0) to (to_y_value,to_x_value)
        //std::cout<<"Get coordinate"<<weighed_matrix[to_y_value][to_x_value]<< std::endl;
        //std::cout<<"testing weight"<<return_weight<< std::endl;


        // No we don't want whats on top of the top value (from_y_value)
        //and we don't want whats left from the left value (from_x_value)
        //we also need to make sure the x values arent edge cases because then we will get a negative number. so no zeros.
        if (from_x_value != 0)
        {
            //when x isn't equal to zero we want to subtract what is to the left of it.
            //which will be the number that is in coordinate(, to_y_value,from_x_value-1)
            return_weight -= weighed_matrix[to_y_value][from_x_value-1];
        }//end of if statement 

        //in case of edge case for the top we want to make sure we only subtract when it isn't and edge case.
        if(from_y_value != 0 )
        {
            //when y isn't equal to 0 we want to subtract whats on top of it from out weight.
            // which will be coordinate(from_y_value-1,to_x_value )
            return_weight -= weighed_matrix[from_y_value-1][to_x_value];
        }//end of if statement.

        if((from_y_value != 0) && (from_x_value != 0))
        {
            return_weight += weighed_matrix[from_y_value-1][from_x_value-1];
        }//end of if statement
    }
    return return_weight;

}//end of weight function. 

/*
@Param: This is like the Cheapest cost we did in class and for our test. 
        O(N) time.
        This method computes the cost of the cheapest path 
        from top-left corner of the field to the bottom-right corner. 
        The only possible moves are right and down.
        In a way we need four points again. 
        Similar to how we did the precomputations in our constructors. 
        We can use what we learned in class during our dynamic programming lectures. 
@return: cheapest_cost but not the matrix. We want the value of the coordinate before the bottom right. 
*/


int Field::PathCost()
{
   // std::cout<< "Hello Welcome to Path Cost Function"<<std::endl;//passed

    cheapest_cost[0][0] = original_matrix[0][0];

    int x_size = original_matrix[0].size();
    //int util = 0;
    //std::cout<< cheapest_cost[0][0]<<std::endl;

    //Similar procces to what we did in the constructors. 
    for (size_t i = 0; i < original_matrix.size(); i++)
    {
        for (size_t j = 0; j < x_size; j++)
        {
            if (j!=0)
            {
                cheapest_cost[0][j] = original_matrix[0][j]+ cheapest_cost[0][j-1];// x = 0

            }//end of if statement 
            if (i!=0)
            {
                cheapest_cost[i][0] = original_matrix[i][0] + cheapest_cost[i-1][0];// y = 0
            }//end of if statement 
        }//end of for loop.
    }//end of for loop.

    //we want to find the minimum/ cheapest cost. 
    for (size_t i = 1; i < original_matrix.size(); i++)
    {
        for (size_t j = 1; j < x_size; j++)
        {
            cheapest_cost[i][j] = original_matrix[i][j] + std::min(cheapest_cost[i][j-1], cheapest_cost[i-1][j]);
        }//end of for loop.
    }//end of for loop.
    return cheapest_cost[original_matrix.size()-1][x_size-1];
}//end of PathCost Function
