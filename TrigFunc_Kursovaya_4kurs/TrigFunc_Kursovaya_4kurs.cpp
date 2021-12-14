// TrigFunc_Kursovaya_4kurs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

#include "sercantutar-infint-fc767ed/InfInt.h"

int main()
{
	InfInt myint1;
    InfInt myint2;

	// n <= 110
	int n = 110, i = 0, j = 0, temp = 0, a = -1;
	double denom = 1;
	double x = 5, sinus = 0, cosinus = 0;

	/*cout << "x = ";
	cin >> x;*/

	unsigned int start_time = clock();

	// sin
	for (i = 0; i < n; i++)
	{
		temp = 2 * i + 1;
		if (i > 0)
		{
			denom *= (temp - 1) * temp; // факториал denom = (2n+1)!
		}
		a *= -1;

		sinus += (a * pow(x, temp)) / denom;
	}

	// cos
	a = -1;
	denom = 1;
	for (i = 0; i < n; i++)
	{
		temp = 2 * i;
		if (i > 0)
		{
			denom *= (temp - 1) * temp; // факториал denom = (2n+1)!
		}
		a *= -1;
		cosinus += (a * pow(x, temp)) / denom;
	}

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;

	cout << "sinus = " << sinus << endl;
	cout << "cosinus = " << cosinus << endl;
	cout << "time = " << search_time / 1000 << endl;
}