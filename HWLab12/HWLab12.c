#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int size(char *address)
{
    //unsigned char* fstByte;
    //fstByte = (char)address; //первый байт
    

    /*int byteAmount = 0;
    for (int i = 0; ; i++)
    {
        unsigned char* byte;
        byte = (int)address + i;
        if (byte == 0)
            break;
        byteAmount += 1;
    }
    return byteAmount;*/
    
    //char ch_add = (char *)address;
    //int bytes = strlen(*address);
    //return bytes;
    //int address_int = (int)address;
    //int* address_int_point = &address_int;
    char ch;// этот адрес будет за один байт
    char *point_ch = &ch;

    int ch_size = point_ch - 0; //один байт в int
    int actuall_address_size = address - 0;
    printf("\nch_size = %d\n", ch_size);
    printf("actuall_address_size = %d\n\n", actuall_address_size);

    int difference = (actuall_address_size - ch_size) - 416;
    if (difference == 0)
        return 1;
    /*else 
        if (typeof(*address) == "float") 
            return (difference / 16);*/
    else
        return (difference / 8);
}

void main()
{
	setlocale(LC_ALL, "RUS");

    char ch;
    int i;
    float f;
    double d;
    size_t s;

    char *point_ch;
    point_ch = &ch; //здесь хранится адрес ch
    int *point_i = &i;
    float *point_f = &f;
    double *point_d = &d;

    printf("Размер char: %lu\n", size(&ch)); 
    //printf("Размер int: %lu\n", size(&i));
    printf("Размер float: %lu\n", size(&f));
    printf("Размер double: %lu\n", size(&d));
    printf("Размер size_t: %lu\n", size(&s));
    printf("\nПравильно:\n");
    printf("Размер char: %lu\n", sizeof(ch));
    //printf("Размер int: %lu\n", sizeof(i));
    printf("Размер float: %lu\n", sizeof(f));
    printf("Размер double: %lu\n", sizeof(d));
    printf("Размер size_t: %lu\n", sizeof(s));

}