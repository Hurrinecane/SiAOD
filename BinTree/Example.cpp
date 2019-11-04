/*В листьях бинарного дерева указаны цифры либо идентификаторы переменных, заданные строчными латинскими буквами, в других вершинах знаки арифметических операций.Значения переменных известны.Выдать на экран выражение в префиксной и постфикской формах.Определить значение выражения.*/

/*#include <conio.h>
#include <ctype.h>
#include <iostream>
const int NUMALPHA = 26;
struct uzel // структура вершины дерева
{
	char key; // знак, цифра или буква
	uzel* left, * right; // сыновья
};
typedef uzel* ukaz;
double a[NUMALPHA]; // массив значений идентификаторов дерева
char s[NUMALPHA]; // множество введенных букв
int ns; // количество введенных букв

int smv(char c)
{
	if (isalnum(c) || (c == '+' || c == '-' || c == '/' || c == '*' || c == '^'))
		return 1;
	return 0;
}

// Рекурсивная процедура создания исходного дерева
void Sozd(ukaz t)
{
	char k;
	ukaz kon;
	if (t != NULL)
	{
		do
		{
			printf("\nВведите значение вершины ");
			k = _getche();
			if (!smv(k))
				printf("\nНеправильный символ! Повторите ввод");
		} while (!smv(k));
		t->key = k;
		if (isalnum(k)) // k - буква или цифра
		{
			t->left = NULL;
			t->right = NULL;
			if (isalpha(k)) s[ns++] = k; // k - буква. Добавление в множество.
		}
		else
		{
			printf("\nПереходим к левому сыну вершины %c", t->key);
			kon = (ukaz)malloc(sizeof(uzel));
			t->left = kon;
		}
		Sozd(t->left);
		if (t->left) // t->key - буква или цифра
		{
			printf("\nПереходим к правому сыну вершины %c", t->key);
			kon = (ukaz)malloc(sizeof(uzel));
			t->right = kon;
		}
		Sozd(t->right);
	}
}

// вывод на экран выражения в постфиксной форме
void PechPo(ukaz t)
{
	if (t) {
		PechPo(t->left);
		PechPo(t->right);
		printf(" %c", t->key);
	}
}
// вывод на экран выражения в префиксной форме
void PechPr(ukaz t)
{
	if (t) {
		printf(" %c", t->key);
		PechPr(t->left);
		PechPr(t->right);
	}
}
// расчет значения выражения, заданного бинарным деревом
double f1(ukaz t)
{
	if (!t->left) // лист: в t->key цифра или буква
		if (isdigit(t->key)) // цифра
			return t->key - '0';
		else // буква-идентификатор
			return a[t->key - 'a'];
	else
		switch (t->key) // не лист: в t->key знак
		{
		case '+': return f1(t->left) + f1(t->right);
		case '-': return f1(t->left) - f1(t->right);
		case '*': return f1(t->left) * f1(t->right);
		case '/': return f1(t->left) / f1(t->right);
		case '^': return exp(f1(t->right) * log(f1(t->left)));
		}
}
int main(void)
{
	setlocale(LC_ALL, "");
	ukaz root;
	root = (ukaz)malloc(sizeof(uzel));
	Sozd(root);
	printf("\nВвод закончен!\n");
	_getch();
	PechPo(root);
	printf(" - постфиксная форма\n");
	_getch();
	PechPr(root);
	printf(" - префиксная форма\n");
	_getch();
	// ввод значений идентификаторов
	for (int i = 0; i < ns; i++)
	{
		printf("\n%c=", s[i]);
		scanf_s("%lf", &a[s[i] - 'a']);
	}
	printf("\nЗначение выражения: %lf", f1(root));
	_getch();
}
*/