// task04, Напишете програма, която намира най-често срещаното число в дадена последователност от числа.
//Числата ще бъдат в диапазона[0, 9].В случай на множество числа с една и съща максимална честота, отпечатайте всички,
//подредени, от най - малкия до най - големия, разделени с интервали.
#include <iostream>
const int size = 1000;
void input(int array[], int& n);
int checkForNumberOfMostCommonNumber(int array[], int n);
void checkOfTheMostcoummonDigit(int array[], int n);
int main()
{
	int array[1000];
	int numberOfElements;

	input(array, numberOfElements);
	checkOfTheMostcoummonDigit(array, numberOfElements);

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
int checkForNumberOfMostCommonNumber(int array[], int n)
{
	int numberEncounteredNumber = 1;
	int numberOfMostCommonNumber = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (array[i] == array[j])
				{
					numberEncounteredNumber++;
				}
			}
		}
		if (numberEncounteredNumber > numberOfMostCommonNumber)
		{
			numberOfMostCommonNumber = numberEncounteredNumber;
		}
		numberEncounteredNumber = 1;
		
	}
	return numberOfMostCommonNumber;
}
void checkOfTheMostcoummonDigit(int array[], int n)
{
	int counter = 0;
	int maxCounter = checkForNumberOfMostCommonNumber(array, n);
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == array[j])
			{
				counter++;
			}
		}
		if (counter == maxCounter)
		{
			std::cout << i << ' ';
		}
		counter = 0;
	}
}

