#include "RLL.h"
#include<iostream>
#include<cstdio>
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "");
	RLL* list = {};

	bool start = true;
	char button;
	do
	{
		if (start)
		{
			system("cls");
			cout << "1 - Начать список;\nESC - Выход;\n";
			button = _getch();
			if (button == '1')
			{
				start = false;
				string tmp;
				system("cls");
				cout << "Введите первый элемент: ";
				cin >> tmp;
				list = Start(list, tmp);
			}
		}
		else
		{
			system("cls");
			cout << "Текущий элемент: " << list->x << endl << "Выберите действие: \n1 - Добавить новый элемент;\n2 - Вывести весь лист;\n3 - Перейти на предыдущий элемент;\n4 - Перейти на следующий элемент;\n5 - Поиск;\n6 - Удалить элемент;\nESC - Выход;\n" << endl;
			button = _getch();
			switch (button)
			{
			case '1':
			{
				std::string tmp;
				cout << "Введите значение нового элемента: ";
				cin >> tmp;
				list = Add(list, tmp);
			}
			break;
			case '2':
				PrintAll(list);
				_getch();
				break;
			case '3':
				list = MoveDown(list);
				break;
			case '4':
				list = MoveUp(list);
				break;
			case '5':
			{
				string tmp;
				cout << "Введите значение искомого элемента: ";
				cin >> tmp;
				list = Search(list, tmp);
				_getch();
			}
			break;
			case '6':
				list = Del(list);
				if (!list) start = true;
				break;
			}
		}
	} while (button != '\x1b');

	while (list)
		list = Del(list);

	system("pause");
}