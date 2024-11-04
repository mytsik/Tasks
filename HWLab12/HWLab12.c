#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int size(char *address)
{
    int res = 0 - (int)address;
    return abs(res);
}

void main()
{
	setlocale(LC_ALL, "RUS");

    char ch;
    int i;
    float f;
    double d;

    char *point_ch = &ch;
    int *point_i = &i;
    float *point_f = &f;
    double *point_d = &d;

    printf("Размер char: %lu\n", size(*point_ch));
    printf("Размер int: %lu", size(*point_i));

}