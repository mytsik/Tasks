#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define K 10  //диапазон значений от 1 до K
#define N 1000 //кол-во случайных чисел
#define R 50  //максимальное кол-во символов для гистограммы

int rand10(int mmax) 
{
    return (rand() % mmax) + 1;
}

double rand_double(double dmin, double dmax) 
{
    return dmin + (rand() / (double)RAND_MAX) * (dmax - dmin);
}

int* rand10_array(int n, int mmax) 
{
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
        arr[i] = rand10(mmax);
    return arr;
}

double* rand_double_array(int n, double dm) 
{
    double* arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) 
        arr[i] = rand_double(-dm, dm);
    return arr;
}

int rock_paper_scissors(int u_ch, int prog_ch)
{
    printf("\nВы выбрали ");
    switch (u_ch)
    {
    case 1:
        printf("камень\n");
        break;
    case 2:
        printf("ножницы\n");
        break;
    case 3:
        printf("бумагу\n");
        break;
    }

    printf("Программа выбрала ");
    switch (prog_ch)
    {
    case 1:
        printf("камень\n");
        break;
    case 2:
        printf("ножницы\n");
        break;
    case 3:
        printf("бумагу\n");
        break;
    }

    if (u_ch == prog_ch)
        printf("\nНичья\n");
    else if ((u_ch == 1 && prog_ch == 2) || (u_ch == 2 && prog_ch == 3) || (u_ch == 3 && prog_ch == 1))
        printf("\nВы выиграли\n");
    else
        printf("\nВы проиграли\n");

    return 1;
}

void main() 
{
    setlocale(LC_ALL, "RUS");

    int m = 1 + rand() % 10;

    int k;
    printf("Введите загаданное число от 1 до 10\n");
    scanf("%d", &k);

    if (k == m) 
        printf("Вы угадали число\n");
    else 
        printf("Вы не угадали число\n");

    int u_ch;
    printf("\nВведите цифру\n1 - Камень\n2 - Ножницы\n3 - Бумага\n");
    scanf("%d", &u_ch);

    int prog_ch = 1 + rand() % 3;

    rock_paper_scissors(u_ch, prog_ch);

    int stime;
    long ltime;
    ltime = time(NULL);
    stime = (unsigned)ltime / 2;
    srand(stime);

    int mmax;
    printf("\nВведите число, которое больше или равно единице\n");
    scanf("%d", &mmax);
    printf("\nСлучайное целое число от 1 до %d равно %d\n", mmax, rand10(mmax));

    double dmin, dmax;
    printf("\nВведите границы диапазона\n");
    scanf("%lf%lf", &dmin, &dmax);
    printf("\nСлучайное вещественное число в заданном диапазоне равно %.2f\n", dmin, dmax, rand_double(dmin, dmax));

    int n = 0;
    printf("\nВведите число, которое больше единицы и меньше или равно %d\n", mmax);
    scanf("%d", &n);

    int* rand_ints = rand10_array(n, mmax);
    printf("\nСлучайные целые чисела от 1 до %d \n", mmax);
    for (int i = 0; i < n; i++) 
        printf("%d ", rand_ints[i]);
    printf("\n\n");

    double dm = 0;
    printf("Введите число, которое меньше или равно %d\n", mmax);
    scanf("%lf", &dm);
    double* rand_doubles = rand_double_array(n, dm);
    printf("\n%d вещественных чисел в диапазоне от %lf до %lf", n, 0 - dm, dm);
    for (int i = 0; i < n; i++) 
        printf("%.2lf ", rand_doubles[i]);
    printf("\n\n");

    int counter[K] = { 0 };  
    int array[N];  

    for (int i = 0; i < N; i++) 
    {
        int num = rand10(K);  
        array[i] = num;  
        counter[num - 1]++; 
    }

    int max_count = 0;
    for (int i = 0; i < K; i++) 
    {
        if (counter[i] > max_count) 
            max_count = counter[i];
    }

    printf("Гистограмма частоты выпадания чисел\n");
    for (int i = 0; i < K; i++) 
    {
        int norm_value = (counter[i] * R) / max_count;
        printf("%2d: ", i + 1);
        for (int j = 0; j < norm_value; j++) 
            printf("*");
        printf(" (%d)\n", counter[i]); 
    }
}
