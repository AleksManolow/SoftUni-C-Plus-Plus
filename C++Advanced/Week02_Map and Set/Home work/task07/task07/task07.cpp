// task07
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <unordered_set>
std::vector<std::string> readInput();
std::unordered_map<std::string, int > resourceQuantity(std::vector<std::string>& resourceAndQuantity);
std::vector<std::string> sortResource(std::vector<std::string>& resourceAndQuantity);
void printSolution(std::unordered_map<std::string, int>& resourceQuantityMap, 
				   std::vector<std::string>& sort);
int main()
{
	std::vector<std::string> resourceAndQuantity = readInput();
	std::unordered_map<std::string, int> resourceQuantityMap = resourceQuantity(resourceAndQuantity);
	std::vector<std::string> sort = sortResource(resourceAndQuantity);
	
	printSolution(resourceQuantityMap, sort);

	return 0;
}
std::vector<std::string> readInput()
{
	std::vector<std::string> resourceAndQuantity;
	std::string line;

	while (line != "stop")
	{
		resourceAndQuantity.push_back(line);
		getline(std::cin, line);
	}

	return resourceAndQuantity;
}
std::unordered_map<std::string, int > resourceQuantity(std::vector<std::string>& resourceAndQuantity)
{
	std::unordered_map<std::string, int> resourceQuantityMap;

	std::ostringstream ostr;
	for (std::string word : resourceAndQuantity)
	{
		ostr << word << ' ';
	}
	std::string answer = ostr.str();

	std::istringstream istr(answer);
	for (int i = 0; i < resourceAndQuantity.size() / 2; i++)
	{
		std::string resourse;
		std::string quantityString;

		istr >> resourse;
		istr >> quantityString;

		int quantity = std::stoi(quantityString);
		resourceQuantityMap[resourse] = resourceQuantityMap[resourse] + quantity;
	}

	return resourceQuantityMap;
}
std::vector<std::string> sortResource(std::vector<std::string>& resourceAndQuantity)
{
	std::unordered_set<std::string> helpSort;
	std::vector<std::string>sort;
	for (int i = 1; i < resourceAndQuantity.size(); i++)
	{
		std::string currResourse = resourceAndQuantity[i];
		if (helpSort.find(currResourse) == helpSort.end())
		{
			helpSort.insert(currResourse);
			sort.push_back(currResourse);
		}
		i++;
	}
	return sort;
}
void printSolution(std::unordered_map<std::string, int>& resourceQuantityMap, 
				   std::vector<std::string>& sort)
{
	for (std::string resourse : sort)
	{
		std::cout << resourse << " -> " << resourceQuantityMap[resourse] << std::endl;
	}
}
