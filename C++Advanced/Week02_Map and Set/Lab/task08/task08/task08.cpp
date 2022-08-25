// task08
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <string>
std::vector<std::string> readInput();
std::set<std::string> keepsAllUniqueChemicalElements(std::vector<std::string>& input);
void printSolution(std::set <std::string>& uniqueChimicalEl);
int main()
{
	std::vector<std::string> input = readInput();
	std::set <std::string> uniqueChimicalEl = keepsAllUniqueChemicalElements(input);
	printSolution(uniqueChimicalEl);

	return 0;
}
std::vector<std::string> readInput()
{
	int n = 0;
	std::cin >> n;
	std::vector<std::string> input;
	std::string line;
	for (int i = 0; i < 4; i++)
	{
		getline(std::cin, line);
		input.push_back(line);
	}

	return input;
}
std::set<std::string> keepsAllUniqueChemicalElements(std::vector<std::string>& input)
{
	std::set <std::string> uniqueChimicalEl;
	std::vector <std::string> allElements;
	for (std::string lineOfEl : input)
	{
		std::istringstream istr(lineOfEl);
		std::string currStr;
		while (istr >> currStr)
		{
			allElements.push_back(currStr);
		}
	}
	for (std::string element : allElements)
	{
		uniqueChimicalEl.insert(element);
	}

	return uniqueChimicalEl;
}
void printSolution(std::set <std::string>& uniqueChimicalEl)
{
	for (std::string elements : uniqueChimicalEl)
	{
		std::cout << elements << " ";
	}

}