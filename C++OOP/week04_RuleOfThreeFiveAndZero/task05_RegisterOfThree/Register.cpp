#include"Register.h"
#include <cstdlib>

Register::Register(size_t numCompanies):numAdded(0)
{
    companiesArray = new Company[numCompanies];    
}
Register::Register(const Register& other)
{
    numAdded = other.numAdded;
    companiesArray = new Company[numAdded];
    for (size_t i = 0; i < numAdded; i++)
    {
        companiesArray[i] = other.companiesArray[i];
    }
}
Register& Register::operator=(const Register& other)
{
    if (this != &other)
    {
        delete[] companiesArray;

        numAdded = other.numAdded;
        companiesArray = new Company[numAdded];
        for (size_t i = 0; i < numAdded; i++)
        {
            companiesArray[i] = other.companiesArray[i];
        }
    }
    return *this;
}    
Register::~Register()
{
    if (companiesArray != nullptr)
    {
        delete[] companiesArray;
        companiesArray = nullptr;
    }
}
void Register::add(const Company& c)
{
    companiesArray[numAdded++] = c;
}
Company Register::get(int companyId) const
{
    for (int i = 0; i < numAdded; i++)
    {
        if (companiesArray[i].getId() == companyId)
        {
            return companiesArray[i];
        }  
    }
    return Company();
}
