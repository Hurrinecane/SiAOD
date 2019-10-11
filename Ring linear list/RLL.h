#pragma once
#include <iostream>

using  std::cout;
using  std::cin;
using std::endl;
using std::string;

struct RLL
{
	string x;
	RLL* next = nullptr;
	RLL* prev = nullptr;
};
	RLL* Start(RLL*,string);
	RLL* Add(RLL*, string);
	RLL* Del(RLL*);
	RLL* MoveUp(RLL*);
	RLL* MoveDown(RLL*);
	RLL* Search(RLL*, string);
	void PrintAll(RLL*);