#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <set>
#include <string>
#include <cctype>

/*
    Parameterized Constructor
    @param: O(N+M) where N = # of words in Keyword file and M = # of words in text file
    @param:non-alphabet strings are seperators. 
    @param: Keyword File: Will go through the keyword file and look through each character in the file.
            Will check if the character is alphatic. If it is alphabetic then it will be added to a 
            temporary string. When a non-alphabetic charcater is found then it 
            will check if this non alphabetic charcter is a period or a new line. 
            If yes this temporary string will be inserted into keyword_set. 
            The temporary string will be emptied and this will continue while the file is open. 

    @param: Text file: Will do a similar search process as the keyword file search process. 
            Will iterate through each charcter and only add alphabetic characters to our temporary string.
            When a seperator is found, we look if the temporary string is a keyword by searching for it 
            in keyword_set. If yes we want to add it to our unordered multimap text_multi_map.
*/
KeywordsInFile::KeywordsInFile( std::string filename_with_keywords, std::string filename_with_text)
{
    std::ifstream keyword_file(filename_with_keywords);
    if (!keyword_file.is_open())
    {
        std::cout << "File with text cannot be opened for reading."<< '\n';
    }//end of if statement
    char keyword_ch;//character iterator for keyword file. 
    std::string temp = "";//temporary string for both files. 
    
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
                keyword_set.insert(temp);
                //std::cout<<temp<<std::endl;//testing purposes
                temp = ""; //empties string.
            } //end of if statement. 
       }//end of else statement
   }//end of while loop
   
   keyword_file.close();//close keyword file. 
   
   std::ifstream text_file(filename_with_text);//open text file.
   if (!text_file.is_open()) 
   {
       std::cout << "File with text cannot be opened for reading."<< '\n';
   }//end of if statement
   
   char text_ch;//character iterator for text file. 
   size_t line_number = 1; //the line_number that corresponds to the line the keyword is found in the text.
   temp = ""; //empties string 

   while (text_file.get(text_ch))
   {
       if (text_ch=='\n')
       {
           line_number++;
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
                   text_multi_map.insert({temp,line_number});
                   //std::cout<<temp<<std::endl;//texting purposes. 
               }//end of if statement   
           }//end of if statement
           temp = ""; //empties string.
       }//end of else statement
   }//end of while statement

   text_file.close();//close text file
}//end of parameterized constructor. 



/*
    KeywordFound
    @param: O(1)
    @return: true(1) if keyword is found in text_multi_map
    @return: false(0) if not. 
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
    @param: will iterate through text_multi_map. if (the keyword at i position is 
            equal to the keyword passed as an argument) && (the line number at i position is equal
            to line_number which is passed as an argument) then increment count by 1.
    @return: count.
*/
size_t KeywordsInFile::KeywordInLine( std::string keyword, size_t line_number )
{   
    size_t count = 0;
    for (auto i{text_multi_map.begin()}; i!=text_multi_map.end();i++)
    {
        if ((i->second == line_number) && (i->first == keyword))
        {
            count++;
        }//end of if statement. 
    }//end of for loop. 
    return count;
}//end of KeywordInLine

/*
    TotalOccurrences 
    @param: no greater than O(log L), where L is # of time keyword is found in text.
            the easiest way would be to have a double loop to access each element,
            however this would increase the time complexity and therefore it would be greater than O(log L)
    @param: We have text_multi_map which holds the keyword. 
            If there are duplicates of keyword then it holds multiple instances of that keyword. 
            We simply have to count how many times that keyword appears in text_multi_map and return that value.        
    @return: the number of times keyword appears in text_multi_map.
*/
size_t KeywordsInFile::TotalOccurrences( std::string keyword )
{
    return text_multi_map.count(keyword);

}//end of TotalOccurances. 

/*
    operator<<
    @param: Allows you to use object of your class with cout. 
            Will print each keyword and how many times it is occurs in text_multi_map.
            There isn't a time complexity constrait in the project specifics. 
            We iterate through keyword_set. Then we count how many times that specific keyword 
            occured in the text_multi_map. 
*/

std::ostream& operator<<(std::ostream& os, const KeywordsInFile& object)
{
    for ( auto it = object.keyword_set.begin(); it != object.keyword_set.end(); it++ )
    {
        os<<"Keyword "<<*it<<" Appears "<<object.text_multi_map.count(*it)<<" times."<<std::endl;
    }//end of for loop. 
    return os;
}//end of operator function
