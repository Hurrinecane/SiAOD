#pragma once
#include <iostream>

using  std::cout;
using  std::cin;
using std::endl;

struct RLL
{
	int x;
	RLL* next = nullptr;
	RLL* prev = nullptr;
};
	RLL* Start(RLL*,int);
	RLL* Add(RLL*, int);
	void Del(RLL*);
	void MoveUp(RLL*);
	void MoveDown(RLL*);
	void Search(RLL*, int);
	void PrintAll(RLL*);