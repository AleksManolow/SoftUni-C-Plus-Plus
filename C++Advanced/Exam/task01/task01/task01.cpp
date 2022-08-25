// task01
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
std::vector<std::string> readInput(int& maxSimbols);
std::vector<std::string> solutionOfProblem(std::vector<std::string>& text, int maxSimbols);
int main()
{
	int maxSimbols = 0;
	std::vector<std::string> text = readInput(maxSimbols);
	std::vector<std::string> solution = solutionOfProblem(text, maxSimbols);
	
	for (std::string line : solution)
	{
		std::cout << line << std::endl;
	}
	return 0;
}
std::vector<std::string> readInput(int& maxSimbols)
{
	std::vector<std::string> text;
	std::string line;

	while (true)
	{
		if (line == "###")
		{
			break;
		}
		text.push_back(line);
		getline(std::cin, line);

	}

	std::cin >> maxSimbols;

	return text;
}
std::vector<std::string> solutionOfProblem(std::vector<std::string>& text, int maxSimbols)
{
	std::vector<std::string> solutio;
	int sumOfElOnLine = 0;
	std::string newline;
	std::string word;
	for (std::string line : text)
	{
			std::istringstream istr(line);

			while (istr >> word)
			{
				int sizeOnWord = word.size();
				if (sizeOnWord > maxSimbols)
				{
					if (newline.size() > 0)
					{
						solutio.push_back(newline);
						newline.erase();
					}
					solutio.push_back(word);
					sumOfElOnLine = 0;
					continue;
				}
				sumOfElOnLine = sumOfElOnLine + (sizeOnWord + 1);
				if (sumOfElOnLine >= maxSimbols)
				{
					newline.append(word).append(" ");
					solutio.push_back(newline);
					newline.erase();
					sumOfElOnLine = 0;
				}
				newline.append(word).append(" ");
			}			
	}
	solutio.push_back(newline);
	return solutio;
}