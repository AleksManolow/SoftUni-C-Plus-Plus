// task03
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>>
#include <sstream>
#include <algorithm>
std::vector<double> readInput();
void sortNumbersInVector(std::vector<double>& numbers);
std::vector<double> produceAnswerNumbers(std::vector<double>& numbers);
void printSolution(std::vector<double>& answerNumber);
int main()
{
	std::vector<double> numbers = readInput();
	sortNumbersInVector(numbers);
	std::vector<double> answerNumber = produceAnswerNumbers(numbers);
	printSolution(answerNumber);
	
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
bool comp(double a, double b)
{
	return (a > b);
}
void sortNumbersInVector(std::vector<double>& numbers)
{
	std::sort(numbers.begin(), numbers.end(), comp);
	
}
std::vector<double> produceAnswerNumbers(std::vector<double>& numbers)
{
	std::unordered_set<double> numbersInset;
	std::vector<double> answerNumber;
	for (double number : numbers)
	{
		if (numbersInset.find(number) == numbersInset.end() && answerNumber.size() < 3)
		{
			numbersInset.insert(number);
			answerNumber.push_back(number);
		}
	}
	return  answerNumber;
}
void printSolution(std::vector<double>& answerNumber)
{
	for (double number : answerNumber)
	{
		std::cout << number << ' ';
	}
}