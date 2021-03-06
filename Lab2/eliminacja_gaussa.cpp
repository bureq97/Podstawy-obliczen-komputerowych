#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double eps = 1e-12; // sta³a przybli¿enia zera

// Funkcja realizuje algorytm eliminacji Gaussa
bool gauss(int n, double** AB, double* X)
{

	int i, j, k;
	double m, s;

	// eliminacja wspó³czynników

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (fabs(AB[i][i]) < eps) return false;
			m = -AB[j][i] / AB[i][i];
			for (k = i + 1; k <= n; k++)
				AB[j][k] += m * AB[i][k];
		}
	}

	// obliczanie niewiadomych

	for (i = n - 1; i >= 0; i--)
	{
		s = AB[i][n];
		for (j = n - 1; j >= i + 1; j--)
			s -= AB[i][j] * X[j];
		if (fabs(AB[i][i]) < eps) return false;
		X[i] = s / AB[i][i];
	}
	return true;
}

int main()
{
	double** AB, * X;
	int      n, i, j;

	cout << setprecision(4) << fixed;

	// odczytujemy liczbê niewiadomych

	cout << "Podaj liczbê niewiadomych: ";
	cin >> n;

	// tworzymy macierze AB i X

	AB = new double* [n];
	X = new double[n];

	for (i = 0; i < n; i++) AB[i] = new double[n + 1];

	// odczytujemy dane dla macierzy AB

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			cout << "a" << i + 1 << j + 1<<" = ";
			cin >> AB[i][j];
		}
	}

	if (gauss(n, AB, X))
	{
		for (i = 0; i < n; i++)
			cout << "x" << i + 1 << " = " << setw(9) << X[i]
			<< endl;
	}
	else
		cout << "dzielnik zero\n";

	// usuwamnie macierzy z pamiêci

	for (i = 0; i < n; i++) delete[] AB[i];
	delete[] AB;
	delete[] X;

	return 0;
}
