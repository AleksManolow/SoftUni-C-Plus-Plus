// task01
#include <iostream>
#include <map>
#include <string>
#include <cmath>
std::string readInput();
std::map<std::string, std::string> hexadecimalToBinary();
std::map<std::string, std::string> binaryheToXadecimal();
int binaryToDecimal(int n);
int decimalToBinary(int num);
int convertStringFirstPairToIntNumber(std::string color,
	int i, int j,
	std::map<std::string, std::string> hecToBin);
std::string converAvarageValueToHec(int avarageValueInInt, 
	std::map<std::string, std::string> binToHex);
std::string calculationOfTheAverageValueOfChannel(std::string firstColor,
	std::string secoundColor,
	int i, int j,
	std::map<std::string, std::string> hecToBin,
	std::map<std::string, std::string> binToHex);
std::string solutionOfTheProblem(std::string firstColor, std::string secoundColor,
	std::map<std::string, std::string> hecToBin,
	std::map<std::string, std::string> binToHex);
int main()
{
	std::string firstColor = readInput();
	std::string secounColor = readInput();

	std::map<std::string, std::string> hecToBin = hexadecimalToBinary();
	std::map<std::string, std::string> binToHex = binaryheToXadecimal();

	std::cout << solutionOfTheProblem(firstColor, secounColor,hecToBin, binToHex) << std::endl;

	return 0;
}
std::string readInput()
{
	std::string color;
	std::cin >> color;
	return color;
}
std::map<std::string, std::string> hexadecimalToBinary()
{
	std::map<std::string, std::string> simwols = {
		std::pair<std::string, std::string> {"0", "0000"},
		std::pair<std::string, std::string> {"1", "0001"},
		std::pair<std::string, std::string> {"2", "0010"},
		std::pair<std::string, std::string> {"3", "0011"},
		std::pair<std::string, std::string> {"4", "0100"},
		std::pair<std::string, std::string> {"5", "0101"},
		std::pair<std::string, std::string> {"6", "0110"},
		std::pair<std::string, std::string> {"7", "0111"},
		std::pair<std::string, std::string> {"8", "1000"},
		std::pair<std::string, std::string> {"9", "1001"},
		std::pair<std::string, std::string> {"a", "1010"},
		std::pair<std::string, std::string> {"b", "1011"},
		std::pair<std::string, std::string> {"c", "1100"},
		std::pair<std::string, std::string> {"d", "1101"},
		std::pair<std::string, std::string> {"e", "1110"},
		std::pair<std::string, std::string> {"f", "1111"}
	};
	return simwols;
}
std::map<std::string, std::string> binaryheToXadecimal()
{
	std::map<std::string, std::string> simwols = {
		std::pair<std::string,std::string> {"0000","0"},
		std::pair<std::string,std::string> {"0001","1"},
		std::pair<std::string,std::string> {"0010","2"},
		std::pair<std::string,std::string> {"0011","3"},
		std::pair<std::string,std::string> {"0100","4"},
		std::pair<std::string,std::string> {"0101","5"},
		std::pair<std::string,std::string> {"0110","6"},
		std::pair<std::string,std::string> {"0111","7"},
		std::pair<std::string,std::string> {"1000","8"},
		std::pair<std::string,std::string> {"1001","9"},
		std::pair<std::string,std::string> {"1010","a"},
		std::pair<std::string,std::string> {"1011","b"},
		std::pair<std::string,std::string> {"1100","c"},
		std::pair<std::string,std::string> {"1101","d"},
		std::pair<std::string,std::string> {"1110","e"},
		std::pair<std::string,std::string> {"1111","f"}
	};
	return simwols;
}
int binaryToDecimal(int n)
{
	int num = n;
	int dec_value = 0;

	int base = 1;

	int temp = num;
	while (temp) {
		int last_digit = temp % 10;
		temp = temp / 10;

		dec_value += last_digit * base;

		base = base * 2;
	}

	return dec_value;
}
int decimalToBinary(int num)
{
	int temp = num;
	int binaryNumber = 0;

	int exponent = 0;
	while (temp) {
		int remainder = temp % 2;
		binaryNumber += remainder * pow(10, exponent);
		temp /= 2;
		exponent++;
	}

	return binaryNumber;
}
int convertStringFirstPairToIntNumber(std::string color,
									int i, int j,
									std::map<std::string, std::string> hecToBin)
{

	std::string firstElOfPair = color.substr(i, 1);
	std::string secoundElOfPair = color.substr(j, 1);
	

	std::string convFirstElOfPair = hecToBin[firstElOfPair];
	std::string convSecoudElOfPair = hecToBin[secoundElOfPair];

	std::string binNumberInString = convFirstElOfPair;
	binNumberInString.append(convSecoudElOfPair);

	int binNumberInInt = std::stoi(binNumberInString);

	int convertNumberInDec = binaryToDecimal(binNumberInInt);

	return convertNumberInDec;
}
std::string converAvarageValueToHec(int avarageValueInInt, std::map<std::string, std::string> binToHex)
{
	std::string avarageValue;

	std::string convertAverageValueToBin = std::to_string(decimalToBinary(avarageValueInInt));

	switch (convertAverageValueToBin.size())
	{
	case 1:
	{
		std::string counter = "0000000";
		counter.append(convertAverageValueToBin);
		convertAverageValueToBin = counter;
		break;
	}
	case 2:
	{
		std::string counter = "000000";
		counter.append(convertAverageValueToBin);
		convertAverageValueToBin = counter;
		break;
	}	
	case 3:
	{
		std::string counter = "00000";
		counter.append(convertAverageValueToBin);
		convertAverageValueToBin = counter;
		break;
	}
	case 4:
	{
		std::string counter = "0000";
		counter.append(convertAverageValueToBin);
		convertAverageValueToBin = counter;
		break;
	}
	case 5:
	{
		std::string counter = "000";
		counter.append(convertAverageValueToBin);
		convertAverageValueToBin = counter;
		break;
	}
	case 6:
	{
		std::string counter = "00";
		counter.append(convertAverageValueToBin);
		convertAverageValueToBin = counter;
		break;
	}
	case 7:
	{
		std::string counter = "0";
		counter.append(convertAverageValueToBin);
		convertAverageValueToBin = counter;
		break;
	}
	}
	std::string firstNumberOfPair = convertAverageValueToBin.substr(0, 4);
	std::string secoundNumberOfPair =  convertAverageValueToBin.substr(4, 4);

	firstNumberOfPair = binToHex[firstNumberOfPair];
	secoundNumberOfPair = binToHex[secoundNumberOfPair];

	avarageValue = firstNumberOfPair;
	avarageValue.append(secoundNumberOfPair);

	return avarageValue;
}
std::string calculationOfTheAverageValueOfChannel(std::string firstColor, 
												  std::string secoundColor,
												  int i, int j,
												  std::map<std::string, std::string> hecToBin,
												  std::map<std::string, std::string> binToHex)
{
	std::string avarageValue;

	int convertNumberInDecFirstColor = convertStringFirstPairToIntNumber(firstColor, i, j, hecToBin);
	int convertNumberInDecSecoundColor = convertStringFirstPairToIntNumber(secoundColor, i, j, hecToBin);

	int avarageValueInInt = (convertNumberInDecFirstColor + convertNumberInDecSecoundColor) / 2;

	avarageValue = converAvarageValueToHec(avarageValueInInt, binToHex);

	return avarageValue;
}
std::string solutionOfTheProblem(std::string firstColor, std::string secoundColor, 
	std::map<std::string, std::string> hecToBin,
	std::map<std::string, std::string> binToHex)
{
	std::string finalColor = "#";

	std::string firstChannel = calculationOfTheAverageValueOfChannel(firstColor, secoundColor, 1, 2, hecToBin, binToHex);
	std::string secoundChannel= calculationOfTheAverageValueOfChannel(firstColor, secoundColor, 3, 4, hecToBin, binToHex);
	std::string thirdChannel= calculationOfTheAverageValueOfChannel(firstColor, secoundColor, 5, 6, hecToBin, binToHex);

	finalColor.append(firstChannel).append(secoundChannel).append(thirdChannel);

	return finalColor;
}