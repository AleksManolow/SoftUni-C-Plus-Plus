#ifndef __STOR_H
#define __STOR_H
#include"Ps.h"
#include"Xbox.h"
#include"Defines.h"
#include<vector>

class Store
{
private:
    std::vector<Ps> ps;
    std::vector<Xbox> xbox;
public:
    void addPs(int price, int quality, int generation);
    void addXbox(int price,int  quality);
    void remove(ConsoleType consoleType);
    void sortByPrice(ConsoleType consoleType);
    void sortByQuality(ConsoleType consoleType);
    void print(ConsoleType consoleType);
};

#endif