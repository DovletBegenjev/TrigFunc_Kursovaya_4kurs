// TrigFunc_Kursovaya_4kurs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;
#define M_PI 3.14159265358979323846

int main()
{
	// can't count pi, pi/2, 3*pi/2, 2*pi 
	int i = 0, j = 0, temp = 0, a = -1;

	double x = 2*M_PI/3;
	double e = 0; // e <= -323

	double denom = 1, b = x, sinus = 0, cosinus = 0;

	/*cout << "x = ";
	cin >> x;*/

	double start_time = clock();
	for (j = 0; j < 323; j++)
	{
		e = pow(10, -j);
		a = -1;
		denom = 1;
		b = x;
		i = 0;
		sinus = cosinus = 0;

		// sin
		while (abs(b) > e)
		{
			temp = 2 * i + 1;
			if (i > 0)
			{
				denom *= (temp - 1) * temp; // факториал denom = (2n+1)!
				a *= -1;
			}
			b = (a * pow(x, temp)) / denom;
			sinus += b;
			++i;
		}

		a = -1;
		denom = 1;
		b = x;
		i = 0;

		// cos
		while (abs(b) > e)
		{
			temp = 2 * i;
			if (i > 0)
			{
				denom *= (temp - 1) * temp; // факториал denom = (2n+1)!
				a *= -1;
			}
			b = (a * pow(x, temp)) / denom;
			cosinus += b;
			++i;
		}

		/*cout << "sinus = " << -sinus << endl;
		cout << "sin(x) = " << sin(x) << endl << endl;

		cout << "cosinus = " << -cosinus << endl;
		cout << "cos(x) = " << cos(x) << endl << endl;*/
	}

	double end_time = clock();
	double search_time = end_time - start_time;

	cout << "sinus = " << -sinus << endl;
	cout << "sin(x) = " << sin(x) << endl << endl;

	cout << "cosinus = " << -cosinus << endl;
	cout << "cos(x) = " << cos(x) << endl << endl;

	cout << "time = " << search_time / 1000 << endl;
}
