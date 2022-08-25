// task01, Напишете програма, която чете два масива от цели числа и ги сравнява елемент по елемент. За по-добър код
//многократна употреба, можете да направите сравнението в a
//bool areEqual(int arr1[], int length1, int arr2[], int lenght2) функция, която връща TRUE
//ако са равни и FALSE, ако не.Всеки масив ще бъде дефиниран от два реда на конзолата - първият съдържащ a
//число, представляващо дължината на масива, а второто, съдържащо числата в масива.
//Отпечатайте равно, ако масивите съвпадат, и не е равно, ако масивите не съвпадат
#include <iostream>
const int size = 1000;
void input(int array[], int& n);
bool areEqual(int arr1[], int lenght1, int arr2[], int lenght2);
int main()
{
	int array1[size], array2[size];

	int lenght1, lenght2;

	input(array1, lenght1);
	input(array2, lenght2);


	bool equal = areEqual(array1, lenght1, array2, lenght2);

	(equal) ? std::cout << "equal" << std::endl : std::cout << "not equal" << std::endl;




	return 0;

}
void input(int array[], int& n)
{
	do
	{
		std::cin >> n;
	} while (n < 1 || n > 100);

	for (int i = 0; i < n; i++)
	{
		std::cin >> array[i];
	}
}
bool areEqual(int arr1[], int lenght1, int arr2[], int lenght2)
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

