#include <iostream>
const int size = 100;

int main()
{
   
	
	int arr[] = { 13, 42, 69 };
	int* p = &arr[1];
	++(*p);
	for (const int el : arr)
	{
		std::cout << el << " ";
	}
		
	return 0;
}


