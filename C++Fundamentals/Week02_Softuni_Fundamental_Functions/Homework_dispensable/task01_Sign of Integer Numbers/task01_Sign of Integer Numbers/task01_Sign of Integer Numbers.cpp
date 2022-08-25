// task01, Създайте функция, която отпечатва знака на цяло число n:
#include <iostream>
void signOfIntegerNumbers(int n);
int main()
{
	int number;
	std::cin >> number;
	
	signOfIntegerNumbers(number);

	return 0;
}
void signOfIntegerNumbers(int n)
{
	if (n > 0) {
		std::cout << "The number " << n << " is positive." << std::endl;
	}
	else if (n < 0) {
		std::cout << "The number " << n << " is negative." << std::endl;
	}
	else {
		std::cout << "The number " << n << " is zero." << std::endl;
	}
}
