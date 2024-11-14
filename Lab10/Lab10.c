#include <stdio.h>
#include <locale.h>
#include <math.h>


double fa(double x)
{
	double y;

	if (x <= 3) 
		y = pow(x, 2) - 3 * x + 9;
	else if(x > 3)
		y = 1 / (pow(x, 3) + 3);

	return y;
}

double fb(double x)
{
	double y;

	y = x * exp(sin(pow(x, 2)));

	return y;
}

int factorial(int num) 
{
	int fact = 1;
	for (int i = 1; i <= num; i++) 
		fact *= i;
	return fact;
}

double sin_n(double x, int N)
{
	double result = 0;
	double member;	

	for (int k = 0; k < N; k++) 
	{		
		member = pow(-1, k - 1) * (pow(x, 2 * k - 1) / factorial(2 * k - 1));
		result += member;
	}

	return result;
}

double sin_eps(double x, double eps)
{
	double result = 0;
	double member = x; 	

	for (int k = 1;fabs(member) >= eps; k++)
	{
		result += member;		
		member = pow(-1, k - 1) * (pow(x, 2 * k - 1) / factorial(2 * k - 1));
	}

	return result;
}

void main()
{
	setlocale(LC_ALL, "RUS");
	double x;
	printf("������� �������� x\n");
	scanf_s("%lf\n", &x);
	printf("fa(x)=%.2lf , fb(x)=%.2lf \n", fa(x), fb(x));
	printf("������������: %.2lf\n�������� ���������: %.2lf\n��������� �����: %.2lf\n", fa(x) * fb(x), pow(fa(x),2) - pow(fb(x), 2), 2 * (fa(x) + fb(x)));
	
	double x2;
	printf("\n������� �������� x2\n");
	scanf_s(" %lf\n", &x2);

	int N;
	printf("\n������� ����� ����������� k-� ������ ����\n");
	scanf_s(" %d\n", &N);

	double eps;
	printf("\n������� �������� ����������\n");
	scanf_s(" %lf\n", &eps);

	printf("sin(x2) � ������� ������� sin(x) ����������� ���������� ����� ��: %.2lf\n", sin(x2));
	printf("sin(x2) ����� �������� ����������� �������, ����������� �������� ��� ����� ����: %.2lf\n", sin_n(x2, N));
	printf("sin(x2) ����� �������� ����������� �������, ����������� �������� ����� ��� ��������� � �������� ������������� ���������: %.2lf\n", sin_eps(x2, eps));
}