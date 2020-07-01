
/*������� ���� � �������������� ������������ ������������� � ���������� �������. ������� ��������� ���� ��� ������ ������������ ������.*/

#include <cstdio>
#include <iostream>

using namespace std;

const int l_name = 30;

struct Position
{
	char type[l_name];
	char name[l_name];
};

class Stock
{
public:
	Stock()
	{
		FILE* fbin;
		int err;
		if (err = fopen_s(&fbin, "dbase.bin", "rb") != NULL)
			cout << "������ ��������  �����. ��� ������: " << err << endl;
		else
		{
			err = fseek(fbin, 0, SEEK_END);
			positionQ = ftell(fbin) / sizeof(Position);
			position = new Position[positionQ];
			fseek(fbin, 0, SEEK_SET);
			fread(position, sizeof(Position), positionQ, fbin);
			fclose(fbin);
		}
		CrateIndexTable();
	}

	~Stock()
	{
	}

	void positionsView()
	{
		cout << "���������� ������:" << endl;
		for (int i = 0; i < positionQ; i++)
			cout << i << " " << position[i].type << " " << position[i].name << endl;
	}

	void indexTableView()
	{
		cout << "���� �������, ���������� �� ������:" << endl;
		for (int i = 0; i < typesQ + 1; i++)
			cout << indexTable[i].number << " " << indexTable[i].position->type << endl;
	}

	Position* position;

	struct IndexTable
	{
		Position* position;
		int number;
	}*indexTable;

	int typesQ;
	int positionQ;

private:
	void CrateIndexTable()
	{
		indexTable = new IndexTable[positionQ];
		typesQ = 0;

		indexTable[0].position = &position[0];
		indexTable[0].number = 0;

		for (int i = 1; i < positionQ; i++)
			if (strcmp(indexTable[typesQ].position->type, position[i].type) != 0)
			{
				typesQ++;
				indexTable[typesQ].position = &position[i];
				indexTable[typesQ].number = i;
			}
	}


	void SaveIndexTable()
	{
		FILE* fbin;
		int err = NULL;
		if (err = fopen_s(&fbin, "dbase.bin", "wb") != NULL)
			cout << "������ ��������  �����. ��� ������: " << err << endl;
		else
		{
			err = fwrite(&indexTable, sizeof(indexTable), 1, fbin);
			if (err != 1)
				cout << "������ ���������� ���������� �����" << endl;

			fclose(fbin);
			cout << "��������� ���� ������� ��������." << endl;
		}
	}
};

int compare(const void* manl, const void* man2)
{
	return strcmp(((Position*)manl)->type,
		((Position*)man2)->type);
}

void Create(void) // �������� �����
{
	Position position;
	FILE* fbin;
	int err = NULL;
	if (err = fopen_s(&fbin, "dbase.bin", "wb") != NULL)
		cout << "������ ��������  �����. ��� ������: " << err << endl;
	else
	{
		int pr;
		system("cls");
		cout << "�������� �������� ����� �������." << endl;
		do
		{
			cout << "��� ������: ";
			cin >> position.type;
			cout << "������������ ������: ";
			cin.get(); gets_s(position.name);

			err = fwrite(&position, sizeof(position), 1, fbin);
			if (err != 1)
				cout << "������ ������" << endl;

			cout << "\n ���������� ����? (0-���)" << endl;
			cin >> pr;
		} while (pr);
		fclose(fbin);
		cout << "���� ������� ������� ������." << endl;
	}
}

void View(void) // �������� �����
{
	FILE* fbin;
	int err;
	if (err = fopen_s(&fbin, "dbase.bin", "rb") != NULL)
		cout << "������ ��������  �����. ��� ������: " << err << endl;
	else
	{
		err = fseek(fbin, 0, SEEK_END);
		int n_record = ftell(fbin) / sizeof(Position);
		Position* position = new Position[n_record];
		fseek(fbin, 0, SEEK_SET);
		fread(position, sizeof(Position), n_record, fbin);
		fclose(fbin);
		cout << "���������� �����:" << endl;
		for (int i = 0; i < n_record; i++)
			cout << position[i].type << " " << position[i].name << endl;
		delete(position);
	}
}

void Sort(void)
{
	FILE* fbin;
	int err;
	if (err = fopen_s(&fbin, "dbase.bin", "rb") != NULL)
		cout << "������ ��������  �����. ��� ������: " << err << endl;
	else
	{
		err = fseek(fbin, 0, SEEK_END);
		int n_record = ftell(fbin) / sizeof(Position);
		Position* position = new Position[n_record];
		fseek(fbin, 0, SEEK_SET);
		fread(position, sizeof(Position), n_record, fbin);
		fclose(fbin);
		qsort(position, n_record, sizeof(Position), compare);
		if (err = fopen_s(&fbin, "dbase.bin", "wb") != NULL)
			cout << "������ ��������  �����. ��� ������: " << err << endl;
		else
		{
			for (int i = 0; i < n_record; i++)
				if (fwrite(&position[i], sizeof(position[i]), 1, fbin) != 1)
					cout << "������ ������" << endl;
			cout << "���� ������������" << endl;
			delete(position);
			fclose(fbin);
		}
	}
}


int main()
{
	setlocale(0, "");
	//Create();
	//Sort();
	Stock stock;
	stock.positionsView();
	stock.indexTableView();

	system("pause");
}