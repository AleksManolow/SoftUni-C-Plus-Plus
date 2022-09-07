#include"Store.h"
void Store::addPs(int price, int quality, int generation)
{
    Ps tempPS(price, quality, generation);
    ps.push_back(tempPS);
    std::cout << "Adding: ";
    tempPS.print();
}
void Store::addXbox(int price,int  quality)
{
    Xbox tempXbox(price, quality);
    xbox.push_back(tempXbox);
    std::cout << "Adding: ";
    tempXbox.print();
}
void Store::remove(ConsoleType consoleType)
{
    if ((int)consoleType == 0)
    {
        std::cout << "Removing: ";
        ps.back().print();
        ps.pop_back();
    }
    else
    {
        std::cout << "Removing: ";
        xbox.back().print();
        xbox.pop_back();
    }
}
void Store::sortByPrice(ConsoleType consoleType)
{
    if ((int)consoleType == 0)
    {
        std::cout <<"Sorting all PS by price" << std::endl;
        for (size_t i = 0; i < ps.size(); i++)
        {
            for (size_t j = i + 1; j < ps.size(); j++)
            {
                if (ps[i].getPrice() < ps[j].getPrice())
                {
                    Ps temp = ps[i];
                    ps[i] = ps[j];
                    ps[j] = temp;
                }
                
            }
        }
    }
    else
    {
        std::cout <<"Sorting all Xbox by price" << std::endl;
        for (size_t i = 0; i < xbox.size(); i++)
        {
            for (size_t j = i + 1; j < xbox.size(); j++)
            {
                if (xbox[i].getPrice() < xbox[j].getPrice())
                {
                    Xbox temp = xbox[i];
                    xbox[i] = xbox[j];
                    xbox[j] = temp;
                }
                
            }
        }

    }
}
void Store::sortByQuality(ConsoleType consoleType)
{
    if ((int)consoleType == 0)
    {
        std::cout <<"Sorting all PS by quality" << std::endl;
        for (size_t i = 0; i < ps.size(); i++)
        {
            for (size_t j = i + 1; j < ps.size(); j++)
            {
                if (ps[i].getQuality() < ps[j].getQuality())
                {
                    Ps temp = ps[i];
                    ps[i] = ps[j];
                    ps[j] = temp;
                }
                
            }
        }

    }
    else
    {
        std::cout <<"Sorting all Xbox by quality" << std::endl;
        for (size_t i = 0; i < xbox.size(); i++)
        {
            for (size_t j = i + 1; j < xbox.size(); j++)
            {
                if (xbox[i].getQuality() < xbox[j].getQuality())
                {
                    Xbox temp = xbox[i];
                    xbox[i] = xbox[j];
                    xbox[j] = temp;
                }
            }
        }
    }
}
void Store::print(ConsoleType consoleType)
{
    if ((int)consoleType == 0)
    {
        std::cout << "Printing all PS data" <<std::endl;
        for(auto elem:ps)
        {
            elem.print();
        }
    }
    else
    {
        std::cout << "Printing all Xbox data" <<std::endl;
        for(auto elem:xbox)
        {
            elem.print();
        }
    }
}