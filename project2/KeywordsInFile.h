#include <unordered_map>
#include <set>
#include <vector>
#pragma once

class KeywordsInFile
{
    public:
        /*
            @param: text_multi_map is an unordered multimap will allow for duplicate keys. 
                    The value will be each line number. The key will be the keyword found in the text. 
                    The element is the value of the line number the keyword is found in. 
        */
        std::unordered_multimap<std::string, size_t>text_multi_map;
        /*
            @param: This set will contain the list of keywords found in the Keyword file.
                    It will also be used to cross refrence the words found in the text file. 
        */
        std::set<std::string>keyword_set;//set of keywords.
        //Disable default constructor. 
        KeywordsInFile() = delete;
        /*
            @param: Parameterized constructor that searches through keyword file 
                    and adds keywords to keyword_set.
        */
        KeywordsInFile( std::string filename_with_keywords, std::string filename_with_text); 
        /*
            @param: Member function that will return 1 or 0 (true or false)
                    using text_multi_map to check whether or not the keyword is found in text.
        */
        bool KeywordFound(std::string keyword);
        /*
            @param: Member function that will loop through text_multi_map 
                    and check how many times the keyword is found for the line_number parameter.
        */
        size_t KeywordInLine( std::string keyword, size_t line_number );
        /*
            @param: Member function that returns how many times the keyword was found in the text. 
                    Uses text_multi_map to do this. 
        */
        size_t TotalOccurrences( std::string keyword );
};
/*
    @param: A non-member Overload Operator that will print out how many times each keyword is found in text.
*/
std::ostream& operator<<(std::ostream& os, const KeywordsInFile&);
#include "KeywordsInFile.cpp"
