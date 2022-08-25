// task01, На определена жп гара влаковете пристигат по два коловоза - Път А и Път Б - и се обединяват в един коловоз. Всеки
//вагонът има номер, а във всеки влак вагоните са подредени по номер - предният вагон има най - малък номер,
//задният вагон има най - голям брой.
//Като се имат предвид номерата на мотрисите на писта А и писта Б, дадени от задната кола към предната кола,
//отпечатайте реда, в който мотрисите от Пътека А и Пътека Б трябва да бъдат обединени в единичната писта, 
//след което да се отпечата новата конфигурация на влака, като се започне от последния вагон и се завърши при 
//първия вагон.Вагоните се преместват, започвайки отпред назад (т.е.можете да движите само предния вагон на влак).
//Всеки път, когато премествате мотриса от паралелните коловози A и B къмслейте коловоза, той тласка напред всички
//мотриси, които вече са там.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <list>
std::vector<int> readTrainFromInout();
void mergeTrains(std::vector <int>& firstTrain,
	std::vector <int>& secoundTrain,
	std::list <int>& mergetTrain,
	std::string& trainSequence);
void printSolution(std::list <int>& mergetTrain,
	std::string& trainSequence);
int main()
{
	std::vector <int> firstTrain = readTrainFromInout();
	std::vector <int> secoundTrain = readTrainFromInout();
	std::list <int> mergetTrain;
	std::string trainSequence;
	mergeTrains(firstTrain, secoundTrain, mergetTrain, trainSequence);
	printSolution(mergetTrain, trainSequence);
	return 0;
}
std::vector<int> readTrainFromInout()
{
	std::vector<int> train;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);
	int currNumber = 0;
	while (istr >> currNumber)
	{
		train.push_back(currNumber);
	}
	return train;
}
void mergeTrains(std::vector <int>& firstTrain,
	std::vector <int>& secoundTrain,
	std::list <int>& mergetTrain,
	std::string& trainSequence)
{
	while (true)
	{
		bool isFirstTrainEmpty = firstTrain.empty();
		bool isSecoundTrainEmpty = secoundTrain.empty();
		if (isFirstTrainEmpty && isSecoundTrainEmpty)
		{
			break;
		}
		if (isFirstTrainEmpty)
		{
			mergetTrain.push_front(secoundTrain.back());
			trainSequence.push_back('B');
			secoundTrain.pop_back();
			continue;
		}
		if (isSecoundTrainEmpty)
		{
			mergetTrain.push_front(firstTrain.back());
			trainSequence.push_back('A');
			firstTrain.pop_back();
			continue;
		}

		if (firstTrain.back() < secoundTrain.back())
		{
			mergetTrain.push_front(firstTrain.back());
			trainSequence.push_back('A');
			firstTrain.pop_back();
		}
		else
		{
			mergetTrain.push_front(secoundTrain.back());
			trainSequence.push_back('B');
			secoundTrain.pop_back();
		}
	}
}
void printSolution(std::list <int>& mergetTrain,
	std::string& trainSequence)
{
	std::cout << trainSequence << std::endl;
	for (int elem : mergetTrain)
	{
		std::cout << elem << ' ';
	}
}

