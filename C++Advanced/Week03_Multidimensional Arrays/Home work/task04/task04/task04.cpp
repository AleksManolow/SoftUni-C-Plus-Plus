// task04
#include <iostream>
#include <array>
#include <string>
#include <sstream>
const int size = 100;
std::string readInput(int& row, int& column);
std::array<std::array<char, size>, size> snakeMoves(std::string line, int row, int column);
void printSolution(std::array<std::array<char, size>, size>& snake, int row, int column);
int main()
{
	int row = 0;
	int column = 0;

	std::string line = readInput(row, column);
	std::array<std::array<char, size>, size> snake = snakeMoves(line, row, column);
	printSolution(snake, row, column);

	return 0;
}
std::string readInput(int& row, int& column)
{
	std::string rowAndColumn;
	getline(std::cin, rowAndColumn);
	std::istringstream istr(rowAndColumn);
	istr >> row;
	istr >> column;


	std::string line;
	std::cin >> line;
	
	return line;
}
std::array<std::array<char, size>, size> snakeMoves(std::string line, int row, int column)
{
	std::array<std::array<char, size>, size> snake;

	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			snake[i][j] = line[count];
			if (count < line.size()- 1)
			{
				count++;
			}
			else
			{
				count = 0;
			}
		}
		i++;
		if (i == row)
		{
			break;
		}
		for (int p = column-1; p >= 0; p--)
		{
			snake[i][p] = line[count];
			if (count < line.size() - 1)
			{
				count++;
			}
			else
			{
				count = 0;
			}
		}
	}
	return snake;
}
void printSolution(std::array<std::array<char, size>, size>& snake, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			std::cout << snake[i][j];
		}
		std::cout << std::endl;
	}
}