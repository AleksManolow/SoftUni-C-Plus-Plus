#include <iostream>
int main()
{	
	int n;
	std::cin >> n;

	int maxElement = INT16_MIN;
	int minElement = INT16_MAX;

	for (int i = 0; i < n; i++)
	{
		int number;
		std::cin >> number;

		if (number > maxElement)
		{
			maxElement = number;
		}
		if (number < minElement)
		{
			minElement = number;
		}
	}

	std::cout << minElement << " " << maxElement << std::endl;

	return 0;
}
