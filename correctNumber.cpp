// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <math.h>

using namespace std;

enum Level {
	Easy = 1,
	Medium,
	Hard,
};

class Randomizer
{
public:
	void initialize()
	{
		srand(time(NULL));
	}
	int getRandom(int max)
	{
		return rand() % (max + 1);
	}
	int getRandom(int min, int max)
	{
		int diff = max - min;
		return min + rand() % diff;
	}
};

class wartosci
{
public:
	int value;
	int flag = 0;
	void fun(int x, int getValue)
	{
		if (x > getValue) cout << "This number is smaller" << endl;
		else if (getValue > x) cout << "This number is higher" << endl;
		else
		{
			cout << "Correct!" << endl;
			flag = 1;
		}
	}
};


int main()
{
	start:
	int number;
	char sign;
	cout << "Choose the level: " << endl;
	cout << Level(Easy) << "<- Easy " << endl;
	cout << Level(Medium) << "<- Medium " << endl;
	cout << Level(Hard) << "<- Hard" << endl;
	cin >> number;
	if (number > 3 || number < 1)
	{
		cout << "Wrong value given " << endl;
		goto start;
	}
	else
	{
		int random;
		int value;
		Randomizer r;
		wartosci s;
		r.initialize();
		random = r.getRandom(1, pow((int)10, number));
		//cout << random << endl; /// <-drawn number
		while (1)
		{
			cout << "Input a number: " << endl;
			cin >> value;
			s.fun(value, random);
			if (s.flag) break;
		}
		cout << "Would you like to play again?" << endl;
		cout << "y<- Yes" << endl;
		cout << "n<- No" << endl;
		cin >> sign;
		if (sign == 'y') goto start;
	}
    return 0;
}

