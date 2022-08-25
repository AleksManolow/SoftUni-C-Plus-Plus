// task01, Every letter wants to be used, otherwise – in today’s day and age – it can sue the user 
//for lack of diversity in their text. That means that everyone that creates text these days needs to 
//include every letter from the English alphabet  To help them, you are tasked with writing a program, 
//which shows lowercase English letters which are NOT used in a certain string(sequence of letters) of 
//lowercase English letters, ordered alphabetically.
#include <iostream>
#include <string>
#include <array>
const int alphabetsSymbols = 26;
std::string readInput();
void markFoundLetters(std::string& line, std::array <bool, alphabetsSymbols>& foundLetters);
void printSolution(std::array <bool, alphabetsSymbols> foundLetters);
int main()
{
	std::string line = readInput();
	std::array <bool, alphabetsSymbols> foundLetters { };
	markFoundLetters(line, foundLetters);
	printSolution(foundLetters);
	return 0;
}
std::string readInput()
{
	std::string line;
	getline(std::cin, line);
	return line;
}
void printSolution(std::array <bool, alphabetsSymbols> foundLetters)
{
	for (int i = 0; i < alphabetsSymbols; i++)
	{
		if (!foundLetters[i])
		{
			std::cout << char(i + 'a');
		}
	}
}
void markFoundLetters(std::string& line, std::array <bool, alphabetsSymbols>& foundLetters)
{
	for (const char letter : line)
	{
		const int letterIdx = letter - 'a';
		foundLetters[letterIdx] = true;
	}
}

