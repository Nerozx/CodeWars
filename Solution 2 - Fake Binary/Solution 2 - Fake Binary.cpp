// Solution 2 - Fake Binary.cpp : Defines the entry point for the console application.
//


#include <string>
#include <iostream>
#include <algorithm>
std::string fakeBin(std::string str);

int main()
{
	std::string test = fakeBin("45385593107843568");
	std::cout << test << std::endl;
	if (test == "01011110001100111")
	{
		std::cout << "True" << std::endl;
	}
	else
	{
		std::cout << "False" << std::endl;
	}
	
    return 0;
}

bool IsLess(char i) {
	return ((i - '0') < 5) ? 1 : 0;
}
bool IsMore(char i) {
	return ((i - '0') > 4 ? 1 : 0);
}

std::string fakeBin(std::string str) {
	
/*	for (int i = 0; i < str.size(); i++)
	{
		if (str.at(i) < '5')
		{
			str.at(i) = '0';
		}
		else
		{
			str.at(i) = '1';
		}
	} */
	
	std::replace_if(str.begin(), str.end(), IsLess,'0');
	std::replace_if(str.begin(), str.end(), IsMore,'1');
	
	return str;
}
