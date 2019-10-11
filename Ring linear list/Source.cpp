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
			cout << "1 - ������ ������;\nESC - �����;\n";
			button = _getch();
			if (button == '1')
			{
				start = false;
				string tmp;
				system("cls");
				cout << "������� ������ �������: ";
				cin >> tmp;
				list = Start(list, tmp);
			}
		}
		else
		{
			system("cls");
			cout << "������� �������: " << list->x << endl << "�������� ��������: \n1 - �������� ����� �������;\n2 - ������� ���� ����;\n3 - ������� �� ���������� �������;\n4 - ������� �� ��������� �������;\n5 - �����;\n6 - ������� �������;\nESC - �����;\n" << endl;
			button = _getch();
			switch (button)
			{
			case '1':
			{
				std::string tmp;
				cout << "������� �������� ������ ��������: ";
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
				cout << "������� �������� �������� ��������: ";
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