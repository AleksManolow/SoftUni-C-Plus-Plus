// task02
#include <iostream>
#include <vector>
#include<unordered_map>
#include <string>
#include<sstream>
#include <unordered_set>
#include <iomanip>
std::vector<std::string> readInput();
std::unordered_map<std::string, std::vector<double>> apOfGrades(std::vector<std::string>& input);
void printSolution(std::unordered_map<std::string, std::vector<double>>& dateMap,
	std::vector<std::string>& input);
int main()
{
	std::vector<std::string> input = readInput();
	std::unordered_map<std::string, std::vector<double>> dateMap = apOfGrades(input);
	printSolution(dateMap, input);

	return 0;
}
std::vector<std::string> readInput()
{
	int lenght = 0;
	std::cin >> lenght;
	std::cin.ignore();

	std::vector<std::string> input(lenght);
	
	for (std::string& line : input)
	{
		getline(std::cin, line);
	}

	return input;
}
std::unordered_map<std::string, std::vector<double>> apOfGrades(std::vector<std::string>& input)
{
	std::unordered_map<std::string, std::vector<double>> map;
	std::string name;
	double grade = 0.00;

	for (std::string line : input)
	{
		std::istringstream istr(line);
		istr >> name;

		grade = 0.00;
		while (istr >> grade)
		{
			map[name].push_back(grade);
		}
	}
	return map;
}
std::vector<std::string> sortNameInVec(std::unordered_map<std::string, std::vector<double>>& dateMap,
									   std::vector<std::string>& input)
{
	std::unordered_set<std::string> helpSort;
	std::string name;
	std::vector <std::string> sortVec;
	for (std::string line : input)
	{
		std::istringstream istr(line);
		istr >> name;
		if (helpSort.find(name) == helpSort.end())
		{
			helpSort.insert(name);
			sortVec.push_back(name);
		}
	}
	return sortVec;
}
void printSolution(std::unordered_map<std::string, std::vector<double>>& dateMap,
				   std::vector<std::string>& input )
{
	std::vector<std::string> sortVec = sortNameInVec(dateMap, input);
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	for (std::string name : sortVec)
	{
		int numberOfElementsInVecOfMap = dateMap[name].size();
		double sumOfElementsInVecOfMap = 0.00;
		std::cout << name << " -> ";
		for (int i = 0; i < dateMap[name].size(); i++)
		{
			std::cout << dateMap[name][i] << " ";
			sumOfElementsInVecOfMap += dateMap[name][i];
		}
		double avarageOfElementsInVecOfMap = 0.00;
		avarageOfElementsInVecOfMap = sumOfElementsInVecOfMap / numberOfElementsInVecOfMap;
		std::cout << "(avg: " << avarageOfElementsInVecOfMap << ")" << std::endl;
	}
}