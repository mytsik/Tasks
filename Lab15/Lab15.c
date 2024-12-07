#include <stdio.h>
#include <locale.h>

void printf_arr(int arr[7][7]) 
{
    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 7; j++) 
            printf("%3d ", arr[i][j]);
        printf("\n");
    }
}

int sum_negat_elems_in_5th_row(int arr[7][7])
{
    int sum = 0;
    for (int i = 0; i < 7; i++) 
    {
        if (arr[4][i] < 0) 
            sum += arr[4][i];
    }
    return sum;
}

int equal_neighbor_pairs_in_rows(int arr[7][7]) 
{
    int count = 0;
    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 7 - 1; j++) 
        {
            if (arr[i][j] == arr[i][j + 1]) 
                count++;
        }
    }
    return count;
}

int equal_neighbor_pairs_in_columns(int arr[7][7])
{
    int count = 0;
    for (int j = 0; j < 7; j++) 
    {
        for (int i = 0; i < 7 - 1; i++) 
        {
            if (arr[i][j] == arr[i + 1][j]) 
                count++;
        }
    }
    return count;
}

void findMax(int arr[7][7])
{
    int max = arr[0][0];
    int row = 0;
    int col = 0;

    for (int j = 0; j < 7; j++) 
    {
        for (int i = 1; i < 7; i++)
        {  
            if (arr[i][j] > max) 
            {
                max = arr[i][j];
                row= i;
                col = j;
            }
        }
    }
    printf("\nИндекс строки максимального значения равен %d, индекс столбца максимального значения равен %d\n", row, col);
}

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
        printf(" %2d ", j); //заголовок столбца
    printf("\n\n");

    for (int i = 0; i < n; i++) 
    {
        printf(" %2d  ", i); //заголовок строки
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
        printf("Минимальный элемент в строке равен %d\n", n_find);
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
        printf("Максимальный элемент в столбце равен %d\n", max);
    }
    else 
        printf("Столбца под введенным номером не существует\n");

    int num;
    printf("\nВведите значение для поиска на главной диагонали\n");
    scanf("%d", &num);

    int success = 0;
    for (int i = 0; i < n && i < m; i++) 
    {
        if (a[i][i] == num) 
        {
            printf("Индекс строки введенного значения равен %d, индекс столбца введенного значения равен %d\n", i, i);
            success = 1;
            break;
        }
    }

    if (success == 0)
        printf("Введенное значение не найдено на главной диагонали\n\n", num);

    
    int arr[7][7];

    int el = -10;
    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 7; j++) 
        {
            arr[i][j] = el;
            if (el == 10)
                el -= 21;
            el += 1;
        }
    }

    int trans_arr[7][7];
    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 7; j++) 
            trans_arr[i][j] = arr[j][i];
    }

    printf("\nИсходный массив:\n");
    printf_arr(arr);

    printf("\nТранспонированный массив:\n");
    printf_arr(trans_arr);

    printf("\nСумма отрицательных элементов пятой строки равна %d\n", sum_negat_elems_in_5th_row(arr));
    printf("\nЧисло пар одинаковых соседних элементов в строках равно %d\n", equal_neighbor_pairs_in_rows(arr));
    printf("\nЧисло пар одинаковых соседних элементов в столбцах равно %d\n", equal_neighbor_pairs_in_columns(arr));

    findMax(arr);
}

