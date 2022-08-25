// task02
#include <iostream>
#include <string>
std::string readInput();
void newLine(std::string& line, std::string& magicalItems);
int main()
{
	std::string line = readInput();
	std::string magicalItems = "aeiou";

	newLine(line, magicalItems);

	return 0;
}
std::string readInput()
{
	std::string line;
	getline(std::cin, line);
	return line;
}
void newLine(std::string& line, std::string& magicalItems)
{
	bool counter = true;
	for (size_t i = 0; i < line.size(); i++)
	{

		if (line[i] == line[i + 1])
		{
			for (size_t j = 0; j < magicalItems.size(); j++)
			{
				if (line[i] == magicalItems[j])
				{
					counter = false;
				}
			}
			if (counter)
			{
				line.erase(i, 1);
				i--;
			}
			counter = true;
		}
	}
	std::cout << line << std::endl;
}
