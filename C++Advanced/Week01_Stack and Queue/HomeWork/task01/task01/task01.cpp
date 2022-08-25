// task01
#include <iostream>
#include <stack>
#include <string>
std::stack<int> readInput(int& popNumberOfElemets, int& targetNumber);
void removeElemetns(std::stack<int>& stackNumbers, int popNumberOfElemets);
std::string fineSolution(std::stack<int>& stackNumbers, int targetNumber);
void printSolution(std::string& answer);
int main()
{
	int popNumberOfElemets = 0;
	int targetNumber = 0;
	std::stack<int> stackNumbers = readInput(popNumberOfElemets, targetNumber);
	removeElemetns(stackNumbers, popNumberOfElemets);
	std::string answer = fineSolution(stackNumbers, targetNumber);
	printSolution(answer);

	return 0;
}
std::stack<int> readInput(int& popNumberOfElemets, int& targetNumber)
{
	std::stack<int> stackNumbers;
	int numberOfElements = 0;
	std::cin >> numberOfElements;
	std::cin >> popNumberOfElemets;
	std::cin >> targetNumber;

	int currNumber = 0;
	for (int i = 0; i < numberOfElements; i++)
	{
		std::cin >> currNumber;
		stackNumbers.push(currNumber);
	}

	return stackNumbers;
}
void removeElemetns(std::stack<int>& stackNumbers, int popNumberOfElemets)
{
	for (int i = 0; i < popNumberOfElemets; i++)
	{
		stackNumbers.pop();
	}
}
std::string fineSolution(std::stack<int>& stackNumbers, int targetNumber)
{
	if (stackNumbers.empty())
	{
		return "0";
	}
	int minNumber = stackNumbers.top();

	while (!stackNumbers.empty())
	{
		int currNumber = stackNumbers.top();
		if (currNumber == targetNumber)
		{
			return "true";
		}
		if (minNumber > currNumber)
		{
			minNumber = currNumber;
		}
		stackNumbers.pop();
	}
	return std::to_string(minNumber);
}
void printSolution(std::string& answer)
{
	std::cout << answer << std::endl;
}