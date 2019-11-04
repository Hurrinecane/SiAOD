#pragma once
#include "Tree.h"

class Tree
{
public:
	Tree(int);

	void Push(int);

	//Tree(const Tree&);
	//void operator = (int);

private:
	int data;
	Tree* left;
	Tree* right;
};


Tree::Tree(int x)
{
	data = x;
	left = nullptr;
	right = nullptr;
}

/*
void Tree::Push(int x)
{
	while (this != nullptr)
	{
		if (x > data)
			*this = *this->right;
		else
			*this = *this->left;
	}
	this = &Tree(x);
}
*/

/*
void Tree::Push(int x)
{
	if (this == nullptr)
	{
		Tree this(x);
		return;
	}
	if (x > data)
		right->Push(x);
	else
		left->Push(x);
}
*/

void Tree::Push(int x)
{
	if (x > data)
	{
		if (right == nullptr)
		{
			static Tree tmp(x);
			right = &tmp;
			this;
			return;
		}
		right->Push(x);
	}
	else
	{
		if (left == nullptr)
		{
			static Tree tmp(x);
			left = &tmp;
			this;
			return;
		}
		left->Push(x);
	}
}