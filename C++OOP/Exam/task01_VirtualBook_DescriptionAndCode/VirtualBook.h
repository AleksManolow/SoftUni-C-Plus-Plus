#ifndef __VIRTUALBOOK_H
#define __VIRTUALBOOK_H
#include"VirtualPage.h"
#include<iostream>

class VirtualBook
{
private:
    std::vector<VirtualPage> listOfVirtualPage;
public:
    VirtualBook() = default;
    void addPage(VirtualPage page)
    {
        listOfVirtualPage.push_back(page);
    }
    void printContent()
    {
        if (listOfVirtualPage.size() > 0)
        {        
            for (int i = 0; i < listOfVirtualPage.size(); i++)
            {
                listOfVirtualPage[i].printContent();
            }
        }

        
    }
    void removeLastPage()
    {
        if (listOfVirtualPage.size() > 0)
            listOfVirtualPage.pop_back();
    }
    void removeAllPages()
    {
        if (listOfVirtualPage.size() > 0)
        {     
            for (int i = 0; i < listOfVirtualPage.size() + 1; i++)
            {
                listOfVirtualPage.pop_back();
            }
        }

    }
};

#endif
