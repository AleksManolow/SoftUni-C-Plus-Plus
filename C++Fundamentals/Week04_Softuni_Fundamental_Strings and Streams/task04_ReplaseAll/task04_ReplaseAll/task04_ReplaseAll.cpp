// task04, �������� ��������, �� ����� � ����� ��� � �����, ���� ��� � & quot; �������� & quot; ��� � ���� ��� �
//& quot; ������ & quot; ���.����� ���� �� ������, ����� ����������� ��& quot; ������& quot; ��� ������ �� ���� 
//������� �& quot; ������& quot; ���.����������� ������� ����� �� ���������.
#include <iostream>
#include <string>
std::string readInput();
void replacingStringWithAnother(std::string& line, std::string& findQuot, std::string& replaceQuot);
int main()
{
	std::string line = readInput();
	std::string findQuot = readInput();
	std::string replaceQuot = readInput();

	replacingStringWithAnother(line, findQuot, replaceQuot);

	std::cout << line << std::endl;

	return 0;
}
std::string readInput()
{
	std::string line;
	getline(std::cin, line);
	return line;
}
void replacingStringWithAnother(std::string& line, std::string& findQuot, std::string& replaceQuot)
{
	int indexOnStringLocated = line.find(findQuot);
	while (indexOnStringLocated != std::string::npos)
	{
		line.replace(indexOnStringLocated, findQuot.size(), replaceQuot);
		indexOnStringLocated = line.find(findQuot, indexOnStringLocated + 1);
	}
}
