// task05
#include <iostream>
#include <vector>
#include <set>
#include<sstream>
#include <string>
#include <algorithm>
std::vector<int> readInput();
std::set<int> sortNumbers(std::vector<int>& numbers);
void printSolution(std::set<int>sortNumbers);
int main()
{
	std::vector<int> numbers = readInput();
	std::set<int>sortNumbersSet = sortNumbers(numbers);
	printSolution(sortNumbersSet);

	return 0;
}
std::vector<int> readInput()
{
	std::vector<int> numbers;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);

	int currNumber = 0;
	while (istr >> currNumber)
	{
		numbers.push_back(currNumber);
	}

	return numbers;
}
std::set<int> sortNumbers(std::vector<int>& numbers)
{

	std::set<int>sortNumbers;
	for (int number: numbers)
	{
		if (sortNumbers.find(number) == sortNumbers.end())
		{
			sortNumbers.insert(number);
		}
	}

	return sortNumbers;
}
void printSolution(std::set<int>sortNumbers)
{
	std::vector<int> answerSolution;
	for (int number:sortNumbers)
	{
		answerSolution.push_back(number);
	}
	std::ostringstream ostr;
	for (int number : sortNumbers)
	{
		ostr << number << " <= ";
	}
	std::string answer = ostr.str();

	answer.pop_back();
	answer.pop_back();
	answer.pop_back();
	answer.pop_back();

	std::cout << answer << std::endl;
}