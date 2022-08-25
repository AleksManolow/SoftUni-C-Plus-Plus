// task06
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
std::vector<int> readInput();
std::vector<int> squaresNumbers(std::vector<int>& numbers);
void sortVacSquaresNumber(std::vector<int>& squares);
void printSolutio(std::vector<int>& squares);
int main()
{
	std::vector<int> numbers = readInput();
	std::vector<int> squares = squaresNumbers(numbers);
	sortVacSquaresNumber(squares);
	printSolutio(squares);
	
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
std::vector<int> squaresNumbers(std::vector<int>& numbers)
{
	std::vector<int> squares;
	for (int number : numbers)
	{
		double squareNumber = sqrt(number);
		if (number == squareNumber * squareNumber )
		{
			squares.push_back(number);
		}
	}
	return squares;
}
bool sort(int i, int j)
{
	return (i > j);
}
void sortVacSquaresNumber(std::vector<int>& squares)
{
	std::sort(squares.begin(), squares.end(), sort);
}
void printSolutio(std::vector<int>& squares)
{
	for (int number : squares)
	{
		std::cout << number << ' ';
	}
}