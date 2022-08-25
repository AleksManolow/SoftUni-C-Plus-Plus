// task03
#include<iostream>
#include <vector>
#include<stack>
#include<sstream>
#include <string>
const int ADD = 1;
const int REMOVE = 2;
const int MAX = 3;
const int MIN = 4;

std::vector<std::string> readInput();
void addElement(std::stack<int>& stackNumbers, int numberToAdd);
void removeElement(std::stack<int>& stackNumbers);
void maxNumberElements(std::stack<int>& stackNumbers);
void minNumberElements(std::stack<int>& stackNumbers);
void processInput(std::vector<std::string>& commands, std::stack<int>& stackNumbers);
void printSolution(std::stack<int>& stackNumbers);
int main()
{
	std::vector<std::string> commands = readInput();
	std::stack<int> stackNumbers;
	processInput(commands, stackNumbers);
	printSolution(stackNumbers);

	return 0;
}
std::vector<std::string> readInput()
{
	int commandsSize = 0;
	std::cin >> commandsSize;
	std::cin.ignore();
	std::vector<std::string> commands(commandsSize);

	for (std::string& command : commands)
	{
		getline(std::cin, command);
	}
	return commands;
}
void addElement(std::stack<int>& stackNumbers, int numberToAdd)
{
	stackNumbers.push(numberToAdd);
}
void removeElement(std::stack<int>& stackNumbers)
{
	if (!stackNumbers.empty())
	{
		stackNumbers.pop();
	}
}
void maxNumberElements(std::stack<int>& stackNumbers)
{
	if (stackNumbers.empty())
	{
		return;
	}
	std::stack<int> stackNumbersCopy = stackNumbers;
	int maxNumber = stackNumbersCopy.top();
	
	while (!stackNumbersCopy.empty())
	{
		int currNumber = stackNumbersCopy.top();
		if (maxNumber < currNumber)
		{
			maxNumber = currNumber;
		}
		stackNumbersCopy.pop();
	}
	std::cout << maxNumber << std::endl;
}
void minNumberElements(std::stack<int>& stackNumbers)
{
	if (stackNumbers.empty())
	{
		return;
	}
	std::stack<int> stackNumbersCopy = stackNumbers;
	int minNumber = stackNumbersCopy.top();

	while (!stackNumbersCopy.empty())
	{
		int currNumber = stackNumbersCopy.top();
		if (minNumber > currNumber)
		{
			minNumber = currNumber;
		}
		stackNumbersCopy.pop();
	}
	std::cout << minNumber << std::endl;
}
void processInput(std::vector<std::string>& commands, std::stack<int>& stackNumbers)
{
	int currNumber = 0;
	for (std::string command : commands)
	{
		std::istringstream istr(command);
		istr >> currNumber;

		switch (currNumber)
		{
		case ADD:
		{
			int numberToAdd = 0;
			istr >> numberToAdd;
			addElement(stackNumbers, numberToAdd);
			break;
		}
		case REMOVE:
		{
			removeElement(stackNumbers);
			break;
		}
		case MAX:
		{
			maxNumberElements(stackNumbers);
			break;
		}
		case MIN:
		{
			minNumberElements(stackNumbers);
			break;
		}
		default:
			break;
		}
	}
}
void printSolution(std::stack<int>& stackNumbers)
{
	std::string answer;
	while (!stackNumbers.empty())
	{
		answer.append(std::to_string(stackNumbers.top()).append(", "));
		stackNumbers.pop();
	}
	answer.pop_back();
	answer.pop_back();
	std::cout << answer << std::endl;
}