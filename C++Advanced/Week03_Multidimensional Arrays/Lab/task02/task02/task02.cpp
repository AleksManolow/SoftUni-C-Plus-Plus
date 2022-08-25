// task02
#include<iostream>
#include <array>
#include<sstream>
#include<string>
const int size = 100;
std::array<std::array<int, size>, size> readInput(int& rowAndColumn);
int main()
{
	int rowAndColumn = 0;
	std::array<std::array<int, size>, size> matrix = readInput(rowAndColumn);

	int sum = 0;
	for (int i = 0; i < rowAndColumn; i++)
	{
		for (int j = 0; j < rowAndColumn; j++)
		{
			if (i == j)
			{
				sum = sum + matrix[i][j];
			}
		}
		
	}
	std::cout << sum << std::endl;

	return 0;
}
std::array<std::array<int, size>, size> readInput(int& rowAndColumn)
{
	std::array<std::array<int, size>, size> matrix;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);
	istr >> rowAndColumn;

	for (int i = 0; i < rowAndColumn; i++)
	{
		for (int j = 0; j < rowAndColumn; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
	return matrix;
}

