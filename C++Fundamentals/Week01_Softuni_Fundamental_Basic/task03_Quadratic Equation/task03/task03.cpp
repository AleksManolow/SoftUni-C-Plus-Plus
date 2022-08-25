#include <iostream>
#include <math.h>

int main()
{
	double a, b, c;
	std::cin >> a >> b >> c;

	double determinant = pow(b, 2) - 4 * a * c;

	double x1 = 0.0;
	double x2 = 0.0;

	if (determinant < 0)
	{
		std::cout << "no roots" << std::endl;
	}
	else if (determinant > 0)
	{
		x1 = (-b + sqrt(determinant)) / (2 * a);
		x2 = (-b - sqrt(determinant)) / (2 * a);

		std::cout << x1 << " " << x2 << std::endl;
	}
	else
	{
		x1 = -b / (2 * a);
		std::cout << x1 << std::endl;
		
	}
	return 0;
}
