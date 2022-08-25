// task01
#include<iostream>
#include<string>
#include <vector>
#include<sstream>
#include <set>
std::vector<std::vector <std::string>> readInout(std::string& namesCol);
void solutionOfProblem(std::vector<std::vector <std::string>>& matrix, std::string namesCol);
int main()
{
	std::string namesCol;
	std::vector<std::vector <std::string>> matrix = readInout(namesCol);

	solutionOfProblem(matrix, namesCol);
	return 0;
}
std::vector <std::string> readLine()
{
	std::vector <std::string> lineVec;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);

	std::string currStr;
	while (istr >> currStr)
	{
		lineVec.push_back(currStr);
	}

	return lineVec;
}
std::vector<std::vector <std::string>> readInout(std::string& namesCol)
{
	std::vector<std::vector <std::string>> matrix;
	
	while (true)
	{
		std::vector<std::string> row = readLine();
		if (row[0] == "end")
		{
			break;
		}
		matrix.push_back(row);
	}
	std::cin >> namesCol;

	return matrix;
}
void solutionOfProblem(std::vector<std::vector <std::string>>& matrix, std::string namesCol)
{
	std::string frequentSting;
	int frequentStingCount = 0;

	int countCol = 0;
	for (auto vec : matrix)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (namesCol == vec[i])
			{
				countCol = i;
				break;
			}
		}
	}
	int counter = 0;
	for (auto vec : matrix)
	{
		std::string zeroStr = vec[countCol];
		if (zeroStr[0] != '0')
		{
			for (auto vec1 : matrix)
			{
				if (vec[countCol] == vec1[countCol])
				{
					counter++;
				}
			}
			if (frequentStingCount <= counter)
			{
				frequentStingCount = counter;
				frequentSting = vec[countCol];
			}
			counter = 0;
		}
	}

	std::cout << frequentSting << " " << frequentStingCount << std::endl;
}
