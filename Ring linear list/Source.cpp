#include "RLL.h"
#include<iostream>
#include<cstdio>
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "");
	RLL*list = {};

	int tmp;
	cout << "Введите первый элемент: ";
	cin >> tmp;
	list = Start(list, tmp);

	char button;
	do
	{
		system("cls");
		cout << "Текущий элемент: " << list->x << endl << "Выберите действие: \n 1 - добавить новый элемент; 2 - Вывести весь лист;" << endl;
		button = _getch();
		switch (button)
		{
		case '1':
			int tmp;
			system("cls");
			cout << "Введите значение нового элемента: ";
			cin >> tmp;
			list = Add(list, tmp);
			break;
		case '2':
			PrintAll(list);
			_getch();
			break;
		case '3':

			break;
		case '4':

			break;
		}
	} while (button != '\x1b');
	system("pause");
}