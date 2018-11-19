// AssertionLab.cpp : Defines the entry point for the console application.
//
#include <iostream>
//#include <assert.h>
#include <stdio.h>
#include <vector>
#include "stdafx.h"
#include "Test.h"
#include <time.h>
#include "App.h"

using namespace std;

int main()
{
	srand(time(NULL));
	App user;
	int input;
	int score = 0;
	int count = 0;
	std::cout << "Enter six random numbers between 0-46" << std::endl;
	//test vector
	std::vector<int> v;

	while ((cin >> input) && count < 5)
	{
		v.push_back(input);
		count++;
	}

	Test t;

	//Generatated Vector
	std::vector<int> vec;
	for (int i = 0; i < 6; i++)
	{
		int random = rand() % 46 + 1;
		vec.push_back(random);
		while (t.duplicates(vec) == false)
		{
			vec.pop_back();
			random = rand() % 46 + 1;
			vec.push_back(random);
		}
		
	}

	
	//Game
	if (user.sizeRange(v) == false)
	{
		v.clear();

		std::cout << "Not enough: please re enter your unique numbers between 0-46" << std::endl;
		count = 0;
		while ((cin >> input) && count < 6)
		{
			v.push_back(input);
			count++;
			std::cout << " count is: " + count << std::endl;
		}
	}
	
	if (user.duplicates(v) == false)
	{
		v.clear();
		std::cout << " Duplicate: please re enter your unique numbers between 0-46" << std::endl;
		count = 0;
		while ((cin >> input) && count < 5)
		{
			v.push_back(input);
			count++;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		std::cout << vec[i] << "\n";
	}

	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (v[i] == vec[j])
			{
				score++;
				
			}
		}
		std::cout << "You got " << score << " number(s) correct" << std::endl;
	}
	system("pause");
	//test obj
	//Test t;

	//std::vector<int> v;
	//v.push_back(0);
	//v.push_back(0);
	//v.push_back(0);
	//v.push_back(0);
	//v.push_back(0);
	//v.push_back(0);

	//assert(t.range(v) == 0);
	//assert(t.duplicates(v) == 1);
	//assert(t.size(v) == 0);
    return 0;
	
}

