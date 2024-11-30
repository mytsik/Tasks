#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

// ������� ��� ��������� ���������� ����� �� -10 �� 10
//int random_int() 
//{
//    return rand() % 21 - 10;  // ���������� ����� �� 0 �� 20 � �������� 10
//}

// ������� ��� ������ ���������� �������
void print_array(int arr[7][7]) 
{
    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 7; j++) 
        {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

void main() 
{
    setlocale(LC_ALL, "RUS");

    int a[50][50];
    int n, m;

    printf("������� ���������� �����: ");
    scanf("%d", &n);
    printf("������� ���������� ��������: ");
    scanf("%d", &m);
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
            a[i][j] = i + j;
    }

    printf("\n");
    printf("     ");
    for (int j = 0; j < m; j++) 
        printf(" %2d ", j);  //��������� �������
    printf("\n\n");

    for (int i = 0; i < n; i++) 
    {
        printf(" %2d  ", i);  //��������� ������
        for (int j = 0; j < m; j++) 
            printf(" %2d ", a[i][j]);
        printf("\n");
    }

    printf("\n�������, ������������� � ������ ������� ���� ������� ����� %d\n", a[0][m - 1]);

    int n_find;
    printf("\n������� ����� ������ ��� ������ ������������ ��������\n");
    scanf("%d", &n_find);

    if (n_find >= 0 && n_find < n) 
    {
        int min = a[n_find][0];
        for (int j = 1; j < m; j++) 
        {
            if (a[n_find][j] < min) 
                min = a[n_find][j];
        }
        printf("����������� ������� � ������ %d ����� %d\n", n_find, min);
    }
    else
        printf("������ ��� ��������� ������� �� ����������\n");

    int m_find;
    printf("\n������� ����� ������� ��� ������ ������������� ��������\n");
    scanf("%d", &m_find);

    if (m_find >= 0 && m_find < m) 
    {
        int max = a[0][m_find];
        for (int i = 1; i < n; i++) 
        {
            if (a[i][m_find] > max) 
                max = a[i][m_find];
        }
        printf("������������ ������� � ������� %d ����� %d\n", m_find, max);
    }
    else 
        printf("������� ��� ��������� ������� �� ����������\n");

    int num;
    printf("\n������� �������� ��� ������ �� ������� ���������\n");
    scanf("%d", &num);

    int success = 0;
    for (int i = 0; i < n && i < m; i++) 
    {
        if (a[i][i] == num) 
        {
            printf("������ ������ ���������� �������� ����� %d, ������ ������� ���������� �������� ����� %d\n", i, i);
            success = 1;
            break;
        }
    }

    if (success == 0)
        printf("��������� �������� �� ������� �� ������� ���������\n\n", num);

    
    int arr[7][7];

    // ������������� ���������� ��������� �����
    //srand(time(NULL));

    // ���������� ��������� ������� ���������� ������� �� -10 �� 10
    int el = -10;
    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 7; j++) 
        {
            arr[i][j] = el;
            if (el == 10)
                el -= 21;
            el += 1;
        }
    }

    int trans_arr[7][7];
    // ���������������� �������
    for (int i = 0; i < 7; i++) 
    {
        for (int j = 0; j < 7; j++) 
        {
            trans_arr[i][j] = arr[j][i];
        }
    }

    // ����� ��������� �������
    printf("�������� ������:\n");
    print_array(arr);

    // ����� ������������������ �������
    printf("\n����������������� ������:\n");
    print_array(trans_arr);
}

