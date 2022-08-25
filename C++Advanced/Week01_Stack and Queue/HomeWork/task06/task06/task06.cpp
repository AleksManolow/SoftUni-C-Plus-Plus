// task06
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
std::vector<std::string> readInput();
void firstPointCircle(std::vector<std::string>& values);
int main()
{
	std::vector<std::string>values = readInput();
	firstPointCircle(values);
	
	
	return 0;
}
std::vector<std::string> readInput()
{
	int sizeVec = 0;
	std::cin >> sizeVec;
	std::cin.ignore();

	std::vector<std::string>values(sizeVec);

	for (std::string& value : values)
	{
		getline(std::cin, value);
	}

	return values;
}
bool result(std::vector<std::string>& values, int index)
{
	int amountPetrol = 0;
	int distancePetrolPump = 0;
	int sumKM = 0;
	int sumL = 0;
	for (int i = index; i < values.size(); i++)
	{
		std::string value = values[i];
		std::istringstream istr(value);
		istr >> amountPetrol;
		istr >> distancePetrolPump;

		sumKM = sumKM + distancePetrolPump;
		sumL = sumL + amountPetrol;
	}
	if (sumKM < sumL)
	{
		return true;

	}
	return false;

}
void firstPointCircle(std::vector<std::string>& values)
{
	int amountPetrol = 0;
	int distancePetrolPump = 0;
	int i = 0;

	for (std::string value : values)
	{
		std::istringstream istr(value);
		istr >> amountPetrol;
		istr >> distancePetrolPump;

		if (amountPetrol > distancePetrolPump)
		{
			if (result(values, i)) 
			{
				std::cout << i << std::endl;
				return;
			}
		}
		i++;
	}
}
