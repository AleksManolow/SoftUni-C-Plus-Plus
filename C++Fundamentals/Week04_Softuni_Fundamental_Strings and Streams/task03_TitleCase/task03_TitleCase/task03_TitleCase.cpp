// task03, �������� ��������, ����� ������� ����� ���� � �����, �� �� ������� � ������ ����� (�� �� ����������� 
//� ������� ��������-������� ������� �� �� �������������� �� ���� ���� in, from � �.�.).�� �������, �� �������
//����� �� ������ � ��������� ������ ������ ����������� �� ������� ������(���� �� � ���� �� �� ���������, ����,
//������, ���� � ��� �� ������ ������� ����, ����� ������ �� �� ����� � ������ �����).
#include <iostream>
#include <string>
#include <cctype>
std::string readInput();
void capitalizedWords(std::string& input);

int main()
{
	std::string input = readInput();
	capitalizedWords(input);
	
	std::cout << input << std::endl;
	return 0;
}
std::string readInput()
{
	std::string line;
	getline(std::cin, line);
	return line;
}
void capitalizedWords(std::string& input)
{
	int startWord = 0;
	int size = input.size();
	for (int i = 0; i < input.size(); i++)
	{
		if (isalpha(input[i]))
		{
			startWord++;
		}
		else if (!isalpha(input[i]))
		{
			input[i - startWord] = toupper(input[i - startWord]);
			startWord = 0;
		}
	}
	input[size - startWord] = toupper(input[size - startWord]);
}