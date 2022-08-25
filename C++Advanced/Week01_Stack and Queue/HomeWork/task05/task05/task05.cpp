// task05
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
std::stack<int> readInput(int& capacityTrunk);
int trunkToNeed(std::stack<int>& boxClothes, int capacityTrunk);
int main() 
{
	int capacityTrunk = 0;
	std::stack<int> boxClothes = readInput(capacityTrunk);
	std::cout << trunkToNeed(boxClothes, capacityTrunk);
	return 0;
}
std::stack<int> readInput(int& capacityTrunk)
{
	std::stack<int> boxClothes;
	std::string line;
	std::getline(std::cin, line);
	std::istringstream istr(line);

	std::string value;
	int currValue = 0;
	while (istr>>value)
	{
		currValue = stoi(value);
		boxClothes.push(currValue);
	}

	std::cin >> capacityTrunk;

	return boxClothes;
}
int trunkToNeed(std::stack<int>& boxClothes, int capacityTrunk)
{
	int sumValueClothes = 0;
	int countTrunk = 0;
	while (!boxClothes.empty())
	{
		sumValueClothes = sumValueClothes + boxClothes.top();
		if (sumValueClothes > capacityTrunk)
		{
			countTrunk++;
			sumValueClothes = 0;
			continue;
		}
		boxClothes.pop();
	}
	return countTrunk + 1;
}