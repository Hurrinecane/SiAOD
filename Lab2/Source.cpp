/*����� ��������� �� Turbo Pascal �������� ����������, ���������� ��������� �������� '{', '}' ���� ������ �������� ' (*' � '*) '.
���������� ����� ���� ���������� ���� � �����. ���� ���������� ������� ������ '{', �� ��� ������ ���� ������� ������ '}'.
���������� ����������, ������������ � �������� ' (*' ������ ������������� ��������� '*) '. ���������:
1) ��������� ������������ ����������� ����������;
2) ���������� ���� � �������� ������� ���, ����� ������������� ��������� ���������� � � �������� �������������� �������� �������� ������ �������� ������.*/

#include <iostream>

int main()
{
	setlocale(LC_ALL, "");

	char text[10000] = {};

	FILE*f;
	if (fopen_s(&f, "Pascal.txt", "r") != 0)
		exit(1);

	char tmp = {};
	int i = 0;
	int counter1 = 0, counter2 = 0;
	bool error = false;

	while (true)
	{
		tmp = fgetc(f);
		if (feof(f))
		{
			if (counter1 != 0)
			{
				std::cout << "������." << std::endl;
				for (int j = 0; j < i; j++)
					std::cout << text[j];
				std::cout << std::endl;
				system("pause");
				return 2;
			}
			else
			{
				for (int j = 0; j < i; j++)
					std::cout << text[j];
				std::cout << std::endl;
				system("pause");
				return 0;
			}

		}
		if (tmp == '(')
		{
			char temp = fgetc(f);
			if (temp == '*')
			{
				counter2++;
				tmp = '{';
			}
			else
			{
				text[i++] = tmp;
				text[i++] = temp;
				continue;
			}
		}
		if (tmp == '*')
		{
			char temp = fgetc(f);
			if (temp == ')')
			{
				if (counter2 == 0)
				{
					std::cout << "������." << std::endl;
					for (int j = 0; j < i; j++)
						std::cout << text[j];
					std::cout << std::endl;
					system("pause");
					return 1;
				}
				counter2--;
				tmp = '}';
			}
			else
			{
				text[i++] = tmp;
				text[i++] = temp;
				continue;
			}
		}
		if (tmp == '{')
		{
			counter1++;
			if (counter1 > 1)
				tmp = fgetc(f);
		}
		if (tmp == '}')
		{
			if (counter1 == 0)
			{
				std::cout << "������." << std::endl;
				for (int j = 0; j < i; j++)
					std::cout << text[j];
				std::cout << std::endl;
				system("pause");
				return 1;
			}
			if (counter1 > 1)
				tmp = fgetc(f);
			if (counter1 >= 1)
			{
				counter1--;
			}

		}
		text[i] = tmp;
		i++;
	}
}