// task02
#include <iostream>
#include <queue>
#include <string>
std::queue<int> readInput(int& popNumberOfElemets, int& targetNumber);
void removeElemetns(std::queue<int>& stackNumbers, int popNumberOfElemets);
std::string fineSolution(std::queue<int>& stackNumbers, int targetNumber);
void printSolution(std::string& answer);
int main()
{
	int popNumberOfElemets = 0;
	int targetNumber = 0;
	std::queue<int> stackNumbers = readInput(popNumberOfElemets, targetNumber);
	removeElemetns(stackNumbers, popNumberOfElemets);
	std::string answer = fineSolution(stackNumbers, targetNumber);
	printSolution(answer);

	return 0;
}
std::queue<int> readInput(int& popNumberOfElemets, int& targetNumber)
{
	std::queue<int> stackNumbers;
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
void removeElemetns(std::queue<int>& stackNumbers, int popNumberOfElemets)
{
	for (int i = 0; i < popNumberOfElemets; i++)
	{
		stackNumbers.pop();
	}
}
std::string fineSolution(std::queue<int>& stackNumbers, int targetNumber)
{
	if (stackNumbers.empty())
	{
		return "0";
	}
	int minNumber = stackNumbers.front();

	while (!stackNumbers.empty())
	{
		int currNumber = stackNumbers.front();
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
