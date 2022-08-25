// task02
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
std::vector<std::vector<int >> readInput(int& row, int& column, int& findNumber);
std::queue <int> findThisNumber(std::vector<std::vector<int >>& vec2D, int findNumber, int row, int columns);
void printSolution(std::queue<int>& rowAndColumnOnFineNumber);
int main()
{ 
	int row = 0;
	int column = 0;
	int findNumber = 0;
	std::vector<std::vector<int >> vec2D = readInput(row, column, findNumber);
	std::queue<int> rowAndColumnOnFineNumber = findThisNumber(vec2D, findNumber, row, column);
	printSolution(rowAndColumnOnFineNumber);

	return 0;
}
std::vector<int> readVec1D(int column)
{
	std::vector<int> vec1D;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr1(line);

	int currNumber = 0;
	while (istr1 >> currNumber)
	{
		vec1D.push_back(currNumber);
	}
	return vec1D;
}
std::vector<std::vector<int >> readInput(int& row, int& column, int& findNumber)
{
	std::string rowAndColumn;
	getline(std::cin, rowAndColumn);
	std::istringstream istr(rowAndColumn);
	istr >> row;
	istr >> column;

	std::vector<std::vector<int >> vec2D (row);

	for (auto& row : vec2D)
	{
		row = readVec1D(column);
	}
	std::cin >> findNumber;

	return vec2D;
}
std::queue <int> findNumberIn1DVec(std::vector<int>& vec1D, int columns, int findNumber)
{
	std::queue <int> columnsFindNumber;
	for (int i = 0; i < columns; i++)
	{
		if (vec1D[i] == findNumber)
		{
			columnsFindNumber.push(i);
		}
	}
	return columnsFindNumber;
}
std::queue <int> findThisNumber(std::vector<std::vector<int >>& vec2D, int findNumber, int row, int columns)
{
	std::queue<int> rowAndColumnOnFineNumber;
	int i = 0;
	for (auto vec1 : vec2D) 
	{
		std::queue<int> colmnsFindNumber = findNumberIn1DVec(vec1, columns, findNumber);
		if (!colmnsFindNumber.empty())
		{
			int topColumn = 0;
			while (!colmnsFindNumber.empty())
			{
				topColumn = colmnsFindNumber.front();
				rowAndColumnOnFineNumber.push(i);
				rowAndColumnOnFineNumber.push(topColumn);
				colmnsFindNumber.pop();
			}
		}
		i++;
	}
	return rowAndColumnOnFineNumber;
}
void printSolution(std::queue<int>& rowAndColumnOnFineNumber)
{
	if (rowAndColumnOnFineNumber.empty())
	{
		std::cout << "not found" << std::endl;
	}
	else
	{
		while (!rowAndColumnOnFineNumber.empty())
		{
			std::cout << rowAndColumnOnFineNumber.front() << " ";
			rowAndColumnOnFineNumber.pop();
			std::cout << rowAndColumnOnFineNumber.front();
			rowAndColumnOnFineNumber.pop();
			std::cout << std::endl;
		}
	}
	
}