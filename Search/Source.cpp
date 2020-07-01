#include<iostream>
#include <ctime>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;


int comp1(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	const int masLen = 40;
	int mas[masLen];

	for (int i = 0; i < masLen; i++)
	{
		mas[i] = rand() % 1000;
	}

	qsort(mas, masLen, sizeof(int), comp1);

	for (int i = 0; i < masLen; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;

	int key = 0;

	cout << "������� �����: ";
	cin >> key;
	cout << endl << endl;


	//�������� �����

	int counter = 0;
	int position = -1;

	for (int i = 0; i < masLen; i++)
	{
		counter++;
		if (mas[i] == key)
		{
			position = i;
			break;
		}
	}

	cout << "�������� �����" << endl;

	switch (position)
	{
	case -1:
		cout << "����� " << key << " �� �������" << endl;
		break;
	default:
		cout << "����� " << key << " ����� �� " << position + 1 << " �������" << endl << "����������� ��������: " << counter << endl;
		break;
	}
	cout << endl;

	counter = 0;
	position = -1;

	//�������� �����

	int mid, right = masLen, left = 0;

	do
	{
		counter++;
		mid = (left + right) / 2;

		if (mas[mid] == key)
		{
			position = mid;
			break;
		}
		if (mas[mid] > key) right = mid - 1;
		else left = mid + 1;
	} while (left <= right);

	cout << "�������� �����" << endl;

	switch (position)
	{
	case -1:
		cout << "����� " << key << " �� �������" << endl;
		break;
	default:
		cout << "����� " << key << " ����� �� " << position + 1 << " �������" << endl << "����������� ��������: " << counter << endl;
		break;
	}

	cout << endl;
	position = -1;
	counter = 0;

	//���������������� �����

	left = 0;
	right = masLen - 1;
	while (mas[left] <= key && mas[right] >= key)
	{
		counter++;
		mid = left + ((key - mas[left]) * (right - left)) / (mas[right] - mas[left]);
		if (mas[mid] < key) left = mid + 1;
		else if (mas[mid] > key) right = mid - 1;
		else
		{
			position = mid;
			break;
		}
	}
	if (mas[left] == key) position = left;

	cout << "���������������� �����" << endl;

	switch (position)
	{
	case -1:
		cout << "����� " << key << " �� �������" << endl;
		break;
	default:
		cout << "����� " << key << " ����� �� " << position + 1 << " �������" << endl << "����������� ��������: " << counter << endl;;
		break;
	}
	system("pause");
}