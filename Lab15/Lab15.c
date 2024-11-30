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

    printf("\nЭлемент, расположенный в правом верхнем углу массива равен %d\n", a[0][m - 1]);

    int n_find;
    printf("\nВведите номер строки для поиска минимального элемента\n");
    scanf("%d", &n_find);

    if (n_find >= 0 && n_find < n) 
    {
        int min = a[n_find][0];
        for (int j = 1; j < m; j++) 
        {
            if (a[n_find][j] < min) 
                min = a[n_find][j];
        }
        printf("Минимальный элемент в строке %d равен %d\n", n_find, min);
    }
    else
        printf("Строки под введенным номером не существует\n");

    int m_find;
    printf("\nВведите номер столбца для поиска максимального элемента\n");
    scanf("%d", &m_find);

    if (m_find >= 0 && m_find < m) 
    {
        int max = a[0][m_find];
        for (int i = 1; i < n; i++) 
        {
            if (a[i][m_find] > max) 
                max = a[i][m_find];
        }
        printf("Максимальный элемент в столбце %d равен %d\n", m_find, max);
    }
    else 
        printf("Столбца под введенным номером не существует\n");

    /*int num;
    printf("\nВведите значение для поиска на главной диагонали\n");
    scanf("%d", &num);

    int success = 0;
    for (int i = 0; i < n && i < m; i++) 
    {
        if (a[i][i] == num) 
        {
            printf("Индекс строки введенного значения равен %d, индекс столбца введенного значения равен %d\n", num, i, i);
            success = 1;
            break;
        }
    }

    if (!success) 
        printf("Введенное значение не найдено на главной диагонали\n", num);*/

    // 3. Найти заданное значение среди элементов диагонали
    int value;
    printf("\nВведите значение для поиска на главной диагонали: ");
    scanf("%d", &value);

    int found = 0;
    for (int i = 0; i < n && i < m; i++) {
        if (a[i][i] == value) {
            printf("Значение %d найдено на главной диагонали (индекс [%d][%d]).\n", value, i, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Значение %d не найдено на главной диагонали.\n", value);
    }
}

