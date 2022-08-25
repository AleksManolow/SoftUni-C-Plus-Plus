// task02
#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
std::string readText();
std::vector<std::string> readOperations();
void solutionOfTheProblem(std::string text, std::vector<std::string>& operations);
int main()
{
	std::string text = readText();
	std::vector<std::string> operations = readOperations();

	solutionOfTheProblem(text, operations);

	return 0;
}
std::string readText()
{
	std::string text;
	getline(std::cin, text);

	return text;
}
std::vector<std::string> readOperations()
{
	std::vector<std::string> operations;
	std::string line;

	while (true)
	{
		getline(std::cin, line);
		if (line == "end")
		{
			break;
		}
		operations.push_back(line);
	}
	return operations;
}
std::queue<int> wordLengthIndicesInTheText(std::string text)// Indeksa na zapochwane i zawurshwane na duma
{
	std::queue<int> indexWord;
	indexWord.push(0);
	for (size_t i = 0; i < text.size(); i++)
	{
		if (text[i] == ' ')
		{
			indexWord.push(i - 1);
			indexWord.push(i + 1);
		}
	}
	indexWord.push(text.size() - 1);
	return indexWord;
}
void copyFunction(std::string& modificationText, int numberAfterWord1, int numberAfterWord2,
	std::queue<int> indexWord)
{
	std::string modificationTextForCopy;
	if (numberAfterWord2 >= modificationText.size() - 1)// Proweka za koqto ako ne po golqm indeksa ot razmera da wzima do kraq string
	{
		numberAfterWord2 = (modificationText.size() - 1);
	}

	while (!indexWord.empty())
	{
		int firstIndex = indexWord.front();
		indexWord.pop();
		int secoundIndex = indexWord.front();
		indexWord.pop();
		if (firstIndex <= numberAfterWord1 && numberAfterWord2 <= secoundIndex)
		{
			std::string sub = modificationText.substr(firstIndex, secoundIndex + 1);
			modificationTextForCopy.append(sub);
			if (! indexWord.empty())
			{
				modificationTextForCopy.append(" ");
			}
		}
	}
	modificationText = modificationTextForCopy;
}
void pasteFunction(std::string text, int numberAfterWord1, std::string& modificationText)
{
	std::string modificationTextForPaste;
	if (modificationText[numberAfterWord1] == ' ')
	{
		modificationTextForPaste.append(modificationText.substr(0, numberAfterWord1 + 1));
		modificationTextForPaste.append(text);
		modificationTextForPaste.append(modificationText.substr(numberAfterWord1, 
			(modificationText.size() - numberAfterWord1)));
	}
	else
	{
		modificationTextForPaste.append(modificationText.substr(0, numberAfterWord1));
		modificationTextForPaste.append(text);
		modificationTextForPaste.append(modificationText.substr(numberAfterWord1-1,
			(modificationText.size() - numberAfterWord1)));
	}
	modificationText =  modificationTextForPaste;
}
void solutionOfTheProblem(std::string text, std::vector<std::string>& operations)
{
	std::string wordOperation;
	int numberAfterWord1 = 0;
	int numberAfterWord2 = 0;
	std::string modificationText = text;
	for (std::string operation : operations)
	{
		std::istringstream istr(operation);
		istr >> wordOperation;

		if (wordOperation == "copy")
		{
			istr >> numberAfterWord1;
			istr >> numberAfterWord2;
			std::queue<int> indexWord = wordLengthIndicesInTheText(modificationText);
			
			copyFunction(modificationText, numberAfterWord1, numberAfterWord2,
				indexWord);
			std::cout << modificationText << std::endl;
		}
		/*else if (wordOperation == "paste")
		{
			istr >> numberAfterWord1;
			pasteFunction(text, numberAfterWord1, modificationText);
		}*/
	}
}