
#include <iostream>
#include <vector>
#include <map>

std::map<int, int> mapVector(std::vector<int> arr)
{
	std::map<int, int> myMap;
	std::map<int, int>::iterator myIterator;

	for (int i = 0; i < arr.size(); i++)
	{
		myIterator = myMap.find(arr.at(i));
		if (myIterator != myMap.end())
		{
			myIterator->second++;
		}
		else
		{
			myMap.insert(std::pair<int, int>(arr.at(i), 1));
		}
	}
	return myMap;
}

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
	std::map<int, int> myMap = mapVector(arr);
	std::map<int, int>::iterator myIterator;

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		myIterator = myMap.find(arr.at(i));
		
		if (myIterator->second > n)
		{
			arr.erase(arr.begin()+i);
			myIterator->second--;
		}
	}

	return arr;
}


int main() {

	std::vector<int> testVector = deleteNth({ 1,1,3,3,7,2,2,2,2 }, 3);

	for (int i = 0; i < testVector.size(); i++)
	{
		std::cout << testVector.at(i) << " ";
	}

	return 0;
}