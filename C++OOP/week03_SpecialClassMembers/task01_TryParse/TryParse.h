#ifndef __TRYPARSE_H
#define __TRYPARSE_H
#include<sstream>

bool tryParse(std::string str, int& num)
{
    if(isalpha(str[0]))
    {
        return false;
    }
    num = stoi(str);
    return true;
}

#endif