#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H
#include "Company.h"

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <cstddef>

std::shared_ptr<Company> makeCompany(std::vector<std::string> properties)
{
    std::vector<std::pair<char, char> > temp;
    for (int i = 2; i < properties.size(); i++)
    {
        temp.push_back(std::pair<char, char>(properties[i][0], properties[i][1]));
    }
    return std::shared_ptr<Company> (new Company(stoi(properties[0]), properties[1], temp));
}

#endif