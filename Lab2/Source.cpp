/*Текст программы на Turbo Pascal включает примечания, выделенные фигурными скобками '{', '}' либо парами символов ' (*' и '*) '.
Примечания могут быть вложенными друг в друга. Если примечание открыто знаком '{', то оно должно быть закрыто знаком '}'.
Аналогично примечание, начинающееся с символов ' (*' должно заканчиваться символами '*) '. Требуется:
1) проверить правильность вложенности примечаний;
2) переписать файл с исходным текстом так, чтобы отсутствовали вложенные примечания и в качестве ограничивающих символов остались только фигурные скобки.*/

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
				std::cout << "Ошибка." << std::endl;
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
					std::cout << "Ошибка." << std::endl;
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
				std::cout << "Ошибка." << std::endl;
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