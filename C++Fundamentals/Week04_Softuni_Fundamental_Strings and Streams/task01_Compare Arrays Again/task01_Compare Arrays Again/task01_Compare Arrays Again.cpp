// task01,Напишете програма, която чете два целочислени масива от конзолата и ги сравнява елемент по елемент.
//За по-добро код за повторна употреба, можете да направите сравнението във функция, която връща true, 
//ако те са равни и false, ако не. Всеки масив ще бъде дефиниран от един ред на конзолата, съдържащ числата
//в масива, разделени с интервали.Отпечатайте равно, ако масивите съвпадат, и не е равно, ако масивите не съвпадат.
#include <iostream>
#include <array>
#include <string>
#include <sstream>
const int size = 1000;
std::array< int, size> readArray(int& number);
bool areEqual(std::array <int, size> arr1, int lenght1, std::array <int, size> arr2, int lenght2);
int main()
{
	int lenght1 = 0;
	int lenght2 = 0;
	std::array <int, size> arr1 = readArray(lenght1);
	std::array <int, size> arr2 = readArray(lenght2);



	bool equal = areEqual(arr1, lenght1, arr2, lenght2);
	(equal) ? std::cout << "equal" << std::endl : std::cout << "not equal" << std::endl;



	return 0;
}
std::array< int, size> readArray(int& number)
{
	std::array< int, size> arr{};
	std::string line;
	getline(std::cin, line);

	std::istringstream istr(line);
	int currNumber = 0;

	while (istr >> currNumber)
	{
		arr[number] = currNumber;
		number++;
	}
	return arr;
}
bool areEqual(std::array <int, size> arr1, int lenght1, std::array <int, size> arr2, int lenght2)
{
	if (lenght1 != lenght2)
	{
		return false;

	}
	for (int i = 0; i < lenght1; i++)
	{
		if (arr1[i] != arr2[i])
		{
			return false;

		}
	}
	return true;
}