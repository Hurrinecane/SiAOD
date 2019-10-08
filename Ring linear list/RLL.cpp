#pragma once
#include "RLL.h"

RLL* Start(RLL*cur, int x)
{
	cur = new(RLL);
	cur->x = x;
	return cur;
}

RLL* Add(RLL*cur, int x)
{
	RLL*tmp = new(RLL);
	if (cur->next != nullptr && cur->prev != nullptr)
	{
		tmp->x = x;
		tmp->next = cur;
		tmp->next = cur->prev;
		cur->prev = tmp;
	}
	else
	{
		tmp->x = x;
		tmp->next = cur;
		tmp->prev = cur;
		cur->next = tmp;
		cur->prev = tmp;
	}
	return tmp;
}

void Del(RLL*cur)
{
	if (cur->next != nullptr && cur->prev != nullptr)
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
	}
	else
		if (cur->next != nullptr)
		{
			cur->next->prev = nullptr;
			delete cur;
		}
		else
			if (cur->prev != nullptr)
			{
				cur->prev->next = nullptr;
				delete cur;
			}
			else
				delete cur;
}

void Free(RLL*cur)
{
	do
	{
	} while (true);
}

void MoveUp(RLL*cur)
{
	cur = cur->next;
}
void MoveDown(RLL*cur)
{
	cur = cur->prev;
}

void Search(RLL*cur, int x)
{
	RLL tmp = *cur;
	RLL* temp = cur;
	do
	{
		temp = temp->next;
	} while (temp != &tmp || temp->x != x);
	if (cur->x == x)
		cout << "Поиск успешен" << temp;
	else
		if (cur == &tmp)
			cout << "Существует только один элемент с данным значением" << temp;
		else
			cout << "Элемента с данным значением не существует" << temp;

}

void PrintAll(RLL*cur)
{
	RLL*tmp = cur;
	do
	{
		cout << tmp->x << ' ';
		tmp = tmp->next;

	} while (tmp != cur);
	cout << endl;
}

/*
struct RLL
{
int x;
RLL* next = nullptr;
RLL* prev = nullptr;
};

void Add(RLL*cur, int x)
{
RLL*tmp = new(RLL);
tmp->x = x;
tmp->next = cur;
tmp->prev = cur->prev;
cur->prev = tmp;
}
void Del(RLL*cur)
{
if (cur->next != nullptr && cur->prev != nullptr)
{
cur->prev->next = cur->next;
cur->next->prev = cur->prev;
delete cur;
}
else
if (cur->next != nullptr)
{
cur->next->prev = nullptr;
delete cur;
}
else
if (cur->prev != nullptr)
{
cur->prev->next = nullptr;
delete cur;
}
else
delete cur;
}

RLL* MoveUp(RLL*cur)
{
return cur->next;
}

RLL* MoveDown(RLL*cur)
{
return cur->prev;
}
*/