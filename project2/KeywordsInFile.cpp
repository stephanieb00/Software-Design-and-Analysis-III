#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>
/*
    Parameterized Constructor
    @param: O(N+M) where N = # of words in Keyword file and M = # of words in text file
    @param:non-alphabet strings are seperators. 
    @param: find keywords in a file create a vector of those keywords to use non alphabetic symbols as seprators to then add it to a set. 
    @param: read the text file. creates a vector of strings and then has this vector be added to the unordered map. Each line will be a key.
*/
KeywordsInFile::KeywordsInFile( const std::string& filename_with_keywords,const std::string& filename_with_text)
{
    std::ifstream text_file(filename_with_text);
    std::ifstream keyword_file(filename_with_keywords);
    
    if (!text_file.is_open()) 
    {
        std::cout << "File with text cannot be opened for reading."<< '\n';
    }//end of if statement
    
    if (!keyword_file.is_open()) 
    {
        std::cout << "File with text cannot be opened for reading."<< '\n';
    }//end of if statement

   //std::set<std::string>keyword_set;//set of keywords.
   char keywords_ch;
   std::set<std::string>keyword_set;//set of keywords.
   std::vector<std::string> keywords_vector;//vector of keywords. 


   //create a vector of lines from keyword_file.
   while(keyword_file, keywords_ch, '\n')
   {
       std::string temp= "";//creates and empty string
       if(isalpha(keywords_ch))
       {
           temp = temp + keywords_ch;
       }//end of if loop.
       else
       {
           //keywords_vector.push_back(temp);
           keyword_set.insert(temp);
       }//end of else statement.
   }//end of while loop

   keyword_file.close();//close file because we are now gonna use the vector to insert. 
  /* for(const std::string& keywords:keywords_vector)
   {
       keyword_set.insert(keywords);
   }//end of for loop. 
   */


   char text_ch;
   std::vector<std::string> word_vector;//vector of words in in each line.
   size_t line_number = 1; //the unique id that will be given to each item, which is the line number. 

   //We have an unordered map which will have line_number as the key and word_vector as the item. 
   while(text_file,text_ch)
   {
       //line_number++;//will make it start at 1. 
       std::string temp= "";//creates and empty string
       if(isalpha(text_ch))
       {
           temp = temp + text_ch;
       }//end of if loop.
       else
       {
           if (keyword_set.count(temp))
           {
               text_map.insert({temp,line_number});
           }//end of if statement
       }//end of else statement.
       if (text_ch=='\n')
       {
           line_number++;
       }  
   }//end of while loop.
   text_file.close();
}//end of parameterized constructor. 



/*
    KeywordFound
    @param: O(1)
    @return: true if keyword found
    @return: false if not. 
*/
bool KeywordsInFile::KeywordFound(std::string keyword)
{
    if(text_map.count(keyword)>0){
        return true;
    }//end of if 
    else{
        return false;
    }//end of else

}//end of KeywordFound

/*
    KeywordInLine
    @param: at most O(log L), where L = number of times keyword is found in line number. 
    @param: line number will be element+1;
    @param: will access the the specified line and look for keyword. 
    @param: if we find the keyword then count goes up by one.
    @return: count.
*/
size_t KeywordsInFile::KeywordInLine( std::string& keyword, size_t& line_number )
{   
    return text_map.at(keyword) = line_number;
}//end of KeywordInLine

/*
    TotalOccurrences 
    @param: no greater than O(log L), where L is # of time keyword is found in text.
            the easiest way would be to have a double loop to access each element,
            however this would increase the time complexity and therefore it would be greater than O(log L)
    @param: we can't make a set of each word of the vectors; 
    @param: we can use a map in which the keys are words and values are vectors of line of words.

            
    @return: count.
*/
size_t KeywordsInFile::TotalOccurrences( std::string& keyword )
{

    return text_map[keyword];

}//end of TotalOccurances. 
/*
    operator<<
    @param:allows you to use object of your class with cout
*/



std::ostream& operator<<(std::ostream& os, const KeywordsInFile& object)
{
    for (auto i{object.text_map.begin()}; i!=object.text_map.end();i++)
    {
        os<<i->first<<": "<< i->second<<'\n';
    }//end of for loop. 
    return os;
}//end of operator function
