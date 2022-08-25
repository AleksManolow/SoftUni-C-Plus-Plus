// task06, Напишете програма, която получава две цели числа от конзолата, след което чете едно от следващите четири
//инструкции(като единичен символ) : +, -, *, / и извършва съответната операция върху двете числа, с първата
//число като ляв операнд и второто число като десен операнд(+е добавяне, -е изваждане, *е умножение и / е деление).
//Ако потребителят въведе символ, различен от една от четирите операции, програмата трябва да отпечата опитайте отново и
//позволи на потребителя да влезе отново в операцията.
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
	std::cin >> firstNumber >> secoundNumber;

	do
	{
		std::cin >> operation;
		if (operation == '+' || operation == '-' || operation == '*' || operation == '/')
		{
			break;
		}
		std::cout << "try again" << std::endl;
	} while (true);
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

