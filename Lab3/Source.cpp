/*В некотором институте информация об имеющихся компьютерах задана двумя деревьями.
В первом из них сыновьям корневой вершины соответствуют факультеты, факультеты в свою очередь делятся на кафедры, а для каждой кафедры заданы номера принадлежащих ей компьютеров.
Во втором дереве сыновьям корня соответствуют учебные корпуса, корпуса включают списки аудиторий, а для каждой аудитории заданы номера находящихся в них компьютеров.
Некоторые аудитории могут принадлежать нескольким кафедрам.
Выдать список таких аудиторий.*/
#include <iostream>
using namespace std;

#pragma region facul

struct Department
{
	string data = {};
	int quantity = 0;
	int* PCs = nullptr;
};

struct Faculty
{
	string data = {};
	int quantity = 0;
	Department* department = nullptr;
};

void PrintDepPCs(const Department& dep)
{
	cout << dep.data << ":\t";
	for (int i = 0; i < dep.quantity; i++)
		cout << dep.PCs[i] << " ";
	cout << endl;
}

int PC = 0;
void GiveDepPCs(Department & dep, int quantity)
{
	dep.quantity = quantity;
	dep.PCs = new int[dep.quantity];
	for (int i = 0; i < dep.quantity; i++)
		dep.PCs[i] = i + PC + 1;
	PC += quantity;
}

void GiveDepPCs(Department & dep, int quantity, int x)
{
	dep.quantity = quantity;
	dep.PCs = new int[dep.quantity];
	for (int i = 0; i < dep.quantity; i++)
		dep.PCs[i] = i + x + 1;
	PC += quantity - PC + x;
}

void DelDep(Department & dep)
{
	delete[] dep.PCs;
}
#pragma endregion

#pragma region Class

struct Classroom
{
	string data = {};
	int quantity = 0;
	int* PCs = nullptr;
};

struct Building
{
	string data = {};
	int quantity = 0;
	Classroom* classrooms = nullptr;
};

void PrintClassPCs(const Classroom & Class)
{
	cout << Class.data << ":\t";
	for (int i = 0; i < Class.quantity; i++)
		cout << Class.PCs[i] << " ";
	cout << endl;
}

void SetClassPCs(Classroom & Class, int quantity)
{
	static int PC = 0;
	Class.quantity = quantity;
	Class.PCs = new int[Class.quantity];
	for (int i = 0; i < Class.quantity; i++)
		Class.PCs[i] = i + PC + 1;
	PC += quantity;
}

void DelClass(Classroom & Class)
{
	delete[] Class.PCs;
}
#pragma endregion


void Show(const Building & build, int x)
{
	do
	{
		for (int i = 0; i < build.quantity; i++)
			for (int j = 0; j < build.classrooms->quantity; j++)
				if (build.classrooms[i].PCs[j] == x)
				{
					cout << build.classrooms[i].data << "Принадлежит 2-м кафедрам" << endl;
					return;
				}

	} while (true);
}

int main()
{
	setlocale(LC_ALL, "");
	const int f = 2;
	Faculty faculties[f];
	faculties[0].data = "Information faculty";
	faculties[1].data = "Math faculty"; //just cause

	const int i_d = 2;
	Department info_deps[i_d];
	info_deps[0].data = "I1";
	info_deps[1].data = "I2";

	const int s_d = 2;
	Department sec_deps[s_d];

	sec_deps[0].data = "S1";
	sec_deps[1].data = "S2";

	faculties[0].department = info_deps;
	faculties[0].quantity = i_d;
	faculties[1].department = sec_deps;
	faculties[1].quantity = s_d;

	GiveDepPCs(info_deps[0], 10); // first 10 PCs

	GiveDepPCs(info_deps[1], 15); // 11 - 25

	GiveDepPCs(sec_deps[0], 15); // 26 - 40

	GiveDepPCs(sec_deps[1], 15, 35); // 36 - 50

	//----------------------------------------------------------------------------------------------------------------------------------

	const int b = 2;
	Building buildings[b];

	buildings[0].data = "1";
	buildings[1].data = "2";

	const int r1 = 3;
	Classroom rooms1[r1];
	buildings[0].classrooms = rooms1;
	buildings[0].quantity = r1;

	rooms1[0].data = "Building 1 Class 1";
	SetClassPCs(rooms1[0], 10);
	rooms1[1].data = "Building 1 Class 2";
	SetClassPCs(rooms1[1], 10);
	rooms1[2].data = "Building 1 Class 3";
	SetClassPCs(rooms1[2], 10);

	const int r2 = 2;
	Classroom rooms2[r2];
	buildings[1].classrooms = rooms2;
	buildings[1].quantity = r2;

	rooms2[0].data = "Building 2 Class 1";
	SetClassPCs(rooms2[0], 10);
	rooms2[1].data = "Building 2 Class 2";
	SetClassPCs(rooms2[1], 10);

	PrintDepPCs(info_deps[0]);
	PrintDepPCs(info_deps[1]);
	PrintDepPCs(sec_deps[0]);
	PrintDepPCs(sec_deps[1]);
	cout << endl;
	PrintClassPCs(rooms1[0]);
	PrintClassPCs(rooms1[1]);
	PrintClassPCs(rooms1[2]);
	PrintClassPCs(rooms2[0]);
	PrintClassPCs(rooms2[1]);

	int* PCs_mas = new int[PC];
	for (int i = 0; i < PC; i++)
		PCs_mas[i] = 0;

	for (int f_ = 0; f_ < f; f_++)
		for (int dep_ = 0; dep_ < faculties[f_].quantity; dep_++)
			for (int i = 0; i < faculties[f_].department[dep_].quantity; i++)
				if (++PCs_mas[faculties[f_].department[dep_].PCs[i] - 1] > 1)
					for (int b_ = 0; b_ < b; b_++)
						for (int c = 0; c < buildings[b_].quantity; c++)
							for (int j = 0; j < buildings[b_].classrooms[c].quantity; j++)
								if (buildings[b_].classrooms[c].PCs[j] == faculties[f_].department[dep_].PCs[i] - 1)
								{
									cout << buildings[b_].classrooms[c].data << " Принадлежит 2-м кафедрам" << endl;
									break;
								}


	system("pause");

	DelDep(faculties[0].department[0]);
	DelDep(faculties[0].department[1]);
	DelDep(faculties[1].department[0]);
	DelDep(faculties[1].department[1]);
	DelClass(buildings[0].classrooms[0]);
	DelClass(buildings[0].classrooms[1]);
	DelClass(buildings[0].classrooms[2]);
	DelClass(buildings[1].classrooms[0]);
	DelClass(buildings[1].classrooms[1]);
}