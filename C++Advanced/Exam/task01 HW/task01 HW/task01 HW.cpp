// task01
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
std::vector<std::string> readInput(int& maxSimbolSize);
std::vector<std::string> solutionOfProblem(std::vector<std::string>& text, int maxSimbolSiz);
int main()
{
	int maxSimbolSize = 0;
	std::vector<std::string> text = readInput(maxSimbolSize);

	std::vector<std::string> newText = solutionOfProblem(text, maxSimbolSize);

	for (std::string line : newText)
	{
		std::cout << line << std::endl;
	}


	return 0;
}
std::vector<std::string> readInput(int& maxSimbolSize)
{
	std::vector<std::string> text;
	std::string line;

	while (true)
	{
		getline(std::cin, line);
		if (line == "###")
		{
			break;
		}
		text.push_back(line);
	}
	std::cin >> maxSimbolSize;

	return text;
}
std::vector<std::string> solutionOfProblem(std::vector<std::string>& text, int maxSimbolSiz)
{
	std::string lastLine;
	std::string temp;
	std::string word;
	int wordSize = 0;
	int sumSimbols = 0;
	std::vector<std::string> newText;
	for (std::string line : text)
	{
		std::istringstream istr(line);
		while (istr >> word)
		{
			wordSize = word.size();
			if (wordSize > maxSimbolSiz)
			{
				if (sumSimbols != 0)
				{
					newText.push_back(temp);
					temp.erase();
					sumSimbols = 0;

				}
				newText.push_back(word);
				continue;
			}

			temp.append(word).append(" ");
			sumSimbols = sumSimbols + (wordSize + 1);

			if ((sumSimbols - 1) == maxSimbolSiz)
			{
				newText.push_back(temp);
				temp.erase();
				sumSimbols = 0;
			}
			if ((sumSimbols-1) > maxSimbolSiz)
			{
				newText.push_back(lastLine);
				temp.erase();
				temp.append(word).append(" ");
				sumSimbols = (wordSize + 1);
			}
			lastLine = temp;
		}
	}
	newText.push_back(temp);
	return newText;
}