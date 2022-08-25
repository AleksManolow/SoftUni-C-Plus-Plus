// task02, �������� ��������, ����� �������� ��� ���� ����� � ���� �� �������� ������ ���������� (���� �������� ������):
//+, -, *, / �� ��������� ���.���������� �� ����� ������ : +� ��������, -� ���������, * � ��������� � / �
//����������.�������� ������ �������(�� ����� ��������) � ��������� ���������� � ���������� �� ���������.
#include <iostream>
void readNumberAndOperation(int& firstNumber, int& secoundNumber, char& operation);
double additionOperation(int firstNumber, int secoudNumber);
double subtractionOperation(int firstNumber, int secoudNumber);
double multiplicationOperation(int firstNumber, int secoudNumber);
double divisionOperation(int firstNumber, int secoudNumber);
int main()
{
	int firstNumber = 0;
	int secoundNumber = 0;
	char operation;

	readNumberAndOperation(firstNumber, secoundNumber, operation);

	if (operation == '+')
	{
		std::cout << additionOperation(firstNumber, secoundNumber) << std::endl;
	}
	else if (operation == '-')
	{
		std::cout << subtractionOperation(firstNumber, secoundNumber) << std::endl;
	}
	else if (operation == '*')
	{
		std::cout << multiplicationOperation(firstNumber, secoundNumber) << std::endl;
	}
	else if (operation == '/')
	{
		if (secoundNumber == 0)
		{
			std::cout << "Can't divide by zero." << std::endl;
		}
		else
		{
			std::cout << divisionOperation(firstNumber, secoundNumber) << std::endl;
		}
		
	}

	return 0;
	
}
void readNumberAndOperation(int& firstNumber, int& secoundNumber, char& operation)
{
	std::cin >> firstNumber >> secoundNumber >> operation;
}
double additionOperation(int firstNumber, int secoudNumber)
{
	return firstNumber + secoudNumber;
}
double subtractionOperation(int firstNumber, int secoudNumber)
{
	return firstNumber - secoudNumber;
}
double multiplicationOperation(int firstNumber, int secoudNumber)
{
	return firstNumber * secoudNumber;
}
double divisionOperation(int firstNumber, int secoudNumber)
{
	
	return firstNumber / secoudNumber;
}
