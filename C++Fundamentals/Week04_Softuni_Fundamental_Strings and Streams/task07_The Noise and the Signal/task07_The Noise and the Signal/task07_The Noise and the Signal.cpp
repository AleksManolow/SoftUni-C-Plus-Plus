// task07, ������ ���� ������ 6, �� ������ ������ ��� � �� �������� ���-������ ��� � ����� (������� ������ �� �����
//����������� ���� �����).��� ������� ���� � ������� �������, ����������� ����, ����� � ������� ��������������.���
//���� ������, ����������� ���� ���.������ ������� ��� ����� �� ����� ��� �����, �����, ���������� ��� ����� ��
//���������� ASCII �������(��� ��������� ������� ���� ���� ������ ��� �������, ��������� � �.�.)
#include <iostream>
#include <string>
#include <cctype>
std::string readInput();
void theNoiseAndTheSignal(std::string& input);
int main()
{
	std::string line = readInput();
	theNoiseAndTheSignal(line);

	return 0;
}
std::string readInput()
{
	std::string line;
	getline(std::cin, line);
	return line;
}
void theNoiseAndTheSignal(std::string& input)
{
	std::string word;
	std::string longNoise;
	int counter = 0;
	int maxCounter = 0;
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i]) && input[i] != ' ')
		{
			char alpha = input[i];
			word.push_back(alpha);
			counter++;
		}
		else if (input[i] == ' ')
		{
			if (counter >= maxCounter)
			{
				longNoise = word;
				maxCounter = counter;
			}
			word.clear();
			counter = 0;
		}
	}
	if (counter >= maxCounter)
	{
		longNoise = word;
	}
	if (counter == 0)
	{
		std::cout << "no noise" << std::endl;

	}
	else
	{
		std::cout << longNoise << std::endl;
	}
}
