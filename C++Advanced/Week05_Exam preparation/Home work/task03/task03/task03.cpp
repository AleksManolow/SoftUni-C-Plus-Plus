// task03
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
const int CITY_IDX = 0;
const int lATITUDE_IDX = 1;
const int LONGITUDE_IDX = 2;
const int ATTRIBUTES_COUNT = 3;
const std::string lineDelimiter = ".";
const char attributeDelimiter = ',';
std::vector<std::array <std::string, ATTRIBUTES_COUNT>> readCityAttributesFromInput()
{
	std::vector<std::array <std::string, ATTRIBUTES_COUNT>> attributes;
	std::string line;
	std::array <std::string, ATTRIBUTES_COUNT>currAttributes;
	while (true)
	{
		getline(std::cin, line);
		if (line == lineDelimiter)
		{
			break;
		}
		std::istringstream istr(line);
		getline(istr, currAttributes[CITY_IDX], attributeDelimiter);
		getline(istr, currAttributes[lATITUDE_IDX], attributeDelimiter);
		getline(istr, currAttributes[LONGITUDE_IDX], attributeDelimiter);
		attributes.push_back(currAttributes);
	}
	return attributes;
}
std::vector<std::string> readQueriesFromInput()
{
	std::vector<std::string>queries;
	std::string line;


	while (true)
	{
		getline(std::cin, line);
		if (line == lineDelimiter)
		{
			break;
		}
		queries.push_back(line);
	}
	return queries;
}
std::unordered_map<std::string, std::string> constructCityMap(
	std::vector<std::array <std::string, ATTRIBUTES_COUNT>> attributes)
{
	std::unordered_map<std::string, std::string> cityMap;

	std::string currCoordsStringified;
	for (const auto& currAttributs : attributes)
	{
		currCoordsStringified = currAttributs[lATITUDE_IDX];
		currCoordsStringified.append(",").append(currAttributs[LONGITUDE_IDX]);
		cityMap[currAttributs[CITY_IDX]] = currCoordsStringified;
	}


	return cityMap;
}
std::unordered_map<std::string, std::vector<std::string>> constructCoordMap(
	std::vector<std::array <std::string, ATTRIBUTES_COUNT>> attributes)
{
	std::unordered_map<std::string, std::vector<std::string>> coordMap;

	std::string currCoordsStringified;
	for (const auto& currAttributs : attributes)
	{
		currCoordsStringified = currAttributs[lATITUDE_IDX];
		currCoordsStringified.append(",").append(currAttributs[LONGITUDE_IDX]);
		coordMap[currCoordsStringified].push_back(currAttributs[CITY_IDX]);
	}

	return coordMap;
}
bool isCityQuery(const std::string& query)
{
	std::istringstream istr(query);
	const char delimiter = ' ';
	std::string a;
	getline(istr, a, delimiter);
	if (getline(istr, a, delimiter) && !a.empty())
	{
		return false;
	}
	return true;
}
std::string executesCityQuery(const std::unordered_map<std::string, std::string>& cityMap,
	const std::string& query)
{
	std::string result;
	auto it = cityMap.find(query);
	if (it == cityMap.end())
	{
		return result;
	}
	result = it->first;
	result.append(",").append(it->second).append("\n");

	return result;
}
std::string executesCoordsQuery(const std::unordered_map<std::string, std::vector<std::string>>& coordMap,
	const std::string& query)
{
	std::string result;
	const std::string prossesedQuery = [&query](){
	std::string prossesedQuery = query;
	std::replace(prossesedQuery.begin(), prossesedQuery.end(), ' ', ',');
	return prossesedQuery;
	}();
	auto it = coordMap.find(prossesedQuery);
	if (it == coordMap.end())
	{
		return result;
	}
	const auto& coord = it->first;
	const auto& cities = it->second;
	for (const auto& city : cities)
	{
		result.append(city).append(",").append(coord).append("\n");
	}
	return result;
}

 std::string executesSingleQuery(const std::unordered_map<std::string, std::string>& cityMap,
	const std::unordered_map<std::string, std::vector<std::string>>& coordMap,
	const std::string& query)
{
	 std::string result;
	 const bool isCity = isCityQuery(query);
	 if (isCity)
	 {
		 result = executesCityQuery(cityMap, query);
	 }
	 else
	 {
		 result = executesCoordsQuery(coordMap, query);
	 }
	 return result;
}
std::vector < std::string> executeQueries(const std::unordered_map<std::string, std::string>& cityMap,
	const std::unordered_map<std::string, std::vector<std::string>>& coordMap,
	const std::vector<std::string>& queries)
{
	std::vector < std::string> results(queries.size());
	for (int i = 0; i < queries.size(); i++)
	{
		results[i] = executesSingleQuery(cityMap, coordMap, queries[i]);
	}
	return results;
}
void printResults(const std::vector <std::string>& results)
{
	for (std::string result : results)
	{
		std::cout << result;
	}
}
int main()
{
	const auto attributes = readCityAttributesFromInput();
	const auto queries = readQueriesFromInput();
	const auto cityMap = constructCityMap(attributes);
	const auto coordMap = constructCoordMap(attributes);
	const auto results = executeQueries(cityMap, coordMap, queries);
	printResults(results);

	return 0;
}

