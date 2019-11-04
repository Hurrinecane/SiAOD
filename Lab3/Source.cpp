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
	Department* department = nullptr;
};

void PrintDepPCs(const Department& dep)
{
	cout << dep.data << " ";
	for (int i = 0; i < dep.quantity; i++)
			cout << dep.PCs[i] << " ";	
	cout << endl;
}

void GiveDepPCs(Department& dep, int quantity)
{
	static int PC = 0;
	dep.quantity = quantity;
	dep.PCs = new int [dep.quantity];
	for (int i = 0; i < dep.quantity; i++)
		dep.PCs[i] = i + PC + 1;
	PC += quantity;
}

void DelDep(Department& dep)
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
	Classroom* classrooms = nullptr;
};

void PrintClassPCs(const Classroom &Class)
{
	cout << Class.data << " ";
	for (int i = 0; i < Class.quantity; i++)
		cout << Class.PCs[i] << " ";
	cout << endl;
}

void SetClassPCs(Classroom& Class, int quantity)
{
	static int PC = 0;
	Class.quantity = quantity;
	Class.PCs = new int[Class.quantity];
	for (int i = 0; i < Class.quantity; i++)
		Class.PCs[i] = i + PC + 1;
	PC += quantity;
}
#pragma endregion

int main()
{
	Faculty faculties[2];
	faculties[0].data = "Information faculty";
	faculties[1].data = "Math faculty"; //just cause

	Department info_deps[2];
	faculties[0].department = info_deps;
	info_deps[0].data = "I1";
	
	GiveDepPCs(info_deps[0], 10);

	PrintDepPCs(info_deps[0]);

	info_deps[1].data = "I2";
	
	GiveDepPCs(info_deps[1], 15);

	PrintDepPCs(info_deps[1]);

	Department sec_deps[2];

	faculties[1].department = sec_deps;
	sec_deps[0].data = "V1";

	GiveDepPCs(sec_deps[0], 15);

	PrintDepPCs(sec_deps[0]);
	sec_deps[1].data = "V2";
	
	GiveDepPCs(sec_deps[1], 10);

	PrintDepPCs(sec_deps[1]);

	//----------------------------------------------------------------------------------------------------------------------------------

	Building buildings[2];

	buildings[0].data = "1";
	buildings[1].data = "2";

	Classroom info_classrooms[3];
	buildings[0].classrooms = info_classrooms;


	Classroom sec_classrooms[2];
	buildings[1].classrooms = sec_classrooms;


	system("pause");
	DelDep(faculties[0].department[0]);
	DelDep(faculties[0].department[1]);
	DelDep(faculties[1].department[0]);
	DelDep(faculties[1].department[1]);
}
