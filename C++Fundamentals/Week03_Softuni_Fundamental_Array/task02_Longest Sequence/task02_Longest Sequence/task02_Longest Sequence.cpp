// task02, �������� ��������, ����� ������ ���-������� ���������������� �� ����� �������� � ���������� ����� � ���� ���� ��������� ���� ����������������
//�� ���������(���� �����, ��������� � �������� �� ���� ���).��� ��� ������ �� ���� ������ ����������������, �����������
//����������.�������� ����� �� ���� ������� �� ��� ���� - ���������� �� ������� ���� �����, �������������� ���� �� ����������,
//������� �� ������� ����������, ��������� � ������������.
#include <iostream>
const int size = 1000;
void input(int array[], int& n);
void longestSequenceOfEqualElements(int array[], int n, int& equalElemen, int& numberOfEqualElemen);
void printEqualElements(int equalElemen, int numberOfEqualElemen);
int main()
{
	int array[size];
	int numberOfElements;

	input(array, numberOfElements);
	
	int equalElemen, numberOfEqualElemen;

	longestSequenceOfEqualElements(array, numberOfElements, equalElemen, numberOfEqualElemen);

	printEqualElements(equalElemen, numberOfEqualElemen);

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
void longestSequenceOfEqualElements(int array[], int n, int& equalElemen, int& numberOfEqualElemen)
{
	numberOfEqualElemen = 1;
	equalElemen = array [0];
	int counter = 1;
	for (int i = 0; i < n ; i++)
	{
		if (array[i] == array[i + 1])
		{
			counter++;
		}
		else
		{
			counter = 1;
		}
		if (counter >= numberOfEqualElemen )
		{
			numberOfEqualElemen = counter;
			equalElemen = array[i];
		}

	}
}
void printEqualElements(int equalElemen, int numberOfEqualElemen)
{
	for (int i = 0; i < numberOfEqualElemen; i++)
	{
		std::cout << equalElemen << " ";
	}
}
