#include <stdio.h>
#include <ctype.h>
#include <locale.h>

void main() 
{
    setlocale(LC_ALL, "RUS");

    char string[100];
    printf("¬ведите строку\n");
    fgets(string, sizeof(string), stdin);

    int length = (int)strlen(&string);
    int second_half = length / 2;
    int count = 0;

    for (int i = second_half; i < length; i++)
    {
        char ch = string[i];
        if ((isdigit(ch) == 0) && (isalpha(ch) == 0) && (ch != ' '))
            count += 1;
    }

    printf(" оличество знаков препинани€ во второй половине строки равно %d\n", count - 1);
}
