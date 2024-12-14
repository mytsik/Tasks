#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double calculate_average(double* arr, int size) 
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

    // Ввод размера массива a
    printf("Введите размер массива a: ");
    scanf("%d", &n);
    double* a = (double*)malloc(n * sizeof(double));  // Динамическое выделение памяти для массива a
    if (a == NULL) {
        printf("Ошибка выделения памяти для массива a.\n");
        return 1;
    }

    printf("Введите элементы массива a:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    // Ввод размера массива b
    printf("Введите размер массива b: ");
    scanf("%d", &m);
    double* b = (double*)malloc(m * sizeof(double));  // Динамическое выделение памяти для массива b
    if (b == NULL) {
        printf("Ошибка выделения памяти для массива b.\n");
        free(a);
        return 1;
    }

    printf("Введите элементы массива b:\n");
    for (int i = 0; i < m; i++) {
        scanf("%lf", &b[i]);
    }

    // Ввод размера массива c
    printf("Введите размер массива c: ");
    scanf("%d", &l);
    double* c = (double*)malloc(l * sizeof(double));  // Динамическое выделение памяти для массива c
    if (c == NULL) {
        printf("Ошибка выделения памяти для массива c.\n");
        free(a);
        free(b);
        return 1;
    }

    printf("Введите элементы массива c:\n");
    for (int i = 0; i < l; i++) {
        scanf("%lf", &c[i]);
    }

    // Вычисление средних значений для массивов b и c
    double avg_b = calculate_average(b, m);
    double avg_c = calculate_average(c, l);

    // Создание массива d с размерами n
    double* d = (double*)malloc(n * sizeof(double));  // Динамическое выделение памяти для массива d
    if (d == NULL) {
        printf("Ошибка выделения памяти для массива d.\n");
        free(a);
        free(b);
        free(c);
        return 1;
    }

    // Перемещение средних значений в первые и последние элементы массива d
    d[0] = avg_b;
    d[n - 1] = avg_c;

    // Обработка элементов массива a начиная с первого положительного
    int found_positive = 0;  // Флаг для отслеживания первого положительного элемента
    for (int i = 1; i < n - 1; i++) {
        if (!found_positive && a[i] > 0) {
            found_positive = 1;
        }

        if (found_positive) {
            if (a[i] > 1) {
                d[i] = a[i] - 0.5;
            }
            else {
                d[i] = a[i] + 0.5;
            }
        }
        else {
            d[i] = a[i];
        }
    }

    // Вывод массива d
    printf("Массив d:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", d[i]);
    }
    printf("\n");

    // Освобождение памяти
    free(a);
    free(b);
    free(c);
    free(d);
}

