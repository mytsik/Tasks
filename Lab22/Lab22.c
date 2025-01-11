#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define SIZE 1000

typedef double(*TFun)(double);

double fun1(double);
double fun2(double);
double fun3(double);
void t_rez(TFun, double, double, double);
void v_rez(TFun, double);
void o_rez(TFun, double, double, double);

void main()
{
	setlocale(LC_ALL, "RUS");
	printf("МЕНЮ\n");

	int choice_fun;
	printf("Выберите функцию(введите цифру):\n1 - S(x)\n2 - V(x)\n3 - Y(x)\n\n");
	scanf_s("%d", &choice_fun);
	int choice_act;
	printf("Выберите действие(введите цифру):\n1 - вычислить значение\n2 - табулировать\n3 - выполнить операцию\n4 - выход\n");
	scanf_s("%d", &choice_act);

	switch (choice_act)
	{
		case 1: 
		{
			double x;
			puts("Введите значение x:");
			scanf("%lf", &x);
			switch (choice_fun)
			{
				case 1:
				{
					v_rez(fun1, x);
					break;
				}
				case 2:
				{
					v_rez(fun2, x);
					break;
				}
				case 3:
				{
					v_rez(fun3, x);
					break;
				}
				default:
					printf("Введенный вами вариант отсутствует\n");
			}
			break;
		}
		case 2:
		{
			double begin, end, step;
			puts("Введите начальное значение, конечное значение и значение шага:");
			scanf("%lf%lf%lf", &begin, &end, &step);
			switch (choice_fun)
			{
				case 1: 
				{
					t_rez(fun1, begin, end, step);
					break;
				}					
				case 2:
				{
					t_rez(fun2, begin, end, step);
					break;
				}					
				case 3: 
				{
					t_rez(fun3, begin, end, step);
					break;
				}
				default:
					printf("Введенный вами вариант отсутствует\n");					
			}
			break;
		}
		case 3:
		{
			double begin, end, step;
			puts("Введите начальное значение, конечное значение и значение шага:");
			scanf("%lf%lf%lf", &begin, &end, &step);
			switch (choice_fun)
			{
			case 1:
			{
				o_rez(fun1, begin, end, step);
				break;
			}
			case 2:
			{
				o_rez(fun2, begin, end, step);
				break;
			}
			case 3:
			{
				o_rez(fun3, begin, end, step);
				break;
			}
			default:
				printf("Введенный вами вариант отсутствует\n");
			}
			break;
		}
		default:
			printf("Введенный вами вариант отсутствует\n");
	}
	
}

double fun1(double r) {
	if (r <= 0) 
	{
		printf("x должен быть больше 0\n");
		return 0;  
	}
	else
		return log(fabs(sqrt(pow(r, 3))));
}

double fun2(double r) {
	
	if (r > 1)
		return sqrt(tan(pow(r, 2) - 1));
	else if (0 <= r <= 1)
		return -2 * r;
	else if (r < 0)
		return exp(cos(r));
}

double fun3(double r) {
	return (r - 1) / (r + 1) + pow(((r - 1) / (r + 1)), 3) / 3 + pow(((r - 1) / (r + 1)), 5) / 5 + pow(((r - 1) / (r + 1)), 7) / 7;
}

void t_rez(TFun f, double begin, double end, double step)
{
	for (double x = begin; x <= end; x += step)
		printf(" x = %5.2lf, y = %8.4lf\n", x, f(x));
}

void v_rez(TFun f, double x)
{
	printf(" x = %5.2lf, y = %8.4lf\n", x, f(x));		
}

void o_rez(TFun f, double begin, double end, double step)
{
	double arr[SIZE][4];
	int i = 0;//индекс строк
	for (double x = begin; x <= end; x += step, i++)
	{
		arr[i][0] = x;
		arr[i][1] = end;
		arr[i][2] = step;
		arr[i][3] = f(x);

		printf("%5.2lf %5.2lf %5.2lf %8.4lf\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
	}		
}