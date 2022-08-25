// task05
#include<iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>
std::vector<std::string> readInput();
std::vector<std::string> sortInVector(std::vector<std::string>& allNumberOfCar);
std::unordered_set<std::string> parking(std::vector<std::string>& input,
	std::vector<std::string>& sortVec);
void printSolution(std::unordered_set<std::string>& carInParking,
	std::vector<std::string>& sortVec);
int main()
{
	std::vector<std::string> input = readInput();
	std::vector<std::string> sortVec;
	std::unordered_set<std::string> carInParking = parking(input, sortVec);
	printSolution(carInParking, sortVec);

	return 0;
}
std::vector<std::string> readInput()
{
	std::vector<std::string> input;
	std::string line;
	getline(std::cin, line);
	while (line != "END")
	{
		input.push_back(line);
		getline(std::cin, line);
	}
	return input;
}
std::vector<std::string> sortInVector(std::vector<std::string>& allNumberOfCar)
{
	std::vector<std::string> sort;
	std::unordered_set<std::string> helpForSort;
	for (std::string carNum : allNumberOfCar)
	{
		if (helpForSort.find(carNum) == helpForSort.end())
		{
			helpForSort.insert(carNum);
			sort.push_back(carNum);
		}
	}
	return sort;
}
std::unordered_set<std::string> parking(std::vector<std::string>& input,
	std::vector<std::string>& sortVec)
{

	std::unordered_set<std::string> carInParking;
	std::vector<std::string> allNumberOfCar;
	std::string entersOrExits;
	std::string numberOfCar;

	for (std::string line : input)
	{
		std::istringstream istr(line);
		istr >> entersOrExits;
		istr >> numberOfCar;


		if (entersOrExits == "IN,")
		{
			carInParking.insert(numberOfCar);
		}
		else if (entersOrExits == "OUT,")
		{
			carInParking.erase(numberOfCar);
		}
		allNumberOfCar.push_back(numberOfCar);
	}
	sortVec = sortInVector(allNumberOfCar);

	return carInParking;
}
void printSolution(std::unordered_set<std::string>& carInParking,
	std::vector<std::string>& sortVec)
{
	if (carInParking.empty())
	{
		std::cout << "Parking Lot is Empty" << std::endl;
	}
	else
	{
		for (std::string carNum : sortVec)
		{
			if (carInParking.find(carNum) != carInParking.end())
			{
				std::cout << carNum << std::endl;
			}
		}
	}
}