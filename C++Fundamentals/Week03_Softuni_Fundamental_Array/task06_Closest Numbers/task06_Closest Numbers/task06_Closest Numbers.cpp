// task06, Напишете програма, която намира двете най-близки (по стойност) цели числа в масив и отпечатва абсолютната стойност
//разлика между тях.
#include <iostream>
#include <cmath>
const int size = 1000;
void input(int array[], int& n);
int findsTwoClosestByValue(int array[], int n);

int main()
{
	int array[size];
	int numberOfElemets;
	input(array, numberOfElemets);
	std::cout << findsTwoClosestByValue(array, numberOfElemets) << std::endl;
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
int findsTwoClosestByValue(int array[], int n)
{
	int valueBetweenTwoNumbers = 0;
	int theSmallestValueBetweenTwoNumbers = abs(array[1] - array[2]);

	int theSmallestValue = abs(array[1] - array[2]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				valueBetweenTwoNumbers = abs(array[i] - array[j]);
				if (valueBetweenTwoNumbers < theSmallestValueBetweenTwoNumbers)
				{
					theSmallestValueBetweenTwoNumbers = valueBetweenTwoNumbers;
				}
			}
			
		}
		if (theSmallestValueBetweenTwoNumbers < theSmallestValue )
		{
			theSmallestValue = theSmallestValueBetweenTwoNumbers;
		}
	}
	return theSmallestValue;
}