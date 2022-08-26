#ifndef __SentenceShifter_H
#define __SentenceShifter_H
#include<iostream>
#include<queue>
#include<string>
#include<sstream>
class SentenceShifter
{
private:
    std::deque<std::string> words;
    int shiftCount;
public:
    SentenceShifter();
    void readInput();
    std::deque<std::string> getShifteSentence();
};





#endif
