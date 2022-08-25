// task01
#include <iostream>
#include <vector>
#include<map>
#include <string>
#include <sstream>
#include <set>
std::vector<double> readInput();
std::map<double, int> numberOfOccurrences(std::vector<double>& numbers);
void printSolution(std::vector<double>& numbers, std::map<double, int>& numOccur);
int main()
{
	std::vector<double> numbers = readInput();
	std::map<double, int> numOccur = numberOfOccurrences(numbers);
	printSolution(numbers, numOccur);
	return 0;
}
std::vector<double> readInput()
{
	std::vector<double> numbers;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);

	double currNumber = 0;
	while (istr >> currNumber)
	{
		numbers.push_back(currNumber);
	}
	return numbers;
}
std::map<double, int> numberOfOccurrences(std::vector<double>& numbers)
{
	std::map<double, int> numOccur;
	for (const double number : numbers)
	{
		numOccur[number]++;
	}

	return numOccur;
}
void printSolution(std::vector<double>& numbers, std::map<double, int>& numOccur)
{
	std::set<double> helpSort;
	for (double number : numbers)
	{
		if (helpSort.find(number) == helpSort.end())
		{
			helpSort.insert(number);
			std::cout << number << " - " << numOccur[number] << " times" << std::endl;
		}
	}

}
