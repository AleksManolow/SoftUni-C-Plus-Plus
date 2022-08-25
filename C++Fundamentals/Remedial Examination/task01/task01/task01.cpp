// task01
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
const int N = 1000;
std::array <int, N> readInput(int& size);
double avarageArrayElements(std::array <int, N>& arr, int size);
void fineGreaterThanAverage(std::array <int, N>& arr, int size, std::vector <int>& vec);
void printElements(std::vector <int>& vec);
int main()
{
	int sizeArr = 0;
	std::array <int, N> arr = readInput(sizeArr);
	std::vector <int> vec;

	fineGreaterThanAverage(arr, sizeArr, vec);
	printElements(vec);
	return 0;
}
std::array <int, N> readInput(int& size)
{
	std::array <int, N> arr;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
	return arr;
}
double avarageArrayElements(std::array <int, N>& arr, int size)
{
	double sum = 0;
	double avarageValue = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + arr[i];
	}
	avarageValue = sum / size;
	return avarageValue;
}
void fineGreaterThanAverage(std::array <int, N>& arr, int size, std::vector <int>& vec)
{
	double avarageValue = avarageArrayElements(arr, size);

	std::vector <int> tempVec;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > avarageValue)
		{
			tempVec.push_back(arr[i]);
		}
	}
	std::sort(tempVec.begin(), tempVec.end());
	int sizeTempVec = tempVec.size() - 1;
	while (vec.size() < 5)
	{
		vec.push_back(tempVec[sizeTempVec]);
		sizeTempVec--;
	}
}
void printElements(std::vector <int>& vec)
{
	if (vec.empty())
	{
		std::cout << "no" << std::endl;
	}
	else
	{
		for (int i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i] << std::endl;
		}
	}
}
//po burzo reshenie ot kolegite
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//	int nums, prints = 0;
//	double ave = 0;
//	std::cin >> nums;
//	std::vector<int> arr;
//	for (int i = 0; i < nums; i++)
//	{
//		int n;
//		std::cin >> n;
//		arr.push_back(n);
//		ave += n;
//	}
//	ave = ave / nums;
//	std::sort(arr.begin(), arr.end());
//	for (int i = nums - 1; (i >= nums - 6); i--)
//	{
//		int n = arr[i];
//		if (n > ave)
//		{
//			std::cout << n << " ";
//			prints++;
//		}
//		else break;
//	}
//	if (prints == 0) std::cout << "No";
//	return 0;
//}