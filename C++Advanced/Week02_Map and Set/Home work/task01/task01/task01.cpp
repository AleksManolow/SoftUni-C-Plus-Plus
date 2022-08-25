// task01
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include<sstream>
std::vector<double> readInput();
std::map<double, int> howMeetNumer(std::vector <double>& numbers);
void printSolutio(std::map<double, int> meetNumber);
int main()
{
	std::vector<double> numbers = readInput();
	std::map <double, int>meetNumber = howMeetNumer(numbers);
	printSolutio(meetNumber);
	
	return 0;
}
std::vector<double> readInput()
{
	std::vector <double> numbers;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);
	
	double currNummber = 0;
	while (istr >> currNummber)
	{
		numbers.push_back(currNummber);
	}

	return numbers;
}
std::map<double, int> howMeetNumer(std::vector <double>& numbers)
{
	std::map<double, int> meetNumber;
	for (double number : numbers)
	{
		meetNumber[number]++;
	}
	return meetNumber;
}
void printSolutio(std::map<double, int> meetNumber)
{
	for (std::pair <double, int> number : meetNumber)
	{
		std::cout << number.first << " -> " << number.second << std::endl;
	}
}
