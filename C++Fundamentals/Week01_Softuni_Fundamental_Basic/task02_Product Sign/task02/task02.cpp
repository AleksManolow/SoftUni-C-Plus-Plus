#include <iostream>
int main()
{
	double firstNum, secountdNum, thirdNum;
	std::cin >> firstNum >> secountdNum >> thirdNum;

	double multiplication = firstNum * secountdNum * thirdNum;

	if (multiplication >= 0)
	{
		std::cout << "+" << std::endl;
	}
	else
	{
		std::cout << "-" << std::endl;
	}

	

	return 0;
}

