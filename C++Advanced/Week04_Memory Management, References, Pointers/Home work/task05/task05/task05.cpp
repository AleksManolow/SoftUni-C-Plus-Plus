// task05
#include <iostream>
#include <string>
std::string readInput(int& size);
void theLowercaseCharacterString(std::string line, int size, char*& lowercaseLetters);
void theUppercaseCharacterString(std::string line, int size, char*& uppercaseLetters);
void printSolution(char* charSting, int size);
void releaseMemory(char*& arr);
int main()
{
	int size = 0;
	std::string line = readInput(size);
	char* lowercaseLetters = nullptr;
	char* uppercaseLetters = nullptr;

	theLowercaseCharacterString(line, size, lowercaseLetters);
	theUppercaseCharacterString(line, size, uppercaseLetters);

	printSolution(lowercaseLetters, size);
	printSolution(uppercaseLetters, size);

	releaseMemory(lowercaseLetters);
	releaseMemory(uppercaseLetters);

	return 0;
}
std::string readInput(int& size)
{
	std::string line;
	getline(std::cin, line);
	size = line.size();

	return line;
}
void theLowercaseCharacterString(std::string line, int size, char*& lowercaseLetters)
{
	lowercaseLetters = new char[size] {};
	for (size_t i = 0; i < size; i++)
	{
		lowercaseLetters[i] = tolower(line[i]);
	}
}
void theUppercaseCharacterString(std::string line, int size, char*& uppercaseLetters)
{
	uppercaseLetters = new char[size] {};
	for (size_t i = 0; i < size; i++)
	{
		uppercaseLetters[i] = toupper(line[i]);
	}
}
void printSolution(char* charSting, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << charSting[i];
	}
	std::cout << std::endl;
}
void releaseMemory(char*& arr)
{
	delete[] arr;
	arr = nullptr;
}
