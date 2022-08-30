#include"Register.h"
Register::Register(size_t numCompanies):numAdded(0)
{
    companiesArray = new Company[numCompanies];
}
void Register::add(const Company& c)
{
    companiesArray[numAdded] = c;
    numAdded++;
}
Company Register::get(int companyId) const
{
    for (size_t i = 0; i < numAdded; i++)
    {
        if (companiesArray[i].getId() == companyId)
        {
            return companiesArray[i];
        }   
    }
    return Company();
}
Register::~Register()
{
    delete[] companiesArray;
}

