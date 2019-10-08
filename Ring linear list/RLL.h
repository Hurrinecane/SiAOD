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
	RLL* Del(RLL*);
	RLL* MoveUp(RLL*);
	RLL* MoveDown(RLL*);
	RLL* Search(RLL*, int);
	void PrintAll(RLL*);