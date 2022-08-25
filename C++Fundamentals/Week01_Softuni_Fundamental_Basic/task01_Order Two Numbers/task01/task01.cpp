#include <iostream>
int main()
{
	int number1, number2;
	std::cin >> number1 >> number2;

	if (number1 > number2)
	{
		std::cout << number2 <<" "<< number1 << std::endl;
	}
	else
	{
		std::cout << number1 <<" "<< number2 << std::endl;
	}
	return 0;
}	
