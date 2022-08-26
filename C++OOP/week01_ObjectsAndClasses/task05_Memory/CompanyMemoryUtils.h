#ifndef __CompanyMemoryUtils_H
#define __CompanyMemoryUtils_H
#include<vector>
#include"cstring"
#include"Company.h"
std::vector<Company> readCompaniesFromMemory(unsigned char* memory, int numCompanies)
{
    std::vector<Company> companies;
    char *localMemory = reinterpret_cast<char*>(memory);
  unsigned char id = 0;
  unsigned char employeesCount = 0;
  std::string name;
  std::vector<std::pair<char, char> > employees;

  for (int i = 0; i < numCompanies; ++i) {
    id = *localMemory;
    localMemory += sizeof (id);

    const size_t nameLen = strlen(localMemory);
    name = std::string(localMemory, nameLen);
    localMemory += (nameLen + 1);

    employeesCount = *localMemory;
    localMemory += sizeof (employeesCount);

    employees.clear();
    for (unsigned char employeeId = 0; employeeId < employeesCount;
        ++employeeId) {
      std::pair<char, char> currEmployee;
      currEmployee.first = *localMemory;
      localMemory += sizeof(currEmployee.first);
      currEmployee.second = *localMemory;
      localMemory += sizeof(currEmployee.second);

      employees.push_back(currEmployee);
    }

    companies.emplace_back(id, name, employees);
  }

    return companies;
}

#endif