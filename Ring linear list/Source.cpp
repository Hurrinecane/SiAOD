#include "RLL.h"
#include<iostream>
#include<cstdio>
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "");
	RLL*list = {};

	int tmp;
	cout << "������� ������ �������: ";
	cin >> tmp;
	list = Start(list, tmp);

	char button;
	do
	{
		system("cls");
		cout << "������� �������: " << list->x << endl << "�������� ��������: \n 1 - �������� ����� �������; 2 - ������� ���� ����;" << endl;
		button = _getch();
		switch (button)
		{
		case '1':
			int tmp;
			system("cls");
			cout << "������� �������� ������ ��������: ";
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