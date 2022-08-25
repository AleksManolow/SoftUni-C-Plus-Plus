// task04, Ќапишете програма, ко€то при дадено ц€ло число в диапазона [0, 9999] отпечатва името на това число на английски. 
#include <iostream>
#include <cmath>
void printDigitName(int digit);
void printTeenDigit(int digit);
int getDigitFormIndex(int num, int index);
void printTensLeadDigit(int digit);
int main()
{	
	const int fisrtDigitInd = 0;
	const int secoundDigitInd = 1;
	const int thirdDigitInd = 2;
	const int fourthDigitInd = 3;

	int number;
	std::cin >> number;

	if (number < 10)
	{
		printDigitName(number);
	}
	else if (number < 20)
	{
		printTeenDigit(number);
	}
	else if (number < 100)
	{
		int currDigit = getDigitFormIndex(number, secoundDigitInd);
		printTensLeadDigit(currDigit);
			std::cout << ' ';
			currDigit = getDigitFormIndex(number, fisrtDigitInd);
		if ( currDigit != 0) {
			printDigitName(currDigit);
		}
	}
	else if( number < 1000)
	{
		int currDigit = getDigitFormIndex(number, thirdDigitInd);
		printDigitName(currDigit);
		std::cout << ' ' << "hundred" << ' ';
		currDigit = getDigitFormIndex(number, secoundDigitInd);

		if (currDigit != 0)
		{
			int temp = number % 100;
			if (temp > 9 && temp < 20)
			{
				printTeenDigit(temp);
			}
			else
			{
				int currDigit1 = getDigitFormIndex(number, secoundDigitInd);
				printTensLeadDigit(currDigit1);
				std::cout << ' ';
				currDigit1 = getDigitFormIndex(number, fisrtDigitInd);
				if (currDigit1 != 0)
				{
					printDigitName(currDigit1);
				}
			}
			
		}  
		else
		{
			currDigit = getDigitFormIndex(number, fisrtDigitInd);

			if (currDigit != 0) {
				printDigitName(currDigit);
			}
		}
	}

	else if (number < 10000)
	{
		int currDigit = getDigitFormIndex(number, fourthDigitInd);
		printDigitName(currDigit);
		std::cout << ' ' << "thousand" << ' ';
		currDigit = getDigitFormIndex(number, thirdDigitInd);

		if (currDigit != 0)
		{
			int currDigit1 = getDigitFormIndex(number, thirdDigitInd);
			printDigitName(currDigit1);
			std::cout << ' ' << "hundred" << ' ';
			currDigit1 = getDigitFormIndex(number, secoundDigitInd);

			if (currDigit1 != 0)
			{
				int temp = number % 100;
				if (temp > 9 && temp < 20)
				{
					printTeenDigit(temp);
				}
				else
				{
					int currDigit2 = getDigitFormIndex(number, secoundDigitInd);
					printTensLeadDigit(currDigit2);
					std::cout << ' ';
					currDigit2 = getDigitFormIndex(number, fisrtDigitInd);
					if (currDigit2 != 0)
					{
						printDigitName(currDigit2);
					}
				}
			}
			else
			{
				currDigit1 = getDigitFormIndex(number, fisrtDigitInd);

				if (currDigit1 != 0)
				{
					printDigitName(currDigit1);
				}
			}
		}
		else
		{
			currDigit = getDigitFormIndex(number, secoundDigitInd);
			if (currDigit != 0)
			{
				int temp = number % 100;
				if (temp > 9 && temp < 20)
				{
					printTeenDigit(temp);
				}
				else
				{
					int currDigit1 = getDigitFormIndex(number, secoundDigitInd);
					printTensLeadDigit(currDigit1);
					std::cout << ' ';
					currDigit1 = getDigitFormIndex(number, fisrtDigitInd);
					if (currDigit1 != 0)
					{
						printDigitName(currDigit1);
					}
				}
			}
			else
			{
				currDigit = getDigitFormIndex(number, fisrtDigitInd);
				if (currDigit != 0)
				{
					printDigitName(currDigit);
				}
			}
		}

	}

	return 0;
}
void printDigitName(int digit)
{
	switch (digit)
	{
	case 0:
		std::cout << "zero";
		break;
	case 1:
		std::cout << "one";
		break;
	case 2:
		std::cout << "two";
		break;
	case 3:
		std::cout << "three";
		break;
	case 4:
		std::cout << "four";
		break;
	case 5:
		std::cout << "five";
		break;
	case 6:
		std::cout << "six";
		break;
	case 7:
		std::cout << "seven";
		break;
	case 8:
		std::cout << "eight";
		break;
	case 9:
		std::cout << "nine";
		break;
	}
}
void printTeenDigit(int digit)
{
	switch (digit)
	{
	case 10:
		std::cout << "ten";
		break;
	case 11:
		std::cout << "eleven";
		break;
	case 12:
		std::cout << "twelve";
		break;
	case 13:
		std::cout << "thirteen";
		break;
	case 14:
		std::cout << "fourteen";
		break;
	case 15:
		std::cout << "fifteen";
		break;
	case 16:
		std::cout << "sixteen";
		break;
	case 17:
		std::cout << "seventeen";
		break;
	case 18:
		std::cout << "eighteen";
		break;
	case 19:
		std::cout << "nineteen";
		break;
	}
}
int getDigitFormIndex(int num, int index)
{
	int digit = num / (int)pow(10, index) % 10;
	return digit;
}
void printTensLeadDigit(int digit)
{
	switch (digit)
	{
	case 2:
		std::cout << "twenty";
		break;
	case 3:
		std::cout << "thirty";
		break;
	case 4:
		std::cout << "fourty";
		break;
	case 5:
		std::cout << "fifty";
		break;
	case 6:
		std::cout << "sixty";
		break;
	case 7:
		std::cout << "seventy";
		break;
	case 8:
		std::cout << "eighty";
		break;
	case 9:
		std::cout << "ninety";
		break;

	}
}
