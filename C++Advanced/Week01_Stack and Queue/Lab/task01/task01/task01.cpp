// task01
#include <iostream>
#include<stack>
#include <vector>
#include <sstream>
#include <string>
std::vector <std::string> readInput();
void printReversed(std::vector <std::string> words);
int main() 
{
	std::vector<std::string> words = readInput();
	printReversed(words);

	return 0;
}
std::vector <std::string> readInput()
{
	std::vector <std::string> words;
	std::string input;
	getline(std::cin, input);
	std::istringstream istr(input);

	std::string word;
	while(istr >> word)
	{
		words.push_back(word);
	}

	return words;
}
void printReversed(std::vector <std::string> words)
{
	std::stack <std::string> reversedWords;

	for (const std::string& word : words)
	{
		reversedWords.push(word);
	}

	while (!reversedWords.empty())
	{
		std::cout << reversedWords.top() << ' ';
		reversedWords.pop();
	}
}
