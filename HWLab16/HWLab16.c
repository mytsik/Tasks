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

    // ���� ������� ������� a
    printf("������� ������ ������� a: ");
    scanf("%d", &n);
    double* a = (double*)malloc(n * sizeof(double));  // ������������ ��������� ������ ��� ������� a
    if (a == NULL) {
        printf("������ ��������� ������ ��� ������� a.\n");
        return 1;
    }

    printf("������� �������� ������� a:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    // ���� ������� ������� b
    printf("������� ������ ������� b: ");
    scanf("%d", &m);
    double* b = (double*)malloc(m * sizeof(double));  // ������������ ��������� ������ ��� ������� b
    if (b == NULL) {
        printf("������ ��������� ������ ��� ������� b.\n");
        free(a);
        return 1;
    }

    printf("������� �������� ������� b:\n");
    for (int i = 0; i < m; i++) {
        scanf("%lf", &b[i]);
    }

    // ���� ������� ������� c
    printf("������� ������ ������� c: ");
    scanf("%d", &l);
    double* c = (double*)malloc(l * sizeof(double));  // ������������ ��������� ������ ��� ������� c
    if (c == NULL) {
        printf("������ ��������� ������ ��� ������� c.\n");
        free(a);
        free(b);
        return 1;
    }

    printf("������� �������� ������� c:\n");
    for (int i = 0; i < l; i++) {
        scanf("%lf", &c[i]);
    }

    // ���������� ������� �������� ��� �������� b � c
    double avg_b = calculate_average(b, m);
    double avg_c = calculate_average(c, l);

    // �������� ������� d � ��������� n
    double* d = (double*)malloc(n * sizeof(double));  // ������������ ��������� ������ ��� ������� d
    if (d == NULL) {
        printf("������ ��������� ������ ��� ������� d.\n");
        free(a);
        free(b);
        free(c);
        return 1;
    }

    // ����������� ������� �������� � ������ � ��������� �������� ������� d
    d[0] = avg_b;
    d[n - 1] = avg_c;

    // ��������� ��������� ������� a ������� � ������� ��������������
    int found_positive = 0;  // ���� ��� ������������ ������� �������������� ��������
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

    // ����� ������� d
    printf("������ d:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", d[i]);
    }
    printf("\n");

    // ������������ ������
    free(a);
    free(b);
    free(c);
    free(d);
}

