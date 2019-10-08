/*Имеется текстовый файл с некоторым описанием. Переносы слов разрешены. Выдать информацию о том, сколько раз встречается в тексте каждое слово.*/
#include<iostream>
#include<cstdio>
#include <conio.h>

char text[10000];

struct Counter
{
	char word[50];
	int number;
};

Counter Words[1000];

void GetText()
{
	FILE*f;
	if (fopen_s(&f, "Text.txt", "r") != 0)
		exit(1);

	char tmp = {};
	int i = 0;

	while (!feof(f))
	{
		tmp = fgetc(f);
		if (feof(f)) break;
		if (tmp == '-')
		{
			char temp = fgetc(f);
			if (temp == '\n')
				continue;
		}

		if (tmp != '\n') text[i] = tmp;
		else text[i] = ' ';

		i++;
	}
}

int k = 0;
void CountWords()
{
	int j = 0; //i - text		j - temp	k - words
	char tmp;
	char word[50] = {};

	int length = strlen(text);

	for (int i = 0; i <= length; i++)
	{
		tmp = text[i];
		if ((tmp > 96 && tmp < 123) || (tmp > 64 && tmp < 91))
		{
			word[j] = tmp;
			j++;
		}
		else
		{
			if (word[0] != '\0')
			{

				bool already = false;
				for (int l = 0; l < k; l++)
				{
					if (!strcmp(Words[l].word, word))  //если строки идентичны
					{
						already = true;
						Words[l].number++;
						break;
					}
				}
				if (!already)
				{
					strcpy_s(Words[k].word, word);
					Words[k].number++;
					k++;
				}
				memset(word, 0, strlen(word));
				j = 0;
			}
		}
	}
}

void PrintWords()
{
	printf_s("Слово              Количество повторений\n");
	for (int i = 0; i < k; i++)
	{
		printf_s("%15s%5d\n", Words[i].word, Words[i].number);
	}
}

int main()
{
	setlocale(LC_ALL, "");

	GetText();
	CountWords();
	PrintWords();

	system("pause");
}