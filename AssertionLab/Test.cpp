#include "stdafx.h"
#include "Test.h"


Test::Test()
{
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
}


Test::~Test()
{
}

bool Test::size(std::vector<int> v)
{
	if (v.size() == 6)
	{
		std::cout << "Vector size of 6" << std::endl;
		return false;
	}
	else {
		std::cout << "Vector less than or greater than 6" << std::endl;
		return true;
	}
}

bool Test::duplicates(std::vector<int> v)
{
	
		std::sort(v.begin(), v.end()); 
 		auto last = std::unique(v.begin(), v.end());
		bool wasUnique = (last == v.end());
		return wasUnique;
		/*if (last == v.end())
		{
			std::cout << "Duplicates found" << std::endl;
			return false;
		}
		else {
			std::cout << "No Duplicates found" << std::endl;
			return true;
		}*/
}

bool Test::range(std::vector<int> v)
{
	for (int i = 0; i <= 6; i++)
		if (v[i] <= 46 || v[i] >= 0)
		{
			std::cout << "The range of nubers is between 0-46" << std::endl;
			return true;
		}
		else
		{
			std::cout << "The range of nubers is not between 0-46" << std::endl;
			return false;
		}
}