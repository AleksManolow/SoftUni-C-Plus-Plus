// task02
#include <iostream>
#include <string>
#include <sstream>
void readInput(int*& arr, int& size);
bool negativeEl(int a);
void removeNegativeElements(int*& arr, int& size);
void printSolution(int* arr, int size);
void releaseMemory(int*& arr);
int main()
{
	int sizeArr = 0;
	int* arr = nullptr;
	readInput(arr, sizeArr);
	removeNegativeElements(arr, sizeArr);

	releaseMemory(arr);

	return 0;
}
void readInput(int*& arr, int& size)
{
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);

	const size_t maxSize = (line.size() / 2) + 1;
	arr = new int[maxSize] {};
	size = 0;

	int currNumber = 0;
	while (istr >> currNumber)
	{
		arr[size] = currNumber;
		size++;
	}
}
bool negativeEl(int a) 
{ 
	return a <  0;
}
void sizeOnNewArr(int* arr, int size, int& newSize)
{
	for (size_t i = 0; i < size; i++)
	{
		if (!negativeEl(arr[i]))
		{
			newSize++;
		}
	}
}
void removeNegativeElements(int*& arr, int& size)
{
	int newSize = 0;
	sizeOnNewArr(arr, size, newSize);
	if (newSize == 0)
	{
		std::cout << "empty" << std::endl;
	}
	else
	{
		int* newArr = new int[newSize] {};

		int counter = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (!negativeEl(arr[i]))
			{
				newArr[counter] = arr[i];
				counter++;
			}
		}
		printSolution(newArr, newSize);

		releaseMemory(newArr);
	}
}
void printSolution(int* arr, int size)
{
	for (int i = (size-1); i >= 0; i--)
	{
		std::cout << arr[i] << " ";
	}
}
void releaseMemory(int*& arr)
{
	delete[] arr;
	arr = nullptr;
}