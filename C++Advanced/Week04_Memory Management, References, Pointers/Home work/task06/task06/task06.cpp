// task06
#include <iostream>
#include <sstream>
#include <string>
const int maxSizeRowAndCol = 10;
void readArr(int**& arr, int& row, int& col);
bool equalOrNotEqual(int** firstArr, int rowFirstArr, int colFirstArr,
	int** secoundArr, int rowSecoundArr, int colSecoundArr);
void releaseMemory(int**& arr2D, int row);
int main()
{
	int rowFirstArr = 0;
	int colFirstArr = 0;
	int** firstArr = nullptr;
	readArr(firstArr, rowFirstArr, colFirstArr);

	int rowSecoundArr = 0;
	int colSecoundArr = 0;
	int** secoundArr = nullptr;
    readArr(secoundArr, rowSecoundArr, colSecoundArr);

	
	
	bool equal = equalOrNotEqual(firstArr, rowFirstArr, colFirstArr,
		secoundArr, rowSecoundArr, colSecoundArr);

	(equal) ? std::cout << "equal" << std::endl : std::cout << "not equal" << std::endl;

	releaseMemory(firstArr, rowFirstArr);
	releaseMemory(secoundArr, rowSecoundArr);

	return 0;
}
void readArr(int**& arr, int& row, int& col)
{
	std::cin >> row;
	std::cin.ignore();

	arr = new int* [row] {};
	
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[maxSizeRowAndCol] {};

		std::string line;
		getline(std::cin, line);
		std::istringstream istr(line);

		col = 0;
		int currNumber = 0;
		while (istr >> currNumber)
		{
			arr[i][col] = currNumber;
			col++;
		}
	}
}
bool equalOrNotEqual(int** firstArr, int rowFirstArr, int colFirstArr,
	int** secoundArr, int rowSecoundArr, int colSecoundArr)
{
	if (rowFirstArr != rowSecoundArr || colFirstArr != colSecoundArr)
	{
		return false;
	}
	for (size_t i = 0; i < rowFirstArr; i++)
	{
		for (size_t j = 0; j < colFirstArr; j++)
		{
			if (firstArr[i][j] != secoundArr[i][j])
			{
				return false;
			}
		}
	}
	return true;
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