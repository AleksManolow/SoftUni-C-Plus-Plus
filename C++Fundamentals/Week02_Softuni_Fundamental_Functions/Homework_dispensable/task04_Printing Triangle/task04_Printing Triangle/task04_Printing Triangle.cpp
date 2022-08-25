// task04, Създайте функция за отпечатване на триъгълници, както е показано по-долу:
//1
//1 2
//1 2 3
//1 2
//1
#include <iostream>
void printingTriangle(int n);
int main()
{
	int number;
	std::cin >> number;

	printingTriangle(number);

	return 0;

}
void printingTriangle(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			std::cout << j << " ";

		}
		std::cout << std::endl;

	}
	for (int i = n - 1 ; i >= 1; i--)
	{
		for (int j = 1 ; j <= i ; j++)
		{
			std::cout << j << " ";
		}
		std::cout << std::endl;

	}
}
