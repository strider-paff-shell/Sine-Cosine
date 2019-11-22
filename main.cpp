#include <iostream>
#include <math.h>

long long int factorial(unsigned n)
{
    long long int f = 1;
    for(int i = 1; i <= n; i++)
        f *= i;

    return f;
}

double correct_value(double x)
{
	while(x > 2*M_PI)
        x -=2*M_PI;

    while(x < -2*M_PI)
        x +=2*M_PI;

    return x;
}

double my_sin(double x)
{
	double y = 0.0;
	x = correct_value(x);
	for(int n = 0; n < 10; n++)
	{
		y += (pow(-1, n) / factorial((2*n)+1)) * pow(x, (2*n)+1);
	}

	return y;
}

double my_cos(double x)
{
	double y = 0.0;
    x = correct_value(x);
	for(int n = 0; n < 10; n++)
	{
		y += (pow(-1, n) / factorial(2*n))*pow(x, 2*n);
	}

	return y;
}

int main()
{
	double values[7] = {0, M_PI/2.0, M_PI, (3./2.)*M_PI, 2*M_PI, M_PI/4., M_PI + (M_PI/4.)};
	for(int i = -20; i < 20; i++)
	{
		std::cout << "sin(" << i << ") = " << my_sin(double(i)) << 
		             "\t\tcos(" << i << ") = " << my_cos(double(i)) 
		          << std::endl;
	}

	for(int i = 0; i < 7; i++)
	{
		std::cout << "sin(" << values[i] << ") = " << my_sin(double(values[i])) << 
		             "\t\tcos(" << values[i] << ") = " << my_cos(double(values[i])) 
		          << std::endl;
	}
	return 0;
}