#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int size(char *address)
{
    //unsigned char* fstByte;
    //fstByte = (char)address; //������ ����
    

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
    char ch;// ���� ����� ����� �� ���� ����
    char *point_ch = &ch;

    int ch_size = point_ch - '0'; //���� ���� � int
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
    //fstByte = (unsigned char*)address; //������ ����
    //unsigned char* byte = 0;
    ////char nAddress[100] = { *address };
    ////char array[100] = *address;

    //int size = 0;
    //for (int i = 0; array[i] != 0; i++)
    //    size += 1;

    //int byteAmount = 0;
    //for (int i = 0; i < size; i++)
    //{
    //    //byte = fstByte + i; //���� ������� ����� ���������� �� �������
    //    //printf("%.2x ", *byte);
    //    byteAmount += 1;
    //}
    //return byteAmount;
}

int byteSize2(char* address)
{
    char ch;// ���� ����� ����� �� ���� ����
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