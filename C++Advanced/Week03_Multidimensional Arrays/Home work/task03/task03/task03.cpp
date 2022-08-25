// task03
#include <iostream>
#include <string>
#include <array>
#include <sstream>
const int size = 100;
std::array<std::array<char, size>, size> readInput(int& row, int& column);
int squaresInMatrix(std::array<std::array<char, size>, size>& matrix, int row, int column);
int main()
{
	int row = 0;
	int column = 0;
	std::array<std::array<char, size>, size> matrix = readInput(row, column);
	std::cout << squaresInMatrix(matrix, row, column) << std::endl;

	return 0;
}
std::array<char, size> readArr1D(int column)
{
	std::array<char, size> arr;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);

	char currChar;
	for (int i = 0; i < column; i++)
	{
		istr >> currChar;
		arr[i] = currChar;
	}
	return arr;
}
std::array<std::array<char, size>, size> readInput(int& row, int& column)
{
	std::array<std::array<char, size>, size> matrix;
	std::string rowAndColumn;
	getline(std::cin, rowAndColumn);
	std::istringstream istr(rowAndColumn);
	istr >> row;
	istr >> column;

	for (int i = 0; i < row; i++)
	{
		matrix[i] = readArr1D(column);
	}
	return matrix;
}
int squaresInMatrix(std::array<std::array<char, size>, size>& matrix, int row, int column)
{
	int countSquareInMatrix = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (matrix[i][j] == matrix[i + 1][j] && matrix[i][j + 1] == matrix[i + 1][j + 1] &&
				matrix[i][j] == matrix[i + 1][j + 1])
			{
				countSquareInMatrix++;
			}
		}

	}
	return countSquareInMatrix;
}
