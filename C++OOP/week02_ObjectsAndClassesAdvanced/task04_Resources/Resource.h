#ifndef RESOURCE_H
#define RESOURCE_H
#include "ResourceType.h"
namespace SoftUni {
    class Resource
    {
    private:
        int id;
        SoftUni::ResourceType type;
        std::string link;
    public:
        Resource(){}
        
        int getId() const
        {
            return id;
        } 
        ResourceType getType()const
        {
            return type;
        } 
        std::string getLink() const
        {
            return link;
        }
        bool operator<(const Resource& other) const {
			return this->id < other.id;
		}
        friend std::ostream& operator<<(std::ostream& out, const Resource& other);
        friend std::istream& operator>>(std::istream& in, Resource& other);
        

    };
    std::ostream& operator<<(std::ostream& out, const Resource& other)
    {
		return out << other.id << " " << other.type << " " << other.link;
    }
    std::istream& operator>>(std::istream& in, Resource& other)
    {
        in >> other.id;
        std::string typeName; 
        in >> typeName;
        
		if (typeName == "Presentation") {
			other.type = ResourceType::PRESENTATION;
		}
		else if (typeName == "Demo") {
			other.type  = ResourceType::DEMO;
		}
		else if (typeName == "Video") {
			other.type  = ResourceType::VIDEO;
		}
        in >> other.link;

        return in;
    }
}





#endif 