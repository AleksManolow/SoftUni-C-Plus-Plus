// task01
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <set>
std::vector<std::string> readText();
std::vector <char> readLetters();
bool areTherePeriodsAndCommas(std::string word);
std::set<std::string> getWordsWithBigLetters(std::vector<std::string>& text, char letter);
std::set<std::string> getWordsWithSmallLetters(std::vector<std::string>& text, char letter);
void pushInVecSolution(std::vector<std::string>& solution, int& counter,
					   std::set <std::string>& setHelp);
std::vector <std::string>solutionOfProblem(std::vector<std::string>& text,
										   std::vector <char>& letters,
										   std::vector <int>& howManyWordsContainLetter);
void printSolution(std::vector <std::string>& solution, std::vector <int>& howManyWordsContainLetter);
int main()
{
	std::vector<std::string> text = readText();
	std::vector <char> letters = readLetters();


	std::vector <int> howManyWordsContainLetter;
	std::vector<std::string> solution = solutionOfProblem(text, letters, howManyWordsContainLetter);

	printSolution(solution, howManyWordsContainLetter);
	return 0;
}
std::vector<std::string> readText()
{
	std::vector<std::string> text;

	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);

	std::string wordInText;
	while (istr >> wordInText)
	{
		text.push_back(wordInText);
	}
	return text;
}
std::vector <char> readLetters()
{
	std::vector <char> letters;
	char letter;
	std::cin >> letter;
	while (letter != '.')
	{
		letters.push_back(letter);
		std::cin >> letter;
	}
	return letters;
}
bool areTherePeriodsAndCommas(std::string word)
{
	for (char a : word)
	{
		if (a == '.' || a == ',')
		{
			return true;
		}
	}
	return false;
}
std::set<std::string> getWordsWithBigLetters(std::vector<std::string>& text, char letter)
{
	std::set <std::string> bigLetter;
	for (std::string word : text)
	{
		if (isupper(word[0]))
		{
			if (areTherePeriodsAndCommas(word))
			{
				word.pop_back();
			}
			for (char letterInWord : word)
			{
				if (letterInWord == letter || letterInWord == toupper(letter))
				{
					bigLetter.insert(word);
				}
			}
		}
	}
	return bigLetter;
}
std::set<std::string> getWordsWithSmallLetters(std::vector<std::string>& text, char letter)
{
	std::set<std::string> smallLetter;
	for (std::string word : text)
	{
		if (!isupper(word[0]))
		{
			if (areTherePeriodsAndCommas(word))
			{
				word.pop_back();
			}
			for (char letterInWord : word)
			{
				if (letterInWord == letter || letterInWord == tolower(letter))
				{
					smallLetter.insert(word);
				}
			}
		}
	}
	return smallLetter;
}
void pushInVecSolution(std::vector<std::string>& solution, int& counter,
					   std::set <std::string>& setHelp)
{
	for (std::string word : setHelp)
	{
		solution.push_back(word);
		solution.push_back(" ");
		counter = counter + 2;
	}
}
std::vector <std::string>solutionOfProblem(std::vector<std::string>& text,
										   std::vector <char>& letters,
										   std::vector <int>& howManyWordsContainLetter)
{
	std::vector<std::string> solution;
	std::set <std::string> bigLetter;
	std::set<std::string> smallLetter;
	int counter = 0;
	for (char letter : letters)
	{
		bigLetter = getWordsWithBigLetters(text, letter);
		smallLetter = getWordsWithSmallLetters(text, letter);
		if (bigLetter.empty() && smallLetter.empty())
		{
			solution.push_back("---");
			solution.push_back(" ");
			counter += 2;
		}
		else
		{
			pushInVecSolution(solution, counter, bigLetter);
			pushInVecSolution(solution, counter, smallLetter);
		}
		howManyWordsContainLetter.push_back(counter);
		counter = 0;
	}
	return solution;
}
void printSolution(std::vector <std::string>& solution, std::vector <int>& howManyWordsContainLetter)
{
	for (int i = 0; i < (howManyWordsContainLetter.size() - 1); i++)
	{
		howManyWordsContainLetter[i + 1] = howManyWordsContainLetter[i] + howManyWordsContainLetter[i + 1];
	}
	int counter = 0;
	for (int i = 0; i < solution.size(); i++)
	{
		std::cout << solution[i];
		i++;
		if (i == (howManyWordsContainLetter[counter] - 1))
		{
			std::cout << std::endl;
			counter++;
		}
		else
		{
			std::cout << solution[i];
		}
	}
}