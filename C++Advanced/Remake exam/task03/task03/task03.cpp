// task03
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<sstream>
int main()
{
	std::vector<std::vector<std::map<std::string, std::string>>>;


	return 0;
}
std::map<std::string, std::string> lineifoffer()
{
	std::map<std::string, std::string> maps;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr (line);

	std::string currstring;
	std::string newCurrString;
	while (istr >> currstring)
	{
		istr >> newCurrString;
		maps[currstring] = newCurrString;
	}
	return maps;
}
std::vector<std::map<std::string, std::string>> readLine()
{
	std::vector<std::map<std::string, std::string>>line;

	



	return line;
}
std::vector<std::vector<std::map<std::string, std::string>>> readInput()
{
	std::vector<std::vector<std::map<std::string, std::string>>> vecRead;

	while (true)
	{

	}


	return vecRead;
}
