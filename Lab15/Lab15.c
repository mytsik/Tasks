#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

// Функция для генерации случайного числа от -10 до 10
//int random_int() 
//{
//    return rand() % 21 - 10;  // Генерируем число от 0 до 20 и вычитаем 10
//}

// Функция для вывода двумерного массива
void print_array(int arr[7][7]) 
{
    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 7; j++) 
        {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
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

    // Инициализация генератора случайных чисел
    //srand(time(NULL));

    // Заполнение исходного массива случайными числами от -10 до 10
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
    // Транспонирование массива
    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 7; j++) 
        {
            trans_arr[i][j] = arr[j][i];
        }
    }

    // Вывод исходного массива
    printf("Исходный массив:\n");
    print_array(arr);

    // Вывод транспонированного массива
    printf("\nТранспонированный массив:\n");
    print_array(trans_arr);
}

