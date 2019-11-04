/*� ������� ��������� ������ ������� ����� ���� �������������� ����������, �������� ��������� ���������� �������, � ������ �������� ����� �������������� ��������.�������� ���������� ��������.������ �� ����� ��������� � ���������� � ����������� ������.���������� �������� ���������.*/

/*#include <conio.h>
#include <ctype.h>
#include <iostream>
const int NUMALPHA = 26;
struct uzel // ��������� ������� ������
{
	char key; // ����, ����� ��� �����
	uzel* left, * right; // �������
};
typedef uzel* ukaz;
double a[NUMALPHA]; // ������ �������� ��������������� ������
char s[NUMALPHA]; // ��������� ��������� ����
int ns; // ���������� ��������� ����

int smv(char c)
{
	if (isalnum(c) || (c == '+' || c == '-' || c == '/' || c == '*' || c == '^'))
		return 1;
	return 0;
}

// ����������� ��������� �������� ��������� ������
void Sozd(ukaz t)
{
	char k;
	ukaz kon;
	if (t != NULL)
	{
		do
		{
			printf("\n������� �������� ������� ");
			k = _getche();
			if (!smv(k))
				printf("\n������������ ������! ��������� ����");
		} while (!smv(k));
		t->key = k;
		if (isalnum(k)) // k - ����� ��� �����
		{
			t->left = NULL;
			t->right = NULL;
			if (isalpha(k)) s[ns++] = k; // k - �����. ���������� � ���������.
		}
		else
		{
			printf("\n��������� � ������ ���� ������� %c", t->key);
			kon = (ukaz)malloc(sizeof(uzel));
			t->left = kon;
		}
		Sozd(t->left);
		if (t->left) // t->key - ����� ��� �����
		{
			printf("\n��������� � ������� ���� ������� %c", t->key);
			kon = (ukaz)malloc(sizeof(uzel));
			t->right = kon;
		}
		Sozd(t->right);
	}
}

// ����� �� ����� ��������� � ����������� �����
void PechPo(ukaz t)
{
	if (t) {
		PechPo(t->left);
		PechPo(t->right);
		printf(" %c", t->key);
	}
}
// ����� �� ����� ��������� � ���������� �����
void PechPr(ukaz t)
{
	if (t) {
		printf(" %c", t->key);
		PechPr(t->left);
		PechPr(t->right);
	}
}
// ������ �������� ���������, ��������� �������� �������
double f1(ukaz t)
{
	if (!t->left) // ����: � t->key ����� ��� �����
		if (isdigit(t->key)) // �����
			return t->key - '0';
		else // �����-�������������
			return a[t->key - 'a'];
	else
		switch (t->key) // �� ����: � t->key ����
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
	printf("\n���� ��������!\n");
	_getch();
	PechPo(root);
	printf(" - ����������� �����\n");
	_getch();
	PechPr(root);
	printf(" - ���������� �����\n");
	_getch();
	// ���� �������� ���������������
	for (int i = 0; i < ns; i++)
	{
		printf("\n%c=", s[i]);
		scanf_s("%lf", &a[s[i] - 'a']);
	}
	printf("\n�������� ���������: %lf", f1(root));
	_getch();
}
*/