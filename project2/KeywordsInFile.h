#pragma once

class KeywordsInFile
{
    private:
        //std::unordered_map<std::string, size_t> text_map; //each unique key will have the line number attached. 
    public:
        std::unordered_map<std::string, size_t> text_map; //each unique key will have the line number attached. 
        KeywordsInFile( const std::string filename_with_keywords,const std::string filename_with_text); //Parameterized Constructor
        bool KeywordFound(std::string keyword);
        size_t KeywordInLine( std::string keyword, size_t line_number );
        size_t TotalOccurrences( std::string keyword );
};
std::ostream& operator<<(std::ostream& os, const KeywordsInFile&);
#include "KeywordsInFile.cpp"
