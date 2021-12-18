#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include <math.h>

int the_first_norm_of_vector(int size_file, double b[])
{
    int     answer;
    double  vichisl = 0;

    for (int k = 0; k < size_file; k++)
    {
        vichisl += fabs(pow(b[k], 1));
    }
    printf_s("\nНорма вектора = %lf\n\n", pow(vichisl, (1 / 1)));

    printf("\nХотите подсчитать другую норму фектора?\n");
    printf("1. Да\n2. Нет\n");
    scanf_s("%d", &answer);
    if (answer == 1)
        return 0;
    else
        return 1;

    return 0;
}

int the_second_norm_of_vector(int size_file, double b[])
{
    int     answer;
    double  vichisl = 0;

    vichisl = fabs(b[size_file - 1]);
    printf("\nНорма вектора = %lf\n\n", vichisl);

    printf("\nХотите подсчитать другую норму фектора?\n");
    printf("1. Да\n2. Нет\n");
    scanf_s("%d", &answer);
    if (answer == 1)
        return 0;
    else
        return 1;

    return 0;
}

int the_Helder_norm_of_vector(int size_file, double b[])
{
    int answer;
    double sum = 0;

    for (int index = 0; index < size_file; index++)
    {
        sum += pow(fabs(b[index]), size_file);
    }

    printf("\nГельдерова норма вектора равна: %lf\n", pow(sum, 1 / size_file));

    printf("\nХотите подсчитать другую норму фектора?\n");
    printf("1. Да\n2. Нет\n");
    scanf_s("%d", &answer);
    if (answer == 1)
        return 0;
    else
        return 1;

    return 0;
}

int infinite_norm_of_vector(int size_file, double b[])
{
    double max = 0;
    int answer;

    for (int index = 0; index < size_file; index++)
    {
        if (b[index] > max)
        {
            max = fabs(b[index]);
        }
    }

    printf("\nБесконечная норма вектора равна: %lf\n", max);

    printf("\nХотите подсчитать другую норму фектора?\n");
    printf("1. Да\n2. Нет\n");
    scanf_s("%d", &answer);
    if (answer == 1)
        return 0;
    else
        return 1;

    return 0;
}

int normalization_of_the_array_vector(int size_file, double b[])
{
    int answer;
    double sum = 0, sum_sqrt;

    for (int index = 0; index < size_file; index++)
    {
        sum += pow(fabs(b[index]), 2);
    }

    sum_sqrt = sqrt(sum);

    printf("\nНормировка вектора:  {");

    for (int index = 0; index < size_file; index++)
    {
        printf("%lf, ", b[index] / sum_sqrt);
    }
    printf("}\n");

    printf("\nХотите подсчитать другую норму фектора?\n");
    printf("1. Да\n2. Нет\n");
    scanf_s("%d", &answer);
    if (answer == 1)
        return 0;
    else
        return 1;

    return 0;
}

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
    int         x, i, x_1, user_run = 0;
    int         case_conf_1, case_conf_2;
    double      * a, * b;
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
        printf_s("1. Печать\n2. Сортировка\n3. Сброс\n4. Работа с массивом\n5. Выход\n");
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
            do
            {
                system("cls");
                printf("Вы выбрали \"Работа с массивом\". Чтобы вы хотели сделать?\n");
                printf("1. Вычислить первую норму вектора\n2. Вычислить вторую норму вектора\n3. Вычислить Гельдерову норму вектора\n");
                printf("4. Вычислить бесконечную норму вектора\n5. Нормировка вектора.\n");
                scanf_s("%d", &x_1);
                switch (x_1)
                {
                case 1:
                    user_run = the_first_norm_of_vector(size_file, b);
                    break;
                case 2:
                    user_run = the_second_norm_of_vector(size_file, b);
                    break;
                case 3:
                    user_run = the_Helder_norm_of_vector(size_file, b);
                    break;
                case 4:
                    user_run = infinite_norm_of_vector(size_file, b);
                    break;
                case 5:
                    user_run = normalization_of_the_array_vector(size_file, b);
                    break;
                default:
                    break;
                }
            } while (user_run == 0);
        case 5:
            break;
        default:
            printf("Вы ввели не коректное число, повторите попытку");
            Sleep(1000);

            system("cls");
            break;
        }

    } while (x != 5);


    fclose(file);
    free(a);
    free(b);

    return 0;
}
