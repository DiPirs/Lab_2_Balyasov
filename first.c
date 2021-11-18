#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <malloc.h>
#include <time.h>

const double RAND_MAX_F = RAND_MAX;

int main() {
	int			x = 0, i = 0, case_1 = 0, j;
	int			size_gener, len_inter_keyboard;
	float		min_gener, max_gener;
	float		inter_keyboard;

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	FILE* file = fopen("file.txt", "w");

	do
	{
		system("cls");
		printf("Вас приветствует меню \"Сортировка\". Что бы Вы хотели сделать?\n");
		printf("1. Сгенерировать числа\n2. Ввести с клавиатуры\n");
		scanf_s("%d", &x);
		switch (x)
		{
		case 1:
			do
			{
				system("cls");
				printf("Вы выбрали \"Генирацию чисел\"\n");
				printf("Введите кол-во элементов массива: ");
				scanf_s("%d", &size_gener);
				printf("Введите минимальное число: ");
				scanf_s("%f", &min_gener);
				printf("Введите максимальное число: ");
				scanf_s("%f", &max_gener);
				printf("Ожидайте проверки данных...\n\n");
				Sleep(1500);
				if (min_gener > max_gener)
				{
					printf("Вы ввели не правильные данные. Пожалуйста, повторите попытку.\n");
					Sleep(1000);
				}
				else
				{
					system("cls");
					printf("Данные коректны.\nСейчас произойдет магия генерации...\n\n");
					Sleep(1000);
					case_1++;
				}
			} while (case_1 != 1);

			printf("Ожидайте...\n\n");
			Sleep(1000);

			for (j = 0; j < size_gener; j++)
			{
				fprintf(file, "%f\n", (rand() / RAND_MAX_F) * ((float)max_gener - (float)min_gener) + min_gener);
			}

			printf("Поздравляю, Вы только что сгенерировали числа\nМожете убедиться, заглянув в текстовой файл.\n");
			i++;
			break;
		case 2:
			system("cls");
			printf("Вы выбрали \"Ввести с клавиатуры\"\n");
			printf("Пожалуйста, введите кол-во элементов массива: ");
			scanf_s("%d", &len_inter_keyboard);
			printf("Пожалуйста, введите все нужные Вам числа (числа вводить с запятой, а не с точкой. К примеру: 1,25):\n");
			for (j = 0; j < len_inter_keyboard; j++)
			{
				scanf_s("%f", &inter_keyboard);
				fprintf(file, "%f\n", inter_keyboard);
			}
			printf("\nОжидайте...\n\n");
			Sleep(1000);

			printf("Поздравляю, Вы только что записали числа в текстовый файл\nМожете убедиться, заглянув в него.\n");
			i++;
			break;
		default:
			printf("Вы ввели не правильное число, повторите попытку\n");
			Sleep(1000);
			break;
		}
	} while (i != 1);

	return 0;
}
