#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include<ctype.h>
#define ARRAY_SIZE 300



char GetRandomChar()
{
	return rand() % (126 - 31 + 1) + 31;
}

void GetText(char textArray[])
{
	printf_s("Enter your massege: ");
	while (getchar() != '\n');
	gets_s(textArray, 300);
}

bool CheckPolindrom(char buffer[])
{
	int strinLen = strlen(buffer);
	if (strinLen == 1)
		return 0;
	for (int i = 0; i < strinLen / 2; i++)
	{
		if (buffer[i] != buffer[strinLen - i - 1])
			return 1;
	}
	return 0;
}

void AddNULL(char newArray[], int name)
{
	char buffer[1] = { name };

	strncat(newArray, buffer, 1);
}


//Удалить из текста все слова, которые являются палиндромами.
void DeletePalindrom(char textArray[], char newArray[])
{
	if (strlen(textArray) == 0)
	{
		AddNULL(newArray, 0);
		return;
	}

	char buffer[30] = {0};
	int strinLen = strlen(textArray);
	//с помощью стринНкопи и указателся на определённый элемент массива копировать определёныый кусок слова

	for (int i = 0,  wordStart = 0,  z = 0; ; i++)
	{
		if (isspace(textArray[i]) || i >= strinLen)
		{
			strncpy(buffer, &textArray[wordStart], i - wordStart);
			
			if (CheckPolindrom(buffer))
			{
				strncat(&newArray[z], buffer, i - wordStart);
				z += i - wordStart;
				newArray[z++] = ' ';
			}

			memset(buffer, 0, 30);

			wordStart = i + 1;
		}

		if (i >= strinLen)
			break;

	}

}


/*Дана строка. Определить, какой символ в ней встречается
раньше: 'x' или 'w'. Если какого-то из символов нет, вывести
сообщение об этом.*/
void ChechXW(char textArray[])
{
	int* x, * w;
	bool checkX = 0, checkW = 0;
	x = (int*)strchr(textArray, 'x');
	w = (int*)strchr(textArray, 'w');

	if (x == 0)
	{
		printf_s("No x found.\n");
		checkX = 1;

	}

	if (w == 0)
	{
		printf_s("No w found.\n");
		checkW = 1;
	}

	if (x == 0 && w == 0)
		return;

	if (x == 0 && w != 0) 
	{
		printf_s("w is first\n");
		return;
	}

	if (x != 0 && w == 0)
	{
		printf_s("x is first\n");
		return;
	}

	if(x > w)
		printf_s("w is first\n");
	else 
		printf_s("x is first\n");
}

/*Дана строка. Вставить после каждого символа два случайных
символа.*/
void AddRandomChar(char textArray[], char newArray[])
{
	int stringLength = strlen(textArray);
	char buffer[3] = {0};
	for (int i = 0, z = 0; i < stringLength; i++)
	{
		buffer[0] = textArray[i];
		buffer[1] = GetRandomChar();
		buffer[2] = GetRandomChar();
		strncat(newArray, buffer, 3);
	}
}

int main()
{
	system("chcp 1251");
	system("cls");

	int seed = time(NULL);
	srand(seed);

	int type;

	char textArray[ARRAY_SIZE] = {0};
	char newArray[ARRAY_SIZE*3] = {0};

	do
	{
		printf_s("Enter ex number: ");
		scanf_s("%d", &type);
		if (type >= 1 && type <= 3)
			break;
		printf_s("Invalid value. Try again.\n");
	} while (true);

	GetText(textArray);

	switch (type)
	{
	case 1:
		DeletePalindrom(textArray, newArray);
		printf_s("%s", newArray);
		break;
	case 2:
		ChechXW(textArray);
		break;
	case 3:
		AddRandomChar(textArray, newArray);
		printf_s("%s", newArray);
		break;
	}


	return 0;
}