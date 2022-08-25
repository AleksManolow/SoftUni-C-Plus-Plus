// task04, �������� ��������, ����� ������ ���-����� ��������� ����� � ������ ���������������� �� �����.
//������� �� ����� � ���������[0, 9].� ������ �� ��������� ����� � ���� � ���� ���������� �������, ����������� ������,
//���������, �� ��� - ������ �� ��� - �������, ��������� � ���������.
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

