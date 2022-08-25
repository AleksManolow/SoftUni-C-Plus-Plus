// task02
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
std::vector<std::pair<int, int>> getIntervals();
std::vector<int> readNumbers();
std::unordered_map<int, std::string> solutionOfProblem(std::vector<std::pair<int, int>> intervals,
	std::vector<int> numbers);
void printSolution(std::unordered_map<int, std::string> solution, std::vector<int> numbers);
int main()
{
	std::vector<std::pair<int, int>> intervals = getIntervals();
	std::vector<int> numbers = readNumbers();

	std::unordered_map<int, std::string> solution = solutionOfProblem(intervals, numbers);

	printSolution(solution, numbers);
	return 0;
}
std::vector<std::pair<int, int>> getIntervals()
{
	std::vector<std::pair<int, int>> intervals;
	std::string token;

	while (std::cin >> token && token != ".") {
		int left = std::stoi(token);
		int right = 0;
		std::cin >> right;
		intervals.push_back(std::make_pair(left, right));
	}
	return intervals;
}
std::vector<int> readNumbers()
{
	std::vector<int> numbers;
	std::string token;

	while (std::cin >> token && token != ".")
	{
		int num = std::stoi(token);
		numbers.push_back(num);
	}

	return numbers;
}
std::unordered_map<int, std::string> solutionOfProblem(std::vector<std::pair<int, int>> intervals,
	std::vector<int> numbers)
{
	std::unordered_map<int, std::string> solution;

	int counter = 0;
	for (int num : numbers)
	{
		for (int i = 0; i < intervals.size(); i++)
		{
			if (num >= intervals[i].first && num <= intervals[i].second)
			{
				counter++;
			}
		}
		if (counter != 0)
		{
			solution[num] = "in";
			
		}
		else
		{
			solution[num] = "out";
		}
		counter = 0;
	}

	return solution;
}
void printSolution(std::unordered_map<int, std::string> solution, std::vector<int> numbers)
{
	for (int num : numbers)
	{
		std::cout << solution[num] << std::endl;
	}
}