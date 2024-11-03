#include <stdio.h>
#include <locale.h>

int Task5_2(char *full_address, int size) 
{
	unsigned char *fstByte;
	fstByte = (unsigned char*)full_address;
	unsigned char *printByte;

	for (int i = 0; i < size; i++) 
	{
		printByte = fstByte + i;
		printf("%.2x ", *printByte);
	}		

	return 0;
}

void main()
{
	setlocale(LC_ALL, "RUS");

	char *ch;
	int *i;
	double *d;
	printf("%lu\n", sizeof(ch));
	printf("%lu\n", sizeof(i));
	printf("%lu\n", sizeof(d));

	float PI = 3.14159, *p1, *p2;
	p1 = p2 = &PI;
	printf("\nПо адресу p1=%p хранится *p1=%g\n", p1, *p1);
	printf("По адресу p2=%p хранится *p2=%g\n", p2, *p2);

	_Bool *pа, x = 5;
	pа = &x;
	printf("\nПо адресу %p хранится *ptr=%g\n", pа, *pа);
	pа++;
	printf("По адресу %p хранится *ptr=%g\n", pа, *pа);
	pа--;
	printf("По адресу %p хранится *ptr=%g\n", pа, *pа);

	float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
	float *ptr_a;

	printf("\n%p %p %p \n", array, &array[0], &array);

	ptr_a = &array[0];
	printf("\n%p %.1f\n", ptr_a++, *ptr_a);
	printf("%p %.1f\n", ptr_a += 4, *ptr_a);
	printf("%p %.1f\n\n", ptr_a -= 2, *ptr_a);

	for (int i = 0; i < 10; i += 2)
	{
		float *straight;
		straight = &array[i];
		printf("%.1f ", *straight);
	}
	printf("\n");

	for (int i = 9; i >= 0; i--)
	{
		float *back;
		back = &array[i];
		printf("%.1f ", *back);
	}
	printf("\n\n");

	int x2 = 12345678;
	int* prt;
	unsigned char* a1, * a2, * a3, * a4;
	unsigned char* a;

	prt = &x2;
	a = (unsigned char*)prt; //адрес первого байта
	a1 = a + 3;
	a2 = a + 2;
	a3 = a + 1;
	a4 = a;
	printf("%.2x\n%.2x\n%.2x\n%.2x\n\n", *a1, *a2, *a3, *a4);

	int i5 = 12345678;
	Task5_2(&i5, sizeof(i5));

}