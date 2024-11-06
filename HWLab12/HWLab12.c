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

    char ch;// этот адрес будет за один байт
    char *point_ch = &ch;
    int ch_size = point_ch - 0; //на эту цифру делим

    //int intAddress = address - 0; // преобразовываю адрес в int отнимая от него int
    //int result = (intAddress - 2010118508) / 8;
    //int res = intAddress / ch_size + ((intAddress - ch_size) / 8);
    int actuall_address = address - 0;
    int difference = (actuall_address - ch_size) - 416;
    if (difference == 0)
        return 1;
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

    char *point_ch;
    point_ch = &ch; //здесь хранится адрес ch
    int *point_i = &i;
    float *point_f = &f;
    double *point_d = &d;

    printf("Размер char: %lu\n", size(&ch)); 
    printf("Размер int: %lu\n", size(&i));
    //printf("Размер float: %lu\n", size(&f));
    printf("\nПравильно:\n");
    printf("Размер char: %lu\n", sizeof(ch));
    printf("Размер int: %lu\n", sizeof(i));

}