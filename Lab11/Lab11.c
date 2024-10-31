#include <stdio.h>
#include <locale.h>
#define N 10

void Task2(float step)
{
    float C[100];

    for (int i = 0; i < 100; i++)
    {
        if (step <= 2.2 && step >= 0.1)
        {
            for (float x = 0.1; x <= 2.2; x += step)
            {
                float res = pow(x, 2) - pow(cos(x + 1), 2);
                C[i] = res;
            }
        }
        else
            printf("�������� ���� ��������� ��� ���������");
    }

    float summ_positive = 0;
    float summ_negative = 0;
    int positive_count = 0;
    int negative_count = 0;
    for (int i = 0; i < 100; i++)
    {
        if (C[i] >= 0)
        {
            summ_positive += C[i];
            positive_count += 1;
        }     
        else
            if (C[i] < 0)
            {
                summ_negative += C[i];
                negative_count += 1;
            }           
    }
    
    printf("C������ �������� ������������� ��������� ������� ����� %2.5f\n", summ_positive / 100);

    float summ_general = summ_positive + summ_negative;
    printf("��� �������: C, ����������� ��������: %.2f, ���������� ������������� ���������: %d, ���������� ������������� ���������: %d, ������� ��������: %.2f\n", summ_general, positive_count, negative_count, summ_general / 100);


}

void Task1()
{
    float A[10];
    float B[10];

    for (int i = 0; i < 10; i++)
    {
        float temp;
        printf("a[%d] = ", i + 1);
        scanf_s("%f", &temp);
        A[i] = temp;
        B[i] = temp / 10;
    }

    printf("\n| ������ | �������� �������� | ����� �������� |\n");
    for (int i = 0; i < 10; i++)
    {
        printf("| %d      | %10.1f        | %10.1f     |\n", i, A[i], B[i]);

        if (i == (N - 1))
        {
            printf("\n���������� ��������� � ������� ����� %d\n", N);
        }
    } 

    float summ = 0;
    for (int i = 0; i < 10; i++)
    {
        summ += A[i];
    }
    printf("C������ �������������� ��������� ������� ����� %2.1f\n", summ / 10);
}

void main()
{
    setlocale(LC_ALL, "RUS");
    Task1();

    float step;
    printf("\n������� �������� ���� ��� ������������� ������� y=x^2-cos^2(x+1) � �������� ��������� �� 0.1 �� 2.2 ������������\n");
    scanf_s("%f", &step);

    Task2(step);
}