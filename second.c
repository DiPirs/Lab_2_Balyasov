#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <time.h>
#include <string.h>

int count_string(FILE* count_str) 
{
    int     result = 0;

    while (!ferror(count_str) && !feof(count_str)) 
    {
        if (fgetc(count_str) == '\n')
            result++;
    }
    rewind(count_str);

    return result;
}

void sorting_bubble(double* arr_b, int size)
{
    int         i, j;
    double      buff;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - (i + 1); j++)
        {
            if (arr_b[j] > arr_b[j + 1])
            {
                buff = arr_b[j];
                arr_b[j] = arr_b[j + 1];
                arr_b[j + 1] = buff;
            }
        }
    }
}

void sorting_insert(double* arr_b, int size)
{
    int         i, j;
    double      buff;

    for (i = 1; i < size; i++)
    {
        for (j = i; j > 0 && arr_b[j - 1] > arr_b[j]; j--)
        {
            buff = arr_b[j];
            arr_b[j] = arr_b[j - 1];
            arr_b[j - 1] = buff;
        }
    }
    
}

void sorting_fast(double* arr_b, int start, int end)
{
    int         left = start;
    int         right = end;
    double      pivot = arr_b[(left + right) / 2];
    while (left <= right)
    {
        while (arr_b[left] < pivot)
        {
            left++;
        }
        while (arr_b[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            double buff = arr_b[left];
            arr_b[left] = arr_b[right];
            arr_b[right] = buff;
            left++;
            right--;
        }
    }

    if (start < right)
        sorting_fast(arr_b, start, right);
    if (end > left)
        sorting_fast(arr_b, left, end);

}
int main() 
{
    int         size_file;
    int         x, i;
    int         case_conf_1, case_conf_2;
    double      *a, *b;
    double      time_prog;

    clock_t     startTime, endTime;

    setlocale(LC_ALL, "Russian");
    FILE* file = fopen("C:/Users/SolEk/source/repos/Lab_2/Lab_2/file.txt", "r");

    printf_s("Происходит чтение из файла...\n");
    Sleep(1000);

    size_file = count_string(file);

    a = (double*)malloc(size_file * sizeof(double));
    b = (double*)malloc(size_file * sizeof(double));
    
    for (i = 0; i < size_file; i++)
        fscanf_s(file, "%lf", &a[i]);

    memcpy(b, a, sizeof(double) * size_file);

    do
    {
        system("cls");
        printf_s("Вас приветствует меню \"Сортировка файла\". Что бы Вы хотели сделать?\n");
        printf_s("1. Печать\n2. Сортировка\n3. Сброс\n4. Выход\n");
        scanf_s("%d", &x);

        switch (x)
        {
        case 1:
            system("cls");
            printf("Вы выбрали \"Печать\".\n");
            printf("Пожалуйста, ожидайте...\n");
            Sleep(1000);

            for (i = 0; i < size_file; i++)
                printf_s("a[%d] = %lf\n", i, b[i]);

            printf("\n1. Вернуться\n2. Выйти\n");
            scanf_s("%d", &case_conf_1);

            if (case_conf_1 == 2)
            {
                x = 4;
                break;
            }
            else
                break;
        case 2:
            system("cls");
            printf("Вы выбрали \"Сортировка\". Каким вариантом сортировки Вы бы хотели воспользоваться?\n");
            printf("1. Пузырьком\n2. Вставками\n3. Быстрая\n");
            scanf_s("%d", &case_conf_2);

            switch (case_conf_2)
            {
            case 1:
                startTime = clock();
                sorting_bubble(b, size_file);
                endTime = clock();
                time_prog = (double)(endTime - startTime) / 1000;

                printf_s("Сортировка \"Пузырьком\" завершена\n");
                printf_s("Время выполнения %f\n\n", time_prog);
                Sleep(1500);
                break;
            case 2:
                startTime = clock();
                sorting_insert(b, size_file);
                endTime = clock();
                time_prog = (double)(endTime - startTime) / 1000;

                printf_s("Сортировка \"Вставками\" завершена\n");
                printf_s("Время выполнения %f\n\n", time_prog);
                Sleep(1500);
                break;
            case 3:
                startTime = clock();
                sorting_fast(b, 0, size_file - 1);
                endTime = clock();
                time_prog = (double)(endTime - startTime) / 1000;

                printf_s("Сортировка \"Быстрая\" завершена\n");
                printf_s("Время выполнения %f\n\n", time_prog);
                Sleep(1500);
                break;
            default:
                printf("Вы ввели неверное число, повторите попытку...");
                break;
            }

            break;
        case 3:
            system("cls");
            printf("Вы выбрали \"Сброс\".\n");
            printf("Пожалуйста, ожидайте...\n\n");
            Sleep(1500);

            memcpy(b, a, sizeof(double) * size_file);

            printf_s("Сортировка успешно сброшена.\n\n");
            Sleep(1000);

            break;
        case 4:
            break;
        default:
            printf("Вы ввели не коректное число, повторите попытку");
            Sleep(1000);

            system("cls");
            break;
        }

    } while (x != 4);


    fclose(file);
    free(a);
    free(b);

	return 0;
}
