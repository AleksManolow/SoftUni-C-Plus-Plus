#ifndef __XBOX_H
#define __XBOX_H

#include"Console.h"

class Xbox : public Console
{
private:

public:
    Xbox(int price, int quality): Console(price, quality)
    { }
    void print() const
    {
        std::cout << "Xbox with ";
        Console::print();
    }
};

#endif