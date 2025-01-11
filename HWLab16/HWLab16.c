#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double calc_average(double* arr, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++) 
        sum += arr[i];
    return sum / size;
}

void main() 
{
    setlocale(LC_ALL, "RUS");

    int n, m, l;

    printf("¬ведите размер массива a\n");
    scanf("%d", &n);
    double* a = (double*)malloc(n * sizeof(double)); 
    if (a == NULL) return NULL;

    printf("¬ведите элементы массива a\n");
    for (int i = 0; i < n; i++) 
        scanf("%lf", &a[i]);

    printf("¬ведите размер массива b\n");
    scanf("%d", &m);
    double* b = (double*)malloc(m * sizeof(double));
    if (b == NULL) return NULL;

    printf("¬ведите элементы массива b\n");
    for (int i = 0; i < m; i++) 
        scanf("%lf", &b[i]);

    printf("¬ведите размер массива c\n");
    scanf("%d", &l);
    double* c = (double*)malloc(l * sizeof(double));  
    if (c == NULL) return NULL;

    printf("¬ведите элементы массива c\n");
    for (int i = 0; i < l; i++) 
        scanf("%lf", &c[i]);

    double b_average = calc_average(b, m);
    double c_average = calc_average(c, l);

    double* d = (double*)malloc(n * sizeof(double));  
    if (d == NULL) return NULL;

    d[0] = b_average;
    d[n - 1] = c_average;

    int found_positive = 0;  
    for (int i = 1; i < n - 1; i++) 
    {
        if ((found_positive == 0) && a[i] > 0) 
            found_positive = 1;

        if (found_positive == 1) 
        {
            if (a[i] > 1) 
                d[i] = a[i] - 0.5;
            else 
                d[i] = a[i] + 0.5;
        }
        else 
            d[i] = a[i];
    }

    printf("\nЁлементы массива d:\n");
    for (int i = 0; i < n; i++) 
        printf("%.1lf ", d[i]);
    printf("\n");

    free(a);
    free(b);
    free(c);
    free(d);
}

