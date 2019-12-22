#include<iostream>
#include <ctime>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	const int masLen = 40;
	int mas[masLen];

	for (int i = 0; i < masLen; i++)
	{
		mas[i] = rand() % 40;
		cout << mas[i] << " ";
	}
	cout << endl;

	int key = 0;

	cout << "Искомое число: ";
	cin >> key;
	cout << endl;
	//линейный поиск
	int position = -1;
	for (int i = 0; i < masLen; i++)
	{
		if (mas[i] == key)
		{
			position = i;
			break;
		}
	}
	switch (position)
	{
	case -1:
		cout << "Число " << key << " не найдено" << endl;
		break;
	default:
		cout << "Число " << key << " стоит на " << position + 1 << " позиции" << endl;
		break;
	}

	position = -1;
	//for (int i = 0; i < masLen; i++)
	//{
	//	mas[i] = i + 1;
	//	cout << mas[i] << " ";
	//}
	//cout << endl;

	int mas1[masLen] = { 1,2,3,4,5,12,15,18,20,25,31,32,33,35,37,40,47,48,50,55,56,58,60,70,71,73,75,79,80,84,86,89,90,101,115,118,120,125,126,130 };

	for (int i = 0; i < masLen; i++)
	{
		cout << mas1[i] << " ";
	}
	cout << endl;

	cout << "Искомое число: ";
	cin >> key;
	cout << endl;
	//бинарный поиск
	int counter = 0;
	int mid, right = masLen, left = 0;

	do
	{
		counter++;
		mid = (left + right) / 2;

		if (mas1[mid] == key)
		{
			position = mid;
			break;
		}
		if (mas1[mid] > key) right = mid - 1;
		else left = mid + 1;
	} while (left <= right);

	switch (position)
	{
	case -1:
		cout << "Число " << key << " не найдено" << endl;
		break;
	default:
		cout << "Число " << key << " стоит на " << position + 1 << " позиции" << endl << "Поиск занял " << counter << " итераций/и/ю" << endl;
		break;
	}

	position = -1;
	counter = 0;
	cout << "Искомое число: ";
	cin >> key;
	cout << endl;

	left = 0;
	right = masLen - 1;
	while (mas1[left] <= key && mas1[right] >= key)
	{
		counter++;
		mid = left + ((key - mas1[left]) * (right - left)) / (mas1[right] - mas1[left]);
		if (mas1[mid] < key) left = mid + 1;
		else if (mas1[mid] > key) right = mid - 1;
		else
		{
			position = mid;
			break;
		}
	}
	if (mas1[left] == key) position = left;

	switch (position)
	{
	case -1:
		cout << "Число " << key << " не найдено" << endl;
		break;
	default:
		cout << "Число " << key << " стоит на " << position + 1 << " позиции" << endl << "Поиск занял " << counter << " итераций/и/ю" << endl;;
		break;
	}
	system("pause");
}