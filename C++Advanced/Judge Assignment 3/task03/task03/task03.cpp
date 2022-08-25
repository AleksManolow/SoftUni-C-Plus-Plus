// task03
#include <iostream>
#include <map>
int main()
{

	std::map<int, int > tiger;

	for (int i = 0; i < 6; i++)
	{
		tiger[i % 2]++;
	}
	for (int i = 0; i < tiger.size(); i++)
	{
		std::cout << tiger[i] << std::endl;
	}


	
	return 0;
}
