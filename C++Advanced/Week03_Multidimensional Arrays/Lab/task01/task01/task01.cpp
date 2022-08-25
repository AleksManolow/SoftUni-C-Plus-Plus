// task01
#include<iostream>
#include <array>
#include<sstream>
#include<string>
const int size = 100;
std::array<std::array<int, size>, size> readInput(int& row, int& column);
int main()
{
	int row = 0;
	int column = 0;
	std::array<std::array<int, size>, size> matrix = readInput(row, column);

	int sumColumn = 0;
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			sumColumn = sumColumn + matrix[j][i];
		}
		std::cout << sumColumn << std::endl;
		sumColumn = 0;
	}

	return 0;
}
std::array<std::array<int, size>, size> readInput(int& row, int& column)
{
	std::array<std::array<int, size>, size> matrix;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);
	istr >> row;
	istr >> column;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
	return matrix;
}
