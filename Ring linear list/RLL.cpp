#pragma once
#include "RLL.h"

RLL* Start(RLL*cur, int x)
{
	cur = new(RLL);
	cur->x = x;
	cur->next = cur->prev = cur;
	return cur;
}

RLL* Add(RLL*cur, int x)
{
	RLL*tmp = new(RLL);
	tmp->x = x;

	if (cur->next == nullptr && cur->prev == nullptr)
	{
		tmp->next = cur;
		tmp->prev = cur;
		cur->next = tmp;
		cur->prev = tmp;
	}
	else if (cur->next == cur->prev)
	{
		tmp->prev = cur;
		tmp->next = cur->next;
		cur->next = tmp;
		cur->prev->prev = tmp;
	}
	else if (cur->next != nullptr && cur->prev != nullptr)
	{
		tmp->prev = cur;
		tmp->next = cur->next;
		tmp->next->prev = tmp;
		tmp->prev->next = tmp;
	}

	return tmp;
}

RLL* Del(RLL*cur)
{
	if (cur->next == cur && cur->prev == cur)
	{
		delete cur;
		return 0;
	}
	else if (cur->next != nullptr && cur->prev != nullptr)
	{
		RLL*tmp = cur->prev;
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
		return tmp;
	}
}

void Free(RLL*cur)
{
	do
	{
	} while (true);
}

RLL* MoveUp(RLL*cur)
{
	if (cur->next != nullptr)
		return cur->next;
	else return cur;

}
RLL* MoveDown(RLL*cur)
{
	if (cur->prev != nullptr)
		return cur->prev;
	else return cur;
}

RLL* Search(RLL*cur, int x)
{
	RLL* tmp = cur;
	do
	{
		cur = cur->next;
	} while (!(cur == tmp || cur->x == x));

	if (cur == tmp && cur->x == x)
		cout << "Существует только один элемент с данным значением";
	else if (cur->x == x)
	{
		cout << "Поиск успешен";
		return cur;
	}
	if (cur == tmp && cur->x != x)
		cout << "Элемента с данным значением не существует";
	return tmp;

}

void PrintAll(RLL*cur)
{
	RLL*tmp = cur;

	if (cur->next != nullptr)
		do
		{
			cout << tmp->x << ' ';
			tmp = tmp->next;

		} while (tmp != cur);
	else
		cout << tmp->x << ' ';
	cout << endl;
}