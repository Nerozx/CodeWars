// CodeWARS.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

std::map<char, int> mapStr(std::string x);

bool isAnagram(std::string test, std::string original);

int main()
{

	std::cout << isAnagram("foefet", "toffee")<< std::endl;
	std::cout << isAnagram("Buckethead", "DeathCubeK")<< std::endl;
	std::cout << isAnagram("Twoo", "WooT")<< std::endl;
	std::cout << isAnagram("dumble", "bumble")<< std::endl;
	std::cout << isAnagram("around", "round")<< std::endl;
	std::cout << isAnagram("ound", "round")<< std::endl;
	std::cout << isAnagram("apple", "pale")<< std::endl;
	std::cout << isAnagram("apple", "appeal")<< std::endl;
	std::cout << isAnagram("apple", "appeal")<< std::endl;
	std::cout << isAnagram("", "")<< std::endl;
    return 0;
}

bool isAnagram(std::string test, std::string original) {
	if (test.size() != original.size()) {
		return false;
	}

	std::transform(test.begin(), test.end(), test.begin(), ::tolower);
	std::transform(original.begin(), original.end(), original.begin(), ::tolower);

	std::map<char, int> mapString = mapStr(test);
	std::map<char, int>::iterator it;

	for (int i = 0; i<original.size(); i++)
	{
		it = mapString.find(original.at(i));
		if (it == mapString.end()) {
			return false;
		}
		else if (it->second == 0)
		{
			return false;
		}
		else if (it->second != 0)
		{
			it->second--;
		}
	}
	return true;
}

std::map<char, int> mapStr(std::string x) {

	std::map<char, int> mapStr;
	std::map<char, int>::iterator it;

	for (int i = 0; i<x.size(); i++)
	{

		it = mapStr.find(x.at(i));
		if (it != mapStr.end())
		{
			it->second++;
		}
		else
		{
			mapStr.insert(std::pair<char, int>(x.at(i), 1));
		}

	}
	return mapStr;
}