// task05, �������� �������, ����� ��������� � ����� ������ �� ������������ �� �������� ������ � ��������:
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