// task03
#include <iostream>
void readInput(char**& matrix, int& row, int& col,
	char& replacementEl, int& rowOfEl, int& colOfEl);
bool isBadSimwol(char a, char replacementEl, char elFromMatrix);
bool isItPossibleToRust(int cordI, int cordJ, int row, int col);
void rustSpread(char**& matrix, int rowI, int colJ,
	char replacementEl, char elFromMatrix,
	int row, int col);
void gaveCordenats(char**& matrix, int* cordinates, int sizeArr,
	int row, int col,
	char replacementEl, char elFromMatrix,
	int rowOfEl, int colOfEl);
void circlingMatrix(char**& matrix, int row, int col,
	char replacementEl, char elFromMatrix,
	int rowOfEl, int colOfEl);
void solutioOfProblem(char**& matrix, int row, int col,
	char replacementEl, int rowOfEl, int colOfEl);
void printSolutio(char**& matrix, int row, int col);
void releaseMemory(char**& arr2D, int row);
int main()
{
	int row = 0;
	int col = 0;
	char** matrix = nullptr;

	char replacementEl;
	int rowOfEl = 0;
	int colOFEl = 0;

	readInput(matrix, row, col, replacementEl, rowOfEl, colOFEl);

	solutioOfProblem(matrix, row, col, replacementEl, rowOfEl, colOFEl);

	printSolutio(matrix, row, col);
	releaseMemory(matrix, row);

	return 0;
}
void readInput(char**& matrix, int& row, int& col,
	char& replacementEl, int& rowOfEl, int& colOfEl)
{
	std::cin >> row >> col;
	matrix = new char* [row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new char[col];
		for (int j = 0; j < col; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
	std::cin >> replacementEl;
	std::cin >> rowOfEl >> colOfEl;
}
bool isBadSimwol(char a,char replacementEl, char elFromMatrix)
{
	if (a == replacementEl || a != elFromMatrix)
	{
		return false;
	}
	return true;
}
bool isItPossibleToRust(int cordI, int cordJ,int row,int col)
{
	if (row <= cordI || col <= cordJ || cordI < 0 || cordJ < 0)
	{
		return false;
	}
	return true;
}
void rustSpread(char**& matrix, int rowI, int colJ, 
	char replacementEl, char elFromMatrix,
	int row, int col)
{

	if (isItPossibleToRust((rowI - 1), colJ, row, col) && isBadSimwol(matrix[rowI - 1][colJ], replacementEl, elFromMatrix))
	{
		matrix[rowI - 1][colJ] = replacementEl;
	}
	if (isItPossibleToRust((rowI + 1), colJ,row, col) && isBadSimwol(matrix[rowI + 1][colJ], replacementEl, elFromMatrix))
	{
		matrix[rowI + 1][colJ] = replacementEl;
	}
	if (isItPossibleToRust(rowI, (colJ - 1), row, col) && isBadSimwol(matrix[rowI][colJ - 1], replacementEl, elFromMatrix))
	{
		matrix[rowI][colJ - 1] = replacementEl;
	}
	if (isItPossibleToRust(rowI, (colJ + 1), row, col) && isBadSimwol(matrix[rowI][colJ + 1], replacementEl, elFromMatrix))
	{
		matrix[rowI][colJ + 1] = replacementEl;
	}

}
void gaveCordenats(char**& matrix, int* cordinates, int sizeArr, 
						int row, int col, 
						char replacementEl,char elFromMatrix,
						int rowOfEl, int colOfEl )
{
	int rowI = 0;
	int colJ = 0;
	for (size_t i = 0; i < sizeArr; i++)
	{
		rowI = cordinates[i];
		i++;
		colJ = cordinates[i];
		rustSpread(matrix, rowI, colJ, replacementEl, elFromMatrix, row, col);
	}
}
void circlingMatrix(char**& matrix,int row, int col, 
 char replacementEl,char elFromMatrix,
 int rowOfEl, int colOfEl )
{
	int* cordinates = new int[200]{};
	int arrCounter = 0;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			if (matrix[i][j] == replacementEl)
			{
				cordinates[arrCounter] = i;
				arrCounter++;
				cordinates[arrCounter] = j;
				arrCounter++;
			}
		}
	}
	int sizeArr = arrCounter - 1;
	gaveCordenats(matrix, cordinates, sizeArr,row, col, 
						replacementEl, elFromMatrix,
						 rowOfEl, colOfEl );
	delete[] cordinates;
}
void solutioOfProblem(char**& matrix, int row, int col,
	char replacementEl, int rowOfEl, int colOfEl)
{
	char elFromMatrix = matrix[rowOfEl][colOfEl];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == rowOfEl && j == colOfEl)
			{
				matrix[i][j] = replacementEl;
				break;
			}
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			circlingMatrix(matrix, row, col, replacementEl, elFromMatrix, rowOfEl, colOfEl);
		}
	}
}
void printSolutio(char**& matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}
}
void releaseMemory(char**& arr2D, int row)
{
	for (int i = 0; i < row; i++)
	{
		delete[] arr2D[i];
		arr2D[i] = nullptr;
	}
	delete[] arr2D;
	arr2D = nullptr;
}

