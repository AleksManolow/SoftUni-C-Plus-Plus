// task03, �������� ��������, ����� ���� ����� �� ���� ����� �� ��������� � ��������� ������ �����, ����� �� ��-������
//�� - ����� ��� ����� �� ��������������� ������ �������� �� ������� � ������.������� ������ �� ���� ��������� �� ���� ���
//,���������� �������� ����� � ���������.��������� ������ ������ �� ����� � ����� ���, ����� ���� � ����.
#include <iostream>
const int size = 1000;
void input(int array[], int& n);
int averageOfTheNumbers(int array[], int numberOfElements);
void prinLagreElementsThemAvarage(int array[], int numberOfElements);
int main()
{
	int array[size];
	int numberOfElements;

	input(array, numberOfElements);

	prinLagreElementsThemAvarage(array, numberOfElements);


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
int averageOfTheNumbers(int array[], int numberOfElements)
{
	int sum = 0;
	for (int i = 0; i < numberOfElements; i++)
	{
		sum = sum + array[i];
	}
	return sum / numberOfElements;
}
void prinLagreElementsThemAvarage(int array[], int numberOfElements)
{
	double avarageValue = averageOfTheNumbers(array, numberOfElements);

	for (int i = 0; i < numberOfElements; i++)
	{
		if (avarageValue <= array[i])
		{
			std::cout << array[i] << " ";
		}
	}
}