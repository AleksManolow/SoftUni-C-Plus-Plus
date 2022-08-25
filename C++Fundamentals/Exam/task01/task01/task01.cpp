// task01
#include <iostream>
#include <array>
const int size = 1000;
std::array <int, size> readInput(int& arrSize);
int averageArrFunction(std::array <int, size>& arr, int arrSize);
void sumOfElemetsInEvenAndOddPosition(std::array <int, size>& arr, int arrSize, int averageArrValue);
int main()
{
	int arrSize = 0;
	std::array <int, size> arr = readInput(arrSize);
	int averageArr = averageArrFunction(arr, arrSize);
	sumOfElemetsInEvenAndOddPosition(arr, arrSize, averageArr);
	
	return 0;
}
std::array <int, size> readInput(int& arrSize)
{
	std::cin >> arrSize;
	std::array <int, size> arr;
	for ( int i = 0; i < arrSize; i++)
	{
		std::cin >> arr[i];
	}
	return arr;
}
int averageArrFunction(std::array <int, size>& arr, int arrSize)
{
	int sum = 0;
	int avarage = 0;
	for (int i = 0; i < arrSize; i++)
	{
		sum = sum + arr[i];
	}
	avarage = sum / arrSize;
	return avarage;
}
void sumOfElemetsInEvenAndOddPosition(std::array <int, size>& arr, int arrSize, int averageArrValue)
{
	int evenSum = 0;
	int oddSum = 0;
	int sumOfAll = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] <= averageArrValue)
		{
			if (i % 2 == 0)
			{
				evenSum = evenSum + arr[i]; 
			}
			else if(i % 2 == 1)
			{
				oddSum = oddSum + arr[i];
			}
		}
	}
	sumOfAll = evenSum * oddSum;
	std::cout << sumOfAll << std::endl;
}
