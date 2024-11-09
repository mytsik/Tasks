#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int byteSize2(char* address)
{
    char ch;// этот адрес будет за один байт
    char* point_ch = &ch;
    int int_address = (int)address;
    int int_point_ch = (int)point_ch;      
    int res = (int_point_ch - int_address) / 64;

    if ((res / 4294967290) == 1)
        return 1; 
    else if (((4294967290 - res) == 1) || ((4294967290 - res) == 2))
        return (4294967290 - res) * 4;
    else if ((4294967290 - res) == 3)
        return 2;
    
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