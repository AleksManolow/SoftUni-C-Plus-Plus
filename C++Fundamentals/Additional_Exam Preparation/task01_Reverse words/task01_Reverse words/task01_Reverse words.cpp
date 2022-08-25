// task01, Напишете програма, която чете редове с думи, разделени с интервал, от стандартния вход 
//(докато се изпълни „крайната“ дума) обръща реда на всички дадени думи и извежда резултата към стандартния
//изход(думите трябва да са интервали разграничени).
#include <iostream>
#include <string>
std::string readInput();
void reverseWords(std::string line);
int main()
{
	std::string line = readInput();
	reverseWords(line);
	return 0;
}
std::string readInput()
{
	std::string getAllLines;
	std::string line;
	while (true)
	{
		getAllLines = getAllLines + ' ' + line;
		getline(std::cin, line);
		if (line == "end")
		{
			break;
		}
	}
	return getAllLines;
}
void reverseWords(std::string line)
{
	int counter = 0;
	std::string reverseLine;
	for (int i = (line.size() - 1); i >= 0; i--)
	{
		if (line[i] == ' ')
		{
			reverseLine = reverseLine + line.substr(i+1, counter);
			reverseLine = reverseLine + ' ';
			counter = 0;
		}
		else
		{
			counter++;
		}
	}
	std::cout << reverseLine << std::endl;
}
//#include <iostream>
//#include <string>
//std::string readInput();
//void reverseWord(std::string line);
//int main()
//{
//	std::string line = readInput();
//	reverseWord(line);
//	return 0;
//}
//std::string readInput()
//{
//	std::string line;
//	getline(std::cin, line);
//	return line;
//
//}
//void reverseWord(std::string line)
//{
//	std::string reverse;
//	for (int i = 5 ; i >= 0; i--)
//	{
//		std::cout << line[i];
//	}
//}