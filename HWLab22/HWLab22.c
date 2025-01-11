#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef double (*TFun)(double x); // ��� ��������� �� �������

double derivative(TFun f, double x, double h) // ������� ��� ���������� ���������� ����������� ������� �������� ���������
{
    return (f(x + h) - f(x - h)) / (2 * h);
}

int action(TFun prtf, double xmin, double xmax) // ������� ��� ������ ��������� �� ������� ����������
{
    setlocale(LC_ALL, "RUS");

    const double h = 1e-5; // ��� ��� ���������� �����������������
    double x = xmin;
    double fx = prtf(x);  // �������� ������� � ����� x
    double fprime = derivative(prtf, x, h); // ����������� ������� � ����� x

    printf("������ ���������: x = %lf, f(x) = %lf, f'(x) = %lf\n", x, fx, fprime);

    // ���� ��������� �� ��������� [xmin, xmax]
    while (x <= xmax) 
    {
        double fprime_next = derivative(prtf, x + h, h); // ����������� � ��������� �����
        if ((fprime > 0 && fprime_next < 0) || (fprime < 0 && fprime_next > 0)) 
        {            
            printf("������ ��������� �� ��������� [%lf, %lf]\n", xmin, x + h); // ���� ����������� ������ ����, ����� ���������
            //return;
        }
        fprime = fprime_next;
        x += h;
    }

    printf("��������� �� ������ �� ��������� [%lf, %lf]\n", xmin, xmax);
    return 1;
}

// ������ ������� ��� ������������
double example_func(double x) 
{
    return x * x - 4 * x + 3; // ������ �������: f(x) = x^2 - 4x + 3
}

void main() 
{
    double xmin = 0.0;
    double xmax = 5.0;

    // �������� ������� action � ��������� �������� example_func
    action(example_func, xmin, xmax);
}

