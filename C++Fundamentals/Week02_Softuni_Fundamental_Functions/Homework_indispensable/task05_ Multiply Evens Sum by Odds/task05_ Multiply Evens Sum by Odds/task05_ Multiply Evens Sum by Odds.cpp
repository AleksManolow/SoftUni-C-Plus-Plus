// task05, Създайте програма, която чете цяло число и умножава сумата на всичките си четни цифри по сумата на всичките си
//нечетни цифри :
#include <iostream>
#include <cmath>
void readNumber(int& num);
int sumEvenDigits(int num);
int sumOddDigits(int num);
int main()
{
	int number;
	readNumber(number);
	number = std::abs(number);

	int sumEven = sumEvenDigits(number);
	int sumOdd = sumOddDigits(number);

	int result = sumEven * sumOdd;

	std::cout << result << std::endl;
	return 0;
}
void readNumber(int& num)
{
	std::cin >> num;
}
int getDigitIndex(int num, int index)
{
	int digit = num / (int)pow(10, index) % 10;
	return digit;
}
int sumEvenDigits(int num)
{
	int sumDigits = 0;
	int counter = 0;
	while (getDigitIndex(num,counter))
	{
		int digit = getDigitIndex(num, counter);
		if ( digit % 2 == 0)
		{
			sumDigits = sumDigits + digit;
		}
		counter++;
	}
	return sumDigits;
}
int sumOddDigits(int num)
{
	int sumDigits = 0;
	int counter = 0;
	while (getDigitIndex(num, counter))
	{
		int digit = getDigitIndex(num, counter);
		if (digit % 2 == 1)
		{
			sumDigits = sumDigits + digit;
		}
		counter++;
	}
	return sumDigits;
}

//#include <iostream>
//
//int main()
//{
//	int n;
//	int oddSum = 0;
//	int evenSum = 0;
//
//	std::cin >> n;   //input number
//	n = std::abs(n); //ignore sign
//
//	while (n > 0)
//	{
//		int digit = n % 10;
//		(digit % 2 == 0) ? evenSum += digit : oddSum += digit;
//		n = n / 10;
//	}
//
//	int result = oddSum * evenSum;
//	std::cout << result;
//}
