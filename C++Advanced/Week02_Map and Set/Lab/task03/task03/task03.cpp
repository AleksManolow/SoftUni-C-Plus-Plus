// task03.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <unordered_set>
std::vector<std::string> readInput();
std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> putsInNestedMap(
	std::vector<std::string>& input);
void sort(std::vector<std::string>& input,
	std::vector<std::string>& sortContinent,
	std::vector<std::string>& sortCountry);
void preintSolution(std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>>& nestedMap,
	std::vector<std::string>& sortContinent,
	std::vector<std::string>& sortCountry);
int main()
{
	std::vector<std::string> input = readInput();
	std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>>nestedMap
		= putsInNestedMap(input);

	std::vector<std::string> sortContinent;
	std::vector<std::string> sortCountry;
	sort(input, sortContinent, sortCountry);

	preintSolution(nestedMap, sortContinent, sortCountry);

	return 0; 
}
std::vector<std::string> readInput()
{
	int length;
	std::cin >> length;
	std::cin.ignore();

	std::vector<std::string> input(length);

	for (std::string& line : input)
	{
		getline(std::cin, line);
	}
	return input;
}
std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>> putsInNestedMap(
	std::vector<std::string>& input)
{
	std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>>nestedMap;
	std::string continent;
	std::string country;
	std::string citie;

	for (std::string line : input)
	{
		std::istringstream istr(line);
		istr >> continent;
		istr>> country;
		istr >> citie;

		nestedMap[continent][country].push_back(citie);
	}
	return nestedMap;
}
void sort(std::vector<std::string>& input,
	std::vector<std::string>& sortContinent,
	std::vector<std::string>& sortCountry)
{
	std::unordered_set<std::string> helpSortContinent;
	std::unordered_set<std::string> helpSortCountry;
	std::string continent;
	std::string country;

	for (std::string line : input)
	{
		std::istringstream istr(line);
		istr >> continent;
		if (helpSortContinent.find(continent) == helpSortContinent.end())
		{
			helpSortContinent.insert(continent);
			sortContinent.push_back(continent);
		}
		istr >> country;
		if (helpSortCountry.find(country) == helpSortCountry.end())
		{
			helpSortCountry.insert(country);
			sortCountry.push_back(country);
		}
	}
}
void preintSolution(std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>>& nestedMap,
	std::vector<std::string>& sortContinent,
	std::vector<std::string>& sortCountry)
{
	for (std::string continent : sortContinent)
	{
		std::cout << continent << ":" << std::endl;
		for (std::string country : sortCountry)
		{
			if (nestedMap[continent][country].size() != 0)
			{
				std::cout <<" "<< country << " -> ";
				for (int i = 0; i < nestedMap[continent][country].size(); i++)
				{
					std::cout << nestedMap[continent][country][i];
					if (i + 1 != nestedMap[continent][country].size())
					{
						std::cout << ", ";
					}
				}
				std::cout << std::endl;
			}
		}
	}
}

