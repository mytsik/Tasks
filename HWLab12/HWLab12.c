#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int byteSize2(char* address)
{
    char ch;// ���� ����� ����� �� ���� ����
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


    printf("������ char: %lu\n", byteSize2(point_ch));
    printf("������ int: %lu\n", byteSize2(point_i));
    printf("������ float: %lu\n", byteSize2(point_f));
    printf("������ double: %lu\n", byteSize2(point_d));
    printf("������ size_t: %lu\n", byteSize2(point_s));
    printf("������ short int: %lu\n", byteSize2(point_si));
    printf("������ unsigned short int: %lu\n", byteSize2(point_usi));
    printf("������ unsigned char: %lu\n", byteSize2(point_uc));
    printf("������ wchar_t: %lu\n", byteSize2(point_wt));
    printf("������ long long int: %lu\n", byteSize2(point_lli));
    printf("������ signed int: %lu\n", byteSize2(point_sgi));
    printf("\n���������:\n");
    printf("������ char: %lu\n", sizeof(ch));
    printf("������ int: %lu\n", sizeof(i));
    printf("������ float: %lu\n", sizeof(f));
    printf("������ double: %lu\n", sizeof(d));
    printf("������ size_t: %lu\n", sizeof(s));
    printf("������ short int: %lu\n", sizeof(si));
    printf("������ unsigned short int: %lu\n", sizeof(usi));
    printf("������ unsigned char: %lu\n", sizeof(uc));
    printf("������ wchar_t: %lu\n", sizeof(wt));
    printf("������ long long int: %lu\n", sizeof(lli));
    printf("������ signed int: %lu\n", sizeof(sgi));

}