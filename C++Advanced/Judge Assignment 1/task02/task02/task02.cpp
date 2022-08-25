// task02
#include <iostream>
#include <string>
#include <vector>
#include<cctype>
#include <sstream>
std::vector<std::string> readText();
void readWordAndMinPurcent(std::string& word, double& minPurcent);
int solutionOfTheProblem(std::vector<std::string>& wordOfText,
	std::string wordForComparison,
	double minPurcent);
int main()
{
	std::vector<std::string> wordOfText = readText();
	std::string wordForComparison;
	double minPurcent = 0.0;
	readWordAndMinPurcent(wordForComparison, minPurcent);

	std::cout << solutionOfTheProblem(wordOfText, wordForComparison, minPurcent) << std::endl;

	/*for (std::string word : wordOfText)
	{
		std::cout << word << std::endl;
	}
	std::cout << wordForComparison << std::endl;
	std::cout << minPurcent << std::endl;*/

	return 0;
}
std::vector<std::string> readText()
{
	std::vector<std::string> wordOfText;

	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);

	std::string word;
	int counter = 0;
	int beginIndex = 0;
	for (int i = 0; i < line.size(); i++)
	{
		if (isalpha(line[i]))
		{
			counter++;
		}
		else
		{
			word = line.substr(beginIndex, counter);
			wordOfText.push_back(word);
			beginIndex = i + 1 ;
			counter = 0;
		}
	}
	if (counter != 0)
	{
		word = line.substr(beginIndex, counter);
		wordOfText.push_back(word);
	}
	return wordOfText;
}
void readWordAndMinPurcent(std::string& word, double& minPurcent)
{
	std::cin >> word;
	std::cin >> minPurcent;
}
bool checkPurcentToSimilar(std::string wordOfText, std::string wordForComparison, double minPurcent)
{
	int counterSimilarSimbols = 0;
	for (int i = 0; i < wordForComparison.size(); i++)
	{
		if (wordForComparison[i] == wordOfText[i])
		{
			counterSimilarSimbols++;
		}
	}
	double purcenOfSimilar = (counterSimilarSimbols * 100) / wordForComparison.size();
	if (purcenOfSimilar < minPurcent)
	{
		return false;
	}
	return true;
}
bool isSimilar(std::string wordOfText ,std::string wordForComparison, double minPurcent)
{
	if (wordOfText.size() != wordForComparison.size())
	{
		return false;
	}
	if (wordOfText[0] != wordForComparison[0])
	{
		return false;
	}
	if (!checkPurcentToSimilar(wordOfText, wordForComparison, minPurcent))
	{
		return false;
	}

	return true;
}
int solutionOfTheProblem(std::vector<std::string>& wordOfText, 
						 std::string wordForComparison,
						 double minPurcent)
{
	int numberOfIdenticalWords = 0;

	for (std::string word :wordOfText)
	{
		bool checkIsSimilar = isSimilar(word, wordForComparison, minPurcent);
		if (checkIsSimilar)
		{
			numberOfIdenticalWords++;
		}
	}

	return numberOfIdenticalWords;
}