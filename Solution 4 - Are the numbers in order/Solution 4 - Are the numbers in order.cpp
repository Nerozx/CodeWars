#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

bool isAscOrder(std::vector<int> arr)
{
	if (arr.size() == 1)
	{
		return true;
	}

	std::vector<int> cpy = arr;
	std::sort(cpy.begin(), cpy.end(), std::less<int>());

	if (cpy == arr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main() {

	std::cout << isAscOrder({ 1, 2 , 3 }) << std::endl;
	char a;
	std::cin >> a;
	return 0;
}