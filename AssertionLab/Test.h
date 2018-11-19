#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <string>
#include <cctype>

class Test
{
	std::vector<int> vec;

public:
	Test();
	~Test();
	bool size(std::vector<int> v);
	bool duplicates(std::vector<int> v);
	bool range(std::vector<int> v);

};

