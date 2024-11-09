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

    int ch_size = point_ch - '0'; //один байт в int
    int actuall_address_size = address - '0';
    printf("\nch_size = %d\n", ch_size);
    printf("actuall_address_size = %d\n\n", actuall_address_size);

    int difference = (actuall_address_size - ch_size) - '416';
    if (difference == 0)
        return 1;
    /*else 
        if (typeof(*address) == "float") 
            return (difference / 16);*/
    else
        return (difference / 8);
}

int byteSize(char* address) 
{
    //unsigned char* fstByte;
    //fstByte = (unsigned char*)address; //первый байт
    //unsigned char* byte = 0;
    ////char nAddress[100] = { *address };
    ////char array[100] = *address;

    //int size = 0;
    //for (int i = 0; array[i] != 0; i++)
    //    size += 1;

    //int byteAmount = 0;
    //for (int i = 0; i < size; i++)
    //{
    //    //byte = fstByte + i; //байт который будет выводиться на консоль
    //    //printf("%.2x ", *byte);
    //    byteAmount += 1;
    //}
    //return byteAmount;
}

int byteSize2(char* address)
{
    char ch;// этот адрес будет за один байт
    char* point_ch = &ch;
    int int_address = (int)address;
    int int_point_ch = (int)point_ch;

    
    //int res2 = (int_point_ch - int_address) / 128;
    int res = (int_point_ch - int_address) / 64;
    if ((res / 4294967290) == 1)
        return 1;
    else
        if (((4294967290 - res) == 1) || ((4294967290 - res) == 2))
            return (4294967290 - res) * 4;
            
    return res;
}

void main()
{
	setlocale(LC_ALL, "RUS");

    char ch;
    int i;
    float f;
    double d;
    size_t s;
    short int si;
    unsigned short int usi;
    unsigned char uc;
    wchar_t wt;
    long long int lli;
    signed int sgi;

    char *point_ch = &ch;
    int *point_i = &i;
    float *point_f = &f;
    double *point_d = &d;
    size_t* point_s = &s;
    short int *point_si = &si;
    unsigned short int *point_usi = &usi;
    unsigned char* point_uc = &uc;
    wchar_t *point_wt = &wt;
    long long int* point_lli = &lli;
    signed int *point_sgi = &sgi;


    printf("Размер char: %lu\n", byteSize2(point_ch));
    printf("Размер int: %lu\n", byteSize2(point_i));
    printf("Размер float: %lu\n", byteSize2(point_f));
    printf("Размер double: %lu\n", byteSize2(point_d));
    printf("Размер size_t: %lu\n", byteSize2(point_s));
    printf("Размер short int: %lu\n", byteSize2(point_si));
    printf("Размер unsigned short int: %lu\n", byteSize2(point_usi));
    printf("Размер unsigned char: %lu\n", byteSize2(point_uc));
    printf("Размер wchar_t: %lu\n", byteSize2(point_wt));
    printf("Размер long long int: %lu\n", byteSize2(point_lli));
    printf("Размер signed int: %lu\n", byteSize2(point_sgi));
    printf("\nПравильно:\n");
    printf("Размер char: %lu\n", sizeof(ch));
    printf("Размер int: %lu\n", sizeof(i));
    printf("Размер float: %lu\n", sizeof(f));
    printf("Размер double: %lu\n", sizeof(d));
    printf("Размер size_t: %lu\n", sizeof(s));
    printf("Размер short int: %lu\n", sizeof(si));
    printf("Размер unsigned short int: %lu\n", sizeof(usi));
    printf("Размер unsigned char: %lu\n", sizeof(uc));
    printf("Размер wchar_t: %lu\n", sizeof(wt));
    printf("Размер long long int: %lu\n", sizeof(lli));
    printf("Размер signed int: %lu\n", sizeof(sgi));

}