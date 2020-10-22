#include <iostream>
#include <string>
#include "KeywordsInFile.h"
int main(int argc, char const *argv[])
{
    KeywordsInFile Testing("Keywords_file.txt","text1_file.txt");
    std::cout<<"Total Occurances"<<Testing.TotalOccurrences("Misery")<<'\n';

    std::cout<<"Keyword Found"<<Testing.KeywordFound("Misery")<<'\n';

    std::cout<<"Keyword Found"<<Testing.KeywordInLine("Misery", 7)<<'\n';

    std::cout<<Testing;

    return 0;
}
