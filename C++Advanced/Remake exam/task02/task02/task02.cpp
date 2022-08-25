// task02
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
std::vector<int> readSeparators();
std::vector<int> readMessage();
std::vector<int> readSearchValue();
std::vector<int> findingIntervals(std::vector<int>& separators, std::vector<int>& message);
std::queue<int> solutionOfProblem(std::vector<int>& message,
	std::vector<int>& searchValue, std::vector<int> intervals);
int main()
{
	std::vector<int> separators = readSeparators();
	std::vector<int> message = readMessage();
	std::vector<int> searchValue = readSearchValue();

	std::vector<int> intervals = findingIntervals(separators, message);

	std::queue<int> intervalsContainingValue = solutionOfProblem(message, searchValue, intervals);

	while (!intervalsContainingValue.empty())
	{
		std::cout << intervalsContainingValue.front() << std::endl;
		intervalsContainingValue.pop();
	}

	return 0;
}
std::vector<int> readSeparators()
{
	std::vector<int> separators;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);

	int currNumber;
	while (istr >> currNumber)
	{
		separators.push_back(currNumber);
	}
	return separators;
}
std::vector<int> readMessage()
{
	std::vector<int> message;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);

	int currNumber;
	while (istr >> currNumber)
	{
		message.push_back(currNumber);
	}
	return message;
}
std::vector<int> readSearchValue()
{
	std::vector<int> searchValue;

	int currNumber;
	while (true)
	{
		std::cin >> currNumber;
		if (currNumber == 0)
		{
			break;
		}
		searchValue.push_back(currNumber);
	}
	return searchValue;
}
std::vector<int> findingIntervals(std::vector<int>& separators, std::vector<int>& message)
{
	std::vector<int> intervals;

	intervals.push_back(-1);
	for (int i = 0; i < message.size(); i++)
	{
		for (int j = 0; j < separators.size(); j++)
		{

			if (message[i] == separators[j])
			{
				intervals.push_back(i);
			}
		}
	}
	intervals.push_back(message.size());

	return intervals;
}
std::queue<int> solutionOfProblem(std::vector<int>& message,
	std::vector<int>& searchValue, std::vector<int> intervals)
{
	std::queue<int> intervalsContainingValue;

	int countInt = 0;
	int counterInIntervals = 0;


	int startInteral = 0;
	int finishInterval = 0;
	for (int value : searchValue)
	{
		for (int i = 0; i < (intervals.size() - 1); i++)
		{
			startInteral = intervals[i];
			finishInterval = intervals[i + 1];
			for (int j = (startInteral + 1); j < finishInterval; j++)
			{
				if (value == message[j])
				{
					counterInIntervals++;
				}
			}
			if (counterInIntervals != 0)
			{
				countInt++;
				counterInIntervals = 0;
			}
		}
		intervalsContainingValue.push(countInt);
		countInt = 0;
	}

	return intervalsContainingValue;
}