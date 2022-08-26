#include"SentenceShifter.h"
SentenceShifter::SentenceShifter():shiftCount(0)
{

}
void SentenceShifter::readInput()
{
    std::string line;
    getline(std::cin, line);
    std::istringstream istr(line);

    std::string word;
    while (istr >> word)
    {
        words.push_back(word);
    }
    std::cin >> shiftCount;
}
std::deque<std::string> SentenceShifter::getShifteSentence()
{
    for (size_t i = 0; i < shiftCount; i++)
    {
        words.push_front(words.back());
        words.pop_back();
    }
    
    return words;
}