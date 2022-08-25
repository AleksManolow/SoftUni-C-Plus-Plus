#include<iostream>
#include <array>
#include<sstream>
#include<string>
#include <cmath>
const int size = 100;
std::array<std::array<int, size>, size> readInput(int& rowAndColumn);
int main()
{
	int rowAndColumn = 0;
	std::array<std::array<int, size>, size> matrix = readInput(rowAndColumn);

	int sumMainDiagonal = 0;
	int sumSecondaryDiagonal = 0;
	for (int i = 0; i < rowAndColumn; i++)
	{
		for (int j = 0; j < rowAndColumn; j++)
		{
			if (i == j)
			{
				sumMainDiagonal += matrix[i][j];
			}
			if (i + j == rowAndColumn - 1)
			{
				sumSecondaryDiagonal += matrix[i][j];
			}
		}
	}
	int difference = 0;
	difference = sumMainDiagonal - sumSecondaryDiagonal;
	std::cout << abs(difference) << std::endl;
	
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
