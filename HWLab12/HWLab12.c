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

    char ch;// ���� ����� ����� �� ���� ����
    char *point_ch = &ch;
    int ch_size = point_ch - 0; //�� ��� ����� �����

    //int intAddress = address - 0; // �������������� ����� � int ������� �� ���� int
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
    point_ch = &ch; //����� �������� ����� ch
    int *point_i = &i;
    float *point_f = &f;
    double *point_d = &d;

    printf("������ char: %lu\n", size(&ch)); 
    printf("������ int: %lu\n", size(&i));
    //printf("������ float: %lu\n", size(&f));
    printf("\n���������:\n");
    printf("������ char: %lu\n", sizeof(ch));
    printf("������ int: %lu\n", sizeof(i));

}