// task02, Напишете програма, която чете ред от конзолата, съдържащ математически израз. Напишете bool функция
//който проверява дали скобите в израза() са поставени правилно(приемете, че всичко останало е правилно, т.е.
//не е необходимо да проверявате за правилни знаци, правилни променливи / числа и т.н.) и връща true,
//ако са верни и false, ако не са верни.Отпечатайте правилно или неправилно съответно на конзолата.
#include <iostream>
#include <string>
std::string readInput();
bool correctlyPlacedBrackets(std::string line);
int main()
{
	std::string input = readInput();
	(correctlyPlacedBrackets(input)) ? std::cout << "correct" << std::endl : std::cout << "incorrect" << std::endl;
}
std::string readInput()
{
	std::string line;
	getline(std::cin, line);
	return line;
}
bool correctlyPlacedBrackets(std::string line)
{
	int openingBracket = 0;
	int closingBracket = 0;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == '(')
		{
			openingBracket++;
		}
		else if (line[i] == ')')
		{
			closingBracket++;
		}
	}
	if (openingBracket == closingBracket)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
