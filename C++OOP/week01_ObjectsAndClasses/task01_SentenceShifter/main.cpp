#include<iostream>
#include"SentenceShifter.h"
int main()
{
    SentenceShifter shifter;
    shifter.readInput();
    std::deque<std::string> newWords = shifter.getShifteSentence();
    for(auto word : newWords)
    {
        std::cout << word << std::endl;
    }     
    
    return 0;
}


