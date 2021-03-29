// Lotto_Simulator_Anfang.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <istream>
#include <ctime>
#include <sstream>
#include <map>
#include <windows.h>
#include "randutils.h"


using namespace std;


int main()

{
	int r = NULL;
	int num = NULL;
	int i = NULL;
	int counter = 0;
	std::string str;
	size_t total = 0;
	int array[6] = { 0,0,0,0,0,0 };
	int user[6] = { 0, 0, 0, 0,
							 0, 0 };
	size_t n = sizeof(array) / sizeof(array[0]);
	std::map<int, int> m;
	randutils::mt19937_rng rng;
	randutils::mt19937_rng rng_explict_seed_seq{ randutils::auto_seed_128{} };

	std::mt19937 rng_engine{ randutils::auto_seed_128{}.base() };
	std::uniform_int_distribution<int> dist{ 1,49 };
	/*
	* std::mt19937 rng_engine{randutils::auto_seed_128{}.base()};
      std::uniform_int_distribution<char> dist{'A','D'};
      char grade = dist(rng_engine);
	

	for (int i = 1; i < 16; ++i)
		std::cout << "[0," << i + 1 << "]:\t" << dist(rng_engine) << "\n";   */

	
	while (user[0] == 0)
	{
 		std::cout << "Please enter your first lotto number: \n";
		cin >> str;
		int t = stoi(str);
		if (t > 0 && t < 50 && user[0] == 0)
		{
			user[0] = t;
		}
	} 


	while (user[1] == 0)
	{
		std::cout << "Please enter your second lotto number: \n";
		cin >> str;
		int t = stoi(str);
		if (t > 0 && t < 50 && t != user[0] && user[1] == 0)
		{
			user[1] = t;
		}
	}
	while (user[2] == 0)
	{
		std::cout << "Please enter your third lotto number: \n";
		cin >> str;
		int t = stoi(str);
		if (t > 0 && t < 50 && t != user[0] && t != user[1] && user[2] == 0)
		{
			user[2] = t;
		}
	}
	while (user[3] == 0)
	{
		std::cout << "Please enter your fourth lotto number: \n";
		cin >> str;
		int t = stoi(str);
		if (t > 0 && t < 50 && t != user[0] && t != user[1] && t != user[2] && user[3] == 0)
		{
			user[3] = t;
		}
	}
	while (user[4] == 0)
	{
		std::cout << "Please enter your fifth lotto number: \n";
		cin >> str;
		int t = stoi(str);
		if (t > 0 && t < 50 && t != user[0] && t != user[1] && t != user[2] && t != user[3] && user[4] == 0)
		{
			user[4] = t;
		}
	}
	while (user[5] == 0)
	{
		std::cout << "Please enter your sixth lotto number: \n";
		cin >> str;
		int t = stoi(str);
		if (t > 0 && t < 50 && t != user[0] && t != user[1] && t != user[2] && t != user[3] && t != user[4] && user[5] == 0)
		{
			user[5] = t;
			std::cout << endl;
		}
	}

	std::cout.flush();

//	for (size_t i = 0; i < n; i++) {
//		std::cout << user[i] << ' ';
//	}

	do {

		//srand(time(NULL)); //r = rand();
		//num = rng.uniform(1, 49); randutils.h
		num = dist(rng_engine);
		
		if (num <= 49 && num > 0 && array[0] == 0)
		{
			array[0] = num;
			// std::cout << num << endl;
		}
		else if (num <= 49 && num > 0 && array[1] == 0 && num != array[0])
		{
			array[1] = num;
			// std::cout << num << endl;
		}
		else if (num <= 49 && num > 0 && num != array[0] && num != array[1] && array[2] == 0)
		{
			array[2] = num;
			// std::cout << num << endl;
		}
		else if (num <= 49 && num > 0 && num != array[0] && num != array[1] && num != array[2] && array[3] == 0)
		{
			array[3] = num;
			// std::cout << num << endl;
		}
		else if (num <= 49 && num > 0 && num != array[0] && num != array[1] && num != array[2] && num != array[3] && array[4] == 0)
		{
			array[4] = num;
			// std::cout << num << endl;
		}
		else if (num <= 49 && num > 0 && num != array[0] && num != array[1] && num != array[2] && num != array[3] && num != array[4] && array[5] == 0)
		{
			array[5] = num;

			for (const auto& item : user) ++m[item];            // beide arrays in die map<int, int> kopieren
			for (const auto& item : array) ++m[item];			// zzum Vergleich

			for (const auto& item : m) total += item.second / 2;
			
		
			if (total <= 5)
			{
				counter++;
				m.clear();
				total = 0;
				if (counter % 10000 == 0)
				{
					std::cout.flush() << '\r';
					std::cout << counter << " Games";
				}

				for (size_t b = 0; b < 6; b++)
				{
					array[b] = 0;
				}
			}
		}
		else
		{
			// hit when rand choose number twice !!!
		}

	} while (total <= 5);


	std::cout.flush() << '\r';

	for (size_t i = 0; i < n; i++)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << endl;
	std::cout << endl;

	std::cout << total << " Lucky numbers after " << counter << " games." << '\n';
	std::cout << "The number of pairs of equal elements is " << total << '\n';

	return 0;

}
