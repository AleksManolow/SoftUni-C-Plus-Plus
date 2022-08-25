// task04
#include<iostream>
#include<queue>
#include<sstream>
#include<string>
std::queue<int> readInput(int& amountFood);
void biggestOrderForTheDay(std::queue<int>& orders);
void remainingOrders(std::queue<int>& orders);
void checkYouHaveEnoughFood(std::queue<int>& orders, int amountFood);
int main()
{
	int amountFood = 0;
	std::queue<int> orders = readInput(amountFood);
	biggestOrderForTheDay(orders);
	checkYouHaveEnoughFood(orders, amountFood);

	return 0;
}
std::queue<int> readInput(int& amountFood)
{
	std::queue<int> orders;
	std::cin >> amountFood;
	std::cin.ignore();

	std::string line;
	std::getline(std::cin, line);
	std::istringstream istr(line);

	std::string digit;
	while (istr >> digit)
	{
		int currNumber = 0;
		currNumber = stoi(digit);
		orders.push(currNumber);
	}
	return orders;
}
void biggestOrderForTheDay(std::queue<int>& orders)
{
	std::queue<int> ordersCopy = orders;

	int bigOrder = 0;
	bigOrder = ordersCopy.front();

	int currNumber = 0;
	while (!ordersCopy.empty())
	{
		currNumber = ordersCopy.front();
		if (currNumber > bigOrder)
		{
			bigOrder = currNumber;
		}
		ordersCopy.pop();
	}
	std::cout << bigOrder << std::endl;
}
void remainingOrders(std::queue<int>& orders)
{
	while (!orders.empty())
	{
		std::cout << orders.front() << ' ';
		orders.pop();
	}
}

void checkYouHaveEnoughFood(std::queue<int>& orders, int amountFood)
{
	int orderPerLine = 0;
	while (!orders.empty())
	{
		orderPerLine = orders.front();
		amountFood = amountFood - orderPerLine;
		if (amountFood < 0)
		{
			std::cout << "Orders left: ";
			remainingOrders(orders);
			return;
		}
		orders.pop();
	}

	std::cout << "Orders complete" << std::endl;
}