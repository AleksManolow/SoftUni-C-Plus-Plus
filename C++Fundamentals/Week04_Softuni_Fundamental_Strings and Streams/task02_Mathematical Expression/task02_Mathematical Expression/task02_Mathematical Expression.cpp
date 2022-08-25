// task02, �������� ��������, ����� ���� ��� �� ���������, �������� ������������� �����. �������� bool �������
//����� ��������� ���� ������� � ������() �� ��������� ��������(��������, �� ������ �������� � ��������, �.�.
//�� � ���������� �� ����������� �� �������� �����, �������� ���������� / ����� � �.�.) � ����� true,
//��� �� ����� � false, ��� �� �� �����.����������� �������� ��� ���������� ��������� �� ���������.
#include <iostream>
#include <string>
std::string readInput();
bool correctlyPlacedBrackets(std::string line);
int main()
{
	std::string input = readInput();
	(correctlyPlacedBrackets(input)) ? std::cout << "correct" << std::endl : std::cout << "incorrect" << std::endl;
}
std::string readInput()
{
	std::string line;
	getline(std::cin, line);
	return line;
}
bool correctlyPlacedBrackets(std::string line)
{
	int openingBracket = 0;
	int closingBracket = 0;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == '(')
		{
			openingBracket++;
		}
		else if (line[i] == ')')
		{
			closingBracket++;
		}
	}
	if (openingBracket == closingBracket)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
