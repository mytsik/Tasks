#include <stdio.h>
#include <locale.h>

void main() 
{
    setlocale(LC_ALL, "RUS");

    int n, A;
    printf("Введите количество элементов массива n\n");
    scanf_s("%d", &n);
    printf("Введите число A\n");
    scanf_s("%d", &A);

    
    int array[1000]; 
    printf("Введите %d элементов массива\n", n);
    for (int i = 0; i < n; i++) 
        scanf_s("%d", &array[i]);

    int count = 0;    
    for (int j = 0; j < n; j++) 
    {
        if (array[j] > A) 
            count++;
    }

    printf("Количество элементов массива, которые больше %d равно %d\n", A, count);
}
