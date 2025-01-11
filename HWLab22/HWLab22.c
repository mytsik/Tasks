#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef double (*TFun)(double x); // Тип указателя на функцию

double derivative(TFun f, double x, double h) // Функция для численного вычисления производной методом конечных разностей
{
    return (f(x + h) - f(x - h)) / (2 * h);
}

int action(TFun prtf, double xmin, double xmax) // Функция для поиска интервала до первого экстремума
{
    setlocale(LC_ALL, "RUS");

    const double h = 1e-5; // Шаг для численного дифференцирования
    double x = xmin;
    double fx = prtf(x);  // Значение функции в точке x
    double fprime = derivative(prtf, x, h); // Производная функции в точке x

    printf("Начало интервала: x = %lf, f(x) = %lf, f'(x) = %lf\n", x, fx, fprime);

    // Ищем экстремум на интервале [xmin, xmax]
    while (x <= xmax) 
    {
        double fprime_next = derivative(prtf, x + h, h); // Производная в следующей точке
        if ((fprime > 0 && fprime_next < 0) || (fprime < 0 && fprime_next > 0)) 
        {            
            printf("Найден экстремум на интервале [%lf, %lf]\n", xmin, x + h); // Если производная меняет знак, нашли экстремум
            //return;
        }
        fprime = fprime_next;
        x += h;
    }

    printf("Экстремум не найден на интервале [%lf, %lf]\n", xmin, xmax);
    return 1;
}

// Пример функции для тестирования
double example_func(double x) 
{
    return x * x - 4 * x + 3; // Пример функции: f(x) = x^2 - 4x + 3
}

void main() 
{
    double xmin = 0.0;
    double xmax = 5.0;

    // Вызываем функцию action с примерной функцией example_func
    action(example_func, xmin, xmax);
}

