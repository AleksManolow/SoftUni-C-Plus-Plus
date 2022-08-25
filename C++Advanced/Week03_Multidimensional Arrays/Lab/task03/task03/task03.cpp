#include<iostream>
#include <array>
#include<sstream>
#include<string>
const int size = 100;
std::array<std::array<char, size>, size> readInput(int& rowAndColumn, char& receiveSymbol);
int main()
{
	int rowAndColumn = 0;
	char receiveSymbol;
	std::array<std::array<char, size>, size> matrix = readInput(rowAndColumn, receiveSymbol);

	int count = 0;
	for (int i = 0; i < rowAndColumn; i++)
	{
		for (int j = 0; j < rowAndColumn; j++)
		{
			if (matrix[i][j] == receiveSymbol)
			{
				std::cout << "(" << i << ", " << j << ")" << std::endl;
				count++;
				break;
			}
		}
	}
	if (count == 0)
	{
		std::cout << receiveSymbol << " does not occur in the matrix" << std::endl;
	}
	return 0;
}
std::array<std::array<char, size>, size> readInput(int& rowAndColumn, char& receiveSymbol)
{
	std::array<std::array<char, size>, size> matrix;
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
	std::cin >> receiveSymbol;
	return matrix;
}
