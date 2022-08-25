// task06, �������� ��������, ����� ���� ���������������� �� ������������� ���� ����� (� ����������� ������� � 
//�����), ��������� � ��������� � ������ ����������� ����.������� �� ����� ����� �� ���� ���� - ������� �����,
//���� ��� ����� ������� �� �������, ����� �� �� ��������� �����(������ �� �� ����������, ������ ������
//�����).������ ������� ��� ����� �� ����� ��� �����, �����, ���������� ��� ����� �� ������������ ASCII �������
//(���� ��������� ������� ���� ���� ������ ��� �������, ��������� � �.�.)
#include <iostream>
#include <string>
#include<cctype>
std::string readInput();
void findMaxNumbers(std::string& input);
int main()
{
	std::string line = readInput();
	findMaxNumbers(line);
	return 0;
}
std::string readInput()
{
	std::string line;
	getline(std::cin, line);
	return line;
}
void findMaxNumbers(std::string& input)
{
	int size = input.size();
	int maxDigit = 0;
	int digit = 0;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (isdigit(input[i]))
		{
			digit = digit * 10;
			digit = digit + (input[i] - '0');
		}
		else if (input[i] == ' ')
		{
			if (maxDigit < digit)
			{
				maxDigit = digit;
			}
			digit = 0;
		}
	}
	if (maxDigit < digit)
	{
		maxDigit = digit;
	}
	std::cout << maxDigit << std::endl;
}
