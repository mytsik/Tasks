#include <locale.h>
#include <stdio.h>
#include <string.h>

void biggestNum(int num1, int num2, int num3)
{
    int first, second, third;
    if (num1 >= num2 && num1 >= num3)
    {
        first = num1;
        if (num2 >= num3) {
            second = num2;
            third = num3;
        }
        else {
            second = num3;
            third = num2;
        }
    }
    else if (num2 >= num1 && num2 >= num3)
    {
        first = num2;
        if (num1 >= num3) {
            second = num1;
            third = num3;
        }
        else {
            second = num3;
            third = num1;
        }
    }
    else
    {
        first = num3;
        if (num1 >= num2) {
            second = num1;
            third = num2;
        }
        else {
            second = num2;
            third = num1;
        }
    }

    printf("\nНаибольшее число %d%d%d", first, second, third);
}

void main() 
{
    setlocale(LC_ALL, "RUS");

    int num1, num2, num3;
    printf("Введите три цифры\n");
    scanf_s("%d%d%d", &num1, &num2, &num3);

    biggestNum(num1, num2, num3);
}