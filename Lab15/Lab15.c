#include <stdio.h>
#include <locale.h>

void main() 
{
    setlocale(LC_ALL, "RUS");

    int a[50][50];
    int n, m;

    printf("Введите количество строк: ");
    scanf("%d", &n);
    printf("Введите количество столбцов: ");
    scanf("%d", &m);
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
            a[i][j] = i + j;
    }

    printf("\n");
    printf("     ");
    for (int j = 0; j < m; j++) 
        printf(" %2d ", j);  //заголовок столбца
    printf("\n\n");

    for (int i = 0; i < n; i++) 
    {
        printf(" %2d  ", i);  //заголовок строки
        for (int j = 0; j < m; j++) 
            printf(" %2d ", a[i][j]);
        printf("\n");
    }
}

