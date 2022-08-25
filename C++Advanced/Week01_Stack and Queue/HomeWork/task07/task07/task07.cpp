// task07
#include <iostream>
#include <stack>
#include <string>
#include <queue>
std::string readInput();
void fillintOfStackEndQueue(std::string& line,
	std::stack<char>& backBrackets,
	std::queue<char>& fronBrackets);
bool openBrackets(char back, char front);
bool closeBrackets(char back, char front);
bool beakBrackets(char back, char front);
void determineExpressionBalanced(std::stack<char>& backBrackets,
								 std::queue<char>& fronBrackets);
int main()
{
	std::string line = readInput();
	std::stack<char>backBrackets;
	std::queue<char>fronBrackets;
	fillintOfStackEndQueue(line, backBrackets, fronBrackets);
	determineExpressionBalanced(backBrackets, fronBrackets);

	return 0;
}
std::string readInput()
{
	std::string line;
	getline(std::cin, line);


	return line;
}
void fillintOfStackEndQueue(std::string& line,
							std::stack<char>& backBrackets,
							std::queue<char>& fronBrackets)
{
	char currChar;
	for (int i = 0; i < (line.size() / 2); i++)
	{
		currChar = line[i];
		fronBrackets.push(currChar);
	}
	for (int i = (line.size() / 2); i < line.size(); i++)
	{
		currChar = line[i];
		backBrackets.push(currChar);
	}

}
bool openBrackets(char back, char front)
{
	if (front == '(' && back == ')')
	{
		return true;
	}
	return false;
}
bool closeBrackets(char back, char front)
{
	if (front == '[' && back == ']')
	{
		return true;
	}
	return false;
}
bool beakBrackets(char back, char front)
{
	if (front == '{' && back == '}')
	{
		return true;
	}
	return false;
}
void determineExpressionBalanced(std::stack<char>& backBrackets,
								 std::queue<char>& fronBrackets)
{
	if (backBrackets.size() != fronBrackets.size())
	{
		std::cout << "NO" << std::endl;
		return;
	}
	if (backBrackets.empty() || fronBrackets.empty())
	{
		std::cout << "NO" << std::endl;
		return;
	}
	while (!backBrackets.empty() && !fronBrackets.empty())
	{
		switch (fronBrackets.front())
		{
		case '(':
			
			if (!openBrackets(backBrackets.top(),fronBrackets.front()))
			{
				std::cout << "NO" << std::endl;
				return;
			}
			fronBrackets.pop();
			if (fronBrackets.front()== '{' || fronBrackets.front() == '[')
			{
				std::cout << "NO" << std::endl;
				return;
			}
			break;
		case '{':
			if (!beakBrackets(backBrackets.top(), fronBrackets.front()))
			{
				std::cout << "NO" << std::endl;
				return;
			}
			fronBrackets.pop();
			break;
		case '[':
			if (!closeBrackets(backBrackets.top(), fronBrackets.front()))
			{
				std::cout << "NO" << std::endl;
				return;
			}
			fronBrackets.pop();
			if (fronBrackets.front() == '{')
			{
				std::cout << "NO" << std::endl;
				return;
			}
			break;
		default:
			break;
		}
		backBrackets.pop();
	}
	std::cout << "YES" << std::endl;
}

