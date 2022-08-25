// task03
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include<cctype>
std::vector<std::string> readInput();
bool isDigitFunction(std::string& temp);
std::vector<int> answerThoAll(std::vector<std::string>& line);
void printResult(std::vector<int>& digit);
int main()
{
	std::vector<std::string>line = readInput();

	std::vector<int> digit = answerThoAll(line);

	printResult(digit);

	return 0;
}
std::vector<std::string> readInput()
{
	std::string input;
	std::cin >> input;

	std::vector<std::string> vec{};

	while (input != "end")
	{
		vec.push_back(input);
		getline(std::cin, input);
	}
	return vec;
}
bool isDigitFunction(std::string& temp)
{
	for (size_t i = 0; i < temp.size(); i++)
	{
		if (isdigit(temp[i]))
		{
			return true;
		}
	}
	return false;
}
std::vector<int> answerThoAll(std::vector<std::string>& line)
{
	std::vector<int> digitVec;

	for (size_t i = 0; i < line.size(); i++)
	{
		std::string temp = line[i];
		bool isDigit = isDigitFunction(temp);
		if (isDigit)
		{
			int digit = 0;
			if (temp[0] == '-')
			{
				for (size_t i = 1; i < temp.size(); i++)
				{
					digit = digit * 10;
					digit = digit + (temp[i] - '0');
				}
				digit = 0 - digit;
			}
			else
			{
				for (size_t i = 0; i < temp.size(); i++)
				{
					digit = digit * 10;
					digit = digit + (temp[i] - '0');
				}
			}
			digitVec.push_back(digit);
		}
		else if (line[i] == "sum")
		{
			int tempSizeNumVec = digitVec.size();
			int sum = digitVec[tempSizeNumVec - 1] + digitVec[tempSizeNumVec - 2];
			digitVec.pop_back();
			digitVec.pop_back();
			digitVec.push_back(sum);
		}
		else if (line[i] == "subtract")
		{
			int tempSizeNumVec = digitVec.size();
			int sum = digitVec[tempSizeNumVec - 1] - digitVec[tempSizeNumVec - 2];
			digitVec.pop_back();
			digitVec.pop_back();
			digitVec.push_back(sum);
		}
		else if (line[i] == "concat")
		{
			int tempSizeNumVec = digitVec.size();
			int unioOfNumbers = digitVec[tempSizeNumVec - 2] * 10;
			unioOfNumbers = unioOfNumbers + digitVec[tempSizeNumVec - 1];
			digitVec.pop_back();
			digitVec.pop_back();
			digitVec.push_back(unioOfNumbers);
		}
		else if (line[i] == "discard")
		{
			digitVec.pop_back();
		}
	}

	return digitVec;
}
void printResult(std::vector<int>& digit)
{
	for (size_t i = 0; i < digit.size(); i++)
	{
		std::cout << digit[i] << std::endl;
	}
}
