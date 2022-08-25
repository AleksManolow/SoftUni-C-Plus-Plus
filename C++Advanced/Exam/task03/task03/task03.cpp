// task03
#include <iostream>
#include <array>
#include <unordered_set>
#include <queue>
const int size = 100;
std::array <std::array<char, size>, size> readMatrix(int& rowAndColSize);
std::array<std::array<char, size>, size> solutionOfProblem(std::array <std::array<char, size>, size> matrix,
	int rowAndColSize);
int main()
{
	int rowAndColSize = 0;
	std::array <std::array<char, size>, size> matrix = readMatrix(rowAndColSize);

	std::array <std::array<char, size>, size> newArr = solutionOfProblem(matrix, rowAndColSize);

	std::cout << std::endl;
	for (int i = 0; i < rowAndColSize; i++)
	{
		for (int j = 0; j < rowAndColSize; j++)
		{
			std::cout << newArr[i][j];
		}
		std::cout << std::endl;
	}


	return 0;
}
std::array <std::array<char, size>, size> readMatrix(int& rowAndColSize)
{
	std::array <std::array<char, size>, size> matrix;

	std::cin >> rowAndColSize;
	for (int i = 0; i < rowAndColSize; i++)
	{
		for (int j = 0; j < rowAndColSize; j++)
		{
			std::cin >> matrix[i][j];
		}
	}

	return matrix;
}
std::queue<char> glitchesSimbol(std::array <std::array<char, size>, size> matrix, int rowAndColSize)
{
	std::unordered_set<char> helpForSimbols;
	std::queue<char> simbols;
	for (int i = 0; i < rowAndColSize; i++)
	{
		for (int j = 0; j < rowAndColSize; j++)
		{
			char currChar = matrix[i][j];
			if (!isalpha(currChar) && !isdigit(currChar) && currChar != '.')
			{
				if (helpForSimbols.find(currChar) == helpForSimbols.end())
				{
					helpForSimbols.insert(currChar);
					simbols.push(currChar);
				}
			}
		}
	}

	return simbols;
}
void removeExcess(std::array <std::array<char, size>, size> matrix,
	int rowAndColSize, char element, int& countI, int& countJ)
{
	int countSimOnRow = 0;
	int cordJ = 0;
	std::queue< int > cordinats;
	for (int i = 0; i < rowAndColSize; i++)
	{
		for (int j = 0; j < rowAndColSize; j++)
		{
			if (matrix[i][j] == element)
			{
				cordJ = j;
				countSimOnRow++;
			}
		}
		if (countSimOnRow == 1)
		{
			cordinats.push(i);
			cordinats.push(cordJ);
		}
		countSimOnRow = 0;
	}
	int firstCordI = 0;
	int firstCordJ = 0;
	int secoundCordI = 0;
	if (!cordinats.empty())
	{
		firstCordI = cordinats.front();
		cordinats.pop();
	}
	if (!cordinats.empty())
	{
		firstCordJ = cordinats.front();
		cordinats.pop();
	}
	if (!cordinats.empty())
	{
		secoundCordI = cordinats.front();
		cordinats.pop();
		cordinats.pop();
	}

	if (((secoundCordI - firstCordI) / 2) % 2 == 0)
	{
		countI = ((secoundCordI - firstCordI) / 2) + firstCordI;
		countJ = firstCordJ;
	}
	else
	{
		countI = ((secoundCordI - firstCordI) / 2)  + firstCordI;
		countJ = firstCordJ;

	}

}
std::array<std::array<char, size>, size> solutionOfProblem(std::array <std::array<char, size>, size> matrix, 
	int rowAndColSize)
{
	std::queue<char> simbols = glitchesSimbol(matrix, rowAndColSize);
	
	std::array<std::array<char, size>, size> newArr;
	for (int i = 0; i < rowAndColSize; i++)
	{
		for (int j = 0; j < rowAndColSize; j++)
		{
			newArr[i][j] = '.';
		}
	}

	int countI = 0;
	int countJ = 0;

	while (!simbols.empty())
	{
		char elemet = simbols.front();
		removeExcess(matrix, rowAndColSize, elemet, countI, countJ);
		newArr[countI][countJ] = elemet;
		simbols.pop();
		countI = 0;
		countJ = 0;
	}

	return newArr;
}
