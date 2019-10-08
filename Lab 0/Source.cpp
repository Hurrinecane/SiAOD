#include<iostream>
#include<cstdio>
#include <conio.h>

const int length = 10;

struct student
{
	char lastname[256];
	int number;
	int mat;
	int phys;
	int prog;
	double average;
};

student List[length];

void GetList()
{
	FILE *f;

	if (fopen_s(&f, "list.txt", "r") != 0)
		exit(1);

	for (int i = 0; i < length; i++)
	{
		int c = 0;
		do
		{
			char tmpstr[30] = {};
			for (int j = 0; tmpstr[j] != '0' || tmpstr[j] != '\n'; j++)
			{
				tmpstr[j] = fgetc(f);
				if (tmpstr[j] == ' ' || tmpstr[j] == '\n')
				{
					switch (c) {
					case 0: //Фамилия
						strcpy_s(List[i].lastname, tmpstr);
						List[i].lastname[j] = {};
						break;
					case 1: //Зачетка
						List[i].number = atoi(tmpstr);
						break;
					case 2:
						List[i].mat = atoi(tmpstr);
						break;
					case 3:
						List[i].phys = atoi(tmpstr);
						break;
					case 4:
						List[i].prog = atoi(tmpstr);
						break;
					}
					break;
				}
			}
			c++;
		} while (c < 5);
	}
	fclose(f);
}

void PrintList()
{
	system("cls");
	printf_s("Выберите действие:\nСортировка:\n1 - По фамилии;\n2 - По математике;\n3 - По физике;\n4 - По програмированию;\nВыход - Esc;\n\n");
	printf_s("Фамилия    Номер      Мат Физ Прог Ср.балл\n");
	for (int i = 0; i < length; i++)
	{
		int c = 0;
		do
		{
			switch (c)
			{
			case 0:
				printf_s("%10s ", List[i].lastname);
				break;
			case 1:
				printf_s("%1d ", List[i].number);
				break;
			case 2:
				printf_s("%2d ", List[i].mat);
				break;
			case 3:
				printf_s("%3d ", List[i].phys);
				break;
			case 4:
				printf_s("%3d ", List[i].prog);
				break;
			case 5:
				printf_s("%7.2lf\n", List[i].average);
				break;
			}
			c++;
		} while (c < 6);
	}
}

void Sort(int choise)
{
	student tmp;

	for (int i = 0; i < length; i++)
	{
		bool flag = true;
		for (int j = 0; j < 10 - (i + 1); j++)
		{

			bool check = false;

			switch (choise)
			{
			case 1:
				if (strcmp(List[j + 1].lastname, List[j].lastname) < 0) check = true;
				break;
			case 2:
				if (List[j].mat > List[j + 1].mat) check = true;
				break;
			case 3:
				if (List[j].phys > List[j + 1].phys) check = true;
				break;
			case 4:
				if (List[j].prog > List[j + 1].prog) check = true;
				break;
			}

			if (check)
			{
				flag = false;
				tmp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = tmp;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "");

	GetList();

	for (int i = 0; i < length; i++)
	{
		List[i].average = (List[i].mat + List[i].phys + List[i].prog) / 3.0;
	}

	char button = {};

	do
	{
		PrintList();
		button = _getch();
		switch (button)
		{
		case '1':
			Sort(1);
			break;
		case '2':
			Sort(2);
			break;
		case '3':
			Sort(3);
			break;
		case '4':
			Sort(4);
			break;
		}
	} while (button != '\x1b');
}