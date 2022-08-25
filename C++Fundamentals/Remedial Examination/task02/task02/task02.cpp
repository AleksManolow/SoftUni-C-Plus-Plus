// task02
#include <iostream>
#include <string>
#include <cctype>
std::string readInput();
int digitSumInString(std::string& line);
int main()
{
	std::string line = readInput();
	int digitSum = digitSumInString(line);
	if (isalpha((char)digitSum))
	{
		std::cout << (char)digitSum;
	}
	else
	{
		std::cout << digitSum;
	}
	return 0;
}
std::string readInput()
{
	std::string line;
	getline(std::cin, line);
	return line;
}
int digitSumInString(std::string& line)
{
	int sumDigit = 0;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (isdigit(line[i]))
		{
			sumDigit = sumDigit + (int)(line[i] - '0');
		}
	}
	return sumDigit;
}