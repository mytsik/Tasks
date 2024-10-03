#include <locale.h>
#include <stdio.h>

void main() 
{
	setlocale(LC_ALL, "RUS");

    float Vc; 
    float S;  
    float Vp; 
    float T;  

    printf("Введите скорость самолета (м/с): \n");
    scanf_s("%f", &Vc);
    printf("Введите расстояние до зенитной пусковой установки (м): \n");
    scanf_s("%f", &S);
    printf("Введите скорость ракеты (м/с): \n");
    scanf_s("%f", &Vp);

    if (Vp <= Vc) {
        printf("Ракета не сможет поразить цель, так как её скорость меньше или равна скорости самолета.\n");
    }
    else {
        T = S / (Vp - Vc);
        printf("Время до поражения цели: %.2f секунд\n", T);
    }
}