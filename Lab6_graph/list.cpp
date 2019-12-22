/* Проект научно-технической программы задан с помощью
ориентированного графа. Вершина графа соответствует отдельному
исследованию, а дуги показывают очередность выполнения
исследований (каждое исследование может начаться не ранее
окончания предшествующих исследований) . Продолжительность
каждого исследования известна. Задан конечный срок выполнения
проекта. требуется определить максимальный интервал времени для
проведения каждого исследования, чтобы проект мог быть завершен
к назначенному сроку.*/

#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Graph;

#pragma region Reserch

class Reserch
{
	friend class Graph;
public:
	Reserch(string&, int&);
	Reserch(Reserch*&, string&, int&);
	//Reserch(Reserch*& prev, Reserch*& next, string&, int&);

	void PrintRes() const;
	void Print() const;
	void CountTime(double&) const;

private:
	string name;
	double time;
	bool completed;

	int quantityPrev;
	Reserch** prev;

	int quantityNext;
	Reserch** next;
};

void Increase(Reserch**& pArr, int length)
{
	Reserch** tmp = new  Reserch * [length + 1];
	for (int i = 0; i < length; i++)
		tmp[i] = pArr[i];
	pArr = tmp;
}

Reserch::Reserch(string& name_, int& time_)
{
	this->quantityNext = quantityPrev = 0;
	time = time_;
	name = name_;
	completed = false;
	prev = next = nullptr;
}

Reserch::Reserch(Reserch*& prev_, string& name_, int& time_)
{
	this->completed = false;
	time = time_;
	name = name_;

	prev = new Reserch * [quantityPrev + 1];
	//Increase(prev, quantityPrev);
	prev[quantityPrev] = prev_;

	//prev[quantityPrev]->next = new Reserch * [quantityNext + 1]; //стирает данные - написать функцию расширения
	Increase(prev[quantityPrev]->next, prev[quantityPrev]->quantityNext);
	prev[quantityPrev]->next[prev[quantityPrev]->quantityNext] = this;

	prev[quantityPrev]->quantityNext++;
	quantityPrev++;
	next = nullptr;
}

void Reserch::PrintRes() const
{
	cout << "Исследование \"" << this->name << "\"" << endl;
	cout << "Требуемое время: " << time << " секунд" << endl;
	cout << "Статус: ";
	if (completed) cout << "Завершено" << endl << endl;
	else cout << "Не завершено" << endl << endl;
}


void Reserch::Print() const
{
	this->PrintRes();
	for (int i = 0; i < this->quantityNext; i++)
	{
		if (this->next[i] != nullptr)
			this->next[i]->Print();
	}
}

void Reserch::CountTime(double& counter) const
{
	counter += this->time;
	for (int i = 0; i < this->quantityNext; i++)
	{
		if (this->next[i] != nullptr)
			this->next[i]->CountTime(counter);
	}
}

//Reserch::Reserch(Reserch*& prev_, Reserch*& next_, string& name_, int& time_)
//{
//	completed = false;
//	time = time_;
//	name = name_;
//
//	prev = new Reserch * [quantityPrev];
//	prev[quantityPrev++] = prev_;
//	prev[quantityPrev++]->next[prev[quantityPrev++]->quantityNext] = this;
//
//	next = new Reserch * [quantityNext++];
//	next[quantityNext] = next_;
//	next[quantityNext]->prev[next[quantityNext]->quantityPrev] = this;
//}

#pragma endregion

#pragma region Graph

class Graph
{
public:
	Graph();
	//~Graph();

	void Insert(string name_, int time_);
	void Bind(Reserch*, Reserch*);
	double CountTime() const;
	void Print() const;
	void ToRoot();
	void NextReserch(int);
	void PrevReserch(int);

private:
	Reserch* curReserch;
	Reserch* root;
};

Graph::Graph()
{
	root = curReserch = nullptr;
}

void Graph::Insert(string name_, int time_)
{
	if (curReserch == nullptr)
		root = curReserch = new Reserch(name_, time_);
	else
		curReserch->next[curReserch->quantityNext] = new Reserch(curReserch, name_, time_);
}

void Graph::Bind(Reserch* first_, Reserch* second_) //from, to //не работает
{
	if (first_ == root) return;
	//не должна быть предком
	Increase(first_->next, first_->quantityNext);
	first_->next[first_->quantityNext] = second_;

	Increase(second_->prev, second_->quantityPrev);
	second_->prev[second_->quantityPrev] = first_;
}

void Graph::Print() const
{
	cout << endl;
	curReserch->Print();
}

void Graph::ToRoot()
{
	curReserch = root;
	system("cls");
	cout << "Текущее исследование: ";
	curReserch->PrintRes();
}

void Graph::NextReserch(int n)
{
	if (curReserch->quantityNext >= n)
		curReserch = curReserch->next[n - 1];
	system("cls");
	cout << "Текущее исследование: ";
	curReserch->PrintRes();
}

void Graph::PrevReserch(int n)
{
	if (curReserch->quantityPrev >= n)
		curReserch = curReserch->prev[n - 1];
	system("cls");
	cout << "Текущее исследование: ";
	curReserch->PrintRes();
}

double Graph::CountTime() const
{
	double counter = 0;
	root->CountTime(counter);
	return counter;
}
#pragma endregion



int main()
{
	setlocale(0, "");
	Graph A;
	A.Insert("1", 10);
	A.Insert("11", 10);
	A.Insert("12", 10);
	A.NextReserch(1);
	A.Insert("111", 10);
	A.Insert("112", 10);
	A.NextReserch(2);
	A.Insert("1121", 10);
	A.ToRoot();
	A.Print();
	cout << "Время всех исследований: " << A.CountTime() << endl;

	system("pause");
}