// task05, Напишете програма, която чете масив от конзолата и отпечатва продукта на всеки от неговите елементи с всички
//елементи.Напр.за масива{ 1, 7, 3 } резултатът ще бъде
//{ 1 * 1, 1 * 7, 1 * 3, 7 * 1, 7 * 7, 7 * 3, 3 * 1, 3 * 7, 3 * 3 },
//което ни дава масива
//{ 1, 7, 3, 7, 49, 21, 3, 21, 9 },
//така че за входа
//1 7 3
//програмата трябва да отпечата
//1 7 3 7 49 21 3 21 9
#include <iostream>
const int size = 1000; 
void input(int array[], int& n);
void  productOfEachElements(int array[], int n);
int main()
{
	int array[size];
	int numberOfElements;

	input(array, numberOfElements);
	productOfEachElements(array, numberOfElements);

	return 0;
}
void input(int array[], int& n)
{
	do
	{
		std::cin >> n;
	} while (n < 1 || n > 1000);

	for (int i = 0; i < n; i++)
	{
		std::cin >> array[i];
	}
}
void  productOfEachElements(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << array[i] * array[j] << " ";
				 
		}
	}
}