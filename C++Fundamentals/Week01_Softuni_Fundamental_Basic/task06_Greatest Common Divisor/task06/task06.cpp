#include <iostream>
int main()
{
	int firstNumber, secoundNumber;
	std::cin >> firstNumber >> secoundNumber;

	while (secoundNumber != 0)
	{
		int helpVariable;
		helpVariable = secoundNumber;
		secoundNumber = firstNumber % secoundNumber;
		firstNumber = helpVariable;
	}
	std::cout << firstNumber << std::endl;
	return 0;
}