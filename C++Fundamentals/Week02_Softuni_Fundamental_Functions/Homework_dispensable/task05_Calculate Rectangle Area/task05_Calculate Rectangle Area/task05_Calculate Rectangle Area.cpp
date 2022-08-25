// task05, Създайте функция, която изчислява и връща площта на правоъгълник по зададена ширина и височина:
#include <iostream>
int areaOfRectangle(int a, int b);
int main()
{
	int width, height;
	std::cin >> width >> height;

	std::cout << areaOfRectangle(width, height) << std::endl;

	return 0;
}
int areaOfRectangle(int a, int b)
{
	return a * b;
}