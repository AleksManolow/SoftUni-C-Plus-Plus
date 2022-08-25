// task02
#include <iostream>
const int rowAndColmnSize = 10;
void readInput(char**& matrix, int& elapsedTime);
bool isBadSimwol(char a);
bool isItPossibleToRust(int cordI, int cordJ);
void rustSpread(char**& matrix, int rowI, int colJ);
void gaveCordenats(char**& matrix, int* cordinates, int sizeArr);
void circlingMatrix(char**& matrix);
void solutionOfTheProblem(char**& matrix, int elapsedTime);
void printSolution(char**& matrix);
void releaseMemory(char**& matrix);
int main()
{
	int elapsedTime = 0;
	char** matrix = nullptr;
	readInput(matrix, elapsedTime);
	

	solutionOfTheProblem(matrix, elapsedTime);

	printSolution(matrix);
	releaseMemory(matrix);
	return 0;
}
void readInput(char**& matrix, int& elapsedTime)
{
	matrix = new char* [rowAndColmnSize] {};

	for (size_t i = 0; i < rowAndColmnSize; i++)
	{
		matrix[i] = new char[rowAndColmnSize] {};

		for (size_t j = 0; j < rowAndColmnSize; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
	std::cin >> elapsedTime;
}
bool isBadSimwol(char a)
{
	if (a == '#' || a == '!')
	{
		return false;
	}
	return true;
}
bool isItPossibleToRust(int cordI, int cordJ)
{
	if (rowAndColmnSize <= cordI || rowAndColmnSize <= cordJ || cordI < 0 || cordJ < 0)
	{
		return false;
	}
	return true;
}
void rustSpread(char**& matrix, int rowI, int colJ)
{

	if (isItPossibleToRust((rowI - 1), colJ) && isBadSimwol(matrix[rowI - 1][colJ]))
	{
		matrix[rowI - 1][colJ] = '!';
	}
	if (isItPossibleToRust((rowI + 1), colJ) && isBadSimwol(matrix[rowI + 1][colJ]))
	{
		matrix[rowI + 1][colJ] = '!';
	}
	if (isItPossibleToRust(rowI, (colJ - 1)) && isBadSimwol(matrix[rowI][colJ - 1]))
	{
		matrix[rowI][colJ - 1] = '!';
	}
	if (isItPossibleToRust(rowI, (colJ + 1)) && isBadSimwol(matrix[rowI][colJ + 1]))
	{
		matrix[rowI][colJ + 1] = '!';
	}

}
void gaveCordenats(char**& matrix, int* cordinates, int sizeArr)
{
	int rowI = 0;
	int colJ = 0;
	for (size_t i = 0; i < sizeArr; i++)
	{	
		rowI = cordinates[i];
		i++;
		colJ = cordinates[i];
		rustSpread(matrix, rowI, colJ);
	}
}
void circlingMatrix(char**& matrix)
{
	int* cordinates = new int[200] {};
	int arrCounter = 0;
	for (size_t i = 0; i < rowAndColmnSize; i++)
	{
		for (size_t j = 0; j < rowAndColmnSize; j++)
		{
			if (matrix[i][j] == '!')
			{
				cordinates[arrCounter] = i;
				arrCounter++;
				cordinates[arrCounter] = j;
				arrCounter++;
			}
		}
	}
	int sizeArr = arrCounter - 1;
	gaveCordenats(matrix, cordinates, sizeArr);
	delete[] cordinates;
}
void solutionOfTheProblem(char**& matrix, int elapsedTime)
{
	for (int i = 0; i < elapsedTime; i++)
	{
		circlingMatrix(matrix);
	}

}
void printSolution(char**& matrix)
{
	for (size_t i = 0; i < rowAndColmnSize; i++)
	{
		for (size_t j = 0; j < rowAndColmnSize; j++)
		{
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}

}
void releaseMemory(char**& matrix)
{
	for (int i = 0; i < rowAndColmnSize; i++)
	{
		delete[] matrix[i];
		matrix[i] = nullptr;
	}

	delete[] matrix;
	matrix = nullptr;
}