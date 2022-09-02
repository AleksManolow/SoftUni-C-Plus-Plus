#ifndef __ARRAYOFPOINTERS_H
#define __ARRAYOFPOINTERS_H
#include"Company.h"

#include<vector>
#include<memory>

class ArrayOfPointers
{
	std::vector<std::shared_ptr<Company> > pointers;

public:
	ArrayOfPointers() {}

	void add(Company* company) {
		this->pointers.push_back(std::shared_ptr<Company>(company));
	}

	int getSize() const {
		return this->pointers.size();
	}

	Company* get(int index) const {
		return this->pointers.at(index).get();
	}
};

#endif