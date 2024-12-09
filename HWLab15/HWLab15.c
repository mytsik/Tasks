#include <stdio.h>
#include <locale.h>

int main() 
{
    setlocale(LC_ALL, "RUS");

    int all_parallels[11][4];  
    int average_nums[11]; 
    int one_parallel_sum;     
    int i, j;

    for (i = 0; i < 11; i++) 
    {
        printf("\n¬ведите количество учеников дл€ каждого класса параллели %d\n", i + 1);
        one_parallel_sum = 0;  
        for (j = 0; j < 4; j++) 
        {
            printf("%d класс %d параллель - ", i + 1, j + 1);
            scanf_s("%d", &all_parallels[i][j]);
            one_parallel_sum += all_parallels[i][j];  
        }
        average_nums[i] = one_parallel_sum / 4; 
    }

    printf("\n");
    for (i = 0; i < 11; i++) 
        printf("—реднее количество учеников в классах параллели %d равно %d\n", i + 1, average_nums[i]);
}
