// task04
#include <iostream>
#include <vector>
#include <unordered_set>
std::vector<std::string> readInput();
void sortNamesInSet(std::vector<std::string>& vec);
int main()
{
	std::vector<std::string> vec = readInput();
	sortNamesInSet(vec);

	return 0;
}
std::vector<std::string> readInput()
{
	int number;
	std::cin >> number;
	std::vector<std::string> vec(number);

	for (std::string& name : vec)
	{
		std::cin >> name;
	}

	return vec;
}
void sortNamesInSet(std::vector<std::string>& vec)
{
	std::unordered_set<std::string> names;
	for (std::string name : vec)
	{
		if (names.find(name) == names.end())
		{
			names.insert(name);
			std::cout << name << std::endl;
		}
	}
}

