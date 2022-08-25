// task01, ��������� �� ������������ �� ��� ����� � ��������� ����������� ������� - X1, Y1, X2 � Y2. �������� �����
//����� ��������� �������, ����� � ��� - ����� �� ������� �� ������������� �������(0, 0) ��� ������(X, Y).��� ������� ��
//�� ������ ���������� �� �������, ����������� ���� ������.
#include <iostream>
#include <cmath>
void readCoordinates(double& x, double& y);
double getDistens(double x, double y, double centerX, double centerY);

int main()
{
	double x1 = 0.0;
	double y1 = 0.0;
	double x2 = 0.0;
	double y2 = 0.0;

	readCoordinates(x1, y1);
	readCoordinates(x2, y2);

	const double centerX = 0.0;
	const double centerY = 0.0;
	double firtsPoinDistens = getDistens(x1, y1, centerX, centerY);
	double secoundPoinDistens = getDistens(x2, y2, centerX, centerY);


	if (firtsPoinDistens < secoundPoinDistens)
	{
		std::cout << "(" << x1 << ", " << y1 << ")" << std::endl;
	}
	else
	{
		std::cout << "(" << x2 << ", " << y2 << ")" << std::endl;
	}
	return 0;
}
void readCoordinates(double& x, double& y)
{
	std::cin >> x >> y;
}
double getDistens(double x, double y, double centerX, double centerY)
{
	double distensX = x - centerX;
	double distensY = y - centerY;
	double squareDistens = (distensX * distensX + distensY * distensY);

	double distens = sqrt(squareDistens);

	return distens;
}

