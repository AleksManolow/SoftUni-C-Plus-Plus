#ifndef __FIND_H
#define __FIND_H
#include "Company.h"

Company* find(std::vector<Company*> companies, int searchId)
{
    for(Company* company:companies)
    {
        if (company->getId() == searchId)
        {
            return company;
        }
    }
    return nullptr;
}

#endif 