// task07
#include <iostream>
void readArr(char**& arr, int& row, int& col);
void creatingNewMatrix(int**& matrixNumbers, int row, int col);
bool isThereAnElement(int cordI, int cordJ, int row, int colum);
void elementsThatIncrease(int**& matrixNumbers, int cordI, int cordJ, int row, int col);
void solutionOfTheProblem(char**& arr, int row, int col, int**& matrixNumbers);
void printSolution(int**& matrixNumbers, int row, int col);
void releaseMemory(char**& arr2D, int row);
void releaseMemoryIntArr(int**& arr2D, int row);
int main()
{
	int row = 0;
	int col = 0;
	char** matrix = nullptr;
	readArr(matrix, row, col);

	int** matrixNumbers = nullptr;
	creatingNewMatrix(matrixNumbers, row, col);
	solutionOfTheProblem(matrix, row, col, matrixNumbers);
	
	printSolution(matrixNumbers, row, col);

	releaseMemory(matrix, row);
	releaseMemoryIntArr(matrixNumbers, row);
	return 0;
}
void readArr(char**& arr, int& row, int& col)
{
	std::cin >> row;
	std::cin >> col;

	arr = new char* [row] {};
	
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new char[col] {};

		for (size_t j = 0; j < col; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}
void creatingNewMatrix(int**& matrixNumbers, int row, int col)
{
	matrixNumbers = new int* [row] {};

	for (int i = 0; i < row; i++)
	{
		matrixNumbers[i] = new int[col] {};
	}
}

bool isThereAnElement(int cordI, int cordJ, int row, int colum)
{
	if (row <= cordI || colum <= cordJ || cordI < 0 || cordJ < 0)
	{
		return false;
	}
	return true;
}
void elementsThatIncrease(int**& matrixNumbers, int cordI, int cordJ, int row, int col)
{
	
	for (int i = (cordI - 1); i <= (cordI + 1); i++)
	{
		for (int j = (cordJ - 1); j <= (cordJ + 1); j++)
		{
			if (isThereAnElement(i, j , row, col))
			{
				matrixNumbers[i][j]++;
			}
		}
	}
}
void solutionOfTheProblem(char**& arr, int row, int col, int**& matrixNumbers)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == '!')
			{
				elementsThatIncrease(matrixNumbers, i, j, row, col);
			}
		}
	}
}
void printSolution(int**& matrixNumbers, int row, int col)
{
	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << matrixNumbers[i][j];
		}
		std::cout << std::endl;
	}


}
void releaseMemory(char**& arr2D, int row)
{
	for (size_t i = 0; i < row; i++)
	{
		delete[] arr2D[i];
		arr2D[i] = nullptr;
	}
	delete[] arr2D;
	arr2D = nullptr;
}
void releaseMemoryIntArr(int**& arr2D, int row)
{
	for (size_t i = 0; i < row; i++)
	{
		delete[] arr2D[i];
		arr2D[i] = nullptr;
	}
	delete[] arr2D;
	arr2D = nullptr;
}
