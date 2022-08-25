// task09
#include <iostream>
#include <array>
#include <map>
const int size = 1000;
std::array<int, size> readInput(int& numberOfElements);
int main()
{
	int numberOfElements = 0;
	std::array<int, size> numbers = readInput(numberOfElements);
	std::map<int, int> equalEl;
	for (int i = 0; i < numberOfElements; i++)
	{
		equalEl[numbers[i]]++;
	}
	for (auto el : equalEl)
	{
		if (el.second % 2 == 0)
		{
			std::cout << el.first << std::endl;
		}
	}
	return 0;
}
std::array<int, size> readInput(int& numberOfElements)
{
	std::cin >> numberOfElements;
	std::array<int, size> numbers;

	for (int i = 0; i < numberOfElements; i++)
	{
		std::cin >> numbers[i];
	}

	return numbers;
}