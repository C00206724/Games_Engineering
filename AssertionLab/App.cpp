#include "stdafx.h"
#include "App.h"


App::App()
{
}


bool App::sizeRange(std::vector<int> & v)
{

	for (int i = 0; i < 6; i++)
	{
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
}

bool App::duplicates(std::vector<int> & v)
{
	auto it = std::unique(v.begin(), v.end());
	bool unique = (it == v.end());
	if (unique)
	{
		std::cout << "six different numbers" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Duplicates found, please try again" << std::endl;
		return false;
	}
}
