// task01
#include <iostream>
void readInput(int*& arr, int& size);
int main()
{
	int size = 0;
	int* arr = nullptr;
	readInput(arr, size);

	int maxCounter = 0;
	int counter = 0;

	for (int i = 0; i < (size-1); i++)
	{
		if (arr[i] < arr[i+1])
		{
			counter++;
		}
		else
		{
			counter = 0;
		}

		if (counter > maxCounter)
		{
			maxCounter = counter;
		}
	}
	std::cout << (maxCounter + 1) << std::endl;

	delete[] arr;
	return 0;
}
void readInput(int*& arr, int& size)
{
	std::cin >> size;

	arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}