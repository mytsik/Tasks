#include <locale.h>
#include <stdio.h>

void getPunctName(char pun)
{
    switch (pun) 
    {
        case '.':
            printf("Точка\n");
            break;
        case ',':
            printf("Запятая\n");
            break;
        case '?':
            printf("Вопросительный знак\n");
            break;
        case '!':
            printf("Восклицательный знак\n");
            break;
        case ':':
            printf("Двоеточие\n");
            break;
        case ';':
            printf("Точка с запятой\n");
            break;
        case '-':
            printf("Тире\n");
            break;
        default:
            printf("Неизвестный знак препинания\n");
    }
}

void main()
{
	setlocale(LC_ALL, "RUS");

    char pun;
	printf("Введите знак препинания\n");
    scanf_s(" %c", &pun);
    getPunctName(pun);
}