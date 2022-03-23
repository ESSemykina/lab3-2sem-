/*2.	Найдите корень уравнения(x - 3) ^ 3 = 0 с точностью до 10 ^ -4 с помощью бисекции.*/
#include <iostream>
#include <math.h>

double f(double x)
{
	return pow((x - 3), 3);
}

double bisection(double a, double b, double eps)
{
	double x;
	while (1)
	{
		double x = (a + b) / 2;
		if ((abs(x - a) < eps) || (abs(x - b) < eps))
			return x;
		if ((f(a) * f(x)) > 0)
			a = x;
		else
			b = x;
	}
}
int main()
{
	double eps = pow(10, -4);
	std::cout << bisection(0, INT_MAX, eps);
}
//ответ 3.00006