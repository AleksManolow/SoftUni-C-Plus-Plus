// task01
#include <iostream>
void readInput(int**& matrix, int& row, int& col, int& mod);
void solutionOfProblem(int**& matrix, int row, int col, int mod, int*& colSumAndDivid);
void printSolution(int*& colSumAndDivid, int col);
void releaseMemory(int**& arr2D, int row);
int main()
{
	int row = 0;
	int col = 0;
	int mod = 0;
	int** matrix = nullptr;

	readInput(matrix, row, col, mod);

	int* colSumAndDivid = nullptr;
	solutionOfProblem(matrix, row, col, mod, colSumAndDivid);
	printSolution(colSumAndDivid, col);

	delete[] colSumAndDivid;
	colSumAndDivid = nullptr;
	releaseMemory(matrix, row);
	return 0;
}
void readInput(int**& matrix, int& row, int& col, int& mod)
{
	std::cin >> row >> col;
	matrix = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
		for (int j = 0; j < col; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
	std::cin >> mod;
	
}
void solutionOfProblem(int**& matrix, int row, int col, int mod, int*& colSumAndDivid)
{
	colSumAndDivid = new int[col];
	int sumOfElementOnCol = 0;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			sumOfElementOnCol = sumOfElementOnCol + matrix[j][i];
		}
		colSumAndDivid[i] = sumOfElementOnCol % mod;
		sumOfElementOnCol = 0;
	}
}
void printSolution(int*& colSumAndDivid, int col)
{
	for (int i = 0; i < col; i++)
	{
		std::cout << colSumAndDivid[i] << " ";
	}
}
void releaseMemory(int**& arr2D, int row)
{
	for (size_t i = 0; i < row; i++)
	{
		delete[] arr2D[i];
		arr2D[i] = nullptr;
	}
	delete[] arr2D;
	arr2D = nullptr;
}
