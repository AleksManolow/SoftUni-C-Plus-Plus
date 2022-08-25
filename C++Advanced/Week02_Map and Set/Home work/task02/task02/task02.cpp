// task02
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <unordered_map>;
#include <unordered_set>;
std::vector<std::string> readINput();
void uppercase(std::vector<std::string>& words);
std::unordered_map<std::string, int> produceCountMap(std::vector<std::string>& words);
std::vector<std::string> produceAnswerWords(std::unordered_map<std::string, int>& countMap,
	std::vector<std::string>& words);
void printSolution(std::vector<std::string> answerWords);
int main()
{
	std::vector<std::string> words = readINput();
	uppercase(words);
	std::unordered_map<std::string, int> countMap = produceCountMap(words);
	std::vector<std::string> answerWords = produceAnswerWords(countMap, words);
	printSolution(answerWords);

	return 0;
}
std::vector<std::string> readINput()
{
	std::vector<std::string> words;
	std::string line;
	getline(std::cin, line);
	std::istringstream istr(line);

	std::string currWord;
	while (istr >> currWord)
	{
		words.push_back(currWord);
	}
	return words;
}
char toLower(char alpha)
{
	return tolower(alpha);
}
void uppercase(std::vector<std::string>& words)
{
	for (std::string& word:words)
	{
		std::transform(word.begin(), word.end(), word.begin(), toLower);
	}
}
std::unordered_map<std::string, int> produceCountMap(std::vector<std::string>& words)
{
	std::unordered_map<std::string, int> countMap;
	for(std::string word:words)
	{
		countMap[word]++;
	}
	return countMap;
}
std::vector<std::string> produceAnswerWords(std::unordered_map<std::string, int>& countMap,
											std::vector<std::string>& words)
{
	std::vector<std::string> answerWords;
	std::unordered_set<std::string> uniqueWordsWithOddCount;

	for (std::string word:words)
	{
		auto it = countMap.find(word);
		bool hasOddCount = it->second & 1;
		if (hasOddCount)
		{
			if (uniqueWordsWithOddCount.find(it->first) == uniqueWordsWithOddCount.end())
			{
				uniqueWordsWithOddCount.insert(it->first);
				answerWords.push_back(it->first);
			}
		}
	}
	return answerWords;
}
void printSolution(std::vector<std::string> answerWords)
{	
	std::ostringstream ostr;
	for (std::string word:answerWords)
	{
		ostr<< word << ", ";
	}
	std::string answer = ostr.str();
	answer.pop_back();
	answer.pop_back();
	std::cout << answer;
}