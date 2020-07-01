#include <iostream>
using namespace std;

const int n = 10;

void Merge(int* A, int first, int last)
{
	int middle, start, final, j;
	int* mas = new int[n];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}

	for (j = first; j <= last; j++) A[j] = mas[j];
	delete[]mas;
};

void MergeSort(int* A, int first, int last)
{
	if (first < last)
	{
		MergeSort(A, first, (first + last) / 2);
		MergeSort(A, (first + last) / 2 + 1, last);
		Merge(A, first, last);
	}
};

void main()
{
	setlocale(0, "");

	int* A = new int[n];

	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}
	cout << endl;

	MergeSort(A, 0, n - 1);
	cout << "”пор€доченный массив: ";
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	cout << endl;


	for (int i = 0; i < n * 0.75; i++)
	{
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}
	cout << endl;

	MergeSort(A, 0, n - 1);
	cout << "”пор€доченный массив: ";
	for (int i = 0; i < n; i++) cout << A[i] << " ";

	cout << endl;

	for (int i = 0; i < n * 0.5; i++)
	{
		A[i] = rand() % 100;
		cout << A[i] << " ";
	}
	cout << endl;

	MergeSort(A, 0, n - 1);
	cout << "”пор€доченный массив: ";
	for (int i = 0; i < n; i++) cout << A[i] << " ";

	delete[]A;
	system("pause>>void");
}