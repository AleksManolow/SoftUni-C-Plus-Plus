#ifndef __LECTURE_H
#define __LECTURE_H
#include <string>
#include <map>
#include <set>
#include <vector>

#include "ResourceType.h"
#include "Resource.h"

namespace SoftUni {

class Lecture
{
private:
    std::set<Resource> resources;
	std::map<ResourceType, int> numberOfResourcesByType;
public:
    Lecture(){ }

    std::set<Resource>::iterator begin() const
    {
        return resources.begin();
    } 
    std::set<Resource>::iterator end() const
    {
        return resources.end();
    } 

    void updateResource(Resource r) 
    {
		if (this->resources.find(r) != this->resources.end()) {
			this->resources.erase(r);
			numberOfResourcesByType[r.getType()]--;
		}

		auto iteratorAndSuccess = this->resources.insert(r);
		numberOfResourcesByType[r.getType()]++;
	}

    int operator[](ResourceType type) const
    {
        return numberOfResourcesByType.at(type);
    }

    friend std::vector<ResourceType>& operator<< (std::vector<ResourceType>& v, Lecture& l);
};

Lecture& operator<<(Lecture& l, Resource r)
{
    l.updateResource(r);
    return l;
}

std::vector<ResourceType>& operator<< (std::vector<ResourceType>& v, Lecture& l)
{
    for(auto pair : l.numberOfResourcesByType)
    {
        v.push_back(pair.first);
    }
    return v;
}

}

#endif