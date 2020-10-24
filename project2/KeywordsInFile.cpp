#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <set>
#include <string>
#include <cctype>
#include <vector>

//#include <tr1/unordered_map>
/*
    Parameterized Constructor
    @param: O(N+M) where N = # of words in Keyword file and M = # of words in text file
    @param:non-alphabet strings are seperators. 
    @param: find keywords in a file create a vector of those keywords to use non alphabetic symbols as seprators to then add it to a set. 
    @param: read the text file. creates a vector of strings and then has this vector be added to the unordered map. Each line will be a key.
*/
KeywordsInFile::KeywordsInFile( std::string filename_with_keywords, std::string filename_with_text)
{
    std::ifstream keyword_file(filename_with_keywords);
    if (!keyword_file.is_open()) 
    {
        std::cout << "File with text cannot be opened for reading."<< '\n';
    }//end of if statement

   //std::set<std::string>keyword_set;//set of keywords.
   std::string keywords_string;
   char keyword_ch;
   std::string temp;
   while (keyword_file.get(keyword_ch))
   {
       if ((isalpha(keyword_ch)))
       {
           temp+=keyword_ch;
       }//end of if statement
       else 
       {
           if ((keyword_ch != '.') && (keyword_ch!='\n'))
           {
               /* code */
               keyword_set.insert(temp);
               //std::cout<<temp<<std::endl;//testing purposes
               temp = ""; //empties string.
           } 
       }//end of else statement
   }//end of while loop

   keyword_file.close();//close file because we are now gonna use the vector to insert. 
  /* for(const std::string& keywords:keywords_vector)
   {
       keyword_set.insert(keywords);
   }//end of for loop. 
   */
  std::ifstream text_file(filename_with_text);
  if (!text_file.is_open()) 
    {
        std::cout << "File with text cannot be opened for reading."<< '\n';
    }//end of if statement
    temp = "";
   std::string text_string;
   char text_ch;
   bool line_bool;
   size_t line_number = 1; //the unique id that will be given to each item, which is the line number.
   size_t count = 0;
   temp = ""; //empties string 
   std::vector<std::string> word_vector;
   while (text_file.get(text_ch))
   {
       if (text_ch=='\n')
       {
           line_number++;
           //text_vector.push_back(word_vector);
       }
       if ((isalpha(text_ch)))
       {
           temp+=text_ch;
       }//end of if statement
       else 
       {
           if ((text_ch != '.') && (text_ch!='\n'))
           {
               if (keyword_set.count(temp))
               {
                   //text_map[temp]+= 1;//inserts and tracks how many times a keyword appears. 
                   text_multi_map.insert({temp,line_number});
                   //std::cout<<temp<<std::endl;
               }//end of if statement   
           } 
           temp = ""; //empties string.
       }//end of else statement
   }

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
    if(text_multi_map.count(keyword)>0){
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
size_t KeywordsInFile::KeywordInLine( std::string keyword, size_t line_number )
{   
    size_t count = 0;
    for (auto i{text_multi_map.begin()}; i!=text_multi_map.end();i++)
    {
        //std::cout<< i->first<< i->second<<std::endl;
        if ((i->second == line_number) && (i->first == keyword))
        {
            count++;
        } 
    }//end of for loop. 
    return count;
}//end of KeywordInLine

/*
    TotalOccurrences 
    @param: no greater than O(log L), where L is # of time keyword is found in text.
            the easiest way would be to have a double loop to access each element,
            however this would increase the time complexity and therefore it would be greater than O(log L)
    @param: in the constructor we have created text_map which has a value that is the 
            number of times a keyword has appeared in the text.
            
    @return: the element of the key.
*/
size_t KeywordsInFile::TotalOccurrences( std::string keyword )
{
    return text_multi_map.count(keyword);//text_map[keyword];

}//end of TotalOccurances. 
/*
    operator<<
    @param:allows you to use object of your class with cout
*/

std::ostream& operator<<(std::ostream& os, const KeywordsInFile& object)
{
    for ( auto it = object.keyword_set.begin(); it != object.keyword_set.end(); it++ )
    {
        os<<"Keyword "<<*it<<" Appears "<<object.text_multi_map.count(*it)<<" times."<<std::endl;
    }
    return os;
}//end of operator function
