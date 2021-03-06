// Bakery.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <iostream>
#include <vector>
#include <queue>
#include <mutex>

bool flag[2];
int turn;

const int AMOUNT = 4;

int in[AMOUNT];
int last[AMOUNT];

std::vector<std::thread> m_threads;

void cs(void * s) 
{
	int n = (int)s;
	while (true)
	{

		for (int i = 0; i < AMOUNT; i++)
		{
			in[n] = i;
			last[i] = n;

			for (int k = 0; k < AMOUNT; k++)
			{
				if (k != n)
				{
					while (in[k] >= in[n] && last[i] == n)
					{

					}
				}
			}
		}
		std::cout << "Number: " << n << std::endl;
		in[n] = 0;
	}
}


int main()
{
	for (int i = 0; i < AMOUNT; i++)
	{
		m_threads.push_back(std::thread(cs, (void*)i));
	}

	for (int i = 0; i < AMOUNT; i++)
	{
		m_threads[i].join();
	}

	return 0;
}

