#include <iostream>
#include <string>
#include "KeywordsInFile.h"

void Test1(){
    KeywordsInFile Testing("keywords_file.txt","text1_file.txt");
    std::cout<<"START OF TEST 1"<< std::endl;
    std::cout<<"Total Occurances: "<<Testing.TotalOccurrences("Misery")<<'\n';//return 4

    std::cout<<"Keyword Found?: "<<Testing.KeywordFound("Misery")<<'\n';//returns 1

    std::cout<<"Keyword Found in Line: "<<Testing.KeywordInLine("Misery", 7)<<'\n';//return  2;

    std::cout<<Testing<<std::endl;;
    std::cout<<"END OF TEST 1"<< std::endl;
}

void Test2(){
    KeywordsInFile Testing("keywords_file.txt","text1_file.txt");
    std::cout<<"START OF TEST 2"<< std::endl;
    std::cout<<"Total Occurances: "<<Testing.TotalOccurrences("misery")<<'\n';//return 4

    std::cout<<"Keyword Found?: "<<Testing.KeywordFound("misery")<<'\n';//returns 1

    std::cout<<"Keyword Found in Line: "<<Testing.KeywordInLine("misery", 7)<<'\n';//return  2;

    std::cout<<Testing<<std::endl;;
    std::cout<<"END OF TEST 2"<< std::endl;
}
int main(int argc, char const *argv[])
{
    Test1();//passed
    Test2();

    return 0;
}
