// task07
#include<iostream>
#include<array>
#include<set>
#include <vector>
const int size = 1000;
std::array<int, size> readArrInput(int numberOfElements);
std::set<int> uniqueElementInArr(std::array<int, size>& arr, int numberOfElements);
std::vector<int> identicalElements(std::set<int>& uniqueElements1, std::set<int>& uniqueElements2);
void printSolution(std::vector<int>& identEl, std::array<int, size>& arr1);
int main()
{
	int n = 0;
	int m = 0;
	std::cin >> n >> m;
	std::array<int, size> arr1 = readArrInput(n);
	std::array<int, size> arr2 = readArrInput(m);

	std::set<int> uniqueElements1 = uniqueElementInArr(arr1, n);
	std::set<int> uniqueElements2 = uniqueElementInArr(arr2, m);

	std::vector<int> identEl = identicalElements(uniqueElements1, uniqueElements2);

	printSolution(identEl, arr1);

	return 0;
}
std::array<int, size> readArrInput(int numberOfElements)
{
	std::array<int, size> arr;
	for (int i = 0; i < numberOfElements; i++)
	{
		std::cin >> arr[i];
	}
	return arr;
}
std::set<int> uniqueElementInArr(std::array<int, size>& arr, int numberOfElements)
{
	std::set<int> uniqueElements;
	for (int i = 0; i < numberOfElements ; i++)
	{
		uniqueElements.insert(arr[i]);
	}
	return uniqueElements;
}
std::vector<int> identicalElements(std::set<int>& uniqueElements1, std::set<int>& uniqueElements2)
{
	std::vector<int> identEl;
	for (auto elements1 : uniqueElements1)
	{
		for (auto elements2 : uniqueElements2)
		{
			if (elements1 == elements2)
			{
				identEl.push_back(elements1);
			}
		}
	}
	return identEl;
}
void printSolution(std::vector<int>& identEl, std::array<int, size>& arr1)
{
	std::set<int> helpSort;
	for (int elInArr : arr1)
	{
		for (int elInVec : identEl)
		{
			if (elInArr == elInVec && helpSort.find(elInArr) == helpSort.end())
			{
				helpSort.insert(elInArr);
				std::cout << elInVec << " ";
			}
		}
	}
}

