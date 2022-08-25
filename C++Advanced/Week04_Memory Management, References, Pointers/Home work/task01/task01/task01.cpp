// task01
#include <iostream>
#include <string>
#include <sstream>
void readInput(int*& arr, int& size);
void copyElementsInResultArr(int* arr, int*& resultArr, int resultArrSize);
void reverseElements(int* inputArr, int inputArrSize,
	int* resultArr, int resultArrSize);
void printsElements(int* arr, int size);
void releaseMemory(int*& arr);
int main()
{
	int* arr = nullptr;
	int arrSize = 0;
	readInput(arr, arrSize);

	int halfArrSize = 0;
	if (arrSize % 2 == 1)
	{
		halfArrSize = (arrSize / 2) + 1;
	}
	else
	{
		halfArrSize = arrSize / 2;
	}
	int* resultArr = new int[halfArrSize] {};
	copyElementsInResultArr(arr, resultArr, halfArrSize);
	reverseElements(arr, arrSize, resultArr, halfArrSize);
	printsElements(resultArr, halfArrSize);
	releaseMemory(resultArr);
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
void copyElementsInResultArr(int* arr, int*& resultArr, int resultArrSize)
{
	for (size_t i = 0; i < resultArrSize; i++)
	{
		resultArr[i] = arr[i];
	}
}
void reverseElements(int* inputArr, int inputArrSize,
					 int* resultArr, int resultArrSize)
{
	const int iterationCount = inputArrSize / 2;
	for (size_t i = 0; i < iterationCount; i++)
	{
		resultArr[i] = inputArr[i] + inputArr[inputArrSize - 1 - i];
	}
}
void printsElements(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}
void releaseMemory(int*& arr)
{
	delete[] arr;
	arr = nullptr;
}


