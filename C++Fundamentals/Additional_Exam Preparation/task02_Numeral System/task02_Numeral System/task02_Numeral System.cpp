// task02, Напишете програма, която чете цифрите на цифрова система от база 10 - точно 10 уникални непространствени
//знака на a единичен ред, представляващ символите, използвани за цифрите 0 - 9 (включително)-след това чете две 
//числа, представени в тази цифрова система, след което отпечатва тяхната сума в тази цифрова система.
#include <iostream>
#include <string>
#include <cctype>
#include <array>
const int size = 1000;
std::string readInput();
void isalphaSumSymbols(std::string lineSymbols,
	std::string lineNum1,
	std::string lineNum2);
int main()
{
	std::string lineSymbols = readInput();
	std::string lineNum1 = readInput();
	std::string lineNum2 = readInput();
	if (isdigit(lineSymbols[1]))
	{

	}
	else
	{
		isalphaSumSymbols(lineSymbols, lineNum1, lineNum2);
	}
}
std::string readInput()
{
	std::string line;
	getline(std::cin, line);
	return line;
}
int convertRowOfLettersToNumbers(std::string lineSymbols, std::string lineNum)
{
	int convertNum = 0;
	for (size_t i = 0; i < lineNum.size(); i++)
	{
		for (size_t j = 0; j < lineSymbols.size(); j++)
		{
			if (lineSymbols[j] == lineNum[i])
			{
				convertNum = convertNum * 10;
				convertNum = convertNum + j;
			}
		}
	}
	return convertNum;

}
std::array <int, size> sumCounvertInArray(int sumCounvertNumber)
{
	std::array <int, size> array;
	int temp = sumCounvertNumber;
	int arraySize = 0;
	while (temp)
	{
		temp = temp / 10;
		arraySize++;
	}
	for (int i = (arraySize - 1); i >= 0; i++)
	{
		array[i] = sumCounvertNumber % 10;
		sumCounvertNumber = sumCounvertNumber / 10;
	}
	return array;
}
void isalphaSumSymbols(std::string lineSymbols,
					std::string lineNum1,
					std::string lineNum2)
{
	int fisrtConvertNum = convertRowOfLettersToNumbers(lineSymbols, lineNum1);
	int secountConvertNum = convertRowOfLettersToNumbers(lineSymbols, lineNum2);

	int sumCounvert = fisrtConvertNum + secountConvertNum;
	std::array <int, size> sumCounvertInArr = sumCounvertInArray(sumCounvert);
	for (size_t i = 0; i < sumCounvertInArr.size(); i++)
	{
		std::cout << sumCounvertInArr[i];
	}

}
void isDigitSumSymbols()
{



}
