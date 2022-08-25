// task03
#include <iostream>
void readInput(int**& arr2D, int& row, int& col);
void printSolution(int** arr2D, int newRow, int newCol);
void releaseMemory(int**& arr2D, int row);
int main()
{
	int row = 0;
	int col = 0;
	int** arr2D = nullptr;

	readInput(arr2D, row, col);

	int printRow, printCol;
	std::cin >> printRow >> printCol;

	printSolution(arr2D, printRow, printCol);

	releaseMemory(arr2D, row);
	return 0;
}
void readInput(int**& arr2D, int& row, int& col)
{
	std::cin >> row >> col;

	arr2D = new int* [row];

	for (int i = 0; i < row; i++)
	{
		arr2D[i] = new int [col];
		for (size_t j = 0; j < col; j++)
		{
			std::cin >> arr2D[i][j];
		}
	}
}
void printSolution(int** arr2D, int newRow, int newCol)
{
	for (size_t i = 0; i < newRow; i++)
	{
		for (size_t j = 0; j < newCol; j++)
		{
			std::cout << arr2D[i][j] << ' ';
		}
		std::cout << std::endl;
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

