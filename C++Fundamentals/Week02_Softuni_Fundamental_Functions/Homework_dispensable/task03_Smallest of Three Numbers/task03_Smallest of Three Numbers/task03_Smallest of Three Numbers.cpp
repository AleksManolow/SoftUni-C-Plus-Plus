// task03,Напишете функция за отпечатване на най-малкото от три цели числа. Използвайте подходящо име за функцията.
#include <iostream>
int smallestOfThreeNumbers();
int main()
{

	std::cout << smallestOfThreeNumbers() << std::endl;

	return 0;
}
int smallestOfThreeNumbers()
{
	int number;
	std::cin >> number;
	int minNumber = number;

	for (int  i = 0; i < 2; i++)
	{
		if (minNumber > number)
		{
			minNumber = number;
		}
		std::cin >> number;
	}
	if (minNumber > number)
	{
		minNumber = number;
	}

	return minNumber;
}
