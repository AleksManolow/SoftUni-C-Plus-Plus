// task03, Прочетете две цели числа. Изчислете факториал на всяко число. Разделете първия резултат на втория и отпечатайте
//разделение, форматирано до втория десетичен знак.
#include <iostream>
#include <iomanip>
void readTwoNumbers(int& firstNum, int& secoundNum);
double factorialCalculation(int num);
int main()
{
	int firstNumber,  secoundNumber ;

	readTwoNumbers(firstNumber, secoundNumber);
	
	double divisionFacturial =  factorialCalculation(firstNumber) / factorialCalculation(secoundNumber);
	
	std::cout << std::setprecision(2) << std::fixed << divisionFacturial;

	return 0;
	
}
void readTwoNumbers(int& firstNum, int& secoundNum)
{
	std::cin >> firstNum >> secoundNum;
}
double factorialCalculation(int num)
{
	double facturial = 1;
	for (int i = 2; i <= num; i++)
	{
		facturial = facturial * i;
	}
	return facturial;
}