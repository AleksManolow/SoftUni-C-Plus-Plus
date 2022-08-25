// task03.cpp
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
int main()
{
	std::vector<std::string> vec = readInput();



	return 0;
}
std::vector<std::string> readInput()
{
	std::vector<std::string> vec;
	std::string input;
	getline(std::cin, input);
	std::istringstream istr(input);

	std::string word;
	while (istr >> word) {
		vec.push_back(word);
	}

	return vec;
}
void Calculator(std::vector<std::string>& vec)
{
	std::stack <std::string> stackCalculate;
	for (int i = 0; i < length; i++)
	{

	}
		



}
