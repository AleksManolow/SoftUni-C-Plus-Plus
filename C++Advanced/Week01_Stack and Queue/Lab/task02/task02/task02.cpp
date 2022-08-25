// task02
#include <iostream>
#include <string>
#include <array>
#include <sstream>
#include <stack>
const int size = 1000;
std::array< int, size> readArray(int& number);
void pushStack(std::array< int, size>& arr, int number, std::stack <int>& stack);
void readsCommands(std::stack <int>& stack);
int sumDigits(std::stack <int>& stack);
int main()
{
	int number = 0;
	std::array< int, size> arr = readArray(number);
	std::stack <int> stack;

	pushStack(arr, number, stack);
	readsCommands(stack);
	std::cout << "Sum digit: " << sumDigits(stack) << std::endl;
	
	return 0;
}
std::array< int, size> readArray(int& number)
{
	std::array< int, size> arr{};
	std::string line;
	getline(std::cin, line);

	std::istringstream istr(line);
	int currNumber = 0;
	

	while (istr >> currNumber)
	{
		arr[number] = currNumber;
		number++;
	}
	return arr;
}
void pushStack(std::array< int, size>& arr, int number, std::stack <int>& stack)
{
	for (int i = 0; i < number; i++)
	{
		stack.push(arr[i]);
	}
}
void readsCommands(std::stack <int>& stack)
{
	std::string str;
	std::cin >> str;
	

	while (str != "end")
	{
		if (str == "add")
		{
			int number1 = 0;
			int number2 = 0;
			std::cin >> number1;
			std::cin >> number2;

			stack.push(number1);
			stack.push(number2);
		}
		else if(str == "remove")
		{
			int numberDelete = 0;
			std::cin >> numberDelete;
			if(numberDelete <= stack.size())
			{
				for (int i = 0; i < numberDelete; i++)
				{
					stack.pop();
				}
			}
			
		}
		std::cin >> str;
	}
}
int sumDigits(std::stack <int>& stack)
{
	if (stack.empty())
	{
		return 0;
	}
	int sum = 0;
	while (!stack.empty()) {
		sum = sum + stack.top();
		stack.pop();
	}
	return sum;
}