#ifndef __STRINGWRAPPER_H
#define __STRINGWRAPPER_H
#include<iostream>

class StringWrapper
{
private:
    std::string temp;
public:
    StringWrapper()
    {
        temp = "";
    }
    StringWrapper(std::string line)
    {
        temp = line;
    }
    StringWrapper(char c, int r)
    {
        for (size_t i = 0; i < r; i++)
        {
            temp += c;
        }
    }
    std::string getContent() const
    {
        return temp;
    }
    StringWrapper& append(const std::string s)
    {
        temp.append(s);
        return *this;
    }
    void printContent() const
    {
        std::cout << temp << std::endl;
    }

};

Input readInput()
{
    Input input;
    std::cin >> input.line;
    std::cin >> input.letter;
    std::cin >> input.repetitions;
    return input;
}


#endif