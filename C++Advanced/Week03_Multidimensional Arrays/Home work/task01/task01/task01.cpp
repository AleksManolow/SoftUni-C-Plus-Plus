// task01
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
std::vector< std::vector<int> > readVec2D();
bool areEqual2D(std::vector<std::vector<int>>& vecOne,
				std::vector<std::vector<int>>& vecTwo);
void printSolution(bool areEqual);
int main()
{
	std::vector< std::vector<int> > firstVec = readVec2D();
	std::vector< std::vector<int> > secoundVec = readVec2D();

	bool areEqual = areEqual2D(firstVec, secoundVec);
	printSolution(areEqual);

	return 0;
}
std::vector<int> readVec1D()
{
	std::vector<int> vec1D;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);

	int currNumber = 0;
	while (istr >> currNumber)
	{
		vec1D.push_back(currNumber);
	}

	return vec1D;
}
std::vector< std::vector<int> > readVec2D()
{
	int rows = 0;
	std::cin >> rows;
	std::cin.ignore();
	std::vector< std::vector<int> > vec2D(rows);

	for (auto& row : vec2D)
	{
		row = readVec1D();
	}

	return vec2D;
}

bool areEqual1D(std::vector<int>& vecOne,
				std::vector<int>& vecTwo)
{
	const int firstSize = vecOne.size();
	if (firstSize != vecTwo.size())
	{
		return false;
	}
	for (int i = 0; i < firstSize; i++)
	{
		if (vecOne[i] != vecTwo[i])
		{
			return false;
		}
	}
	return true;
}
bool areEqual2D(std::vector<std::vector<int>>& vecOne,
			    std::vector<std::vector<int>>& vecTwo)
{
	const int firstSize = vecOne.size();
	if (firstSize != vecTwo.size() )
	{
		return false;
	}
	for (int i = 0; i < firstSize; i++)
	{
		bool areEqual = areEqual1D(vecOne[i], vecTwo[i]);
		if (!areEqual)
		{
			return false;
		}
	}
	return true;
}
void printSolution(bool areEqual)
{
	std::cout << (areEqual ? "equal" : "not equal");
}