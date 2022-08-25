// task06, Създайте функция, която изчислява и връща стойността на число, повишено до дадена степен:
#include <iostream>
int mathPower(int a, int b);
int main()
{
	int number, degree;
	std::cin >> number >> degree;

	std::cout << mathPower(number, degree) << std::endl;

	return 0;
}
int mathPower(int a, int b)
{
	int power = 1;
	for (int  i = 0; i < b; i++)
	{
		power = power * a;
	}
	return power;
}