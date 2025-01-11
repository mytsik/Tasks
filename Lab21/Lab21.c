#include <stdio.h>
#include <locale.h>
#define SIZE_TH 1000

typedef struct Cornice {
    int length;
    int ceilingWidth;
    int wallHeight;
    char material[20];
} cornice_t;


void fill_array(cornice_t*, int);
void print_array(cornice_t* cornices, int size);

cornice_t* search_material(cornice_t* cornices, int size, char* material);
int compare(const void* a, const void* b);
void qsort(cornice_t* cornices, int size);

int input_file(char* filename, cornice_t* arr);
int output_file(char* filename, cornice_t* arr, int n);

void main()
{
    setlocale(LC_ALL, "RUS");
    cornice_t cornices[SIZE_TH] =
    {
        {10, 5, 3, "Wood"},
        {8, 4, 2, "Alluminium"},
        {12, 5, 4, "Plastic"},
        {6, 3, 2, "Steel"},
        {9, 6, 3, "Metal"}
    };

    fill_array(cornices, SIZE_TH);
    print_array(cornices, SIZE_TH);
    output_file("text.txt", cornices, SIZE_TH);

    qsort(cornices, SIZE_TH, sizeof(cornice_t), compare);
}

void fill_array(cornice_t* cornices, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Введите длину, ширину, высоту, и матирал карниза %d\n", i + 1);
        scanf("%d %d %d %s", &cornices[i].length, &cornices[i].ceilingWidth, &cornices[i].wallHeight, cornices[i].material);
    }
}

void print_array(cornice_t* cornices, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("| %d || %d || %d || %s |\n", cornices[i].length, cornices[i].ceilingWidth, cornices[i].wallHeight, cornices[i].material);
    }
}

cornice_t* search_material(cornice_t* cornices, int size, char* material)
{
    for (int i = 0; i < size; i++) {
        if (strcmp(cornices[i].material, material) == 0)
            return (cornices + i);
    }
    return NULL;
}

int compare(const void* a, const void* b)
{
    const cornice_t* corniceA = (const cornice_t*)a;
    const cornice_t* corniceB = (const cornice_t*)b;

    int areaA = corniceA->length * corniceA->ceilingWidth;
    int areaB = corniceB->length * corniceB->ceilingWidth;

    return (areaA - areaB);
}

int input_file(char* filename, cornice_t* arr)
{
    FILE* file = fopen(filename, "rb");
    if (!file)
    {
        printf("Ошибка открытия файла\n");
        return 0;
    }
    fread(arr, sizeof(cornice_t), SIZE_TH, file);
    fclose(file);
    return 1;
}

int output_file(char* filename, cornice_t* arr, int n)
{
    FILE* file = fopen(filename, "wb");
    if (!file)
    {
        printf("Ошибка открытия файла\n");
        return 0;
    }
    fwrite(arr, sizeof(cornice_t), n, file);
    fclose(file);
    return 1;
}