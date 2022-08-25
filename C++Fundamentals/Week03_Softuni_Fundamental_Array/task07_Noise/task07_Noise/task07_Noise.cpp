// task07, Напишете програма, която чете положително цяло число и връща квадратния си корен (отпечатайте резултата като 
//отпечатъци от cout двойни числа)
//Номерът ще бъде въведен с "шум" в него, т.е.ще има символи, които не са цифри.Тези символи трябва да бъдат
//игнорирани.Последният символ на въведеното число винаги ще бъде. (точка)и няма да има друга. (точка)в
//номер.
#include <iostream>
#include <cmath>
const int size = 1000;
void input(char array[], int& n);
bool isDigit(int c);
void appendDigitToNumber(int digit, int& number);
int returnNumber(char array[], int n);
int main()
{
	char array[size];
	int numberOfElements;

	input(array, numberOfElements);
	std::cout << sqrt(returnNumber(array, numberOfElements)) << std::endl;

	
	return 0;
}
void input(char array[],int& n)
{
	n = -1;
	do
	{
		n++;
		std::cin >> array[n];
		
	} while (array[n] != '.');

}
bool isDigit(int c)
{
	switch (c)
	{
	case 0:
		return true;
		break;
	case 1:
		return true;
		break;
	case 2:
		return true;
		break;
	case 3:
		return true;
		break;
	case 4:
		return true;
		break;
	case 5:
		return true;
		break;
	case 6:
		return true;
		break;
	case 7:
		return true;
		break;
	case 8:
		return true;
		break;
	case 9:
		return true;
		break;
	default:
		return false;
	}

}
void appendDigitToNumber(int digit, int& number)
{
	number = number * 10;
	number = number + digit;
}
int returnNumber(char array[], int n)
{
	int number = 0;
	for (int i = 0; i < n; i++)
	{
		int digit = int(array[i] - '0');
		if (isDigit(digit))
		{
			appendDigitToNumber(digit, number);
		}
	}
	return number;
}



