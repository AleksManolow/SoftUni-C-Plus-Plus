// task05, Напишете програма, която чете ред, съдържащ цели числа, разделени с интервали, и отпечатва тяхната сума.
//Във допълнение към числата, всеки ред ще съдържа една или повече думи(поредици от английски букви) - отпечатайте
//тези думи на отделен ред, разделен с интервали, след сумата, в реда, в който са били въведени.
#include <iostream>
#include <string>
#include <cctype>
std::string readInput();
void findSumOfNumbers(std::string& input);
void findWordsInSentence(std::string& input);
int main()
{
	std::string line = readInput();
	findSumOfNumbers(line);
	findWordsInSentence(line);
	return 0;
}
std::string readInput()
{
	std::string line;
	getline(std::cin, line);
	return line;
}
void findSumOfNumbers(std::string& input)
{
	int digit = 0;
	int digCounter = 1;
	int digitSum = 0;
	int maxSize = input.size();
	for (size_t i = 0; i < input.size(); i++) 
	{
		if(isdigit(input[i]))
		{
			digit = digit * 10;
			digit = digit + (input[i] - '0');
			digCounter++;
		}
		if(!isdigit(input[i]))
		{
	
			if (input[i - digCounter] == '-')
			{
				digitSum = digitSum - digit;
			}
			else
			{
				digitSum = digitSum + digit;
			}
			digit = 0;
			digCounter = 1;
		}
		
	}
	if (isdigit(input[maxSize -1]))
	{
		if (input[maxSize - digCounter] == '-')
		{
			digitSum = digitSum - digit;
			std::cout << digitSum << std::endl;
		}
		else
		{
			digitSum = digitSum + digit;
			std::cout << digitSum << std::endl;
		}
	}
	else
	{
		std::cout << digitSum << std::endl;
	}
}
void findWordsInSentence(std::string& input)
{
	std::string word;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (isalpha(input[i]))
		{
			char alpha = input[i];
			word.push_back(alpha);
		}
		else if (!isalpha(input[i]) && isalpha(input[i-1]))
		{
			std::cout << word << " ";
			word.clear();
		}
	}
	std::cout << word;
}


