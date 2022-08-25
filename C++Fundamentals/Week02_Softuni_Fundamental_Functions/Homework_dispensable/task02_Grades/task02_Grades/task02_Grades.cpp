// task02, Напишете функция, която получава оценка между 2,00 и 6,00 и отпечатва съответната оценка с думи.
#include <iostream> 
void printsTheCorresponding(double grade);
int main()
{
	double grade;
	std::cin >> grade;
	printsTheCorresponding(grade);
	return 0;

}
void printsTheCorresponding(double grade)
{
	if (grade >= 2.00 && grade < 3.00 )
	{
		std::cout << "Fail" << std::endl;
	}
	else if ( grade <= 3.49 )
	{
		std::cout << "Poor" << std::endl;
	}
	else if (grade <= 4.49)
	{
		std::cout << "Good" << std::endl;
	}
	else if (grade <= 5.49)
	{
		std::cout << "Very good" << std::endl;
	}
	else if (grade <= 6.00)
	{
		std::cout << "Excellent" << std::endl;
	}
}
