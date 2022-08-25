// Function referens
#include <iostream>
#include <vector>
std::vector<int> filterVec(std::vector<int>& vec, bool(*filter)(int number));
bool biggerThem3(int number);
bool isEven(int number);
bool negativeNumber(int number);
void print(std::vector<int>& vec);
int main()
{
	std::vector<int> vec = { 1, 2, 35, 8 ,-45, 15, -89 };

	std::vector<int> newVec = filterVec(vec, biggerThem3);
	print(newVec);

	newVec = filterVec(vec, isEven);
	print(newVec);

	newVec = filterVec(vec, negativeNumber);
	print(newVec);

	return 0;
}
void print(std::vector<int>& vec)
{
	for (int number : vec)
	{
		std::cout << number << " ";
	}
	std::cout << std::endl;
}
std::vector<int> filterVec(std::vector<int>& vec, bool(*filter)(int number))
{
	std::vector<int> newVec;
	for (int number : vec)
	{
		if (filter(number))
		{
			newVec.push_back(number);
		}
	}
	return newVec;
}
bool biggerThem3(int number)
{
	return number > 3;
}
bool isEven(int number)
{
	return number % 2 == 0;
}
bool negativeNumber(int number)
{
	return number < 0;
}


