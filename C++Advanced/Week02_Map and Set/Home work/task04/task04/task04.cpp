// task04
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
std::vector<std::string> readInput();
void uppercase(std::vector<std::string>& words);
std::set<std::string> wordsSmallerThanFiveCharacters(std::vector<std::string>& words);
void printAnswer(std::set<std::string> wordsSmaller);
int main()
{
	std::vector <std::string> words = readInput();
	uppercase(words);
	std::set<std::string> wordsSmaller = wordsSmallerThanFiveCharacters(words);
	printAnswer(wordsSmaller);

	return 0;
}
std::vector<std::string> readInput()
{
	std::vector <std::string> words;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);

	std::string currWord;
	while (istr >> currWord)
	{
		words.push_back(currWord);
	}
	return words;
}
char toLower(char alpha)
{
	return tolower(alpha);
}
void uppercase(std::vector<std::string>& words)
{
	for (std::string& word : words)
	{
		std::transform(word.begin(), word.end(), word.begin(), toLower);
	}
}
std::set<std::string> wordsSmallerThanFiveCharacters(std::vector<std::string>& words)
{
	std::set<std::string> wordsSmaller;

	for (std::string word : words)
	{
		if (wordsSmaller.find(word) == wordsSmaller.end() && word.size() < 5)
		{
			wordsSmaller.insert(word);
		}
	}
	return wordsSmaller;
}
void printAnswer(std::set<std::string> wordsSmaller)
{
	std::vector<std::string> answerWords;
	for (std::string word:wordsSmaller)
	{
		answerWords.push_back(word);
	}

	std::ostringstream ostr;
	for (std::string word : wordsSmaller)
	{
		ostr << word << ", ";
	}
	std::string answer = ostr.str();
	answer.pop_back();
	answer.pop_back();
	std::cout << answer << std::endl;
}

