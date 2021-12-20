// TrigFunc_Kursovaya_4kurs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <ctime>
using namespace std;
#define M_PI 3.14159265358979323846

int main(int argc, char** argv)
{
	int rank, size;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size); //кол-во запущен процессов (size)
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// can't count pi, pi/2, 3*pi/2, 2*pi 
	int i = 0, rows = 1000;

	double x = 5 * M_PI / 12;

	double sinus = 0, cosinus = 0;
	int temp = 0, temp2 = 0;
	int a = -1, a2 = -1;
	double denom = 1, denom2 = 1;

	double t1 = MPI_Wtime();

	int k = rows / size;
	int start = rank * k; // если 1 процесс то стартовая позиция = 25
	int stop = ((rank + 1) * k);
	if (rank == size - 1) stop = rows;

	MPI_Bcast(&sinus, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	MPI_Bcast(&cosinus, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	for (i = start; i < stop; i++)
	{
		// sin
		temp = 2 * i + 1;
		for (int j = 1; j <= temp; j++)
		{
			denom *= j;
		}
		sinus += (pow(-1, i) * pow(x, temp)) / denom;

		// cos
		temp2 = 2 * i;
		for (int j = 1; j <= temp2; j++)
		{
			denom2 *= j;
		}
		cosinus += (pow(-1, i) * pow(x, temp2)) / denom2;
		denom = denom2 = 1;
	}

	double total_sin = 0, total_cos = 0;

	MPI_Reduce(&sinus, &total_sin, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&cosinus, &total_cos, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	double t2 = MPI_Wtime() - t1;

	if (rank == 0)
	{
		cout << "sinus = " << total_sin << endl;
		cout << "sin(x) = " << sin(x) << endl << endl;

		cout << "cosinus = " << total_cos << endl;
		cout << "cos(x) = " << cos(x) << endl << endl;

		cout << "time = " << t2 << endl;
	}

	MPI_Finalize();
	return 0;
}
